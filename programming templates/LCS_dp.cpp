#include <bits/stdc++.h>
using namespace std;
long lcs(string x, string y){
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
	return dp[x.size()][y.size()];
}

int main(){
	string x = "hello" ,y = "hola", z = "hey"; 
	cout<<"Length of the Longest Common Subsequence between the strings "<<x<<" and "<<y<<" is "<<lcs(x,y)<<endl;
	cout<<"Length of the Longest Common Subsequence between the strings "<<y<<" and "<<z<<" is "<<lcs(y,z)<<endl;
	cout<<"Length of the Longest Common Subsequence between the strings "<<z<<" and "<<x<<" is "<<lcs(z,x)<<endl;

	return 0;
}