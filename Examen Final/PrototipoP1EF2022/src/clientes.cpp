#include "clientes.h"
#include "DatosClientes.h"
#include <iostream>
#include <ctime>
#include <vector>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>
using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>
using std::setw;
using std::setprecision;
#include <cstdlib>

int opcionEmp();
void imprimirRegistroEmp( fstream& );
void crearArchivoCreditoEmp();
void mostrarLineaEmp( ostream&, const DatosClientes & );
void nuevoRegistroEmp( fstream&);
int obtenernCodigoEmp( const char * const );
void modificarRegistroEmp( fstream& );
void eliminarRegistroEmp( fstream& );
void consultarRegistroEmp( fstream& );
void mostrarLineaPantallaEmp( const DatosClientes &);
int obtenernCodigoImp( const char * );
int obtenernCodigoCon( const char * );

using namespace std;

clientes::clientes()
{
    fstream creditoEntradaSalida( "client.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoEmp();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }

    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionEmp() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroEmp( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroEmp( creditoEntradaSalida);
            break;
            case modificar:
                modificarRegistroEmp( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroEmp( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroEmp( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE
}
int opcionEmp(){
    system("cls");

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

    //Formato=hoy miercoles, 27 de mayo del 2015
    cout<< "\n";
    cout << "Hoy " << dia_semana[time->tm_wday] << ", ";
    cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
    cout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;


    cout<<"\n\t\t\t-----------------------------------------------";
    cout<<"\n\t\t\t\t   ----------------------------------------------"<<endl;
	cout<<"\t\t\t\t      |   Alan Abimael Galicia Ruano 9959213632   |"<<endl;
	cout<<"\t\t\t\t     ----------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar Cliente" << endl
        << "\t\t\t 3. Modificar Cliente" << endl
        << "\t\t\t 4. Eliminar Cliente" << endl
        << "\t\t\t 5. Mostrar Lista de Cliente" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t-----------------------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
    int opcionMenu ;

    cin >> opcionMenu;

   return opcionMenu;
}
void imprimirRegistroEmp( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "imprimirClientes.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 14 ) << "Codigo" << setw( 16 )<< "Nombre" << setw( 14 ) << "Direcci�n" << setw( 20 ) << "Nit"
       << setw( 16 ) << "Telefono" << endl;
    leerDeArchivo.seekg( 0 );

    DatosClientes empleados;
    leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );

    while ( !leerDeArchivo.eof() ) {
        if ( empleados.obtenerCodigo() != 0 )
        mostrarLineaEmp( archivoImprimirSalida, empleados );
        leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );
    } //FIN DE WHILE
    cout<<"\n";
    system("pause");
} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaEmp( ostream &salida, const DatosClientes &registro )
{
   salida << left << setw( 18 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 15 ) << registro.obtenerCorreo().data()
          << setw( 15 ) << registro.obtenerSueldo()<< endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoEmp()
{
    ofstream creditoSalida( "client.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosClientes empleadoEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &empleadoEnBlanco ), sizeof( DatosClientes ) );
    cout<<"\n";
    system("pause");
}
void nuevoRegistroEmp( fstream &insertarEnArchivo)
{
    int codigo = obtenernCodigoEmp( "\nEscriba el Codigo del Cliente " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosClientes ) );
    DatosClientes empleados;
    insertarEnArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );

    if ( empleados.obtenerCodigo() == 0 ) {
        char apellido[ 15 ];
        char nombre[ 10 ];
        char correo[ 15 ];
        int sueldo;

        cout<<"Escriba el Nombre del Cliente: ";
        cin>> setw( 15 ) >> apellido;
        cout<<"Escriba la direcci�n del Cliente: ";
        cin>> setw( 10 ) >> nombre;
        cout<<"Escriba el NIT del Cliente: ";
        cin>> setw( 15 ) >> correo;
        cout<<"Escriba el Telefono del Cliente: ";
        cin>> sueldo;

        empleados.establecerApellido( apellido );
        empleados.establecerNombre( nombre );
        empleados.establecerCorreo( correo );
        empleados.establecerSueldo( sueldo );

        empleados.establecerCodigo( codigo );
        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosClientes ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &empleados ), sizeof( DatosClientes ) );
        cout<<"\n Cliente agregado Exitosamente..."<<endl;
    } //FIN IF
    else
        cerr << "El Cliente con codigo #" << codigo << " ya contiene informacion.\n" << endl;
    cout<<"\n";
    system("pause");
} //FIN REGISTRO
int obtenernCodigoEmp( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroEmp( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. telefono\n 2. direccion\n 3. nombre \n 4. nit\n R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );

        if (empleados.obtenerCodigo() != 0 ) {
            mostrarLineaEmp( cout, empleados );
            cout << "Escriba el nuevo telefono: ";
            int cambiosu;
            cin >> cambiosu;
            double sueldoAnterior = empleados.obtenerSueldo();
            empleados.establecerSueldo( cambiosu );
            mostrarLineaEmp( cout, empleados );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));

            actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosClientes ) );
        }

    }else if (opcionAc== 2){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );

        //ACTUALIZAR EL REGISTRO
        if (empleados.obtenerCodigo() != 0 ) {
            mostrarLineaEmp( cout, empleados );
            cout << "\nEscriba la nueva direccion: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = empleados.obtenerNombre();
            empleados.establecerNombre( nombre );
            mostrarLineaEmp( cout, empleados );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosClientes ) );
        }
    }else if(opcionAc == 3){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );

        if (empleados.obtenerCodigo() != 0 ) {
                mostrarLineaEmp( cout, empleados );
                cout << "\nEscriba el nuevo nombre: ";
                string apellido;
                cin >> apellido;

                string apellidoAnterior = empleados.obtenerApellido();
                empleados.establecerApellido( apellido );
                mostrarLineaEmp( cout, empleados );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosClientes ) );
        }
    }else if(opcionAc == 4){
        int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes empleados;
        actualizarArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );

        if (empleados.obtenerCodigo() != 0 ) {
                mostrarLineaEmp( cout, empleados );
                cout << "\nEscriba el nuevo NIT: ";
                string correo;
                cin >> correo;

                string correoAnterior = empleados.obtenerCorreo();
                empleados.establecerCorreo( correo );
                mostrarLineaEmp( cout, empleados );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &empleados ), sizeof( DatosClientes ) );
        }
    }
cout<<"\n";
 system("pause");
} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroEmp( fstream &eliminarDeArchivo )
{
    int codigo = obtenernCodigoEmp( "\nEscriba el codigo del Cliente a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosClientes ) );
    DatosClientes empleados;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );

    if ( empleados.obtenerCodigo() != 0 ) {
        DatosClientes clienteEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosClientes ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &clienteEnBlanco ), sizeof( DatosClientes ) );

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";
cout<<"\n";
 system("pause");
} //FIN -ELIMINARREGISTRO-
void consultarRegistroEmp( fstream &leerDeArchivo )

{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 14 ) << " Nombre" << setw( 12 ) << " Direcci�n" << setw( 16 ) << " NIT" << setw( 15 )
    << " telefono" << endl;
    leerDeArchivo.seekg( 0 );
    DatosClientes empleados;
    leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );
    while ( !leerDeArchivo.eof() ) {
        if ( empleados.obtenerCodigo() != 0 )
            mostrarLineaPantallaEmp(empleados);
            leerDeArchivo.read( reinterpret_cast< char * >( &empleados ), sizeof( DatosClientes ) );

   } //FIN WHILE
    cout<<"\n";
    system("pause");
} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaEmp( const DatosClientes &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 14 ) << registro.obtenerApellido().data()
          << setw( 12 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerCorreo().data()
          << setw( 15 ) << registro.obtenerSueldo()<< endl;

} //FIN -MOSTRARLINEAENOANTALLA-

clientes::~clientes()
{
    //dtor
}
