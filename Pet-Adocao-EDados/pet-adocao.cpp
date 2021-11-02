/*
[x] 1 - Inclusão de novos animais;
[ ] 2 - Remoção de animais;
[ ] 3 - Alteração de informações;
[x] 4 - Busca de um animal a partir do seu nome;
[x] 5 - Busca de animais por espécie;
[x] 6 - Busca de animais por espécie e raça;
[ ] 7 - Busca de animais por espécie, raça e sexo;
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
    char *nome;
    char *especie;
    char *raca;
    char *sexo;
    int idade;
    char *carc_gerais;
    struct no* prox;
};

// funcao 1 insere
void insere(char *nom, char *esp,char *rac, char *sex, int idd, char *carc_g, no **lista){ // lista = NULL
    no *aux;
    aux = (no *) malloc(sizeof(no));
    aux->nome = nom;
    aux->especie = esp;
    aux->raca = rac;
    aux->sexo = sex;
    aux->idade = idd;
    aux->carc_gerais = carc_g;
    aux->prox = (*lista);
    (*lista) = aux;
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
void procura_especie(no *lista, char *esp){
    int x = 0;
    while (lista != NULL){
        if (strcmp(lista->especie,esp) == 0){
            x = 1;
            cout<<"\n\n"<<esp<<" - ENCONTRADO com sucesso"<<endl;
            cout<<"==========================================\n";
            cout<<"Nome: "<<lista->nome<<endl;
            cout<<"Raça: "<<lista->raca<<endl;
            cout<<"Sexo: "<<lista->sexo<<endl;
            cout<<"Idade: "<<lista->idade<<endl;
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<esp<<" - NÃO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao 6 - busca especie e raça
void procura_especie_raca(no *lista, char *esp, char *rac){
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
        cout<<"Nome: "<<lista->nome<<endl;
        cout<<"Especie: "<<lista->especie<<endl;
        cout<<"Raça: "<<lista->raca<<endl;
        cout<<"Sexo: "<<lista->sexo<<endl;
        cout<<"Idade: "<<lista->idade<<endl;
        cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl<<endl;
        lista = lista->prox;
    }
    cout<<"\n";
}

int main()
{
    int opcao;
    
    cout<<"      DavidPet - Adoção de Animais\n";
    cout<<"==========================================\n\n";
    
    no *lista = NULL; // inicializando o no, com NULL
    do{
        cout<<"\nMenu de opcoes\n";
        cout<<"==========================================\n";
        cout<<"1 - Inclusão de novos animais\n";
        cout<<"4 - Busca de um animal a partir do seu nome\n";
        cout<<"5 - Busca de animais por espécie\n";
        cout<<"6 - Procurar o animal pela especie e raça\n";
        cout<<"8 - Contagem (quantidade de animais)\n";
        cout<<"9 - Contagem por espécie\n";
        cout<<"10 - Listagem de todos os animais cadastrados\n";
        cout<<"0 - Sair do programa\n";

        cout<<"\nDigite a opcao: ";
        cin>>opcao; cin.ignore();

        switch(opcao){
            case 1:     
                char *nom;
                nom = (char *)malloc(TAM);
                char *esp;
                esp = (char *)malloc(TAM);
                char *rac;
                rac = (char *)malloc(TAM);
                char *sex;
                sex = (char *)malloc(TAM);
                int idd;
                char *carc_g;
                carc_g = (char *)malloc(TAM);
                cout<<"\n\nDados do animal\n";
                cout<<"==========================================\n";
                cout<<"Nome: "; cin.getline(nom,TAM);
                cout<<"Especie: "; cin.getline(esp,TAM);
                cout<<"Raca: "; cin.getline(rac,TAM);
                cout<<"Sexo: "; cin.getline(sex,TAM);
                cout<<"Idade: "; cin>>idd; cin.ignore();
                cout<<"Caracteristicas gerais: "; cin.getline(carc_g,TAM);
                cout<<"\n\n";
                insere(nom,esp,rac,sex,idd,carc_g, &lista);break;
                
            case 4: 
                cout<<"Nome: "; cin.getline(nom,TAM);
                procura_nome(lista,nom);
                break;
            case 5:
                cout<<"Especie: "; cin.getline(esp,TAM);
                procura_especie(lista,esp);
                break;
            case 6:
                cout<<"Especie: "; cin.getline(esp,TAM);
                cout<<"Raça: "; cin.getline(rac,TAM);
                procura_especie_raca(lista,esp,rac);
                break;
            case 8: 
                cout<<"Numero de animais: "<<conta_animal(lista)<<"\n\n\n";
                break;
            case 9: 
                cout<<"Contagem de qual especie? ";
                cin.getline(esp,TAM);
                cout<<"Numero de animais da especie "<<esp<<": "<<conta_esp(lista,esp)<<"\n\n\n";
                break;
            case 10: imprime_todos(lista); break;
        }
    }while(opcao!=0);
    return 0;
}
