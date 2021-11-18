/*
File Merge
Category: Knuth Optimization

C[i][j]: 구간 [i,j]의 누적합
dp[i][j]: 구간 [i,j]를 합치는 최소 비용 
1) dp[i][j] = min_{i<=k<j} (dp[i][k]+dp[k+1][j]) + C[i][j]
dp[i+1][j] = min_{i+1<=k<j} (dp[i+1][k]+dp[k+1][j]) + C[i+1][j]
-> dp[i+1][j] = D[i][j], C[i+1][j] = C'[i][j]
D[i][j] = min_{i<k<j} (D[i][k]+D[k][j]) + C'[i][j]

2) Quadrangle Inequalty
C'[a][c]+C'[b][d] <= C'[a][d] + C'[b][c], a<=b<=c<=d

3) Monotonicity
C'[b][c]<=C'[a][d], a<=b<=c<=d
A[i][j]: D[i][j]가 최소가 되기 위한 k(i<k<j)

Therefore, A[i][j-1] <= A[i][j] <= A[i+1][j]

Time Complexity: O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
const int INF = 1e9;
int n, C[MAXN], psum[MAXN];
int A[MAXN][MAXN], D[MAXN][MAXN];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        
        scanf("%d", &n);
        memset(psum, 0, sizeof(psum));
        memset(D, -1, sizeof(D));


        for(int i=1;i<=n;i++){
            scanf("%d", &C[i]);
            psum[i] = psum[i-1]+C[i];
            D[i-1][i] = 0;  // == dp[i][i]
            A[i-1][i] = i;
        }

        for(int d=2;d<=n;d++) {
            for(int i=0;i+d<=n;i++) {
                int j = i+d;
                // dp[i+1][j] == D[i][j]
                D[i][j] = INF;  // i-1 ~ j

                for (int k=A[i][j-1]; k<=A[i+1][j]; k++) {
                    int cur_cost = D[i][k]+D[k][j] + psum[j]-psum[i];
                    if(cur_cost<D[i][j]) {
                        D[i][j] = cur_cost;
                        A[i][j] = k;
                    }
                }
            }
        }
        printf("%d\n", D[0][n]);
    }
}