/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Silas Nazare
 *
 * Created on 27 de janeiro de 2021, 03:07
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int i, j, tam, trilhos, count, cifra[100][1000];
    char texto[1000] = "silas nazare chagas";
    
    printf("CRIPTOGRAFIA - CERCA DE FERROVIA\n\n");
    /*printf("Texto a ser criptografado: ");
    scanf("%c", texto);
    printf("\nNumero de trilhos: ");
    scanf("%d", &trilhos);*/
    
    tam = strlen(texto);
    trilhos = 3;
    
    for(int i = 0, posicao = 0; i < tam; i++, posicao++)
    {
        if(texto[posicao] == ' ') posicao++;
        texto[i] = texto[posicao];
    }
    
    for(i = 0; i<trilhos ;i++)
    {
        for(j = 0; j<tam; j++)
        {
            cifra[i][j] = 0;
        }
    }
    
    count = 0;
    j = 0;
    
    while(j<tam)
    {
        if(count%2==0)
        {
            for(i=0;i<trilhos;i++)
            {
                cifra[i][j] = (int)texto[j]; 
                j++;
            }
        }
        else
        {
            for(i=trilhos-2;i>0;i--)
            {
                cifra[i][j] = (int)texto[j];
                j++;
            }  
        } 
        count++;
    }

    for(i = 0; i<trilhos; i++)
    {
        for(j = 0; j<tam; j++)
        {
            if(cifra[i][j]!=0)
            printf("%c", cifra[i][j]);
        }
    }
    printf("\n");

    return (EXIT_SUCCESS);
}