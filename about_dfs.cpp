/*[a] Grafuri neorientate

1. metode de reprezentare
    Apps :
    - conversii

2. parcurgeri in NDG
    Strategii :
    - DFS ( deep first search )
    parcurgere cu vizitare mai intai in adancime
    ( vizitez prim adiacent nevizitat inca daca exista , altfel ma intorc ! )

    exemplu :

       1 *
       /   \
    2 *    * 3
    /   \
4 *    * 5

 DFS(1) : 1,2,4,5,3

Parcurgere inseamna vizitarea tutor nodurilor mergand pe muchii
DFS este un algoritm de tip BKTR ( datorita momentului "pas inapoi"
cand nu depistam "prim adiacent nevizitat inca" al nodului curent
Asadar DFS contruieste o lista a nodurilor parcurse
pas cu pas ( constructiv , la fiecare pas se adauga un cate nou nod
in parcurse ) manevrata cu strategie de tip STACK ( metoda bktr )
Parcurgere DFS genereaza ca solutie un vector continad
lista nodurilor parcurse  pornind dintr-un nod de start

Date si structuri de date necesare :
[ cazul G(X,U) reprezentat ca matrice de adiacenta ]

n - numarul nodurilor
a11 ... a1n
....
an1 ...ann  - matricea de adiacenta ( care reprezinta G(X,U) )
S - vectorul solutie  ( manevrat cu strategie de tip stiva )
top - varf curent pe stiva
VIZ - vector caracteristic al "vizitatilor" i.e. VIZ[i]=0 i nod nevizitat
                                                                       VIZ[i]=1 i nod vizitat
Rutina de parcurgere DFS fiind de tip BKTR admite
implementatri atat recursive cat si iterative

(I) DFS iterativ
Ca orice bktr alg ruleaza intr-un ciclu de tipul "atata timp cat stiva nu
vida"
Adica atata timp cat mai sunt noduri nevizitate accesibile inca.
DFS datorita particularitatilor problemei in care functioneaza
       frecvent se implementeaza ca alg bktr degenrat voluntar
       cu scopul optimizarilor evidente.

DFS  in varianta bktr standard  utilizeaza rutina standard bktr
       cu adaptari specifice enuntului in  descririle intrumentelor

       init
       tipar
       valid
       solutie
       succesor

*/
#include<fstream>
#include<iostream>
using namespace std;
fstream f;
ifstream fin ("inut.dat");
int G[100][100];
int n;
int VIZ[100];

int k; // nodul de start

struct stiva
{
    int content[100];
    int top;
};
stiva S;

int read_data()
{
    fin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            fin>>G[i][j];
    fin>>k;
}


int  init(stiva *S)
{
    S->content[S->top]=0;
}
int tipar(stiva *S)
{
        cout<<S->content[S->top]<<" ";
}
int valid(stiva *S)
{

}
int solutie(stiva *S)
{
    return S->top == n;
}
int succesor(stiva *S)
{

}

int DFS_BKTR(stiva *S, int nod)
{
S->top=1;
S->content[S->top]=nod;
cout<<nod<<" ";
VIZ[nod]=1;
while (S->top>=1)
    { // caut succesor valid , daca acesta exista
      int am,este;
      do {
            am=succesor(S);
            este=valid(S);
           }  while (!((am&&este)||(!am)));
     if (am) if (solutie(S)) { tipar(S);}
                                else   {
                                            init(S->top);
                                            S->top++;
                                          }
       else S->top--;
    }
}
int main()
{
read_data();
init(&S);
DFS_BKTR(k);
}

/*
       1 *
       /   \
    2 *    * 3
    /   \
4 *    * 5

DFS(1) : 1,2,4,5,3

input.dat
5
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
1
output.dat
1,2,4,5,3





*/
