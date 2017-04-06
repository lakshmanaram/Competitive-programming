#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int z=0, o=0;
		for(long i=0;i<n;i++)
			for(long j=0;j<n;j++){
				int a;
				cin>>a;
				if(a == 0)
					z++;
				else
					o++;
			}
		if(o == 0 || o == n)
			cout<<0<<endl;
		else {
			int x = sqrt(z);
			if(x*(x+1) > z)
				x--;
			cout<<n-x-1<<endl;
		}
	}
	return 0;
}