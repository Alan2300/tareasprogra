#include <iostream>

using namespace std;

int main()
{
    int lA=0,lB=0,lC=0;
    cout<<"ingrese el primer lado del tri�ngulo: ";
    cin>>lA;
    cout<<endl<<"ingrese el primer lado del tri�ngulo: ";
    cin>>lB;
    cout<<endl<<"ingrese el primer lado del tri�ngulo: ";
    cin>>lC;
    if((lA>lB) && (lA>lC))
    {
        cout<<endl<<"Estos pueden ser los lados de un tri�ngulo recto";
    }
    else
    {
        if((lB>lA) && (lB>lC))
        {
            cout<<endl<<"Estos pueden ser los lados de un tri�ngulo recto";
        }
        else
        {
             if(lC>lA && lC>lB)
        {
            cout<<endl<<"Estos pueden ser los lados de un tri�ngulo recto";
        }
        else
        {
            cout<<endl<<"Estos no pueden ser los lados de un tri�ngulo recto";
        }
        }
    }


     return 0;
}
