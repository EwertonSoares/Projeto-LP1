#ifndef __CONTANDOLINHAS_H
#define __CONTANDOLINHAS_H

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

#endif

