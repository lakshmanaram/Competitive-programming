#include <bits/stdc++.h>
using namespace std;
bool arr[1000001];
void markMultiples(long a, long n)
{
    long i = 2, num;
    while ( (num = i*a) <= n ) {
        arr[num] = true;
        ++i;
    }
}
void SieveOfEratosthenes(long n)
{
    if (n >= 2) {
        fill(arr,arr+1000001,false);
        arr[0] = true;
        arr[1] = true;
        for (long i=2; i<n; ++i)
            if (!arr[i])
                markMultiples(i, n);
    }
}
bool isprime(long a)
{
    if(arr[a]==false)
        return true;
    return false;
}
int main() {
    SieveOfEratosthenes(1000001);
	long n;
	cin>>n;
    if( n == 1)
        cout<<3<<endl;
    else if(n&1)
		cout<<1<<endl;
	else{
		long i=1;
		for(i=1;i<=1000;i++)
			if(!isprime(i*n+1))
				break;
		cout<<i<<endl;
	}
	return 0;
}