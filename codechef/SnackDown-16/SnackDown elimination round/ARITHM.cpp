#include <bits/stdc++.h>
using namespace std;
int main(){
    long t;
    cin>>t;
    while(t--){
        long long n,c;
        cin>>n>>c;
        c *= 2;
        if(n==1){
            cout<<"Yes"<<endl;
        } else if(c%n!=0){
            cout<<"No"<<endl;
        } else {
            c /= n;
            n--;
            long long k = c%n;
            if(k%2!=0 && n%2 == 0){
                cout<<"No"<<endl;
            } else {
                if(k!=0 && k%2==0 && c>n){
                    cout<<"Yes"<<endl;
                } else if((k+n)%2==0 && c-k-n >= n){
                    cout<<"Yes"<<endl;
                } else if((k+2*n)%2==0 && c-k-2*n >= n){
                    cout<<"Yes"<<endl;
                } else {
                    cout<<"No"<<endl;
                }
            }
        }
    }
    return 0;
}
