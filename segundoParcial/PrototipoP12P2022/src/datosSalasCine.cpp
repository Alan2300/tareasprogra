#include "datosSalasCine.h"
#include "salasCine.h"
#include <cstring>
#include <iostream>

using std::string;


datosSalasCine::datosSalasCine(int valorCodigo, string valorApellido, string valorNombre )
{
    establecerCodigo( valorCodigo );
    establecerApellido( valorApellido );
    establecerNombre( valorNombre );

}
int datosSalasCine::obtenerCodigo() const
{
   return codigo;
}
void datosSalasCine::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string datosSalasCine::obtenerApellido() const
{
   return apellido;
}
void datosSalasCine::establecerApellido(string apellidoString)
{
    const char *valorApellido = apellidoString.data();
    int longitud =strlen(valorApellido);
    longitud = ( longitud < 15 ? longitud : 14);
    strncpy(apellido, valorApellido, longitud );

    apellido [ longitud ] = '\0';
}
string datosSalasCine::obtenerNombre() const
{
    return nombre;
}
void datosSalasCine::establecerNombre ( string primerNombre)
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( nombre, valorNombre, longitud );

}
datosSalasCine::~datosSalasCine()
{
    //dtor
}
