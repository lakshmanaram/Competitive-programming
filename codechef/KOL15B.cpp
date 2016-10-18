#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		vector<long long> temp2(m);
		vector<vector<long long> > arr(n,temp2),leftright,topdown,temp,temp1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>arr[i][j];
			}
		}
		temp = temp1 = topdown = leftright = arr;
		for(int i=0;i<n;i++) {
			for(int j=1;j<m;j++) {
				temp[i][j] = min(temp[i][j],temp[i][j]+temp[i][j-1]);
			}
		}

		for(int i=0;i<n;i++) {
			for(int j=m-2;j>=0;j--) {
				temp1[i][j] = min(temp1[i][j],temp1[i][j]+temp1[i][j+1]);
			}
		}

		for(int i=0;i<n;i++) {
			for(int j=m-1;j>=0;j--) {
				topdown[i][j] = temp[i][j] + temp1[i][j] - arr[i][j];
			}
		}		
		temp = temp1 = arr;
		for(int j=0;j<m;j++) {
			for(int i=1;i<n;i++) {
				temp[i][j] = min(temp[i][j],temp[i][j]+temp[i-1][j]);
			}
		}	
		for(int j=0;j<m;j++) {
			for(int i=n-2;i>=0;i--) {
				temp1[i][j] = min(temp1[i][j],temp1[i][j]+temp1[i+1][j]);
			}
		}	
		for(int j=0;j<m;j++) {
			for(int i=0;i<n;i++) {
				leftright[i][j] = temp[i][j] + temp1[i][j] - arr[i][j];
			}
		}
		long long minval = topdown[0][0]+leftright[0][0]-arr[0][0];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				minval = min(minval,leftright[i][j]+topdown[i][j]-arr[i][j]);
			}
		}
		cout<<minval<<endl;
	}

	return 0;
}