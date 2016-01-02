//contest 606 B codeforces
#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,n,x,y;
	cin>>m>>n>>x>>y;
	string s;
	cin>>s;
	int i;
	bool check[m][n];
	for(i=0;i<m;i++){
		for(int j=0;j<n;j++){
			check[i][j] = false;
		}
	}
	x--;
	y--;
	long ans = 1;
	cout<<1<<" ";
	check[x][y] = true;
	for(i=0;i<s.size();i++){
		if(i==s.size()-1){
			if(m*n>ans)
				cout<<m*n-ans;
			else
				cout<<0;	
			break;
		}
		switch(s[i]){
			case 'R':
				y++;
				if (y>=n)
					y--;
				break;
			case 'L':
				y--;
				if (y<0)
					y++;
				break;
			case 'U':
				x--;
				if(x<0)
					x++;
				break;
			case 'D':
				x++;
				if(x>=m)
					x--;
		}
		if(check[x][y]==false){
			check[x][y] = true;
			cout<<1<<" ";
			ans++;
		}
		else{
			cout<<0<<" ";
		}
	}
	return 0;
}
