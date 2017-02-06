#ifndef ___ESTADO_H___
#define ___ESTADO_H___

#include"stack.h"

#define MAX_BUF 1024
#define DIM_TAB_X 100 
#define DIM_TAB_Y 100 

/** Estrutura do tabuleiro*/
typedef struct
{
    int nLinhas;
    int nColunas;
    int nSeg_linhas [DIM_TAB_X];
    int nSeg_colunas [DIM_TAB_Y];
	int conteudo;
    char tab [DIM_TAB_X] [DIM_TAB_Y];
    int num_cmd;
    STACK *stack;
}ESTADO;

#endif

