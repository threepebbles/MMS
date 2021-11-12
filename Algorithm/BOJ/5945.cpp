// Treasure chest
// 카테고리: 구간 DP
// Time Complexity: O(n^2)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5002;
int n, A[2][MAXN];
int psum[MAXN];

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &A[0][i]);
        psum[i]=psum[i-1]+A[0][i];
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j+i<=n;j++) {
            A[i%2][j] = psum[j+i]-psum[j-1] 
                        - min(A[(i-1)%2][j], A[(i-1)%2][j+1]);
        }
    }
    printf("%d", A[(n-1)%2][1]);
    return 0;
}