#include <iostream>
#include <cstdlib>
using namespace std;
#define TMAX 10

typedef struct
{
    string titulo,autor,isbn;
    int qtdeEx,qtdeEm;
} Livro;

typedef struct
{
    string matri,dataDevo,isbn;
    int cod;
} Emprestimo;

/*
void menu();
void entradaDadosLivro(string isbn,Livro &acervo);
void leituraLivro(int &i, Livro acervo[]);
void consulta(int i, Livro acervo[]);
void entradaDadosEmprestimo(string isbn, Emprestimo &divida, int &qtde);
void emprestimoLivro(int &n, Emprestimo divida[],int i, Livro acervo[]);
void exclusaoLivro(int &i, Livro acervo[]);
void devolucao(int n, Emprestimo divida[], int i, Livro acervo[]);
void relatorio1(int i, Livro acervo[]);
void relatorio2(int n, Emprestimo divida[]);
*/

void menu()
{
    system("cls");
    cout<<"==========================="<<endl;
    cout<<" 1 - Incluir um novo livro"<<endl;
    cout<<" 2 - Consulta de um livro"<<endl;
    cout<<" 3 - Exclusao de um livro"<<endl;
    cout<<" 4 - Emprestimo"<<endl;
    cout<<" 5 - Devolucao"<<endl;
    cout<<" 6 - Registro 1"<<endl;
    cout<<" 7 - Registro 2"<<endl;
    cout<<" 8 - Sair"<<endl;
    cout<<"==========================="<<endl;
}

void entradaDadosLivro(string isbn, Livro &acervo)
{
    acervo.isbn = isbn;
    cout<<"Titulo: ";
    getline(cin,acervo.titulo);
    cout<<"Autor: ";
    getline(cin,acervo.autor);
    cout<<"Qtde de exemplares: ";
    cin>>acervo.qtdeEx;
    do{
        cout<<"Qtde para emprestimo: ";
        cin>>acervo.qtdeEm;
    }while(acervo.qtdeEm>acervo.qtdeEx);
}

void leituraLivro(int &i, Livro acervo[])
{
    string isbn;
    cout<<"INCLUSAO DE UM LIVRO!"<<endl;
    cout<<"ISBN: ";
    getline(cin,isbn);
    for(int j=0;j<=i;j++){
        if(isbn == acervo[j].isbn){
            cout<<"Titulo ja existente!"<<endl;
            cout<<acervo[i].isbn<<endl;
            system("pause");
            return;
        }
    }
    entradaDadosLivro(isbn, acervo[i]);
    i++;
    cout<<endl<<"Inclusao de titulo confirmada!"<<endl<<endl;
    system("pause");
}

void relatorio1(int i,Livro acervo[])
{
    cout<<"RELATORIO 1!"<<endl;
    for(int j=0; j<i; j++)
    {
        cout<<endl<<"Livro "<<j+1<<endl;
        cout<<"Titulo: "<<acervo[j].titulo<<endl;
        cout<<"Autor: "<<acervo[j].autor<<endl;
        cout<<"ISBN: "<<acervo[j].isbn<<endl;
        cout<<"Qtde de exemplares: "<<acervo[j].qtdeEx<<endl;
        cout<<"Qtde para emprestimo: "<<acervo[j].qtdeEm<<endl;
    }
    system("pause");
}

void consulta(int i,Livro acervo[])
{
    string isbn;
    cout<<"CONSULTA DE UM LIVRO!"<<endl;
    cout<<"Informe o ISBN: ";
    getline(cin,isbn);
    for(int j=0;j<i;j++){
        if(isbn == acervo[j].isbn){
            cout<<"Titulo: "<<acervo[j].titulo<<endl;
            cout<<"Autor: "<<acervo[j].autor<<endl;
            cout<<"ISBN: "<<acervo[j].isbn<<endl;
            cout<<"Qtde de exemplares: "<<acervo[j].qtdeEx<<endl;
            cout<<"Qtde para emprestimo: "<<acervo[j].qtdeEm<<endl;
            system("pause");
            return;
        }
    }
    cout<<"Titulo inexistente!"<<endl;
    system("pause");
}

void exclusaoLivro(int &i,Livro acervo[])
{
    string isbn;
    cout<<"EXCLUSAO DE UM LIVRO!"<<endl;
    cout<<"ISBN: ";
    getline(cin,isbn);
    for(int j=0;j<i;j++){
        if(isbn == acervo[j].isbn){
            acervo[j]= acervo[i-1];
            acervo[i-1].autor= " ";
            acervo[i-1].isbn= " ";
            acervo[i-1].qtdeEm= 0;
            acervo[i-1].qtdeEx= 0;
            acervo[i-1].titulo= " ";
            i--;
            return;
        }
    }
    cout<<"Titulo inexistente, impossivel excluir!"<<endl;
    system("pause");
    return;
}

void entradaDadosEmprestimo(string isbn, Emprestimo &divida)
{
    isbn = divida.isbn;
    cout<<"Matricula do aluno/professor: ";
    getline(cin,divida.matri);
    cout<<"Data de devolução(dia/mes/ano): ";
    getline(cin,divida.dataDevo);
}

void emprestimoLivro(int &n, Emprestimo divida[],int i, Livro acervo[])
{
    string isbn;
    cout<<"EMPRESTIMO DE UM LIVRO"<<endl;
    cout<<"Informe o ISBN: ";
    getline(cin,isbn);
    for(int j=0;j<i;j++){
        if(isbn!=acervo[j].isbn)
        {
            cout<<"Titulo Inexistente!"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            return;
        }
        if(acervo[j].qtdeEm==0){
            cout<<"Titulo indisponivel para emprestimo!"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            return;
        }
        entradaDadosEmprestimo(isbn, divida[j]);
        divida[j].isbn = isbn;
        acervo[j].qtdeEm-=1;
        divida[j].cod = j;
        n++;
        cout<<"Foi retirado 1 exemplar do livro "<<acervo[j].titulo<<endl;
        cout<<"Emprestimo realizado! - codigo "<<divida[j].cod<<endl;
        system("pause");
    }
}

void devolucao(int n, Emprestimo divida[], int i, Livro acervo[])
{
    int cod;
    cout<<"DEVOLUCAO DE UM LIVRO!"<<endl;
    cout<<"Informe o codigo do emprestimo: ";
    cin>>cod;
    for(int j=0;j<i;j++){
        if(cod == divida[j].cod){
            if(divida[j].matri == "-1"){
                cout<<"Devolucao ja realizada!"<<endl;
                system("pause");
                return;
            }
            for(int k=0; k<i;k++){
                cout<<"CONFIRMACAO DOS DADOS!"<<endl;
                cout<<"Matricula do aluno/professor: "<<divida[j].matri<<endl;
                cout<<"Data de devolucao: "<<divida[j].dataDevo<<endl;
                divida[j].matri = "-1";
                acervo[j].qtdeEm+=1;
                n--;
                system("pause");
                return;
            }
        }
    }
    cout<<"Registro inexistente!"<<endl;
    system("pause");
}

void relatorio2(int n,Emprestimo divida[])
{
    cout<<"RELATORIO 2!"<<endl;
    for(int j=0; j<n; j++)
    {
        cout<<"Matricula: "<<divida[j].matri<<endl;
        cout<<"ISBN: "<<divida[j].isbn<<endl;
        cout<<"Data de devolucao: "<<divida[j].dataDevo<<endl;
        cout<<"Cod do emprestimo "<<divida[j].cod<<endl;
    }
    system("pause");
}

int main()
{
    Livro acervo[TMAX];
    Emprestimo divida[TMAX];
    int op,i=0, n=0;
    do{
        menu();
        cout<<"Opcao: ";
        cin>>op;
        system("CLS");
        cin.ignore();
        switch (op)
        {
        case 1:
            leituraLivro(i, acervo);
            break;
        case 2:
            consulta(i, acervo);
            break;
        case 3:
            exclusaoLivro(i, acervo);
            break;
        case 4:
            emprestimoLivro(n, divida, i, acervo);
            break;
        case 5:
            devolucao(n, divida, i, acervo);
            break;
        case 6:
            relatorio1(i,acervo);
            break;
        case 7:
            relatorio2(n,divida);
            break;
        }
    }while(op!=8);
    return 0;
}
