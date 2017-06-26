#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main (){ 

	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		long b;
		cin>>b;
		long starno = (n+1)/2;
		if(n == 2) {
			if(b == 1)
				cout<<"YES\n1 2\n";
			else
				cout<<"NO\n";
			continue;
		}
		long chain = 2;
		chain += n-starno;
		if(chain/2 -1 < b)
			printf("NO\n");
		else {
			printf("YES\n");
			while(chain/2 -1 != b) {
				starno++;
				chain--;
			}
			starno -= 2;
			for(long i=1;i<chain;i++){
				printf("%ld %ld\n",i,i+1);
			}
			for(long i = chain+1;i<=n;i++) {
				printf("2 %ld\n",i);
			}
			// cout<<"starno = "<<starno<<endl;
			// cout<<"chain = "<<chain<<endl;
		}
	}
	return 0;
}