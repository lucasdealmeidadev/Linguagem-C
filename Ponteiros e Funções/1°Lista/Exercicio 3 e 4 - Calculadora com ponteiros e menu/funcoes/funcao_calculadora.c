int soma(int *n1, int *n2){ 
     
    return printf("Resultado da soma é : %d\n\n",(*n1)+(*n2));
}

int sub(int *n1, int *n2){ 
     
    return printf("Resultado da subtração é : %d\n\n",(*n1)-(*n2));
}

int mult(int *n1, int *n2){ 
     
    return printf("Resultado da multiplicação é : %d\n\n",(*n1)*(*n2));
}

int divisao(int *n1, int *n2){
    
    if((*n2) == 0){
          printf("Impossivel realizar a divisão por zero\n\n");
          
    }else{
          return printf("Resultado da divisão é : %d\n\n",(*n1)/(*n2));
    } 
}
