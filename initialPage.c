#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>

void textoInicial(){

printf("\n\n************ SISTEMA  DE PREVENÇÃO CONTRA DENGUE EM JAGUARIANA *****************");
printf("\n********************************************************************************");
printf("\n********************************************************************************");
printf("\n********************************************************************************");

}

//Registrando caso de dengue
void registrandoOcorrencia(char* userLogin){
printf("\nRegistrando ocorrencia: ");

  char cidade[] = "Jaguariuna";
  char bairro[20];
  char cep[10];

    FILE *casosDeDengue;

    casosDeDengue = fopen("casos_de_dengue.txt", "a");

  if(casosDeDengue == NULL){
  printf("\nAlgo inesperado ocorreu refassa seu cadastro!");
       usleep(1000000);
        userValidation();
  }

  printf("\nInforme o CEP onde houve a ocorrencia: ");
  scanf("%s", cep);

  printf("\nInforme o bairro onde houve a ocorrencia: ");
  scanf("%s", bairro);

    fprintf(casosDeDengue,"%s        ", userLogin);
    fprintf(casosDeDengue,"%s     ", cidade);
    fprintf(casosDeDengue,"%s           ", bairro);
    fprintf(casosDeDengue,"%s", cep);
    fprintf(casosDeDengue, "\n");

  printf("\nOcorrencia reristrada com sucesso: ");

  fclose(casosDeDengue);

}


//Cadastrando usuario
void cadastrandoUsuario(){
 printf("************************** CADASTRAMENTO DE USUARIO *****************************");

 char texto[] = ".txt";
 char proj[] = "spcdj";
 char userName[20];
 char senha[20];

 printf("\nDigite seu nome: ");
 scanf("%s", userName);

 strcat(userName, proj);

 printf("\nDigite uma senha: ");
 scanf("%s", senha);

  FILE *creatingUser;

  creatingUser = fopen(strcat(userName, texto), "a");

  //Chamada de função
  escrevendo_login_e_Senha(userName, senha);

  fclose(creatingUser);

  userName[(strlen(userName) -4)] = '\0';

  printf("Você foi cadastrado com sucesso!");
  printf("\nSeu login é: %s", userName);
  printf("\nSua senha: ******");
  printf("\n");
  usleep(10000000);
  system("clear");
   main();
  //logado();
}


//Escrevendo nome e senha do usuario
void escrevendo_login_e_Senha(char* userName, char* senha){

  char nomeDoUsuario[20];
  char proj[] = "spcdj";

    FILE *write_arq;

    write_arq = fopen(userName, "wb");

  if(write_arq == NULL){
  printf("\nAlgo inesperado ocorreu refassa seu cadastro!");
       usleep(1000000);
       system("clear");
    //system(clear);
    cadastrandoUsuario();
  }

  printf("\nConfirme seu nome: ");
  scanf("%s", nomeDoUsuario);

  strcat(nomeDoUsuario, proj);
  //usando fprintf para armazenar a string no arquivo
  fprintf(write_arq, "%s\r\n", nomeDoUsuario);
  fprintf(write_arq, "%s", senha);

  fclose(write_arq);

}

//Login de usuario
void userValidation(char* userLogin, char* password){

char texto[] = ".txt";
int ocorrencia;

    FILE *usersFile;
    usersFile = fopen(strcat(userLogin, texto), "r");

    if( usersFile == NULL ){
        printf("\nAlgo inesperado ocorreu!");
            usleep(1000000);
            system("clear");
            main();
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
                printf("\nSeu login foi efetuado com sucesso");
                printf("\n");
                usleep(1000000);
                system("clear");
                userLogin[(strlen(userLogin) -5)] = '\0';
                printf("%s esta logado", userLogin);
                textoInicial();

                do{
                printf("\n************************************ BEM VINDO *********************************\n");
                printf("\n********************************************************************************\n");
                printf("\n********************************************************************************\n");

                printf("\nDigite 1 p/ registrar ocorrencia: ");
                printf("\nDigite 2 p/ visualizar ocorrencia: ");
                printf("\nDigite 3 p/ sair: ");
                scanf("%i", &ocorrencia);

                if(ocorrencia == 1){
                registrandoOcorrencia(userLogin);
                }
                else if(ocorrencia == 2){
                printf("\nChamará função que exibira casos registrados");
                //vizualizarOcorrenciarCadastradas();
                }
                else if(ocorrencia == 3){
                system("clear");
                main();
                }
                else{
                printf("\n\nEscolha invalida!");
                printf("\n\nTente novamente!");
                }
                }while((ocorrencia != 1) && (ocorrencia != 2) && (ocorrencia != 3));
            }

            else {
                printf("\n\n\n\n\n******** USUARIO OU SENHA INVALIDO! **************************\n\n");
                usleep(1000000);
                system("clear");
                usleep(1000000);
                main();
            }

    fclose(usersFile);
}


//Função principal
int main(){

    textoInicial();

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
            //system("clear");
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
            usleep(1000000);
            system("clear");
            //System("cls");
            usleep(1000000);
            main();
        }

    return 0;
}














