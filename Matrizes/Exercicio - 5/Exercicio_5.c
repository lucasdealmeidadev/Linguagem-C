#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main(){
    
    int l=0,c=0,i,j;
    
        setlocale(LC_ALL, "portuguese");            
            printf("Defina a quantidade de linhas da matriz = ");
            scanf("%d",&l);
                
            system("cls");
                
            printf("Defina a quantidade de colunas da matriz = ");
            scanf("%d",&c); 
            
            if(l > 0 && c > 0){
                 
                int mat[l][c],vet[c];  
                
                     system("cls");              
                        printf("\n---------------MATRIZ %d por %d---------------\n",l,c);                  
                           for(i=0; i < l; i++){
                                    
                                    for(j=0; j < c; j++){
                                             
                                         printf("\nMatriz [%d] [%d] = ",i,j);
                                         scanf("%d",&mat[i][j]);
                                    }
                           }
                           
                     system("cls");              
                        printf("\n---------------VETOR---------------\n",l,c);                  
                           for(i=0; i < c; i++){                       
                                             
                                         printf("\nVetor [%d] = ",i);
                                         scanf("%d",&vet[i]);
                           }        
                           
                       
                     system("cls");
                     
                     printf("\n---------------MATRIZ PREENCHIDA----------------\n");
                           for(i=0; i < l; i++){
                                    printf("\n");
                                      for(j=0; j < c; j++){
                                               printf("%d ",mat[i][j]);
                                      }        
                           }
                     
                     printf("\n\n----------------VETOR PREENCHIDO----------------\n\n");
                           for(i=0; i < c; i++){                       
                                             
                                              printf("%d ",vet[i]);
                           }        
                     
    
                     printf("\n\n-----------------VETOR COM SOMA-----------------\n\n");
                          for(i=0; i < l; i++){
                               
                               int soma_c=0,soma_f=0;
                                
                                   for(j=0; j < c; j++){ 
                                                                          
                                          soma_c = soma_c + mat[i][j];//Soma as colunas da matriz
                                          soma_f = soma_c + vet[i];//Soma o valor das colunas com o valor do vetor
                         
                                   }
                                   
                                        
                                printf("%d ",soma_f);
                                   
                          }
                          printf("\n\n");

              }else{
                    system("cls");
                    printf("\nErro, não é permitido números negativos ou igual à zero\n\n");
              }         
    system("PAUSE");
    return 0;    
}
