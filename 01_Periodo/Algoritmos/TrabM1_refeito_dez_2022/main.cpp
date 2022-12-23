#include <iostream>

using namespace std;

typedef struct
{
    float num;
}Numeros;

void menu()
{
    cout<<"--------- MENU ---------"<<endl;
    cout<<" 1 - Iniciar"<<endl;
    cout<<" 2 - Ordem Crescente"<<endl;
    cout<<" 3 - Ordem Decrescente"<<endl;
    cout<<" 4 - Maior no Meio"<<endl;
    cout<<" 5 - Sair"<<endl;
    cout<<"------------------------"<<endl;
    cout<<" Opcao: ";
}

void iniciar(Numeros v[])
{
    for(int i = 0; i < 3; i++){
        cout<<"Informe o "<<i+1<<" numero: ";
        cin>>v[i].num;
    }
}

void ordemCresce(Numeros v[])
{

}

int main()
{
    Numeros vet[3];
	int opcao = 0;

	do{
        do{
            system("cls");
            menu();
            cin>>opcao;
        }while(opcao<1 && opcao>5);
        system("cls");
        switch(opcao)
        {
        case 1:
            iniciar(vet);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
        system("pause");
	}while(opcao != 5);
	cout<<"Saindo..."<<endl;
	return 0;

	/*Se ((a > b) e (a > c)) Entao
		asort <- a
		Se (b > c) Entao
			bsort <- b
			csort <- c
		Senao
			bsort <- c
			csort <- b
		Fimse
	Senao
		Se ((b > a) e (b > c)) Entao
			asort <- b
			Se (a > c) Entao
				bsort <- a
				csort <- c
			Senao
				bsort <- c
				csort <- a
			Fimse
		Senao
			asort <- c
			Se (b > a) Entao
				bsort <- b
				csort <- a
			Senao
				bsort <- a
				csort <- b
			Fimse
		Fimse
	Fimse
	Escolha opcao
		Caso 1
			Escreval("em ordem crescente:", asort, bsort, csort)
		Caso 2
			Escreval("em ordem decrescente:", csort, bsort, asort)
		Caso 3
			Escreval("maior no meio:", bsort, asort, csort)
		Outrocaso
			Escreval("opcao incorreta")
	Fimescolha

Fimalgoritmo*/
}
