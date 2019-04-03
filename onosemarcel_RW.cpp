/*
 STRUCTURI DE DATE :
 1) LISTE ...
 2) NDG ...
 ============

 3) DG = Directed Graphs

 Grafuri orientate

 1. Metode reprezentare :

 a) Matricea arcelor

 Fie G(X,U) graf orientat. X multimea nodurilor U multimea arcelor
 Il reprezentam printr-o matrice
                   | 1  daca exista arcul (xi,xj) in U
  (M)nxn = |
                   | 0   altfel

   n=|X|

exemplu : n=5

                1
             /     \
            *        *
            2  ---* 3
            |         *
            *         |
            4  ---*5

 Matricea arcelor  "input.dat"
 5
 0 1 1 0 0
 0 0 1 1 0
 0 0 0 0 0
 0 0 0 0 1
 0 0 1 0 0

 b) Matricea drumurilor

                 |   1 daca exista drum de la xi la xj
 (D) nxn =|
                 |  0 altfel

 xi din X ,xj din X , xi!=xj, n=|X|


 Conversie : Matricea arcelor ==> Matricea drumurilor

 Def :
 Fie G(X,U) DG.  Prin drum in G de la xi la xj intelegem o succesiune de noduri
 xi , .... , xk-1,xk, .... xj in care pentru oricare doua noduri  consecutive
 din secventa (xk-1,xk) k>1,k<=n exista in multimea U arcul (xk-1,xk)
 exemplu :
            n=5

                1
             /     \
            *        *
            2  ---* 3
            |         *
            *         |
            4  ---*5

 drum(1,5) : {1,2,4,5}       oricare consecutive
                                        (1,2)
                                        (2,4)
                                        (4,5) numesc arce din G(X,U)

 Numarul arcelor unui drum numeste lungimea acelui drum
 Pentru exemplul  dat
 drum(1,5) are lungime 3

 Algoritmul de conversie :
 Matricea arcelor ==> Matricea drumurilor
Ruleaza din un principiu de tip PD ( programare dinamica )
In care insa structura optimelor peste subseturi ale setului dat
este insasi structura initiala a setului dat
adica nu se utilizeaza o structura auxiliara.
Algoritmul lucreaza aplicand transformari succesive ale matricei arcelor
pana cand obtinem matricea drumurilor .
Sirul transformarilor de efectuat inseamna tatonarea tuturor nodurilor
intermediare posibile intre oricare doua noduri.
Concret parcurgem toate extremitatile posibile  ale drumurilor
pentru fiecare determinand existenta unui nod intermediar.
La pasul initial consideram ca matricea arcelor memoreaza doar existenta
drumurilor pe arce directe intre noduri

Roy Warshall

pentru i=1 pana la n executa
    pentru j=1 pana la n executa
                        pentru k=1 la n executa

                              daca k!=i si k!=j si i!=j atunci
                                                    M[i,j]=min(M[i,k],M[k,j] )


 output.dat
                1
             /     \
            *        *
            2  ---* 3
            |         *
            *         |
            4  ---*5
5
0 1 1 1 1
0 0 1 1 1
0 0 0 0 0
0 0 1 0 1
0 0 1 0 0

*/
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("input.dat");

int n;
int M[100][100];
int drum[100][100];

void read_data()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fin>>M[i][j];
}

int conversie()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(k!=i && k!=j && i!=j)
                    {
                        if(M[i][k]!=0 && M[k][j]!=0)
                        {
                        if(M[i][k]<=M[k][j])
                            M[i][j]=M[i][k];
                        if(M[i][k]>M[k][j])
                            M[i][j]=M[k][j];}
                    }
}

void write_data()
{
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    read_data();
    conversie();
    write_data();
}

