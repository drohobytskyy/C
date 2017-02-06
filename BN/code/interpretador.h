#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"estado.h"
#include<time.h>

/*Protótipo da funçao ler cujo comando é "l"*/
void ler (ESTADO *e,char *nome);

/*Protótipo da funçao auxiliar de leitoura de ficheiro*/
void ler_ficheiro (ESTADO *e, FILE *file);

/*Protótipo do interpretador de comandos*/
int interpretador (ESTADO *e, char *linha);

/*Protótipo da função "mostrar" cujo comando é "m"*/
void mostrar (ESTADO *e);

/*Protótipo da função "lAgua"*/
void lAgua (ESTADO *e,int num);

/*Protótipo da função "cAgua"*/
void cAgua (ESTADO *e,int num);

/*Protótipo da função "colocarChr"*/
void colocarChr (ESTADO*e, char l, int numL, int numC);

/*Protótipo da função carregar do ficheiro*/
void carregar (ESTADO *e);

/*Protótipo da funão escrever para ficheiro*/
void escrever (ESTADO *e,char *nome);

/*protótipo da função set_state para guardar o estado na stack*/
int set_state (ESTADO *e, int l, int c, char valor);

/*Protótipo da função defazer*/
void undo (ESTADO *);

/*protótipo da funçao que adiciona água a volta dos barcos (E1)*/
int add_water_e1 (ESTADO *e);

/*Protótipo da função que adiciona água nas linhas e colunas (E2)*/
void add_water_e2 (ESTADO *e);

/*Adiciona partes de barco desconhecidas no tabuleiro*/
int set_unknown_segments (ESTADO *e);

/*Adiciona os extremos de um barco*/
void set_boat_borders (ESTADO *e);

/*Preenche segmentos no meio de um barco de lado esquerdo*/
void fill_boat_from_left (ESTADO *e);

/*Preenche segmentos no meio de um barco do lado direito*/
void fill_boat_from_right (ESTADO *e);

/*Preenche segmentos no meio de um barco a partir do topo*/
void fill_boat_from_top (ESTADO *e);

/*Preenche segmentos no meio de um barco por baixo*/
void fill_boat_from_bottom (ESTADO *e);

/*Protótipo da função que adiciona segmentos de barcos (E3)*/
void add_boat_e3 (ESTADO *e);

/*Protótipo da função validar tabuleiro*/
void validate (ESTADO *e);

/*Protótipo da função que verifica se os segmentos coencidem*/
int match_segments (ESTADO *e, int l, int c);

/*Incicaliza linhas e colunas*/
void init_nColunas_nLinhas (ESTADO *e);

/*Incializa segmentos aleatoreos*/
void init_segments (ESTADO *e);

/*Inicializa as peças dos barcos*/
void init_boats (ESTADO *e,int l,int c);

/*Verifica se houve mudança no tabuleiro*/
int changes (ESTADO *e);

/*Resolver tabuleiro*/
int resolve (ESTADO *e);
