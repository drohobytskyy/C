/*Etrutura orientação*/
typedef struct orient{
	int N;
	int S;
	int W;
	int E;
}ORIENT;

/*Protótipo do função que dado uma parte de um barco determina as posições livre para pôr agua*/
int set_water_coords (ORIENT *coords, char c);

/*Protótipo da função que faz reset às coordenadas*/
void reset_coords (ORIENT *coords);

/*protótipo da funão que recebe um caracter e determina se é parte de um barco retornando 1 no caso afirmativo*/
int is_boat (char c);
