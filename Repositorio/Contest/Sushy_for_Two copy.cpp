#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> MAX_HEAPIFY(vector<int> A, int i, int n){
    int largest;
    int l = i*2 + 1; 
    int r = i*2 + 2;

    if(l < n && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
    }

    if(r < n && A[r] > A[largest]){
        largest = r;
    }

    if(largest != i){
        int temp;
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        A = MAX_HEAPIFY(A, largest, n);
    }

    return A;
}

vector<int> BUILD_MAX_HEAP(vector<int> A){
    float n = A.size();
    for(int i = floor(n/2) - 1; i >= 0; i--){
        A = MAX_HEAPIFY(A, i, n);
    }

    return A;
}

vector<int> HEAP_SORT(vector<int> A){

    A = BUILD_MAX_HEAP(A);
    int n = A.size();
    for(int i = n - 1; i >= 1; i--){
        int temp;
        temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        A = MAX_HEAPIFY(A, 0, i);
    }
    
    return A;
}


int main() 
{   
    int tamano;
    cin >> tamano;
    int iterador = tamano;

    vector<int> bandeja;
    vector<int> resp_posibles;

    int key = 0;
    int contador = 1;
    int key_contador = 0;
    while(iterador > 0){
        int i;
        cin >> i;
        bandeja.push_back(i);
        if(key == i){
            contador += 1;
        } else if ((key != 0 && key != i) || (i == tamano - 1)) {
            if(key_contador != 0 && contador >= key_contador){
                resp_posibles.push_back(key_contador);
                cout << key_contador << endl;
            } else if (key_contador != 0 && contador < key_contador)
            {
                resp_posibles.push_back(contador);
                cout << contador << endl;
            }
            key_contador = contador;
            contador = 1;
        }
        key = i;
        cout << "Key: " << key << endl;
        cout << "Contador: " << contador << endl;
        cout << "Key contador: " << key_contador << endl;
        iterador -= 1;
    }
    cout << "--Salimos-- " << contador << endl;

    cout << "Contador: " << contador << endl;
    cout << "Key contador: " << key_contador << endl;

    if(contador >= key_contador){
        resp_posibles.push_back(key_contador);
        cout << key_contador << endl;
    } else if (contador < key_contador)
    {
        resp_posibles.push_back(contador);
        cout << contador << endl;
    }

    cout << "Lista: " << endl;
    for(int i : resp_posibles){
        cout << i << endl;
    }

    resp_posibles = BUILD_MAX_HEAP(resp_posibles);

    cout << "Lista ordenada: " << endl;
    for(int i : resp_posibles){
        cout << i << endl;
    }
    
    cout << 2 * resp_posibles[0];


    return 0;
}