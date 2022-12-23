#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
    float valorC, valorQ, tara, pesoR, valorA, pratoC, totalP, sub, dinC, troco, fatur;
    char resp;
    int cont=0, opcao=0;

    cout<<setprecision(2)<<fixed;
    do{
        cout<<"1 - Abrir o caixa"<<endl;
        cout<<"2 - Novo cliente"<<endl;
        cout<<"3 - Fechar o caixa"<<endl;
        cin>>opcao;
        system ("CLS");
        if(opcao!=1){
            cout<<"Saindo do sistema sem abertura do caixa."<<endl;
            break;
        }

        do{
            cout<<"Qual o valor que sera inserido?"<<endl;
            cin>>valorC;
            valorA = valorC;

            if(valorC<100){
                cout<<"ERRO!"<<endl;
            }
            system ("CLS");
        }while(valorC<100);

        do{
            cout<<"Qual o preco do quilo?"<<endl;
            cin>>valorQ;

            if(valorQ<1.00){
                cout<<"ERRO!"<<endl;
            }
            system ("CLS");
        }while(valorQ<1.00);

        do{
            cout<<"Qual o peso do prato em kg?"<<endl;
            cin>>tara;
            if(tara<0){
                cout<<"ERRO!"<<endl;
            }
            system ("CLS");
        }while(tara<0);

        do{
            cout<<"1 - Abrir o caixa"<<endl;
            cout<<"2 - Novo cliente"<<endl;
            cout<<"3 - Fechar o caixa"<<endl;
            cin>>opcao;
            system ("CLS");

            if(opcao<=1 and opcao>3){
                cout<<"ERRO!";
                system ("CLS");
            }else{
                if(opcao==2){
                    sub = 0;
                    do{
                        do{
                            cout<<"Qual o peso do prato de comida em kg?"<<endl;
                            cin>>pratoC;
                            system("cls");
                        }while(pratoC<=tara);

                        cont = cont + 1;
                        pesoR = pratoC - tara;
                        totalP = pesoR * valorQ;
                        sub = sub + totalP;

                        cout<<"Peso real: "<<pesoR<<"kg"<<endl;
                        cout<<"Total do prato: R$"<<totalP<<endl;
                        cout<<"Subtotal: R$"<<sub<<endl;

                        cin.ignore();
                        cout<<"Mais um prato?(S/N)"<<endl;
                        resp = toupper(cin.get());
                        system("cls");
                    }while(resp!='N');

                    cout<<"Total a pagar: R$"<<sub<<endl;

                    do{
                        cout<<"Troco para quanto?"<<endl;
                        cin>>dinC;
                    }while(dinC<sub);

                    troco = dinC - sub;
                    cout<<"Troco: R$"<<troco<<endl;
                    system ("cls");
                    valorC = sub + valorC;
                    fatur = valorC - valorA;
                }else{
                    cout<<"Valor atual do caixa: R$"<<valorC<<endl;
                    cout<<"Pratos Vendidos: "<<cont<<endl;
                    cout<<"Faturameto do dia: R$"<<fatur<<endl;
                }
            }
        }while(opcao!=3);
    }while(opcao!=3);
    return 0;
}
