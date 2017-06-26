#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main (){ 

	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		printf("%ld\n",n);
		for(long i=0;i<n;i++) {
			printf("%ld\n",n);
			for(long r = 0; r<n;r++) {
				printf("%ld %ld %ld\n",r+1,(r+i)%n+1,(r+i+1)%n+1);
			}
		}
	}
	return 0;
}