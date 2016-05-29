#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        vector<long long> a(n),b(n);
        long long pa = 0;
        for(long i=0;i<n;i++){
            cin>>a[i];
        }
        for(long i=0;i<n;i++){
            cin>>b[i];
        }
        long ans = 0;
        for(long i=0;i<n;i++){
            if(a[i]-pa >= b[i])
                ans++;
            pa = a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
