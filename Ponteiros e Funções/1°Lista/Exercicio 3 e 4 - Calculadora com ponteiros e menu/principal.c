#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

/* Função da calculadora */
#include "funcoes/calculadora.c"

int main(){
    setlocale(LC_ALL, "portuguese");
    
    calculadora();
    
    system("PAUSE");
    return 0;
}
