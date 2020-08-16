#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct No{
     
     int valor;
     struct No *prox;  
};

typedef struct No lista;

void inicializa(lista *cartas);
int checa_lista(lista *cartas);
void adiciona_fim(lista *cartas);
void adiciona_inicio(lista *cartas);
void mostra_lista(lista *cartas);
void remove_inicio (lista *cartas);
void remove_final (lista *cartas);
void limpa_lista(lista *cartas);
int tamanho_lista (lista *cartas);

/*Específica*/
void mostra_elemento(lista *cartas, int i);
void adiciona(lista *cartas);
void remover(lista *cartas);

/*Exercicio 1*/
void adiciona_ordenada(lista *cartas);

int main(){
    
        setlocale(LC_ALL, "portuguese");
        
        lista *cartas =(lista*) malloc(sizeof(lista)); 
              
              if(!cartas){
                   
                   printf("Impossível alocar memória\n\n");
                   exit(1);       
              
              }else{
                    //printf("Memória alocada com sucesso\n\n");
                    inicializa(cartas);
                    
                        int i = checa_lista(cartas);
                            
                            if(i == 1){
                                     printf("Lista vazia\n\n");
                            
                            }else{
                                     printf("Lista não vazia\n\n");
                            }
                    
                            //adiciona_fim(cartas); 
                            //mostra_lista(cartas);
                            adiciona_inicio(cartas);
                            adiciona_inicio(cartas);
                            adiciona_inicio(cartas);
                            mostra_lista(cartas);
                            adiciona_ordenada(cartas);
                            mostra_lista(cartas);
                            //mostra_lista(cartas);
                            
                            //adiciona(cartas); 
                            //mostra_lista(cartas);
                            //adiciona(cartas);
                           // mostra_lista(cartas);
                            //remover(cartas); 
                           // mostra_lista(cartas);
                            
                            //mostra_lista(cartas);
                            /*                          
                            int y1 = tamanho_lista(cartas);
                            printf("\nTamanho da lista = %d\n\n", y1);
                            
                            mostra_lista(cartas); 
                            remove_inicio(cartas);
                            mostra_lista(cartas);
                            remove_final(cartas);
                            mostra_lista(cartas);
                            
                            int y2 = tamanho_lista(cartas);
                            printf("\nTamanho da lista = %d\n\n", y2); 
                            
                            limpa_lista(cartas); 
                            printf("Limpando lista\n");
                            
                            int y3 = tamanho_lista(cartas);
                            printf("\nTamanho da lista = %d\n\n", y3); 
                            */
                            
                            /*int x;
                            
                            printf("Elemento especifico = ");
                            scanf("%d",&x);
                            mostra_elemento(cartas,x);*/
                            
         
                       
                  free(cartas);      
              }
               
        
        system("PAUSE");
        return 0;
}

void inicializa(lista *cartas){
     
     cartas->prox = NULL;
     //printf("Lista de cartas inicializada\n\n");
}
int checa_lista(lista *cartas){
    
    if(cartas->prox == NULL){
          return 1;          
    
    }else{
          return 0;
    }
}
void adiciona_fim(lista *cartas){
     
     lista *novo = (lista*) malloc(sizeof(lista));
     
     if(!novo){
             printf("Impossível alocar memória\n\n");      
             exit(1);
     }
             printf("Digite uma carta para inserir no baralho = ");
             scanf("%d",&novo->valor);
             novo->prox = NULL;
                 
                 if(checa_lista(cartas)){
                        cartas->prox = novo;                 
                 
                 }else{
                        lista *aux = cartas->prox;
                          
                          while(aux->prox != NULL){
                               aux = aux->prox;    
                          }
                          aux->prox = novo;  
                 }        
                 
}
void adiciona_inicio(lista *cartas){
     lista *novo = (lista *) malloc(sizeof(lista));
     
        if(!novo){
            printf("Impossivel alocar memoria\n");
            exit(1);
        }
        
        printf("Digite uma carta para inserir no baralho: ");
        scanf("%d", &novo->valor);
        
            lista *aux = cartas->prox;
            cartas->prox = novo;
            novo->prox = aux;
}

void mostra_lista(lista *cartas){
     if(checa_lista(cartas)){
          printf("Lista vazia\n\n");                   
     }
     printf("Cartas -> ");
     lista *aux = cartas->prox;
         while(aux != NULL){
              printf("%d -> ",aux->valor);   
              aux = aux->prox;   
         }
     printf("null\n");     
}
void remove_inicio (lista *cartas){
    lista *aux = cartas->prox;
    
        printf("Removendo o primeiro elemento do baralho \n");
        cartas->prox = cartas->prox -> prox;
        
        free(aux);
}
void remove_final (lista *cartas){
     
    while (cartas->prox->prox != NULL){
          cartas = cartas->prox;
    }
        free(cartas->prox);
        cartas->prox = NULL;
        
        printf("Removendo o ultimo elemento do baralho \n");
}

void limpa_lista(lista *cartas){ 
     
         if(!checa_lista(cartas)){
                                   
            lista *aux,*atual,*head;
            head = cartas;
            atual = cartas->prox;
            
                while(atual->prox != NULL){
                                  
                    aux = atual->prox;
                    free(atual);
                    atual = aux;
                }
                
                if (atual->prox == NULL){ 
                                
                    head->prox = NULL;
                    free(atual);
                }
         }
}

int tamanho_lista (lista *cartas){
    
    int i = 0;
    
        while (cartas->prox != NULL){
            cartas = cartas->prox;
            i++;
        }
        return i;
}

void mostra_elemento(lista *cartas, int i){
     int n=0;
         lista *aux = cartas->prox;
         
         while(aux != NULL){
                   
                   if(aux->valor == i){
                         
                         printf("Elemento encontrado = %d\n",aux->valor); 
                         n++;       
                   }
                aux = aux->prox;   
         }
         
         if(n == 0){
              printf("Elemento não existe\n"); 
         }
}
void adiciona(lista *cartas){

     int cont=1,pos,i;
     
        lista *novo = (lista *) malloc(sizeof(lista));
        lista *aux = cartas;
        lista *ant = cartas;

            if(!novo){
                printf("Impossivel alocar memoria\n");
                exit(1);
            }

            i = tamanho_lista(cartas);
            
            printf("Qual posicao (1 ate %d) deseja adicionar: ",i);
            scanf("%d", &pos);
            
            printf("Digite uma carta para inserir no baralho: ");
            scanf("%d", &novo->valor);

                if(pos>0 && pos <= i+1){
                         
                    while (cont <= pos){
                          
                            ant = aux;
                            aux = aux->prox;
                        
                                if (cont == pos){
                                    ant->prox = novo;
                                    novo->prox = aux;
                                }
                          cont++;
                    }
                }else{
                     printf("Posicao invalida\n");
                }     
}

void remover(lista *cartas){ 
     
     int cont=1,pos,i;
     
        lista *aux = cartas;
        lista *ant = cartas;
        i = tamanho_lista(cartas);
        
            printf("Qual posicao (1 ate %d) deseja remover: ",i);
            scanf("%d", &pos);
            
        if(pos>0 && pos <= i){ 
         
             while (cont <= pos){ 
                   ant = aux;
                   aux = aux->prox;
                   
                        if (cont == pos) {
                            ant->prox = aux->prox;
                            free(aux); 
                        }
             cont++; 
             }
         }else{
               printf("Posicao invalida\n");
         }              
}

void adiciona_ordenada(lista *cartas){

         lista *novo = (lista *) malloc(sizeof(lista));
         lista *aux = cartas->prox;
         
         lista *aux2 = cartas;
         lista *ant = cartas;
         
         printf("Digite uma carta para inserir no baralho: ");
         scanf("%d", &novo->valor);
         
         while(aux != NULL){
            
            ant = aux;
            aux2 = aux->prox;   
            
               if(novo->valor >= ant->valor && novo->valor <= aux2->valor){
                                                             
                    ant->prox = novo;
                    novo->prox = aux2;
                                  
                                           
               }
       
                aux = aux->prox;   
         }
     
         /*if(novo->valor < ant->valor){
                           
                    adiciona_inicio(cartas);
         }*/



}
