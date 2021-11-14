#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 51;
// 가로세로 글자는 3글자 이상
int n, m;
char brd[MAXN][MAXN];


bool chk_horizontal(int r, int c) {
    if(c>0 && brd[r][c-1]=='.') return false;
    if(c+2>=m) return false;

    if(brd[r][c+1]==brd[r][c+2] && brd[r][c+1]=='.')
        return true;
    return false;
}

bool chk_vertical(int r, int c) {
    if(r>0 && brd[r-1][c]=='.') return false;
    if(r+2>=n) return false;

    if(brd[r+1][c]==brd[r+2][c] && brd[r+1][c]=='.')
        return true;
    return false;
}

int main() {
    
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) {
        scanf("%s", brd[i]);
    }

    vector<pii> ans;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(brd[i][j]=='#') continue;

            if(chk_horizontal(i, j) || chk_vertical(i, j)) {
                ans.push_back({i, j});
            }
        }
    }
    printf("%d\n", ans.size());
    for(pii crd: ans) {
        printf("%d %d\n", crd.first+1, crd.second+1);
    }
}