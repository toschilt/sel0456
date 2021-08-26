# Compilação

Para realizar a compilação de um arquivo em C é necessário o uso do GCC
A instalação pode ser realizada utilizando * `sudo apt install build-essential`

Supondo um arquivo * `helloworld.c`, há alguns comandos que podem ser realizados:

- * `gcc helloworld.c` --> Cria um executável do programa nomeado * `a.out`
- * `gcc helloworld.c -o helloworld` --> Cria um executável do programa nomeado * `helloworld`
- * `gcc helloworld.c -c` --> Cria um arquivo com objetos alocáveis * `helloworld.o`
- * `gcc helloworld.c -s` --> Cria um código em assembly do programa, nomeado * `helloworld.s`


# Makefile

Um arquivo Makefile é utilizado para automatizar processos, facilitando a compilação de arquivos