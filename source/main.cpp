/*
Calibracao de parametros do Iterated Local Search para o Problema do Caixeiro Viajante
Autor: Marcone Jamilson Freitas Souza / Debora Nasser Diniz
Local: Departamento de Computacao - Universidade Federal de Ouro Preto
Homepage: www.decom.ufop.br/prof/marcone
Data: 04/12/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include "Util.h"
#include "Arquivos.h"
#include "Estruturas.h"
#include "Construcao.h"
#include "Listas.h"
#include "Descida.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "ILS.h"
#include <vector>
//---------------------------------------------------------------------------
using namespace std;

int main(int argc, char* argv[])
{
    int n,                    // numero de cidades
      *s;                   // vetor solucao corrente
    float **d,                // matriz de distancias entre as cidades
        fo;                 // funcao objetivo corrente

    vector<string> arguments(argv + 1, argv + argc);

    string inputFileName = arguments[0];

    int size_before=0;
    int size_after = 0;
    for(int i=0;i<inputFileName.length();i++){
        if(inputFileName[i]=='_'){
            size_before = i+1;
        }
        if(inputFileName[i]=='.'){
            size_after = i;
        }
    }
    char resultado[size_after-size_before];
    for(int i=size_before,j=0;i<size_after;i++,j++){
        resultado[j]=inputFileName[i];
    }
    n = atoi(resultado);

    s = cria_vetor(n); // vetor solucao
    d = cria_matriz_float(n, n); // matriz de distancias

    inputFileName = arguments[0];
    char *filename2 = new char[inputFileName.length() + 1];
    strcpy(filename2, inputFileName.c_str());
    le_arq_matriz(filename2, n, d);

    constroi_solucao(n,s,d);
    embaralha_vetor(s,n);
    fo = calcula_fo(n, s, d);

    int vezesnivel, ILSmax;

    for(unsigned int i=1; i<arguments.size(); i+=2)
    {
        if(arguments[i]== "--VEZESNIVEL")
            vezesnivel = atoi(arguments[i+1].c_str());
        else if(arguments[i]== "--ILSMAX")
            ILSmax = atoi(arguments[i+1].c_str());
    }

    fo = ILS(n,s,d,vezesnivel,ILSmax);
    cout << fo;
    libera_vetor(s);
    libera_matriz_float(d, n);
    return 0;
}
