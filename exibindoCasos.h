#ifndef __EXIBINDOCASOS_H
#define __EXIBINDOCASOS_H

#include "contandoLinhas.h"
#include "estrutura.h"

//void exibindoCasosDeDengue(struct dados ordenando)
void exibindoCasosDeDengue()
{
    char estado[10];
    char cidade[50];
    char bairro[30];
    char cep[20];
    char data[20];
    int cont = 0;
    int j=0, i, m, c, r=0;
    int linhas, aux, voltar;
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
    char aux2[5][40];

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
        printf("%s \t", casosDeDengue[r].estado);
        printf("%s \t", casosDeDengue[r].cidade);
        printf("%s \t", casosDeDengue[r].bairro);
        printf("%s \t", casosDeDengue[r].cep);
        printf("%d \t", casosDeDengue[r].contador);
        printf("%s", casosDeDengue[r].data);
        printf("\n--------------------------------------------------------------------------------\n");
    }

    printf("\n\nDIGITE 0 PARA VOLTAR Ao MENU INICIAL!");
    do
    {
        printf("\nDigite: ");
        scanf("%i", &voltar);
        fflush(stdin);


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

    fclose(arquivo);
}

#endif
