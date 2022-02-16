#include <iostream>

using namespace std;

int main()
{
    double kil = 0;
    double lit = 0;
    double kpl = 0;
    while (kil != -1)
        {
            cout << " Escriba la cantidad de kilometros recorridos: "<<endl;
            cin >> kil;
            if (kil ==-1)
                break;
            else
            {
            cout << " Escriba la cantidad de litros utilizados: "<<endl;
            cin >> lit;
            kpl = kil/lit;
            cout <<"La cantidad de kilometros por litros es: "<<kpl<<endl;
            }
        }


    return 0;

}
