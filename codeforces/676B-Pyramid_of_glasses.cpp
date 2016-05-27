#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long t;
    cin>>n>>t;
    if(t>1023)
    t = 1024;
    int l = 0;
    vector<vector<long double> > ans(10);
    int answ = 0;
    if(n==1){
        ans[0].push_back((long double)t);
        if(t - 1 >= 0)
            answ++;
    }else{
        long double one = 1.0;
        while(l<n-1){
            if(l == 0){
                ans[l].push_back((long double)t);
            }
            for(int i=0;i<=ans[l].size();i++){
                if(ans[l][i] >= one){
                    answ++;
                    // cout<<"l = "<<l<<" i = "<<i<<endl;
                    long double surplus = ans[l][i]-one;
                    ans[l][i] = 1.0;
                    if(ans[l+1].size()>i)
                        ans[l+1][i] += surplus/2;
                    else
                        ans[l+1].push_back(surplus/2);
                    ans[l+1].push_back(surplus/2);
                }else{
                    if(ans[l+1].size()<=i)
                        ans[l+1].push_back(0);
                    ans[l+1].push_back(0);
                }
            }
            l++;
        }
        for(int j=0;j<ans[n-1].size();j++){
            if(ans[n-1][j] >= 1.0)
                answ++;
        }
    }
    cout<<answ;
    return 0;
}
