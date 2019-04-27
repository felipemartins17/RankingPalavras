#include <stdio.h>
#include <stdlib.h>

typedef struct _item
{
int conta; //contador
char *termo; //palavra
} Item;

typedef struct _mapa
{
int total; // n�mero de itens no mapa
int blocos; // n�mero de blocos de itens alocados
Item **lista; // vetor de ponteiros para itens
} Mapa;

int menu(void);
void inicia_mapa (Mapa *mp); //inicia um mapa vazio
void insere_termo (Mapa *mp, char *s); // insere um item com termo s e conta=1
int incrementa (Mapa *mp, char *s); // incrementa contador do termo s, retorna 1
// se n�o encontrou o termo
int escreve_cont (Mapa *mp, char *s, int c); // escreve �c` no contador do termo s,
// retorna 1 se n�o encontrou o termo
int le_contador (Mapa *mp, char *s); // retorna contador do termo s
void remove_termo (Mapa *mp, char *s); // remove o item com termo s
void libera_mapa (Mapa * mp); // libera o espa�o ocupado pelo mapa
int tamanho_mapa (Mapa * mp); // retorna n�mero de itens no mapa
void le_termo (Mapa * mp, int i, char *t, int *c); //retorna em �t� o termo no �ndice �i�
//e em �c� o seu contador
