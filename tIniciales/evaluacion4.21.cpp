#include <iostream>

using namespace std;

int main()
{
    unsigned int cuenta = 1;

    while(cuenta<=10)
    {
        cout <<(cuenta % 2 ? "****" : "++++++++")<<endl;
        ++cuenta;
    }

     return 0;
}
