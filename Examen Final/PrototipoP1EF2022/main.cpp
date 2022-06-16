#include <iostream>
#include <ctime>
#include <vector>
#include "Usuarios.h"
#include "submenuCat.h"

using namespace std;

int escribirOpcion();
enum Opciones { catalogos = 1, procesos, informes, FIN };

int main()
{
    Usuarios claseusuarios;
    int opcion=0;
    while (( opcion = escribirOpcion() ) != FIN)
    {
        switch ( opcion ) {
            case catalogos:
                {
                    submenuCat claseMenuCat;
                }
            break;
            case procesos:
                {
                    cout<<"yayaya"<<endl;

                }
            break;
            case informes:
                {
                    cout<<"yayaya"<<endl;
                }
            break;
        }
    }
    return 0;
}

int escribirOpcion(){
    system("cls");
    system("color F");

    time_t now = time(0);
    tm * time = localtime(&now);

    vector<string> dia_semana;
    dia_semana.push_back("Domingo");
    dia_semana.push_back("Lunes");
    dia_semana.push_back("Martes");
    dia_semana.push_back("Miercoles");
    dia_semana.push_back("Jueves");
    dia_semana.push_back("Viernes");
    dia_semana.push_back("Sabado");

    vector<string> mes;
    mes.push_back("Enero");
    mes.push_back("Febrero");
    mes.push_back("Marzo");
    mes.push_back("Abril");
    mes.push_back("Mayo");
    mes.push_back("Junio");
    mes.push_back("Julio");
    mes.push_back("Agosto");
    mes.push_back("Septiembre");
    mes.push_back("Octubre");
    mes.push_back("Noviembre");
    mes.push_back("Diciembre");

    int year = 1900 + time->tm_year;

    cout << "Hoy " << dia_semana[time->tm_wday] << ", ";
    cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
    cout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;

    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t |   Alan Abimael Galicia Ruano 9959213632 |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;

    cout<< "\n\t\t\t  1. Catálogo" << endl
        << "\t\t\t  2. Procesos" << endl
        << "\t\t\t  3. Informes" << endl
        << "\t\t\t  4. Salir del sistema" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;

}
