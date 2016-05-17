#include<bits/stdc++.h>
using namespace std;
int main()
{
	int val;
	cout<<1<<endl;
	fflush(stdout);
	cout<<3<<" "<<1<<" "<<1<<" "<<2<<endl;
	fflush(stdout);
	cout<<3<<" "<<3<<" "<<4<<" "<<4<<endl;
	fflush(stdout);
	cin>>val;
	cout<<2<<endl;
	fflush(stdout);
	if(val == 0)
		cout<<5;
	else if(val == 1)
		cout<<2;
	else if(val == 2)
		cout<<1;
	else if(val == -1)
		cout<<3;
	else
		cout<<4;
	fflush(stdout);
	return 0;
}
