#include <stdio.h>
#include "cycle.h"
#define N 3

int v[10]={1,2,3,4,-10,-11,-12,-13,201,-150};

int OperaMat(int Matriz[N][N], int salto);

main(){
   long int i,a;
   int b;
   // Descomentar para medir los ticks
  
   
   // Descomentar para medir los ticks

   for (i=0;i<1000;i++)
     for (a=0;a<1000;a++)
       b=OperaMat((int (*)[3])v,2);
   // Descomentar para medir los ticks
  

       
   if (b==-612)
     printf("OperaMat BIEN programado.\n");
   else
     printf("OperaMat MAL programado.\n");
}
