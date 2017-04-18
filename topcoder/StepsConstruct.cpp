#include <bits/stdc++.h>
#define mp make_pair
#define pb push
using namespace std;
string construct(vector <string> board, long long y) {
	pair<int, char> x = make_pair(0,'.');
	vector<pair<int, char> > temp(board[0].size(),x);
	vector<vector<pair<int, char> > > arr(board.size(), temp);
	for(int i=0;i<board.size();i++) {
		for(int j=0;j<board[i].size();j++){ 
			if(board[i][j] == '#'){
				arr[i][j].first = -1;
				arr[i][j].second = '#';
			}
		}
	}
	if((board.size() + board[0].size()) %2 != y%2)
		return "";
	if(arr[0][0].first == -1)
		return "";
	vector<bool> temp1(board[0].size(),false);
	vector<vector<bool> > vis(board.size(),temp1);
	queue<pair<int,int> > q;
	q.pb(mp(0,0));
	vis[0][0] = true;
	while(q.size()!=0) {
		pair<int,int> h = q.front();
		q.pop();
		int i = h.first;
		int j = h.second;
		vis[i][j] = false;
		int k = i-1;
		if ( k >=0) {
			if (arr[k][j].first != -1)
				if (!(k == 0 &&  j==0))
					if (arr[k][j].first==0 || arr[k][j].first>1+arr[i][j].first) {
						arr[k][j].first = 1 + arr[i][j].first;
						arr[k][j].second = 'D';
						if(!vis[k][j]) {
							q.pb(mp(k,j));
							vis[k][j] = true;
						}
					}
				}
				k = i+1;
				if(k < board.size()) {
					if (arr[k][j].first != -1)
						if (!(k == 0 &&  j==0))
							if (arr[k][j].first==0 || arr[k][j].first>1+arr[i][j].first) {
								arr[k][j].first = 1 + arr[i][j].first;
								arr[k][j].second = 'U';
								if(!vis[k][j]) {
									q.pb(mp(k,j));
									vis[k][j] = true;
								}
							}
						}
						k = j-1;
						if ( k >=0) {
							if (arr[i][k].first != -1)
								if (!(k == 0 &&  i==0))
									if (arr[i][k].first==0 || arr[i][k].first>1+arr[i][j].first) {
										arr[i][k].first = 1 + arr[i][j].first;
										arr[i][k].second = 'R';
										if(!vis[i][k]) {
											q.pb(mp(i,k));
											vis[i][k] = true;
										}
									}
								}
								k = j+1;
								if(k < board[0].size()) {
									if (arr[i][k].first != -1)
										if (!(k == 0 &&  i==0))
											if (arr[i][k].first==0 || arr[i][k].first>1+arr[i][j].first) {
												arr[i][k].first = 1 + arr[i][j].first;
												arr[i][k].second = 'L';
												if(!vis[i][k]) {
													q.pb(mp(i,k));
													vis[i][k] = true;
												}
											}
										}
			/*
			queue<pair<int, int> > q1;
			while(q.size()) {
				cout<<q.front().first <<" "<<q.front().second<<endl;
				q1.push(q.front());
				q.pop();
			}
			cout<<"______________"<<endl;
			q = q1;
			*/
									}
									// for(int i = 0; i< board.size();i++) {
									// 	for(int j=0;j<board[0].size();j++) {
									// 		cout<<arr[i][j].second<<" ";
									// 	}
									// 	cout<<endl;
									// }
									string s = "";
									if(arr[board.size()-1][board[0].size()-1].first == 0)
										return s;
									else if(arr[board.size()-1][board[0].size()-1].first == -1)
										return s;
									else {
										int i = board.size()-1;
										int j = board[0].size()-1;
										char x = arr[i][j].second;
										while(x != '.') {
											s += x;
											switch(x) {
												case 'U':
												i--;
												break;
												case 'D':
												i++;
												break;
												case 'L':
												j--;
												break;
												case 'R':
												j++;
											}
											x = arr[i][j].second;
										}
			//cout<<"It's coming till here!! "<<i<<" "<<j;
										if(s.size() <=  y) {
											reverse(s.begin(),s.end());
											for(int i=0;i<s.size();i++){
												if(s[i] == 'U') s[i] = 'D';
												else if(s[i] == 'D') s[i] = 'U';
												else if(s[i] == 'L') s[i] = 'R';
												else if(s[i] == 'R') s[i] = 'L';
											}
											char last = s[s.size()-1];
											char neglast = last;
											if(neglast == 'U') neglast = 'D';
											else if(neglast == 'D') neglast = 'U';
											else if(neglast == 'L') neglast = 'R';
											else if(neglast == 'R') neglast = 'L';
											while(s.size()!=y){
												s += neglast;
												s += last;
											}
											return s;
										}
										else return "";
									}
								}


int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		long long k;
		cin>>n>>m>>k;
		vector<string> board(n);
		for(int i=0;i<n;i++) {
			cin>>board[i];
		}
		if(construct(board,k).size() > 0)
			cout<<"Possible\n";
		else
			cout<<"Impossible\n";
	}
	return 0;
}
