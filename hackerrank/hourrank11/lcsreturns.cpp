#include <bits/stdc++.h>
using namespace std;
vector<vector<long> > lcs(string x, string y){
	long ans = 0;
	vector<long> temp(y.size()+1);
	vector<vector<long> > dp (x.size()+1, temp);
	for (long i=0; i<=x.size(); i++)
	{
		for (long j=0; j<=y.size(); j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (x[i-1] == y[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp;
}

int main(){
	string x,y;
	cin>>x>>y;
	vector<vector<long> > forward_dp = lcs(x,y), backward_dp;
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	backward_dp = lcs(x,y);
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	long lcsVal = forward_dp[x.size()][y.size()];
	long long ans = 0;
	for(int i=0; i<=x.size(); i++){
        set<char> possibilities;
		for(int j=1; j<=y.size(); j++){
			if(forward_dp[i][j-1]+backward_dp[x.size()-i][y.size()-j] == lcsVal){
				possibilities.insert(y[j-1]);
                //cout<<y[j-1]<<" can be inserted at position "<<i<<endl;
            }
		}
        ans += possibilities.size();
	}
	cout<<ans<<endl;
	return 0;
}