#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"
//macros
#define NUM_ERROS_TOTAL 5
#define TAMANHO_BANCO 123
#define h GetStdHandle (STD_OUTPUT_HANDLE)


//funcao main do programa:
int main()
{
    //variaveis do programa:
    //repete o programa até que o usuario decida parar de jogar
    bool sair = false;
    //conta os placares de vitorias, derrotas e desistencias
    int contador_derrotas=0, contador_vitorias=0, contador_desistencias=0;
    //ve se vai sair ou nao
    int simnao=0;
    while (!sair)
    
    {
        //declaracaoo de variáveis pro loop:

        //int i usada para repeticoes 'for' e n para o loop do jogo 
        int i, n = 1, indicador, vit, modo, acertosmax = 0, repetido = 0, secreto = 0;
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
        cabecalho_anagrama(contador_vitorias,contador_derrotas,contador_desistencias);
        
        //SELEÇÃO MODO DE JOGO(dificuldade):
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
            valida_int(modo, "\n\t\t  > Digite 1, 2, 3 ou 4 para selecionar: ");
            //validacao de tamanho
            if (modo < 1 || modo>4)
            {
                SetConsoleTextAttribute(h,12); // vermelho
                std::cout<<"\n\t        >> Insira apenas valores de 1 a 4!\n";
            }
        } while (modo < 1 || modo>4);   
        SetConsoleTextAttribute(h,15); // branco
        //decide o numero de acertos necessarios para a vitoria baseado na escolha do modo
        if (modo == 1) acertosmax = 10;
        if (modo == 2) acertosmax = 20;
        if (modo == 3) acertosmax = 30;
        if (modo == 4) acertosmax = 100;
        limpa_tela(contador_vitorias,contador_derrotas,contador_desistencias);
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
                    SetConsoleTextAttribute(h,14); // amarelo
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
                limpa_tela(contador_vitorias,contador_derrotas,contador_desistencias);        
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
                vit = 4;
                break;
            }
            //imprime banco de palavras 
            else if (strcmp(resposta, "bancop")==0)
            {
                quadro_palavras(banco_palavra);
            }
            //comando secreto 1:
            else if (strcmp(resposta, "puc")==0||strcmp(resposta, "puccamp")==0)
            {
                vit = 3;
                secreto = 0;
                break;
            }
            //comando secreto 2:
            else if (strcmp(resposta, "unicamp")==0)
            {
                vit = 3;
                secreto = 1;
                break;
            }
            //comando secreto 3
            else if (strcmp(resposta, "faccamp")==0)
            {
                vit = 3;
                secreto = 2;
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
        //MENSAGENS FINAIS DO JOGO
        switch (vit)
        {
            //derrota
            case 0:
                derrota(simnao);
                contador_derrotas++;
                break;
            //vitoria
            case 1:
                vitoria(simnao);
                contador_vitorias++;
                break;
             //desistencia
            case 2:
                saidamanual(simnao);
                contador_desistencias++;
                break;
            //comandos secretos
            case 3:
                if (secreto==0) {puc(simnao); contador_vitorias++;}
                if (secreto==1) {unicamp(simnao); contador_derrotas++;}
                if (secreto==2) {faccamp(simnao); contador_desistencias++;}
                break;
            //creditos
            default:
                creditos(simnao);
                break;
        }
        //caso vc queira sair, sai
        if (simnao == 2)
            sair = true;
        //senao nao sai, ne
        else
        {
            sair = false;
            system("cls");
        }
    }    
    return 0; 
}