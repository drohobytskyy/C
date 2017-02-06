#include"interpretador.h"

/** Funão main, chama a funçao Interpretador e executa os comandos em ciclo
*/
int main()
{
	ESTADO e;
	char linha [MAX_BUF];
	e.conteudo = 0;

	e.stack = create_stack();
	while (fgets(linha, MAX_BUF, stdin) && interpretador(&e, linha));

	return 0;
}
