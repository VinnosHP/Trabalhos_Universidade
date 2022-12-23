#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
//Trabalho M3 Consulta de Estoque - Vinicius Hostins Pereira e Igor Carmo.
int main()
{
    string nome[15]={"","","","","","","","","","","","","","",""},nomePes,nomeAux;
    int i,j,n,opcao,cont,vetPre[15],vetQuant[15],quant;

    do{
        do{
            cout<<"-----Estoque-----\n"
                " 1 - Cadastrar\n"
                " 2 - Consultar\n"
                " 3 - Editar\n"
                " 4 - Excluir\n"
                " 5 - Listar\n"
                " 6 - Sair\n"
                "-----------------\n"
                "Opcao: ";
            cin>>opcao;
            system("CLS");
        }
        while(opcao<1 or opcao>6);

        switch(opcao){
        case 6:
            cout<<"\nSaindo..."<<endl;
            break;

        case 1:
            for(i=0;i<n;i++){
                if(n>vetQuant[i]){
                    cout<<"Estoque cheio!"<<endl;
                    system("PAUSE");
                    system("CLS");
                    cont++;
                    break;
                }
            }
            if(cont!=0){
                break;
            }
            cont=0;
            do{
                cout<<"Informe a quantidade de produtos(limite de 15): ";
                cin>>n;
            }while(n>15 or n<1);

            for(i=0; i<n; i++){
                do{
                    cout<<"Informe o Nome do produto: ";
                    cin.ignore();
                    getline(cin, nomeAux);
                    cont=0;
                    for(j=0;j<15;j++){
                        if(nomeAux==nome[j]){
                            cout<<"\nProduto ja cadastrado!\n";
                            cont++;
                        }
                    }
                }while(cont!=0);
                nome[i]=nomeAux;
                cout<<"Informe o Preco do produto: ";
                cin>>vetPre[i];
                if(vetPre[i]<1){
                    cout<<"valor invalido!"<<endl;
                    system("PAUSE");
                    nome[i]="";
                    vetPre[i]=0;
                    system("cls");
                    break;
                }
                cout<<"Informe a Quantidade deste produto: ";
                cin>>vetQuant[i];
                if(vetQuant[i]<0){
                    cout<<"Quantidade invalida!"<<endl;
                    system("PAUSE");
                    nome[i]="";
                    vetPre[i]=0;
                    vetQuant[i]=0;
                    break;
                }
                system("CLS");
            }
            break;

        case 2:
            cout<<"Informe o Nome do produto: ";
            cin.ignore();
            getline(cin,nomePes);
            cont = 0;
            for(i=0;i<15;i++){
                if(nomePes==nome[i]){
                    cout<<"Produto: "<<nome[i]<<" --- Preco: R$"<<vetPre[i]<<" --- QTDE: "<<vetQuant[i]<<endl;
                    system("PAUSE");
                    system("CLS");
                    break;
                }else{
                    cont++;
                }
                if(cont==15){
                    cout<<"Produto nao encontrado!"<<endl;
                    system("PAUSE");
                    system("CLS");
                    break;
                }
            }
            break;

         case 3:
            cont=0;
            opcao=0;
            cin.ignore();
            cout<<"Informe o produto que ira ser editado: ";
            getline(cin,nomePes);
            for(i=0;i<15;i++){
                if(nomePes==nome[i]){
                    cout<<"\nNome: "<<nome[i]<<" --- Preco: R$"<<vetPre[i]<< " --- QTDE: " <<vetQuant[i]<<endl;
                    cout<<"\nDeseja aumentar ou diminuir a qtde deste produto?\n""1 - Aumentar\n""2 - Diminuir\n";
                    cin>>opcao;
                    if(opcao==1){
                        cout<<"Deseja aumentar em quanto?"<<endl;
                        cin>>quant;
                        vetQuant[i] = vetQuant[i] + quant;
                        cout<<"\nProduto editado.\n";
                        system("PAUSE");
                        system("CLS");
                    }
                    if(opcao==2){
                        cout << "Quanto deseja diminuir?" << endl;
                        cin >> quant;
                        vetQuant[i] = vetQuant[i] - quant;
                        cout<<"\nProduto editado.\n";
                        system("PAUSE");
                        system("CLS");
                    }
                }else{
                    cont++;
                }
                if(cont==15){
                    cout<<"Produto nao encontrado\n";
                    system("PAUSE");
                    system("CLS");
                    break;
                }
            }
            break;

        case 4:
            cont=0;
            cin.ignore();
            cout<<"Informe o produto: ";
            getline(cin,nomePes);
            for(i=0;i<15;i++){
                if(nomePes==nome[i]){
                    cout<<"\nNome: "<<nome[i]<<" --- Preco: R$"<<vetPre[i]<<" ---  QTDE: "<<vetQuant[i]<<endl;
                    do{
                        cout<<"\nQuer realmente excluir este produto?\n""1 - Sim\n""2 - Nao\n";
                        cin>>opcao;
                    }while(opcao!=1 and opcao!=2);
                    if(opcao==1){
                        nome[i]="";
                        vetPre[i]=0;
                        vetQuant[i]=0;
                        cout<<"Produto excluido do estoque!"<<endl;
                        system("PAUSE");
                    }else{
                        cout<<"Produto nao excluido.\n";
                        system("PAUSE");
                        system("CLS");
                        break;
                    }
                }else{
                    cont++;
                }
                if(cont==15){
                    cout<<"Produto nao encontrado!\n";
                    system("PAUSE");
                    system("CLS");
                    break;
                }
            }
            system("CLS");
            break;

        case 5:
            cont=0;
            cout<<"Lista dos Produtos abaixo de 5 unidades:\n";
            for(i=0;i<15;i++){
                if(vetQuant[i]<5 and nome[i]!=""){
                    cout<<"Nome: "<<nome[i]<<" --- Preco: R$"<<vetPre[i]<<" --- QTDE: "<<vetQuant[i]<<endl;
                }else{
                    cont++;
                }
            }
            if(cont==15){
                cout<<"Nenhum produto abaixo de 5 unidades.\n";
            }
            cout<<endl;
            system("PAUSE");
            system("CLS");
            break;
        }
    }while(opcao!=6);
    return 0;
}
