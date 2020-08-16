#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct pacientes{
       
   char nome[50];
   int idade;
   float altura,peso,imc;    
       
}dados_p;

/*Função inserir*/
void inserir(){
    
    FILE *arquivo = fopen("pacientes.dat","ab");
    char op='s';
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int i,tam;
                   
                         while(op=='s' || op=='S'){
                                  
                                  if(op=='s' || op=='S'){
                                      
                                      printf("Informe quantos pacientes deseja cadastrar = ");
                                      scanf("%d",&tam);
                                          
                                         struct pacientes dados_p[tam]; 
                                            
                                            system("cls");
                                            printf("---------------------Cadastro de pacientes---------------------\n\n");
                                                
                                            for(i=0; i < tam; i++){
                                                     
                                                        system("\n\n");
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
                                                        
                                                        system("cls");
                                                        printf("Dados cadastrados com sucesso");   
                                              }
                                      
                                      }else{
                                            break;
                                            system("cls");
                                      }       
                                     
                                      printf("\n\nDeseja continuar (S) ou (N) :");
                                      op=getche();
                                      system("cls");
                                      
                       }       
             }
            
        fclose(arquivo);                        
}

/*Função Alterar registro*/
void alterar_dados(){

    FILE *arquivo = fopen("pacientes.dat","r+b");
    char op='s',nome[50];
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int i=1,count=0,posicao=0;
                                    
                       printf("Informe o nome do registro que deseja alterar = ");
                       scanf("%s",&nome);
                          
                             while(!feof(arquivo)){
                                      
                                             if(fread(&dados_p,sizeof(struct pacientes), 1, arquivo) == 1){
                                                  
                                                   if(strcmp(nome,dados_p.nome) == 0){
                                                                                       
                                                         printf("\n\nPaciente %d\n\n",i); 
                                                         printf("<Nome> = %s",dados_p.nome);
                                                         printf("\n<Idade> = %d",dados_p.idade);
                                                         printf("\n<Altura> = %.2f",dados_p.altura);
                                                         printf("\n<Peso> = %.2f",dados_p.peso);
                                                         printf("\n<Imc> = %.2f",dados_p.imc);                                 
                                                         count++;
                                                         posicao = i++;
                                                  }                                          
                                                                                      
                                             }
                              i++;                        
                           }
                            
                           if(count == 0){
                                printf("\n\nErro nenhum registro encontrado\n\n");
                           
                           }else{
                                
                                              printf("\n\n------------------Atualizção de paciente------------------");
                                              printf("\n\n<Nome> = ");
                                              scanf("%s",&dados_p.nome);
                                              fflush(stdin);
                                              
                                              printf("\n<Idade> = ");
                                              scanf("%d",&dados_p.idade);
                                              fflush(stdin);
                                              
                                              printf("\n<Altura> = ");
                                              scanf("%f",&dados_p.altura);
                                              fflush(stdin);
                                              
                                              printf("\n<Peso> = ");
                                              scanf("%f",&dados_p.peso);
                                              fflush(stdin);
                                              
                                              dados_p.imc = dados_p.peso/(dados_p.altura*dados_p.altura);
                                
                                              fseek(arquivo,(posicao-1)*sizeof(struct pacientes), SEEK_SET);
                                              fwrite(&dados_p, sizeof(struct pacientes), 1, arquivo);
                                              
                                              printf("\nDados alterados com sucesso\n\n");
                          
                                  }               
                       
             }
            
        fclose(arquivo);
        getch();
        system("cls");              
}

/*Função Excluir registro*/
void deleta_dados(){
     
    FILE *arquivo2 = fopen("temp.dat","wb"); 
    FILE *arquivo = fopen("pacientes.dat","r+b");
    char op='s',nome[50];
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int i=1,count=0,posicao=0;
                                    
                       printf("Informe o nome do registro que deseja alterar = ");
                       scanf("%s",&nome);
                          
                             while(!feof(arquivo)){
                                      
                                             if(fread(&dados_p,sizeof(struct pacientes), 1, arquivo) == 1){
                                                  
                                                   if(strcmp(nome,dados_p.nome) != 0){
                    
                                                        fwrite(&dados_p, sizeof(struct pacientes), 1, arquivo2);
                                                   }                                          
                                                                                      
                                             }                      
                           }
  
             }
        fclose(arquivo2);   
        fclose(arquivo);
        
        system("del pacientes.dat"); 
        system("ren temp.dat pacientes.dat");
        
        printf("\n\nDados deletados com sucesso\n\n");
         
        getch();
        system("cls");              
}

/*Função Listar todos*/
void listar_todos(){
     FILE *arquivo = fopen("pacientes.dat","rb");
     
     if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                    int i=0,val,count=0;
                    printf("---------------------Lista de pacientes---------------------\n\n");
                        while(!feof(arquivo)){
                                     
                                   val=fread(&dados_p,sizeof(struct pacientes),1,arquivo);
                                                     
                                     if(val == 1){
                                           
                                           printf("Paciente %d\n\n",i+1); 
                                           printf("<Nome> = %s",dados_p.nome);
                                           printf("\n<Idade> = %d",dados_p.idade);
                                           printf("\n<Altura> = %.2f",dados_p.altura);
                                           printf("\n<Peso> = %.2f",dados_p.peso);
                                           printf("\n<Imc> = %.2f",dados_p.imc);
                                           printf("\n-------------------------\n\n");   
                                           count++;
                                     }
                            i++;                         
                       }
                       if(val == count){
                            printf("Erro nenhum registro encontrado\n\n");
                       }

             }
          
     fclose(arquivo);
     getch();
     system("cls");
}

/*Listar pelo id do paciente*/
void listar_especifico(){

    FILE *arquivo = fopen("pacientes.dat","rb");
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int val,posicao;
                                    
                        printf("Pesquise pelo <ID> do paciente = ");
                        scanf("%d",&posicao);
                        fflush(stdin); 
                          
                          
                          fseek(arquivo,(posicao-1)*sizeof(struct pacientes), SEEK_SET);
                          val = val=fread(&dados_p,sizeof(struct pacientes),1,arquivo);

                          if(val == 0 || posicao == 0){
                                  printf("\n\nErro, registro não existe\n\n");
                          
                          }else{
                                  system("cls");
                                  printf("---------------------Lista de específica---------------------\n\n");           
                                  printf("Paciente %d\n\n",posicao); 
                                  printf("<Nome> = %s",dados_p.nome);
                                  printf("\n<Idade> = %d",dados_p.idade);
                                  printf("\n<Altura> = %.2f",dados_p.altura);
                                  printf("\n<Peso> = %.2f",dados_p.peso);
                                  printf("\n<Imc> = %.2f\n\n",dados_p.imc);
                          }                        
                       
             }
            
        fclose(arquivo);
        getch();
        system("cls");              
} 

/*Função Listar registros por palavras*/
void listar_palavras(){

    FILE *arquivo = fopen("pacientes.dat","rb");
    char nome[50];
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int i=1,count=0,posicao=0;
                                    
                       printf("Informe uma palavra que deseja pesquisar = ");
                       scanf("%s",&nome);
                          
                          system("cls");
                          printf("---------------------Pesquisa de pacientes---------------------\n\n");               
                             while(!feof(arquivo)){
                                      
                                             if(fread(&dados_p,sizeof(struct pacientes), 1, arquivo) == 1){
                                                  
                                                   if(strstr(dados_p.nome, nome) != NULL){
            
                                                         printf("Paciente %d\n\n",i); 
                                                         printf("<Nome> = %s",dados_p.nome);
                                                         printf("\n<Idade> = %d",dados_p.idade);
                                                         printf("\n<Altura> = %.2f",dados_p.altura);
                                                         printf("\n<Peso> = %.2f",dados_p.peso);
                                                         printf("\n<Imc> = %.2f\n\n",dados_p.imc);                                 
                                                         count++;
                                                         posicao = i++;
                                                  }                                          
                                                                                      
                                             }
                              i++;                        
                           }
                            
                           if(count == 0){
                                printf("\n\nErro nenhum registro encontrado\n\n");
                           }
             }
            
        fclose(arquivo);
        getch();
        system("cls");              
}

/*Função Listar registros pelo nome*/
void listar_nome(){

    FILE *arquivo = fopen("pacientes.dat","rb");
    char nome[50];
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   int i=1,count=0,posicao=0;
                                    
                       printf("Informe o nome do registro que deseja pesquisar = ");
                       scanf("%s",&nome);
                          
                             while(!feof(arquivo)){
                                      
                                             if(fread(&dados_p,sizeof(struct pacientes), 1, arquivo) == 1){
                                                  
                                                   if(strcmp(nome,dados_p.nome) == 0){
                                                         system("cls");                       
                                                         printf("---------------------Pesquisa de pacientes---------------------\n\n");                              
                                                         printf("Paciente %d\n\n",i); 
                                                         printf("<Nome> = %s",dados_p.nome);
                                                         printf("\n<Idade> = %d",dados_p.idade);
                                                         printf("\n<Altura> = %.2f",dados_p.altura);
                                                         printf("\n<Peso> = %.2f",dados_p.peso);
                                                         printf("\n<Imc> = %.2f\n\n",dados_p.imc);                                 
                                                         count++;
                                                         posicao = i++;
                                                  }                                          
                                                                                      
                                             }
                              i++;                        
                           }
                            
                           if(count == 0){
                                printf("\n\nErro nenhum registro encontrado\n\n");
                           }
             }
            
        fclose(arquivo);
        getch();
        system("cls");              
}

/*Função Listar pelo imc*/
void listar_imc(){

    FILE *arquivo = fopen("pacientes.dat","rb");
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   
                   float imc2,imc3;
                   int i=1,count=0;
                       
                       //printf("Informe o imc desejado = ");
                       printf("Informe um valor inicial do IMC para pesquisa = ");
                       scanf("%f",&imc2);
                       fflush(stdin);
                       
                       system("cls");
                       
                       printf("Informe um valor final do IMC para pesquisa = ");
                       scanf("%f",&imc3);
                       fflush(stdin);  
                       
                         system("cls");
                         printf("---------------------Lista intervalo de IMC---------------------");            
                             while(!feof(arquivo)){
                                   
                                   if(fread(&dados_p,sizeof(struct pacientes),1,arquivo) == 1){
                                         
                                         if(dados_p.imc >= imc2 && dados_p.imc <= imc3){
                                             
                                                     printf("\n\nPaciente %d\n\n",i); 
                                                     printf("<Nome> = %s",dados_p.nome);
                                                     printf("\n<Idade> = %d",dados_p.idade);
                                                     printf("\n<Altura> = %.2f",dados_p.altura);
                                                     printf("\n<Peso> = %.2f",dados_p.peso);
                                                     printf("\n<Imc> = %.2f",dados_p.imc);
                                                     printf("\n\n-----------------------------------\n\n");  
                                                     count++;                                  
                                         }                                
                                   } 
                                i++;                  
                             }
                             if(count == 0){
                                      printf("\n\nErro nenhum registro encontrado\n\n");
                             }         
                       
             }
            
        fclose(arquivo);
        getch();
        system("cls");              
} 

/*Função Listar pela altura*/
void listar_altura(){

    FILE *arquivo = fopen("pacientes.dat","rb");
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   
                   float altura;
                   int i=1,count=0;
                       
                       printf("Informe uma faixa de altura desejada = ");
                       scanf("%f",&altura);
                       fflush(stdin);
                        
                           system("cls");
                           printf("---------------------Lista sobre altura---------------------");           
                             while(!feof(arquivo)){
                                   
                                   if(fread(&dados_p,sizeof(struct pacientes),1,arquivo) == 1){
                                         
                                         if(dados_p.altura <1.00){
                                             
                                             if(altura <1.00){
                                                     printf("\n\nPaciente %d\n\n",i); 
                                                     printf("<Nome> = %s",dados_p.nome);
                                                     printf("\n<Idade> = %d",dados_p.idade);
                                                     printf("\n<Altura> = %.2f",dados_p.altura);
                                                     printf("\n<Peso> = %.2f",dados_p.peso);
                                                     printf("\n<Imc> = %.2f",dados_p.imc);
                                                     printf("\n\n-----------------------------------\n\n");  
                                                     count++;         
                                             }                            
                                         }
                                         else if(dados_p.altura >=1.00){
                                             
                                             if(altura >=1.00 ){
                                                     printf("\n\nPaciente %d\n\n",i); 
                                                     printf("<Nome> = %s",dados_p.nome);
                                                     printf("\n<Idade> = %d",dados_p.idade);
                                                     printf("\n<Altura> = %.2f",dados_p.altura);
                                                     printf("\n<Peso> = %.2f",dados_p.peso);
                                                     printf("\n<Imc> = %.2f",dados_p.imc);
                                                     printf("\n\n-----------------------------------\n\n");  
                                                     count++;         
                                             }                            
                                         }
                                   } 
                                i++;                  
                             }
                             if(count == 0){
                                      printf("\n\nErro nenhum registro encontrado\n\n");
                             }         
                       
             }
            
        fclose(arquivo);
        getch();
        system("cls");              
}

/*Função Listar pelo peso*/
void listar_peso(){

    FILE *arquivo = fopen("pacientes.dat","rb");
        
             if(arquivo == NULL){
                   printf("Erro, arquivo não existe");
        
             }else{
                   
                   float peso;
                   int i=1,count=0;
                       
                       printf("Informe um faixa de peso desejada = ");
                       scanf("%f",&peso);
                       fflush(stdin); 
                       
                           system("cls");
                           printf("---------------------Lista sobre faixa de peso---------------------\n");
                                       
                             while(!feof(arquivo)){
                                   
                                   if(fread(&dados_p,sizeof(struct pacientes),1,arquivo) == 1){
                                         
                                        if(dados_p.peso >= 0 && dados_p.peso <= 50){
                                             
                                             if(peso >= 0 && peso <= 50){
                                                     
                                                     printf("Paciente %d\n\n",i); 
                                                     printf("<Nome> = %s",dados_p.nome);
                                                     printf("\n<Idade> = %d",dados_p.idade);
                                                     printf("\n<Altura> = %.2f",dados_p.altura);
                                                     printf("\n<Peso> = %.2f",dados_p.peso);
                                                     printf("\n<Imc> = %.2f",dados_p.imc);
                                                     printf("\n\n-----------------------------------\n");  
                                                     count++;        
                                             }                            
                                         }
                                         else if(dados_p.peso > 50){
                                             
                                             if(peso > 50){
                                                     
                                                     printf("\n\nPaciente %d\n\n",i); 
                                                     printf("<Nome> = %s",dados_p.nome);
                                                     printf("\n<Idade> = %d",dados_p.idade);
                                                     printf("\n<Altura> = %.2f",dados_p.altura);
                                                     printf("\n<Peso> = %.2f",dados_p.peso);
                                                     printf("\n<Imc> = %.2f",dados_p.imc);
                                                     printf("\n\n-----------------------------------\n\n");  
                                                     count++;        
                                             }                            
                                        }                        
                                   } 
                                i++;                  
                             }
                             if(count == 0){
                                      printf("\n\nErro nenhum registro encontrado\n\n");
                             }         
                       
             }
        fclose(arquivo);
        getch();
        system("cls");              
}  
int main(){
    
      int op,tam; 
       system ("color F");
       setlocale(LC_ALL, "portuguese");          
         
         do{
            
             printf("---------------------MENU---------------------\n");
     
             printf("<1> - Inserir\n\n");
             printf("<2> - Alterar\n\n");
             printf("<3> - Excluir\n\n");
             printf("<4> - Listar todos\n\n");
             printf("<5> - Listar específico\n\n");
             printf("<6> - Listar pelo nome\n\n");
             printf("<7> - Listar pelo imc\n\n");
             printf("<8> - Listar pela altura\n\n");
             printf("<9> - Listar pelo peso\n\n");
             printf("<10> - Listar por palavras\n\n");
             printf("<11> - Sair\n\n");
     
             printf("----------------------------------------------\n");
             
             printf("Escolha uma opção = ");
             scanf("%d",&op);
             fflush(stdin);
             
            switch(op){
                                 
                       case 1:
                            system("cls");
                                inserir();
                       break;
                             
                       case 2:
                            system("cls");
                                alterar_dados();           
                       break;
                       
                       case 3:
                            system("cls");
                                deleta_dados();
                       break;
                             
                       case 4:
                            system("cls");
                                listar_todos();
                       break;
                             
                       case 5: 
                            system("cls");
                                listar_especifico();
                       break;
                       
                       case 6: 
                            system("cls");
                                listar_nome();
                       break;
                       
                       case 7: 
                            system("cls");
                                listar_imc();
                       break;
                       
                       case 8: 
                            system("cls");
                                listar_altura();
                       break;
                       
                       case 9: 
                            system("cls");
                                listar_peso();
                       break;
                        
                       case 10: 
                            system("cls");
                                listar_palavras();
                       break;                         
                } 
                if(op >11){
                     system("cls");      
                     printf("\nOpção invalída, tente novamente\n\n");  
                
                }else if(op == 11){
                      system("cls");
                      break;
                }   
             
         }while(op!=11);
         
                          
                

    system("PAUSE");
    return 0;
}
