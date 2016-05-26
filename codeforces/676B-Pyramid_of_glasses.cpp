#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long t;
    cin>>n>>t;
    int l = 0;
    vector<vector<double> > ans(10);
    if(n==1)
    ans[0].push_back((double)t);
    while(l<n-1){
        if(l == 0){
            ans[l].push_back((double)t);
        }
        double one = 1.0;
        for(int i=0;i<=ans[l].size();i++){
            if(ans[l][i] > one){
                double surplus = ans[l][i]-one;
                ans[l][i] = 1.0;
                if(ans[l+1].size()>i)
                ans[l+1][i] += surplus/2;
                else
                ans[l+1].push_back(surplus/2);
                ans[l+1].push_back(surplus/2);
            }
        }
        l++;
    }
    int answer = 0;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            if(ans[i][j] >= 1.0)
                answer++;
        }
    }
    cout<<answer;
    return 0;
}
