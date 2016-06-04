#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        vector<long long> arr(n);
        bool allneg = true;
        for(long i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>0)
                allneg = false;
        }
        long long maxval,sum;
        maxval = *max_element(arr.begin(),arr.end());
        if(allneg)
            cout<<maxval<<endl;
        else{
            sum=0;
            vector<pair<pair<long long, long long>,long long> > ans_pairs;
            long long minele = 0;
            long long maxsum = 0;
            for(long i=0;i<arr.size();i++){
                sum += arr[i];
                minele = min(minele,arr[i]);
                maxsum += arr[i];
                if(maxsum < 0)
                    maxsum = 0;
                maxval = max(maxval,maxsum);
                if(arr[i]<0){
                    ans_pairs.push_back(make_pair(make_pair(sum,minele),maxsum));
                    sum = 0;
                    minele = 0;
                }
            }
            if(!(sum==0 && minele==0))
                ans_pairs.push_back(make_pair(make_pair(sum,minele),maxsum));
            long long presum=0;
            for(long i = ans_pairs.size()-1;i>=0;i--){
                long long tempsum = ans_pairs[i].first.first, tempmin = ans_pairs[i].first.second;
                long long tempval;
                if(i!=0)
                    tempval = ans_pairs[i-1].second;
                else
                    tempval = 0;
                // cout<<"presum = "<<presum<<" tempsum = "<<tempsum<<" tempmin = "<<tempmin<<" maxsum = "<<tempval<<endl;
                if(tempmin<0){
                    maxval = max(presum+tempsum-tempmin+tempval,maxval);
                    // cout<<"maxval inside = "<<maxval<<endl;
                }else{
                    maxval = max(presum+tempsum+tempval,maxval);
                    // cout<<"maxval else = "<<maxval<<endl;
                }
                if(tempmin + presum < 0){
                    if(tempmin < 0)
                        presum = tempsum-tempmin;
                    else
                        presum = tempsum;
                }
                else
                    presum += tempsum;
            }
            cout<<maxval<<endl;
        }
    }
    return 0;
}
