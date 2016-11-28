#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		string n;
		cin>>n;
		long ans = 0;
		for(long i=0;i<n.size();i++){
			if(n[i] == '<')
				n[i] = '>';
			else if (n[i] == '>'){
				n[i] = '<';
				if(i!=0 && n[i-1] == '>')
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}