#include <iostream>

using namespace std;

int main()
{
    int resultado, x;
    cout << "Informe o X:";
    cin >> x;
    if (x<= -2)
    {
        resultado = 1 + x;
    }
    if ((x>-2)and(x<2))
    {
        resultado = 2 - x;
    }
    if (x>=2)
    {
        resultado = 2 * x - 1;
    }
    cout << "X = " << resultado;
    return 0;
}
