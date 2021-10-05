#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#define NUM_PALAVRAS 20
#define NUM_ERROS_TOTAL 5
using namespace std;

void cabecalho_anagrama() {
    cout << "\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/" << endl;
    cout << "\tJOGO ANAGRAMA" << endl;
    cout << "\tRegras: " << endl;
    cout << "\t  > forme palavras com as letras do quadro" << endl;
    cout << "\t  > total de " << NUM_PALAVRAS << " palavras" << endl;
    cout << "\t  > " << NUM_ERROS_TOTAL << " tentativas erradas termina o jogo" << endl;
    cout << "\n\t BOA SORTE !!!";
    cout << "\n=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/" << endl;
}

void quadro_palavras(char pl[])
{
    cout << "\nQuadro de letras: " << endl;
    for (int i = 0; i < 25; i++)
    {
        if (i % 5 == 0) { cout << endl; }
        cout << setw(5) << pl[i];
    }

}


int main()
{
    char caracter[25] = { 'O', 'N', 'I', 'O', 'A', 'C', 'R', 'C', 'A', 'O', 'E', 'I', 'D', 'A', 'R', 'N', 'E', 'N', 'D', 'L', 'D', 'H', 'T', 'A', 'E' };
    char bd_palavra[][12] = { "acaro","acida","acidentada","acidental","acre","acro",
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
         "rica", "rico", "roncar", "ronco", "tala", "talar", "tenda", "tendao" };

    char bd_acertos[20][12];

    //CABEÇALHO E INICIAÇÃO DE VARIAVEIS
    cabecalho_anagrama();
    int num_acertos = 0;
    int num_erros = 0;
    char resposta[12];
    int i = 0, j, ind, k, modo, acertosmax = 0, indf = 0 ;

    //SELEÇÃO MODO DE JOGO
    cout << "\n\nDeseja jogar em qual modo?" << endl;
    cout << "1 - Facil (10 acertos)" << endl;
    cout << "2 - Medio (20 acertos)" << endl;
    cout << "3 - Dificil (30 acertos)" << endl;
    cout << "\nDigite 1, 2 ou 3 para selecionar." << endl;
    do { cin >> modo; } while (modo < 1 || modo>3);
    if (modo == 1) acertosmax = 10;
    if (modo == 2) acertosmax = 20;
    if (modo == 3) acertosmax = 30;
    cin.ignore();
    //LOOP DO JOGO
    while (num_erros < 5)
    {
        quadro_palavras(caracter);
        cout << "\n\n>>> Acertos (" << num_acertos << " de " << NUM_PALAVRAS << ") e Erros (" << num_erros << " de " << NUM_ERROS_TOTAL << ")" << endl;

        ind = 3;
        //IMPRESSÃO BANCO DE ACERTOS
        if (num_acertos > 0)
        {
            cout << "\n>>> Acertos:" << endl;
            for (k = 0; k < num_acertos; k++)
                cout << bd_acertos[k] << endl;
        }

        //LEITURA DA RESPOSTA
        cout << "\n\t>>> Tentativa " << i + 1 << ": ";
        cin.getline(resposta, 12);

        //CHECAR SE É REPETIDO
        for (k = 0; k < num_acertos; k++)
        {
            if (strcmp(resposta, bd_acertos[k]) == 0) ind = 2;
        }
        //COMPARAR COM O BD
        for (j = 0; j < 123; j++)
        {
            if (ind == 2) break;
            //IF CORRETO E ERRADO
            if (strcmp(resposta, bd_palavra[j]) == 0)
            {
                ind = 0;
                break;
            }
            else ind = 1;
        }
        if (ind == 0)
        {
            num_acertos++;
            //strcpy_s(bd_acertos[i],sizeof bd_acertos[i], resposta);
        }
        if (ind == 1) num_erros++;
        i++;
        if (ind == 2) cout << "RESPOSTA REPETIDA!!!" << endl;

        if (num_acertos == acertosmax) 
        {
            indf = 1;
            break;
        }
    }
    
    //MENSAGEM FINAL DO JOGO
    if (indf == 1)
        cout << "\n\n\nPARABENS!!!! VOCE GANHOU!!!!" << endl;
    else
        cout << "\n\n\nVOCE PERDEU :(" << endl;
    

    return 0;
}