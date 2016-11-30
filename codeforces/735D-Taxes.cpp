#include <iostream>
#include <cmath>
using namespace std;
bool isprime(long long n) {
    for(long long i=2;i*i<=n;i++) {
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    long long n;
    cin>>n;
    if(isprime(n))
        cout<<1<<endl;
    else {
        if(n%2 == 0)
            cout<<2<<endl;
        else if(isprime(n-2))
            cout<<2<<endl;
        else
            cout<<3<<endl;
    }
    
    return 0;
}
