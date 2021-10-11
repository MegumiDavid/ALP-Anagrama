#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//macros
#define NUM_ERROS_TOTAL 5
#define TAMANHO_BANCO 123
#define h GetStdHandle (STD_OUTPUT_HANDLE)


//funcao que valida int
void valida_int(int &numero, const std::string msg)
{
    //impede casos de cin.fail (so por precaucao):
        SetConsoleTextAttribute(h,11); // ciano
        std::cout << msg;
        std::cin >> numero;
        while (std::cin.fail())
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Erro de entrada, tente novamente.\n";
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            SetConsoleTextAttribute(h,11); // ciano
            std::cout << msg;
            std::cin >> numero;
        }           
}


//funcao que imprime o cabecalho do jogo
void cabecalho_anagrama(int vitorias, int derrotas, int desistencias)
{
    
    SetConsoleTextAttribute(h,10); // verde
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
    std::cout<<"\n\t\tPlacar: "<<std::endl;
    SetConsoleTextAttribute(h,14); // amarelo
    std::cout<<"\t\t  >> Vitorias: ";
    SetConsoleTextAttribute(h,10); // verde
    std::cout<< vitorias <<std::endl;
    SetConsoleTextAttribute(h,14); // amarelo
    std::cout<<"\t\t  >> Derrotas: ";
    SetConsoleTextAttribute(h,12); // vermelho
    std::cout<< derrotas <<std::endl;
    SetConsoleTextAttribute(h,14); // amarelo
    std::cout<<"\t\t  >> Desistencias: ";
    SetConsoleTextAttribute(h,15); // branco
    std::cout<< desistencias << std::endl;


    SetConsoleTextAttribute(h,10); // verde
    //quadro de regras do jogo, para informar o jogador das peculiaridades do jogo
    std::cout<<"\n\t\tRegras: "<<std::endl;
    SetConsoleTextAttribute(h,14); // amarelo
    std::cout<<"\n\t\t  >> Forme palavras com as letras do quadro"<<std::endl;
    std::cout<<"\t\t  >> Total de palavras depende da dificuldade"<<std::endl;
    std::cout<<"\t\t  >> "<<NUM_ERROS_TOTAL<<" tentativas erradas terminam o jogo"<<std::endl;
    std::cout<<"\t\t  >> Duas palavras repetidas contam como um erro. O contador reseta depois do erro, entao atencao!"<<std::endl;
    SetConsoleTextAttribute(h,10); // verde
    std::cout<<"\n\t\t BOA SORTE !!!\n";

    std::cout<<"\n\t\tComandos especiais: "<<std::endl;
    SetConsoleTextAttribute(h,14); // amarelo
    std::cout<<"\n\t\t  >> Digite 'limpar' para limpar a tela se quiser"<<std::endl;
    std::cout<<"\t\t  >> Digite 'sair' para fechar o jogo (ou desistir da rodada atual)"<<std::endl;
    std::cout<<"\t\t  >> Digite 'bancop' para ver o banco de palavras"<<std::endl;
    std::cout<<"\t\t  >> Digite 'creditos' para abrir o menu de creditos (obs, isso vai terminar sua rodada atual!)"<<std::endl;
    std::cout<<"\t\t  >> Digite o nome da melhor universidade de Campinas para ver a opcao secreta!"<<std::endl;
    SetConsoleTextAttribute(h,10); // verde
    std::cout<<"\n\t\tObs: os comandos devem ser digitados apos a escolha da dificuldade! "<<std::endl;
    SetConsoleTextAttribute(h,13); // rosa
    std::cout<<"\n\n\t   =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    SetConsoleTextAttribute(h,15); // branco
}


//funcao para o menu de creditos
void creditos(int& continua)
{
    system("cls");
    SetConsoleTextAttribute(h,14); // amarelo
    std::cout << std::endl << R"(
               ######  ########  ######## ########  #### ########  #######   ######  
              ##    ## ##     ## ##       ##     ##  ##     ##    ##     ## ##    ##    ###
              ##       ##     ## ##       ##     ##  ##     ##    ##     ## ##          ###
              ##       ########  ######   ##     ##  ##     ##    ##     ##  ######  
              ##       ##   ##   ##       ##     ##  ##     ##    ##     ##       ##    
              ##    ## ##    ##  ##       ##     ##  ##     ##    ##     ## ##    ##    ###
               ######  ##     ## ######## ########  ####    ##     #######   ######     ###
                                                                   
    )" << '\n';
    SetConsoleTextAttribute(h,9); // azul
    std::cout << std::endl << R"(
              ___       _   _                 __   __            _           
             / _ \     | | | |                \ \ / /           (_)          
            / /_\ \_ __| |_| |__  _   _ _ __   \ V /  __ ___   ___  ___ _ __ 
            |  _  | '__| __| '_ \| | | | '__|  /   \ / _` \ \ / / |/ _ \ '__|
            | | | | |  | |_| | | | |_| | |    / /^\ \ (_| |\ V /| |  __/ |   
            \_| |_/_|   \__|_| |_|\__,_|_|    \/   \/\__,_| \_/ |_|\___|_|   
                                                                   
    )" << '\n';
    SetConsoleTextAttribute(h,13); // rosa
    std::cout << std::endl << R"(
            ______            _     _  ___  ___                           _ 
            |  _  \          (_)   | | |  \/  |                          (_)
            | | | |__ ___   ___  __| | | .  . | ___  __ _ _   _ _ __ ___  _ 
            | | | / _` \ \ / / |/ _` | | |\/| |/ _ \/ _` | | | | '_ ` _ \| |
            | |/ / (_| |\ V /| | (_| | | |  | |  __/ (_| | |_| | | | | | | |
            |___/ \__,_| \_/ |_|\__,_| \_|  |_/\___|\__, |\__,_|_| |_| |_|_|
                                                     __/ |                  
                                                    |___/                     
    )" << '\n';
    SetConsoleTextAttribute(h,11); // ciano
    std::cout << std::endl << R"(
               ___        ____          ___  _                                       
              |_  |      |____|        / _ \| |                                      
                | | ___   __ _  ___   / /_\ \ |_   ____ _ _ __ ___ _ __   __ _  __ _ 
                | |/ _ \ / _` |/ _ \  |  _  | \ \ / / _` | '__/ _ \ '_ \ / _` |/ _` |
            /\__/ / (_) | (_| | (_) | | | | | |\ V / (_| | | |  __/ | | | (_| | (_| |
            \____/ \___/ \__,_|\___/  \_| |_/_| \_/ \__,_|_|  \___|_| |_|\__, |\__,_|
                                                                          __/ |      
                                                                         |___/        
    )" << '\n';
    SetConsoleTextAttribute(h,12); // vermelho
    std::cout << std::endl << R"(
            ___  ____                  _  ___  ___                  _ _      ____               
            |  \/  (_)                | | |  \/  |                 | | |    |____|            
            | .  . |_  __ _ _   _  ___| | | .  . | __ _  __ _  __ _| | |__   __ _  ___  ___ 
            | |\/| | |/ _` | | | |/ _ \ | | |\/| |/ _` |/ _` |/ _` | | '_ \ / _` |/ _ \/ __|
            | |  | | | (_| | |_| |  __/ | | |  | | (_| | (_| | (_| | | | | | (_| |  __/\__ \
            \_|  |_/_|\__, |\__,_|\___|_| \_|  |_/\__,_|\__, |\__,_|_|_| |_|\__,_|\___||___/
                       __/ |                             __/ |                            
                      |___/                             |___/                                
    )" << '\n';
    do
    {
        valida_int(continua,"\n\t\tObrigado por jogar! Deseja continuar jogando? (digite 1 para sim, 2 para nao) ");
        if(continua<1 || continua>2)
        {
            std::cout<<"\n\t        >> Insira apenas os valores 1 ou 2!\n";
        }
    } while (continua<1 || continua>2);
    SetConsoleTextAttribute(h,15); // branco
}


//saida manual pelo comando do menu
void saidamanual(int& continua)
{
    SetConsoleTextAttribute(h,13); // rosa
    std::cout<<"\n\n\t   =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    SetConsoleTextAttribute(h,15); // branco
    std::cout << std::endl << R"(
            ######                                                             
            #     # ######  ####  #  ####  ##### ###### #    #  ####  #   ##   
            #     # #      #      # #        #   #      ##   # #    # #  #  #  
            #     # #####   ####  #  ####    #   #####  # #  # #      # #    # 
            #     # #           # #      #   #   #      #  # # #      # ###### 
            #     # #      #    # # #    #   #   #      #   ## #    # # #    # 
            ######  ######  ####  #  ####    #   ###### #    #  ####  # #    # 
    )" << '\n';
    do
    {
        valida_int(continua,"\n\t\t>>> Voce desistiu! Deseja continuar jogando? (digite 1 para sim, 2 para nao) ");
        if(continua<1 || continua>2)
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Insira apenas os valores 1 ou 2!\n";
        }
    } while (continua<1 || continua>2);
    
}


//funcao derrota
void derrota(int& continua)
{
    SetConsoleTextAttribute(h,13); // rosa
    std::cout<<"\n\n\t   =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    SetConsoleTextAttribute(h,12); // vermelho
    std::cout << std::endl << R"(
            ######                                           
            #     # ###### #####  #####   ####  #####   ##   
            #     # #      #    # #    # #    #   #    #  #  
            #     # #####  #    # #    # #    #   #   #    # 
            #     # #      #####  #####  #    #   #   ###### 
            #     # #      #   #  #   #  #    #   #   #    # 
            ######  ###### #    # #    #  ####    #   #    #    
    )" << '\n';
    do
    {
        valida_int(continua,"\n\t\t>>> Voce perdeu! Deseja continuar jogando? (digite 1 para sim, 2 para nao) ");
        if(continua<1 || continua>2)
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Insira apenas os valores 1 ou 2!\n";
        }
    } while (continua<1 || continua>2);
    
    SetConsoleTextAttribute(h,15); // branco
}



//funcao vitoria
void vitoria(int& continua)
{
    SetConsoleTextAttribute(h,13); // rosa
    std::cout<<"\n\n\t   =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    SetConsoleTextAttribute(h,9); // azul
    std::cout << std::endl << R"(
            ##     ## #### ########  #######  ########  ####    ###    
            ##     ##  ##     ##    ##     ## ##     ##  ##    ## ##   
            ##     ##  ##     ##    ##     ## ##     ##  ##   ##   ##  
            ##     ##  ##     ##    ##     ## ########   ##  ##     ## 
             ##   ##   ##     ##    ##     ## ##   ##    ##  ######### 
              ## ##    ##     ##    ##     ## ##    ##   ##  ##     ## 
               ###    ####    ##     #######  ##     ## #### ##     ## 
    )" << '\n';
    do
    {
        valida_int(continua,"\n\t\t>>> Parabens, voce venceu! Deseja continuar jogando? (digite 1 para sim, 2 para nao) ");
        if(continua<1 || continua>2)
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Insira apenas os valores 1 ou 2!\n";
        }
    } while (continua<1 || continua>2);
    
    SetConsoleTextAttribute(h,15); // branco

}




//funcao secreta puc
void puc(int& continua)
{
    SetConsoleTextAttribute(h,13); // rosa
    std::cout<<"\n\n\t   =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    SetConsoleTextAttribute(h,9); // azul
    std::cout << std::endl << R"(
            ##     ## #### ########  #######  ########  ####    ###          ## ####   ##     ##  ######  
            ##     ##  ##     ##    ##     ## ##     ##  ##    ## ##         ##     ## ##     ## ##    ## 
            ##     ##  ##     ##    ##     ## ##     ##  ##   ##   ##        ##     ## ##     ## ##       
            ##     ##  ##     ##    ##     ## ########   ##  ##     ##       ########  ##     ## ##       
             ##   ##   ##     ##    ##     ## ##   ##    ##  #########       ##        ##     ## ##       
              ## ##    ##     ##    ##     ## ##    ##   ##  ##     ##       ##        ##     ## ##    ## 
               ###    ####    ##     #######  ##     ## #### ##     ##       ##         #######   ######                                      
                                                   ___         
                                                  |   |    
                                               ___|   |___ 
                                              |           |   
                                              '---.   .---'    
                                                  |   |
                                                  |   |
                                               _.-|___|-,_              
   
    )" << '\n';
    do
    {
        valida_int(continua,"\n\t\t>>> Parabens, HEROI DA PUC, voce venceu! Deseja continuar jogando? (digite 1 para sim, 2 para nao) ");
        if(continua<1 || continua>2)
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Insira apenas os valores 1 ou 2!\n";
        }
    } while (continua<1 || continua>2);
    
    SetConsoleTextAttribute(h,15); // branco
}


//funcao secreta puc
void unicamp(int& continua)
{
    SetConsoleTextAttribute(h,13); // rosa
    std::cout<<"\n\n\t   =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    SetConsoleTextAttribute(h,12); // vermelho
    std::cout << std::endl << R"(
             ######  ####### ######  ######  ####### #######    #        #     # #     # ###  #####     #    #     # ######  
             #     # #       #     # #     # #     #    #      # #       #     # ##    #  #  #     #   # #   ##   ## #     # 
             #     # #       #     # #     # #     #    #     #   #      #     # # #   #  #  #        #   #  # # # # #     # 
             #     # #####   ######  ######  #     #    #    #     #     #     # #  #  #  #  #       #     # #  #  # ######  
             #     # #       #   #   #   #   #     #    #    #######     #     # #   # #  #  #       ####### #     # #       
             #     # #       #    #  #    #  #     #    #    #     #     #     # #    ##  #  #     # #     # #     # #       
             ######  ####### #     # #     # #######    #    #     #      #####  #     # ###  #####  #     # #     # #       
                                                                                                                
    )" << '\n';
    do
    {
        valida_int(continua,"\n\t\t>>> Voce perdeu, UNICAMPER! Deseja continuar jogando? (digite 1 para sim, 2 para nao) ");
        if(continua<1 || continua>2)
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Insira apenas os valores 1 ou 2!\n";
        }
    } while (continua<1 || continua>2);
    
    SetConsoleTextAttribute(h,15); // branco
}


//funcao secreta puc
void faccamp(int& continua)
{
    SetConsoleTextAttribute(h,13); // rosa
    std::cout<<"\n\n\t   =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    SetConsoleTextAttribute(h,15); // branco
    std::cout << std::endl << R"(
            ######                                                             
            #     # ######  ####  #  ####  ##### ###### #    #  ####  #   ##   
            #     # #      #      # #        #   #      ##   # #    # #  #  #  
            #     # #####   ####  #  ####    #   #####  # #  # #      # #    # 
            #     # #           # #      #   #   #      #  # # #      # ###### 
            #     # #      #    # # #    #   #   #      #   ## #    # # #    # 
            ######  ######  ####  #  ####    #   ###### #    #  ####  # #    # 
    )" << '\n';
    do
    {
        valida_int(continua,"\n\t\t>>> NAO!! Deseja continuar jogando? (digite 1 para sim, 2 para nao) ");
        if(continua<1 || continua>2)
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Insira apenas os valores 1 ou 2!\n";
        }
    } while (continua<1 || continua>2);
    
    
}






//funcao que imprime o quadro de letras toda vez que eh chamada:
void quadro_letras(char pl[])
{
    SetConsoleTextAttribute(h,15); // branco
    std::cout<<"\n\t        Quadro de letras: "<<std::endl;
    SetConsoleTextAttribute(h,9); // azul
    for (int i=0; i<25; i++)
    {
        if (i % 5 == 0){std::cout<<"\n\t        ";}
        std::cout<<std::setw(5)<<pl[i];
    }

}



//funcao que imprime o banco de palavras toda vez que eh chamada:
void quadro_palavras(char pl[][12])
{
    SetConsoleTextAttribute(h,15); // branco
    std::cout<<"\n\t        Quadro de palavras: "<<std::endl;
    SetConsoleTextAttribute(h,9); // azul
    for (int i=0; i<TAMANHO_BANCO; i++)
    {
        if (i % 5 == 0){std::cout<<"\n\t        ";}
        std::cout<<std::setw(17)<<pl[i];
    }
    std::cout<<'\n';
}



//funcao para limpar a tela:
void limpa_tela(int vitorias, int derrotas, int desistencias)
{
    system("cls");
    cabecalho_anagrama(vitorias, derrotas, desistencias);
}



//funcao para validar a entrada de palavras:
void validainput(char input[], int n)
{
    int tamanho,i,caractere=0;

    do
    {
        SetConsoleTextAttribute(h,11); // ciano
        //impede casos de cin.fail (so por precaucao):
        std::cout<<"\n\t        > Tentativa " << n << ": ";
        std::cin.getline(input,12);
        while (std::cin.fail())
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Erro de entrada, tente novamente.";
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            SetConsoleTextAttribute(h,11); // ciano
            std::cout <<"\n\n\t        > Tentativa " << n << ": ";
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
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Insira apenas caracteres validos, tente novamente.\n";
        }
    } while (caractere==1);   
}
