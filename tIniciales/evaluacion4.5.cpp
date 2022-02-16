#include <iostream>

using namespace std;

int main()
{
    unsigned int suma = 0;
    unsigned int x = 1;

    while (x<=10)
    {
        suma += x;
        ++x;
    }
    cout << "suma:" << suma << endl;
    return 0;

}
