#include<iostream>
using namespace std;
int main()
{
	int a[] = {4,7,44,47,74,77,447,477,444,777,744,747,774,474};
	int n;
	cin>>n;
	int i=0;
	for(;i<14;i++)
	{
		if(n%a[i]==0)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}