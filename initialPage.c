#include<stdio.h>
#include <stdlib.h>
#include<string.h>

void userValidation(char* userLogin, char* password){

char texto[] = ".txt";

    //CRiando ponteiro para arquivo
    FILE *usersFile;
    //Arindo aquivo concatenado
    usersFile = fopen(strcat(userLogin, texto), "r");

    if( usersFile == NULL ){
        printf("\nAlgo errado ocorreu!");
        exit (0);
    }

    userLogin[(strlen(userLogin) -4)] = '\0';

    char readUsersFile[20];
    char readPasswordFile[20];


    while(!feof(usersFile)){
        fgets(readUsersFile, 20,usersFile);
        fgets(readPasswordFile, 20,usersFile);
    }

    readPasswordFile[(strlen(readPasswordFile)-1)] = '\0';
    readUsersFile[(strlen(readUsersFile)-1)] = '\0';

      if((strcmp(readUsersFile, userLogin) == 0) && ((strcmp(readPasswordFile, password) == 0))){
                printf("\nLogado");
                //initialUserPage();
            }

            else {
                printf("\nUsuario ou senha invalidos!");
                main();
            }

    fclose(usersFile);
}


//Função principal
int main(){

printf("\n************ SISTEMA  DE PREVENÇÃO CONTRA DENGUE EM JAGUARIANA *****************");
printf("\n********************************************************************************");
printf("\n********************************************************************************");
printf("\n********************************************************************************");
printf("\n********************************************************************************");

    char userLogin[20];
    char password[20];
    int num;

    printf("\nVocê ja tem cadastro?");

    do{
        printf("\nDigite 1 se tiver cadastro!");
        printf("\nDigite 2 se nao tiver cadstro!");
        printf("\nDigite: ");
        scanf("%i", &num);
        system("clear");

        if( num == 1 ){
            printf("\nDigite seu login: ");
            scanf("%s", userLogin);
            printf("\nDigite a sua senha: ");
            scanf("%s", password);
            userValidation(userLogin, password);

        }
         else if( num == 2 ){

        }
        if(( num != 1) && (num != 2)){
            printf("\nNumero digitado invalido!");

        }
    }
    while(( num != 1) && (num != 2));



    return 0;
}














