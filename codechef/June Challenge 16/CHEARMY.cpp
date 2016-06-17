#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,t;
    cin>>n;
    while(n--){
        cin>>t;
        t--;
        long long ans=0;
        long long p=2;
        while(t){
            ans += (t%5)*p;
            p *= 10;
            t /= 5;
        }
        cout<<ans<<endl;
    }
    return 0;
}
