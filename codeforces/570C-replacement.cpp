#include<bits/stdc++.h>
using namespace std;
int main()
{
	long m,n;
	cin>>m>>n;
	string a;
	cin>>a;
	long f=0,i,ans=0;
	for(i=0;i<m;i++)
	{
		if(a[i]=='.')
		{
			f=1;
			i++;
			while(a[i]=='.'&&i<m)
			{
				f++;
				i++;
			}
			ans+=f-1;
			f=0;
		}
	}
	while(n--)
	{
		int pos;
		char val;
		cin>>pos>>val;
		if(val=='.')
		{
			if(a[pos-1]!='.')
			{
				if(((pos-2)>=0) && (a[pos-2]=='.'))
					ans++;
				if((pos<m)&&(a[pos]=='.'))
					ans++;
			}
		}
		else
		{
			if(a[pos-1]=='.')
			{
				if(((pos-2)>=0) && (a[pos-2]=='.'))
					ans--;
				if((pos<m)&&(a[pos]=='.'))
					ans--;
			}
		}
		a[pos-1]=val;
		cout<<ans<<endl;
	}
	return 0;
}
