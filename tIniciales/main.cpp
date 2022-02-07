#include <iostream>

using namespace std;

int main()
{
    int progra = 0;
    int admin = 0;
    int fis = 0;
    int cal = 0;
    int der = 0;

    cout <<"Ingrese la nota de programación1: "<<endl;
    cin >> progra;
    cout <<"Ingrese la nota de Proceso administrativo:"<<endl;
    cin >> admin;
    cout <<"Ingrese la nota de Física 1: "<<endl;
    cin >> fis;
    cout <<"Ingrese la nota de Cálculo 1: "<<endl;
    cin >> cal;
    cout <<"Ingrese la nota de Derecho Informático:"<<endl;
    cin >> der;

    cout <<"Programación 1:"<<endl;
    switch(progra)
    {
    case 100:
        cout <<"Felicidades, usted obtuvo una nota perfecta :D"<<endl;
        break;
    default:
        if(progra >= 61){
            cout <<"Bien hecho, usted aprobo el curso"<<endl;
        }else{cout <<"Lo sentimos, usted reprobo el curso"<<endl;
        }
    }
    cout <<"Proceso Administrativo:"<<endl;
    switch(admin)
    {
    case 100:
        cout <<"Felicidades, usted obtuvo una nota perfecta :D"<<endl;
        break;
    default:
        if(admin >= 61){
            cout <<"Bien hecho, usted aprobo el curso"<<endl;
        }else{cout <<"Lo sentimos, usted reprobo el curso"<<endl;
        }
    }
    cout <<"Física 1:"<<endl;
    switch(fis)
    {
    case 100:
        cout <<"Felicidades, usted obtuvo una nota perfecta :D"<<endl;
        break;
    default:
        if(fis >= 61){
            cout <<"Bien hecho, usted aprobo el curso"<<endl;
        }else{cout <<"Lo sentimos, usted reprobo el curso"<<endl;
        }
    }
    cout <<"Cálculo 1:"<<endl;
    switch(cal)
    {
    case 100:
        cout <<"Felicidades, usted obtuvo una nota perfecta :D"<<endl;
        break;
    default:
        if(cal >= 61){
            cout <<"Bien hecho, usted aprobo el curso"<<endl;
        }else{cout <<"Lo sentimos, usted reprobo el curso"<<endl;
        }
    }
    cout <<"Derecho informático:"<<endl;
    switch(der)
    {
    case 100:
        cout <<"Felicidades, usted obtuvo una nota perfecta :D"<<endl;
        break;
    default:
        if(der >= 61){
            cout <<"Bien hecho, usted aprobo el curso"<<endl;
        }else{cout <<"Lo sentimos, usted reprobo el curso"<<endl;
        }
    }
    return 0;

}
