#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,p;
	cin>>n>>p;
	vector<vector<long long> > arr;
	set<pair<long long, pair<int,int> > > complexarr;
	for(int i=0;i<n;i++){
		vector<long long> temp(n);
		for(int j=0;j<n;j++){
			cin>>temp[j];
			complexarr.insert(make_pair(temp[j],make_pair(i,j)));
		}
		arr.push_back(temp);
	}
	/*
	set<int> ansx,ansy;
	set<pair<long long, pair<int,int> > >::iterator sit = complexarr.end();
	sit--;
	while(true){
		pair<int,int> t = (*sit).second;
		if(t.first!=0 && ansx.size() < p-1)
			ansx.insert(t.first);
		if(t.first!=n-1 && ansx.size() < p-1)
			ansx.insert(t.first+1);
		if(t.second!=0 && ansy.size() < p-1)
			ansy.insert(t.second);
		if(t.second!=n-1 && ansy.size() < p-1)
			ansy.insert(t.second+1);
		if((ansx.size()==(p-1) && ansy.size() == (p-1))||sit == complexarr.begin())
			break;
		sit--;
	}
	set<int>::iterator a;
	for(a=ansx.begin();a!=ansx.end();a++)
		cout<<*a<<" ";
	cout<<endl;
	for(a=ansy.begin();a!=ansy.end();a++)
		cout<<*a<<" ";
	*/
	vector<int> ansx,ansy;
	for(int i=1;i<n;i++){
		ansx.push_back(i);
		ansy.push_back(i);
	}
	srand(time(NULL));
	while(ansx.size()!=(p-1)){
		int index = rand()%ansx.size();
		ansx.erase(ansx.begin()+index);
		index = rand()%ansy.size();
		ansy.erase(ansy.begin()+index);
	}
	for(int i=0;i<ansx.size();i++)
		cout<<ansx[i]<<" ";
	cout<<endl;
	for(int i=0;i<ansy.size();i++)
		cout<<ansy[i]<<" ";
	return 0;
}