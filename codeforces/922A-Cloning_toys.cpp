#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x, y;
	cin>>x>>y;
	y--;
	x -= y;
	if( x < 0 || y < 0 || x&1){
		cout<<"No"<<endl;
	} else {
		if(y == 0 && x != 0){
			cout<<"No"<<endl;
		} else {
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}