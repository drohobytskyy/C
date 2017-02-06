#include"stack.h"

/** Cria uma stack vazia
*/
STACK *create_stack() {
	STACK *s = malloc(sizeof(STACK));
	init(s);
	return s;
}

/** incializa a stack a 0
	"param s apontador para STACK
*/
void init (STACK *s)
{
	s->n = 0;
		
}

/** Verifica se a stack está vazia
    @param s apontador para STACK
    @return retorna 1 caso seja verdade
*/
int isEmpty (STACK *s)
{
	return (s->n == 0);
}

/** Determina o tamanho da stack 
    @param s apontador para STACK
    @return retorna o tamnaho
*/
int size (STACK *s)
{
	return (s->n);
}

/** Faz o push do elemento na stack
    @param s apontador para STACK
    @param i estrutura ELEM
    @return retorna 1 se houve mudanças e 0 caso nada foi alterado
*/
int push (STACK *s, ELEM i) 
{
	int r = 0;
	if (s->n == ARRAY_SIZE)
		r = 1;
	else
	{
		s->stack[s->n] = i;
		s->n++;
	}
	
	return r;
}

/** faz o pop de um elemento na stack 
    @param s apontador para STACK
    @return retorna 1 caso a stack está vazia
*/
int pop (STACK *s)
{
	int r = 0;
	if (s->n == 0)
	{
		r = 1;
	}
	else
	{
	s->n --;
	}
	return r;
}

/** poe no topo o elemento na stack
    @param s apontador para stack
    @param v apontador para ELEM
    @return retorna 1 se a stack está vazia
*/
int top (STACK *s, ELEM *v)
{
	int r = 0;
	if (s->n == 0)
	{
		r = 1;
	}
	else
	{
		*v = s->stack[s->n-1];
	}
	
	return r;

}
