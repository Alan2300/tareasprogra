#include <iostream>

using namespace std;



int obsuma (int num1 , int num2)
{
    return num1 + num2;
}
int obresta (int num1 , int num2)
{
    return num1 - num2;
}
int obmultiplicacion (int num1 , int num2)
{
    return num1 * num2;
}
int obdivision (int num1 , int num2)
{
    return num1 / num2;
}
int main()
{

    int num1, num2;
    int suma, rest, multi,divi;
    cout <<"Ingrese el primer numero para las operaciones matemáticas"<<endl;
    cin >>num1;
    cout <<"Ingrese el segundo numero para las operaciones matemáticas"<<endl;
    cin >>num2;

    suma = obsuma(num1,num2);
    cout <<"La suma de los numeros es: "<< suma<<endl;
    rest = obresta(num1,num2);
    cout <<"La resta de los numeros es: "<< rest<<endl;
    multi = obmultiplicacion(num1,num2);
    cout <<"La multiplicación de los numeros es: "<< multi<<endl;
    divi = obdivision(num1,num2);
    cout <<"La división de los numeros es: "<< divi<<endl;

    return 0;
}

