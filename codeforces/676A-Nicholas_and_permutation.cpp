#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int mini,maxi;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1)
            mini = i;
        if(arr[i] == n)
            maxi = i;
    }
    int temp = min(mini,maxi);
    maxi = max(mini,maxi);
    mini = temp;
    cout<<max(n-1-mini,maxi);
}
