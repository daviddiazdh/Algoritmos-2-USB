#include <iostream>
#include <vector> 
#include <utility>
#include <cmath>
#include<iterator>

using namespace std;

vector<int> merge(vector<int> U, vector<int> V, vector<int> T, int m, int n) {

    int i = 0;
    int j = 0;

    U.push_back(100000);
    V.push_back(100000);
    for(int k = 0; k < m + n; k++){
        
        if(U[i] < V[j]){
            T[k] = U[i];
            i += 1;
        } else {
            T[k] = V[j];
            j += 1;
        }
    }
    cout << "-----------" << endl;
    cout << "Merge" << endl;
    unsigned l = 0;
    while(l < T.size() ){
        cout << T[l] << endl;
        l += 1;
    }

    return T;

}

vector<int> merge_sort(vector<int> T, float n) {
    if( n == 1 ){
        return T;
    } else {
        vector<int> U(T.begin(), T.begin() + floor( n / 2 ));

        cout << "-----" << endl;

        unsigned j = 0;
        while(j < U.size() ){
            cout << U[j] << endl;
            j += 1;
        }

        cout << "-----" << endl;

        vector<int> V(T.begin() + floor( n / 2 ), T.end());

        j = 0;
        while(j < V.size() ){
            cout << V[j] << endl;
            j += 1;
        }

        cout << "-----" << endl;

        U = merge_sort(U, floor( n / 2 ));
        V = merge_sort(V, ceil( n / 2 ));
        return merge(U, V, T, floor( n / 2 ), ceil( n / 2 ));
    }
}




int main()
{   

    vector<int> T = merge_sort({4,1,3,2,4,5,6}, 7);


    cout << "-------------" << endl; 

    unsigned j = 0;
    while(j < T.size() ){
        cout << T[j] << endl;
        j += 1;
    }

    cout << "-------------" << endl; 

    return 0;
}
