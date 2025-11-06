/* Lista linear estática de um controle de Pessoas -> AGENDA
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct {int cod;
               char Nome[40];
               char Tel[16];
               char email[50];
               char data_nasc[11];
               }PESSOA;
               
typedef struct { PESSOA Elem[MAX];
                 int prim, ult;
               }AGENDA;
               
 /* TAD da lista linear Agenda
  * 0 - Criar Lista Vazia
  * 1 - Inserir uma pessoa na Agenda
  * 2 - Alterar uma pessoa da Agenda
  * 3 - Remover uma pessoa da Agenda
  * 4 - Consultar uma pessoa da Agenda
  * 5 - Exibir uma pessoa da Agenda
  * 6 - Exibir todas pessoas da Agenda
  */
  
  void criar_agenda_vazia(AGENDA *A) {
	  A->prim = 0;
	  A->ult = A->prim;
	 }
int Verifica_Lista_Vazia(AGENDA A) {
	return(A.prim==A.ult);
}

int Verifica_Lista_Cheia(AGENDA A) {
	return(A.ult==MAX);
}

void Insere_Pessoa_lista(AGENDA *A, PESSOA x) {
	int i, j;
	if(Verifica_Lista_Cheia(*A)) {
		printf("A LISTA ESTA CHEIA - Aumente a capacidade da Lista para MAX*2\n");
	}else {
	      i=0;
	      while((i<A->ult)&&(x.cod > A->Elem[i].cod))
	         i++;
	      if(i==A->ult)
	         { A->Elem[i] = x;
	           A->ult++;
	        }else { j = A->ult;
		           while (j>i) {
			     	  A->Elem[j] = A->Elem[j-1];
			    	  j--;
				   }
			      A->Elem[i] = x;
			      A->ult++;
			     }
		}
}

void Remover_Pessoa_Lista(AGENDA *A, int i) {
  int j;
  j = i; 
  while(j<A->ult-1){
    A->Elem[j] = A->Elem[j+1];
    j++;
  }  
  A->ult--;	
}

void Ler_Pessoa(PESSOA *X) {
	printf("Entre com o código da pessoa: \n");
	scanf("%d", &X->cod);
	getchar();
	printf("Entre com o Nome da Pessoa\n");
	fgets(X->Nome, 40, stdin);
	printf("Entre com Telefone da Pessoa\n");
	fgets(X->Tel, 16, stdin);
}

void Exibe_Pessoa(PESSOA P) {
   printf("============  PESSOA cod %d =============\n", P.cod);
   printf(" NOME: %s\n", P.Nome);
   printf(" Telefone: %s\n", P.Tel);	
   printf("=============================================\n");
}

int Consultar_Pessoa_Lista(AGENDA A, char nome[]) {
	int i;
	i = A.prim;
	while((i<A.ult)&&((strcmp(nome,A.Elem[i].Nome)!=0)))
	  i++;
	if(i==A.ult)
	   return -1;
	 else return i;
}

void Exibe_Lista(AGENDA A) {
	int i;
	if(Verifica_Lista_Vazia(A))
	  printf("A LISTA ESTA VAZIA\n");
	else { printf("********  RELATORIA DA LISTA *************\n");
	      i = A.prim;
	      while(i<A.ult) {
	      	Exibe_Pessoa(A.Elem[i]);
		    i++;
	      }
	      printf("************ FIM DA LISTA *************\n");
	    }
}

void MENU() {
	printf("* * * ** M E N U ** * * * *\n");
	printf("+ + + + + + + + + + + + + +\n");
	printf("1 - Inserir Pessoa na Agenda\n");
	printf("2 - Alterar Pessoa na Agenda\n");
	printf("3 - Remover Pessoa da Agenda\n");
	printf("4 - Consultar Pessoa na Agenda\n");
	printf("5 - Exibir 1 Pessoa da Agenda\n");
	printf("6 - Exibir todas Pessoas da Agenda\n");
	printf("7 - Sair da Agenda\n");
	printf("Opcao:   ");
}	 

int main() {
	AGENDA A; 
	PESSOA P;
	char nome[40], r;
	int op, i;
	criar_agenda_vazia(&A);
	do{
	   MENU();	
	   scanf("%d", &op);
	   getchar();
	   switch (op) {
		 case 1: Ler_Pessoa(&P);
		         Insere_Pessoa_lista(&A, P);
		     break;  
		 case 2:
		     break;  
		 case 3: printf("Entre com o nome da pessoa que deseja remover: ");
		         fgets(nome, 40, stdin);
		         i = Consultar_Pessoa_Lista(A, nome);
		         if(i==-1)
		            printf("O nome %s nao esta na lista portanto nao tem como remover\n", nome);
		          else { P = A.Elem[i];
					     Remover_Pessoa_Lista(&A, i);
					     printf("Deseja mesmo remover a pessoa: S ou N \n");
					     Exibe_Pessoa(P);
					     scanf(" %c", &r);
		                 if(r!='S') 
		                   Insere_Pessoa_lista(&A, P);
		                  else printf("Elemento Removido com Sucesso\n");
		                }
		     break;
		 case 4: printf("Entre com o NOME da pessoa que deseja consultar\n");
		        fgets(nome, 40, stdin);
		         i = Consultar_Pessoa_Lista(A, nome);
		         if(i==-1)
		           printf("A Pessoa com Nome %s que deseja consultar nao esta na Lista\n", nome);
		          else { printf("A Pessoa com Nome %s esta na posicao %d da Lista\n", nome, i+1);
					     Exibe_Pessoa(A.Elem[i]);
					     
					    }
		     break;
		 case 5: printf("Digite a posicao que voce desja que seja exibido da Lista 0..%d\n", A.ult-1);
		         scanf("%d", &i);
		          
		         if(i>=A.ult)
		            printf("Esse elemento não esta na lista\n");
		           else { printf("A pessoa que esta na posição %d eh:\n", i);
					     Exibe_Pessoa(A.Elem[i]);
					    }
		     break;  
		 case 6:  Exibe_Lista(A);
		     break;
		 case 7:printf("Obrigado por usar nosso produto, volte sempre\n");
		     break;
		 default: printf("Entre com uma opcao válida de 1..7\n");
		     break;
	   }	
	}while(op!=7);
	
 return 0;
}        