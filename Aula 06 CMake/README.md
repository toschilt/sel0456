# CMAKE

O CMAKE é um auxiliar para compilação de programas como um Makefile.

Para utilizá-lo, é necessário criar um arquivo `CMakeLists.txt`, que conterá as informações de compilação

O documento de exemplo contêm o mínimo necessário para o funcionamento do programa

Após criado o documento, é necessário utilizar o comando para a criação dos documentos de compilação. Isso pode ser realizado utilizando `cmake -B <diretorio>`, em que diretório é a pasta destino para criação dos arquivos

Em seguida, o código pode ser compilado utilizando o `make` convencional, através do comando `make -C <diretorio>`. Isso criará um executável com o nome explicado no txt.

Por fim, o programa pode ser executado através do comando `<comando>/<executavel>`