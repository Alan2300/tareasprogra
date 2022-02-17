#include <iostream>

using namespace std;

int main()
{
    int lA=0,lB=0,lC=0;
    cout<<"ingrese el primer lado del triángulo: ";
    cin>>lA;
    cout<<endl<<"ingrese el primer lado del triángulo: ";
    cin>>lB;
    cout<<endl<<"ingrese el primer lado del triángulo: ";
    cin>>lC;
    if((lA>lB) && (lA>lC))
    {
        cout<<endl<<"Estos pueden ser los lados de un triángulo recto";
    }
    else
    {
        if((lB>lA) && (lB>lC))
        {
            cout<<endl<<"Estos pueden ser los lados de un triángulo recto";
        }
        else
        {
             if(lC>lA && lC>lB)
        {
            cout<<endl<<"Estos pueden ser los lados de un triángulo recto";
        }
        else
        {
            cout<<endl<<"Estos no pueden ser los lados de un triángulo recto";
        }
        }
    }


     return 0;
}
