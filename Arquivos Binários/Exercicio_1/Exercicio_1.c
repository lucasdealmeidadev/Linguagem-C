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
    
        FILE *arquivo = fopen("pacientes.dat","wb");
             
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int i;
                       
                       for(i=0; i <= 4; i++){
                                   
                                   system("cls");
                                   printf("Paciente %d\n\n",i+1); 
                                    
                                   printf("<Nome> = ");
                                   scanf("%s",&dados_p[i].nome);
                                   fflush(stdin);
                                   
                                   printf("\n<Idade> = ");
                                   scanf("%d",&dados_p[i].idade);
                                   fflush(stdin);
                                   
                                   printf("\n<Altura> = ");
                                   scanf("%f",&dados_p[i].altura);
                                   fflush(stdin);
                                   
                                   printf("\n<Peso> = ");
                                   scanf("%f",&dados_p[i].peso);
                                   fflush(stdin);
                                   
                                   dados_p[i].imc = dados_p[i].peso/(dados_p[i].altura*dados_p[i].altura);
                                   
                                   fwrite(&dados_p[i], sizeof(struct pacientes), 1, arquivo);
                                   
                       }
             }
             
        fclose(arquivo); 
                     
    system("PAUSE");
    return 0;
}
