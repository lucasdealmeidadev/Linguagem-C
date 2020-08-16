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
        int query,i;  
        
        setlocale(LC_ALL, "portuguese");
        
           lista *pilha =(lista *) malloc(sizeof(lista)); 
           inicializa(pilha);  
              while(op=='S' || op=='s'){
                            
                    system("cls");
                    
                    menu();
                        
                        printf("Selecione uma opção = ");
                        scanf("%d",&query);
                           
                           if(query == 7){
                                    system("cls");
                                    break;
                           }else{
                                 
                                     switch(query){
                              
                                            case 1:
                                                   i = checa_pilha(pilha);
                                                       if(i == 1){
                                                            
                                                             printf("\nLista Vazia\n");
                                                       }else{
                                                             
                                                             printf("\nElementos encontrados = %d\n",i);
                                                       }
                                            break;
                                            
                                            case 2:
                                                   push(pilha);
                                            break;
                                            
                                            case 3:
                                                   i = checa_pilha(pilha);
                                                       
                                                       if(i == 1){
                                                            
                                                              printf("\nImposivel retirar, pilha vazia\n");
                                                       }else{
                                                              pop(pilha);
                                                       } 
                                            break;
                                            
                                            case 4:
                                                   mostra_pilha(pilha);
                                            break;
                                            
                                            case 5:
                                                  i = checa_pilha(pilha);
                                                       
                                                       if(i == 1){
                                                            
                                                              printf("\nSua lista já está vazia\n");
                                                       }else{
                                                              limpa_pilha(pilha);
                                                       } 
                                            break;
                                            
                                            case 6:
                                                  i = checa_pilha(pilha);
                                                  int val;
                                                       
                                                       if(i == 1){
                                                            
                                                              printf("\nNenhum resultado encontrado\n");
                                                       }else{
                                                              printf("\nPesquise um elemnto da pilha = ");
                                                              scanf("%d", &val);
                                                              
                                                              mostra_especifico(pilha,val);
                                                       } 
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
