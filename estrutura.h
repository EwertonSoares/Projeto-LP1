#ifndef __ESTRUTURA_H
#define __ESTRUTURA_H

//Declarando constantes
#define ESTADO_LEN 50
#define CIDADE_LEN 50
#define BAIRRO_LEN 50
#define CEP_LEN 50
#define DATA_LEN 20

//Declarando struct global
struct dados
{
    char estado[ESTADO_LEN];
    char cidade[CIDADE_LEN];
    char bairro[BAIRRO_LEN];
    char cep[CEP_LEN];
    int contador;
    char data[DATA_LEN];
};

#endif
