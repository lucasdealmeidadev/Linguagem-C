#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
         
int main(){
    int i,j,mat[4][4];
    
    setlocale(LC_ALL, "portuguese");
               for(i=0; i < 4; i++){
                      
                      for(j=0; j < 4; j++){
                               
                               if (i + j == 3){
                                     
                                     mat[i][j]=1;
                               }else{
         
                                     mat[i][j]=0;
                               }
                      }  
               }
               printf("----------------MATRIZ----------------\n");
               for(i=0; i < 4; i++){
                    printf("\n");  
                    
                      for(j=0; j < 4; j++){
                               
                               printf("%d ",mat[i][j]);
                      }  
               }
               printf("\n\n");                                                     
    
    system("PAUSE");
    return 0;
}         
