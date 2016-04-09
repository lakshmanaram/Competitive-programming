#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
	int r1 = 0,r2 = 0;
	long ans = 0;
	int m,n;
	cin>>m>>n;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(r1==0){
			r1 = b;
			ans += abs(b-a);
		}else{
			if(a == r1){
				r1 = b;
				ans += abs(b-a);
			}else if(r2 == 0){
				r2 = b;
				ans += abs(b-a);
			}else{
				if(abs(r1 - a)<abs(r2-a)){
					ans += abs(r1-a) + abs(b-a);
					r1 = b;
				}else{
					ans += abs(r2 - a) + abs(b-a);
					r2  = b;
				}
			}
		}
		cout<<"--"<<ans<<endl;
	}
	cout<<ans<<endl;
}

return 0;
}
