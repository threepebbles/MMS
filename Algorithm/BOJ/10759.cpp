#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 500;
const ll mod = 1e9 + 7;

int n;
char brd[MAXN][MAXN+1];
ll dp[MAXN][MAXN], nxt_dp[MAXN][MAXN];


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", brd[i]);
    	
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	for (int dis = n - 1; dis >= 1; dis--) {
		int r1 = 0, c1 = dis - 1;
		while (c1 >= 0) {
			int r2 = n - 1 - dis + 1;
			int c2 = n - 1;

			while (r2 < n) {
                if (c1 > c2) break;
				if (brd[r1][c1] != brd[r2][c2]) {
					r2++, c2--;
					continue;
				}
				
				nxt_dp[r1][r2] += dp[r1][r2];
				if (r1 + 1 < n) nxt_dp[r1][r2] += dp[r1 + 1][r2];
				if (r2 - 1 >= 0) nxt_dp[r1][r2] += dp[r1][r2 - 1];

				if (r1 + 1 < n && r2 - 1 >= 0)
					nxt_dp[r1][r2] += dp[r1 + 1][r2 - 1];

				nxt_dp[r1][r2] %= mod;
				r2++, c2--;
			}

			r1++, c1--;
		}
        memcpy(dp, nxt_dp, sizeof(dp));
        memset(nxt_dp, 0, sizeof(nxt_dp));
	}
	printf("%lld", dp[0][n - 1]);
	return 0;
}