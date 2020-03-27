#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
struct objeto
{

string name;
int peso;
int beneficio;
}objetos[4];

class mochila{
    public:
    int pesoactual;
    vector<objeto>elementos;
    const int pesomax=5;
};

class avido{
    public:

    void swap(objeto *xp, objeto *yp) 
{ 
    objeto temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// An optimized version of Bubble Sort 
void ordenar(objeto arr[], int n) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j].peso > arr[j+1].peso) 
        { 
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 
  
/* Function to print an array */
void printArray(objeto arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
    cout<<arr[i].name<< " peso:  "<<arr[i].peso<<" ,";
    cout<<endl;
} 
void llenarMochila(mochila m, objeto objetos[]){
     while(m.pesoactual<m.pesomax){
        for (int i=0; i<4;i++){
            if(m.pesoactual+objetos[i].peso<=m.pesomax){
                m.elementos.push_back(objetos[i]);
                m.pesoactual+=objetos[i].peso;
            }
            else{
                cout<<"\n Elementos en la mochila: "<<endl;
                for(int i=0;i<m.elementos.size();i++){
                cout<<m.elementos[i].name<<" peso: "<<m.elementos[i].peso<<" "<<endl;
                cout<<endl;
                }  
                return;
            }
        }

        }
        
    } 

          
};


int main(){
    srand(time(NULL));
    avido a;
    mochila m;
    bool flag;
    m.pesoactual=0;
    objetos[0].name="cuaderno";
    objetos[0].beneficio=rand() % 1 + 4;
    objetos[0].peso=1+rand() % (7-1);

    objetos[1].name="lapiz";
    objetos[1].beneficio=rand() % 1 + 4;
    objetos[1].peso=1+rand() % (7-1);

    objetos[2].name="pluma";
    objetos[2].beneficio=rand() % 1 + 4;
    objetos[2].peso= 1+ rand() % (7-1);

    objetos[3].name="Libro";
    objetos[3].beneficio=rand() % 1 + 4;
    objetos[3].peso=1+rand() %(7-1);
    a.printArray(objetos,4);
    a.ordenar(objetos,4);
    a.printArray(objetos,4); 
    a.llenarMochila(m,objetos);
}