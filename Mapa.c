#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mapa.h"
#define BLOCK 10


int menu (void)
{
    int valor;

    printf("1 - Ler arquivo txt \n"
           "2 - Exibir ranking completo\n"
           "3 - Exibir intervalo de Ranking\n"
           "4 - Buscar palavra\n"
           "5 - Opcoes\n"
           "6 - Sair\n");
    scanf("%d", &valor);

    while (valor < 0 || valor > 6)
    {
        printf("Item nao existente, tente novamente: ");
        scanf("%d", valor);
    }

return valor;

}

void inicia_mapa (Mapa *mp) //inicia um mapa vazio
{
    mp->lista = (Item**)malloc(BLOCK*sizeof(Item*));
    mp->total = 0;
    mp->blocos = 1;
}

void insere_termo (Mapa *mp, char *s) // insere um item com termo s e conta = 1
{
    
    if ((mp->total != 0)&&((mp->total%BLOCK) == 0))
    {
        mp->lista = (Item**)realloc(mp->lista,(mp->blocos+1)*BLOCK*(sizeof(Item*)));
        mp->blocos++;
    }
    
    mp->lista[mp->total] = (Item*) malloc(sizeof(Item)); // alocação dinâmica de item no mapa

    if (mp->lista[mp->total] == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        exit(0);
    }

    strcpy(mp->lista[mp->total]->termo, s); // Insere termo s
    printf("%s\n", mp->lista[mp->total]->termo);
    mp->lista[mp->total]->conta++;
    mp->total++; // contagem do total

}
int incrementa (Mapa *mp, char *s) //incrementa contador do termo s, retorna 1 se não encontrou o termo
{
    int i;
    for (i=0; i<mp->total; i++)
    {
        if (strcmp ( mp->lista[i]->termo, s) == 0)
        {
            mp->lista[i]->conta++;
        }
        else
        {
             return 1;
        }

    }
return 0;
}
int escreve_cont (Mapa *mp, char *s, int c)  // escreve ´c` no contador do termo s,
// retorna 1 se não encontrou o termo
{
    int i;
    for (i=0; i < mp->total; i++){
        if (strcmp(mp->lista[i]->termo, s) == 0)
        {
            mp->lista[i]->conta = c;
        }
        else
            return 1;
}
return 0;
}

int le_contador (Mapa *mp, char *s) // retorna contador do termo s
{
    int i;
    for (i=0; i<= mp->total; i++)
    {
        if (strcmp ( mp->lista[i]->termo, s) ==0)
        {
            return mp->lista[i]->conta;
        }
        else
        {
            return 1;
        }
    }
}

void remove_termo (Mapa *mp, char *s)
{
    int i;
    for (i=0; i < mp->total; i++)
        {
            if (strcmp ( mp->lista[i]->termo, s) ==0)
            {
                free(mp->lista[i]);
                mp->lista[i] = &mp->lista[i + 1];
                mp->total--;
                mp->lista[i] = ( Item **) realloc(mp->lista[i], mp->total * sizeof( Item*));
            }

        }

}

void libera_mapa (Mapa *mp) // libera o espaço ocupado pelo mapa
{
    int i;
    for (i=0; i<mp->total; i++)
    {
        free (mp->lista[i]);

    }
        mp->lista =(Item **)realloc(mp->lista, BLOCK*sizeof(Item*));
}

int tamanho_mapa (Mapa * mp) // retorna número de itens no mapa
{
    return mp->total;
}

void le_termo(Mapa *mp, int i, char *t, int *c){
    int k;
    for (k=0; k<mp->total; k++)
        {
            if (k == i)
            {
              strcpy (t, mp->lista[k]->termo);
             *c = mp->lista[k]->conta;
            }
            else
                printf("Índice não encontrado, tente outro");
        }
}

