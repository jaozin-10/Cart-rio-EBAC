#include <stdio.h> //biblioteca de comunicação com úsuario 
#include <stdlib.h> // biblioteca de alocaação de espaço em memória 
#include <locale.h> // biblioteca de alocação de texo por região 
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema 
{
	//Inicio criação de variáveis/string
	 char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     //Final criação de variáveis/string
    
    printf("Digite o cpf a ser cadastrado: "); // Coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
     
    strcpy(arquivo, cpf); // responsavel por copiar os valores das string
     
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel 
    fclose(file);  // fecha o arquivo
     
    file = fopen(arquivo, "a");  //cria o arquivo 
    fprintf(file,","); // Virgula entre os dados 
    fclose(file); // fecha arquivo
     
    printf("Digite o nome a ser cadastrado: "); // mensagem para usuário 
    scanf("%s",nome); //%s refere-se a string
     
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,nome); // salva o valor da variavel
    fclose(file); // fecha arquivo
     
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,","); // Virgula entre os dados
    fclose(file); // fecha arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // mensagem para usuário 
    scanf("%s",sobrenome); // espaço para digitar sobrenome
     
        
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,sobrenome); // colocar o sobrenome no arquivo
    fclose(file); // fecha arquivo
     
    file = fopen(arquivo, "a"); //cria o aquivo
    fprintf(file,","); // colocar Virgula entre os dados no arquivo
    fclose(file); // fecha arquivo
     
    printf("Digite o cargo a ser cadastrado: "); // mensagem para usuário 
    scanf("%s",cargo); // espaço para digitar cargo
     
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
	
	    printf("Digite o cpf a ser consultado: "); // mensagem para usuário 
	    scanf("%s",cpf); // espaço para digitar cpf do usuario
	
	FILE *file; //cria o aquivo
	file = fopen(cpf,"r"); // abrir aquivo e ler cpf
	
	if(file == NULL) // Se o documento for Nulo 
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n");	// mensagem para usuário 		
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{  
		printf("\nEssas são as informações do usuário: "); // mensagem para usuário 
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n"); // pular linha
	}    
	
	    system("pause");  		
	
}

int deletar()
{
	 char cpf[40];
	 
	    printf("Digite o cpf do usuário a ser deletado: "); // mensagem para usuário 
	    scanf("%s",cpf);
	 
	    remove(cpf);
	 
	 FILE *file; //cria o aquivo
	 file = fopen(cpf,"r"); // abrir aquivo e ler cpf 
	 
	 if(file == NULL)
	 {
	    printf("O usuário não pode ser encontardo no sistema! \n"); // mensagem para usuário 
	    system("pause");	
	 	
	 }
	 	 	 	 
}

int main()
{
    int opcao=0;  // Definindo variáveis 
	int laco=1;

	    for(laco=1;laco=1;)
	    {
		
        system("cls"); // Responsavel por limpar a tela 
	
	    setlocale(LC_ALL, "portuguese"); // Definindo a linguagem 
	
	    printf("### Cadastro da EBAC ###\n\n"); // Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes nomes\n");
	    printf("\t3 - Deletar nomes nomes\n\n\n");
	    printf( "Opção: "); // Fim do menu
	
        scanf("%d", &opcao);  // armazenando a escolha do usuario 
     
        system("cls"); // Responsavel por limpar a tela
             
                switch(opcao) // Inicio da seleção do menu 
	            {
	   	        case 1:
	   	        registro(); // Chamada de funções 
     	        break;     	    
     	  
     	        case 2:
     	        consulta(); // Chamada de funções 
    	        break;
    	  
    	        case 3:
    	        deletar(); // Chamada de funções 
		        break;
		  			   		
		        default:
		        printf("Essa opção não esta disponivel!\n\n"); // Mensagem ao usuário 
		        system("pause");
		        break;
		        //fim da seleção do menu 
     	
	            }
      
        }
   
}



