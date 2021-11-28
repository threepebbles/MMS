#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
const int INF = 1e9;

vector<int> G[MAXN];
bool visited[MAXN];


int main() {
    int A,B,n;
    scanf("%d %d %d", &A, &B, &n);

    int ans = INF;
    for(int i=0;i<n;i++) {
        int c, k;
        scanf("%d %d", &c, &k);
        
        int node[2];
        scanf("%d", &node[0]);
        for(int j=1;j<k;j++) {
            scanf("%d", &node[j&1]);
            G[node[(j-1)&1]].push_back(node[j&1]);
        }

        queue<int> que;
        que.push(A);
        visited[A] = true;

        while(!que.empty()) {
            int cur_node = que.front();
            que.pop();
            
            for(int nxt_node: G[cur_node]) {
                if(visited[nxt_node]) continue;
                visited[nxt_node] = true;
                que.push(nxt_node);
            }
        }

        if(visited[B])
            ans = min(ans, c);
        
        for(int j=1;j<=MAXN;j++) {
            visited[j] = false;
            G[j].clear();
        }
    }
    printf("%d", ans==INF?-1:ans);
}