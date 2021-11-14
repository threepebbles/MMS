#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+2;

int x[MAXN], y[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int maxd = 0;
    int sum = 0;
    for(int i=0;i<n-1;i++) {
        int diff12 = abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]);
        if(i<n-2) {
            int diff23 = abs(x[i+2]-x[i+1]) + abs(y[i+2]-y[i+1]);
            int diff13 = abs(x[i+2]-x[i]) + abs(y[i+2]-y[i]);
            int x = abs((diff12+diff23)-diff13);
            maxd = max(maxd, x);
        }
        sum += diff12;
    }
    printf("%d", sum-maxd);
}