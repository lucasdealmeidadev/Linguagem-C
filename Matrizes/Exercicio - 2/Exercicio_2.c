#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
         
int main(){
    int i,j,mat[6][6];
        
        setlocale(LC_ALL, "portuguese");
        
           printf("----------------MATRIZ----------------\n"); 
           
             for(i=0; i < 6; i++){
                  
                  printf("\n");
                   
                   for(j=0; j < 6; j++){
                            
                            if(i == j){
                                     
                                 mat[i][j] = 1;
                            }
                            else if(i + j == 5){
                                 
                                 mat[i][j] = 2;  
                            }
                            
                            else{
                                 
                                 mat[i][j] = 3;
                            }
                            
                            printf("%d ",mat[i][j]);
                            
                         }
                         
                   }
          printf("\n\n");           
                          
    system("PAUSE");
    return 0;
}   
