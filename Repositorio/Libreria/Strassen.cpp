#include <iostream>
#include <vector> 
#include <utility>
#include <iterator>

using namespace std;

vector<vector<int>> resta(vector<vector<int>> A, vector<vector<int>> B, int n){

    vector<vector<int>> C(n, vector<int>(n));

    int i = 0;
    int j;
    while(i < n){
        j = 0; 
        while(j < n){
            C[i][j] = A[i][j] - B[i][j];
            j += 1;
        }
        i += 1;
    }
    
    return C;
}

vector<vector<int>> suma(vector<vector<int>> A, vector<vector<int>> B, int n){

    vector<vector<int>> C(n, vector<int>(n));

    int i = 0;
    int j;
    while(i < n){
        j = 0; 
        while(j < n){
            C[i][j] = A[i][j] + B[i][j];
            j += 1;
        }
        i += 1;
    }
    
    return C;
}

vector<vector<int>> sub_matriz(vector<vector<int>> A, int min_x, int max_x, int min_y, int max_y, int n){

    vector<vector<int>> C(n, vector<int>(n));
    
    int i = min_x;
    int q = 0;
    int j;
    int k;
    while(i < max_x){
        j = min_y; 
        k = 0;
        while(j < max_y){
            C[q][k] = A[i][j];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }

    return C;
}

vector<vector<int>> mezclar_matriz(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> C, vector<vector<int>> D, int n){

    vector<vector<int>> E(n, vector<int>(n));
    int i = 0;
    int q = 0;
    int j;
    int k;
    while(i < n/2){
        j = 0; 
        k = 0;
        while(j < n/2){
            E[i][j] = A[q][k];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }

    i = 0;
    q = 0;
    while(i < n/2){
        j = n/2;
        k = 0; 
        while(j < n){
            E[i][j] = B[q][k];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }

    i = n/2;
    q = 0;
    while(i < n){
        j = 0;
        k = 0; 
        while(j < n/2){
            E[i][j] = C[q][k];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }

    i = n/2;
    q = 0;
    while(i < n){
        j = n/2;
        k = 0; 
        while(j < n){
            E[i][j] = D[q][k];
            j += 1;
            k += 1;
        }
        i += 1;
        q += 1;
    }

    return E;
}

vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B, int n){

    if(n == 1){
        vector<vector<int>> C(n, vector<int>(n));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    } else {

        vector<vector<int>> A11 = sub_matriz(A, 0, n/2, 0, n/2, n/2); 
        vector<vector<int>> A12 = sub_matriz(A, 0, n/2, n/2, n, n/2); 
        vector<vector<int>> A21 = sub_matriz(A, n/2, n, 0, n/2, n/2); 
        vector<vector<int>> A22 = sub_matriz(A, n/2, n, n/2, n, n/2); 

        vector<vector<int>> B11 = sub_matriz(B, 0, n/2, 0, n/2, n/2); 
        vector<vector<int>> B12 = sub_matriz(B, 0, n/2, n/2, n, n/2); 
        vector<vector<int>> B21 = sub_matriz(B, n/2, n, 0, n/2, n/2); 
        vector<vector<int>> B22 = sub_matriz(B, n/2, n, n/2, n, n/2);
        
    
        vector<vector<int>> P1 = strassen(A11, resta(B12, B22, n/2), n/2);
        vector<vector<int>> P2 = strassen(suma(A11, A12, n/2), B22, n/2);
        vector<vector<int>> P3 = strassen(suma(A21, A22, n/2), B11, n/2);
        vector<vector<int>> P4 = strassen(A22, resta(B21, B11, n/2), n/2);
        vector<vector<int>> P5 = strassen(suma(A11, A22, n/2), suma(B11, B22, n/2), n/2);
        vector<vector<int>> P6 = strassen(resta(A12, A22, n/2), suma(B21, B22, n/2), n/2);
        vector<vector<int>> P7 = strassen(resta(A11, A21, n/2), suma(B11, B12, n/2), n/2);

        vector<vector<int>> C11 = suma(suma(P5, P6, n/2), resta(P4, P2, n/2), n/2);
        vector<vector<int>> C12 = suma(P1, P2, n/2);
        vector<vector<int>> C21 = suma(P3, P4, n/2);
        vector<vector<int>> C22 = resta(suma(P5, P1, n/2), suma(P3, P7, n/2), n/2);
        
        vector<vector<int>> C = mezclar_matriz(C11, C12, C21, C22, n);

        return C;

    }

} 

vector<vector<int>> build_strassen(vector<vector<int>> A, vector<vector<int>> B, int n){

    int i,j;

    if( n % 2 != 0){
        vector<vector<int>> Ac(n + 1, vector<int>(n + 1));  
        vector<vector<int>> Bc(n + 1, vector<int>(n + 1));
        

        i = 0;
        while(i < n + 1){
            j = 0;
            while(j < n + 1){
                if(i != n){
                    if(j == n){
                        Ac[i][j] = 0;
                    } else {
                        Ac[i][j] = A[i][j];
                    }
                } else {
                    Ac[i][j] = 0;
                }
                j += 1;
            }
            i += 1;
        }

        i = 0;
        while(i < n + 1){
            j = 0;
            while(j < n + 1){
                if(i != n){
                    if(j == n){
                        Bc[i][j] = 0;
                    } else {
                        Bc[i][j] = B[i][j];
                    }
                } else {
                    Bc[i][j] = 0;
                }
                j += 1;
            }
            i += 1;
        }

        vector<vector<int>> Cc = strassen(Ac, Bc, n + 1);
        
        vector<vector<int>> C(n, vector<int>(n));

        i = 0;
        while(i < n){
            j = 0;
            while(j < n){
                C[i][j] = Cc[i][j];
                j += 1;
            }
            i += 1;
        }

        return C;
        
    } else {

        vector<vector<int>> C = strassen(A, B, n);

        return C;
    }

}

int main() 
{   
    vector<vector<int>> A = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    vector<vector<int>> B = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    vector<vector<int>> C = build_strassen(A,B,4);

    int i, j;
    i = 0;
    while(i < 4){
        j = 0;
        while(j < 4){
            cout << C[i][j] << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }
    

    


    return 0;

}