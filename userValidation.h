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
            printf("\n********************************************************************************\n");
            printf("\n********************************************************************************\n");
            printf("\n********************************************************************************\n");
            printf("\n");

            printf("\nDigite 1 p/ registrar ocorrencia: ");
            printf("\nDigite 2 p/ visualizar casos registrados: ");
            printf("\nDigite 3 p/ sair: ");
            printf("\nDigite: ");
            scanf("%i", &ocorrencia);
            fflush(stdin);

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
