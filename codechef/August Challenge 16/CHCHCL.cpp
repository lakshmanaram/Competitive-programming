#include <bits/stdc++.h>
using namespace std;
int main(){
	long t;
	long long m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		if(m%2==0 || n%2 == 0){
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}
	return 0;
}