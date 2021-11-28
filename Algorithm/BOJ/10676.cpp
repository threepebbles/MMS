#include <bits/stdc++.h>
using namespace std;

typedef struct E{
    int u, v;
};

const int MAXCITY = 10001;
const int MAXROUTE = 501;
const int MAXK = 501;
const int INF = 1e9;
int cur_route[MAXK];
// dis1[i]: distance from A to i, dis2[i]: distance from i to B
int dis1[MAXCITY], dis2[MAXCITY];


int main() {
    int A,B,N;  // source, destination, # of routes
    scanf("%d %d %d", &A, &B, &N);

    int ans = INF;
    for(int i=1;i<MAXCITY;i++) {
        dis1[i] = dis2[i] = INF;
    }

    dis1[A] = dis2[B] = 0;
    for(int i=0, cost, k;i<N;i++) {
        scanf("%d %d", &cost, &k);
        for(int j=0;j<k;j++) {
            scanf("%d", &cur_route[j]);
        }

        for(int j=0, u, v;j<k;j++) {
            for(int l=j+1;l<k;l++) {
                u = cur_route[j], v = cur_route[l];
                
                if(u==A) {
                    dis1[v] = min(dis1[v], cost);
                }
                if(v==B) {
                    dis2[u] = min(dis2[u], cost);
                }
            }
        }
    }

    for(int i=1;i<MAXCITY;i++) {
        ans = min(ans, dis1[i]+dis2[i]);
    }

    printf("%d", ans == INF ? -1 : ans);
}