#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--) {
		long n,m,c;
		cin>>n>>m>>c;
		long ans = 0;
		for(long i=1; i<=n; i++){
			if(c%i ==0 && c/i <= m)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
