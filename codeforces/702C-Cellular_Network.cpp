#include <bits/stdc++.h>
using namespace std;
int main(){
	long n,m;
	cin>>n>>m;
	vector<long long> cities(n), cns(m);
	for(long i=0;i<n;i++){
		cin>>cities[i];
	}	
	for(long i=0;i<m;i++){
		cin>>cns[i];
	}	
	sort(cities.begin(),cities.end());
	sort(cns.begin(),cns.end());
	long long maxv = 0, cnsp = 0;
	long i;
	for(i=0;i<n && cnsp <m;i++){
		long long minv;
		minv = abs(cities[i] - cns[cnsp]);
		while(cities[i] >= cns[cnsp] && cnsp < m){
			minv = min(abs(cities[i] - cns[cnsp]), minv);
			//cout<<"----"<<cns[cnsp]<<" "<<minv<<endl;
			cnsp++;
		}
		if(cnsp < m){
			minv = min(abs(cities[i] - cns[cnsp]), minv);
		}
		cnsp--;
		if(cnsp<0)
			cnsp = 0;
		maxv = max(maxv,minv);
		// cout<<cities[i]<<" "<<minv<<endl;
	}
	if(i!=n)
		maxv = max(maxv, abs(cities[cities.size()-1] - cns[cns.size()-1]));
	cout<<maxv;
}