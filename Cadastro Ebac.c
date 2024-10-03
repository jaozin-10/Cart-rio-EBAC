#include <stdio.h> //biblioteca de comunica��o com �suario 
#include <stdlib.h> // biblioteca de alocaa��o de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��o de texo por regi�o 
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema 
{
	//Inicio cria��o de vari�veis/string
	 char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     //Final cria��o de vari�veis/string
    
    printf("Digite o cpf a ser cadastrado: "); // Coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
     
    strcpy(arquivo, cpf); // responsavel por copiar os valores das string
     
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel 
    fclose(file);  // fecha o arquivo
     
    file = fopen(arquivo, "a");  //cria o arquivo 
    fprintf(file,","); // Virgula entre os dados 
    fclose(file); // fecha arquivo
     
    printf("Digite o nome a ser cadastrado: "); // mensagem para usu�rio 
    scanf("%s",nome); //%s refere-se a string
     
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,nome); // salva o valor da variavel
    fclose(file); // fecha arquivo
     
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,","); // Virgula entre os dados
    fclose(file); // fecha arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // mensagem para usu�rio 
    scanf("%s",sobrenome); // espa�o para digitar sobrenome
     
        
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,sobrenome); // colocar o sobrenome no arquivo
    fclose(file); // fecha arquivo
     
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,","); // colocar Virgula entre os dados no arquivo
    fclose(file); // fecha arquivo
     
    printf("Digite o cargo a ser cadastrado: "); // mensagem para usu�rio 
    scanf("%s",cargo); // espa�o para digitar cargo
     
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,cargo); // colocar o cargo no arquivo 
    fclose(file); // fecha arquivo

         
        system("pause");     
     
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	    printf("Digite o cpf a ser consultado: "); // mensagem para usu�rio 
	    scanf("%s",cpf); // espa�o para digitar cpf do usuario
	
	FILE *file; //cria o aquivo
	file = fopen(cpf,"r"); // abrir aquivo e ler cpf
	
	if(file == NULL) // Se o documento for Nulo 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");	// mensagem para usu�rio 		
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{  
		printf("\nEssas s�o as informa��es do usu�rio: "); // mensagem para usu�rio 
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n"); // pular linha
	}    
	
	    system("pause");  		
	
}

int deletar()
{
	 char cpf[40];
	 
	    printf("Digite o cpf do usu�rio a ser deletado: "); // mensagem para usu�rio 
	    scanf("%s",cpf);
	 
	    remove(cpf);
	 
	 FILE *file; //cria o aquivo
	 file = fopen(cpf,"r"); // abrir aquivo e ler cpf 
	 
	 if(file == NULL)
	 {
	    printf("O usu�rio n�o pode ser encontardo no sistema! \n"); // mensagem para usu�rio 
	    system("pause");	
	 	
	 }
	 	 	 	 
}

int main()
{
    int opcao=0;  // Definindo vari�veis 
	int laco=1;

	    for(laco=1;laco=1;)
	    {
		
        system("cls"); // Responsavel por limpar a tela 
	
	    setlocale(LC_ALL, "portuguese"); // Definindo a linguagem 
	
	    printf("### Cadastro da EBAC ###\n\n"); // Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes nomes\n");
	    printf("\t3 - Deletar nomes nomes\n\n\n");
	    printf( "Op��o: "); // Fim do menu
	
        scanf("%d", &opcao);  // armazenando a escolha do usuario 
     
        system("cls"); // Responsavel por limpar a tela
             
                switch(opcao) // Inicio da sele��o do menu 
	            {
	   	        case 1:
	   	        registro(); // Chamada de fun��es 
     	        break;     	    
     	  
     	        case 2:
     	        consulta(); // Chamada de fun��es 
    	        break;
    	  
    	        case 3:
    	        deletar(); // Chamada de fun��es 
		        break;
		  			   		
		        default:
		        printf("Essa op��o n�o esta disponivel!\n\n"); // Mensagem ao usu�rio 
		        system("pause");
		        break;
		        //fim da sele��o do menu 
     	
	            }
      
        }
   
}



