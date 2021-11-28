#include <bits/stdc++.h>
using namespace std;

typedef struct E{
    int to, cost;
};

typedef struct V{
    int idx, cost;
};

const int MAXN = 100;
const int INF = 1e9;

bool chk[MAXN][10001];  // chk[i][j]: checking taken time j from 1 to i
vector<E> G1[MAXN], G2[MAXN];
vector<int> cand1, cand2;


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int u, v, a, b; // a,b <= 100
    for(int i=0;i<m;i++) {
        scanf("%d %d %d %d", &u, &v, &a, &b);
        u--, v--;
        G1[u].push_back({v, a});
        G2[u].push_back({v, b});
    }

    queue<V> que;
    que.push({0, 0});
    chk[0][0] = true;
    while(!que.empty()) {
        V cur = que.front();
        que.pop();

        for(E e: G1[cur.idx]) {
            if(chk[e.to][e.cost+cur.cost]) continue;
            chk[e.to][e.cost+cur.cost] = true;
            que.push({e.to, e.cost+cur.cost});
        }
    }
    for(int i=0;i<=n*100;i++) {
        if(chk[n-1][i]) cand1.push_back(i);
    }

    memset(chk, 0, sizeof(chk));
    que.push({0, 0});
    chk[0][0] = true;
    while(!que.empty()) {
        V cur = que.front();
        que.pop();

        for(E e: G2[cur.idx]) {
            if(chk[e.to][e.cost+cur.cost]) continue;
            chk[e.to][e.cost+cur.cost] = true;
            que.push({e.to, e.cost+cur.cost});
        }
    }
    for(int i=0;i<=n*100;i++) {
        if(chk[n-1][i]) cand2.push_back(i);
    }

    int ans = INF;
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