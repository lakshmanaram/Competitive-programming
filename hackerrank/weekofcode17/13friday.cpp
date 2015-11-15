#include<bits/stdc++.h>
using namespace std;
int nod(int i,int y)
{
	switch(i)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:		
		case 12:
		return 31;
		case  2:
		if(y%4==0)
		{
			if(y%100==0)
			if(y%400!=0)
				return 28;
			return 29;
		}
		return 28;
		default:
		return 30;
	}
}
int main()
{
	vector<vector<int> > months;
	int var =6;
	for(int i=0;i<400;i++)
	{
		vector<int> temp1;
		for(int j=1;j<=12;j++)
		{
			if(var==0)
				temp1.push_back(j);
			var = (var+nod(j,i))%7;
		}
		months.push_back(temp1);
	}
	
	int t,d1,d2,m1,m2,y1,y2;
	cin>>t;
	long long ans=0;
	vector<vector<int> >::iterator itm = months.begin();
	vector<int>:: iterator temp;
	while(t--)
	{
		ans=0;
	cin>>d1>>m1>>y1>>d2>>m2>>y2;
	if((y2-y1)/400>=1)
	{
		ans+=688*((y2-y1)/400);
	}
	y2%=400;
	y1%=400;
	if(y2<y1)
	{
		itm=months.begin()+y1;
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			if(m1<*temp)
				ans++;
			else if(m1==*temp)
			{
				if(d1<=13)
					ans++;
			}
			temp++;
		}
		itm++;
		while(itm<months.end()){
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			ans++;
			temp++;
		}
		itm++;
		}
		itm = months.begin();
		while(itm<months.begin()+y2){
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			ans++;
			temp++;
		}
		itm++;
		}
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			if(m2>*temp)
				ans++;
			else if(m2==*temp)
			{
				if(d2>=13)
					ans++;
			}
			temp++;
		}

	}
	else if(y2==y1)
	{
		itm=months.begin()+y1;
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			if(m1<*temp)
				ans++;
			else if(m1==*temp)
			{
				if(d1<=13)
					ans++;
			}
			if(m2<*temp)
				ans--;
			else if(m2==*temp)
			{
				if(d2<13)
					ans--;
			}
			temp++;
		}
	}
	else{
		itm=months.begin()+y1;
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			if(m1<*temp)
				ans++;
			else if(m1==*temp)
			{
				if(d1<=13)
					ans++;
			}
			temp++;
		}
		itm++;
		while(itm<months.begin()+y2){
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			ans++;
			temp++;
		}
		itm++;
		}
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			if(m2>*temp)
				ans++;
			else if(m2==*temp)
			{
				if(d2>=13)
					ans++;
			}
			temp++;
		}
	}
	cout<<ans;
	}
	/*	
	//int no=0;
	while(itm!=months.end())
	{
		//cout<<2000+itm-months.begin()<<" ";
		temp = (*itm).begin();
		while(temp != (*itm).end())
		{
			//cout<<*temp<<"  ";
			temp++;
			//no++;
		}
		//cout<<endl;
		itm++;
	}
	//cout<<no;
	*/
	return 0;
}