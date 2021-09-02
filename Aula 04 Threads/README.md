# Tipos de Variáveis

### Extern

Variáveis extern são utilizadas para importar variáveis de outros arquivos.

### Static

Variáveis estáticas são um tipo de variável global. Estas são declaradas na memória de dados ao invés da Stack e não são destruidas assim que a função que as declara é encerrada

Variáveis estáticas são iniciadas como 0 por padrão, mas podem ser modificadas de forma literal caso desejado.


### Volatile

Variáveis do tipo volatile são utilizadas para armazenar endereços de memória ou valores que podem ser modificados por outro processo no caso de multi-threading

Uma variável do tipo volatile será sempre salva na memória RAM, nunca em um registrador


### Register

Variáveis do tipo register fazem com que a variável seja alocada em um registrador diretamente, para agilizar a velocidade

Não é tão útil atualmente, dado que compiladores fazem isso "automaticamente"


# Threads

Permitem que tarefas sejam executadas em paralelo com o código original

Para a utilização de threads, é necessário fazer uso da biblioteca `pthread.h`

Não é necessário mais de um núcleo para a utilização de threads. É possível fazer uso da função sleep.

O `sleep` cancela a execução da thread primária enquanto processa threads paralelas (análogo a aguardar uma interrupção).

* A stack não é compartilhada entre threads


### Criação

A criação de uma nova thread pode ser realizada através da função abaixo
`int pthread_create(pthread_t *thread, pthread_attr_t *atributos, rotina, restrict *args)`

A função acima retorna 0 caso tudo ocorra como esperado.

### Sequencia

A princípio, caso a rotina principal finalize antes da thread, o programa mata a thread e encerra com sucesso.

Caso se deseje aguardar o término da thread, é necessário utilizar a função `pthread_join(pthread_t thread, retorno)`


### Compartilhamento de Memória

Em caso de multi-threading, pode ocorrer de diferentes processos acessarem o mesmo espaço de memória

Assim, é necessário sincronizar o acesso aos dados, através de `semáforos`


## Semáforos

Semáforos permitem que uma linha de código seja executada apenas por uma thread específica

A utilização destes depende da biblioteca `semaphore.h`

