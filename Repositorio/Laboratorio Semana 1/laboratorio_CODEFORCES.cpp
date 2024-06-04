#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{   

vector <int> vectorito;
vector<int> respuestas;

int cantidad; 
cin >> cantidad;

int contador = 0;
while(contador < cantidad){

    int tamano; 
    int cambio;
    cin >> tamano >> cambio;

    int k = 0;
    
    while(k < tamano){
        int elemento;
        cin >> elemento;
        vectorito.push_back(elemento);
        k += 1;
    } 

    int d = 0;

    vector <int> borrar;
    vector <int> borrar_temp;
    int respuesta = tamano;

    int i = 0;

    while(i < tamano){
        
        if((count(borrar.begin(), borrar.end(), i)) == 0){
            
            int c = 1;

            if(c + d == cambio){

                borrar.push_back(i);
                respuesta = respuesta - 1;

                d = cambio - 1;
                i = -1;

            } else{
                int j = i + 1;

                borrar_temp.push_back(i);

                while(j < tamano){
                    
                    if(vectorito[j] == vectorito[i] and count(borrar.begin(), borrar.end(), j) == 0){
                
                        c = c + 1; 
                        borrar_temp.push_back(j);

                    }
                    j = j + 1; 

                    if (c + d == cambio){

                        d = cambio - 1;
                        respuesta = respuesta - 1;
                        for(int k : borrar_temp){
                            borrar.push_back(k);
                        }

                        i = -1;
                        break;
                    }
                }
        
                borrar_temp.clear();
            }

        }

        i = i + 1;
    }

    respuestas.push_back(respuesta);

    borrar.clear();
    vectorito.clear();

    contador += 1;

}

for( int i : respuestas){
    cout << i << endl;
}

return 0;
}