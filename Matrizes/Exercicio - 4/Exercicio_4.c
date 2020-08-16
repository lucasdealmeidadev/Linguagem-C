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
                    int mat[l][c], matb[l][c],soma[l][c];
                   
                       system("cls");              
                       printf("\n---------------1° MATRIZ %d por %d---------------\n",l,c);                  
                          for(i=0; i < l; i++){
                                   
                                   for(j=0; j < c; j++){
                                            
                                        printf("\nMatriz [%d] [%d] = ",i,j);
                                        scanf("%d",&mat[i][j]);
                                   }
                          }
                      
                      system("cls");    
                      printf("\n---------------2° MATRIZ %d por %d---------------\n",l,c);                  
                          for(i=0; i < l; i++){
                                   
                                   for(j=0; j < c; j++){
                                            
                                        printf("\nMatriz [%d] [%d] = ",i,j);
                                        scanf("%d",&matb[i][j]);
                                   }
                      }    
                      system("cls"); 
                      printf("\n--------------- 1° MATRIZ %d por %d PREENCHIDA---------------\n",l,c);
                          for(i=0; i < l; i++){
                                   printf("\n");
                                     for(j=0; j < c; j++){
                                              printf("%d ",mat[i][j]);
                                     }        
                          }
                          
                       printf("\n--------------- 2° MATRIZ %d por %d PREENCHIDA---------------\n",l,c);
                         for(i=0; i < l; i++){
                                  printf("\n");
                                    for(j=0; j < c; j++){
                                             printf("%d ",matb[i][j]);
                                    }        
                         }
                         
                      printf("\n---------------SOMA DAS MATRIZES A e B---------------\n"); 
                       for(i=0; i < l; i++){
                                printf("\n");
                                  for(j=0; j < c; j++){
                                           
                                           soma[i][j] = (mat[i][j] + matb[i][j]);
                                           printf("%d ",soma[i][j]);
                                  }        
                       }     
                       printf("\n\n"); 
                                     
                }else{
                      system("cls");
                      printf("\nErro, não é permitido números negativos ou igual à zero\n\n");
                }
    system("PAUSE");
    return 0;
}

