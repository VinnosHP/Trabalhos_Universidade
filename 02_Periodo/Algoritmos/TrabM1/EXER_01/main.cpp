#include <iostream>

using namespace std;

int main()
{
    int idade, tempoS;
    char sexo ;
    cout << "Informe a idade da pessoa:";
    cin >> idade;
    cout << "Informe o sexo(M/F) da pessoa:";
    cin >> sexo;
    cout << "Informe o tempo de servico da pessoa:";
    cin >> tempoS;
    switch (sexo)
    {
    case 'M':
        if ((idade>=65)and(tempoS>=30))
        {
            cout << "Parabens, voce pode se aposentar." << endl;
        }
        else
        {
            cout << "Nao pode se aposentar ainda." << endl;
        }
        break;
    case 'F':
        if ((idade>=60)and(tempoS>=25))
        {
            cout << "Parabens, voce pode se aposentar." << endl;
        }
        else
        {
            cout << "Nao pode se aposentar ainda." << endl;
        }
        break;
    }
    return 0;
}
