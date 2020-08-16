#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int preenche_vetor(int qtd, int vet[]);
void lista_vetor(int qtd, int vet[]);

int main(){
     int *vet;
     int qtd,i;
         
         setlocale(LC_ALL, "portuguese");
         
          printf("Informe o tamanho do vetor = ");
          scanf("%d",&qtd);
          printf("\n");
            
          vet = calloc(qtd, sizeof(int)); 
                
                if(vet == NULL){
                       printf("Erro, na alocação de memória\n\n");
                       
                }else{
                        
                        preenche_vetor(qtd,vet);                      
                        lista_vetor(qtd,vet);
                        
                        printf("\n\nAltere o tamanho do vetor  = ");
                        scanf("%d",&qtd);
                        printf("\n");
                        
                        vet = realloc(vet,qtd*sizeof(int));
                        
                        preenche_vetor(qtd,vet); 
                        lista_vetor(qtd,vet);
                        
                        free(vet);   
                }             
    
    system("PAUSE");
    return 0;
}

int preenche_vetor(int qtd, int vet[]){
   
    int i; 
     
     for(i=0; i < qtd; i++){
                                  
         printf("Vetor [%d] = ",i);
         scanf("%d",&vet[i]);
     }
}

void lista_vetor(int qtd, int vet[]){
   
   int i; 
     
     printf("\n\n---------------VETOR PREENCHIDO---------------\n\n");  
     for(i=0; i < qtd; i++){
                                   
           printf("Vetor [%d] = [%d]\n",i,vet[i]);
     }
     printf("\n----------------------------------------------\n\n"); 
}
