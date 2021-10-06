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


//funcao que imprime o cabecalho do jogo
void cabecalho_anagrama(){
    
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
    std::cout<<"\t\t  >> Digite 'sair' para fechar o jogo"<<std::endl;
    std::cout<<"\t\t  >> Digite 'bancop' para ver o banco de palavras"<<std::endl;
    std::cout<<"\t\t  >> Digite 'creditos' para abrir o menu de creditos (obs, isso vai terminar seu jogo!)"<<std::endl;
    SetConsoleTextAttribute(h,10); // verde
    std::cout<<"\n\t\tObs: os comandos devem ser digitados apos a escolha da dificuldade! "<<std::endl;
    SetConsoleTextAttribute(h,13); // rosa
    std::cout<<"\n\n\t   =/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/="<<std::endl;
    SetConsoleTextAttribute(h,15); // branco
}


//funcao para o menu de creditos
void creditos()
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
    std::cout<<"\n\t\tObrigado por jogar! pressione 'enter' para fechar o jogo. "<<std::endl;
    std::cin.ignore();
    SetConsoleTextAttribute(h,15); // branco
}


//funcao derrota
void derrota()
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
    std::cout<<"\n\t\tVoce perdeu, pressione 'enter' para fechar o jogo. "<<std::endl;
    std::cin.ignore();
    SetConsoleTextAttribute(h,15); // branco
}



//funcao vitoria
void vitoria()
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
    std::cout<<"\n\t\tParabens, voce venceu! Pressione 'enter' para fechar o jogo. "<<std::endl;
    std::cin.ignore();
    SetConsoleTextAttribute(h,15); // branco
}



//saida manual pelo comando do menu
void saidamanual()
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
    std::cout<<"\n\t\tVoce escolheu sair do jogo. Pressione 'enter' para fechar o jogo. "<<std::endl;
    std::cin.ignore();
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



//funcao main do programa:
int main()
{
    //declaracaoo de variáveis:
    
    //int i usada para repeticoes 'for' e n para o loop do jogo 
    int i, n = 1, indicador, vit, modo, acertosmax = 0, repetido = 0;
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
    "coada", "coar", "conica", "conico", "corda", "cordao", "cria", "criacao",
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
    SetConsoleTextAttribute(h,10); // verde
    std::cout << "\n\n\t\tDeseja jogar em qual modo?" << std::endl;
    SetConsoleTextAttribute(h,14); // amarelo
    std::cout << "\n\t\t>> 1 - Facil (10 acertos)" << std::endl;
    std::cout << "\t\t>> 2 - Medio (20 acertos)" << std::endl;
    std::cout << "\t\t>> 3 - Dificil (30 acertos)" << std::endl;
    SetConsoleTextAttribute(h,12); // vermelho
    std::cout << "\t\t>> 4 - MUITO DIFICIL (100 acertos)" << std::endl;
    //validacao de entrada:
    do
    {
        //impede casos de cin.fail (so por precaucao):
        SetConsoleTextAttribute(h,11); // ciano
        std::cout << "\n\t\t  > Digite 1, 2, 3 ou 4 para selecionar: ";
        std::cin >> modo;
        while (std::cin.fail())
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Erro de entrada, tente novamente.";
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            SetConsoleTextAttribute(h,11); // ciano
            std::cout << "\n\n\t\t  > Digite 1, 2, 3 ou 4 para selecionar: ";
            std::cin >> modo;
        }
        //validacao de tamanho
        if (modo < 1 || modo>4)
        {
            SetConsoleTextAttribute(h,12); // vermelho
            std::cout<<"\n\t        >> Insira apenas valores de 1 a 4!\n";
        }
    } while (modo < 1 || modo>4);   
    SetConsoleTextAttribute(h,15); // branco
    
    if (modo == 1) acertosmax = 10;
    if (modo == 2) acertosmax = 20;
    if (modo == 3) acertosmax = 30;
    if (modo == 4) acertosmax = 100;
    limpa_tela();
    std::cin.ignore();
    

    //LOOP DO JOGO:
    while (num_erros<5)
    {
        vit = 0;
        indicador = 0;

        //quadro de letras e placar de erros/acertos
        quadro_letras(caracter);
        SetConsoleTextAttribute(h,14); // amarelo
        std::cout << "\n\n\t        >>>";
        SetConsoleTextAttribute(h,10); // verde
        std::cout << " Acertos ";
        SetConsoleTextAttribute(h,14); // amarelo
        std::cout <<"(";
        SetConsoleTextAttribute(h,10); // verde
        std::cout << num_acertos;
        SetConsoleTextAttribute(h,14); // amarelo
        std::cout << " de " << acertosmax << ") e " ;
        SetConsoleTextAttribute(h,12); // vermelho
        std::cout << "Erros " << num_erros;
        SetConsoleTextAttribute(h,14); // amarelo
        std::cout <<" (";
        SetConsoleTextAttribute(h,12); // vermelho
        std::cout << num_erros;
        SetConsoleTextAttribute(h,14); // amarelo
        std::cout << " de " << NUM_ERROS_TOTAL<<")";

         //IMPRESSÃO BANCO DE ACERTOS
        if (num_acertos > 0)
        {
            SetConsoleTextAttribute(h,14); // amarelo
            std::cout << "\n\t        >>> Banco de acertos:" << std::endl;
            for (i = 0; i < num_acertos; i++)
            {
                std::cout << "\t         >>";
                SetConsoleTextAttribute(h,15); // branco
                std::cout << " Palavra " << i+1 << ": "; 
                SetConsoleTextAttribute(h,10); // verde
                std::cout << b_acertos[i] << std::endl;
            }
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
        //sai do jogo
        else if (strcmp(resposta, "sair")==0)
        {
            vit = 2;
            break;
        }
        //mostra creditos
        else if (strcmp(resposta, "creditos")==0)
        {
            vit = 3;
            break;
        }
        //imprime banco de palavras 
        else if (strcmp(resposta, "bancop")==0)
        {
            quadro_palavras(banco_palavra);
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
                    repetido++;
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
                    SetConsoleTextAttribute(h,12); // vermelho
                    std::cout << "\n\t        >> Resposta errada! \n";
                    num_erros++;
                    break;
                //repetido
                case 2:
                    if (repetido==2)
                    {
                        SetConsoleTextAttribute(h,12); // vermelho
                        std::cout << "\n\t        >> Duas repetidas, + 1 erro! \n";
                        num_erros++;
                        repetido = 0;
                    }
                    else
                    {
                        SetConsoleTextAttribute(h,14); // amarelo
                        std::cout << "\n\t        >> Resposta repetida! \n";        
                    }
                    break;
                //acerto
                default:
                    SetConsoleTextAttribute(h,10); // verde
                    std::cout << "\n\t        >> Resposta certa! (+ respect)\n";
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
    else if (vit == 0)
        derrota();
    else if (vit == 2)
        saidamanual();
    else
        creditos();
    return 0; 
}