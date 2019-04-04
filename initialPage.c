#include<stdio.h>
#include <stdlib.h>
#include<string.h>
void userValidation(char* userLogin, char* password)
{

    FILE *usersFile;
    usersFile = fopen("user.txt", "r");

    if( usersFile == NULL )
    {
        printf("Arquivo nao encontrado!");
        exit (0);
    }

    char readUsersFile[20];
    char readPasswordFile[20];


    while(!feof(usersFile)){
        fscanf (usersFile, "%20[^\n]", readUsersFile);
        fscanf (usersFile, "%20[^\n]", readPasswordFile);

        printf("\n\nNome digitado: %s %i", userLogin, strlen(userLogin));
        printf("\nSenha digitada: %s %i", password, strlen(password));

        printf("\n\nEsse é o usuario: %s %i", readUsersFile, strlen(readUsersFile));
        printf("\nEssa é a senha: %s %i", readPasswordFile, strlen(readPasswordFile));


           if((strcmp(readUsersFile, userLogin) == 0) && ((strcmp(readPasswordFile, password) == 0)))
            {
                printf("\nSâo iguais");
            }
            else {
                printf("\nSâo diferentes");
                printf("\n\n");
            }
    }

printf("#########");

    fclose(usersFile);
}


int main()
{
    char userLogin[20];
    char password[20];
    int num;

    printf("\nVocê é aluno ou administrador?");

    do
    {
        printf("\nDigite 1 se aluno!\n");
        printf("\nDigite 2 se administrador!");
        printf("\n:");
        scanf("%i", &num);
        system("clear");

        if( num == 1 )
        {

        }
        else if( num == 2 )
        {
            printf("\nDigite login de usuario: ");
            scanf("%s", userLogin);
            printf("\nDigite a password de usuario: ");
            scanf("%s", password);
            userValidation(userLogin, password);

        }
        if(( num != 1) && (num != 2))
        {
            printf("\nNumero digitado invalido!");

        }
    }
    while(( num != 1) && (num != 2));



    return 0;
}














