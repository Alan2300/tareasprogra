#include "DatosClientes.h"
#include "clientes.h"
#include <cstring>
#include <iostream>

using std::string;

DatosClientes::DatosClientes(int valorCodigo, string valorApellido, string valorNombre, string valorCorreo, int valorSueldo)
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );
    establecerCorreo( valorCorreo );
    establecerSueldo( valorSueldo );

}
int DatosClientes::obtenerCodigo() const
{
   return codigo;
}
void DatosClientes::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string DatosClientes::obtenerApellido() const
{
   return apellido;

}
void DatosClientes::establecerApellido( string apellidoString )
{
    const char *valorApellido = apellidoString.data();
    int longitud = strlen( valorApellido );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( apellido, valorApellido, longitud );

    apellido[ longitud ] = '\0';

}
string DatosClientes::obtenerNombre() const
{
   return nombre;
}
void DatosClientes::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';

}
int DatosClientes::obtenerSueldo() const
{
   return sueldo;
}
void DatosClientes::establecerSueldo( int valorSueldo )
{
   sueldo = valorSueldo;
}
string DatosClientes::obtenerCorreo() const
{
   return correo;
}
void DatosClientes::establecerCorreo( string correostring )
{
    const char *valorCorreo = correostring.data();
    int longitud = strlen( valorCorreo );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( correo, valorCorreo, longitud );

    correostring[ longitud ] = '\0';
}

DatosClientes::~DatosClientes()
{
    //dtor
}
