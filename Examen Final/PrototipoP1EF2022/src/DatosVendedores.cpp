#include "DatosVendedores.h"
#include "Vendedores.h"
#include <cstring>
#include <iostream>

using std::string;

DatosVendedores::DatosVendedores(int valorCodigo, string valorApellido, string valorNombre, string valorCorreo, int valorSueldo)
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );
    establecerCorreo( valorCorreo );
    establecerSueldo( valorSueldo );

}
int DatosVendedores::obtenerCodigo() const
{
   return codigo;
}
void DatosVendedores::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string DatosVendedores::obtenerApellido() const
{
   return apellido;

}
void DatosVendedores::establecerApellido( string apellidoString )
{
    const char *valorApellido = apellidoString.data();
    int longitud = strlen( valorApellido );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( apellido, valorApellido, longitud );

    apellido[ longitud ] = '\0';

}
string DatosVendedores::obtenerNombre() const
{
   return nombre;
}
void DatosVendedores::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';

}
int DatosVendedores::obtenerSueldo() const
{
   return sueldo;
}
void DatosVendedores::establecerSueldo( int valorSueldo )
{
   sueldo = valorSueldo;
}
string DatosVendedores::obtenerCorreo() const
{
   return correo;
}
void DatosVendedores::establecerCorreo( string correostring )
{
    const char *valorCorreo = correostring.data();
    int longitud = strlen( valorCorreo );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( correo, valorCorreo, longitud );

    correostring[ longitud ] = '\0';
}

DatosVendedores::~DatosVendedores()
{
    //dtor
}
