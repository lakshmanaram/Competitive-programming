#include <bits/stdc++.h>
using namespace std;

int t, N, M;

double dp[2222][2222];
bool vis[2222][2222];

double f(int n, int m) {
    if (n > M) return 1;
    if (vis[n][m]) return dp[n][m];
    vis[n][m] = 1;
    
    int tot = (N - n) + (M - m);
    
    dp[n][m] = (double) (N - n) / tot * f(n+1, m);
    if (m < M && n > m + 1) dp[n][m] += (double) (M - m) / tot * f(n, m+1);
    return dp[n][m];
}

int Main() {
    scanf ("%d %d", &N, &M);
    for (int i=0; i<=M; i++) for (int j=0; j<=M; j++) vis[i][j] = 0;
    
    printf ("%.8lf\n", f(0, 0));
    return 0;
}

int main() {
    int t;
    scanf ("%d", &t);
    for (int tc=0; tc<t; tc++) {
        printf ("Case #%d: ", tc+1);
        Main();
    }
    return 0;
}   