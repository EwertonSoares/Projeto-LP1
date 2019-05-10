#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include <unistd.h>

//#define NOME_LEN 50
#define ESTADO_LEN 50
#define CIDADE_LEN 50
#define BAIRRO_LEN 50
#define CEP_LEN 20
#define DATA_LEN 20


struct dados
{
    //char nome[NOME_LEN];
    char estado[ESTADO_LEN];
    char cidade[CIDADE_LEN];
    char bairro[BAIRRO_LEN];
    char cep[CEP_LEN];
    int contador;
    char data[DATA_LEN];
    //int contador;
};



void main(){

    printf("\n\n*********************** REGISTRANDO OCORRENCIA *******************************");
    printf("\n********************************************************************************");
    printf("\n********************************************************************************");
    printf("\n********************************************************************************");

    //Pegando data atual do sistema
    struct tm *ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);

    //Declaração de variaveis
    char estado[3];
    char cidade[50];
    char bairro[50];
    char cep[20];
    char data[20];
    int cont = 0;
    int linhas, i, c, j = 0;

    //Criando Struct
    struct dados cadastrar;
    cadastrar.contador = 0;

    int resp;

    FILE *casosDeDengue;

    casosDeDengue = fopen("casos_de_dengue.txt", "a");

    if(casosDeDengue == NULL)
    {
        printf("\nALGO INESPERADO OCORREU!");
        usleep(1500000);
        system("clear");
        main();;
    }

    system("clear");

    printf("\nInforme a cidade onde houve a ocorrencia: ");
    scanf("%s", cadastrar.cidade);

    printf("\nInforme o estado onde houve a ocorrencia: ");
    scanf("%s", cadastrar.estado);

    printf("\nInforme o bairro onde houve a ocorrencia: ");
    scanf("%s", cadastrar.bairro);

    printf("\nInforme o CEP onde houve a ocorrencia: ");
    scanf("%s", cadastrar.cep);


   // linhas = contandoLinhasDoArquivo();
    struct dados casos[5];

    while(fscanf(casosDeDengue,"%s %s %s %s %i %s", estado, cidade, bairro, cep, &cont, data) != EOF)
    {

        strcpy(casos[j].estado, estado);
        strcpy(casos[j].cidade, cidade);
        strcpy(casos[j].bairro, bairro);
        strcpy(casos[j].cep, cep);
        strcpy(casos[j].contador, cont);
        strcpy(casos[j].data, data);
        j++;

        printf("\nDentro do while: %s",  casos[j].cep);

    }


    for(i = 1; i <= 5; i++)
    {

         printf("\n%s,     %s", cadastrar.cep, casos[i].cep);
         printf("\n#####");
        if(strcmp(cadastrar.cep, casos[i].cep) != 0)
        {

            if(i == 5)
            {
                fprintf(casosDeDengue,"%s    ",cadastrar.estado);
                fprintf(casosDeDengue,"%s    ",cadastrar.cidade);
                fprintf(casosDeDengue,"%s    ",cadastrar.bairro);
                fprintf(casosDeDengue,"%s    ",cadastrar.cep);

                cadastrar.contador = cadastrar.contador + 1;

                fprintf(casosDeDengue,"%d    ", cadastrar.contador);
                fprintf(casosDeDengue,"%d/0%d/%d",ptr->tm_mday,(ptr->tm_mon+1),(ptr->tm_year+1900));
                fprintf(casosDeDengue,"\n");

                fclose(casosDeDengue);
            }

        }
        else
        {
            fclose(casosDeDengue);

            casos[i].contador++;

            FILE *rewriteFile;

            rewriteFile = fopen("casos_de_dengue.txt", "w");

            for(c = 0; c < linhas; c++)
            {
                fprintf(rewriteFile,"%s\t\t",casos[c].estado);
                fprintf(rewriteFile,"%s\t\t",casos[c].cidade);
                fprintf(rewriteFile,"%s\t\t",casos[c].bairro);
                fprintf(rewriteFile,"%s\t\t",casos[c].cep);
                fprintf(rewriteFile,"%d\t\t", casos[c].contador);
                fprintf(rewriteFile,"%d/0%d/%d",ptr->tm_mday,(ptr->tm_mon+1),(ptr->tm_year+1900));
                fprintf(rewriteFile,"\n");
            }

            fclose(casosDeDengue);

            //Saindo do primeiro for
            break;


        }

    }

    /*printf("\n\nOCORRENCIA REGISTRADA COM SUCESSO: ");
    usleep(1500000);
    system("clear");*/

    do
    {
        printf("\n\nDESEJA REGISTRAR UMA NOVA OCORRENCIA?");
        printf("\n\nDigite 1 para registrar uma nova ocorrencia.");
        printf("\nDigite 2 para voltar a o menu inicial.");
        printf("\nDigite 3 para ver casos registrados.");
        printf("\nDigite 4 para sair");
        printf("\nDigite: ");
        scanf("%i", &resp);
        usleep(1500000);

        switch(resp)
        {
        case 1:
            system("clear");
//            registrandoOcorrencia(userLogin);
            break;
        case 2:
            system("clear");
            main();
            break;
        case 3:
            system("clear");
            //exibindoCasosDeDengue();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nNumnero digitado invalido:");
        }
    }
    while((resp != 1) && (resp != 2) && (resp != 3) && (resp != 4));

}

