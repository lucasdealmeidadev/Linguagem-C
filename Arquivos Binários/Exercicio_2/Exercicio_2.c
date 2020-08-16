#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct pacientes{
       
   char nome[50];
   int idade;
   float altura,peso,imc;    
       
}dados_p[5];

int main(){
    
        FILE *arquivo = fopen("../Exercicio_1/pacientes.dat","rb");
             
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int i;
                       
                       for(i=0; i <= 4; i++){
                                   
                                   fread(&dados_p[i], sizeof(struct pacientes), 1, arquivo);
                                   
                                   printf("Paciente %d\n\n",i+1); 
                                   printf("<Nome> = %s",dados_p[i].nome);
                                   printf("\n<Idade> = %d",dados_p[i].idade);
                                   printf("\n<Altura> = %.2f",dados_p[i].altura);
                                   printf("\n<Peso> = %.2f",dados_p[i].peso);
                                   printf("\n<Imc> = %.2f",dados_p[i].imc);
                                   printf("\n\n-----------------------------------\n\n");          
                       }
             }
             
        fclose(arquivo); 
                     
    system("PAUSE");
    return 0;
}
