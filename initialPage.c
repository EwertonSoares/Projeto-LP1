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


//Texto exibido na tela inicial
void textoInicial()
{
    printf("\n************ SISTEMA  DE PREVENÇÃO CONTRA DENGUE EM JAGUARIANA *****************");
    printf("\n********************************************************************************");
    printf("\n********************************************************************************");
    printf("\n********************************************************************************");
}

//Declarando struct global
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

//Esssa função apenas conta as linhas do arquivo
int contandoLinhasDoArquivo()
{

    char arquivoTexto[100];
    int linhas = 0;

    FILE *arquivo;

    arquivo = fopen("casos_de_dengue.txt", "r");

    if(arquivo == NULL)
    {
        printf("\nNão foi possivel ver essas informações!");
        return 0;
    }

    while(fgets(arquivoTexto, 100, arquivo) != NULL)
    {
        if(strlen(arquivo) < 99)
        {
            linhas++;
        }
    }

    return (linhas);

    fclose(arquivo);
}


//void exibindoCasosDeDengue(struct dados ordenando)
void exibindoCasosDeDengue()
{
    char estado[10];
    char cidade[30];
    char bairro[30];
    char cep[20];
    char data[20];
    int cont = 0;
    int j=0, i, m, c, r=0;
    int linhas, linhas2, aux, voltar;
    char aux2[5][20];
    //char texto[1000];


    FILE *arquivo;

    arquivo = fopen("casos_de_dengue.txt", "r");

    if(arquivo == NULL)
    {
        printf("\nNão foi possivel ver essas informações!");
        return 0;
    }

    linhas = contandoLinhasDoArquivo();
    struct dados casosDeDengue[linhas];

    for(c = 0; c < linhas; c++)
    {
        casosDeDengue[c].contador = 0;
    }



    while(fscanf(arquivo,"%s %s %s %s %d  %s", estado, cidade, bairro, cep, &cont, data) != EOF)
    {

        strcpy(casosDeDengue[j].estado, estado);
        strcpy(casosDeDengue[j].cidade, cidade);
        strcpy(casosDeDengue[j].bairro, bairro);
        strcpy(casosDeDengue[j].cep,    cep);
        casosDeDengue[j].contador = cont;
        strcpy(casosDeDengue[j].data,   data);

        j++;
    }


//Ordenação bubble sort
    for(i = linhas; i >= 0; i--)
    {
        for(m = 0; m < i; m++)
        {
            if(casosDeDengue[m].contador < casosDeDengue[m+1].contador)
            {


                aux =  casosDeDengue[m].contador;
                casosDeDengue[m].contador =  casosDeDengue[m+1].contador;
                casosDeDengue[m+1].contador =  aux;


                 strcpy(aux2[0], casosDeDengue[m].estado);
                 strcpy(casosDeDengue[m].estado, casosDeDengue[m+1].estado);
                 strcpy(casosDeDengue[m+1].estado, aux2[0]);

                 strcpy(aux2[1], casosDeDengue[m].cidade);
                 strcpy(casosDeDengue[m].cidade, casosDeDengue[m+1].cidade);
                 strcpy(casosDeDengue[m+1].cidade, aux2[1]);

                 strcpy(aux2[2], casosDeDengue[m].bairro);
                 strcpy(casosDeDengue[m].bairro, casosDeDengue[m+1].bairro);
                 strcpy(casosDeDengue[m+1].bairro, aux2[2]);

                 strcpy(aux2[3], casosDeDengue[m].cep);
                 strcpy(casosDeDengue[m].cep, casosDeDengue[m+1].cep);
                 strcpy(casosDeDengue[m+1].cep, aux2[3]);

                 strcpy(aux2[4], casosDeDengue[m].cep);
                 strcpy(casosDeDengue[m].cep, casosDeDengue[m+1].cep);
                 strcpy(casosDeDengue[m+1].cep, aux2[4]);


            }
        }

    }


    printf("ESTADO   /  CIDADE    /   BAIRRO    /     CEP     /   QTD CASOS   /  DATA\n");


    for(r = 0; r < linhas; r++)
    {
        printf("\n\n");
        printf("%s  ", casosDeDengue[r].estado);
        printf("%s  ", casosDeDengue[r].cidade);
        printf("%s  ", casosDeDengue[r].bairro);
        printf("%s  ", casosDeDengue[r].cep);
        printf("%d  ", casosDeDengue[r].contador);
        printf("%s", casosDeDengue[r].data);
        printf("\n--------------------------------------------------------------------------------\n");
    }


    fclose(arquivo);


    printf("\n\nDIGITE 0 PARA VOLTAR Ao MENU INICIAL!");
    do
    {
        printf("\nDigite: ");
        scanf("%i", &voltar);
        if(voltar == 0)
        {
            system("clear");
            main();
        }
        else
        {
            system("clear");
            usleep(1000000);
            printf("\nOpção invalida!");
            printf("\n\nTente novamente.");
            printf("\n");
        }
    }
    while(voltar !=  0);
}

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

    printf("\nInforme o estado onde houve a ocorrencia: ");
    scanf("%s", cadastrar.estado);

    printf("\nInforme o bairro onde houve a ocorrencia: ");
    scanf("%s", cadastrar.bairro);

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



    for(i = 1; i <= linhas; i++)
    {
        if(strcmp(cadastrar.cep, casos[i].cep) != 0)
        {

            if(i == linhas)
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
            registrandoOcorrencia(userLogin);
            break;
        case 2:
            system("clear");
            main();
            break;
        case 3:
            system("clear");
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

//Cadastrando usuario
void cadastrandoUsuario()
{
    printf("*************************** CADASTRAMENTO DE USUARIO ***************************");
    printf("********************************************************************************");
    printf("********************************************************************************");

    char texto[] = "@projetolp1.com.txt";
    int next;
    int num;
    char convertedNumber[40];
    char userName[20];
    char senha[20];


    srand(time (NULL));
    num = rand() % 100000;

//Convertendo numeros para string
    sprintf(convertedNumber, "%d", num);

    printf("\n\nDigite seu nome para ser cadastrado: ");
    scanf("%s", userName);

    do
    {
        printf("\nCadastre uma senha: ");
        scanf("%s", senha);

        system("clear");

//Validando senha
        if(strlen(senha) < 6)
        {
            usleep(1000000);
            printf("\nSENHA MUITO CURTA");
            printf("\nSua senha deve ter pelo menos seis caracteres\n");
        }

    }
    while(strlen(senha) < 6);

//Concatenando nome com numero convertido em string
    strcat(userName, convertedNumber);

    FILE *creatingUser;
//Criando aquivo (.txt)
    creatingUser = fopen(strcat(userName, texto), "a");

    //Chamada de função escrevendo_login_e_Senha()
    escrevendo_login_e_Senha(userName, senha);

    fclose(creatingUser);

    printf("VOCE FOI CADASTRADO COM SUCESSO!");
    usleep(2000000);
    system("clear");
    printf("\n\nEste é eu login é: %s", userName);
    printf("\nSua senha: ***************");
    printf("\n");

    do
    {
        printf("\nDESEJA CONTINUAR OU VOLTAR A TELA INICIAL?");
        printf("\nDigite 1 para continuar ou 2 para voltar a tela inicial.");
        printf("\nDigite: ");
        scanf("%i", &next);
        system("clear");

        if(next == 1)
        {
            userValidation(userName, senha);
        }
        else if(next == 2)
        {
            main();
        }
        else
        {
            printf("\nDigito invalido!");
        }
    }
    while((next != 1) && (next != 2));

//}
}

//Escrevendo login e senha do usuario no arquivo
void escrevendo_login_e_Senha(char* userName, char* senha)
{
    char nomeDoUsuario[20];

    FILE *write_arq;

    write_arq = fopen(userName, "wb");

    if(write_arq == NULL)
    {
        printf("\n************************** ALGO INESPERADO OCORREU REFASSA SEU CADASTRO! **************************");
        usleep(1000000);
        system("clear");
        cadastrandoUsuario();
    }

    //Removendo os ultimos 4 caracteries do arquivo (.txt)
    userName[strlen(userName) -4] = '\0';

    //usando fprintf para escrever login e senha no arquivo;
    fprintf(write_arq, "%s\r\n", userName);
    fprintf(write_arq, "%s", senha);

    fclose(write_arq);

}

//Validando login do usuario
void userValidation(char* userLogin, char* password)
{
    char texto[] = ".txt";
    int ocorrencia;

    FILE *usersFile;
    usersFile = fopen(strcat(userLogin, texto), "r");

    if( usersFile == NULL )
    {
        printf("\nALGO INESPERADO OCORREU!");
        usleep(1500000);
        system("clear");
        main();
    }

    //Retirando o ultimos caracteres do nome do arquivo(.txt)
    userLogin[(strlen(userLogin) -4)] = '\0';

    //Variaveies que receberão dados do arquivos
    char readUsersFile[100];
    char readPasswordFile[100];


    while(!feof(usersFile))
    {
        fgets(readUsersFile, 100,usersFile);
        fgets(readPasswordFile, 100,usersFile);
    }

    //Removendo espaços criados pelo sistema
    readUsersFile[(strlen(readUsersFile)-2)] = '\0';

    //Verificando se login e senha digitado são iguais a os que estão salvos no arquivo
    if((strcmp(readUsersFile, userLogin) == 0) && ((strcmp(readPasswordFile, password) == 0)))
    {
        printf("\nSeu login foi efetuado com sucesso");
        printf("\n");
        usleep(1500000);
        system("clear");
        //Removendo string "projetolp1" de userLogin
        userLogin[(strlen(userLogin) -15)] = '\0';
        printf("%s esta logado", userLogin);
        textoInicial();

        do
        {
            printf("\n************************************ BEM VINDO *********************************\n");
            printf("\n********************************************************************************\n");
            printf("\n********************************************************************************\n");
            printf("\n");

            printf("\nDigite 1 p/ registrar ocorrencia: ");
            printf("\nDigite 2 p/ visualizar casos registrados: ");
            printf("\nDigite 3 p/ sair: ");
            printf("\nDigite: ");
            scanf("%i", &ocorrencia);

            if(ocorrencia == 1)
            {
                system("clear");
                registrandoOcorrencia(userLogin);
            }
            else if(ocorrencia == 2)
            {
                system("clear");
                exibindoCasosDeDengue();
            }
            else if(ocorrencia == 3)
            {
                system("clear");
                main();
            }
            else
            {
                printf("\n\nOPÇÃO INVALIDA!");
                printf("\n\nTente novamente!");
            }
        }
        while((ocorrencia != 1) && (ocorrencia != 2) && (ocorrencia != 3));
    }

    else
    {
        printf("\n\n*********************** USUARIO OU SENHA INVALIDO! *************************\n\n");
        usleep(1500000);
        system("clear");
        main();
    }
    fclose(usersFile);
}

//Função principal
int main()
{
    textoInicial();
    printf("\n");

    char userLogin[50];
    char password[50];
    int num;

    printf("\n\nVOCÊ JA TEM CADASTRO?");

    printf("\n\nDigite 1 se tiver cadastro!");
    printf("\n\nDigite 2 se nao tiver cadstro!");
    printf("\n\nDigtie 3 para visualixar casos registrados");
    printf("\n\nDigite 4 para fechar o programa!");
    printf("\n\nDigite: ");
    scanf("%i", &num);
    system("clear");

    switch(num)
    {
    case 1:
        printf("\nDigite seu login: ");
        scanf("%s", userLogin);
        printf("\nDigite a sua senha: ");
        scanf("%s", password);
        system("clear");
        userValidation(userLogin, password);
        break;
    case 2:
        cadastrandoUsuario();
        break;
    case 3:
        system("clear");
        exibindoCasosDeDengue();
        //system("pause");
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("\n\n\n***************************** OPÇÃO INVALIDA! ****************************\n\n");
        usleep(1500000);
        system("clear");
        main();
    }

    return 0;
}
