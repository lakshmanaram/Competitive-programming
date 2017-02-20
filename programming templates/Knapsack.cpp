// Knapsack problem and subset sum difference problem
#include <bits/stdc++.h>
using namespace std;
long knapsack(vector<long> arr, long long m) {
    long n = arr.size();
    vector<bool> temp(m+1);
    vector<vector<bool> > dp(n+1,temp);
    for (long i = 0; i <= n; i++)
        dp[i][0] = true;
    for (long i = 1; i <= m; i++)
        dp[0][i] = false;
    for (long i=1; i<=n; i++) {
        for (long j=1; j<=m; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j)
                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
        }
    }
    for (long j=m; j>=0; j--)
        if (dp[n][j] == true)
            return j;
}
double difference(vector<long> arr) {
    long n = arr.size();
    long long sum = accumulate(arr.begin(),arr.end(),0);
    vector<bool> temp(sum+1);
    vector<vector<bool> > dp(n+1,temp);
    for (long i = 0; i <= n; i++)
        dp[i][0] = true;
    for (long i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (long i=1; i<=n; i++) {
        for (long j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j)
                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
        }
    }
    for (long j=sum/2; j>=0; j--)
        if (dp[n][j] == true)
            return sum-2*j;
}
int main()
{
    int n;
    cin>>n;
    vector<long> arr(n);
    for(long i=0;i<n;i++) cin>>arr[i];
    long long m;
    cin>>m;
    cout<<knapsack(arr,m)<<endl;
    cout<<difference(arr)<<endl;
    return 0;
}
