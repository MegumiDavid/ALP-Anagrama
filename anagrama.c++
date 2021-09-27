#include <iostream>
#include <string.h>
#include <iomanip>
#define NUM_PALAVRAS 20
#define NUM_ERROS_TOTAL 5
using namespace std;

void cabecalho_anagrama(){
    cout<<"\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/"<<endl;
    cout<<"\tJOGO ANAGRAMA"<<endl;
    cout<<"\tRegras: "<<endl;
    cout<<"\t  > forme palavras com as letras do quadro"<<endl;
    cout<<"\t  > total de "<<NUM_PALAVRAS<<" palavras"<<endl;
    cout<<"\t  > "<<NUM_ERROS_TOTAL<<" tentativas erradas termina o jogo"<<endl;
    cout<<"\n\t BOA SORTE !!!";
    cout<<"\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/"<<endl;
}


int main()
{
    char caracter[21] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};
    char bd_palavra[] = "trepadeira esquiador refrescar filtro sereia claustrofobia boato lupa escravo praga andares bocejo democracia massagista arquitetura cobra atraente roupas luto begala";
    //char bd_acertos[];
    

    cabecalho_anagrama();
    
    cout<<"\nQuadro de letras: "<<endl;
    for (int i=0; i<strlen(caracter); i++)
    {
        if (i % 4 == 0){cout<<endl;}
        cout<<setw(5)<<caracter[i];
    }
    
    // Controla numero de acertos
    int num_acertos = 5; // rascunho
    int num_erros = 5; // rascunho
    cout<<"\n\n>>> Acertos ("<<num_acertos<<" de "<<NUM_PALAVRAS<<") e Erros ("<<num_erros<<" de "<<NUM_ERROS_TOTAL<<")"<<endl;
    
    // função cin para a palavra
    // Mostra os bd_acertor
    // Mostrar bd_palavras
    
    return 0;
}
