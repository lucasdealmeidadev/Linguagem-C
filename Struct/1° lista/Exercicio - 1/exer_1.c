#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct notas{
      char nome[50]; 
      int n1,n2; 
       
}alunos;

int main(){

           float media=0;
           
           setlocale(LC_ALL,"portuguese");
           
           printf("Informe seu nome : ");
           gets(alunos.nome);
           
           system("cls");
           
           printf("Informe sua 1° nota :");
           scanf("%d",&alunos.n1);
           
           system("cls");
           
           printf("Informe sua 2° nota :");
           scanf("%d",&alunos.n2);
           
           system("cls");
           
           media = (alunos.n1 + alunos.n2)/2;
                         
                         if(media >= 6){
                                  printf("Nome = %s",alunos.nome);
                                  printf("\n\nSituação = <Aprovado> / Média final = %.2f\n\n",media);
                         }else{
                                  printf("Nome = %s",alunos.nome);
                                  printf("\n\nSituação = <Reprovado> / Média final = %.2f\n\n",media);
                         }
    
    system("PAUSE");
    return 0;
}
