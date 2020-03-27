#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
struct problema{
string name;
int time;
string satisfaccion;
}problemas[5];

class fontanero{
    public:
    int tiempo=0;
    vector<problema>trabajos;
};

class avido{
    public:
    void swap(problema *xp, problema *yp) 
{ 
    problema temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// An optimized version of Bubble Sort 
void ordenar(problema arr[], int n) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j].time > arr[j+1].time) 
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
void printArray(problema arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
    cout<<arr[i].name<< " tiempo:  "<<arr[i].time<<" ,";
    cout<<endl;
}
void jornada(fontanero f, problema problemas[]){
    for (int i=0;i<5;++i){
        if(f.tiempo-problemas[i].time<=10){
            problemas[i].satisfaccion="Satisfecho";
        }
        else if(f.tiempo-problemas[i].time>11 && f.tiempo-problemas[i].time<=20){
             problemas[i].satisfaccion="Regular";
        }
        else if(f.tiempo-problemas[i].time>21){
             problemas[i].satisfaccion="Insatisfecho";
        }
        f.tiempo+=problemas[i].time;
        f.trabajos.push_back(problemas[i]);

    }  
    cout<<"Jornada del día "<<endl;
    for(int i=0;i<f.trabajos.size();i++){

        cout<<"Trabajo: "<<f.trabajos[i].name<<", Satisfacción: "<<f.trabajos[i].satisfaccion<<endl;
    } 
} 

};


int main(){
    srand(time(NULL));
    avido a;
    fontanero f;
    problemas[0].name="baño";
    problemas[0].time= 5+rand() %(30 - 5);

    problemas[1].name="lavabo";
    problemas[1].time= 5+rand() %(30 - 5);

    problemas[2].name="regadera";
    problemas[2].time= 5+rand() %(30 - 5);

    problemas[3].name="lavadero";
    problemas[3].time= 5+rand() %(30 - 5);

    problemas[4].name="tubería";
    problemas[4].time= 5+rand() %(30 - 5);
    
    a.printArray(problemas,5);
    a.jornada(f,problemas); //comparacion sin el ordenamiento
    a.ordenar(problemas,5);
    a.printArray(problemas,5);
    a.jornada(f,problemas);
}
