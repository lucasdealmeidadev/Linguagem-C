#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct notas{
      char nome[50]; 
      int n1,n2; 
       
}alunos[0];

int main(){
           int i,qtd;
           float media=0;
               setlocale(LC_ALL,"portuguese");  
               
                 printf("Informe a quantidade de alunos = ");
                 scanf("%d",&qtd);
                 
                 alunos[qtd]; 
                                                 
                 for(i=1; i <= qtd; i++){
                     
                     system("cls");
                     printf("Aluno %d",i);
                     
                     printf("\n\nInforme seu nome : ");
                     scanf("%s",&alunos[i].nome);
                     fflush(stdin);
                     
                     printf("\nInforme sua 1° nota :");
                     scanf("%d",&alunos[i].n1);
                     fflush(stdin);
                     
                     printf("\nInforme sua 2° nota :");
                     scanf("%d",&alunos[i].n2);
                     fflush(stdin); 
                 }
                 
                 system("cls");
                 for(i=1; i <= qtd; i++){
                     
                     media = (alunos[i].n1 + alunos[i].n2);
                     
                     if((media/2) >= 6){
                                  printf("\nNome = %s",alunos[i].nome);
                                  printf("\n\nSituação = <Aprovado> / Média final = %.2f\n\n",(media/2));
                         }else{
                                  printf("Nome = %s",alunos[i].nome);
                                  printf("\n\nSituação = <Reprovado> / Média final = %.2f\n\n",(media/2));
                     }
                     printf("------------------------x------------------------\n");          
                 } 
    
    system("PAUSE");
    return 0;
}
