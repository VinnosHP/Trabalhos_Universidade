#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef struct
{
    string nome, cpf, telefone;
} Clientes;

typedef struct
{
    string modelo, marca, codigo, placa, situacao="D", categoria;
    int qtdeL=0;
} Veiculos;

typedef struct
{
    string dataLocacao, cpf, codV, dataEntrega;
    float valorPagar, valorPago;
} Locacao;

int menu()
{
    int op;
    cout<<"             MENU"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<" 1 - Inclusao de veiculo"<<endl;
    cout<<" 2 - Inclusao de cliente"<<endl;
    cout<<" 3 - Exclusao de veiculo"<<endl;
    cout<<" 4 - Locacao de veiculo"<<endl;
    cout<<" 5 - Devolucao de veiculo"<<endl;
    cout<<" 6 - Relatorio Frota"<<endl;
    cout<<" 7 - Relatorio Clientes"<<endl;
    cout<<" 8 - Relatorio Locacoes"<<endl;
    cout<<" 9 - Relatorio Devolucoes"<<endl;
    cout<<" 0 - Sair"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Opcao: ";
    cin>>op;
    return op;
}

void inclusaoCarros(Veiculos x)
{
    static int n=0;
    string placa="", palavra="", op;
    char ch;
    if(rename("FROTA.txt","FROTA.bak")!=0)
        cout<<" ";
    else
        cout<<" ";
    ifstream arq2("FROTA.bak");
    ofstream arq("FROTA.txt", ios::app);
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para escrita!"<<endl; system("PAUSE");
    }
    if(!arq2){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl; system("PAUSE");
    }
    cin.ignore();
    cout<<"Placa: "; getline(cin, x.placa);
    while(arq2.get(ch)){
        if(ch == '|' or ch == '\n'){
            placa = palavra;
            if(placa != ""){
                if(x.placa == placa){
                    cout<<"Placa ja cadastrada!"<<endl; system("pause");
                    arq.close(); arq2.close(); return;
                }
                else
                    arq<<palavra<<ch;
                palavra = "";
            }
        }else{
            palavra = palavra + ch;
        }
    }
    if(arq2.gcount()==0){
        n++; x.codigo=to_string(n);
        cout<<"Codigo: "<<x.codigo<<endl;
        do{
            cout<<"Categoria"<<endl;
            cout<<"B - Basico"<<endl;
            cout<<"I - Intermediario"<<endl;
            cout<<"S - Super"<<endl;
            cout<<"Op: ";
            getline(cin, op);
        }while(op!="B" and op!="I" and op!="S");
        x.categoria = op;
        cout<<"Marca do carro: "; getline(cin, x.marca);
        cout<<"Modelo do carro: "; getline(cin, x.modelo);
        cout<<"Cadastro feito com sucesso!"<<endl;
        system("PAUSE");
        arq<<setw(7)<<x.placa<<"|"<<setw(1)<<x.codigo<<"|"<<setw(1)<<x.categoria<<"|"<<setw(8)<<x.marca<<"|"<<setw(8)<<x.modelo<<"|"<<setw(1)<<x.situacao<<"|"<<setw(2)<<x.qtdeL<<endl;
        arq.close(); arq2.close();
        remove("FROTA.bak");
    }
}

void inclusaoClientes(Clientes x)
{
    string palavra = "", nome = "";
    char ch;
    if(rename("CLIENTE.txt","CLIENTE.bak")!=0)
        cout<<" ";
    else
        cout<<" ";
    ifstream arq("CLIENTE.bak");
    ofstream arq2("CLIENTE.txt", ios::app);
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl; system("pause");
    }
    if(!arq2){
        cout<<"Arquivo nao pode ser aberto para escrita!"<<endl; system("pause");
    }
    cin.ignore();
    cout<<"Nome: "; getline(cin, x.nome);
    while(arq.get(ch)){
        if(ch == '|' or ch == '\n'){
            nome = palavra;
            if(nome != ""){
                if(x.nome == nome){
                    cout<<"Nome ja cadastrado!"<<endl; system("pause");
                    arq.close(); arq2.close(); return;
                }
                else
                    arq2<<palavra<<ch;
                palavra = "";
            }
        }else{
            palavra = palavra + ch;
        }
    }
    if(arq.gcount() == 0){
        cout<<"Cpf: "; getline(cin, x.cpf);
        cout<<"Telefone: "; getline(cin, x.telefone);
        system("pause");
        arq2<<x.nome<<"|"<<x.cpf<<"|"<<x.telefone<<"\n";
        arq.close(); arq2.close();
        remove("CLIENTE.bak");
    }
}

void exclusaoCarro(Veiculos x)
{
    string placa="", linha="", lido="";
    int i;
    char resp;
    bool achou = false;
    if(rename("FROTA.txt","FROTA.bak")!=0)
        cout<<" ";
    else
        cout<<" ";
    ofstream arq("FROTA.txt");
    ifstream arq2("FROTA.bak");
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl; system("pause");
    }
    if(!arq2){
        cout<<"Arquivo nao pode ser aberto para escrita!"<<endl; system("pause");
    }
    cin.ignore();
    cout<<"Placa: "; getline(cin,x.placa);
    while(getline(arq2, linha)){
        lido = linha.substr(0,7);
        x.codigo = linha.substr(8,9);
        x.categoria = linha.substr(10,11);
        x.marca = linha.substr(12,20);
        x.modelo = linha.substr(21,29);
        x.situacao = linha.substr(30,31);
        x.qtdeL = stoi(linha.substr(32,34));
        for(i=0; i<7; i++){
            if(lido[i]!=' ') placa = placa + lido[i];
        }
        if(x.placa == placa){
            achou = true;
            cout<<"Carro: "<<x.marca<<" "<<x.modelo<<endl;
            cout<<"Placa: "<<x.placa<<endl;
            do{
                cout<<"Confirmar exclusao? (S/N)"<<endl;
                resp = toupper(cin.get());
            }while(resp !='N' and resp!='S');
            if(resp == 'S'){
                arq<<setw(7)<<"-1"<<"|"<<setw(1)<<x.codigo<<"|"<<setw(1)<<x.categoria<<"|"<<setw(8)<<x.marca<<"|"<<setw(8)<<x.modelo<<"|"<<setw(1)<<x.situacao<<"|"<<setw(2)<<x.qtdeL<<endl;
            }else{
                cout<<"Exclusao cancelada!"<<endl;
                arq.close();
                arq2.close();
                system("pause");
                return;
            }
        }else{
            arq<<setw(7)<<placa<<"|"<<setw(1)<<x.codigo<<"|"<<setw(1)<<x.categoria<<"|"<<setw(8)<<x.marca<<"|"<<setw(8)<<x.modelo<<"|"<<setw(1)<<x.situacao<<"|"<<setw(2)<<x.qtdeL<<endl;
        }
        placa = "";
    }
    if(achou == true){
        while(getline(arq2,linha)){
            lido = linha.substr(0,7);
            x.codigo = linha.substr(8,9);
            x.categoria = linha.substr(10,11);
            x.marca = linha.substr(12,20);
            x.modelo = linha.substr(21,29);
            x.situacao = linha.substr(30,31);
            x.qtdeL = stoi(linha.substr(32,34));
            for(i=0; i<7; i++){
                if(lido[i]!=' ') placa = placa + lido[i];
            }
            if(placa != "-1"){
                arq<<setw(7)<<placa<<"|"<<setw(1)<<x.codigo<<"|"<<setw(1)<<x.categoria<<"|"<<setw(8)<<x.marca<<"|"<<setw(8)<<x.modelo<<"|"<<setw(1)<<x.situacao<<"|"<<setw(2)<<x.qtdeL<<endl;
            }
            placa = "";
        }
        arq.close(); arq2.close(); system("pause");
    }else{
        cout<<"Veiculo nao encontrado!"<<endl;
        arq.close(); arq2.close(); system("pause");
    }
    remove("FROTA.bak");
}

void locacaoC(Clientes lista, Locacao x, Veiculos y, int datL, int datD)
{
    string nome="", palavra="";
    char ch;
    ifstream arq("CLIENTE.txt");
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl;
        system("pause");
    }
    cin.ignore();
    cout<<"Nome: ";
    getline(cin, lista.nome);
    while(arq.get(ch)){
        if(ch == '|' or ch == '\n'){
            nome = palavra;
            if(nome != ""){
                if(lista.nome != nome){
                    cout<<"Cliente nao esta cadastrado!"<<endl;
                    system("pause");
                    arq.close();
                    return;
                }
                palavra = "";
            }
        }else{
            palavra = palavra + ch;
        }
    }
    string cat="", linha="";
    ifstream arq2("FROTA.txt");
    if(!arq2){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl;
        system("PAUSE");
        arq2.close();
        return;
    }
    cout<<"Informe a categoria: ";
    getline(cin, cat);
    while(arq2.get(ch)){
        getline(arq2, linha);
        if(ch == '|' or ch == '\n'){
            cat = palavra;
            if(cat != ""){
                if(y.categoria == cat){
                    cout<<linha<<endl;
                    system("PAUSE");
                }
                palavra = "";
            }
        }else{
            palavra = palavra + ch;
        }
    }
    system("PAUSE");
}

void devolucao(Clientes x, Veiculos y, Locacao z, int datD, int datL)
{
    string palavra = "", cpf = "";
    char ch;
    ifstream arq("CLIENTE.txt");
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl; system("pause");
    }
    cout<<"CPF: "; getline(cin, x.cpf);
    while(arq.get(ch)){
        if(ch == '|' or ch == '\n'){
            cpf = palavra;
            if(cpf != ""){
                if(x.cpf != cpf){
                    cout<<"CPF nao existe!"<<endl;
                    system("pause"); arq.close(); return;
                }
                palavra = "";
            }
        }else{
            palavra = palavra + ch;
        }
    }
    string situacao="";
    float multa=0.00, total=0.00;
    ifstream arqC("FROTA.txt");
    ofstream arqD("FROTA.txt");
    while(arqC.get(ch)){
        if(ch == '|' or ch == '\n'){
            situacao = palavra;
            if(situacao != ""){
                if(y.situacao == situacao){
                    arqD<<setw(7)<<y.placa<<"|"<<setw(1)<<y.codigo<<"|"<<setw(1)<<y.categoria<<"|"<<setw(8)<<y.marca<<"|"<<setw(8)<<y.modelo<<"|"<<setw(1)<<"D"<<"|"<<setw(2)<<y.qtdeL<<endl;
                    multa = datD - datL;
                    if(multa > 0){
                        multa = multa *(z.valorPagar*0.1);
                        total = z.valorPagar + multa;
                        cout<<"Veiculo atrasado!"<<endl;
                        cout<<"Valor da multa: R$"<<multa<<endl;
                        cout<<"Total a pagar: R$"<<total<<endl;
                        arqC.close(); arqD.close(); return;
                    }else{
                        cout<<"Veiculo entregue na data certa!"<<endl;
                        system("PAUSE");
                        arqC.close(); arqD.close(); return;
                    }
                    system("pause"); arqC.close(); return;
                }
                palavra = "";
            }
        }else{
            palavra = palavra + ch;
        }
    }
}

void relatorioFrota()
{
    string linha;
    ifstream arq("FROTA.txt");
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl;
        system("PAUSE"); arq.close(); return;
    }
    while(!arq.eof()){
        getline(arq, linha);
        cout<<linha<<endl;
    }
    system("PAUSE");
    arq.close();
}

void relatorioCliente()
{
    string linha;
    ifstream arq("CLIENTE.txt");
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl;
        system("PAUSE"); arq.close(); return;
    }
    while(!arq.eof()){
        getline(arq, linha);
        cout<<linha<<endl;
    }
    system("pause");
    arq.close();
}

void relatorioLocacao()
{
    string linha;
    ifstream arq("LOCACAO.txt");
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl;
        system("PAUSE"); arq.close(); return;
    }
    while(!arq.eof()){
        getline(arq, linha);
        cout<<linha<<endl;
    }
    system("pause");
    arq.close();
}

void relatorioDevolucao()
{
    string linha;
    ifstream arq("LOCACAO.txt");
    if(!arq){
        cout<<"Arquivo nao pode ser aberto para leitura!"<<endl;
        system("PAUSE"); arq.close(); return;
    }
    while(!arq.eof()){
        getline(arq, linha);
        cout<<linha<<endl;
    }
    system("pause");
    arq.close();
}


int main()
{
    Clientes lista; Veiculos lista2; Locacao lista3;
    int op=0, dataLocacao=1, dataDevolucao=11;
    do{
        system("CLS");
        op = menu();
        system("CLS");
        switch(op){
        case 1: inclusaoCarros(lista2); break;
        case 2: inclusaoClientes(lista); break;
        case 3: exclusaoCarro(lista2); break;
        case 4: locacaoC(lista, lista3, lista2, dataLocacao, dataDevolucao); break;
        case 5: devolucao(lista, lista2, lista3, dataDevolucao, dataLocacao); break;
        case 6: relatorioFrota(); break;
        case 7: relatorioCliente(); break;
        case 8: relatorioLocacao(); break;
        case 9: relatorioDevolucao(); break;
        }
    }while(op!=0);
    cout<<"Program by Vinicius Hostins Pereira and Igor do Carmo!"<<endl;
}
