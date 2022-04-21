#include <iostream>
#include "usuariosCine.h"
#include "datosUsuariosCine.h"
#include "peliculas.h"
#include "datosPeliculas.h"
#include "salas.h"
#include "datosSalas.h"

using namespace std;
int escribirOpcion();
int escribirOpcionCatalogo();
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
                    enum OpcionesCatalogos { peliculass = 1, salass, asientos, cines, clientes, FIN };
                    int opcionCatalogos=0;
                    while (( opcionCatalogos = escribirOpcionCatalogo() ) != FIN)
                    {
                        switch ( opcionCatalogos ) {
                        case peliculass:
                            {
                                peliculas peliculasclase;
                            }
                            break;
                        case salass:
                            {
                                cout <<"yey :)";
                            }
                            break;
                        case asientos:
                            {
                                cout <<"yey :)";
                            }
                            break;
                        case cines:
                            {
                                salas claseSala;
                            }
                            break;
                        case clientes:
                            {
                                cout <<"yey :)";
                            }
                            break;
                            break;
                        }
                    }

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
    cout<<"\t\t\t-------------------------------------------------"<<endl;
	cout<<"\t\t\t |   ALAN ABIMAEL GALICIA RUANO; 9959-21-3632  |"<<endl;
	cout<<"\t\t\t-------------------------------------------------"<<endl;

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
int escribirOpcionCatalogo(){
    system("cls");
    cout<<"\t\t\t---------------------------------"<<endl;
    cout<<"\t\t\t |   CATALOGOS DEL SISTEMA  |"<<endl;
    cout<<"\t\t\t---------------------------------"<<endl;
    cout<< "\n\n\t\t\t  1. Peliculas" << endl
    << "\t\t\t  2. Salas" << endl
    << "\t\t\t  3. Asientos" << endl
    << "\t\t\t  4. cines" << endl
    << "\t\t\t  5. clientes" << endl
    << "\t\t\t  6. Regresar al menu principal" << endl
    <<"\n\t\t\t---------------------------------"<<endl
    << "\n\t\t\tIngrese su opcion: ";
    int opcionMenuCat;
    cin >> opcionMenuCat;

    return opcionMenuCat;
}
