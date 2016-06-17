#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,t;
    cin>>n;
    while(n--){
        cin>>t;
        if(t%6==0)
            cout<<"Misha"<<endl;
        else
            cout<<"Chef"<<endl;
    }
    return 0;
}
