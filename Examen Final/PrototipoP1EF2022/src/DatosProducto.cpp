#include "DatosProducto.h"
#include "Producto.h"
#include <cstring>
#include <iostream>

using std::string;

DatosProducto::DatosProducto(int valorCodigo, string valorNombre, int valorCelular)
{
    establecerCodigo( valorCodigo );
    establecerNombre( valorNombre );
    establecerCelular( valorCelular );
}
int DatosProducto::obtenerCodigo() const
{
   return codigo;
}
void DatosProducto::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
string DatosProducto::obtenerNombre() const
{
   return nombre;
}
void DatosProducto::establecerNombre( string nombreEmpre )
{
    const char *valorNombre = nombreEmpre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 20 ? longitud : 19 );
    strncpy( nombre, valorNombre, longitud );

    nombreEmpre[ longitud ] = '\0';

}
int DatosProducto::obtenerCelular() const
{
   return celular;
}
void DatosProducto::establecerCelular( int valorCelular )
{
   celular = valorCelular;
}

DatosProducto::~DatosProducto()
{
    //dtor
}
