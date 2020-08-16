#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int main(){
    
        FILE *arquivo = fopen("numeros.dat","wb");
        FILE *arquivo2 = fopen("numeros.dat","rb");
        FILE *arquivo3 = fopen("pares.dat","wb");
             
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int i,qtd,num;
                      
                      setlocale(LC_ALL, "portuguese");
                      
                          printf("Informe a posição de números = ");
                          scanf("%d",&qtd);
                          
                          int vet[qtd];
                              
                              for(i=0; i < qtd; i++){
                                       
                                       printf("\nInforme o %d número = ",i);
                                       scanf("%d",&vet[i]);
                                       
                                       fwrite(&vet[i], sizeof(vet[qtd]), 1, arquivo);
                              }
                              
                              for(i=0; i < qtd; i++){
                                       
                                       fread(&vet[i], sizeof(vet[qtd]), 1, arquivo2);
                                       num = vet[i];
                                           
                                           if(num%2 == 0){
                                                  fwrite(&num, sizeof(num), 1, arquivo3); 
                                                  fread(&vet[i], sizeof(vet[qtd]), 1, arquivo3);
                                                  printf("%d ",num);  
                                           }
                                           
                              } 

             }
             
        fclose(arquivo);
        fclose(arquivo2);
        fclose(arquivo3);  
                     
    system("PAUSE");
    return 0;
}
