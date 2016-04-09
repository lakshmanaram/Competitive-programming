#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> a(n),b(n);
        for(long long i=0;i<n;i++)
            cin>>a[i];
        long long edge = 0;
        for(long long i=0;i<n;i++){
            cin>>b[i];
            if(abs(b[i])>abs(b[edge]))
                edge = i;
        }
        if(b[edge]>0)
            a[edge] += k;
        else
            a[edge] -= k;
        long long sum = 0;
        for(long long i=0;i<n;i++)
            sum+=a[i]*b[i];
        cout<<sum<<endl;
    }
    return 0;
}
