float cal(float *n1, float *n2){
    
    float soma;
    
        soma = ((*n1)+(*n2))/2;   
    
            if(soma >= 0 && soma < 3){
                        
                        printf("Sua m�dia final � : %.2f",soma);
                        printf("\n\nSitua��o : Reprovado\n\n");
            
            }else if(soma >= 3 && soma <= 6.9){
                  
                        printf("Sua m�dia final � : %.2f",soma);
                        printf("\n\nSitua��o : Exame\n\n");
            
            }else if(soma >= 7 && soma <= 10){
                                          
                        printf("Sua m�dia final � : %.2f",soma);
                        printf("\n\nSitua��o : Aprovado\n\n");
            }     
    return soma;    
}

void exibe_media(){
       
       float n1,n2;
                   
       printf("Digite sua 1� nota = ");
       scanf("%f",&n1);
     
       printf("\n\nDigite sua 2� nota = ");
       scanf("%f",&n2);
       
       system("cls");
       cal(&n1,&n2);
}
