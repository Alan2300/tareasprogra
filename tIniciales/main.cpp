#include <iostream>

using namespace std;

int main()
{
    int progra = 0;
    int admin = 0;
    int fis = 0;
    int cal = 0;
    int der = 0;

    cout <<"Ingrese la nota de programaci�n1: "<<endl;
    cin >> progra;
    cout <<"Ingrese la nota de Proceso administrativo:"<<endl;
    cin >> admin;
    cout <<"Ingrese la nota de F�sica 1: "<<endl;
    cin >> fis;
    cout <<"Ingrese la nota de C�lculo 1: "<<endl;
    cin >> cal;
    cout <<"Ingrese la nota de Derecho Inform�tico:"<<endl;
    cin >> der;

    cout <<"Programaci�n 1:"<<endl;
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
    cout <<"F�sica 1:"<<endl;
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
    cout <<"C�lculo 1:"<<endl;
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
    cout <<"Derecho inform�tico:"<<endl;
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
