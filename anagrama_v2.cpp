#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#define NUM_ERROS_TOTAL 5
#define TAMANHO_BANCO 123


//funcao que imprime o cabecalho do jogo
void cabecalho_anagrama(){

    //titulo do jogo em arte ascii, para ficar bonitona deve ser visualizada em tela cheia quando em modo exe(arquivo executavel)
    std::cout << R"(
    ::::::'##::'#######:::'######::::'#######::::::::'###::::'##::: ##::::'###:::::'######:::'########:::::'###::::'##::::'##::::'###::::
    :::::: ##:'##.... ##:'##... ##::'##.... ##::::::'## ##::: ###:: ##:::'## ##:::'##... ##:: ##.... ##:::'## ##::: ###::'###:::'## ##:::
    :::::: ##: ##:::: ##: ##:::..::: ##:::: ##:::::'##:. ##:: ####: ##::'##:. ##:: ##:::..::: ##:::: ##::'##:. ##:: ####'####::'##:. ##::
    :::::: ##: ##:::: ##: ##::'####: ##:::: ##::::'##:::. ##: ## ## ##:'##:::. ##: ##::'####: ########::'##:::. ##: ## ### ##:'##:::. ##:
    '##::: ##: ##:::: ##: ##::: ##:: ##:::: ##:::: #########: ##. ####: #########: ##::: ##:: ##.. ##::: #########: ##. #: ##: #########:
     ##::: ##: ##:::: ##: ##::: ##:: ##:::: ##:::: ##.... ##: ##:. ###: ##.... ##: ##::: ##:: ##::. ##:: ##.... ##: ##:.:: ##: ##.... ##:
    . ######::. #######::. ######:::. #######::::: ##:::: ##: ##::. ##: ##:::: ##:. ######::: ##:::. ##: ##:::: ##: ##:::: ##: ##:::: ##:
    :......::::.......::::......:::::.......::::::..:::::..::..::::..::..:::::..:::......::::..:::::..::..:::::..::..:::::..::..:::::..::      
    )" << '\n';

    //quadro de regras do jogo, para informar o jogador das peculiaridades do jogo
    std::cout<<"\n\tRegras: "<<std::endl;
    std::cout<<"\n\t  >> Forme palavras com as letras do quadro"<<std::endl;
    std::cout<<"\t  >> Total de palavras depende da dificuldade"<<std::endl;
    std::cout<<"\t  >> "<<NUM_ERROS_TOTAL<<" tentativas erradas terminam o jogo"<<std::endl;
    std::cout<<"\n\t BOA SORTE !!!\n";

    std::cout<<"\n\tComandos especiais: "<<std::endl;
    std::cout<<"\n\t  >> Digite 'limpar' para limpar a tela se quiser"<<std::endl;
    std::cout<<"\t  >> Digite 'sair' para fechar o jogo"<<std::endl;
    //std::cout<<"\t  >> Digite 'menuesp' para abrir o menu de creditos (obs, isso vai terminar seu jogo!)"<<std::endl;
    std::cout<<"\n\tObs: os comandos devem ser digitados apos a escolha da dificuldade! "<<std::endl;
    std::cout<<"\n\n    =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
}



//funcao derrota
void derrota()
{
    std::cout<<"\n\n    =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    std::cout << std::endl << R"(
      ######                                           
      #     # ###### #####  #####   ####  #####   ##   
      #     # #      #    # #    # #    #   #    #  #  
      #     # #####  #    # #    # #    #   #   #    # 
      #     # #      #####  #####  #    #   #   ###### 
      #     # #      #   #  #   #  #    #   #   #    # 
      ######  ###### #    # #    #  ####    #   #    #    
    )" << '\n';
    std::cout<<"\n\tVoce perdeu, pressione enter para fechar o jogo: "<<std::endl;
    std::cin.ignore();
}



//funcao vitoria
void vitoria()
{
    std::cout<<"\n\n    =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    std::cout << std::endl << R"(
      ##     ## #### ########  #######  ########  ####    ###    
      ##     ##  ##     ##    ##     ## ##     ##  ##    ## ##   
      ##     ##  ##     ##    ##     ## ##     ##  ##   ##   ##  
      ##     ##  ##     ##    ##     ## ########   ##  ##     ## 
       ##   ##   ##     ##    ##     ## ##   ##    ##  ######### 
        ## ##    ##     ##    ##     ## ##    ##   ##  ##     ## 
         ###    ####    ##     #######  ##     ## #### ##     ## 
    )" << '\n';
    std::cout<<"\n\tParabens, voce venceu! Pressione enter para fechar o jogo: "<<std::endl;
    std::cin.ignore();
}



//saida manual pelo comando do menu
void saidamanual()
{
    std::cout<<"\n\n    =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    std::cout << std::endl << R"(
      ######                                                             
      #     # ######  ####  #  ####  ##### ###### #    #  ####  #   ##   
      #     # #      #      # #        #   #      ##   # #    # #  #  #  
      #     # #####   ####  #  ####    #   #####  # #  # #      # #    # 
      #     # #           # #      #   #   #      #  # # #      # ###### 
      #     # #      #    # # #    #   #   #      #   ## #    # # #    # 
      ######  ######  ####  #  ####    #   ###### #    #  ####  # #    # 
    )" << '\n';
    std::cout<<"\n\tVoce escolheu sair do jogo. Pressione enter para fechar o jogo: "<<std::endl;
    std::cin.ignore();
}



//funcao que imprime o quadro de letras toda vez que eh chamada:
void quadro_palavras(char pl[])
{
    std::cout<<"\n        Quadro de letras: "<<std::endl;
    for (int i=0; i<25; i++)
    {
        if (i % 5 == 0){std::cout<<"\n        ";}
        std::cout<<std::setw(5)<<pl[i];
    }

}



//funcao para limpar a tela:
void limpa_tela()
{
    system("cls");
    cabecalho_anagrama();
}



//funcao para validar a entrada de palavras:
void validainput(char input[], int n)
{
    int tamanho,i,caractere=0;

    do
    {
        //impede casos de cin.fail (so por precaucao):
        std::cout<<"\n        > Tentativa " << n << ": ";
        std::cin.getline(input,12);
        while (std::cin.fail())
        {
            std::cout<<"\n        >> Erro de entrada, tente novamente.";
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            std::cout <<"\n        > Tentativa " << n << ": ";
            std::cin.getline(input,12); ;
        }
   
        //transforma a entrada do usuario em minuscula e checa se os caracteres estao dentro dos valores da tabela ascii para letras minusculas:
        tamanho = strlen(input);
        for (i=0;i<tamanho;i++)
        {
            input[i] = std::tolower(input[i]);
            if (input[i]<97 || input[i]>122)
            {
                caractere = 1;
                break;
            }
            else caractere = 0;
        }

        if (caractere==1)
            std::cout<<"\n        >> Insira apenas caracteres validos, tente novamente.\n";
    } while (caractere==1);   
}



//funcao main do programa:
int main()
{
    //declaracaoo de variáveis:
    
    //int i usada para repeticoes 'for' e n para o loop do jogo 
    int i, n = 1, indicador, vit, modo, acertosmax = 0;
    char resposta[12];

    // Controla acertos/erros
    int num_acertos = 0; //acertos
    int num_erros = 0;  //erros

    //quadro de letras do jogo
    char caracter[25] = { 'O', 'N', 'I', 'O', 'A', 'C', 'R', 'C', 'A', 'O', 'E', 'I', 'D', 'A', 'R', 'N', 'E', 'N', 'D', 'L', 'D', 'H', 'T', 'A', 'E' };

    //banco de palavras
    char banco_palavra[][12] = { "acaro","acida","acidentada","acidental","acre","acro",
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

    //banco de acertos
    char b_acertos[30][12];

    
    //jogo:
    
    
    //menu inicial:
    cabecalho_anagrama();
    //SELEÇÃO MODO DE JOGO:
    std::cout << "\n\n\tDeseja jogar em qual modo?" << std::endl;
    std::cout << "\n\t>> 1 - Facil (10 acertos)" << std::endl;
    std::cout << "\t>> 2 - Medio (20 acertos)" << std::endl;
    std::cout << "\t>> 3 - Dificil (30 acertos)" << std::endl;
    //validacao de entrada:
    do
    {
        //impede casos de cin.fail (so por precaucao):
        std::cout << "\n\t  > Digite 1, 2 ou 3 para selecionar: ";
        std::cin >> modo;
        while (std::cin.fail())
        {
            std::cout<<"\n        >> Erro de entrada, tente novamente.\n";
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            std::cout << "\n\t  > Digite 1, 2 ou 3 para selecionar: ";
            std::cin >> modo;
        }
        //validacao de tamanho
        if (modo < 1 || modo>3)
            std::cout<<"\n        >> Insira apenas valores de 1 a 3!\n";
    } while (modo < 1 || modo>3);   
    
    if (modo == 1) acertosmax = 10;
    if (modo == 2) acertosmax = 20;
    if (modo == 3) acertosmax = 30;
    limpa_tela();
    std::cin.ignore();
    

    //LOOP DO JOGO:
    while (num_erros<5)
    {
        vit = 0;
        indicador = 0;
        quadro_palavras(caracter);
        std::cout << "\n\n        >>> Acertos (" << num_acertos << " de " << acertosmax << ") e Erros (" << num_erros << " de " << NUM_ERROS_TOTAL << ")" << std::endl;
         //IMPRESSÃO BANCO DE ACERTOS
        if (num_acertos > 0)
        {
            std::cout << "\n        >>> Banco de acertos:" << std::endl;
            for (i = 0; i < num_acertos; i++)
                std::cout << "         >> Palavra " << i+1 << ": " << b_acertos[i] << std::endl;
        }
        //leitura da resposta:
        std::cout<<'\n';
        validainput(resposta, n);
       
        //checa se eh um comando do menu:
        //limpa tela
        if (strcmp(resposta, "limpar") == 0)
        {
            limpa_tela();        
        }
        else if (strcmp(resposta, "sair")==0)
        {
            vit = 2;
            break;
        }
        //segue com o jogo:
        else
        {           
            //CHECAR SE É REPETIDO:
            for (i = 0; i < num_acertos; i++)
            {
                if (strcmp(resposta, b_acertos[i]) == 0)
                {
                    indicador = 2;
                    break;
                }
                }
                //COMPARAR COM O Banco de palavras:
                for (i = 0; i < TAMANHO_BANCO; i++)
                {
                    //se for repetida (ou o comando para sair) ja pula o processo repetitivo
                    if (indicador >= 2 ) break;
                    //IF CORRETO E ERRADO
                    if (strcmp(resposta, banco_palavra[i]) == 0)
                    {
                        indicador = 0;
                        break;
                    }
                    else indicador = 1;
                } 
                //Casos de indicador:
                switch (indicador)
                {
                //erro        
                case 1:
                    std::cout << "\n        >> Resposta errada! \n";
                    num_erros++;
                    break;
                //repetido
                case 2:
                    std::cout << "\n        >> Resposta repetida! \n";
                    break;
                //acerto
                default:
                    std::cout << "\n        >> Resposta certa! (+ respect)\n";
                    strcpy(b_acertos[num_acertos], resposta);
                    num_acertos++;
                    break;
                }

                //caso de vitoria:
                if (num_acertos == acertosmax) 
                {
                    vit = 1;
                    break;
                }
                n++;
         
        }
    }
    //MENSAGEM FINAL DO JOGO
    if (vit == 1)
        vitoria();
    if (vit == 0)
        derrota();
    else 
        saidamanual();

    return 0; 
}