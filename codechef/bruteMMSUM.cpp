#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        vector<long long> arr(n);
        for(long i=0;i<n;i++){
            cin>>arr[i];
        }
        long long maxval,sum;
        maxval = *max_element(arr.begin(),arr.end());
        sum=0;
        vector<pair<pair<long long, long long>,long long> > ans_pairs;
        long long minele = 0;
        long long maxtempval = 0;
        for(long i=0;i<arr.size();i++){
            sum += arr[i];
            minele = min(minele,arr[i]);
            maxval = max(maxval,sum);
            maxtempval = max(maxtempval,sum);
            if(arr[i]<0){
                ans_pairs.push_back(make_pair(make_pair(sum,minele),maxtempval));
                sum = 0;
                minele = 0;
                maxtempval = 0;
            }
        }
        if(!(sum==0 && minele==0 && maxtempval==0))
            ans_pairs.push_back(make_pair(make_pair(sum,minele),maxtempval));
        long long presum=0;
        for(long i = ans_pairs.size()-1;i>=0;i--){
            long long tempsum = ans_pairs[i].first.first, tempmin = ans_pairs[i].first.second;
            long long tempval = ans_pairs[i].second;
            if(tempmin<0 && tempsum-tempmin > 0){
                maxval = max(presum+tempsum-tempmin,maxval);
            }else{
                maxval = max(presum+tempsum,maxval);
            }
            if(tempmin + presum < 0)
                presum = tempval;
            else
                presum += tempsum;
        }
        cout<<maxval<<endl;
    }
    return 0;
}
