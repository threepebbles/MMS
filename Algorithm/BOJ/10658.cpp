#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+1;
typedef pair<int, int> pii;
pii cow[MAXN];

int main() {
    int n,A,B;
    scanf("%d %d %d", &n, &A, &B);
    
    char is_spotted[3];
    for(int i=0, w, s;i<n;i++) {
        scanf("%s %d", is_spotted, &w);

        if(is_spotted[0]=='N') s = 0;
        else s = 1;

        cow[i] = {w, s};
    }
    sort(cow, cow+n);

    int L,R,M;
    int ans = 0;
    if(cow[0].second) {
        L = A;
        R = min(cow[0].first, B);
        if(L<=R) ans += R-L+1;
    }
    for(int i=0;i<n-1;i++) {
        if(cow[i].second && cow[i+1].second) {
            L = max(cow[i].first+1, A);
            R = min(cow[i+1].first, B);
            if(L<=R) ans += R-L+1;
        }
        else if(cow[i].second && !cow[i+1].second) {
            M = (cow[i].first+cow[i+1].first)/2;
            L = max(cow[i].first+1, A);
            R = min(M, B);
            if(L<=R) ans += R-L+1;
        }
        else if(!cow[i].second && cow[i+1].second) {
            M = (cow[i].first+cow[i+1].first+1)/2;
            L = max(M, A);
            R = min(cow[i+1].first, B);
            if(L<=R) ans += R-L+1;
        }
    }
    if(n>1 && cow[n-1].second) {
        L = max(cow[n-1].first+1, A);
        R = B;
        if(L<=R) ans += R-L+1;
    }

    printf("%d", ans);
    return 0;
}