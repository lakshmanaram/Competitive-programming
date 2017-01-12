#include <bits/stdc++.h>
using namespace std;
int main() {
	long t;
	cin>>t;
	string yes = "yes";
	string no = "no";
	while(t--) {
		int n,m;
		cin>>n>>m;
		vector<string> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		bool flag = true;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if (arr[i][j] == 'B'){
					if(i+1 < n && arr[i+1][j] == 'A')
						flag = false;
				} else if (arr[i][j] == 'W'){
					if(i!=0 && arr[i-1][j] == 'B')
						flag = false;
					if(i+1 < n && arr[i+1][j] == 'A')
						flag = false;
					if(j+1 == m || arr[i][j+1] == 'A')
						flag = false;
					if(j == 0 || arr[i][j-1] == 'A')
						flag = false;
				}
			}
		}
		if(flag)
			cout<<yes<<endl;
		else
			cout<<no<<endl;
	}
	return 0;
}
