#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vbl vector<bool>
using namespace std;
int main(){
    long n;
    cin>>n;
    vll x(n);
    ll sum = 0;
    for(long i=0;i<n;i++){
        cin>>x[i];
        sum += x[i];
    }
    sum++;
    sum /= 2;
    vbl temp(n+1,true);
    vector<vbl> dp(sum+1,temp);
    for(long i=1;i<dp.size();i++){
        dp[i][0] = false;
        for(long j=1;j<dp[i].size();j++){
            if(dp[i][j-1] || i-x[j-1]>=0 && dp[i-x[j-1]][j-1])
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }
    for(long i=0;i<dp.size();i++){
        if(dp[i][dp[i].size()-1])
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}
