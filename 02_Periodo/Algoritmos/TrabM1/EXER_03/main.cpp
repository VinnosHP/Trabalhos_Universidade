#include <iostream>

using namespace std;

int main()
{
    int dia,mes ;
    cout << "Informe o dia do seu nacimento: ";
    cin >> dia;
    cout << "Informe o mes do seu nacimento: ";
    cin >> mes;
    switch (mes)
    {
    case 1:
        if (dia <= 20)
        {
            cout <<  ("signo: capricórnio.");
        }
        else
        {
            cout <<  ("signo: aguario.");
        }
        break;
    case 2:
        if (dia <=19)
        {
            cout << ("signo: aguario.");
        }
        else
        {
            cout << ("signo: peixes");
        }
        break;
    case 3:
        if (dia <=20)
        {
            cout << ("signo: peixes.");
        }
        else
        {
            cout << ("signo: aries.");
        }
        break;
    case 4:
        if (dia <=20)
        {
            cout << ("signo: aries.");
        }
        else
        {
            cout << ("signo: touro.");
        }
        break;
    case 5:
        if (dia <=20)
        {
            cout << ("signo: touro.");
        }
        else
        {
            cout << ("signo: gemeos.");
        }
        break;
    case 6:
        if (dia <=21)
        {
            cout << ("signo: gemeos.");
        }
        else
        {
            cout << ("signo: cancer.");
        }
        break;
    case 7:
        if (dia <=22)
        {
            cout << ("signo: cancer.");
        }
        else
        {
            cout << ("signo: leao.");
        }
        break;
    case 8:
        if (dia <=22)
        {
            cout << ("signo: leao.");
        }
        else
        {
            cout << ("signo: virgem.");
        }
        break;
    case 9:
        if (dia <=22)
        {
            cout << ("signo: virgem.");
        }
        else
        {
            cout << ("signo: libra");
        }
        break;
    case 10:
        if (dia <=21)
        {
            cout << ("signo: libra.");
        }
        else
        {
            cout << ("signo: escorpiao.");
        }
        break;
    case 11:
        if (dia <=21)
        {
            cout << ("signo: escorpiao.");
        }
        else
        {
            cout << ("signo: sargitario.");
        }
        break;
    case 12:
        if (dia <=21)
        {
            cout << ("signo: sargitario.");
        }
        else
        {
            cout << ("signo: capricornio.");
        }
        break;
    }
    return 0;
}
