#ifndef DATOSMARCAS_H
#define DATOSMARCAS_H
#include <iostream>

using std::string;

class DatosMarcas
{
    public:
        virtual ~DatosMarcas();

        DatosMarcas( int = 0, string = "", string = "" );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerApellido( string );
        string obtenerApellido() const;

        void establecerNombre( string );
        string obtenerNombre() const;

    protected:

    private:
        int codigo;
        char apellido[ 15 ];
        char nombre[ 20 ];

};
#endif // DATOSMARCAS_H
