#include<iostream>
using namespace std;
int HCF(int a,int b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a>b)
	{
		if(a%b==0)
			return b;
		else
			return HCF(a%b,b);
	}
	else
	{
		if(b%a==0)
			return a;
		else
			return HCF(a,b%a);
	}
}
int main()
{
	int a,b,n,ga,gb;
	cin>>a>>b>>n;
	do
	{
		ga=HCF(a,n);
		if(ga>n)
		{
			cout<<"1";
			break;
		}
		n=n-ga;
		gb=HCF(b,n);
		if(gb>n)
		{
			cout<<"0";
			break;
		}
		n=n-gb;
	}while(true);
	return 0;
}