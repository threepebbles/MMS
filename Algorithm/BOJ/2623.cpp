#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000+1;

vector<int> G[MAXN];
int in_deg[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int x[2];
    for(int i=0, l;i<m;i++) {
        scanf("%d", &l);    // 1<=l<=n
        scanf("%d", &x[0]);
        for(int j=1;j<l;j++) {
            scanf("%d", &x[j&1]);
            G[x[(j-1)&1]].push_back(x[j&1]);
            in_deg[x[j&1]]++;
        }
    }

    queue<int> que;
    for(int i=1;i<=n;i++) {
        if(in_deg[i]==0) {
            que.push(i);
        }
    }

    vector<int> ans;
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        ans.push_back(cur);

        for (int nxt:G[cur]) {
            in_deg[nxt]--;
            if(in_deg[nxt]==0)
                que.push(nxt);
        }
    }

    if(ans.size()!=n) {
        puts("0");
        return 0;
    }

    for(int x: ans)
        printf("%d\n", x);
}