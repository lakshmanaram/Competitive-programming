#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vbl vector<bool>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> topdown,leftright;
        int x;
        char ch;
        ll tdsum = 0,lrsum = 0, tdsafesum = 0, lrsafesum = 0;
        bool tdlr = true;
        for(int i=0;i<n;i++){
            cin>>x;
            if(tdlr){
                topdown.push_back(x);
                tdlr = false;
                tdsum += x;
            } else {
                leftright.push_back(x);
                tdlr = true;
                lrsum += x;
            }
            cin>>ch;
        }
        cin>>x;
        if(tdlr){
            topdown.push_back(x);
            tdsum += x;
        } else {
            leftright.push_back(x);
            lrsum += x;
        }
        if(n<=2){
            cout<<"NO"<<endl;
            continue;
        }
        lrsafesum = lrsum - (n+1)/2;
        tdsafesum = tdsum - (n+2)/2;
        ll anslr=0, anstd=0, atd = tdsum, alr = lrsum;
        if(tdsum%2!=0){
            anstd++;
            tdsum--;
        }
        if(lrsum%2!=0){
            anslr++;
            lrsum--;
        }
        if(anslr>lrsafesum || anstd>tdsafesum){
            cout<<"NO"<<endl;
            continue;
        }
        long i;
        vector<int> dp;
        sort(topdown.begin(),topdown.end());
        ll sum = tdsum/2;
        if(topdown[topdown.size()-1] >= sum){
            i = atd - topdown[topdown.size()-1];
            if(i>topdown[topdown.size()-1])
                i = topdown[topdown.size()-1];
        } else {
            int temp = 0;
            dp.resize(sum+1,temp);
            for(i=1;i<dp.size();i++){
                dp[i] = -1;
                for(long j=1;j<=topdown.size();j++){
                    if(i-topdown[j-1]>=0){
                        if(dp[i-topdown[j-1]]!=-1 && j-1>=dp[i-topdown[j-1]]){
                            dp[i] = j;
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
            for(i=dp.size()-1;i>=0;i--){
                if(dp[i]!=-1)
                    break;
            }
        }
        anstd += tdsum - 2*i;
        if(anstd>tdsafesum){
            cout<<"NO"<<endl;
            continue;
        }
        sort(leftright.begin(),leftright.end());
        sum = lrsum/2;
        if(leftright[leftright.size()-1] >= sum){
            i = alr - leftright[leftright.size()-1];
            if(i>leftright[leftright.size()-1])
                i = leftright[leftright.size()-1];
        } else {
            dp.resize(sum+1);
            dp[0] = 0;
            for(i=1;i<dp.size();i++){
                dp[i] = -1;
                for(long j=1;j<=leftright.size();j++){
                    if(i-leftright[j-1]>=0){
                        if(dp[i-leftright[j-1]]!=-1 && j-1>=dp[i-leftright[j-1]]){
                            dp[i] = j;
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
            for(i=dp.size()-1;i>=0;i--){
                if(dp[i]!=-1)
                    break;
            }
        }
        anslr += lrsum - 2*i;
        if(anslr>lrsafesum){
            cout<<"NO"<<endl;
            continue;
        }
        // cout<<"ans td "<<anstd<<" "<<tdsum<<" "<<i<<endl;
        // cout<<anslr<<" "<<anstd<<endl;
        cout<<anslr+anstd<<endl;
    }
    return 0;
}
