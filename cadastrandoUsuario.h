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
