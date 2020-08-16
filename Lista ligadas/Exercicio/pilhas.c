#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#include "funcoes/struct.c"
#include "funcoes/menu.c"
#include "funcoes/pilhas_funcoes.c"

int main(){
        
        char op='S'; 
        int query,i,j;  
        
        setlocale(LC_ALL, "portuguese");
        
           lista *cartas =(lista*) malloc(sizeof(lista)); 
          
              while(op=='S' || op=='s'){
                            
                    system("cls"); 
                    menu();
                        
                        printf("Selecione uma opção = ");
                        scanf("%d",&query);
                           
                           if(query == 12){
                                    system("cls");
                                    break;
                           }else{
                                 
                                     switch(query){
                              
                                            case 1:
                                                   adiciona_inicio(cartas);
                                            break;
                                            
                                            case 2:
                                                   adiciona_fim(cartas);
                                            break;
                                            
                                            case 3:
                                                   mostra_lista(cartas);
                                            break;
                                            
                                            case 4:
                                                   remove_inicio(cartas);
                                            break;
                                            
                                            case 5:
                                                   remove_final(cartas);
                                            break;
                                            
                                            case 6:
                                                   limpa_lista(cartas);
                                            break;
                                            
                                            case 7:
                                                   i = tamanho_lista(cartas);
                                                   printf("\n\nTamanho da lista é = %d",i);
                                            break;
                                            
                                            case 8:
                                                   printf("\n\nInforme um número para buscar no baralho = ");
                                                   scanf("%d",&j);
                                                   mostra_elemento(cartas,j);
                                            break;
                                            
                                            case 9:
                                                   adiciona(cartas);
                                            break;
                                            
                                            case 10:
                                                   remover(cartas);
                                            break;
                                            
                                            case 11:
                                                   printf("Função em desenvolvimento");
                                            break;
                                            
                                            default:
                                                    system("cls");
                                                    printf("Erro, selecione uma opção valida\n\n");
                                            break;  
        
                                     }            
                           }                      
                                                                 
                        printf("\n\nDeseja continuar (S) ou (N) = ");
                        op=getche();

              }                
        
                 
                
        system("PAUSE");
        return 0;
}
