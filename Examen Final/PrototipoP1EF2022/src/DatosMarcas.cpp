#include "DatosMarcas.h"
#include "Marcas.h"
#include <cstring>
#include <iostream>

using std::string;


DatosMarcas::DatosMarcas(int valorCodigo, string valorApellido, string valorNombre )
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );

}
int DatosMarcas::obtenerCodigo() const
{
   return codigo;
}
void DatosMarcas::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string DatosMarcas::obtenerApellido() const
{
   return apellido;
}
void DatosMarcas::establecerApellido(string apellidoString)
{
    const char *valorApellido = apellidoString.data();
    int longitud =strlen(valorApellido);
    longitud = ( longitud < 15 ? longitud : 14);
    strncpy(apellido, valorApellido, longitud );

    apellido [ longitud ] = '\0';
}
string DatosMarcas::obtenerNombre() const
{
    return nombre;
}
void DatosMarcas::establecerNombre ( string primerNombre)
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 20 ? longitud : 19 );
    strncpy( nombre, valorNombre, longitud );

}

DatosMarcas::~DatosMarcas()
{
    //dtor
}
