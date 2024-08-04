#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //funcão responsavel por cadastrar os usuários no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacão de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //cria arquivo
    file = fopen(arquivo, "w"); //cria arquivo e o "w" significa escrever
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
     
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
    }
	
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas sao as informacoes do usuario; ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}

    system("pause"); 
	  
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!.\n");
		system("pause");
	}	
}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	    
        setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
    
        printf("$$$ Clinicas Contratos VIP FATURAMENTO $$$\n\n"); //Inicio do Menu
        printf("Escolha a opcao desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
    	printf("opcao: "); //Final do Menu
   
        scanf("%d", &opcao); //Armazenando a escolha do usuario
    
        system("cls"); //responsavel por limpar a tela
        
        switch(opcao)//inicio da seleção da seleção do menu
        {
        	case 1:
        	registro(); //chamada de fuções
            break;
            
			case 2:
            consulta();
        	break;
        	
        	case 3:
            deletar();
        	break;
        	
        	default:
        	printf("Essa opcao nao esta disponivel!\n");
    	    system("pause");
    	    break;
    	    
        }
        
   
   } 
}