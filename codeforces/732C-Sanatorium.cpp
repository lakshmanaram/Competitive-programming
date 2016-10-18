#include <bits/stdc++.h>
using namespace std;
int main() {
	long long b,d,s;
	cin>>b>>d>>s;
	long long ans = 0;
	long long temp;
	//*before bf
	//after supper
	ans = max(max(b,d),s)*3 - (b+d+s); 
	//before supper
	temp = max(max((b-1),(d-1)),s)*3 - ((b-1)+(d-1)+s); 
	if(temp < ans && temp >= 0)
		ans = temp;
	// before lunch
	temp = max(max((b-1),d),s)*3 - ((b-1)+d+s); 
	if(temp < ans && temp >= 0)
		ans = temp;
	//*after bf
	temp = max(max(b,(d-1)),(s-1))*3 - (b+(d-1)+(s-1)); 
	if(temp < ans && temp >= 0)
		ans = temp;
	temp = max(max((b-1),(d-1)),(s-1))*3 - ((b-1)+(d-1)+(s-1)); 
	if(temp < ans && temp >= 0)
		ans = temp;
	temp = max(max((b-1),(d-2)),(s-1))*3 - ((b-1)+(d-2)+(s-1)); 
	if(temp < ans && temp >= 0)
		ans = temp;
	temp = max(max(b,d),(s-1))*3 - (b+d+(s-1)); 
	if(temp < ans && temp >= 0)
		ans = temp;
	temp = max(max((b-1),d),(s-1))*3 - ((b-1)+d+(s-1)); 
	if(temp < ans && temp >= 0)
		ans = temp;
	cout<<ans<<endl;
	return 0;
}