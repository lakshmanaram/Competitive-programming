#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > vis;
vector<string> arr;
bool ans = false;
int r2,c2;
void func(int a, int b){
	if(a == vis.size()||a==-1)
		return;
	if(b==-1 || b==vis[0].size())
		return;
	if(arr[a][b] == '.'){
		arr[a][b] = 'X';
		//vis[a][b] ++;
		func(a+1,b);
		if(ans)
			return;
		func(a-1,b);
		if(ans)
			return;
		func(a,b+1);
		if(ans)
			return;
		func(a,b-1);
	} else {
		if(a == r2 && b == c2){
			ans = true;
			return;
		}
		vis[a][b] ++;
		if(vis[a][b]>0)
			return;
		func(a+1,b);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> temp(m,0);
	vis.resize(n,temp);
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		arr.push_back(x);
	}
	int r1,c1;
	cin>>r1>>c1>>r2>>c2;
	r1--;
	c1--;
	r2--;
	c2--;
	arr[r1][c1] = '.';
	func(r1,c1);
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}