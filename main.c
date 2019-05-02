#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mapa.h"
#define BLOCK 10

int main()
{
    Mapa mp;
    FILE *arq;
    int i, result;
    float x;
    int valor, max, min, mincar;
    char caminho[20];
    char termo[40];
    int tam;

    inicia_mapa(&mp);

    valor = menu();

    while (valor != 0)
    {
        switch (valor)
        {
        case 1:
            printf ("*Ler Arquivo* \n");
            printf("Digite caminho: ");
            scanf("%s", caminho);

            arq = fopen(caminho,"r"); // abrir arquivo no caminho especificado
                if (arq == NULL)
                {
                     printf("Erro, nao foi possivel abrir o arquivo\n");
                }

    while(fscanf(arq, "%s", termo) != EOF)
    {
        //Adiciona cada palavra na estrutura
        tam = strlen(termo);
        if (tam > 3)
        {
           insere_termo(&mp, termo); 
        }
        
    }
    
    printf("\nPalavras armazenadas corretamente\n");
    
    valor = menu();

    break;

    case 2:
        printf ("\n*Ranking Completo*\n"
                "\nPalavra | Contador\n");
        
        ranking(&mp);
        
        valor = menu();
    break;

    case 3:
        printf ("*Intervalo de Ranking*\n"
                "Digite quantidade maxima: ");
        scanf("%d", &min);
        printf ("Digite quantidade minima: ");
        scanf("%d", &max);
        valor = menu();

    break;

    case 4:
        printf("*Buscar Palavra*\n"
               "Digite a palavra: ");
        scanf ("%s", termo);
        valor = menu();
    break;

    case 5:
        printf("*Opcoes*\n");
        printf("Digite o minimo de caracteres a considerar: ");
        scanf ("%d", &mincar);
        valor = menu();
    break;

    case 6:
        printf("Saindo do programa...\n");
        exit(0);
        valor = menu();
    break;
    }
}

libera_mapa(&mp);
return 0;

}
