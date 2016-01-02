#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    long i = 2;
    long m,n;
    cin>>m>>n;
    int ans = 0;
    while(i<=n){
        if(i%2==0)
            f.push_back(f[i/2]);
        else
            f.push_back(f[i/2]+1);
        if(i>=m)
            ans = max(ans,f[i]);
        i++;
    }
    cout<<ans;
return 0;
}
