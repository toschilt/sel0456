# Tipos de Variáveis

### Extern

Variáveis extern são utilizadas para importar variáveis de outros arquivos.

### Static

Variáveis estáticas são um tipo de variável global. Estas são declaradas na memória de dados ao invés da Stack e não são destruidas assim que a função que as declara é encerrada

Variáveis estáticas são iniciadas como 0 por padrão, mas podem ser modificadas de forma literal caso desejado.


### Volatile

Variáveis do tipo volatile são utilizadas para armazenar endereços de memória ou valores que podem ser modificados por outro processo no caso de multi-threading


# Threads

Permitem que tarefas sejam executadas em paralelo com o código original

Para a utilização de threads, é necessário fazer uso da biblioteca `pthread.h'

A criação de uma nova thread pode ser realizada através da função abaixo
`int pthread_create(pthread_t *thread, pthread_attr_t *atributos, rotina, restrict *args)'

A função acima retorna 0 caso tudo ocorra como esperado.

