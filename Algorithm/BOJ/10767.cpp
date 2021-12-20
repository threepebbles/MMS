#include <bits/stdc++.h>
using namespace std;

const int MAXN = 18;

int n;
char brd[MAXN][MAXN+1];
unordered_set<string> dict1[MAXN], dict2[MAXN], dict3;
string s;

void dfs1(int r, int c) {
    if(r+c==n-1) {
        dict1[r].insert(s+brd[r][c]);
        return;
    }

    s += brd[r][c];
    if(r+1<n)
        dfs1(r+1, c);
    if(c+1<n)
        dfs1(r, c+1);
    s.pop_back();
}

void dfs2(int r, int c) {
    if(r+c==n-1) {
        dict2[r].insert(s+brd[r][c]);
        return;
    }

    s += brd[r][c];
    if(r-1>=0)
        dfs2(r-1, c);
    if(c-1>=0)
        dfs2(r, c-1);
    s.pop_back();
}


int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%s", brd[i]);
    }
    // length of palindrome == 2*n-1
    // center : distance from the origin == n-1 == (i+j)
    s = "";
    dfs1(0, 0);
    s = "";
    dfs2(n-1, n-1);

    for(int r=0;r<n;r++) {
        for(auto s1: dict1[r]) {
            if(dict2[r].find(s1)!=dict2[r].end())
                dict3.insert(s1);
        }
    }
    
    printf("%d", dict3.size());
}