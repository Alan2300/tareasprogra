#include "submenuPro.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int escribirOpcionpro();
enum Opciones { clientes = 1, vendedores, marcas, lineas, productos, FIN };

submenuPro::submenuPro()
{
    int opcion=0;
    while (( opcion = escribirOpcionpro() ) != FIN)
    {
        switch ( opcion ) {
            case clientes:
                {
                    cout<<"yayaya"<<endl;
                }
            break;
            case vendedores:
                {
                    cout<<"yayaya"<<endl;

                }
            break;
            case marcas:
                {
                    cout<<"yayaya"<<endl;
                }
            break;
            case lineas:
                {
                    cout<<"yayaya"<<endl;
                }
            break;
            case productos:
                {
                    cout<<"yayaya"<<endl;
                }
            break;
        }
    }
}

int escribirOpcionpro(){
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

    cout<< "\n\t\t\t  1. ventas Encabezado" << endl
        << "\t\t\t  2. Ventas Detalle" << endl
        << "\t\t\t  3. Bodegas" << endl
        << "\t\t\t  4. Compra Detalle" << endl
        << "\t\t\t  5. Compras Encabezado" << endl
        << "\t\t\t  6. Regresar al menú general" << endl
        <<"\n\t\t\t---------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;

}

submenuPro::~submenuPro()
{
    //dtor
}
