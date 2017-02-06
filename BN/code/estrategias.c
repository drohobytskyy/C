#include"estrategias.h"


/** gera as coordenadas para serem candidatos a ser preenchidos por água
    @param coords apontador para ORIENT
    @param c caracter
    @return retorna 1 caso corre tudo como esperado
*/
int set_water_coords (ORIENT *coords, char c)
{
	switch (c){
	
		case '<' : 
			coords->N = 1;
			coords->S = 1;
			coords->E = 0; 
			coords->W = 1;
		break;

		case '>' :
			coords->N = 1;
			coords->S = 1;
			coords->E = 1; 
			coords->W = 0;
		break;

		case '#' :
			coords->N = 0;
			coords->S = 0;
			coords->E = 0; 
			coords->W = 0;
		break;

		case '^' : 
			coords->N = 1;
			coords->S = 0;
			coords->E = 1; 
			coords->W = 1;
		break;

		case 'v' :
			coords->N = 0;
			coords->S = 1;
			coords->E = 1; 
			coords->W = 1;
		break;

		case 'O' :
			coords->N = 1;
			coords->S = 1;
			coords->E = 1; 
			coords->W = 1;
		break;

		default :
			coords->N = 0;
			coords->S = 0;
			coords->E = 0; 
			coords->W = 0;
		return 0;	
	}
	return 1;
}

/** Faz reset as coordenadas
    @param coords apontador para ORIENT
    @return void
*/
void reset_coords (ORIENT *coords)
{
	coords->N = 0;
	coords->S = 0;
	coords->E = 0;
	coords->W = 0;
}

/** verifica se um dado segmento é pode ser um barco
    @param c caracter
    @return retorn 1 se for verdade
*/
int is_boat (char c)
{
	int r = 0;
	if (c == '<' || 
		c == '>' || 
		c == '<' || 
		c == '#' ||
		c == '^' || 
		c == 'v' || 
		c == 'v' || 
		c == 'O' || 
		c == 'o')

		{
			r = 1;
		}

	return r;
}

