#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,q,t;
    cin>>n>>q;
    long long maxv = INT_MIN,minv = INT_MAX;
    while(n--){
        cin>>t;
        maxv = max(maxv,t);
        minv = min(minv,t);
    }
    while(q--){
        cin>>t;
        if(t>=minv && t<=maxv)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
