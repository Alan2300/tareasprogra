#include "Lineas.h"
#include "DatosLineas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>

using namespace std;

int escribirOption();
void nuevoRegistroPuesto( fstream& );
int obtenernCodigoPuesto( const char * const );
void mostrarLineaP( ostream&, const DatosLineas & );
void imprimirRegistroPuesto( fstream& );
void crearArchivoPuesto();
void modificarRegistroPuesto( fstream& );
void eliminarRegistroPuesto( fstream& );
void consultarRegistroPuesto( fstream& );
void mostrarLineaPantallaP( const DatosLineas &);

enum Optios { imprim = 1, nuevo = 2, leer, eliminar, editar, regresar};

Lineas::Lineas()
{
	fstream puestoEntradaSalida( "Line.dat", ios::in | ios::out | ios::binary);
    if ( !puestoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoPuesto();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
   int opcionP=0;

    while ( ( opcionP = escribirOption() ) != regresar ) {

        switch ( opcionP ) {

         case imprim:
            {
                imprimirRegistroPuesto( puestoEntradaSalida );
            }
            break;
         case nuevo:
            {
                nuevoRegistroPuesto( puestoEntradaSalida );
            }
            break;
         case leer:
            {
                consultarRegistroPuesto( puestoEntradaSalida );

            }
            break;
          case eliminar:
            {
                eliminarRegistroPuesto( puestoEntradaSalida );
            }
            break;
          case editar:
            {
                modificarRegistroPuesto( puestoEntradaSalida );
            }
            break;
            break;
        }
        puestoEntradaSalida.clear();
    }
}

int escribirOption()
{
    system("cls");
    time_t now = time(0);//Hora y fecha por Daniel Alexander Hall Alvarez - 9959-21-1395
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

    //Formato=hoy miercoles, 27 de mayo del 2015
    cout<< "\n";
    cout << "Hoy " << dia_semana[time->tm_wday] << ", ";
    cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
    cout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;

    cout<<"\n\t\t\t-----------------------------------------------"<<endl;
    cout<<"\t\t\t\t       ----------------"<<endl;
	cout<<"\t\t\t\t        |   PUESTOS  |"<<endl;
	cout<<"\t\t\t\t       ----------------"<<endl;

    cout<< "\n\n\t\t\t 1. Crear un archivo de texto para imprimir" << endl
        << "\t\t\t 2. Crear una nueva linea" << endl
        << "\t\t\t 3. Ver las lineas" << endl
        << "\t\t\t 4. Eliminar linea" << endl
        << "\t\t\t 5. Editar linea" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t-----------------------------------------------"
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenuP;
   cin >> opcionMenuP; // recibir opci�n del usuario

   return opcionMenuP;

}

void imprimirRegistroPuesto( fstream &leerDeArchivoP )
{
    ofstream archivoImprimirSalidaP( "ImprimirLinea.txt", ios::out );
    if ( !archivoImprimirSalidaP ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalidaP << left << setw( 10 ) << "Codigo" << setw( 16 )<< "Estatus" << setw( 14 ) << "Nombre" << endl;
    leerDeArchivoP.seekg( 0 );

    DatosLineas puestos;
    leerDeArchivoP.read( reinterpret_cast< char * >( &puestos ), sizeof( DatosLineas ) );

    while ( !leerDeArchivoP.eof() ) {
        if ( puestos.obtenerCodigoP() != 0 )
        mostrarLineaP( archivoImprimirSalidaP, puestos );
        leerDeArchivoP.read( reinterpret_cast< char * >( &puestos ), sizeof( DatosLineas ) );
    } //FIN DE WHILE
cout << "archivo creado exitosamente"<<endl;

  cout<<"\n";
 system("pause");
}

void mostrarLineaP( ostream &salida, const DatosLineas &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigoP()
          << setw( 16 ) << registro.obtenerEstatus().data()
          << setw( 14 ) << registro.obtenerNombre().data()<< endl;
}

void crearArchivoPuesto()
{
    ofstream creditoSalida( "Line.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosLineas puestoEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &puestoEnBlanco ), sizeof( DatosLineas ) );
        cout<<"\n";
 system("pause");
}

void nuevoRegistroPuesto( fstream &insertarEnArchivo )
{
    int codigoP = obtenernCodigoPuesto( "\nEscriba el Codigo de la linea " );
    insertarEnArchivo.seekg( ( codigoP - 1 ) * sizeof( DatosLineas ) );
    DatosLineas puestos;
    insertarEnArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( DatosLineas ) );

    if ( puestos.obtenerCodigoP() == 0 ) {
        char Estatus[ 15 ];
        char nombreP[ 15 ];
        cout<<"Escriba el Estatus de la linea: ";
        cin>> setw( 15 ) >> Estatus;
        cout<<"Escriba el Nombre de la linea: ";
        cin>> setw( 15 ) >> nombreP;

        puestos.establecerEstatus( Estatus );
        puestos.establecerNombrePuestos( nombreP );
        puestos.establecerCodigoP( codigoP );

        insertarEnArchivo.seekp( ( codigoP - 1 ) * sizeof( DatosLineas ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &puestos ), sizeof( DatosLineas ) );
        cout<<"\n linea agregada Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "la linea con codigo #" << codigoP << " ya contiene informacion.\n" << endl;
  cout<<"\n";
 system("pause");
}

int obtenernCodigoPuesto( const char * const indicador )
{
   int codigoP;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigoP;

    } while ( codigoP < 1 || codigoP > 100 );

   return codigoP;

}

void modificarRegistroPuesto( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Estatus\n  R - ";
    cin>>opcionAc;

    if (opcionAc== 1){
        int codigoP = obtenernCodigoPuesto( "\nEscriba el codigo de la linea que desea Modifcar" );

        actualizarArchivo.seekg(( codigoP - 1 ) * sizeof( DatosLineas ));

        DatosLineas puestos;
        actualizarArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( DatosLineas ) );

        //ACTUALIZAR EL REGISTRO
        if (puestos.obtenerCodigoP() != 0 ) {
            mostrarLineaP( cout, puestos );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombreP;
            cin >> nombreP;

            string nombreAnterior = puestos.obtenerNombre();
            puestos.establecerNombrePuestos( nombreP );
            mostrarLineaP( cout, puestos );

            actualizarArchivo.seekp(( codigoP - 1 ) * sizeof( DatosLineas ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &puestos ), sizeof( DatosLineas ) );
        }
    }else if(opcionAc == 2){
        int codigoP = obtenernCodigoPuesto( "Escriba el codigo de la linea que desea Modifcar" );

        actualizarArchivo.seekg(( codigoP - 1 ) * sizeof( DatosLineas ));

        DatosLineas puestos;
        actualizarArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( DatosLineas ) );

        if (puestos.obtenerCodigoP() != 0 ) {
                mostrarLineaP( cout, puestos );
                cout << "\nEscriba el nuevo Estatus: ";
                string Estatus;
                cin >> Estatus;

                string apellidoAnterior = puestos.obtenerEstatus();
                puestos.establecerEstatus( Estatus );
                mostrarLineaP( cout, puestos );

                actualizarArchivo.seekp(( codigoP - 1 ) * sizeof( DatosLineas ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &puestos ), sizeof( DatosLineas ) );
        }
    }
  cout<<"\n";
 system("pause");
} //FIN DE -ACTUALIZAR REGISTRO-

void eliminarRegistroPuesto( fstream &eliminarDeArchivo )
{
    int codigoP = obtenernCodigoPuesto( "\nEscriba el codigo de la linea a Eliminar" );
    eliminarDeArchivo.seekg( ( codigoP - 1 ) * sizeof( DatosLineas ) );
    DatosLineas puestos;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &puestos ), sizeof( DatosLineas ) );

    if ( puestos.obtenerCodigoP() != 0 ) {
        DatosLineas puestoEnBlanco;
        eliminarDeArchivo.seekp( ( codigoP - 1 ) * sizeof( DatosLineas ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &puestoEnBlanco ), sizeof( DatosLineas ) );

      cout << " codigo #" << codigoP << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "El codigo #" << codigoP << " esta vacia.\n";

cout<<"\n";
 system("pause");
} //FIN -ELIMINARREGISTRO-

void consultarRegistroPuesto( fstream &leerDeArchivoP )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << "Estatus" << setw( 14 ) << " Nombre" << endl;
    leerDeArchivoP.seekg( 0 );
    DatosLineas puestos;
    leerDeArchivoP.read( reinterpret_cast< char * >( &puestos ), sizeof( DatosLineas ) );
    while ( !leerDeArchivoP.eof() ) {
        if ( puestos.obtenerCodigoP() != 0 )
            mostrarLineaPantallaP(puestos);
            leerDeArchivoP.read( reinterpret_cast< char * >( &puestos ), sizeof( DatosLineas ) );

   } //FIN WHILE
   cout<<"\n";
 system("pause");
} //FIN CONSULTAR REGISTRO

void mostrarLineaPantallaP( const DatosLineas &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigoP()
          << setw( 16 ) << registro.obtenerEstatus().data()
          << setw( 14 ) << registro.obtenerNombre().data()<< endl;

} //FIN -MOSTRARLINEAENOANTALLA-

Lineas::~Lineas()
{
    //dtor
}
