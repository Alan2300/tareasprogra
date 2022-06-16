#include "DatosLineas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

DatosLineas::DatosLineas(int valorCodigoP, string valorEstatus, string valorNombrePuestos)
{
    establecerCodigoP( valorCodigoP );
    establecerEstatus( valorEstatus );
    establecerNombrePuestos( valorNombrePuestos );
}
int DatosLineas::obtenerCodigoP() const
{
   return codigoP;
}
void DatosLineas::establecerCodigoP( int valorCodigoP )
{
   codigoP = valorCodigoP;
}
string DatosLineas::obtenerEstatus() const
{
   return Estatus;

}
void DatosLineas::establecerEstatus( string EstatusString )
{
    const char *valorEstatus = EstatusString.data();
    int longitudP = strlen( valorEstatus );
    longitudP = ( longitudP < 15 ? longitudP : 14 );
    strncpy( Estatus, valorEstatus, longitudP );

    Estatus[ longitudP ] = '\0';

}
string DatosLineas::obtenerNombre() const
{
   return nombreP;
}
void DatosLineas::establecerNombrePuestos( string nombrePuestos )
{
    const char *valorNombrePuestos = nombrePuestos.data();
    int longitudP = strlen( valorNombrePuestos );
    longitudP = ( longitudP < 10 ? longitudP : 9 );
    strncpy( nombreP, valorNombrePuestos, longitudP );

    nombrePuestos[ longitudP ] = '\0';

}

DatosLineas::~DatosLineas()
{
    //dtor
}
