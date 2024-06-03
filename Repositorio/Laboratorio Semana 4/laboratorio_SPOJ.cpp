#include <iostream>
#include <vector> 
#include <utility>

using namespace std;

vector<vector<uint64_t>> resta(vector<vector<uint64_t>> A, vector<vector<uint64_t>> B, uint32_t n){

    vector<vector<uint64_t>> C(n, vector<uint64_t>(n));

    uint32_t i = 0;
    uint32_t j;
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

vector<vector<uint64_t>> suma(vector<vector<uint64_t>> A, vector<vector<uint64_t>> B, uint32_t n){

    vector<vector<uint64_t>> C(n, vector<uint64_t>(n));

    uint32_t i = 0;
    uint32_t j;
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

vector<vector<uint64_t>> sub_matriz(vector<vector<uint64_t>> A, uint32_t min_x, uint32_t max_x, uint32_t min_y, uint32_t max_y, uint32_t n){

    vector<vector<uint64_t>> C(n, vector<uint64_t>(n));
    
    uint32_t i = min_x;
    uint32_t q = 0;
    uint32_t j;
    uint32_t k;
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

vector<vector<uint64_t>> mezclar_matriz(vector<vector<uint64_t>> A, vector<vector<uint64_t>> B, vector<vector<uint64_t>> C, vector<vector<uint64_t>> D, uint32_t n){

    vector<vector<uint64_t>> E(n, vector<uint64_t>(n));
    uint32_t i = 0;
    uint32_t q = 0;
    uint32_t j;
    uint32_t k;
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

vector<vector<uint64_t>> strassen(vector<vector<uint64_t>> A, vector<vector<uint64_t>> B, uint32_t n){

    if(n == 1){
        vector<vector<uint64_t>> C(n, vector<uint64_t>(n));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    } else {

        vector<vector<uint64_t>> A11 = sub_matriz(A, 0, n/2, 0, n/2, n/2); 
        vector<vector<uint64_t>> A12 = sub_matriz(A, 0, n/2, n/2, n, n/2); 
        vector<vector<uint64_t>> A21 = sub_matriz(A, n/2, n, 0, n/2, n/2); 
        vector<vector<uint64_t>> A22 = sub_matriz(A, n/2, n, n/2, n, n/2); 

        vector<vector<uint64_t>> B11 = sub_matriz(B, 0, n/2, 0, n/2, n/2); 
        vector<vector<uint64_t>> B12 = sub_matriz(B, 0, n/2, n/2, n, n/2); 
        vector<vector<uint64_t>> B21 = sub_matriz(B, n/2, n, 0, n/2, n/2); 
        vector<vector<uint64_t>> B22 = sub_matriz(B, n/2, n, n/2, n, n/2);
        
    
        vector<vector<uint64_t>> P1 = strassen(A11, resta(B12, B22, n/2), n/2);
        vector<vector<uint64_t>> P2 = strassen(suma(A11, A12, n/2), B22, n/2);
        vector<vector<uint64_t>> P3 = strassen(suma(A21, A22, n/2), B11, n/2);
        vector<vector<uint64_t>> P4 = strassen(A22, resta(B21, B11, n/2), n/2);
        vector<vector<uint64_t>> P5 = strassen(suma(A11, A22, n/2), suma(B11, B22, n/2), n/2);
        vector<vector<uint64_t>> P6 = strassen(resta(A12, A22, n/2), suma(B21, B22, n/2), n/2);
        vector<vector<uint64_t>> P7 = strassen(resta(A11, A21, n/2), suma(B11, B12, n/2), n/2);

        vector<vector<uint64_t>> C11 = suma(suma(P5, P6, n/2), resta(P4, P2, n/2), n/2);
        vector<vector<uint64_t>> C12 = suma(P1, P2, n/2);
        vector<vector<uint64_t>> C21 = suma(P3, P4, n/2);
        vector<vector<uint64_t>> C22 = resta(suma(P5, P1, n/2), suma(P3, P7, n/2), n/2);
        
        vector<vector<uint64_t>> C = mezclar_matriz(C11, C12, C21, C22, n);

        return C;

    }

} 

vector<vector<uint64_t>> build_strassen(vector<vector<uint64_t>> A, vector<vector<uint64_t>> B, uint32_t n){

    uint32_t i,j;

    if( n % 2 != 0){
        vector<vector<uint64_t>> Ac(n + 1, vector<uint64_t>(n + 1));  
        vector<vector<uint64_t>> Bc(n + 1, vector<uint64_t>(n + 1));
        

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

        vector<vector<uint64_t>> Cc = strassen(Ac, Bc, n + 1);
        
        vector<vector<uint64_t>> C(n, vector<uint64_t>(n));

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

        vector<vector<uint64_t>> C = strassen(A, B, n);

        return C;
    }

}

int main() 
{   
    uint32_t n, i, j, d1, p1, r1, r2, m1, d2, p2, m2;

    cin >> n >> p1 >> d1 >> r1 >> m1 >> p2 >> d2 >> r2 >> m2;
    
    vector<vector<uint64_t>> A(n, vector<uint64_t>(n));
    vector<vector<uint64_t>> B(n, vector<uint64_t>(n));
    vector<uint64_t> V(n);

    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j) {
            d1 = d1 * p1 + r1;
            d2 = d2 * p2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }

    vector<vector<uint64_t>> C = build_strassen(A, B, n);

    for (i=0; i<n; ++i) {
        V[i] = 0;
        for (j=0; j<n; ++j)
            V[i] ^= C[i][j];
    }

    for( uint64_t i : V){
        cout << i << " ";
    }

    return 0;

}
