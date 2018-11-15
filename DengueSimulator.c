#include<stdio.h>
#include<stdlib.h>
#include<time.h

typedef int bool;
#define true 1
#define false 0

//---------- Faz o armazenamentp do numero da casa do vizinho em um vetor ----------------------//
typedef struct Vizinho{
  int *vizinhos;
  int fim, tam, usado;
}Tvizinho;
/*----------
  struct CASA e todos seus elementos sendo eles os mosquitos
 presentes na casa, se os moradores estão infectadas ou não, numeros de pessoas
 na casa, além de apontar para proxima casa
 -----------------------*/
typedef struct Casa{
  int ndacasa, mosquito, moradores;
  bool infectada;
  Tvizinho *vizinho;
  struct Casa *prox;
}casa;

typedef struct Cidade{
  casa *inicio;
  casa *fim;
}cidade;

void INSERE_CASA(int n, cidade *c, int nm);
void LIGA_CASAS(int cI, int cII, cidade *v);
void AGENTE_ATUA();
void AGENTE_SAUDE();

casa *busca(int num, casa *c);
void insereVizinho(casa *ca, int c);

int main(void)
{
  int i, n, lc, count = 0;
  casa *ca;
  int cag;//randy

  srand(time(NULL));

  // Cria a cidade
  cidade *c = (cidade *)malloc(sizeof(cidade));
  c->inicio = c->fim = NULL;
  for (size_t i = 0; i < 10; i++)
    INSERE_CASA(i, c, 3*i);

  scanf("%d", &n);
  ca = busca(n, c->inicio);
  printf("%d", ca->moradores);

  printf("\n");
  return 0;

}

//RESPOSTA PARA TUDO
void INSERE_CASA(int n, cidade *c,int nm)
{
  casa *aux = NULL;
  if (c->inicio == NULL) {
    aux = (casa *)malloc(sizeof(casa));
    if(aux == NULL)return;
    aux->ndacasa = n;
    aux->vizinho = NULL;
    aux->moradores = nm;
    aux->mosquito = 0;
    aux->infectada = false;
    c->inicio = c->fim = aux;
  } else {
    aux = (casa *)malloc(sizeof(casa));
    if(aux == NULL)return;
    aux->ndacasa = n;
    aux->vizinho = NULL;
    aux->moradores = nm;
    aux->mosquito = 0;
    aux->infectada = false;
    c->fim->prox = aux;
    c->fim = aux;
  }
}

void LIGA_CASAS(int cI, int cII, cidade *v)
{
  casa *aux = busca(cI, v->inicio), *aux2 = busca(cII, v->inicio);
    insereVizinho(aux, cII);
    insereVizinho(aux2, cI);
}

void AGENTE_ATUA(casa cas)
{

  if(cas->mosquito != 0)
    cas->mosquito = 0;

  if(cas->infectada == true) AGENTE_SAUDE(cas);

}

void AGENTE_SAUDE(int cas)
{
  if(cas->infectada == true)
    cas->infectada = false;

  if(casa->mosquito != 0) AGENTE_ATUA(cas);

}

void MOSQUITO_BOTA(int casa)
{
  casa->mosquito = casa->mosquito + 2;
}


void insereVizinho(casa *ca, int c){
  Tvizinho *aux;
  if(ca->vizinho == NULL){
    aux->vizinhos = (int *) malloc(sizeof(int));
    aux->fim = 1;
    aux->usado = 0;
    ca->vizinho = aux;
  } else if (ca->vizinho->fim == ca->vizinho->usado) {

    ca->vizinho->vizinhos = (int *) realloc(ca->vizinho->vizinhos, ca->vizinho->fim * sizeof(int));
    ca->vizinho->fim *= 2;
  }
  aux = ca->vizinho;
  int i = aux->usado;
  aux->vizinhos[aux->usado++] = c; // ERRO

}



//TODO: Criar funcao busca e insereVetor
casa *busca(int num, casa *c){
  if (c == NULL)return NULL;
  casa *aux = c;
  if (aux->ndacasa == num)
    return aux;
  else return busca(num, c->prox);
}

/*

MOSQUITO_MOVE();
INSERE_MOSQUITO();
INICIA_MOSQUITO();
FIM();
*/
