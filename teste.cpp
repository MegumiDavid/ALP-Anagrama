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



//funcao main do programa:
int main()
{
    std::cout << std::endl << R"(
 ▄▄   ▄▄ ▄▄▄ ▄▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄▄     
█  █▄█  █   █       █  █ █  █       █   █    
█       █   █   ▄▄▄▄█  █ █  █    ▄▄▄█   █    
█       █   █  █  ▄▄█  █▄█  █   █▄▄▄█   █    
█       █   █  █ █  █       █    ▄▄▄█   █▄▄▄ 
█ ██▄██ █   █  █▄▄█ █       █   █▄▄▄█       █
█▄█   █▄█▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█
    )" << '\n';
    return 0; 
}