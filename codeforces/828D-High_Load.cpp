#include <bits/stdc++.h>
using namespace std;
int main(){
	long n,k;
	cin>>n>>k;
	if(k == 2){
		printf("%ld\n",n-1);
		for(long i=1;i<n;i++)
			printf("%ld %ld\n",i,i+1);
	} else if(n%k == 1){
		printf("%ld\n",2*(n/k));
		long n1=n-1;
		for(long i=1;i<=n1;i++){
			printf("%ld %ld\n",i,min(i+k,n));
		}
	} else if(n%k == 2){
		printf("%ld\n",2*(n/k)+1);
		long n1=n-3;
		for(long i=1;i<=n1;i++){
			printf("%ld %ld\n",i,min(i+k,n-1));
		}
		printf("%ld %ld\n",n-2,n);
		printf("%ld %ld\n",n-1,n);
	} else {
		printf("%ld\n",2*((n-1)/k)+2);
		long n1=n-1;
		n1 = k*(n1/k);
		for(long i=1;i<=n1;i++){
			printf("%ld %ld\n",i,min(i+k,n-1));
		}
		for(long i=n1+1;i<n;i++){
			printf("%ld %ld\n",i,n);
		}
	}
	return 0;
}