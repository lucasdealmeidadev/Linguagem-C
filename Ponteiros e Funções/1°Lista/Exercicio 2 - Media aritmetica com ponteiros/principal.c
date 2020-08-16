#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

/* Função média*/
#include "funcoes/media.c"

int main(){
    
    setlocale(LC_ALL, "portuguese");
    
    exibe_media();
    
    system("PAUSE");
    return 0;
}
