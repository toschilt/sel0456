# Desenvolvimento de Software para Sistemas Embarcados com Sistemas Operacionais (SEL0456)

### Configurando chaves para GitHub (Ubuntu)

A seguir veremos como podemos adicionar chaves ao GitHub com o objetivo de podermos
sicronizar nosso repositorio local com o repositório online.

1) Gerar novo par de chaves assimetricas
 
Comando: `ssh-keygen -t ed25519 -C "seu_email_git@exemplo.com"`

 * `-t ed25519` --> Especifica o tipo de algoritimo criptográfico utilizado na geração das chaves
 * `-C "seu_email_git@exemplo.com"` --> Especifica o e-mail associado ao par de chaves. Substituir este exemplo pelo seu e-mail no GitHub
 
Ao executar o comando de geração de chaves acima mencionado serão solicitadas duas informações, sendo ambas de preenchimento opcional: 

Informar o Local de salvamento e nome das chaves: `~/.ssh/GitHub`

Informar senha e repeti-la (caso não queira, pressionar enter)

2) Verificar se o programa gerenciador do SSH está funcionando em segundo plano

Comando: `eval "$(ssh-agent -s)"`

Ao executar o comando devemos ver na tela um numero "pid", o que significa que o processo referente ao gerenciador do SSH está funcionando

3) Adicionar a chave gerada anteriormente no gerenciador do SSH
 
Comando: `ssh-add ~/.ssh/GitHub`

 * `~/.ssh/GitHub` --> Especifica o local em que as chaves foram salvas
 
4) Adicionar a chave publica no GitHub
 
Primeiramente devemos copiar a chave publica que acabamos de gerar.

Comando: `cat ~/.ssh/GitHub.pub`

 * Este comando `cat` imprime na tela o conteudo do arquivo `~/.ssh/GitHub.pub` que foi passado como argumento

Selecionamos a chave publica com o mouse, clicamos com o botão direito do mouse em cima do texto selecionado e depois clicamos em "copiar". [Imagem exemplo.](https://github.com/vitorstraggiotti/sel0456/blob/main/img/terminal_copy_pub.png)

Com a chave publica copiada vamos ao GitHub e seguimos o seginte caminho: 

[Settings](https://docs.github.com/assets/images/help/settings/userbar-account-settings.png) -->
[SSH and GPG keys](https://docs.github.com/assets/images/help/settings/settings-sidebar-ssh-keys.png) -->
[New SSH key](https://docs.github.com/assets/images/help/settings/ssh-add-ssh-key.png)

Criar um titulo para sua chave (ex: computador casa, ubuntu, etc) e em seguida colar a chave no campo "key" e clicar em "add SSH key". [Imagem exemplo](https://docs.github.com/assets/images/help/settings/ssh-key-paste.png)

Agora seu computador e o site do GitHub podem se comunicar sem a necessidade de senhas cada vez que quiser sincronizar o seu repositorio local com o online.

DICA: Caso pretenda fazer o upload de alterações no repositorio local para o GitHub (será o caso desta diciplina) você deve clonar o repositorio utilizando o link referente a aba SSH. [Imagem exemplo](https://github.com/vitorstraggiotti/sel0456/blob/main/img/aba_SSH.png) 


### Utilizando o Emacs como IDE

Para instalar o Emacs no Ubuntu:

```bash
sudo apt install emacs
```

Infelizmente o Emacs não vem comn as opções habilitadas, e habilitá-las requer um esforço e um tempo muito grande. Felizmente, existem alguns utilitários para isso. Um bom exemplo disso é o [Spacemacs](https://www.spacemacs.org/).
Para instalar o Spacemacs, você pode seguir os passos indicados na web page anterior ou:
  
  ```bash
  cd ~
  git clone https://github.com/syl20bnr/spacemacs ~/.emacs.d
  ```
  
  Aí é só executar o emacs normalmente: 
  
  ```bash
  emacs
  ```
  
  Ele vai perguntar se você prefere o estilo `vim` ou `emacs`. Se você não sabe o que isso quer dizer, escolha `emacs`.
  
  > **Algumas dicas úteis:** pelo fato do Emacs ter sido escrito muito antes do DOS existir, quanto mais do Windows, ele utiliza algumas combinações de teclas pouco familiares aos iniciantes, devido aos diversos modelos de teclados existentes.
  
  > > Quando se quer indicar uma tecla pressionada simultaneamente com a tecla `Control`, por exemplo a tecla `Control` pressionada com a tecla `x`, simultaneamente, indica-se por `C-x`. Para a tecla `Alt` pressionada simultaneamente com uma tecla m, por exemplo, utiliza-se a notação: `M-m`. Em sistemas anteriores ao PC, a tecla `Alt` se chamava `Meta`, por isso o `M-`.
  
  > > A combinação `C-g` é utilizado como `CANCEL`, quando se quer, por exemplo, abortar alguma entrada de texto ou comando.
  
  > > O Emacs usa as teclas de **Cut**, **Copy** e **Paste** diferentes. Para o **Cut**, ele usa `C-w`, para o **Copy**, ele usa `M-w` e para o **Paste**, usa-se C-y. **No entanto**, se você preferir usar `C-x`, `C-c` e `C-v`, você pode escolher a opção `CUA Mode` no menu: `F10`->`Options`->`Use CUA keys`. Para ativar o menu, caso ele não esteja aparecendo, pressione `F10` **ou** `M-x menu-bar-mode`, para deixá-lo permanente. Nessa última opção, a combinação `M-x` irá abrir uma linha de comando para chamar funções internas escrita em `emacs-lisp`, que no caso foi `menu-bar-mode`.
  
  > > Em muitos casos é interessante ativar a barra de ferramentas, com: `M-x tool-bar-mode`.
  
  > > Para se visualizar as opções de comandos pelo menu de teclas, pressione `M-m`, tanto no modo `Emacs` quanto no modo `vim`, ou a tecla `Espaço` no modo `vim`.
  
  Existem muitos guias e tutoriais para o `Emacs` disponíveis na rede. O site oficial é: https://www.gnu.org/savannah-checkouts/gnu/emacs/emacs.html.
  
  Em português: no [IME](https://www.ime.usp.br/~rbrito/texts/emacs.html), [EmacsWiki](https://www.emacswiki.org/emacs/NovatoNoEmacs) e [MIT](http://web.mit.edu/Emacs/source/emacs-23.1/etc/tutorials/TUTORIAL.pt_BR).


### Instalação do `esp-idf`

Para instalar o IoT Development Framework da Espressif, siga os seguintes passos:

```bash
cd ~
mkdir esp
cd esp
git clone -b v4.3 --recursive https://github.com/espressif/esp-idf.git
cd esp-idf
./install.sh
```

O processo de instalação está finalizado nesse ponto.

Pode-se copiar um exemplo, dos vários disponíveis e rodar:

```bash
cd ~
mkdir Code
cd Code
cp -a ~/esp/esp-idf/examples/peripherals/ledc .
cd ledc
. ~/esp/esp-idf/export.sh
```

Para editar o exemplo:
```bash
emacs main/ledc_example_main.c
```

```bash
idf.py menuconfig
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor