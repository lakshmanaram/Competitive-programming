#include <bits/stdc++.h>
using namespace std;
vector<long long> factorial;
long long mod;
long long findfac(long long a){
    if(factorial.size() > a)
        return factorial[a];
    if(factorial.size() == 0)
        factorial.push_back(1);
    for(long long i = factorial.size(); i <= a;i++)
        factorial.push_back((factorial[i-1]*i)%mod);
    return factorial[a];
}
int main(){
    cout<<"Enter mod value: ";
    cin>>mod;
    while(true){
        cout<<"Enter value to find factorial \% mod: ";
        long long x;
        cin>>x;
        cout<<findfac(x)<<endl;
    }
    return 0;
}
