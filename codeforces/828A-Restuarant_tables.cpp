#include <bits/stdc++.h>
using namespace std;
int main(){
	long n,a,b;
	cin>>n>>a>>b;
	long va = 0;
	long long ans = 0;
	while(n--){
		int c;
		cin>>c;
		if(c == 2){
			if(b==0) ans+=2;
			else b--;
		} else {
			if(a == 0 && va == 0 && b == 0) ans++;
			else if(a==0 && b == 0){
				va--;
			} else if(a==0){
				b--;
				va++;
			} else {
				a--;
			}
		}
		// cout<<a<<" "<<b<<endl;
	}
	cout<<ans<<endl;
	return 0;

}