void inicializa(lista *cartas){
     
     cartas->prox = NULL;
}

int checa_lista(lista *cartas){
    
    if(cartas->prox == NULL){
          return 1;          
    
    }else{
          return 0;
    }
}
void adiciona_inicio(lista *cartas){
     lista *novo = (lista *) malloc(sizeof(lista));
     
        if(!novo){
            printf("Impossivel alocar memoria\n");
            exit(1);
        }
        
        system("cls"); 
        printf("Digite uma carta para inserir no ínicio do baralho = ");
        scanf("%d", &novo->valor);
        
            lista *aux = cartas->prox;
            cartas->prox = novo;
            novo->prox = aux;
}
void adiciona_fim(lista *cartas){
     
     lista *novo = (lista*) malloc(sizeof(lista));
     
     if(!novo){
             printf("Impossível alocar memória\n\n");      
             exit(1);
     }
     
             system("cls");         
             printf("Digite uma carta para inserir no fim do baralho = ");
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
void mostra_lista(lista *cartas){
     
      if(checa_lista(cartas)){
           printf("\n\nLista vazia\n\n");                   
      }
      
      printf("\nCartas -> ");
      lista *aux = cartas->prox;
          while(aux != NULL){
               printf("%d -> ",aux->valor);   
               aux = aux->prox;   
          }
      printf("null\n"); 
          
}

void remove_inicio(lista *cartas){
    lista *aux = cartas->prox;
    
        printf("\n\nRemovendo o primeiro elemento do baralho \n");
        cartas->prox = cartas->prox -> prox;
        
        free(aux);
}

void remove_final(lista *cartas){
     
    while (cartas->prox->prox != NULL){
          cartas = cartas->prox;
    }
        free(cartas->prox);
        cartas->prox = NULL;
        
        printf("\n\nRemovendo o ultimo elemento do baralho \n");
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
             printf("\n\nExcluindo todos os elementos do baralho \n");   
         }
}
int tamanho_lista(lista *cartas){
    
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
                         
                         printf("\n\nElemento encontrado = %d\n",aux->valor); 
                         n++;       
                   }
                aux = aux->prox;   
         }
         
         if(n == 0){
              printf("\n\nElemento não existe\n"); 
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
            
            printf("\n\nQual posicao (1 ate %d) deseja adicionar: ",i);
            scanf("%d", &pos);
            
            printf("\n\nDigite uma carta para inserir no baralho: ");
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
                     printf("\n\nPosicao invalida\n\n");
                }     
}
void remover(lista *cartas){ 
     
     int cont=1,pos,i;
     
        lista *aux = cartas;
        lista *ant = cartas;
        i = tamanho_lista(cartas);
        
            printf("\n\nQual posicao (1 ate %d) deseja remover = ",i);
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
               printf("\n\nPosicao inválida\n\n");
         }              
}
