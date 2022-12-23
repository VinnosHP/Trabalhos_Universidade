#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int i,j,mat[6][2],codfilme,contC=0,contD=0,contDe=0,contA=0,contS=0,contM=0,dvdS;
    char resp;
    float preco,dindin,troco,medC,totalCl,totalA,totalC,totalD,totalDe,totalS,totalM;
    string tipo;
    do
    {
        cout<<"        REGISTRO"<<endl;
        cout<<"=========================="<<endl;
        cout<<"  Qual o genero do filme:"<<endl;
        cout<<"-comedia         -drama"<<endl;
        cout<<"-desenho         -aventura"<<endl;
        cout<<"-suspense        -musical"<<endl;
        cout<<"=========================="<<endl;
        cin>>tipo;

        cout<<"=========================="<<endl;
        cout<<"  Qual o codigo do filme:"<<endl;
        cout<<"-comedia                =1"<<endl;
        cout<<"-drama                  =2"<<endl;
        cout<<"-desenho                =3"<<endl;
        cout<<"-aventura               =4"<<endl;
        cout<<"-suspense               =5"<<endl;
        cout<<"-musical                =6"<<endl;
        cout<<"=========================="<<endl;
        cin>>codfilme;

        if(codfilme==1)
        {
            contC=contC+1;
        }
        if(codfilme==2)
        {
            contD=contD+1;
        }
        if(codfilme==3)
        {
            contDe=contDe+1;
        }
        if(codfilme==4)
        {
            contA=contA+1;
        }
        if(codfilme==5)
        {
            contS=contS+1;
        }
        if(codfilme==6)
        {
            contM=contM+1;
        }

        cout<<"Mais algum filme?(S/N)"<<endl;
        cin>>resp;
    }
    while(resp!='N' and resp!='n');

    for(i=0; i<6; i++)
    {
        for(j=0; j<2; j++)
        {
            cout<<"       Teste de Matriz para Registro"<<endl;
            cout<<"========================================="<<endl;
            cout<<"Digite: primeiro o genero depois o codigo"<<endl;
            cout<<"   comedia                         = 1"<<endl;
            cout<<"   drama                           = 2"<<endl;
            cout<<"   desenho animado                 = 3"<<endl;
            cout<<"   suspense                        = 4"<<endl;
            cout<<"   aventura                        = 5"<<endl;
            cout<<"   musical                         = 6"<<endl;
            cout<<"========================================="<<endl;
            cout<<"Genero na posicao ["<<i+1<<"] e Codigo na posicao[" << j+1 <<"]: ";
            cin>> mat[i][j];
        }
    }
    cout << endl << "Matriz Teste" << endl;
    for(i=0; i<6; i++)
    {
        for(j=0; j<2; j++)
        {
            cout <<"["<< mat[i][j] << "]";
        }
        cout<<endl;
    }
    cout << endl;


    cout<<"Qual o valor do DVD:"<<endl;
    cin>>preco;
    cout<<endl;
    cout<<"Quanto o cliente deu:"<<endl;
    cin>>dindin;
    troco=dindin-preco;
    cout<<"Troco: R$"<<troco<<endl;

    cout<<"==================================="<<endl;
    cout<<"Numeros de locacoes de cada genero:"<<endl;
    cout<<"-comedia "<<contC<<endl;
    cout<<"-drama "<<contD<<endl;
    cout<<"-desenho "<<contDe<<endl;
    cout<<"-aventura "<<contA<<endl;
    cout<<"-suspense "<<contS<<endl;
    cout<<"-musical "<<contM<<endl;
    cout<<"==================================="<<endl;
    cout<<"==================================="<<endl;
    cout<<"Total arrecadado por cada genero:"<<endl;
    cout<<"-comedia "<<totalC<<endl;
    cout<<"-drama "<<totalD<<endl;
    cout<<"-desenho "<<totalDe<<endl;
    cout<<"-aventura "<<totalA<<endl;
    cout<<"-suspense "<<totalS<<endl;
    cout<<"-musical "<<totalM<<endl;
    cout<<"==================================="<<endl;
    cout<<"=================================================="<<endl;
    if(contD>3)
    {
        cout<<"DVDs tipo drama que tiveram mais de 3 locacoes: "<<contD<<endl;
    }
    else
    {
        cout<<"DVDs tipo drama que tiveram mais de 3 locacoes: 0"<<endl;
    }
    cout<<"DVDs que nao tiveram locacao: "<<dvdS<<endl;
    cout<<"Total Pago por cliente: R$"<<totalCl<<endl;
    cout<<"Valor medio pago por cliente: R$"<<medC<<endl;
    cout<<"=================================================="<<endl;
    return 0;
}
