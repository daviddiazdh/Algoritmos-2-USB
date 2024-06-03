#include <iostream>
#include <vector> 
#include <cmath>
#include <utility>

using namespace std;
vector<vector<int>> MAX_HEAPIFY(vector<vector<int>> A, int i, int n){
    int largest;
    int l = i*2 + 1; 
    int r = i*2 + 2;

    if(l < n && A[l][1] > A[i][1]){
        largest = l;
    } else if (l < n && A[l][1] == A[i][1] && A[l][2] < A[i][2]){
        largest = l;
    } else {
        largest = i;
    }

    if(r < n && A[r][1] > A[largest][1]){
        largest = r;
    } else if(r < n && A[r][1] == A[largest][1] && A[r][2] < A[largest][2]){
        largest = r;
    }

    if(largest != i){
        vector<int> temp;
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        A = MAX_HEAPIFY(A, largest, n);
    }

    return A;
}

vector<vector<int>> BUILD_MAX_HEAP(vector<vector<int>> A){
    float n = A.size();
    for(int i = floor(n/2) - 1; i >= 0; i--){
        A = MAX_HEAPIFY(A, i, n);
    }

    return A;
}

vector<vector<int>> HEAP_SORT(vector<vector<int>> A){

    A = BUILD_MAX_HEAP(A);
    int n = A.size();
    for(int i = n - 1; i >= 1; i--){
        vector<int> temp;
        temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        A = MAX_HEAPIFY(A, 0, i);
    }
    
    return A;
}

int main () {

    vector <int> lista;

    int tamano;
    int elementos;

    cin >> tamano >> elementos;

    int k = 0;
    while(k < tamano){
        int l;
        cin >> l;
        lista.push_back(l);
        k += 1; 
    }

    /*A partir de aca esta el codigo*/

    vector<vector<int>> instancias;
    vector<int> numeros;
    bool bandera;
    int conteo = 0;

    for(int i = 0; i < tamano; i++){
        bandera = 1;
        for(int j : numeros){
            if(lista[i] == j){
                bandera = 0;
            }
        }

        if(bandera == 1){
            numeros.push_back(lista[i]);
            instancias.push_back({lista[i], 0, conteo + 1});
            for(int j : lista){
                if(lista[i] == j){
                    instancias[conteo][1] += 1; 
                }
            }
            conteo += 1;
        }
    }

    /*HEAP SORT*/

    instancias = HEAP_SORT(instancias);

    for(int i = instancias.size() - 1; i >= 0; i--){
        
        int j = 0;
        while(j < instancias[i][1]){
            cout << instancias[i][0] << " ";
            j += 1;
        }
        
    }

    return 0;
}
