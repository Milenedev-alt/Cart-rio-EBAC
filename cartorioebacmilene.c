#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
   char arquivo[40];
   char cpf[40];
   char nome [40];
   char sobrenome [40];
   char cargo[40];
  
   printf("Digite o CPF a ser cadastrado: ");
   scanf("%s", cpf);
  
   strcpy(arquivo, cpf); //responsável por copiar os valores das string
  
   FILE *file;//cria o arquivo
   file = fopen(arquivo, "w"); //cria o arquivo
   fprintf(file,cpf);// salva o valor da variável
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
		printf("Não foi possivel localizar o arquivo! \n\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações no usuário:");
		printf ("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
	system("pause");
}


int main ()
{
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	system("cls");
	
	printf("\tCartório da EBAC\n\n");//inicio do menu
	printf("     Escolha a opção desejada \n\n");
	printf("\t1) Registrar nomes\n");
	printf("\t2) Consultar nomes\n");
	printf("\t3) Deletar nomes\n\n");
	printf("Opção:");// fim do menu
	
	scanf("%d", &opcao); // armazenamento da escolha do usuário
	
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
		    printf("Esta opção está indisponivel\n");
	    	system("pause");
    		break;
    	}
	
    }
}
