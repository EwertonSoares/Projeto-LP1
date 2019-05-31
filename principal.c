#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include <unistd.h>
#include "exibindoCasos.h"
#include "registrandoOcorrencia.h"
#include "cadastrandoUsuario.h"
#include "userValidation.h"

//Texto exibido na tela inicial
void textoInicial()
{
    printf("\n*************** SISTEMA DE MONITORAMENTO DE CASOS DE DENGUE ********************");
    printf("\n********************************************************************************");
    printf("\n********************************************************************************");
    printf("\n********************************************************************************");
    printf("\n********************************* BEM VINDO ************************************");
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
        fflush(stdin);

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
