# GDB

O `GDB` é um *debugger* para C e C++, permitindo que o usuário veja passo a passo a execução do código.

Isso permite a análise de variáveis e chamadas de funções, facilitando a identificação de falhas e erros no programa.

O `GDB` pode ser utilizado via *socket* ou *pipe*. O uso de *pipe* é o padrão pelas IDEs

Para realizar um *debbug* utilizando *socket* para estabelecer comunicação com placas externas, por exemplo.


# LEFENCE

A `LIBEFENCE` é uma biblioteca que permite a identificação de *segmentation faults* no código. Esta permite localizar precisamente os pontos de falha, os acusando sempre que encontrados. 


# ASSERT

A biblioteca `assert` permite fazer com que o programa envie um erro caso os dados do programa não condizam com o esperado.

Ao executar `assert(condição)`, o programa verifica se a condição está de acordo com o previsto. Caso não esteja, é enviado um código.