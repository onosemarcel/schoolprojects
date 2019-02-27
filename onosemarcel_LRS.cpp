/*
Arbori binari "insestrati"  ( informatii atasate nodurilor )
[I] Metode de reprezentare
[II] Metode de parcurgere

I.a) Prin "legatura la tata"
I.b) Prin " fii stangi - fii drepti"

fii stangi - fii drepti

Utilizam 3 vectori :
- INFO unde INFO[i]=node inseamna ca nodul i este inzestrat cu informatia k
- STANGI unde STANGI[i]=j
inseamna ca numele fiului stang al lui i este j
( daca acesta nu exista STANG[i]=0 )
- DREPTI unde DREPTI[i]=j
inseamna ca numele fiului drept al lui i este j

exemplu :
                               100(1)
                            /          \
                           /             \
                          50(2)         170(5)
                          /      \                \
                        20(3)   60(4)     190(6)

INFO ={100,50,20,60,170,190}
STANGI={2,3,0,0,0,0}
DREPTI={5,4,0,0,6,0}

Input.dat
6
100 50 20 60 170 190
2 3 0 0 0 0
5 4 0 0 6 0

aplicatii :
( parcurgere in preordine )
RSD(1): 100,50,20,60,170,190
( parcurgere in inordine )
SRD(1): 20,50,60,100,170,190
( parcurgere in postordine )
SDR(1): ... ,100


*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream f("input.dat");

int n;
int INFO[100], STANGI[100], DREPTI[100];

int read_data()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>INFO[i];
    }
    for(int i=1;i<=n;i++)
    {
        f>>STANGI[i];
    }
    for(int i=1;i<=n;i++)
    {
        f>>DREPTI[i];
    }
}

int RSD(int node)
{
    cout<<INFO[node]<<" ";
    if(STANGI[node]!=0)
    {
        RSD(STANGI[node]);
    }
    if(DREPTI[node]!=0)
    {
        RSD(DREPTI[node]);
    }
}

int SRD(int node)
{
    if(STANGI[node]!=0)
    {
        SRD(STANGI[node]);
    }
    cout<<INFO[node]<<" ";
    if(DREPTI[node]!=0)
    {
        SRD(DREPTI[node]);
    }
}

int SDR(int node)
{
    if(STANGI[node]!=0)
    {
        SDR(STANGI[node]);
    }
    if(DREPTI[node]!=0)
    {
        SDR(DREPTI[node]);
    }
    cout<<INFO[node]<<" ";
}

int main()
{
    read_data();
    RSD(1);
    cout<<endl;
    SRD(1);
    cout<<endl;
    SDR(1);
}
