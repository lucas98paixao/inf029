#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

strprincipal vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) 
{
  int retorno = 0;
  posicao = posicao - 1;
  
   if (posicao<0 || posicao>9) {
    retorno = POSICAO_INVALIDA;
  }
  
  else if (vetorPrincipal[posicao].vetaux != NULL) {
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
  }

  else if (tamanho>TAM){
    retorno = SEM_ESPACO_DE_MEMORIA;
  }
  else if (tamanho<1){
    retorno = TAMANHO_INVALIDO;
  }
  
  else if (vetorPrincipal[posicao].vetaux == NULL) {
   vetorPrincipal[posicao].vetaux = (int*) malloc(tamanho * sizeof(int));
    vetorPrincipal[posicao].tamanho = tamanho;
      retorno = SUCESSO;
  }

  return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
   
  posicao = posicao - 1;
  if (posicao<0 || posicao>9)
      posicao_invalida = 1;
  if (vetorPrincipal[posicao].vetaux != NULL){
    existeEstruturaAuxiliar = 1;
  }
  if (vetorPrincipal[posicao].ocupados < vetorPrincipal[posicao].tamanho){
    int temEspaco = 1;
  }
  

    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else
    {
        if (existeEstruturaAuxiliar)
        {
            if (temEspaco)
            {
                //insere
              vetorPrincipal[posicao].vetaux[vetorPrincipal[posicao].ocupados] = valor;
              vetorPrincipal[posicao].ocupados++;
              retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  int retorno;
  posicao = posicao - 1;
  
  if (posicao<0 || posicao>9) {
    retorno = POSICAO_INVALIDA;
  }
  else if (vetorPrincipal[posicao].vetaux == NULL || vetorPrincipal[posicao].tamanho == 0){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  else if (vetorPrincipal[posicao].ocupados == 0){
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  else {
    vetorPrincipal[posicao].ocupados--;
    retorno = SUCESSO;
  }
  
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno;
  posicao = posicao - 1;
  
  if (posicao<0 || posicao>9) {
    retorno = POSICAO_INVALIDA;
  }
  else if (vetorPrincipal[posicao].vetaux == NULL || vetorPrincipal[posicao].tamanho == 0){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  else if (vetorPrincipal[posicao].ocupados == 0){
    retorno = ESTRUTURA_AUXILIAR_VAZIA;
  }
  else {
   int verdadeiro = 0;
    for (int i = 0; i < vetorPrincipal[posicao].ocupados; i++){
      if (vetorPrincipal[posicao].vetaux[i] == valor){
        verdadeiro = 1;
        for (int j=i,k=j+1; j < vetorPrincipal[posicao].ocupados; j++, k++){
          int troca = vetorPrincipal[posicao].vetaux[j];
          vetorPrincipal[posicao].vetaux[j] = vetorPrincipal[posicao].vetaux[k];
          vetorPrincipal[posicao].vetaux[k] = troca;
        }
        vetorPrincipal[posicao].ocupados--;
      }
    }
    if (verdadeiro){
    retorno = SUCESSO;
    }
    else{
      retorno = NUMERO_INEXISTENTE;
    }
  }
  
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0;
  posicao = posicao - 1;
  
  if (posicao<0 || posicao>9) {
    retorno = POSICAO_INVALIDA;
  }
  else if (vetorPrincipal[posicao].vetaux == NULL || vetorPrincipal[posicao].tamanho == 0){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  else if (vetorPrincipal[posicao].ocupados == 0) {
      retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }
    else{
      for (int i = 0; i < vetorPrincipal[posicao].ocupados; i++){
        vetorAux[i] = vetorPrincipal[posicao].vetaux[i];
        retorno = SUCESSO;
      }
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    posicao = posicao - 1;
  
    if (posicao<0 || posicao>9) {
      retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao].vetaux == NULL || vetorPrincipal[posicao].tamanho == 0){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else if (vetorPrincipal[posicao].ocupados == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
      else{
        for (int i = 0; i < vetorPrincipal[posicao].ocupados; i++){
        vetorAux[i] = vetorPrincipal[posicao].vetaux[i];
          for (int j = 0; j < vetorPrincipal[posicao].ocupados-i; j++){
            if (vetorAux[j] > vetorAux[j+1]){
              int troca = vetorAux[j];
              vetorAux[j] = vetorAux[j+1];
              vetorAux[j+1] = troca;
            }
          }
        }    
          retorno = SUCESSO;
        }
      return retorno;
  }

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
		int conseguiu	=	0;
		for(int i=0;	i	<	TAM; i++){
			if(vetorPrincipal[i].vetaux	!= NULL &&  vetorPrincipal[i].tamanho >0 && vetorPrincipal[i].ocupados > 0){
				for(int j=0;	j	<	vetorPrincipal[i].ocupados	;j++){
					vetorAux[j]	=	vetorPrincipal[i].vetaux[j];
				}
				conseguiu++;
			}
		}
		if (conseguiu == 0){
			retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
		}else{
			retorno = SUCESSO;
		}
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
		int conseguiu	=	0;
    int contaux = 0;
		for(int i=0;	i	<	TAM; i++){
			if(vetorPrincipal[i].vetaux	!= NULL &&  vetorPrincipal[i].tamanho > 0 && vetorPrincipal[i].ocupados > 0){
				for(int j=0;	j	<	vetorPrincipal[i].ocupados; j++){
					vetorAux[j]	=	vetorPrincipal[i].vetaux[j];
          contaux++;
				}
				conseguiu++;
			}
		}
    for (int j = 0; j < contaux; j++){
          if (vetorAux[j] > vetorAux[j+1]){
            int troca = vetorAux[j];
            vetorAux[j] = vetorAux[j+1];
            vetorAux[j+1] = troca;
          }
      }
    if (conseguiu == 0){
			retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
		}else{
			retorno = SUCESSO;
		}
    return retorno;

}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
//sugestão da sala: usar realloc
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    posicao = posicao - 1;
    novoTamanho = novoTamanho + vetorPrincipal[posicao].ocupados;
    if (posicao<0 || posicao>9) {
      retorno = POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao].vetaux == NULL || vetorPrincipal[posicao].tamanho == 0){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else if (novoTamanho < 1) {
      retorno = NOVO_TAMANHO_INVALIDO;
    }
    else{
      vetorPrincipal[posicao].tamanho = novoTamanho;
		  vetorPrincipal[posicao].vetaux = realloc(vetorPrincipal[posicao].vetaux, novoTamanho * sizeof(int));
      retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao = posicao - 1;
  
    if (posicao<0 || posicao>9) {
      return POSICAO_INVALIDA;
    }
    else if (vetorPrincipal[posicao].vetaux == NULL || vetorPrincipal[posicao].tamanho == 0){
      return SEM_ESTRUTURA_AUXILIAR;
    }
    else if (vetorPrincipal[posicao].ocupados == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
      }
    else{
      return vetorPrincipal[posicao].ocupados;
    }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
  int elementos = 0;
	for(int i=0; i	< TAM ;i++){
		elementos	=	elementos + vetorPrincipal[i].ocupados;
	}
	if (elementos ==	0){
		return NULL;
	}
  else {
    No *inicioListaComCabecote = (No*)	malloc (sizeof(No));
		inicioListaComCabecote->prox = NULL; 
    int vetaux[elementos]; 
    for(int i = 0;	i	<	TAM; i++){
      for(int j = 0;	j	<	vetorPrincipal[i].ocupados; j++){
        int k = 0;
        vetaux[k]	=	vetorPrincipal[i].vetaux[j];
        k++;
        } 
      }
  for(int l = 0; l <	elementos; l++) {
			No* novo = malloc(sizeof(No));
			novo->conteudo = vetaux[l];
			novo->prox = NULL;
			if(inicioListaComCabecote->prox == NULL){
				inicioListaComCabecote->prox = novo;
			}
      else{
				No* atual = inicioListaComCabecote;
				while(atual->prox != NULL) 
				atual = atual->prox;
				atual->prox = novo; 
			}
		}
	return inicioListaComCabecote;
	}
}  
/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
 	No* atual = inicio->prox;
	int i = 0;
	while(atual->prox != NULL){
		vetorAux[i] = atual->conteudo;
		atual = atual->prox;
		i++;
	}
	vetorAux[i] = atual->conteudo; 
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
  No* presente = *inicio;

	while(presente->prox != NULL){
		No* troca = (No*)malloc (sizeof(No));
		troca = presente->prox;
		free(presente);
		presente = troca;
	}

	*inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/
// dica da sala: inicializar com um valor invalido para poder retornar um erro ao fazer a validação. Caso queira excluir o ultimo, por exemplo, é só procurar o ultimo que não é invalido.

void inicializar()
{
  for (int i = 0; i<TAM; i++){
    vetorPrincipal[i].vetaux = NULL;
    vetorPrincipal[i].tamanho	=	0;
		vetorPrincipal[i].ocupados	=	0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
  for(int i = 0;	i < TAM ;	i++){
		free(vetorPrincipal[i].vetaux);
  }
}