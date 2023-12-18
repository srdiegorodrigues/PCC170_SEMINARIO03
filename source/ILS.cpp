#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Util.h"
#include "Arquivos.h"
#include "Descida.h"
#include <iostream>
#include "ILS.h"

using namespace std;

float ILS(int n, int *s, float **d,
          int vezesnivel, // nro de vezes sem melhora em um dado nivel
          int ILSmax)  // nro de niveis sem melhora
{
  int i, j, nivel, iter, MelhorIter;
  int *s_2l;
  float fo, fo_2l;
  s_2l = cria_vetor(n);
  fo = descida(n,s,d);
  iter = 0;
  MelhorIter = 0;
  nivel = 1;
  while (iter - MelhorIter < ILSmax){
    iter++;
    // s_2l <- s
    atualiza_vetor(s_2l,s,n);
    int vezes = 0;
    while (vezes < vezesnivel){
       int ntrocasmax = nivel + 1;
       int ntrocas = 0;
       atualiza_vetor(s_2l,s,n);
       fo_2l = fo;
       while (ntrocas < ntrocasmax){
         ntrocas++;
         i = rand()%n;
         do{
           j = rand()%n;
         }while (i == j);
         int aux;
         aux = s_2l[i];
         s_2l[i] = s_2l[j];
         s_2l[j] = aux;
       } // fim while ntrocasmax
//       fo_2l = descida_randomica(n,s_2l,d,0.70*n*(n-1)/2);
       fo_2l = descida(n,s_2l,d);
       if (fo_2l < fo){
         fo = fo_2l;
         atualiza_vetor(s,s_2l,n);
         vezes = 0;
         nivel = 1;
         MelhorIter = iter;
         //printf("fo = %12.4f \n", fo);
       }
       vezes++;
    } // fim while vezesnivel
    nivel++;
    //printf("Aumentando o nivel perturbacao para %2d \n",nivel);
  } // fim while
  fo = descida(n,s,d);
  libera_vetor(s_2l);
  return fo;
} // fim ILS






















