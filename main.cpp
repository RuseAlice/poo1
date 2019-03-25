#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("date.in");
ifstream fout("date.out");
/**Tema 15. grafuri neorientate, reprezentate cum doreste programatorul:

o clasa graf neorientat sa contina metode pentru:

 citirea grafului, care sa supraincarce operatorul >> ;

 afisarea grafului, care sa supraincarce operatorul <<;

citirea si afisarea sa foloseasca acelasi mod de reprezentare a grafului, care sa
arate intreaga structura a grafului, ceea ce parcurgerile urmatoare nu pot face;

parcurgerea in latime;

parcurgerea in adancime;

determinarea matricii (existentei) drumurilor;

determinarea componentelor conexe nu ca grafuri, ci ca liste de
noduri;
 o metoda care sa determine daca graful este conex, care poate folosi
oricare dintre metodele anterioare;
 o metoda de supraincarcare a operatorului +,
care sa determine, din doua grafuri neorientate avand aceeasi multime de noduri,
graful cu aceeasi multime de noduri ca si acele doua grafuri, si cu multimea
muchiilor egala cu, reuniunea multimilor muchiilor acelor doua grafuri; */


class GrafN{
    int s, mat[20][20], viz[20], n, m;
public:
    GrafN();
    GrafN(int x, int y, int v[20][20]);


friend istream &operator>>(istream &i, GrafN &g);
friend istream &operator<<(istream &i, GrafN &g);
GrafN operator+(GrafN &f );
GrafN operator=(GrafN f );
void BF(GrafN &g);
void DF(GrafN &g);
void comp_conex(GrafN g);
bool existenta_comp_conex(GrafN g);
};
GrafN GrafN:: operator+(GrafN &f){
if(f.n != this->n)
{
    cout<<"Grafurile nu au acelasi nr de noduri \n";
   /// break;
}
else{

GrafN h;
   // h = new GrafN() ;
//h();


    for(int i=1;i<=f.n;i++)
        {
          for(int j=1;j<=f.n;j++)
           {
            h.mat[i][j]=(this->mat[i][j]+f.mat[i][j]);
          ///  if((h.mat[i][j])==2)
           ///     h.mat[i][j]=1;
           }

        }
     }
     return h;
}





GrafN::GrafN(){
n=0;
m=0;
int i, j;
for(i=1;i<=n;i++)
{   viz[i]==0;
    for(j=1;j<=n;j++)
        mat[i][j]=0;
}


}

GrafN::GrafN(int x, int y, int v[20][20]){
n=x;
m=y;
int i, j;
for(i=1;i<=n;i++)
{   viz[i]==0;
    for(j=1;j<=n;j++)
        mat[i][j]=v[i][j];
}


}

istream &operator<<(istream &i, GrafN &g){

for(int j=1;j<=g.n;j++)
{
    for(int k=1;k<=g.n;k++)
    {if(g.mat[j][k]!=0)
        {i<<j;
        i<<" - ";
        i<<k;
        i<<" -> ";
        i<< g.mat[j][k];
        i<<"\n";}
    }
}


}

istream &operator>>(istream &i, GrafN &g){
int p, q, w
i>>g.m;
i>>g.n;
i>>g.s;
for(int k=1;k<=g.n;k++)
    i>>viz[k];
for(int j=0;i<g.m;i++)
      {
          i>>p;
          i>>q;
          i>>w;
          g.mat[p][q]=w;
          g.mat[q][p]=w;

      }

}

void GrafN::BF(){
int coada[20], u;
coada[1]=this->s;
void bf(int i){
    cout<<i<<" ";
    u=i;
    for(int j=1;j<=g.n;j++){
if(this->mat[coada[i][j]!=0&&this->viz[j]==0)
    poz=poz+1;
coada[poz]=j;
this->viz[j]=1;
    }
    if(i<=poz)
        bf(i+1);
}

bf(1);
cout<<"\n";
}
void GrafN::DF(){

void df(int x, this){
g.viz[x]=1;
cout<<x;
for(int i=1; i<=g.n;i++)
    if(this->mat[x][i]!=0 && this->viz[x]==0)
    df(i, g);
}
df(this->s, this);

cout<<"\n";

}

void GrafN:: comp_conex(){
this->BF();
///dc vectorul de vizitati nu e tot 1, atunci facem bf din 1, afisam nodurile prin care trecem
for(i=0;i<n;i++){

    if(this->v[i]==0)
    {
        cout<<"componenta conexa: ";
        this->BF();
    }

}



}

bool GrafN:: existenta_comp_conex(){

this->BF();
///dc vectorul de vizitati nu e tot 1, atunci facem bf din 1, afisam nodurile prin care trecem
for(int i=0;i<n;i++){

    if(this->viz[i]==0)
    {return 1;

}
return 0;
}

GrafN GrafN:: &operator=(GrafN f){
s=f.s;
n=f.n;
m=f.m;
for(int i=1;i<=n;i++)
{
    v[i]=f.v[i];
    for(int j=1;j<=n;j++)
        this->mat[i][j]=f.mat[i][j];
}



}



int main()
{
GrafN g[20];
int opt, n=5;
cout<<"cum doriti sa cititi datele? 1- tastatura; 2-fisier\n";
cin>>opt;
if(opt==1)
    for(int i=1;i<=n;i++)
    cin>>g[i];
else
for(int i=1;i<=n;i++)
fin>>g[i];


g[1]=g[2];
g[3]=g[2]+g[1];
g[2].BF();
g[3].DF();
g[1].comp_conex();
g[1].existenta_comp_conex();




cout<<"cum doriti sa afisati datele? 1- tastatura; 2-fisier\n";
cin>>opt;
if(opt==1)
for(int i=1;i<=n;i++)
    cout<<g[i];
else
for(int i=1;i<=n;i++)
fout<<g[i];


}
