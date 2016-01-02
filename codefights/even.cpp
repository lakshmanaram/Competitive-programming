#include <iostream>
using namespace std;
int evenSum(int n) {
    long long c = 0, a = 2,b,d = 0;
    while(true){
        for(b = 1;b<a;b = b<<1){
            d += a|b;
            d %= 1000000007;
            c++;
            cout<<a<<" "<<b<<" "<<c<<endl;
            if(c==n)
                return d;
        }
        a = a<<1;
    }
}
int main(){
	cout<<evenSum(10000);
}
