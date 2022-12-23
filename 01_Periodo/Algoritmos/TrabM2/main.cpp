#include <iostream>

using namespace std;

int main()
{
    float euro,dolar,real,valorP,subtotal,totalP,troco,dinC,realito,verdinha,eurinho;
    int quantP,opcao;
    char produto,resp,moeda;

    cout<<"-------MENU-------"<<endl;
    cout<<"1 - Abrir o caixa"<<endl;
    cout<<"2 - Novo cliente"<<endl;
    cout<<"3 - Fechar o caixa"<<endl;
    cout<<"------------------"<<endl;
    cin>>opcao;

    real=10000;
    euro=6.50;
    dolar=5;

    euro=real/euro;
    dolar=real/dolar;

    cout<<"-------------"<<endl;
    cout<<"Caixa Aberto:"<<endl;
    printf("\nR$ %0.2f\n",real);
    printf("\nUS$ %0.2f\n",dolar);
    printf("\nE$ %0.2f\n",euro);
    cout<<"-------------"<<endl;

    switch(opcao){
       case 2:
          cout<<"Informe a moeda em que sera efetuado o pagamento:";
          cin>>moeda;
          setbuf(stdin,NULL);
          do{
            cout<<"Informe o produto:";
            cin>>produto;
            cout<<"Informe seu valor:";
            cin>>valorP;
            cout<<"Informe a quantidade:";
            cin>>quantP;
            subtotal=valorP*quantP;
            printf("\nSubtotal = R$ %0.2f\n",subtotal);
            cout<<"Mais um produto?(S/N)";
          }while(resp=='N');
          printf("\nTotal em reais R$ %0.2f\n",subtotal);
          if(moeda=='euro'){
            totalP=subtotal/6.50;
            printf("\nTotal em euros: €$ %0.2f\n",totalP);
          }
          else{
            if(moeda=='dolar'){
                totalP=subtotal/5;
                printf("\nTotal em dolar US$ %0.2f\n",totalP);
            }
          }
         cout<<"Qual o valor dado pelo cliente?";
         cin>>dinC;
         if(moeda=='euro'){
            dinC=dinC*6.50;
            troco=dinC-subtotal;
            printf("\nTroco em reais R$ %0.2f\n",troco);
         }
         else{
            if(moeda=='dolar'){
               dinC=dinC*5;
               troco=dinC-subtotal;
               printf("\nTroco em reais R$ %0.2f\n",troco);
            }
         }
         break;
       case 3:
          cout<<"-------------"<<endl;
          cout<<"Caixa Fechado"<<endl;
          printf("\nR$ %0.2f\n",real);
          printf("\nUS$ %0.2f\n",dolar);
          printf("\nE$ %0.2f\n",euro);
          cout<<"-------------"<<endl;
          break;
    }
      realito=(real-troco)+dinC;
      eurinho=realito/6.50;
      verdinha=realito/5;
      cout<<"-------------"<<endl;
      cout<<"Caixa Fechado:"<<endl;
      printf("\nR$ %0.2f\n",realito);
      printf("\nUS$ %0.2f\n",verdinha);
      printf("\nE$ %0.2f\n",eurinho);
      cout<<"-------------"<<endl;

    return 0;
}
