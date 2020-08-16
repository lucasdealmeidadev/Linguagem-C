#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int main(){
    
    int *vet;
    int qtd,i;
        
        setlocale(LC_ALL, "portuguese");
        
         printf("Por favor informe o tamanho do vetor = ");
         scanf("%d",&qtd);
         
         vet = calloc(qtd, sizeof(int));
           
           system("cls");
             
             if(vet == NULL){
                  printf("Erro, na alocação de memória\n\n");
             
             }else{
                   for(i=0; i < qtd; i++){
                            printf("Vetor [%d] = ",i);
                            scanf("%d",&vet[i]);
                   }
                   
                    printf("\n\nVetores preenchidos\n\n");
                    
                    for(i=0; i < qtd; i++){
                             printf("Vetor [%d] = [%d]\n",i,vet[i]);
                    }
                   
                free(vet);
             }

    system("PAUSE");
    return 0;
}
