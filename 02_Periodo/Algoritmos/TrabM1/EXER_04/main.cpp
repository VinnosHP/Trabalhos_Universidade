#include <iostream>

using namespace std;

int main()
{
    int matri;
    float p1A, p1B, p2, mediaE, mediaA;
    char conc;
    cout<<"Informe a matricula:";
    cin>>matri;
    cout<<"Informe as tres notas das verificacoes parciais:";
    cin>>p1A >> p1B >> p2;
    cout<<"Informe a media dos exercicios:";
    cin >>mediaE;
    mediaA = (p1A + p1B * 2 + p2 * 3 + mediaE)/7;
    if(mediaA >= 9.0)
    {
        conc = 'A';
    }
    else
    {
        if(mediaA >= 7.5)
        {
            conc = 'B';
        }
        else
        {
            if(mediaA >= 6.0)
            {
                conc = 'C';
            }
            else
            {
                if(mediaA >= 4.0)
                {
                    conc = 'D';
                }
                else
                {
                    conc = 'E';
                }
            }
        }
    }
    cout<<"Matricula: "<<matri<<endl;
    cout<<"Notas: "<<p1A<<", "<<p1B<<", "<<p2<<endl;
    cout<<"Media dos exercicios: "<<mediaE<<endl;
    cout<<"Conceito: "<<conc<<endl;
    switch (conc)
    {
    case 'A':
        cout<<"Situacao: Aprovado";
        break;
    case 'B':
        cout<<"Situacao: Aprovado";
        break;
    case 'C':
        cout<<"Situacao: Aprovado";
        break;
    case 'D':
        cout<<"Situacao: Reprovado";
        break;
    case 'E':
        cout<<"Situacao: Reprovado";
        break;
    }
    return 0;
}
