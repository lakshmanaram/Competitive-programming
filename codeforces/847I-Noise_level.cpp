#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	int n,m;
	long q, p;
	cin>>n>>m>>q>>p;
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<long long> temp(m, 0);
	vector<vector<long long> > sound(n, temp);
	vector<bool> temp_bool(m,false);
	vector<vector<bool> > vis(n, temp_bool);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == '*'|| arr[i][j]=='.') continue;
			vector<pair<int, int> > checking_out;
			queue<pair<pair<int,int>, long long> > bfsq;
			bfsq.push(mp(mp(i,j),q*(arr[i][j]-'A'+1)));
			vis[i][j] = true;
			checking_out.pb(mp(i,j));
			while(!bfsq.empty()){
				int i1 = bfsq.front().first.first;
				int j1 = bfsq.front().first.second;
				long long val = bfsq.front().second;
				bfsq.pop();
				if(arr[i1][j1] == '*'||val == 0) continue;
				sound[i1][j1] += val;
				for(int i2 = i1-1; i2 <= i1+1; i2+=2){
					if(i2 < 0 || i2 >= n) continue;
					if(vis[i2][j1]) continue;
					vis[i2][j1] = true;
					checking_out.pb(mp(i2,j1));
					bfsq.push(mp(mp(i2,j1), val/2));
				}
				for(int j2 = j1-1; j2 <= j1+1; j2+=2){
					if(j2 < 0 || j2 >= m) continue;
					if(vis[i1][j2]) continue;
					vis[i1][j2] = true;
					checking_out.pb(mp(i1,j2));
					bfsq.push(mp(mp(i1,j2), val/2));
				}
			}
			for(int i=0;i<checking_out.size();i++)
				vis[checking_out[i].first][checking_out[i].second] = false;
			// for(int i3=0;i3<n;i3++){
			// 	for(int j3=0;j3<m;j3++){
			// 		cout<<sound[i3][j3]<<" ";
			// 	}
			// 	cout<<endl;
			// }
		}
	}
	long count = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(sound[i][j] > p)
				count++;
		}
	}
	cout<<count;
	return 0;
}