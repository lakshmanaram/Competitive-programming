#include <bits/stdc++.h>
using namespace std;
int main() {
	long t;
	cin>>t;
	while(t--) {
		long n;
		scanf("%ld",&n);
		long others = 0,minus=0,zeros =0,ones=0;
		long long x;
		for(long i=0;i<n;i++){
			scanf("%lld",&x);
			if(x==0)
				zeros++;
			else if(x==1)
				ones++;
			else if(x==-1)
				minus++;
			else 
				others++;
		}
		if((others>1)||(others==1)&&(minus>0))
			printf("no\n");
		else {
			if(minus>1 && ones==0){
				printf("no\n");
			} else
				printf("yes\n");
		}
	}
	return 0;
}
