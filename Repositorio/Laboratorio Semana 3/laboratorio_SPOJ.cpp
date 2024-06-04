#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> merge(vector<int> U, vector<int> V, vector<int> T, int m, int n) {

    int i = 0;
    int j = 0;

    U.push_back({999999999});
    V.push_back({999999999});
    for(int k = 0; k < m + n; k++){
        
        if(U[i] < V[j]){
            T[k] = U[i];
            i += 1;
        } else {
            T[k] = V[j];
            j += 1;
        }
    }

    return T;

}

vector <int> merge_sort(vector<int> T, float n) {
    if( n == 1 ){
        return T;
    } else {
        vector<int> U(T.begin(), T.begin() + floor( n / 2 ));
        
        vector<int> V(T.begin() + floor( n / 2 ), T.end());

        U = merge_sort(U, floor( n / 2 ));
        V = merge_sort(V, ceil( n / 2 ));
        return merge(U, V, T, floor( n / 2 ), ceil( n / 2 ));
    }
}

bool posible_colocar_vacas(vector<int> V, int cantidad, int distancia){

    int n = V.size();
    int posicion = V[0];
    int conteo = 1;

    int i = 1;
    while(i < n){
        
        if(V[i] - posicion >= distancia){
            posicion = V[i];
            conteo += 1;
        } 

        if(conteo >= cantidad){
            return 1;
        }

        i += 1;
    }

    return 0;

}

int main()
{
    int casos;
    scanf("%d", &casos);

    while (casos > 0){
        
        int tamano;
        int cantidad; 
        scanf("%d %d", &tamano, &cantidad);

        vector <int> vacas(tamano);

        int i = 0;
        while( i < tamano){
            scanf("%d\n", &vacas[i]);
            i += 1;
        }
        
        vacas = merge_sort(vacas, tamano);

        int l = 1;
        int n = vacas.size();
        int r = vacas[n-1] - vacas[0];
        int medio;
        
        while( l <= r ){
            
            medio = floor(float(l+r) / 2);

            if(posible_colocar_vacas(vacas, cantidad, medio)){
                l = medio + 1;
            } else {
                r = medio - 1;
            }

        }

        printf("%d\n", r);

        casos -= 1;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> merge(vector<int> U, vector<int> V, vector<int> T, int m, int n) {

    int i = 0;
    int j = 0;

    U.push_back({999999999});
    V.push_back({999999999});
    for(int k = 0; k < m + n; k++){
        
        if(U[i] < V[j]){
            T[k] = U[i];
            i += 1;
        } else {
            T[k] = V[j];
            j += 1;
        }
    }

    return T;

}

vector <int> merge_sort(vector<int> T, float n) {
    if( n == 1 ){
        return T;
    } else {
        vector<int> U(T.begin(), T.begin() + floor( n / 2 ));
        
        vector<int> V(T.begin() + floor( n / 2 ), T.end());

        U = merge_sort(U, floor( n / 2 ));
        V = merge_sort(V, ceil( n / 2 ));
        return merge(U, V, T, floor( n / 2 ), ceil( n / 2 ));
    }
}

bool posible_colocar_vacas(vector<int> V, int cantidad, int distancia){

    int n = V.size();
    int posicion = V[0];
    int conteo = 1;

    int i = 1;
    while(i < n){
        
        if(V[i] - posicion >= distancia){
            posicion = V[i];
            conteo += 1;
        } 

        if(conteo >= cantidad){
            return 1;
        }

        i += 1;
    }

    return 0;

}

int main()
{
    int casos;
    scanf("%d", &casos);

    while (casos > 0){
        
        int tamano;
        int cantidad; 
        scanf("%d %d", &tamano, &cantidad);

        vector <int> vacas(tamano);

        int i = 0;
        while( i < tamano){
            scanf("%d\n", &vacas[i]);
            i += 1;
        }
        
        vacas = merge_sort(vacas, tamano);

        int l = 1;
        int n = vacas.size();
        int r = vacas[n-1] - vacas[0];
        int medio;
        
        while( l <= r ){
            
            medio = floor(float(l+r) / 2);

            if(posible_colocar_vacas(vacas, cantidad, medio)){
                l = medio + 1;
            } else {
                r = medio - 1;
            }

        }

        printf("%d\n", r);

        casos -= 1;
    }

    return 0;
}