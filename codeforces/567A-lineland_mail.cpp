#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<long long> lv;
	long long temp;
	long n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		lv.push_back(temp);
	}
	long long small = *(lv.begin());
	long long big = *(lv.end()-1);
	vector<long long>::iterator it;
	it = lv.begin();
	cout<<(*(it+1)-*it)<<" "<<big-*it<<endl;
	it++;
	while(it!=lv.end()-1)
	{
		long long temp1,temp2;
		temp1 = *(it+1)-*it;
		temp2 = *it-*(it-1);
		if(temp1<temp2)
			cout<<temp1<<" ";
		else
			cout<<temp2<<" ";
		temp1 = big - *it;
		temp2 = *it - small;
		if(temp1>temp2)
			cout<<temp1<<endl;
		else
			cout<<temp2<<endl;
		it++;
	}
	cout<<(*it-*(it-1))<<" "<<*it-small<<endl;
	return 0;
}