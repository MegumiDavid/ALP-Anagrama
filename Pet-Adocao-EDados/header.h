#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

using namespace std;

//struct das listas ligadas
struct no{
    int codigo;
    char nome[TAM];
    char especie[TAM];
    char raca[TAM];
    char sexo[TAM];
    int idade;
    char carc_gerais[TAM];
    char hora_adicionado[TAM];
    char hora_ultima_alteracao[TAM];
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

//insere alfabeticamente um no em uma lista
void insere_alfabeticamente(no **lista, no *novo)
{
    no *aux, *aux2;
    aux = *lista;
    if (aux == NULL || stricmp(aux->nome, novo->nome)>=0) 
    {
        novo->prox = (*lista);
        (*lista) = novo;
    }
    else 
    {
        aux2 = aux;
        while (aux2->prox != NULL && stricmp(aux2->prox->nome, novo->nome)<0) 
        {
            aux2 = aux2->prox;
        }
        novo->prox = aux2->prox;
        aux2->prox = novo;
    }
}

// funcao que recebe parametros para inserir itens em uma lista ligada
void insere(no **lista){ // lista = NULL
    no *aux;
    aux = (no *) malloc(sizeof(no));
    int cod, idd, errosex=1, errocod=0;
    char nom[TAM], esp[TAM], rac[TAM], sex[TAM], carc_g[TAM];
    
    //valida e insere dados na lista
    //horario de insersao dos dados (e, por enquanto, hora da ultima alteraçao)
    //pega a hora (0)
    time_t agora = time(0);
    // converte para string (formato de data)
    string hora = ctime(&agora);
    strcpy (aux->hora_adicionado, hora.c_str());    
    strcpy (aux->hora_ultima_alteracao, hora.c_str());
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
    
    //ordena alfabeticamente
    insere_alfabeticamente(lista, aux);
}

// Remove item de uma lista ligada
void remove_no(int cod, no **lista, no **apaga, int n){
    int checa;
    no *aux, *aux2, *aux3;
    time_t agora = time(0);
    // converte para string (formato de data)
    string hora = ctime(&agora);
    aux = *lista;
    aux2 = NULL;
    aux3 = (no *) malloc(sizeof(no));
    if (aux != NULL && aux->codigo == cod)
    {
        *lista = aux->prox;
        if (n==1)
        {
            checa = checa_cod(*apaga,aux->codigo);
            while (checa==0)
            {
                valida_int(aux->codigo, "Codigo do item apagado ja esta na lista de itens apagados, por favor inserir novo codigo (para fins de recuperaçao): ");
                hora = ctime(&agora);
                checa = checa_cod(*apaga,aux->codigo);
            } 
            aux3->codigo=aux->codigo;
            strcpy(aux3->nome, aux->nome);
            strcpy(aux3->especie, aux->especie);
            strcpy(aux3->raca, aux->raca);
            strcpy(aux3->sexo, aux->sexo);
            aux3->idade = aux->idade;
            strcpy(aux3->carc_gerais, aux->carc_gerais);
            strcpy (aux3->hora_adicionado, aux->hora_adicionado); 
            strcpy (aux3->hora_ultima_alteracao, hora.c_str()); 
            aux3->prox = (*apaga);
            (*apaga) = aux3;
            cout<<"\nItem removido com sucesso.\n";
        }
        free (aux); 
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
        if (n==1)
        {
                        checa = checa_cod(*apaga,aux->codigo);
            while (checa==0)
            {
                valida_int(aux->codigo, "Codigo do item apagado ja esta na lista de itens apagados, por favor inserir novo codigo (para fins de recuperaçao): ");
                hora = ctime(&agora);
                checa = checa_cod(*apaga,aux->codigo);
            } 
            aux3->codigo=aux->codigo;
            strcpy(aux3->nome, aux->nome);
            strcpy(aux3->especie, aux->especie);
            strcpy(aux3->raca, aux->raca);
            strcpy(aux3->sexo, aux->sexo);
            aux3->idade = aux->idade;
            strcpy(aux3->carc_gerais, aux->carc_gerais);
            strcpy (aux3->hora_ultima_alteracao, hora.c_str()); 
            aux3->prox = (*apaga);
            (*apaga) = aux3;
            cout<<"\nItem removido com sucesso.\n";
        }
        free(aux);
    }
}

//funcao que altera informacoes de um no numa lista ligada
void altera(no **lista, int cod){
    no *aux;
    aux = (no *) malloc(sizeof(no));
    //seleciona o item da lista
    while (lista != NULL)
    {
        if ((*lista)->codigo == cod)
            break;
        else (*lista) = (*lista)->prox;
    }
    char nom[TAM], esp[TAM], rac[TAM], carc_g[TAM];
    int opcao, codigo, checa, idd;
    string hora; time_t agora;
    
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
            checa = checa_cod((*lista), codigo);
            if (checa == 0)
                cout<<"Codigo de cadastro ja existe na lista, selecione outro codigo!\n";
            else 
            {
                aux->codigo = codigo;
                strcpy (aux->nome, (*lista)->nome);
                strcpy (aux->especie, (*lista)->especie);
                strcpy (aux->raca, (*lista)->raca);
                strcpy (aux->sexo, (*lista)->sexo);
                aux->idade = (*lista)->idade;
                strcpy (aux->carc_gerais, (*lista)->carc_gerais);
                strcpy (aux->hora_adicionado, (*lista)->hora_adicionado);
                remove_no(cod,lista,lista,0);
                cout<<"Codigo de cadastro alterado com sucesso.\n";
            }
            break;
        case 2:
            validastring(nom,"Nome: ");
            aux->codigo = cod;
            strcpy (aux->nome, nom);
            strcpy (aux->especie, (*lista)->especie);
            strcpy (aux->raca, (*lista)->raca);
            strcpy (aux->sexo, (*lista)->sexo);
            aux->idade = (*lista)->idade;
            strcpy (aux->carc_gerais, (*lista)->carc_gerais);
            strcpy (aux->hora_adicionado, (*lista)->hora_adicionado);
            remove_no(cod,lista,lista,0);
            cout<<"Nome alterado com sucesso.\n";
            break;
        case 3:
            validastring(esp,"Especie: ");
            aux->codigo = cod;
            strcpy (aux->nome, (*lista)->nome);
            strcpy (aux->especie, esp);
            strcpy (aux->raca, (*lista)->raca);
            strcpy (aux->sexo, (*lista)->sexo);
            aux->idade = (*lista)->idade;
            strcpy (aux->carc_gerais, (*lista)->carc_gerais);
            strcpy (aux->hora_adicionado, (*lista)->hora_adicionado);
            remove_no(cod,lista,lista,0);
            cout<<"Especie alterada com sucesso.\n";
            break;
        case 4: 
            validastring(rac,"Raca: ");
            aux->codigo = cod;
            strcpy (aux->nome, (*lista)->nome);
            strcpy (aux->especie, (*lista)->especie);
            strcpy (aux->raca, rac);
            strcpy (aux->sexo, (*lista)->sexo);
            aux->idade = (*lista)->idade;
            strcpy (aux->carc_gerais, (*lista)->carc_gerais);
            strcpy (aux->hora_adicionado, (*lista)->hora_adicionado);
            remove_no(cod,lista,lista,0);
            cout<<"Raca alterada com sucesso.\n";
            break;
        case 5:
            aux->codigo = cod;
            strcpy (aux->nome, (*lista)->nome);
            strcpy (aux->especie, (*lista)->especie);
            strcpy (aux->raca, rac);
            aux->idade = (*lista)->idade;
            strcpy (aux->carc_gerais, (*lista)->carc_gerais);
            strcpy (aux->hora_adicionado, (*lista)->hora_adicionado);     
            if(strcmp((*lista)->sexo,"masculino")==0)
                strcpy(aux->sexo, "feminino");
            else strcpy(aux->sexo, "masculino");
            remove_no(cod,lista,lista,0);               
            cout<<"Sexo alterado com sucesso.\n";
            break;
        case 6:
            do
            {
                valida_int(idd, "Idade: "); 
                if (idd<0||idd>100) cout<<"Insira apenas idades entre 0 e 100 anos!\n";
            }while(idd<0||idd>100);
            aux->codigo = cod;
            strcpy (aux->nome, (*lista)->nome);
            strcpy (aux->especie, (*lista)->especie);
            strcpy (aux->raca, (*lista)->raca);
            strcpy (aux->sexo, (*lista)->sexo);
            aux->idade = idd;
            strcpy (aux->carc_gerais, (*lista)->carc_gerais);
            strcpy (aux->hora_adicionado, (*lista)->hora_adicionado);
            remove_no(cod,lista,lista,0);           
            cout<<"Idade alterada com sucesso.\n";
            break; 
        case 7: 
            validastring(carc_g,"Caracteristicas gerais: ");
            aux->codigo = cod;
            strcpy (aux->nome, (*lista)->nome);
            strcpy (aux->especie, (*lista)->especie);
            strcpy (aux->raca, (*lista)->raca);
            strcpy (aux->sexo, (*lista)->sexo);
            aux->idade = (*lista)->idade;
            strcpy (aux->carc_gerais, carc_g);
            strcpy (aux->hora_adicionado, (*lista)->hora_adicionado);
            remove_no(cod,lista,lista,0);        
            cout<<"Caracteristicas gerais alteradas com sucesso.\n";
            break;
    }
    //pega a hora
    agora = time(0);
    // converte para string (formato de data) e insere na lista
    hora = ctime(&agora);
    strcpy (aux->hora_ultima_alteracao, hora.c_str());    
    insere_alfabeticamente(lista,aux);
}

// funcao que busca por no pelo codigo de cadastro
void procura_codigo(no *lista, int cod){
    int x = 0;
    while (lista != NULL){
        if (lista->codigo == cod){
            x = 1;
            cout<<"\n\n"<<cod<<" - ENCONTRADO com sucesso"<<endl;
            cout<<"==========================================\n";
            cout<<"Nome: "<<lista->nome<<endl;
            cout<<"Especie: "<<lista->especie<<endl;
            cout<<"Raça: "<<lista->raca<<endl;
            cout<<"Sexo: "<<lista->sexo<<endl;
            cout<<"Idade: "<<lista->idade;
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<cod<<" - NÃO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao que busca por no pelo nome cadastrado
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
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl;
            cout<<"Data e hora inicial do cadastro: "<<lista->hora_adicionado;
            cout<<"Data e hora da ultima alteracao: "<<lista->hora_ultima_alteracao<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<nom<<" - NÃO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao que busca por no pela especie
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
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl;
            cout<<"Data e hora inicial do cadastro: "<<lista->hora_adicionado;
            cout<<"Data e hora da ultima alteracao: "<<lista->hora_ultima_alteracao<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<esp<<" - NAO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao que busca por no por especie e raça
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
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl;
            cout<<"Data e hora inicial do cadastro: "<<lista->hora_adicionado;
            cout<<"Data e hora da ultima alteracao: "<<lista->hora_ultima_alteracao<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<esp<<" + "<<rac<<" - NÃO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao que busca no por especie, raça e sexo
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
            cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl;
            cout<<"Data e hora inicial do cadastro: "<<lista->hora_adicionado;
            cout<<"Data e hora da ultima alteracao: "<<lista->hora_ultima_alteracao<<endl<<endl;
        }
        lista = lista->prox;
    }
    if(x==0){
        cout<<esp<<" + "<<rac<<" - NÃO foi ENCONTRADO"<<endl;
        cout<<"==========================================\n";
}}

// funcao que faz contagem de nos
int conta_animal(no* lista){
    int c = 0;
    while (lista != NULL){
        c++;
        lista = lista->prox;
    }
    return c;
}

// funcao que faz Contagem de nos por espécie;
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

// funcao que imprime todos os nos em uma lista
void imprime_todos(no* lista, const string msg1, const string msg2){
    cout<<"Listagem de todos os animais "<<msg1<<": \n";
    cout<<"==============================================\n\n";
    while (lista != NULL){
        cout<<"Codigo de cadastro: "<<lista->codigo<<endl;
        cout<<"Nome: "<<lista->nome<<endl;
        cout<<"Especie: "<<lista->especie<<endl;
        cout<<"Raca: "<<lista->raca<<endl;
        cout<<"Sexo: "<<lista->sexo<<endl;
        cout<<"Idade: "<<lista->idade<<endl;
        cout<<"Caracteristicas gerais: "<<lista->carc_gerais<<endl;
        cout<<"Data e hora inicial do cadastro: "<<lista->hora_adicionado;
        cout<<"Data e hora da "<<msg2<<lista->hora_ultima_alteracao<<endl<<endl;
        lista = lista->prox;
    }
    cout<<"\n";
}

//funcao que adiciona um item removido de volta na lista ligada
void adiciona_removido(int cod, no **lista, no *apaga){
    int checacod, novocod;
    no *aux;
    aux = (no *) malloc(sizeof(no));
    while (apaga->codigo != cod) apaga = apaga->prox;
    checacod = checa_cod(*lista, cod);
    if (checacod==0)
    {
        cout<<"O codigo do cadastro deletado foi substituido na lista por um codigo igual.";
        valida_int(novocod,"Novo codigo de cadastro do registro: ");
    }
    else novocod=cod;
    aux->codigo = novocod;
    strcpy(aux->nome, apaga->nome);
    strcpy(aux->especie, apaga->especie);
    strcpy(aux->raca, apaga->raca);
    strcpy(aux->sexo, apaga->sexo);
    aux->idade = apaga->idade;
    strcpy(aux->carc_gerais, apaga->carc_gerais);
    strcpy(aux->hora_adicionado, apaga->hora_adicionado);
    //pega a hora (0)
    time_t agora = time(0);
    // converte para string (formato de data)
    string hora = ctime(&agora); 
    strcpy (aux->hora_ultima_alteracao, hora.c_str());
    insere_alfabeticamente(lista, aux);
}

//funcao que adiciona um item da lista ligada na lista de adocao
void adiciona_adocao(int cod_adocao, no **adota, no *lista){
    no *aux;
    aux = (no *) malloc(sizeof(no));
    aux->codigo = cod_adocao;
    strcpy(aux->nome, lista->nome);
    strcpy(aux->especie, lista->especie);
    strcpy(aux->raca, lista->raca);
    strcpy(aux->sexo, lista->sexo);
    aux->idade = lista->idade;
    strcpy(aux->carc_gerais, lista->carc_gerais);
    strcpy(aux->hora_adicionado, lista->hora_adicionado);
    //pega a hora (0)
    time_t agora = time(0);
    // converte para string (formato de data)
    string hora = ctime(&agora); 
    strcpy (aux->hora_ultima_alteracao, hora.c_str());
    insere_alfabeticamente(adota, aux); 
}
