#include <string>
#include <vector>
#include <iostream>

class Registro
{
    private:
        std::string nome;
        int key;

    public:
        Registro(std::string nome, int key)
        {
            setNome(nome);
            setKey(key);
        }

        std::string getNome()
        {
            return nome;
        }

        int getKey()
        {
            return key;
        }   

        void setNome(std::string nome)
        {
            this->nome = nome;
        }

        void setKey(int key)
        {
            this->key = key;
        }

        void printRegistro()
        {
            std::cout << "Registro = {nome = " 
                      << nome 
                      << ", key = "
                      << key
                      << "}";
        }   
};

class ConjuntoRegistros
{
    private:
        std::vector<Registro> vetorRegistros;
        int numRegistros;

    public:
        ConjuntoRegistros()
        {
            numRegistros = 0;
        }

        std::vector<Registro> getVetorRegistros()
        {
            return vetorRegistros;
        }

        int getNumRegistros()
        {
            return numRegistros;
        }

        void pushNovoRegistro(Registro novoRegistro)
        {
            vetorRegistros.push_back(novoRegistro);
            numRegistros++;
        }

        void ordenarRegistros()
        {
            //Variáveis para iteração.
            int i = 0, j = 0;
            int n = numRegistros;

            //Flag
            int s = 1;

            for(; i <= (n+1) && s != 0; i++)
            {
                s = 0;
                
                for(j = 0; j < (n-1); j++)
                {
                    if(vetorRegistros[j].getKey() > vetorRegistros[j+1].getKey())
                    {
                        Registro t = vetorRegistros[j];
                        vetorRegistros[j] = vetorRegistros[j+1];
                        vetorRegistros[j+1] = t;
                        s++;
                    }
                }
                n--;
            }
        }

        void printConjuntoRegistros()
        {   
            if(numRegistros == 0)
            {
                std::cout << "Não há registros armazenados!" << std::endl;
            }
            else
            {
                for(int i = 0; i < numRegistros; i++)
                {
                    vetorRegistros[i].printRegistro();
                    std::cout << std::endl;
                }
            }
        }
};

void initializeRegistros(ConjuntoRegistros *registros)
{
    Registro registro1("bill", 3);
    registros->pushNovoRegistro(registro1);

    Registro registro2("neil", 4);
    registros->pushNovoRegistro(registro2);

    Registro registro3("john", 2);
    registros->pushNovoRegistro(registro3);

    Registro registro4("rick", 5);
    registros->pushNovoRegistro(registro4);

    Registro registro5("alex", 1);
    registros->pushNovoRegistro(registro5);
}

int main(void)
{
    ConjuntoRegistros *registros = new ConjuntoRegistros();
    initializeRegistros(registros);
    registros->ordenarRegistros();
    registros->printConjuntoRegistros();

    return 0;
}

