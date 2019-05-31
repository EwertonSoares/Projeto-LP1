#include "estrutura.h"
#include "exibindoCasos.h"

//Registrando caso de dengue
void registrandoOcorrencia(char* userLogin)
{
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

    casosDeDengue = fopen("casos_de_dengue.txt", "r");

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
    setbuf(stdin,NULL);

    printf("\nInforme o estado onde houve a ocorrencia: ");
    scanf("%s", cadastrar.estado);
    setbuf(stdin,NULL);

    printf("\nInforme o bairro onde houve a ocorrencia: ");
    scanf("%s", cadastrar.bairro);
    setbuf(stdin,NULL);

    printf("\nInforme o CEP onde houve a ocorrencia: ");
    scanf("%s", cadastrar.cep);
    setbuf(stdin,NULL);

    linhas = contandoLinhasDoArquivo();
    struct dados casos[linhas];


    while(fscanf(casosDeDengue,"%s %s %s %s %d  %s", estado, cidade, bairro, cep, &cont, data) != EOF)
    {
        strcpy(casos[j].estado, estado);
        strcpy(casos[j].cidade, cidade);
        strcpy(casos[j].bairro, bairro);
        strcpy(casos[j].cep,    cep);
        casos[j].contador = cont;
        strcpy(casos[j].data, data);

        j++;
    }

    fclose(casosDeDengue);

    for(i = 1; i <= linhas; i++)
    {
        if(strcmp(cadastrar.cep, casos[i].cep) != 0)
        {

            if(i == linhas)
            {
                FILE *anexandoOcorrencia;

                anexandoOcorrencia = fopen("casos_de_dengue.txt", "a");

                fprintf(anexandoOcorrencia,"%s\t",cadastrar.estado);
                fprintf(anexandoOcorrencia,"%s\t",cadastrar.cidade);
                fprintf(anexandoOcorrencia,"%s\t",cadastrar.bairro);
                fprintf(anexandoOcorrencia,"%s\t",cadastrar.cep);

                cadastrar.contador = cadastrar.contador + 1;

                fprintf(anexandoOcorrencia,"%d\t", cadastrar.contador);
                fprintf(anexandoOcorrencia,"%d/0%d/%d",ptr->tm_mday,(ptr->tm_mon+1),(ptr->tm_year+1900));
                fprintf(anexandoOcorrencia,"\n");

                fclose(anexandoOcorrencia);
            }

        }
        else
        {
            casos[i].contador++;

            FILE *rewriteFile;

            rewriteFile = fopen("casos_de_dengue.txt", "w");

            for(c = 0; c < linhas; c++)
            {
                fprintf(rewriteFile,"%s\t",casos[c].estado);
                fprintf(rewriteFile,"%s\t",casos[c].cidade);
                fprintf(rewriteFile,"%s\t",casos[c].bairro);
                fprintf(rewriteFile,"%s\t",casos[c].cep);
                fprintf(rewriteFile,"%d\t", casos[c].contador);
                fprintf(rewriteFile,"%d/0%d/%d",ptr->tm_mday,(ptr->tm_mon+1),(ptr->tm_year+1900));
                fprintf(rewriteFile,"\n");
            }

            fclose(casosDeDengue);

            //Saindo do primeiro for
            break;
        }
    }

    printf("\n\nOCORRENCIA REGISTRADA COM SUCESSO: ");
    usleep(1500000);
    system("clear");

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
            registrandoOcorrencia(userLogin);
            break;
        case 2:
            system("clear");
            main();
            break;
        case 3:
            system("clear");
            setbuf(stdin, NULL);
            exibindoCasosDeDengue();
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
