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
    vector<ll> dp(sum+1,0);
    for(long i=1;i<dp.size();i++){
        dp[i] = -1;
        for(long j=1;j<=x.size();j++){
            if(i-x[j-1]>=0 && dp[i-x[j-1]]!=-1 && j-1>=dp[i-x[j-1]]){
                dp[i] = j;
                break;
            }
        }
    }
    for(long i=0;i<dp.size();i++){
        cout<<dp[i]<<endl;
    }
    return 0;
}
