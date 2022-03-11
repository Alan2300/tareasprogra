#include <iostream>
using namespace std;

class persona
{
public:
    string mNombre;
    int mEdad,mIdentificacion, mTelefono;
    persona(string nombre, int identificacion, int telefono, int edad)
    {
        mNombre = nombre;
        mIdentificacion = identificacion;
        mTelefono = telefono;
        mEdad = edad;
    }
    string registrar()
    {
        cout <<"Usted entro al metodo Registrar"<<endl;
    }
    int getEdad()
    {
        return mEdad;
    }
     string modificar()
    {
        cout <<"Usted entro al metodo Modificar"<<endl;
    }
    string eliminar()
    {
        cout <<"Usted entro al metodo Eliminar"<<endl;
    }
    string consultar()
    {
        cout <<"Usted entro al metodo consultar"<<endl;
    }
};

class empleado : public persona
{
public:
    empleado(string nombre, int identificacion, int telefono, int edad):persona(nombre, identificacion, telefono, edad)
    {
        mNombre = nombre;
        mIdentificacion = identificacion;
        mTelefono = telefono;
        mEdad = edad;
    }
};

int main()
{
    persona primerPersona("Jose", 3654512354, 65445875, 25);
    cout << primerPersona.consultar() << endl;
    cout << primerPersona.eliminar() << endl;
    cout << primerPersona.modificar() << endl;
    cout << primerPersona.registrar() << endl;
    cout << primerPersona.getEdad() << endl;
    empleado primerEmpleado("Jose", 3654512354, 65445875, 25);
    cout << primerEmpleado.consultar() << endl;
    cout << primerEmpleado.eliminar() << endl;
    cout << primerEmpleado.modificar() << endl;
    cout << primerEmpleado.registrar() << endl;
    cout << primerEmpleado.getEdad() << endl;
    return 0;
}
