#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

/* Função vetor*/
#include "funcoes/vetor.c"

int main(){
    
    setlocale(LC_ALL, "portuguese");
    
    int vet[5];
    preenche(&vet[5]);
    lista_vetor(&vet[5]);
    
    
    system("PAUSE");
    return 0;
}
