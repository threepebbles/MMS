#include <bits/stdc++.h>
using namespace std;

typedef struct E{
    int to, cost;
};

const int MAXN = 16;
const int INF = 1e9;

int G1[MAXN][MAXN], G2[MAXN][MAXN];
vector<int> cand1, cand2;


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            G1[i][j] = G2[i][j] = INF;
        }
    }

    int u, v, a, b;
    for(int i=0;i<m;i++) {
        scanf("%d %d %d %d", &u, &v, &a, &b);
        u--, v--;
        G1[u][v] = a;
        G2[u][v] = b;
    }

    int ans = INF;
    for(int i=1;i<(1<<n);i++) {
        if(!(i&1) || !((i>>(n-1))&1)) continue;
        
        u = 0, v = -1;
        int sum1 = 0, sum2 = 0;
        bool inv = false;
        for(int j=1;j<n;j++) {
            if((i>>j)&1) {
                v = j;
                if(G1[u][v]==INF) {
                    inv = true;
                    break;
                }
                else {
                    sum1 += G1[u][v];
                    sum2 += G2[u][v];
                }
                u = j;
            }
        }
        if(inv) continue;

        cand1.push_back(sum1);
        cand2.push_back(sum2);
    }
    sort(cand1.begin(), cand1.end());
    sort(cand2.begin(), cand2.end());
    for(int x: cand1) {
        int lbidx = lower_bound(cand2.begin(), cand2.end(), x)-cand2.begin();
        if(lbidx==cand2.size()) continue;
        if(x==cand2[lbidx]) {
            ans = x;
            break;
        }
    }

    if(ans==INF)
        puts("IMPOSSIBLE");
    else
        printf("%d", ans);
}