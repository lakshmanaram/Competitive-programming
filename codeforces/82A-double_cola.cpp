#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long num=0,numbef=0,i;
	for(i=1;;i*=2)
	{
		numbef=num;
		num+=5*i;
		if(num>=n)
			break;
	}
	cout<<"num-"<<num<<endl<<"numbef-"<<numbef<<endl;
	int a = (num-numbef)/5;
	cout<<"---"<<a<<endl<<"---"<<(int)((n-numbef-1)/a)<<endl;
	switch((int)((n-numbef-1)/a))
	{
		case 0:
			cout<<"Sheldon";
			break;
		case 1:
			cout<<"Leonard";
			break;
		case 2:
			cout<<"Penny";
			break;
		case 3:
			cout<<"Rajesh";
			break;
		case 4:
			cout<<"Howard";
	}
	
	return 0;
}