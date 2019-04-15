#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>
void cadastrandoUsuario(){
 printf("************************* CADASTRAMENTO DE USUARIO *****************************");

 char texto[] = ".txt";
 char userName[20];
 char senha[20];

 printf("\nDigite seu nome: ");
 scanf("%s", userName);

 printf("\nDigite uma senha: ");
 scanf("%s", senha);

  FILE *creatingUser;

  creatingUser = fopen(strcat(userName, texto), "a");

  //Chamada de função
  arquivoDeUsuario(userName, senha);

  fclose(creatingUser);

  printf("Você foi cadastrado com sucesso!");
  //logado();

}


//Escrevendo nome e senha do usuario
void arquivoDeUsuario(char* userName, char* senha){

  char nomeDoUsuario[20];

    FILE *write_arq;

    write_arq = fopen(userName, "wb");

  if(write_arq == NULL){
  printf("\nAlgo de errado ocorreu refassa seu cadastro!");
    //system(clear);
    cadastrandoUsuario();
  }

  printf("\nConfirme seu nome: ");
  scanf("%s", nomeDoUsuario);

  //usando fprintf para armazenar a string no arquivo
  fprintf(write_arq, "%s\r\n", nomeDoUsuario);
  fprintf(write_arq, "%s", senha);

  fclose(write_arq);

}

//Login de usuario
void userValidation(char* userLogin, char* password){

char texto[] = ".txt";

    FILE *usersFile;
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

    readUsersFile[(strlen(readUsersFile)-2)] = '\0';

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

    printf("\n\nVocê ja tem cadastro?");

        printf("\n\nDigite 1 se tiver cadastro!");
        printf("\n\nDigite 2 se nao tiver cadstro!");
        printf("\n\nDigite 3 para fechar o programa!");
        printf("\n\nDigite: ");
        scanf("%i", &num);
        system("clear");

        switch(num){
        case 1:
            printf("\nDigite seu login: ");
            scanf("%s", userLogin);
            printf("\nDigite a sua senha: ");
            scanf("%s", password);
            userValidation(userLogin, password);
            break;
        case 2:
            cadastrandoUsuario();
            break;
        case 3:
            exit(0);
            //system("pause");
            break;
        default:
            printf("\n\n\n\n\n************************** NUMERO DIGITADO INVALIDO! ***************************\n\n");
            usleep(2000000);
            system("clear");
            //System("cls");
            usleep(1000000);
            main();
        }

    return 0;
}














