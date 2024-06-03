#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() 
{   

vector<int> respuesta;

int cantidad;

cin >> cantidad;

int contador = 0;
while(contador < cantidad){

    vector <int> lista;

    int tamano; 
    cin >> tamano;

    int k = 0;
    
    while(k < tamano){
        int elemento;
        cin >> elemento;
        lista.push_back(elemento);
        k += 1;
    } 

    unsigned i = 0;

    while(i < lista.size()){

        for(unsigned j = lista.size() - 1; j > 0; j--){
            if(lista[j] < lista[j-1]){
                iter_swap(lista.begin() + j, lista.begin() + j - 1);
            }
        }
        i += 1;
    }

    i = lista.size() - 1; 
    int suma = 0;

    while(i > 0){

        suma += lista[i] - lista[i-1];
        i -= 1;

    }

    
    respuesta.push_back(suma);

    contador += 1;
}

for(int i : respuesta){
    cout << i << endl;
}


/*A partir de acá está el código*/

return 0;
}