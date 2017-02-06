#include "interpretador.h"
#include"estrategias.h"

/** Altera o estado da estrutura ELEM e faz o push da stack caso seja preciso
    @param e apontador para estrutura ESTADO
	@param l linha
	@param c coluna
	@param valor caracter
	@return retorna 1 se houve mudanças e 0 caso nada foi alterado
*/
int set_state (ESTADO *e, int l, int c, char valor) {
	char ant = e->tab[l][c];
	ELEM elem;
	elem.l = l;
	elem.c = c;
	elem.s0 = ant;
	elem.num_cmd = e->num_cmd;
	if(ant == valor)
		return 1;
	
	e->tab[l][c] = valor;
	return push(e->stack, elem);
}

/** Imprime o conteudo do tabuleiro no standard imput
    @param e apontador para ESTADO
    @return no return value
*/
void mostrar (ESTADO *e)
{	
	int i;
	int j;

	if (e->conteudo) /*caso foi adicionado conteudo no estado, executa instruçoes seguintes*/
	{
	for (i = 0; i < e->nLinhas; i++)
    { 
    	for (j = 0; j < e->nColunas; j++)
			printf ("%c", e->tab[i][j]);
		printf("%d\n", e->nSeg_linhas[i]);		
	}

	for (i = 0; i < (e->nColunas); i++)
		printf("%d", e->nSeg_colunas[i]);
	printf("\n");
	}
	else
		printf("Sem conteudo!\n");
}

/** Transforma os espaços vazio em agua nas linhas do tabuleiro*
    @param e apontador para ESTADO
	@param num numero de linha
    @return no return value
*/
void lAgua (ESTADO *e,int num)
{
	int j;

	for (j = 0; j < e->nColunas; j++)
	{
		if (e->tab[num - 1][j] == '.')
			set_state(e, num - 1, j, '~');
	}
	
}

/** Transforma os espaços vazio em agua nas colunas do tabuleiro*
    @param e apontador para ESTADO
	@param num numero de coluna
    @return no return value
*/
void cAgua (ESTADO *e,int num)
{
	int i;
	
	for (i = 0; i < e->nLinhas; i++)
	{
		if (e->tab[i][num - 1] == '.')
			set_state(e, i, num - 1, '~');
	}

}

/** Interpretador de comandos, executa um comando, mudando ou nao o estado do tabuleiro, retornando 1*
    @param e apontador para ESTADO
	@param linha string da linha
    @return 1 ou 0
*/
int interpretador (ESTADO *e, char *linha)
{
	char cmd [MAX_BUF];
	int nArgs;
	char arg1[MAX_BUF], arg2[MAX_BUF];
	nArgs = sscanf (linha, "%s %s %s", cmd, arg1, arg2);
	e->num_cmd++;
	
	if (strcmp(cmd, "c") == 0)
	{
		carregar (e);
	}

	if (strcmp(cmd, "m") == 0)
	{
		mostrar (e);
	}

	if ((strcmp(cmd, "h") == 0) && nArgs == 2)
	{
        lAgua (e, atoi(arg1));
	}

	if ((strcmp(cmd, "v") == 0) && nArgs == 2)
	{
        cAgua (e, atoi(arg1));
	}

	if (cmd[0] == 'p' && nArgs == 3)
	{
        colocarChr (e, cmd[1], atoi(arg1), atoi (arg2));
	}
	
	if (strcmp(cmd, "D") == 0)
    {
		undo (e);
	}

	if (strcmp(cmd, "E1")==0)
	{
		add_water_e1 (e);
	}

	if (strcmp(cmd, "E2")==0)
	{
		add_water_e2 (e);
	}

	if (strcmp(cmd, "E3")==0)
	{
		add_boat_e3 (e);
	}

	if (strcmp(cmd, "V")==0)
	{
		validate (e);
	}

	if (strcmp(cmd, "l") == 0)
	{
        ler (e, arg1);
	}

	if (strcmp(cmd, "e") == 0)
    {
		escrever (e, arg1);
	}

	if(strcmp(cmd,"G") == 0 && nArgs == 3)
	{
		init_boats (e, atoi(arg1), atoi (arg2));
	}

	if(strcmp(cmd, "R") == 0)
	{
		resolve (e);
	}

	if (strcmp(cmd, "q") == 0)
	{
		return 0;
	}

	return 1;
}

/** Desfaz o último comando*
    @param e apontador para ESTADO
    @return no return value
*/
void undo(ESTADO *e)
{
	int flag=0;
	ELEM elem;
	int num;

	top(e->stack, &elem);
	if(isEmpty(e->stack))
		return;
	num = elem.num_cmd;

	while(flag == 0)
	{
		top(e->stack, &elem);

		if(num == elem.num_cmd && !isEmpty(e->stack))
		{
			pop(e->stack);
			e->tab[elem.l][elem.c] = elem.s0;
		}
		else
		{
		flag = 1;
		}
	}
}

/** Altera o caracter existente no tabuleiro para um novo, dado pelo utilizado
    @param e apontador para ESTADO
	@param l caracter do tabuleiro
    @param numL linha
    @param numC coluna
    @return no return value
*/
void colocarChr (ESTADO*e, char l, int numL, int numC) 
{
	set_state (e, numL - 1, numC - 1, l);
}

/** Carrega a informaçao para o estado a partir de um ficheiro ou do standard input
    @param e apontador para ESTADO
    @return no return value
*/
void carregar(ESTADO *e)
{
	ler_ficheiro(e, stdin);
}

/** Lê ficheiro de texto
    @param e apontador para ESTADO
	@param nome string do nome com nome do ficheiro
    @return no return value
*/
void ler (ESTADO *e, char *nome)
{
	FILE *f = NULL;

	f = fopen(nome, "r");
	
	ler_ficheiro(e, f);

	fclose(f);
}

/** Função auxiliar de leitura de ficheiro de texto ou do standard input
    @param e apontador para ESTADO
    @param file nome do ficheiro
    @return no return value
*/
void ler_ficheiro (ESTADO *e, FILE *file)
{
	char linha[MAX_BUF], resto[MAX_BUF];
	int c, l;
	
	if (fgets (linha, MAX_BUF, file))
		sscanf (linha, "%d %d", &(e->nLinhas), &(e->nColunas));

	if (fgets (linha, MAX_BUF, file))
	{
		for (l = 0; l < e->nLinhas; l++)
		{
			sscanf (linha, "%d %[^\n]", &(e->nSeg_linhas[l]), resto);
			strcpy (linha, resto);
		}
	}
		
	if (fgets (linha, MAX_BUF, file))
	{
		for (c = 0; c < e->nColunas; c++)
    	{   
			sscanf (linha, "%d %[^\n]", &(e->nSeg_colunas[c]), resto);
        	strcpy (linha, resto);
    	}
	}

   	for (l = 0; l < e->nLinhas; l++) 
	{
	 	if (fgets (linha, MAX_BUF, file))
		{
      		for (c = 0; c < e->nColunas; c++ ) 
			{ 
        		sscanf (linha, "%c %[^\n]", &e->tab[l][c], resto);
				strcpy (linha, resto);
      		}
		}
    }

	e->conteudo = 1;
}

/** Escreve num ficheiro de texto a informaçao do tabuleiro
    @param e apontador para ESTADO
    @param nome string com o nome do ficheiro
    @return no return value
*/
void escrever (ESTADO *e, char *nome)
{
	int i;
	int j;
	FILE *f;
	int flag = 0;

	f = fopen (nome, "w");

	fprintf (f, "%d %d\n", e->nLinhas, e->nColunas);

	for (i = 0; i < e->nLinhas; i++)
	{
		if (flag)
		{
			fprintf (f, " %d", e->nSeg_linhas[i]);
		}
		else
		{
			fprintf (f, "%d", e->nSeg_linhas[i]);
			flag = 1;
		}
	
	}
	fprintf (f, "\n");

	flag = 0;

	for (i = 0; i < (e->nColunas); i++)
	{
		if (flag)
		{
			fprintf (f, " %d", e->nSeg_colunas[i]);
		}
		else
		{
			fprintf (f, "%d", e->nSeg_colunas[i]);
			flag = 1;
		}
	}
	fprintf (f, "\n");

	for (i = 0; i < e->nLinhas; i++)
	{ 
		for (j = 0; j < e->nColunas; j++)
			fprintf (f, "%c", e->tab[i][j]);
		fprintf (f, "\n");
	}       

	fclose(f);
}

/** verifica se um segmento do meio de um barco está num dos cantos do tabuleiro
    @param e apontador para ESTADO
    @return 1 caso encontrar um desse casos
*/
int is_middle_segment_corner (ESTADO *e) 
{
    int r=0;
	       
	if (e->tab [0][0] == '#' 
		|| e->tab [0][e->nLinhas] == '#'  
		|| e->tab [0][e->nColunas] == '#' 
		|| e->tab [e->nLinhas][e->nColunas] == '#')

		r = 1;

	return r;
}


/** Estrategia I adiciona água a volta de uma peça de um barco
    @param e apontador para ESTADO
    @return 0;
*/
int add_water_e1 (ESTADO *e)
{
	ORIENT coords;

	int i, j, r = 0;

	reset_coords (&coords);

	for (i = 0; i < e->nLinhas; i++)
	{
		for (j = 0; j < e->nColunas; j++)
		{
			if(set_water_coords (&coords, (e->tab[i][j]))) {

				if (i - 1 >= 0 && j - 1 >= 0 && e->tab[i - 1][j - 1] == '.')
				{
					set_state (e, i - 1, j - 1, '~');
				}

				if (i - 1 >= 0 && j + 1 <= e->nColunas - 1 && e->tab[i - 1][j + 1] == '.')
				{
					set_state (e, i - 1, j + 1 , '~');
				}
				
				if (i + 1 <= e->nLinhas - 1 && j - 1 >= 0 && e->tab[i + 1][j - 1] == '.')
				{
					set_state(e, i + 1, j - 1, '~');
				}
				
				if (i + 1 <= e->nLinhas - 1 && j + 1 <= e->nColunas - 1 && e->tab[i + 1][j + 1] == '.')
				{
					set_state(e, i + 1, j + 1, '~');
				}
			}

			if (e->tab[i][j] == '#')
			{
				if ((is_boat(e->tab[i][j - 1]) || is_boat(e->tab[i][j + 1])) && i - 1 >= 0)
				{
					coords.N = 1;
				}

				if ((is_boat(e->tab[i][j - 1]) || is_boat(e->tab[i][j + 1])) && i + 1 <= e->nLinhas - 1)
				{
					coords.S = 1;
				}

				if ((is_boat(e->tab[i - 1][j]) || is_boat(e->tab[i+1][j])) && j + 1 <= e->nColunas - 1)
				{
					coords.E = 1;
				}

				if ((is_boat(e->tab[i - 1][j]) || is_boat(e->tab[i + 1][j])) && j - 1 >= 0)
				{
					coords.W = 1;
				}

				if (e->tab[i - 1][j] == '~' && i + 1 <= e->nLinhas - 1)
				{
					coords.S = 1;
				}

				if (e->tab[i + 1][j] == '~' && i - 1 >=0)
				{
					coords.N = 1;
				}

				if (e->tab[i][j + 1] == '~' && j - 1 >= 0)
				{
					coords.W = 1;
				}

				if (e->tab[i][j - 1] == '~' && j + 1 <= e->nColunas - 1)
				{
					coords.E = 1;
				}
			}


			if (coords.N == 1)
			{
				if (i - 1 >= 0 && e->tab[i - 1][j] == '.')
				{
					set_state (e, i - 1, j, '~');
				}
			}

			if (coords.S == 1)
			{
				if (i + 1 <= e->nLinhas - 1 && e->tab[i + 1][j] == '.')
				{
					set_state (e, i + 1, j, '~');
				}
			}

			if (coords.E == 1)
			{
				if (j + 1 <= e->nColunas - 1 && e->tab[i][j + 1] == '.')
				{
					set_state (e, i, j + 1, '~');
				}
			}

			if (coords.W == 1)
			{
				if (j - 1 >= 0 && e->tab[i][j - 1] == '.')
				{
					set_state (e, i, j - 1, '~');
				}
			}

		}
	}
	return r;
}

/** Estratégia II, preenche os espaços vazios com água de uma linha ou coluna do tabuleiro
    @param e apontador para ESTADO
    @return void;
*/
void add_water_e2 (ESTADO *e)
{
	int i, j, c = 0;

	for (i = 0; i < e->nLinhas; i++)
	{
			
		if (e->nSeg_linhas[i] == 0)
		{
			for (j = 0; j < e->nColunas; j++)
			{   
				if (e->tab[i][j] == '.')
					set_state (e, i, j, '~');
			}   
		}

		for (j = 0; j < e->nColunas; j++)
		{
				if (is_boat(e->tab[i][j]))
					c++;
		}

		for (j = 0; j < e->nColunas; j++)
		{
				if (c == e->nSeg_linhas[i])
				{
					for (j = 0; j < e->nColunas; j++)
					{   
						if (e->tab[i][j] == '.')
							set_state (e, i, j, '~');
					}   
				}
		}
		c = 0;


	}

	for (j = 0; j < e->nColunas; j++)
	{
		if (e->nSeg_colunas[j] == 0)
		{
			for (i=0; i < e->nLinhas; i++)
			{
				if (e->tab[i][j] == '.')
					set_state (e,i, j, '~');
			}
		}
			
		for (i = 0; i < e->nLinhas; i++)
		{
			if (is_boat(e->tab[i][j])) 
				c++;
		}

		for (i = 0; i < e->nLinhas; i++)
		{
			if (c == e->nSeg_colunas[j])
			{
				for (i = 0; i < e->nLinhas; i++)
				{
					if (e->tab[i][j] == '.')
						set_state (e,i, j, '~');
				}
			}
		}
		c = 0;
	} 
}

/** Preenche os espaços vazios onde sabemos que vao estar os barcos com os submarinos
    @param e apontador para ESTADO
    @return retorna 1 se as peças está bem posicionadas e 0 no caso contrario;
*/
int set_unknown_segments (ESTADO *e)
{
	int i, j, c = 0, r = 0, temp = 0;

	for (i = 0; i < e->nLinhas; i++)
	{
			
		for (j = 0; j < e->nColunas; j++)
		{
				if (!is_boat(e->tab[i][j]))
					c++;
		}

		for (j = 0; j < e->nColunas; j++)
		{
				if (e->nLinhas - c < e->nSeg_linhas[i])
				{
						
						if (e->tab[i][j] == '.')
						{
							set_state (e, i, j, 'O');
							c--;

       						r = match_segments(e,i,j);
       	 					r = r - temp;

        					if (r > 0 || r < 0)
           					r = 1;
        					else
            				r = 0;
						}
				}
		}
		c = 0;

	}

	for (j = 0; j < e->nColunas; j++)
	{
			
		for (i = 0; i < e->nLinhas; i++)
		{
			if  (!is_boat(e->tab[i][j]))
				c++;
		}

		for (i = 0; i < e->nLinhas; i++)
		{
			if (c <= e->nSeg_colunas[j])
			{
					if (e->tab[i][j] == '.')
					{			
						set_state (e,i, j, 'O');
						c--;
					}
			}
		}
		c = 0;
	}

	return r; 
}

/** Preenche os segmentos laterais de um barcos
    @param e apontador para ESTADO
    @return void
*/
void set_boat_borders (ESTADO *e)
{
	int i, j;

	for (i = 0; i < e->nLinhas; i++)
	{
		for (j = 0; j < e->nColunas; j++)
		{
			if (is_boat(e->tab[i][j + 1]) && !is_boat(e->tab[i][j - 1]) && e->tab[i][j] == 'O')
				set_state (e, i, j, '<');
		}
	}

	for (i = 0; i < e->nLinhas; i++)
	{
		 for (j = 0; j < e->nColunas; j++)
		 {
		 	if (is_boat(e->tab[i][j - 1]) && !is_boat(e->tab[i][j + 1]) && e->tab[i][j] == 'O')
				set_state (e, i, j, '>');
		 }
	}

	for (i = 0; i < e->nLinhas; i++)
	{
		for (j = 0;j < e->nColunas; j++)
		{
			 if (is_boat(e->tab[i+1][j]) && !is_boat(e->tab[i - 1][j]) && e->tab[i][j] == 'O') 
			 	set_state (e, i, j, '^');
		}
	}

	for (i = 0; i < e->nLinhas; i++)
	{
		for (j = 0; j < e->nColunas; j++)
		{
			if (is_boat(e->tab[i - 1][j]) && !is_boat(e->tab[i + 1][j]) && e->tab[i][j] == 'O')
				set_state (e, i, j, 'v');
		}
	}
}

/** Preenche os segmentos do meio de um barco da esquerda para direita
    @param e apontador para ESTADO
    @return void
*/
void fill_boat_from_left (ESTADO *e)
{
	int i, j, c = 0, flag = 0;

	for (i = 0; i < e->nLinhas; i++)
	{
		for (j = 0; j < e->nColunas; j++)
		{
			if (is_boat(e->tab[i][j]) && e->tab[i][j] == '<')
			{
				flag = 1;
				j++;
				while (flag == 1)
				{
					if (e->tab[i][j]=='O')
					{
						c++;
						if (c < e->nSeg_linhas[i] - 1)
						{
							set_state (e, i, j, '#');
						}
						j++;
					}
					else
					{
						flag = 0;
					}
				}
			}
		}
		c = 0;
	}
}

/** Preenche os segmentos do meio de um barco da direita para esquerda 
    @param e apontador para ESTADO
    @return void
*/
void fill_boat_from_right (ESTADO *e)
{
	int i, j, c = 0, flag = 0;

	for (i = e->nLinhas; i >= 0; i--)
	{
		for(j = e->nColunas; j>=0; j--)
		{
			if (is_boat(e->tab[i][j]) && e->tab[i][j] == '>')
			{
				flag = 1;
				j--;
				while(flag == 1)
				{
					if (e->tab[i][j] == 'O')
					{
						c++;
						if (c < e->nSeg_linhas[i] - 1)
						{
							 set_state (e, i, j, '#');
						}
						j--;
					}
					else
					{
						flag = 0;
					}
				}
			}
		}
		c = 0;
	}
}

/** Preenche os segmentos do meio de um barco do topo para baixo
    @param e apontador para ESTADO
    @return void
*/
void fill_boat_from_top (ESTADO *e)
{
	 int i, j, c = 0, flag = 0;

	 for (j = 0;j < e->nColunas; j++)	
	 {
	 	for (i = 0; i < e->nLinhas; i++)
		{
			if (is_boat(e->tab[i][j]) && e->tab[i][j] == '^')
			{
				flag = 1;
				i++;
				while (flag == 1)
				{
					if (e->tab[i][j] == 'O')
					{
						c++;
						if (c<e->nSeg_colunas[j] - 1)
						{
							 set_state (e, i, j, '#');							
						}
						i++;
					}
					else
					{
						flag = 0;
					}
				}	
			}
		}
		c = 0;
	 }
}

/** Preenche os segmentos do meio de um barco de baixo para cima 
    @param e apontador para ESTADO
    @return void
*/
void fill_boat_from_bottom (ESTADO *e)
{
	int i, j, c = 0, flag = 0;

	for (j = e->nColunas; j >= 0; j--)
	{
		for (i = e->nLinhas;i >= 0; i--)
		{
			 if (is_boat(e->tab[i][j]) && e->tab[i][j] == 'v')
			 {
			 	 flag = 1;
				 i--;
				 while (flag == 1)
				 {
				 	if (e->tab[i][j] == 'O')
					{
						c++;
						if (c < e->nSeg_colunas[j] - 1)
						{
							 set_state (e, i, j, '#');
						}
						i--;
					}
					else
					{
						flag = 0;
					}
				 }
			 }
		}
		c = 0;
	}
}

/** Preenche os barcos completos usando as funções auxiliares 
    @param e apontador para ESTADO
    @return void
*/
void add_boat_e3 (ESTADO *e)
{
	set_unknown_segments (e);

	set_boat_borders (e);

	fill_boat_from_left (e);

	fill_boat_from_right (e);

	fill_boat_from_top (e);

	fill_boat_from_bottom (e);
}

/** Verifica se o numero de segmentos de linhas e colunas estão correctamente distribuidos
    @param e apontador para ESTADO
    @param l linha
    @param c coluna
    @return retornando 1 no caso afirmativo e 0 caso nao se verifica
*/
int match_segments (ESTADO *e, int l, int c)
{
	int rl = 0, rc = 0, index,  count = 0;

	for (index = 0; index < e->nColunas; index++)	
	{
		if (is_boat(e->tab[l][index]))
		count++;
	}

	if (e->nLinhas - count < e->nSeg_linhas[l])
		rl = 1;


	for (index = 0; index < e->nColunas; index++)    
    {   
        if (is_boat(e->tab[index][c]))
        count++;
    } 
	
	if (e->nColunas - count < e->nSeg_colunas[c])
		rc = 1;
	

	return rl-rc;
}

/** Verifica se um tabuleiro é valido 
    @param e apontador para ESTADO
    @return void
*/
void validate (ESTADO *e)
{
	int r = 0;

	r = set_unknown_segments(e);

	if (r == 1)
		printf ("SIM\n");
	else
		printf ("NAO\n");

	undo(e);
}

/** Gera um número aleatorio de segmentos 
    @param e apontador para ESTADO
    @return void
*/
void init_segments(ESTADO *e)
{
	int i;
	time_t t;
	srand ((unsigned) time(&t));
	for (i = 0; i < e->nLinhas; i++)
	{
		e->nSeg_linhas[i] = rand() % (abs(e->nLinhas - e->nColunas) + 1);
	}
	
	for (i = 0; i < e->nColunas; i++)
	{
		e->nSeg_colunas[i] = rand() % abs((e->nColunas - e->nLinhas) + 1);
	}
}

/** Gera um tabuleiro e os segmentos de barco aleatórios 
    @param e apontador para ESTADO
    @param l linha
    @param c coluna
    @return void
*/
void init_boats (ESTADO *e, int l, int c)
{
	int i, j;

	e->nLinhas = l;
	e->nColunas = c;

	init_segments (e);
	
	for (i=0; i < e->nLinhas; i++)
	{
		for (j=0; j < e->nColunas; j++)
		{
			 set_state (e, i, j, '.');
		}
	}
	add_water_e2 (e);
	add_boat_e3 (e);
	add_water_e1 (e);
	add_boat_e3 (e);

	for (i = 0; i < e->nLinhas; i++)
	{
		for (j = 0; j < e->nColunas; j += rand() % 2 + 1)
		{
			set_state (e, i, j, '.');
		}
	}
		
	e->conteudo = 1;
}

/** Verifica se houve mudanças no tabuleiro 
    @param e apontador para ESTADO
    @return retornando 1 se houve mudanças e zero caso o tabuleiro nao foi alterado
*/
int changes (ESTADO *e)
{
	ESTADO temp;
	int i, j, r = 0;

	for (i = 0; i < e->nLinhas; i++)
	{
		 for (j = 0;j < e->nColunas; j++)
		 {
		 	if (temp.tab[i][j] != e->tab[i][j])
			{
		 		temp.tab[i][j] = e->tab[i][j];
				r = 1;
			}
		 }
	}

	return r;
}

/** Resolve o tabuleiro aplicando as estrategias I II II e usando a funçao auxiliar para fixar o ponto quando as estrategias deixam de alterar o tabuleiro 
    @param e apontador para ESTADO
    @return retorna 0 se correr tudo bem
*/
int resolve (ESTADO *e)
{
	while (changes(e))
	{
		add_water_e2 (e);	
		add_water_e1 (e);
	}
	add_boat_e3 (e);
	add_water_e2 (e);
	
	return 0;
}

