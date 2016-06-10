#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    x--;
    if(x>=n/2){
        x = n-x-1;
        reverse(a.begin(),a.end());
    }
    int ans = 0;
    if(a[x] == 1)
        ans++;
    for(int i=1;x-i>=0;i++){
        if(a[x-i]==a[x+i] && a[x-i]==1)
            ans += 2;
    }
    for(int i=x+x+1;i<n;i++){
        if(a[i])
            ans += 1;
    }
    cout<<ans;
    return 0;
}
