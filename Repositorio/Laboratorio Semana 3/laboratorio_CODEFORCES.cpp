#include <iostream>
#include <vector> 
#include <utility>
#include <cmath>
#include <iterator>

using namespace std;

#define value first
#define position second

vector <pair<long long, int>> merge(vector<pair<long long, int>> U, vector<pair<long long, int>> V, vector<pair<long long, int>> T, int m, int n) {

    int i = 0;
    int j = 0;

    U.push_back({10000000001,U.size()});
    V.push_back({10000000001,U.size()});
    for(int k = 0; k < m + n; k++){
        
        if(U[i].first < V[j].first){
            T[k] = U[i];
            i += 1;
        } else {
            T[k] = V[j];
            j += 1;
        }
    }

    return T;

}

vector<pair<long long, int>> merge_sort(vector<pair<long long, int>> T, float n) {
    if( n == 1 ){
        return T;
    } else {
        vector<pair<long long, int>> U(T.begin(), T.begin() + floor( n / 2 ));
        
        vector<pair<long long, int>> V(T.begin() + floor( n / 2 ), T.end());

        U = merge_sort(U, floor( n / 2 ));
        V = merge_sort(V, ceil( n / 2 ));
        return merge(U, V, T, floor( n / 2 ), ceil( n / 2 ));
    }
}

using namespace std;

int main()
{
    vector<pair<long long, int>> C;
    vector<int> respuesta;
    int t, n;
    scanf("%d", &t);

    while (t > 0)
    {
        scanf("%d", &n);

        C.resize(n);
        respuesta.resize(n);

        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &C[j]);
            C[j].position = j;
        }

        C = merge_sort(C, n);

        long long suma = 0;
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == k)
            {
                suma += C[i].value;
                k++;
            }

            while (k < n && suma >= C[k].value)
            {
                suma += C[k].value;
                k++;
            }

            respuesta[C[i].position] = k - 1;
        }

        for (int j = 0; j < n; j++)
        {
            printf("%d ", respuesta[j]);
        }
        cout << endl;

        t -= 1;
    }

    return 0;
}
