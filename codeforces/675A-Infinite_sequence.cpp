#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	bool flag = false;
	if(c!=0 && (b-a)%c==0){
		if(c>0){
			if(b>=a)
				flag = true;
		}else{
			if(b<=a)
				flag = true;
		}
	}else{
		if(a==b)
			flag = true;
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}
