/*
Nomes: Arthur Xavier, David Megumi, João Alvarenga, Miguel Magalhães                                                                 

RAs: 19087329, 21002558, 21000688, 21980446, 20079273

Opcionais funcionando: 1,2,3,4

Valor do Projeto: 10 pontos
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"
#define TAM 50

using namespace std;

int main()
{
    int opcao, cod, cod_ad=1, checa, errosex = 1;
    char nom[TAM], esp[TAM], rac[TAM], sex[TAM];
    cout<<"\n      DavidPet - Adocao de Animais\n";
    cout<<"==========================================\n\n";
    
    no *lista = NULL; // inicializando o no, com NULL
    no *temp = NULL; // inicializando o no, com NULL    
    no *apagados = NULL; // inicia com NULL
    no *adotados = NULL; // inicia com NULL
    do{
        cout<<"\nMenu de opcoes\n";
        cout<<"==========================================\n";
        cout<<"1 - Inclusao de novos animais\n";
        cout<<"2 - Remover animal\n";
        cout<<"3 - Alterar informacoes de um cadastro\n";
        cout<<"4 - Busca de um animal a partir do codigo de cadastro\n";
        cout<<"5 - Busca de um animal a partir do seu nome\n";
        cout<<"6 - Busca de animais por especie\n";
        cout<<"7 - Procurar o animal pela especie e raca\n";
        cout<<"8 - Procurar o animal pela especie, raca, sexo\n";
        cout<<"9 - Contagem (quantidade de animais)\n";
        cout<<"10 - Contagem por especie\n";
        cout<<"11 - Listagem de todos os animais cadastrados\n";
        cout<<"12 - Listagem de todos os animais apagados\n";
        cout<<"13 - Recuperar cadastro apagado\n";
        cout<<"14 - Registrar uma adocao\n";
        cout<<"15 - Listagem de todas as adocoes\n";
        cout<<"0 - Sair do programa\n";
        
        do
        {
            valida_int(opcao,"\nDigite a opcao: ");
            cin.ignore();
            if (opcao<0||opcao>15)
                cout<<"Insira apenas opcoes presentes no menu!";
        } while (opcao<0||opcao>15);
        switch(opcao){
            case 1:     
                insere(&lista);
                break;
            case 2:
                valida_int(cod, "Codigo de cadastro do animal que sera removido: "); 
                checa = checa_cod(lista, cod);
                if (checa == 0)
                    remove_no(cod, &lista, &apagados, 1);
                else 
                    cout<<"Codigo de cadastro nao existe na lista, selecione outro codigo!\n";
                break;
            case 3:
                valida_int(cod, "\nCodigo de cadastro do animal cujas informacoes serao alteradas: "); 
                checa = checa_cod(lista, cod);
                if (checa == 0)
                {
                    coloca_temp(cod, &temp, &lista);
                    remove_no(cod, &lista, &apagados, 0);
                    altera(&lista, &temp);
                    remove_no(cod, &temp, &apagados, 0);
                }
                else 
                    cout<<"Codigo de cadastro nao existe na lista, selecione outro codigo!\n";                
                break;
            case 4: 
                valida_int(cod,"Codigo de cadastro a buscar: ");
                procura_codigo(lista,cod);
                break;    
            case 5: 
                validastring(nom,"Nome: ");
                procura_nome(lista,nom);
                break;
            case 6:
                validastring(esp,"Especie: ");
                procura_especie(lista,esp);
                break;
            case 7:
                validastring(esp,"Especie: ");
                validastring(rac,"Raca: ");
                procura_especie_raca(lista,esp,rac);
                break; 
            case 8:
                validastring(esp,"Especie: ");
                validastring(rac,"Raca: ");
                do
                {
                    validastring(sex,"Sexo ('masculino' ou 'feminino'): "); 
                    int tamanho = strlen(sex);
                    for (int i = 0; i < tamanho; i++)
                    {
                        sex[i] = tolower(sex[i]);
                        if (sex[i]<97 || sex[i]>122)
                        {
                            cout<<"Insira apenas caracteres validos!\n";
                            errosex = 1;
                            break;
                        }
                    }
                    if (strcmp(sex,"masculino")== 0 || strcmp(sex,"feminino")==0) 
                        errosex = 0;
                    else 
                        {
                            errosex = 1;
                            cout<<"Insira apenas 'masculino' ou 'feminino'!\n";
                        }
                    } while (errosex==1); 
                    procura_especie_raca_sexo(lista,esp,rac,sex);
                break; 
            case 9: 
                cout<<"Numero de animais: "<<conta_animal(lista)<<"\n\n\n";
                break;
            case 10: 
                cout<<"Contagem de qual especie? ";
                validastring(esp,"Especie: ");
                cout<<"Numero de animais da especie "<<esp<<": "<<conta_esp(lista,esp)<<"\n\n\n";
                break;
            case 11: imprime_todos(lista, "cadastrados","ultima alteracao: "); break;
            case 12: imprime_todos(apagados, "apagados","ultima alteracao: "); break;
            case 13: 
                valida_int(cod, "\nCodigo de cadastro do animal a ser re-inserido: "); 
                checa = checa_cod(apagados, cod);
                if (checa == 0)
                {
                    adiciona_removido(cod, &lista, apagados);
                    remove_no(cod, &apagados, &apagados, 0);
                }
                else 
                    cout<<"Codigo de cadastro nao existe na lista, selecione outro codigo!\n";                
                break;
            case 14: 
                valida_int(cod, "\nCodigo de cadastro do animal que foi adotado: "); 
                checa = checa_cod(lista, cod);
                if (checa == 0)
                    {
                    adiciona_adocao(cod_ad, cod, &adotados, &lista);
                    cod_ad++;
                    remove_no(cod, &lista, &apagados, 0);                    
                    }
                else 
                    cout<<"Codigo de cadastro nao existe na lista, selecione outro codigo!\n";
                break;         
            case 15: imprime_todos(adotados, "adotados","adocao: "); break;
        }
    }while(opcao!=0);
    return 0;
}
