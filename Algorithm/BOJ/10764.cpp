#include <bits/stdc++.h>
using namespace std;

int n, m;
char brd[50][51];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool is_in(int r, int c) {
    if(r<0 || r>=n || c<0 || c>=m) return false;
    return true;
}

int cnt_MOO() {
    int cnt=0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(brd[i][j]=='M') {
                int suc = 0;
                for(int d=0;d<8;d++) {
                    for(int step=1;step<2;step++) {
                        int nr = i+dr[d]*step;
                        int nc = j+dc[d]*step;
                        if(!is_in(nr, nc)) continue;
                    }
                }
            }
            
        }
    }

    return cnt;
}


int main() {
    
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) {
        scanf("%s", brd[i]);
    }

    

}