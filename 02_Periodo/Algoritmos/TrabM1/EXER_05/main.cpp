#include <iostream>

using namespace std;

int main()
{
    int cod1,cod2,cod3;
    float preco;
    preco = 0;
    cout<<"==============================="<<endl;
    cout<<"Informe o codigo do alimento:";
    cin>>cod1;
    cout<<"-------------------------------"<<endl;
    if((cod1>0)and(cod1<5))
    {
        switch (cod1)
        {
        case 1:
            cout<<"Hamburguer: R$14,50"<<endl;
            preco = preco + 14.5;
            break;
        case 2:
            cout<<"Chessburguer: R$15,50"<<endl;
            preco = preco + 15.5;
            break;
        case 3:
            cout<<"Cachorro Quente: R$10,00"<<endl;
            preco = preco + 10;
            break;
        case 4:
            cout<<"Sanduiche Natural: R$13,50"<<endl;
            preco = preco + 13.5;
            break;
        }
    }
    else
    {
        cout<< "Erro, codigo de alimento invalido!";
    }
    cout<< "==============================="<<endl;
    cout<< "Informe o codigo da bebida:";
    cin >> cod2;
    cout<< "-------------------------------"<<endl;
    if((cod2>4)and(cod2<7))
    {
        switch (cod2)
        {
        case 5:
            cout<< "Refrigerante: R$5,00"<<endl;
            preco = preco + 5;
            break;
        case 6:
            cout<< "Suco de Laranja: R$6,00"<<endl;
            preco = preco + 6;
            break;
        }
    }
    else
    {
        cout<< "Erro, codigo de bebida invalido!";
    }
    cout<< "==============================="<<endl;
    cout<< "Informe o codigo da sobremesa:";
    cin >> cod3;
    cout<< "-------------------------------"<<endl;
    if((cod3>6)and(cod3<10))
    {
        switch (cod3)
        {
        case 7:
            cout<< "Milk Shake: R$10,5"<<endl;
            preco = preco + 10.5;
            break;
        case 8:
            cout<< "Sundae: R$13,00"<<endl;
            preco = preco + 13;
            break;
        case 9:
            cout<< "Casquinha: R$10,00"<<endl;
            preco = preco + 10;
            break;
        }
    }
    else
    {
        cout<< "Erro, codigo de sobremesa invalido!";
    }
    cout<< "==============================="<<endl;
    cout<< "Total a Pagar: R$"<< preco <<endl;
    cout<< "==============================="<<endl;
    return 0;
}
