#include <iostream>

using namespace std;

int main()
{
    double salar = 200;
    double vent = 0;
    double comi = 0;
    double suel = 0;
    while(vent != -1)
    {
        cout <<endl<< "Introduzaca la cantidad de ventas en dolares que hizo el vendedor: $";
        cin >> vent;
        if (vent == -1)
            break;
        else
        {
        comi = vent * 9/100;
        suel = salar + comi;
        cout <<endl<<"El salario total del vendedor sera de: $"<<suel;
        }
    }


    return 0;
}
