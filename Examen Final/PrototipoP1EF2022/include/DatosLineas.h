#ifndef DATOSLINEAS_H
#define DATOSLINEAS_H
#include <iostream>

using std::string;

class DatosLineas
{
    public:
        virtual ~DatosLineas();

        DatosLineas( int = 0, string = "", string = "");

        void establecerCodigoP( int );
        int obtenerCodigoP() const;

        void establecerEstatus( string );
        string obtenerEstatus() const;

        void establecerNombrePuestos( string );
        string obtenerNombre() const;

    protected:

    private:
        int codigoP;
        char Estatus[ 15 ];
        char nombreP[ 10 ];
};

#endif // DATOSLINEAS_H
