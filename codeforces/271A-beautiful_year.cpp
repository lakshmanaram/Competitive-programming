#include<iostream>
using namespace std;
bool dist(int a)
{
	bool ch[10];
	fill(ch,ch+10,false);
	while(a!=0)
	{
		if(ch[a%10]==true)
		{
			return false;
		}
		ch[a%10]=true;
		a/=10;
	}
	return true;
}
int main()
{
	int y,flag=0;
	cin>>y;
	do
	{
		y++;
	}while(!dist(y));
	cout<<y;
	return 0;
}