#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(long i=0;i<n;i++) cin>>arr[i];
    for(long i=0;i<n;i++) arr.push_back(arr[i]);
    long start = 0, end = -1;
    long ans = 0;
    long sum = 0;
    // cout<<start<<" "<<end<<" "<<arr.size()<<endl;
    while(end < (int)arr.size()){
        // cout<<start<<" "<<end<<endl;
        end++;
        sum += arr[end];
        while(sum > 180){
            sum -= arr[start];
            start++;
        }
        ans = max(ans,sum);
        // cout<<sum<<" "<<ans<<endl;
    }
    cout<<360-2*ans;
    return 0;
}