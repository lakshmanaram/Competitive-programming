#include <bits/stdc++.h>
using namespace std;
long solve(vector<long> batons, vector<long> robots,long t, long n) {
	long ans = 0;
	if(batons.size() < robots.size())
		return 0;
	batons.insert(batons.end(),batons.begin(),batons.end());
	long j=0;
	while(t<n && j<(batons.size()/2)) {
		long i=0,k=j;
		for(;i<robots.size();i++) {
			bool flag = true;
			for(;k<2*batons.size();k++) {
				
			}
		}
	}
	return ans;
}
int main() {
	long n,m;
	cin>>n>>m;
	vector<long> batons;
	vector<bool> batonsActual;
	int x;
	for(long i=0;i<n;i++) {
		cin>>x;
		if(x==1)
			batonsActual.push_back(true);
		else 
			batonsActual.push_back(false);
	}
	vector<long> robots, robotsActual(m);
	for(long i=0;i<m;i++) {
		cin>>robotsActual[i];
	}
	sort(robotsActual.begin(),robotsActual.end());
	robots.push_back(n-robotsActual[m-1]+robotsActual[0]);
	for(long i=1;i<m;i++) {
		robots.push_back(robotsActual[i]-robotsActual[i-1]);
	}
	long long t;
	long lastposition = -1, initialposition;
	bool flag = true;
	for(long i=robotsActual[m-1];flag || (i!=robotsActual[m-1]);i=(i+1)%n) {
		flag = false;
		if(batonsActual[i]){
			if(lastposition == -1){
				initialposition = i;
				t = initialposition-robotsActual[m-1];
				lastposition = i;
			}
			else {
				if(i > lastposition)
					batons.push_back(i-lastposition);
				else
					batons.push_back(n+i-lastposition);
				lastposition = i;
			}
		}
	}
	if(lastposition > initialposition)
		batons.push_back(n+lastposition-initialposition);
	else
		batons.push_back(-lastposition+initialposition);
	cout<<solve(batons,robots,t,n);
	// for(long i=0;i<batons.size();i++) {
	// 	cout<<batons[i]<<" ";
	// }
	// cout<<endl;
	// for(long i=0;i<robots.size();i++) {
	// 	cout<<robots[i]<<" ";
	// }
	// cout<<endl;
	// cout<<t<<endl;
	return 0;
}
