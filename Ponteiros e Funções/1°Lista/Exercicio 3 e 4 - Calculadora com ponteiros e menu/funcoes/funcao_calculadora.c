int soma(int *n1, int *n2){ 
     
    return printf("Resultado da soma � : %d\n\n",(*n1)+(*n2));
}

int sub(int *n1, int *n2){ 
     
    return printf("Resultado da subtra��o � : %d\n\n",(*n1)-(*n2));
}

int mult(int *n1, int *n2){ 
     
    return printf("Resultado da multiplica��o � : %d\n\n",(*n1)*(*n2));
}

int divisao(int *n1, int *n2){
    
    if((*n2) == 0){
          printf("Impossivel realizar a divis�o por zero\n\n");
          
    }else{
          return printf("Resultado da divis�o � : %d\n\n",(*n1)/(*n2));
    } 
}
