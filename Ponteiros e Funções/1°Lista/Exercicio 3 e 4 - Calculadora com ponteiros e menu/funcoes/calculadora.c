#include "layout.c"
#include "funcao_calculadora.c"

void calculadora(){
     
     int n1,n2,op;
     char val = 's';
     
       while(val =='s' || val =='S'){
                 
                system("cls"); 
                menu();
                
                printf("Escolha uma opção :");
                scanf("%d",&op);
                
                if(op >=1 && op <= 5){
                       
                    system("cls");
                     
                    printf("Informe o 1° número :");
                    scanf("%d",&n1);
                    
                    printf("\nInforme o 2° número :");
                    scanf("%d",&n2);
                

                
                                
                     switch(op){
                                
                                case 1:
                                       footer();
                                       soma(&n1,&n2);
                                break ;
                                
                                case 2:
                                       footer();
                                       sub(&n1,&n2);
                                break;
                                
                                case 3:
                                       footer();
                                       mult(&n1,&n2);
                                break;
                                
                                case 4:
                                       footer();
                                       divisao(&n1,&n2);
                                break;
                                
                                case 5:
                                       footer();
                                       soma(&n1,&n2);
                                       sub(&n1,&n2);
                                       mult(&n1,&n2);
                                       divisao(&n1,&n2);
                                break;
                                       
                                default:
                                        system("cls");
                                        printf("Erro, selecione uma opção valida\n\n");
                                break;            
                                    
                     }
                        
                     printf("\n\nDeseja continuar (S) / (N) = ");
                     val=getche(); 
                     
                }else{
                      system("cls");
                      break;
                }                    
         }
         system("cls");           
}

