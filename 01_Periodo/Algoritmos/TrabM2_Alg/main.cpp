#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//tema: restaurante de comida a kilo, simulacao de caixa

typedef struct
{
    float dinheiroDisp, dinheiroInicial, precoKg, pesoPrato, faturamento;
}Caixa;

void menu()
{
    cout << "------- MENU -------" << endl;
    cout << " 1 - Abrir o caixa" << endl;
    cout << " 2 - Novo cliente" << endl;
    cout << " 3 - Fechar o caixa" << endl;
    cout << "--------------------" << endl;
    cout << " Opcao: ";
}

void aberturaCaixa(Caixa &c)
{
    float aux;
    do{
        cout << "Quantia que sera inserida no caixa: ";
        cin >> aux;
        if(aux < 100.00){
            cout << "Quantia abaixo do permitido!" << endl;
            system("pause");
            system("cls");
        }
    }while(aux < 100);
    c.dinheiroDisp = aux;
    c.dinheiroInicial = aux;
    do{
        cout << "Preco do quilo: ";
        cin >> aux;
        if(aux < 1.00){
            cout << "Valor abaixo do permitido!" << endl;
            system("pause");
            system("cls");
        }
    }while(aux < 1.00);
    c.precoKg = aux;
    do{
        cout << "Peso do prato em kg: ";
        cin >> aux;
        if(aux < 0.00){
            cout << "Peso invalido!" << endl;
            system("pause");
            system("cls");
        }
    }while(aux < 0.00);
    c.pesoPrato = aux;
    cout << "Caixa Aberto com sucesso!" << endl << endl;
    system("pause");
    system("cls");
}

void mostraCaixa(Caixa c)
{
    cout<<"---------- CAIXA ----------"<<endl;
    cout<<" Dinheiro no caixa: R$"<<c.dinheiroDisp<<endl;
    cout<<" Preco do Kg: R$"<<c.precoKg<<endl;
    cout<<" Peso do prato: "<<c.pesoPrato<<"kg"<<endl;
    cout<<"---------------------------"<<endl<<endl;
    system("pause");
    system("cls");
}

void novoCliente(Caixa &c, int &cont)
{
    float precoP, pesoR, totalP, subT = 0.00, dinheiro, troco;
    char resp;
    do{
        system("cls");
        do{
            system("cls");
            cout << "Peso do prato em Kg: ";
            cin >> precoP;
            system("pause");
        }while(precoP <= c.pesoPrato);

        pesoR = precoP - c.pesoPrato;
        totalP = pesoR * c.precoKg;
        subT += totalP;

        cout << "Peso real: " << pesoR << "kg" << endl;
        cout << "Preco do prato: R$" << totalP << endl;
        cout << "Subtotal: R$" << subT << endl;

        cin.ignore();
        cout << "Mais um prato?(S/N)" << endl;
        resp = toupper(cin.get());
    }while(resp != 'N');

    cout << "Total a pagar: R$" << subT << endl;

    do{
        cout << "Troco para quanto?" << endl;
        cin >> dinheiro;
        system("pause");
        system("cls");
    }while(dinheiro < subT);
    troco = dinheiro - subT;
    cout << "Troco: R$" << troco << endl;
    c.dinheiroDisp = subT + c.dinheiroDisp;
    c.faturamento = c.dinheiroDisp - c.dinheiroInicial;
}

void caixaAtual(Caixa c, int cont)
{
    cout << "Valor atual do caixa: R$" << c.dinheiroDisp << endl;
    cout << "Pratos Vendidos: " << cont << endl;
    cout << "Faturameto do dia: R$" << c.faturamento << endl << endl;
}

int main()
{
    Caixa registradora;
    int op = 0, cont = 0;

    do{
        do{
            menu();
            cin >> op;
            system("cls");
        }while(op < 1 && op > 3);

        if(op != 1)
            break;

        aberturaCaixa(registradora);
        //mostraCaixa(registradora);
        do{
            system("cls");
            do{
                menu();
                cin >> op;
                system("cls");
            }while(op < 1 && op > 3);
            if(op==2){
                novoCliente(registradora, cont);
                system("pause");
            }else{
                caixaAtual(registradora, cont);
                system("pause");
            }
        }while(op!=3);
        system("cls");
    }while(op!=3);
    cout << "Saindo..." <<endl;
    return 0;
}
