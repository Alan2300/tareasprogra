#include <iostream>
#include "usuariosCine.h"
#include "datosUsuariosCine.h"

using namespace std;
int escribirOpcion();
enum Opciones { catalogos = 1, procesos, informes, FIN };

int main()
{
    usuariosCine usuariosDeCine;
    int opcion=0;
    while (( opcion = escribirOpcion() ) != FIN)
    {
        switch ( opcion ) {
            case catalogos:
                {
                    cout <<"yey :)";
                }
            break;
            case procesos:
                {
                    cout <<"yey :)";
                }
            break;
            case informes:
                {
                    cout <<"yey :)";
                }
            break;
        }
    }
    return 0;
}

int escribirOpcion(){
    system("cls");
    cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA RECURSOS HUMANOS  |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;

    cout<< "\n\n\t\t\t  1. catalogos" << endl
        << "\t\t\t  2. procesos" << endl
        << "\t\t\t  3. informes" << endl
        << "\t\t\t  4. salir" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;

}
