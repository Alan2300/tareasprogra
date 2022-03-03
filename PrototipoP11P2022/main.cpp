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
    m2[x][y] = 0;//
    else
    m2[x][y] = 1;
    printf("%d , %d , %d", m2[0][0], m2[1][1], m2[2][2]);


return 0;
}
