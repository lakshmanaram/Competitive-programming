#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long ans = 0;
		string a, b, c;
		cin>>a>>b>>c;
		long n;
		cin>>n;
		bool flag = false;
		for(long i=c.size()-1;i>=0;i--){
			if(c[i]=='1' && flag)
				ans++;
			else if(c[i] == '0')
				flag = true;
		}
		for(long i=b.size()-1;i>=0;i--){
			if(b[i]=='1' && flag)
				ans++;
			else if(b[i] == '0')
				flag = true;
		}
		if(flag){
			long long temp = 0;
			for(long i=b.size()-1;i>=0;i--){
				if(b[i]=='1')
					temp++;
			}
			ans += temp*(n-1);
		}
		for(long i=a.size()-1;i>=0;i--){
			if(a[i]=='1' && flag)
				ans++;
			else if(a[i] == '0')
				flag = true;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}