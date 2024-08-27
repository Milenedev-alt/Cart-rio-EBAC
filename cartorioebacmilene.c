#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
   char arquivo[40];
   char cpf[40];
   char nome [40];
   char sobrenome [40];
   char cargo[40];
  
   printf("Digite o CPF a ser cadastrado: ");
   scanf("%s", cpf);
  
   strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
  
   FILE *file;//cria o arquivo
   file = fopen(arquivo, "w"); //cria o arquivo
   fprintf(file,cpf);// salva o valor da vari�vel
   fclose(file);//fecha o arquivo
  
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
  
   printf("Digite o nome a ser cadastrado:");
   scanf("%s", nome);
  
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
  
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);

   printf("Digite o sobrenome a ser cadastrado:");
   scanf("%s", sobrenome);
  
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);

   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
  
   printf("Digite o cargo a ser cadastrado:");
   scanf("%s", cargo);
  
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);

   system ("pause");
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL )
	{
		printf("N�o foi possivel localizar o arquivo! \n\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es no usu�rio:");
		printf ("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
	system("pause");
}


int main ()
{
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	system("cls");
	
	printf("\tCart�rio da EBAC\n\n");//inicio do menu
	printf("     Escolha a op��o desejada \n\n");
	printf("\t1) Registrar nomes\n");
	printf("\t2) Consultar nomes\n");
	printf("\t3) Deletar nomes\n\n");
	printf("Op��o:");// fim do menu
	
	scanf("%d", &opcao); // armazenamento da escolha do usu�rio
	
	system ("cls");
	
	switch(opcao)
	{
	    	case 1:
	        registro();
		    break;
		
		    case 2:
    	    consulta();
		    break;
		
		    case 3:
	    	deletar();
		    break;
		
	    	default:
		    printf("Esta op��o est� indisponivel\n");
	    	system("pause");
    		break;
    	}
	
    }
}
