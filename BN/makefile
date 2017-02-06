CFLAGS= -Wall -Wextra -ansi -pedantic -O2
OBJS=$(patsubst %.c,%.o,$(wildcard code/*.c))

bn:$(OBJS)
	        $(CC) $(CFLAGS) -o bn $(OBJS) $(LIBS)
			cd code; doxygen doxygen.bak
			ln -s doc/html/index.html documentation.html
			@echo done!

limpar:
	rm bn
	rm code/*.o
	rm -r doc
	rm documentation.html
	@echo done!

	
