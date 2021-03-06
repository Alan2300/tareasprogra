#ifndef DATOSCLIENTES_H
#define DATOSCLIENTES_H
#include <iostream>
using std::string;

class DatosClientes
{
    public:
        virtual ~DatosClientes();
        DatosClientes( int = 0, string = "", string = "", string = "", int=0);

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerApellido( string );
        string obtenerApellido() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerSueldo( int );
        int obtenerSueldo() const;

        void establecerCorreo( string );
        string obtenerCorreo() const;

    protected:

    private:
        int codigo;
        char apellido[ 15 ];
        char nombre[ 10 ];
        char correo[ 15 ];
        int sueldo;
};

#endif // DATOSCLIENTES_H
