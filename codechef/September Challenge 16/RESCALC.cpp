#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		long maxval = -1;
		int maxind;
		for(int i=0;i<n;i++) {
			long x;
			cin>>x;
			vector<int> types(6,0);
			for(int j=0;j<x;j++) {
				int y;
				cin>>y;
				types[y-1]++;
			}
			sort(types.begin(),types.end());
			while(types.size()>=4){
				int y = types[0];
				for(int j=0;j<types.size();j++)
					types[j] -= y;
				if(types.size() == 4)
					x += y;
				else if(types.size()==5)
					x += 2*y;
				else if(types.size() == 6)
					x += 4*y;
				types.erase(types.begin()); 
			}
			if(x > maxval){
				maxval = x;
				maxind = i+1;
			} else if( x == maxval ){
				maxind = -1;
			}
		}
		if(maxind == -1)
			cout<<"tie"<<endl;
		else if(maxind == 1)
			cout<<"chef"<<endl;
		else
			cout<<maxind<<endl;

	}
	return 0;
}