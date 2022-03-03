#include <iostream>
#include <stdio.h>
#define N 3

using namespace std;

int main()
{
    int m1[N][N] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}}; // declara e inicializa la matriz m1
    int m2[N][N]; //
    int x, y;//
    for(x=0; x < N; x++)// crea el ciclo for para las filas
    for(y=0; y < N; y++)//crea el ciclo for para las columnas
    if (m1[x][y]%2 == 0)//si al estar m1 en x Y y, se divide dentro de 2 y el residuo es igual a 0, entonces:
    m2[x][y] = 0;// la acción a relizar si el if se cumple: m2 cuando este en x Y y, sera igual a 0
    else
    m2[x][y] = 1;//de lo contrario m2 en x Y y, sera 1
    printf("%d , %d , %d", m2[0][0], m2[1][1], m2[2][2]);//imprimira lo que este en m2 en la fila 1 y columna1, despues en la fila 2 y columna2 y en la fila  y columna3


return 0;
}
