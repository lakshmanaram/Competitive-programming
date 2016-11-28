#include <bits/stdc++.h>
using namespace std;
bool barr[1000001];
long divisors[1000001];
vector<long> primes;
void markMultiples(int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n ) {
        barr[num] = true;
        divisors[num] = a;
        ++i;
    }
}
void SieveOfEratosthenes(int n)
{
    if (n >= 2) {
    	divisors[1] = 1;
        fill(barr,barr+1000001,false);
        for (int i=2; i<n; ++i)
            if ( barr[i] == false ){
            	primes.push_back(i);
            	divisors[i] = i;
                markMultiples(i, n);
            }
    }
}
int main(){
    SieveOfEratosthenes(1000001);
	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		long x;
		map<long,long> counts;
		for(long i=0;i<n;i++) {
			cin>>x;
			while(x!=1){
				long prev = divisors[x];
				x /= prev;
				if(divisors[x] != prev)
					counts[prev]++;
				else
					x /= prev;
			}
		}
		long long ans = 0;
		for(map<long,long>::iterator it = counts.begin();it!=counts.end();it++) {
			ans += min(it->second,n-it->second);
		}
		cout<<ans<<endl;
	}
	return 0;
}