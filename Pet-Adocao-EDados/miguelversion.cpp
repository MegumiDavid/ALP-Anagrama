/*
[x] 1 - Inclusão de novos animais;
[x] 2 - Remoção de animais;
[x] 3 - Alteração de informações;
[x] 4 - Busca de um animal a partir do seu nome;
[x] 5 - Busca de animais por espécie;
[x] 6 - Busca de animais por espécie e raça;
[x] 7 - Busca de animais por espécie, raça e sexo;
[x] 8 - Contagem (quantidade de animais);
[x] 9 - Contagem por espécie;
[x] 10 - Listagem de todos os animais cadastrados.
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#define TAM 50

using namespace std;

struct no{
    int codigo;
    char nome[TAM];
    char especie[TAM];
    char raca[TAM];
    char sexo[TAM];
    int idade;
    char carc_gerais[TAM];
    struct no* prox;
};

//funcao que valida int
void valida_int(int &numero, const string msg)
{
        cout << msg;
        cin >> numero;
        while (cin.fail())
        {
            cout<<"\nErro de entrada, tente novamente.\n";
            cin.clear();
            cin.ignore(9999, '\n');
            cout << msg;
            cin >> numero;
        }           
}

//funcao que valida string
void validastring(char input[], const string msg)
{
    cout << msg;
    cin.getline(input,TAM); 
    while (cin.fail())
    {
        cout << "\nErro de entrada, tente novamente.\n";
        cin.clear();
        cin.ignore(9999, '\n');
        cout << msg;
        cin.getline(input,TAM);
    }
}

// funcao que checa se o codigo existe na lista (pra validar o codigo e outras coisas)
int checa_cod(no *lista, int cod){
    while (lista != NULL)
    {
        if (lista->codigo == cod)
            return 0;
        lista = lista->prox;
    }
    return 1;
}


// funcao 1 insere
void insere(no **lista){ // lista = NULL
    no *aux;
    aux = (no *) malloc(sizeof(no));
    int cod, idd, errosex=1, errocod=0;
    char nom[TAM], esp[TAM], rac[TAM], sex[TAM], carc_g[TAM];
    
    //valida e insere dados na lista
    cout<<"\n\nDados do animal\n";
    cout<<"==========================================\n";
    //codigo
    do
    {
        valida_int(cod, "Codigo de cadastro: "); 
        errocod = checa_cod(*lista, cod);
        if (errocod==0) cout << "Codigo de cadastro ja existe na lista, selecione outro codigo!\n";
    } while(errocod==0);
    cin.ignore();
    aux->codigo = cod;
    //nome
    validastring(nom,"Nome: ");
    strcpy(aux->nome, nom);
    //especie
    validastring(esp,"Especie: ");
    strcpy(aux->especie, esp);
    //raca
    validastring(rac,"Raca: ");
    strcpy(aux->raca, rac);
    //sexo
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
    strcpy(aux->sexo, sex);
    //idade
    do
    {
        valida_int(idd, "Idade: "); 
        if (idd<0||idd>100) cout<<"Insira apenas idades entre 0 e 100 anos!\n";
    }while(idd<0||idd>100);
    aux->idade = idd; cin.ignore();
    //caracteristicas gerais
    validastring(carc_g,"Caracteristicas gerais: ");
    strcpy(aux->carc_gerais, carc_g);
    cout<<"\n\n";
    //proximo
    aux->prox = (*lista);
    (*lista) = aux;
}

// funcao 2 - remove item
void remove_no(int cod, no **lista){
    no *aux, *aux2;
    aux = *lista;
    aux2 = NULL;
    if (aux != NULL && aux->codigo == cod)
    {
        *lista = aux->prox;
        free (aux); 
        cout<<"\nItem removido com sucesso.\n";
        return;
    }
    else
    {
        while (aux != NULL && aux->codigo != cod)
        {
            aux2 = aux;
            aux = aux->prox;
        }
        if (aux == NULL)
            return;
        aux2->prox = aux->prox;
        free(aux);
        cout<<"\nItem removido com sucesso.\n";
    }
}

//funcao 3 - altera
void altera(no *lista, int cod){
    //seleciona o item da lista
    while (lista != NULL)
    {
        if (lista->codigo == cod)
            break;
        lista = lista->prox;
    }
    char nom[TAM], esp[TAM], rac[TAM], carc_g[TAM];
    int opcao, codigo, checa, idd;
    do{
        cout<<"\nAlterar quais informacoes?\n";
        cout<<"==========================================\n";
        cout<<"1 - Codigo de cadastro\n";
        cout<<"2 - Nome\n";
        cout<<"3 - Especie\n";
        cout<<"4 - Raca\n";
        cout<<"5 - Sexo\n";
        cout<<"6 - Idade\n";
        cout<<"7 - Caracteristicas gerais\n";
        cout<<"0 - Nao realizar mais nenhuma alteracao\n";
        
        valida_int(opcao,"\nDigite a opcao: ");
        cin.ignore();
        switch(opcao)
        {
            case 1:     
                valida_int(codigo, "Novo codigo de cadastro: ");
                checa = checa_cod(lista, cod);
                if (checa == 0)
                    cout<<"Codigo de cadastro ja existe na lista, selecione outro codigo!\n";
                else 
                {
                    lista->codigo = codigo;
                    cout<<"Codigo de cadastro alterado com sucesso.\n";
                }
                break;
            case 2:
                validastring(nom,"Nome: ");
                strcpy(lista->nome, nom);
                cout<<"Nome alterado com sucesso.\n";
                break;
            case 3:
                validastring(esp,"Especie: ");
                strcpy(lista->especie, esp);
                cout<<"Especie alterada com sucesso.\n";
                break;
            case 4: 
                    validastring(rac,"Raca: ");
                    strcpy(lista->raca, rac);
                    cout<<"Raca alterada com sucesso.\n";
                break;
            case 5:
                if(strcmp(lista->sexo,"masculino")==0)
                    strcpy(lista->sexo, "feminino");
                else strcpy(lista->sexo, "masculino");
                cout<<"Sexo alterado com sucesso.\n";
                break;
            case 6:
                do
                {
                    valida_int(idd, "Idade: "); 
                    if (idd<0||idd>100) cout<<"Insira apenas idades entre 0 e 100 anos!\n";
                }while(idd<0||idd>100);
                lista->idade = idd;
                cout<<"Idade alterada com sucesso.\n";
                break; 
            case 7: 
                validastring(carc_g,"Caracteristicas gerais: ");
                strcpy(lista->carc_gerais, carc_g);
                cout<<"Caracteristicas gerais alteradas com sucesso.\n";
                break;
        }
    }while(opcao!=0);

}

// funcao 4 - busca nome
void procura_nome(no *lista, char *nom){
    int x = 0;
    while (lista != NULL){
        if (strcmp(lista->nome,nom) == 0){
            x = 1;
            cout<<"\n\n"<<nom<<" - ENCONTRADO com sucesso"<<endl;
            cout<<"==========================================\n";
            cout<<"Especie: "<<lista->especie<<endl;
            cout<<"Raça: "<<lista->raca<<endl;
            cout<<"Sexo: "<<lista->sexo<<endl;
            cout<<"Idade: "<<lista->idade<<endl;
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<nom<<" - NÃO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao 5 - busca especie
void procura_especie(no *lista, char esp[]){
    int x = 0;
    while (lista != NULL){
        if (strcmp(lista->especie,esp) == 0){
            x = 1;
            cout<<"\n\n"<<esp<<" - ENCONTRADO com sucesso"<<endl;
            cout<<"==========================================\n";
            cout<<"Nome: "<<lista->nome<<endl;
            cout<<"Raca: "<<lista->raca<<endl;
            cout<<"Sexo: "<<lista->sexo<<endl;
            cout<<"Idade: "<<lista->idade<<endl;
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<esp<<" - NAO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao 6 - busca especie e raça
void procura_especie_raca(no *lista,  char esp[], char rac[]){
    int x = 0;
    while (lista != NULL){
        if (strcmp(lista->especie,esp) == 0 && strcmp(lista->raca,rac) == 0){
            x = 1;
            cout<<esp<<" + "<<rac<<" - ENCONTRADO com sucesso"<<endl;
            cout<<"==========================================\n";
            cout<<"Nome: "<<lista->nome<<endl;
            cout<<"Sexo: "<<lista->sexo<<endl;
            cout<<"Idade: "<<lista->idade<<endl;
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<esp<<" + "<<rac<<" - NÃO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao 7 - busca especie, raça e sexo
void procura_especie_raca_sexo(no *lista, char esp[], char rac[], char sex[]){
    int x = 0;
    while (lista != NULL){
        if (strcmp(lista->especie,esp) == 0 && strcmp(lista->raca,rac) == 0 && strcmp(lista->sexo,sex) == 0){
            x = 1;
            cout<<esp<<" + "<<rac<<" + "<<sex<<" - ENCONTRADO com sucesso"<<endl;
            cout<<"==========================================\n";
            cout<<"Nome: "<<lista->nome<<endl;
            cout<<"Sexo: "<<lista->sexo<<endl;
            cout<<"Idade: "<<lista->idade<<endl;
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<esp<<" + "<<rac<<" - NÃO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao 8 contagem de animais
int conta_animal(no* lista){
    int c = 0;
    while (lista != NULL){
        c++;
        lista = lista->prox;
    }
    return c;
}

// funcao 9 Contagem por espécie;
int conta_esp(no* lista, char *esp){
    int c = 0;
    while (lista != NULL){
        if (strcmp(lista->especie,esp) == 0){
            c++;
        }
        lista = lista->prox;
    }
    return c;
}

// funcao 10
void imprime_todos(no* lista){
    cout<<"Listagem de todos os animais cadastrados: "<<endl;
    cout<<"==============================================\n\n";
    while (lista != NULL){
        cout<<"Codigo de cadastro: "<<lista->codigo<<endl;
        cout<<"Nome: "<<lista->nome<<endl;
        cout<<"Especie: "<<lista->especie<<endl;
        cout<<"Raca: "<<lista->raca<<endl;
        cout<<"Sexo: "<<lista->sexo<<endl;
        cout<<"Idade: "<<lista->idade<<endl;
        cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl<<endl;
        lista = lista->prox;
    }
    cout<<"\n";
}

int main()
{
    int opcao, cod, idd, checa, errosex = 1;
    char nom[TAM], esp[TAM], rac[TAM], sex[TAM];
    cout<<"      DavidPet - Adoção de Animais\n";
    cout<<"==========================================\n\n";
    
    no *lista = NULL; // inicializando o no, com NULL
    do{
        cout<<"\nMenu de opcoes\n";
        cout<<"==========================================\n";
        cout<<"1 - Inclusao de novos animais\n";
        cout<<"2 - Remover animal\n";
        cout<<"3 - Alterar informacoes de um cadastro\n";
        cout<<"4 - Busca de um animal a partir do seu nome\n";
        cout<<"5 - Busca de animais por especie\n";
        cout<<"6 - Procurar o animal pela especie e raca\n";
        cout<<"7 - Procurar o animal pela especie, raca, sexo\n";
        cout<<"8 - Contagem (quantidade de animais)\n";
        cout<<"9 - Contagem por especie\n";
        cout<<"10 - Listagem de todos os animais cadastrados\n";
        cout<<"0 - Sair do programa\n";
        
        valida_int(opcao,"\nDigite a opcao: ");
        cin.ignore();
        switch(opcao){
            case 1:     
                insere(&lista);
                break;
            case 2:
                valida_int(cod, "Codigo de cadastro do animal que sera removido: "); 
                checa = checa_cod(lista, cod);
                if (checa == 0)
                    remove_no(cod, &lista);
                else 
                    cout<<"Codigo de cadastro nao existe na lista, selecione outro codigo!\n";
                break;
            case 3:
                valida_int(cod, "\nCodigo de cadastro do animal cujas informacoes serao alteradas: "); 
                checa = checa_cod(lista, cod);
                if (checa == 0)
                    altera(lista, cod);
                else 
                    cout<<"Codigo de cadastro nao existe na lista, selecione outro codigo!\n";                
                break;
            case 4: 
                validastring(nom,"Nome: ");
                procura_nome(lista,nom);
                break;
            case 5:
                validastring(esp,"Especie: ");
                procura_especie(lista,esp);
                break;
            case 6:
                validastring(esp,"Especie: ");
                validastring(rac,"Raca: ");
                procura_especie_raca(lista,esp,rac);
                break; 
            case 7:
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
            case 8: 
                cout<<"Numero de animais: "<<conta_animal(lista)<<"\n\n\n";
                break;
            case 9: 
                cout<<"Contagem de qual especie? ";
                validastring(esp,"Especie: ");
                cout<<"Numero de animais da especie "<<esp<<": "<<conta_esp(lista,esp)<<"\n\n\n";
                break;
            case 10: imprime_todos(lista); break;
        }
    }while(opcao!=0);
    return 0;
}
