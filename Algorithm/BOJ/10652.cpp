#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e4+1;
const int INF = 2e9;

int B,E,P,N,M;
vector<int> G[MAXN];
int Bdis[MAXN], Edis[MAXN], Pdis[MAXN];
bool chk[MAXN];

void bfs(int st, int dis[]) {
    memset(chk, 0, sizeof(chk));
    queue<int> Q;

    Q.push(st);  // Bessie:1, Elsie:2
    dis[st] = 0;

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if(chk[cur]) continue;
        chk[cur] = true;

        for(int nxt: G[cur]) {
            if(chk[nxt] || dis[nxt]!=-1) continue;
            dis[nxt] = dis[cur]+1;
            Q.push(nxt);
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &B, &E, &P, &N, &M);
    
    for(int i=0, u,v;i<M;i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    memset(Bdis, -1, sizeof(Bdis));
    memset(Edis, -1, sizeof(Edis));
    memset(Pdis, -1, sizeof(Pdis));
    bfs(1, Bdis);
    bfs(2, Edis);
    bfs(N, Pdis);

    int ans = INF;
    for(int i=1;i<=N;i++) {
        if(Bdis[i]==-1 || Edis[i]==-1 || Pdis[i]==-1) continue;
        
        ans = min({
            B*Bdis[i] + E*Edis[i] + P*Pdis[i],  // together
            B*(Bdis[i]+Pdis[i]) + E*(Edis[i]+Pdis[i]),   // separately
            ans
        });
    }
    printf("%d", ans);
}