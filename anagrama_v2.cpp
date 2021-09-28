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
    char caracter[25] = {'O', 'N', 'I', 'O', 'A', 'C', 'R', 'C', 'A', 'O', 'E', 'I', 'D', 'A', 'R', 'N', 'E', 'N', 'D', 'L', 'D', 'H', 'T', 'A', 'E'};
    const char *bd_palavra[] = {"acaro","acida","acidentada","acidental","acre","acro",
         "adir","adro","alada","alao","alar","alarde","aldea","aldeao","alea", "anal",
         "anao", "andar", "anta", "ante", "arada", "arandela", "cada", "cade", "cadela",
         "cair", "calda", "cana", "canal", "candeeiro", "caneta", "canteiro", "carao",
         "cardeal", "caro", "cenica", "cenico", "cercada", "cercar", "cerco", "cerda",
         "cidada", "cidade", "cidadela", "cinco", "cine", "cinta", "circo", "cirio",
         "coada", "coar", "conica", "conico", "corda", "cordao", "cria", "criaçao", 
         "criada", "criar", "crina", "cronica", "cronico", "dada", "danar", "dedada", 
         "dedal", "dedao", "dedicada", "dedicar", "dela", "dentada", "dental", "dica",
         "dieta", "entalada", "entalar", "etnica", "etnico", "idade", "iene", "inalar",
         "inca", "inercia", "ironia", "ironica", "ironico", "laca", "lacaio", "ladina",
         "ladino", "ladra", "ladrao", "nada", "nadar", "neta", "ninar", "nordica", "nordico",
         "ocidental", "ocre", "oral", "orca", "ordenada", "ordenar", "ordinal", "orientada",
         "oriental", "orla", "orlada", "radical", "raio", "rala", "rale", "ranheta", "reinar",
         "rica", "rico", "roncar", "ronco", "tala", "talar", "tenda", "tendão"};
         
    char bd_acertos[30];
    

    cabecalho_anagrama();
    
    cout<<"\nQuadro de letras: "<<endl;
    for (int i=0; i<25; i++)
    {
        if (i % 5 == 0){cout<<endl;}
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