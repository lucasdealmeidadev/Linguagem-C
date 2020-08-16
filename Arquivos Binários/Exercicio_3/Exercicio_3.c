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
                   int posicao,val;
                      
                      setlocale(LC_ALL, "portuguese");
                      
                          printf("Informe a posição do registro = ");
                          scanf("%d",&posicao); 
                            
                          fseek(arquivo, (posicao-1) * sizeof(struct pacientes), SEEK_SET);
                          val = fread(&dados_p[posicao], sizeof(struct pacientes), 1, arquivo);
                             
                          if(val == 0){
                                  printf("\n\nErro, registro não existe\n\n");
                          
                          }else{
                                  system("cls");           
                                  printf("Paciente %d\n\n",posicao); 
                                  printf("<Nome> = %s",dados_p[posicao].nome);
                                  printf("\n<Idade> = %d",dados_p[posicao].idade);
                                  printf("\n<Altura> = %.2f",dados_p[posicao].altura);
                                  printf("\n<Peso> = %.2f",dados_p[posicao].peso);
                                  printf("\n<Imc> = %.2f",dados_p[posicao].imc);    
                          }                            
             }
             
        fclose(arquivo); 
                     
    system("PAUSE");
    return 0;
}
