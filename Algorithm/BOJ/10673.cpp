#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct E{
    int to, fcnt;
    ll cost;
};

typedef struct V{
    int idx, fcnt;
    ll dis;
    bool operator<(const V& A) const {
        return dis==A.dis ? fcnt>A.fcnt : dis>A.dis;
    }
};

const int MAXROUTE = 101;
const int MAXCITY = 1001;
const ll INF = 2e18;

int cur_route[MAXROUTE];
vector<E> G[MAXCITY];
int fcnt[MAXCITY];  // # of individual flights
bool chk[MAXCITY];
ll dis[MAXCITY];


int main() {
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);
    
    ll cost;
    int k;
    for(int i=1;i<=N;i++) {
        scanf("%lld %d", &cost, &k);    // k<=100
        for(int j=0;j<k;j++) {
            scanf("%d", &cur_route[j]);
        }
        for(int j=0;j<k;j++) {
            for(int l=j+1;l<k;l++) {
                G[cur_route[j]].push_back({cur_route[l], l-j, cost});
            }
        }
    }

    for(int i=1;i<=MAXCITY;i++) {
        dis[i] = INF;
        fcnt[i] = 1e9;
    }
        
    priority_queue<V> pq;
    pq.push({A, 0, 0ll});
    dis[A] = 0, fcnt[A] = 0;

    while(!pq.empty()) {
        V cur_node = pq.top();
        pq.pop();
        chk[cur_node.idx] = true;

        for(E cur_edge: G[cur_node.idx]) {
            if(chk[cur_edge.to]) continue;
            
            if(cur_node.dis + cur_edge.cost < dis[cur_edge.to]) {
                fcnt[cur_edge.to] = cur_node.fcnt+cur_edge.fcnt;
                dis[cur_edge.to] = cur_node.dis + cur_edge.cost;
                pq.push({cur_edge.to, fcnt[cur_edge.to], dis[cur_edge.to]});
            }
            else if(cur_node.dis + cur_edge.cost == dis[cur_edge.to]) {
                if(cur_node.fcnt + cur_edge.fcnt < fcnt[cur_edge.to]) {
                    fcnt[cur_edge.to] = cur_node.fcnt + cur_edge.fcnt;
                    dis[cur_edge.to] = cur_node.dis + cur_edge.cost;
                    pq.push({cur_edge.to, fcnt[cur_edge.to], dis[cur_edge.to]});
                }
            }
        }
    }
    
    if(dis[B]==INF) {
        puts("-1 -1");
        return 0;
    }
    printf("%lld %d", dis[B], fcnt[B]);
}