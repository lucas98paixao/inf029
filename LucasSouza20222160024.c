// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Lucas Paixão Souza
//  email: lucas98paixao@gmail.com
//  Matrícula: 20222160024
//  Semestre: 2023.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LucasSouza20222160024.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

//Função usada para converter caracteres com acento para sem acento
wchar_t sem_acento(wchar_t c) {
    switch (c) {
        case L'á': case L'à': case L'ã': case L'â':
            return L'a';
        case L'é': case L'è': case L'ê':
            return L'e';
        case L'í': case L'ì': case L'î':
            return L'i';
        case L'ó': case L'ò': case L'õ': case L'ô':
            return L'o';
        case L'ú': case L'ù': case L'û':
            return L'u';
        default:
            return c;
    }
}

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 casa para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 casa para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 
  if (i == 2){
    dq.iAno = dq.iAno + 2000;
  }
	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  quebraData (data);
  
  DataQuebrada datacompleta = quebraData (data);
  int dia, mes, ano, bissexto = 0, datavalida;
  dia = datacompleta.iDia;
  mes = datacompleta.iMes;
  ano = datacompleta.iAno;

  if (ano % 4 == 0)
    {
        if (ano % 100 == 0)
        {
            if (ano % 400 == 0)
                bissexto = 1;
        }
        else
            bissexto = 1;
    }

    if (mes < 1 || mes > 12)
        datavalida = 0;
    else
    {
        if (mes == 2)
        {
            if (bissexto)
            {
                if (dia < 1 || dia > 29)
                    datavalida = 0;
                else
                    datavalida = 1;
            }
            else
            {
                if (dia < 1 || dia > 28)
                    datavalida = 0;
                else
                    datavalida = 1;
            }
        }
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
            if (dia < 1 || dia > 30)
                datavalida = 0;
            else
                datavalida = 1;
        }
        else
        {
            if (dia < 1 || dia > 31)
                datavalida = 0;
            else
                datavalida = 1;
        }
    }
  

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  DiasMesesAnos dma;
  dma.retorno = 1;
  quebraData (datainicial);
  quebraData (datafinal);
  DataQuebrada dataini = quebraData (datainicial);
  DataQuebrada datafin = quebraData (datafinal);
  int diai, mesi, anoi, diaf, mesf, anof;
  diai = dataini.iDia;
  mesi = dataini.iMes;
  anoi = dataini.iAno;
  diaf = datafin.iDia;
  mesf = datafin.iMes;
  anof = datafin.iAno;
  
  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }
  else {
    if (anof < anoi)
      dma.retorno = 4;
    else
      if (anoi == anof && mesf < mesi)
        dma.retorno = 4;
      else if (anoi == anof && mesf == mesi && diaf < diai)
        dma.retorno = 4;

    if (dma.retorno == 1){
    dma.qtdDias = diaf - diai;
    dma.qtdMeses = mesf - mesi;
    dma.qtdAnos = anof - anoi;
    }
    
    return dma;
  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

int q3 (char texto[251], wchar_t c, int isCaseSensitive)
{
  
  int qtdOcorrencias = 0;

  if (isCaseSensitive == 1) {
    for (int i = 0; i < strlen(texto); i++) {
      char c = texto[i];
      sem_acento (c);
      if (c == texto[i]) {
        qtdOcorrencias++;
        }
      }
    }
  else {

    for (int i = 0; i < strlen(texto); i++) {
      char c = texto[i];
      c = tolower(c);
      c = sem_acento (c);
      if (c == texto[i]) {
        qtdOcorrencias++;
        }
      }
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int i, j;
    int x = 0;

    for (i = 0; i <= strlen(strTexto) - strlen(strBusca); i++) {
        int achou = 1;
        for (j = 0; j < strlen(strBusca); j++) {
            if (strTexto[i+j] != strBusca[j]) {
                achou = 0;
                break;
            }
        }
        if (achou) {
          posicoes[x] = i;
          x++;
          posicoes[x] = i + strlen(strBusca) - 1;
          x++;
          qtdOcorrencias++;
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int invertido = 0;

    while(num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }

    return invertido;
  }

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    while (numerobase != 0) {
        if (numerobase % 10 == numerobusca) {
            qtdOcorrencias++;
        }
        numerobase /= 10;
    }
    return qtdOcorrencias;
}