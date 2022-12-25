//Vinicius Hostins Pereira e Igor do Carmo
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct Nodo{
    int quantEstoque, unidVendidas, codigo;
    float precoProduto, totalVenda;
    string nome;
    struct Nodo *proximo;
}TipoProduto;

void menu(){
    system("cls");
    cout<<"============================="<<endl;
    cout<<" 1 - Incluir um novo Produto"<<endl;
    cout<<" 2 - Consultar Produto"<<endl;
    cout<<" 3 - Excluir Produto"<<endl;
    cout<<" 4 - Venda"<<endl;
    cout<<" 5 - Relatorio de Estoque"<<endl;
    cout<<" 6 - Relatorio de Vendas"<<endl;
    cout<<" 7 - Sair"<<endl;
    cout<<"============================="<<endl;
}

void novoProduto(TipoProduto **ptr_lista){
    TipoProduto *p, *paux;
    bool achou;
    string nome;
    p = new TipoProduto;
    p->unidVendidas = 0;
    p->totalVenda = 0;
    if(p == NULL){
        cout<<"Sem memoria!";
        cin.get();
        exit(1);
    }
    cout<<"Nome: ";
    getline(cin,p->nome);
    paux = *ptr_lista;
    while(paux != NULL){
        if(paux->nome == p->nome){
            cout<<endl<<"Produto ja existente!"<<endl<<endl;
            system("PAUSE");
            return;
        }
        paux = paux->proximo;
    }
    do{
        cout<<"Quantidade no estoque: ";
        cin>>p->quantEstoque;
    }while(p->quantEstoque <= 0);
    do{
        cout<<"Preco do Produto: ";
        cin>>p->precoProduto;
    }while(p->precoProduto <= 0);
    p->codigo = rand()%100 + 1;
    do{
        achou = false;
        paux = *ptr_lista;
        while(paux != NULL){
            if(p->codigo == paux->codigo){
                p->codigo = rand()%100 + 1;
                achou = true;
            }
            paux = paux->proximo;
        }
    }while(achou == true);
    p->proximo = *ptr_lista;
    *ptr_lista = p;
    cout<<"Codigo do produto: "<<p->codigo<<endl;
    cout<<endl<<"Inclusao confirmada!"<<endl<<endl;
    system("PAUSE");
}

void consultaProduto(TipoProduto **lista){
    TipoProduto *p;
    int codigo = 0;
    cout<<"informe o codigo do produto: ";
    cin>>codigo;
    p = *lista;
    while(p != NULL){
        if(p->codigo == codigo){
            cout<<endl<<"Codigo: "<<p->codigo<<endl;
            cout<<"Nome: "<<p->nome<<endl;
            cout<<"Pre�o: "<<p->precoProduto<<endl;
            cout<<"Quantidade em estoque: "<<p->quantEstoque<<endl;
            cout<<"Quantidade vendida: "<<p->unidVendidas<<endl;
            system("PAUSE");
            return;
        }
        p = p->proximo;
    }
    cout<<endl<<"Produto inexistente!"<<endl<<endl;
    system("PAUSE");
}

void exclusaoProduto(TipoProduto **lista){
    TipoProduto *p, *pant = NULL;
    int codigo = 0;
    char resp;
    p = *lista;
    cout<<"Informe o codigo do produto: "<<endl;
    cin>>codigo;
    if(p != NULL){
        if(p->codigo == codigo){
            cout<<"Nome:"<<p->nome<<endl;
            cout<<"Codigo: "<<p->codigo<<endl;
            cout<<"Preco do Produto: R$"<<p->precoProduto<<endl;
            cout<<"Quantidade no Estoque: "<<p->quantEstoque<<endl;
            cout<<"Quantidade Vendida: "<<p->unidVendidas<<endl;
            cout<<"Confirmar exclusao(S/N)? "<<endl;
            cin.ignore();
            resp = toupper(cin.get());
            if(resp == 'S'){
                *lista = p->proximo;
                delete p;
                cout<<"Exclusao realizada!"<<endl;
                system("pause");
                return;
            }else{
                cout<<"Exclusao nao realizada!"<<endl;
                system("pause");
                return;
            }
        }
        pant = *lista;
        p = p->proximo;
        while(p != NULL and p->codigo != codigo){
            pant = p;
            p = p->proximo;
        }
        if(p != NULL){
            cout<<"Nome: "<<p->nome<<endl;
            cout<<"Codigo: "<<p->codigo<<endl;
            cout<<"Preco do Produto: R$"<<p->precoProduto<<endl;
            cout<<"Quantidade no Estoque: "<<p->quantEstoque<<endl;
            cout<<"Quantidade Vendida: "<<p->unidVendidas<<endl;
            cout<<"Confirmar exclusao(S/N)? "<<endl;
            cin.ignore();
            resp = toupper(cin.get());
            if(resp == 'S'){
                pant->proximo = p->proximo;
                delete p;
                cout<<"Exclusao realizada!"<<endl;
                system("pause");
                return;
            }else{
                cout<<"Exclusao nao realizada!"<<endl;
                system("pause");
                return;
            }
        }
    }
    cout<<"Produto inexistente!"<<endl;
    system("pause");
}

void venda(TipoProduto **lista){
    TipoProduto *p;
    int codigo = 0, quantidade = 0;
    float total = 0.0;
    char resp;
    cout<<"Informe o codigo do produto: ";
    cin>>codigo;
    p = *lista;
    while(p != NULL){
        if(p->codigo == codigo){
            cout<<"Qual a quantidade vendida? ";
            cin>>quantidade;
            if(p->quantEstoque < quantidade or quantidade < 0){
                cout<<"Quantidade ultrapassa a do estoque!"<<endl;
                cout<<"Quantidade em estoque: "<<p->quantEstoque<<endl;
                system("PAUSE");
                return;
            }
            total = quantidade * p->precoProduto;
            cout<<"Quantidade vendida: "<<quantidade<<endl;
            cout<<"Preco: "<<p->precoProduto<<endl;
            cout<<"Total: "<<total<<endl;
            cout<<"Confirmar venda(S/N)? ";
            cin.ignore();
            resp=toupper(cin.get());
            if(resp == 'N'){
                cout<<endl<<"Venda nao realizada!"<<endl<<endl;
                system("PAUSE");
                return;
            }
            p->unidVendidas += quantidade;
            p->quantEstoque -= quantidade;
            p->totalVenda += total;
            cout<<endl<<"Venda realizada!"<<endl<<endl;
            system("PAUSE");
            return;
        }
        p = p->proximo;
    }
    cout<<endl<<"Produto inexistente"<<endl<<endl;
    system("PAUSE");
}

void relatorioEstoque(TipoProduto *p){
    while (p != NULL){
        cout<<"Codigo do Produto: "<< p->codigo<<endl;
        cout<<"Nome: "<< p->nome<<endl;
        cout<<"Preco do Produto: R$"<< p->precoProduto<<endl;
        cout<<"Quantidade no estoque: "<< p->quantEstoque<<endl<<endl;
        p = p->proximo;
    }
    system("PAUSE");
}

void relatorioVenda(TipoProduto *p){
    while (p != NULL){
        cout<<"Codigo do Produto: "<< p->codigo<<endl;
        cout<<"Quantidade Vendida: "<< p->unidVendidas<<endl;
        cout<<"Total da Venda: R$"<<p->totalVenda<<endl<<endl;
        p = p->proximo;
    }
    system("PAUSE");
}

void destroilista(TipoProduto **lista){
    TipoProduto *p;
    while (*lista != NULL){
        p = *lista;
        *lista = (*lista)->proximo;
        delete p;
    }
}

int main(){
    TipoProduto *lista = NULL;
    srand(time(NULL));
    int op = 0;
    do{
        do{
            menu();
            cout<<"Opcao: ";
            cin>>op;
            system("CLS");
        }while(op <= 0 or op>7);
        cin.ignore();
        switch (op)
        {
        case 1:
            novoProduto(&lista);
            break;
        case 2:
            consultaProduto(&lista);
            break;
        case 3:
            exclusaoProduto(&lista);
            break;
        case 4:
            venda(&lista);
            break;
        case 5:
            relatorioEstoque(lista);
            break;
        case 6:
            relatorioVenda(lista);
            break;
        }
    }while(op!=7);
    destroilista(&lista);
    cout<<"Codigo feito por Vincius HP e Igor do Carmo"<<endl;
}
