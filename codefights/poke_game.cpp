#include <bits/stdc++.h>
using namespace std;
vector<int> num;
int main(){
	while(true){
    int n,m;
    cin>>n>>m;
    vector<int> num;
    long long ans[n+1][m+1],i,j,k;
    num.push_back(0);
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        num.push_back(x);
    }
    for(i=1;i<=n;i++){
        ans[i][0] = 1;
    }
    for(i=1;i<=num[1]&&i<=m;i++){
        ans[1][i] = 1;
    }
    for(;i<=m;i++){
        ans[1][i] = 0;
    }
    for(i=2;i<=n;i++){
        for(j=1;j<=m;j++){
            int v = 0;
            for(int k = j;j-k<=num[i]&&k>=0;k--){
                v += ans[i-1][k];
            }
            ans[i][j] = v;
        }
    }
    cout<<ans[n][m]<<endl;
}
    return 0;
}
