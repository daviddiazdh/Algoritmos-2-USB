#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() 
{   

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

vector <pair<int, int>> instancias;
vector <int> baneados;

unsigned i = 0;
int q = -1;

for(i = 0; i < lista.size(); i++){
    if(count(baneados.begin(), baneados.end(), i) == 0){
        q = q + 1;
        instancias.push_back({lista[i], 1});
        for(unsigned j = i + 1; j < lista.size(); j++){
            if(lista[i] == lista[j]){
                baneados.push_back(j);
                instancias[q].second += 1; 
            }
        }
    }
}

/*Bubble Sort*/
unsigned p = 0;
while(p < instancias.size()){
    for(unsigned i = instancias.size() - 1; i > 0; i--){
        if(instancias[i].second > instancias[i-1].second){
            iter_swap(instancias.begin() + i, instancias.begin() + i - 1);
        }
    }
    p += 1;
}

for(pair<int, int> i : instancias){
    
    int j = 0;
    while(j < i.second){
        cout << i.first << " ";
        j += 1;
    }
    
}

return 0;
}