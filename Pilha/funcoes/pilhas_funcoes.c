void inicializa (lista *pilha){
     
    pilha->prox = NULL;
    topo = 0;
    printf("\nPilha inicializada\n\n");
}

int checa_pilha(lista *pilha){
    
    if(pilha->prox == NULL){
                   
       return 1;
    }
    else{
         
       return 0;
    }
}
void push(lista *pilha){
      
     lista *novo =(lista *) malloc(sizeof(pilha));
     
        if(!pilha){
                   
            printf("\nImpossivel alocar memoria\n\n");
            exit(1);
        }
        
        printf("\nDigite um numero para inserir na pilha = ");
        scanf("%d", &novo->valor);
        novo->prox = NULL;

            if(checa_pilha(pilha)){
                                   
                pilha->prox = novo;
            }else{ 
                   
                    lista *aux = pilha->prox;
                    
                    while(aux->prox != NULL){
                                    
                        aux = aux->prox;                        
                    } 
                    aux->prox = novo;
            }  
            topo++;    
            
}

void pop(lista *pilha){
     
    while (pilha->prox->prox != NULL){
          
          pilha = pilha->prox ;
    }
    
    free(pilha->prox);
    pilha->prox = NULL;
    topo--;
    
    printf("\nRemovendo um elemento da pilha\n");
}

void mostra_pilha(lista *pilha){
     
    if(checa_pilha(pilha)){
        printf("\nPilha vazia\n");
        return ;
    }
    
    lista *aux = pilha->prox;
    printf("\nPilha -> ");
    
        while( aux != NULL){
               
            printf("%d ->", aux->valor);
            aux = aux->prox;
        }
    printf("\n");
}

void mostra_especifico(lista *pilha, int val){
     
    if(checa_pilha(pilha)){
        printf("\nPilha vazia\n");
        return ;
    }
    
    lista *aux = pilha->prox;
    
        while( aux != NULL){
            
            if (aux->valor == val){
                printf("\nElemento encontrado = %d\n", aux->valor);
            }    
                aux = aux->prox;
        }
    printf("\n");
}
void limpa_pilha(lista *pilha){ 
    if(!checa_pilha(pilha)){ 
                             
        lista *aux,*atual,*head;
        head = pilha;
        atual = pilha->prox;
    
            while(atual->prox != NULL){ 
                              
                aux = atual->prox;
                free(atual);
                atual = aux;
            }
    
                if (atual->prox == NULL){ 
                                
                    head->prox = NULL;
                    free(atual);
                    topo = 0;
                }
    }
}

