#include<iostream>
using namespace std;
int main()
{
	long n;
	cin>>n;
	long f=0,th=0,tw=0,o=0;
	int temp;
	while(n--)
	{
		cin>>temp;
		if(temp==4)
			f++;
		else if(temp==3) th++;
		else if(temp==2) tw++;
		else o++;
	}
	long ans =f;
	if(o>=th)
	{
		ans+=th;
		o-=th;
	}
	else
	{
		o=0;
		ans+=th;
	}
	if(tw%2==0)
		ans+=tw/2;
	else
	{
		if(o>=2)
		{
			ans+=tw/2 + 1;
			o-=2;
		}
		else
		{
			ans+=tw/2 + 1;
			o=0;	
		}

	}
	if(o%4==0)
		ans+=o/4;
	else
		ans+=(o/4)+1;
	cout<<ans;
	return 0;
}