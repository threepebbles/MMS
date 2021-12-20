/* 
Category: Bruteforce
Time Complexity: O(n*m) // n*m*(8*2)*(26*26)
*/
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

int cnt_MOO(char c1, char c2) {
    int cnt=0;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(brd[i][j]==c1) { // M
                for(int d=0;d<8;d++) {
                    int O_cnt = 0;
                    for(int step=1;step<=2;step++) {
                        int nr = i+dr[d]*step;
                        int nc = j+dc[d]*step;
                        if(!is_in(nr, nc)) continue;
                        if(brd[nr][nc]==c2) // O
                            O_cnt++;
                    }
                    if(O_cnt==2) cnt++;
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

    int ans = 0;
    for(char c1='A';c1<='Z';c1++) {  // M
        if(c1=='M') continue;
        for(char c2='A';c2<='Z';c2++) {  // O
            if(c1==c2 || c2=='O') continue;
            ans = max(ans, cnt_MOO(c1, c2));
        }
    }
    
    printf("%d", ans);
}