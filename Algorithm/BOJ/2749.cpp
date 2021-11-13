/*
Title:              피보나치 수 3
Category:           Matrix Multiplication
Time Complexity:    O(log(n))
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e6;

typedef struct M{
    ll mat[2][2];
    M() {
        memset(mat, 0, sizeof(mat));
    };

    M mul(M A, M B) {
        M C;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    C.mat[i][j] += A.mat[i][k]*B.mat[k][j]%MOD;
                    C.mat[i][j]%=MOD;
                }
            }
        }
        return C;
    }    
};

M mat_pow(M A, ll n) {
    M ret;
    ret.mat[0][0] = ret.mat[1][1] = 1;
    
    while(n) {
        if(n&1) {
            ret = ret.mul(ret, A);
        }
        A = A.mul(A, A);
        n>>=1;
    }
    return ret;
}

ll solve(M A, ll n) {
    M F = mat_pow(A, n);
    return F.mat[1][0];
}

int main() {
    ll n;
    scanf("%lld", &n);

    M A;
    A.mat[0][0] = A.mat[0][1] = A.mat[1][0] = 1;

    printf("%lld", solve(A, n));
}