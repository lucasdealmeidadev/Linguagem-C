void preenche(int *vet){
     
     int i;
     
         for(i=0; i < 5; i++){
               
               printf("\nPreencha o Vetor [%d] = ",i);
               scanf("%d",&vet[i]);
         }
}

void lista_vetor(int *vet){
     
     printf("\n\n--------------------VETOR NORMAL-------------------\n");
     
     int i;
     
         for(i=0; i < 5; i++){
               
               printf("\nVetor [%d] = [%d]",i,vet[i]);  
         }
         
     printf("\n\n------------------VETOR INVERTIDO------------------\n");
     
         for(i=4; i >= 0; i--){
               
               printf("\nVetor [%d] = [%d]",i,vet[i]);  
         }
     printf("\n\n");        
}
