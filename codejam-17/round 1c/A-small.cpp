#include <bits/stdc++.h>
#define pb push_back
using namespace std;
bool scomp( pair<long long, long long> a, pair<long long, long long> b) {
    if(a.first*a.second > b.first*b.second)
        return true;
    else if(a.first*a.second < b.first*b.second)
        return false;
    if(a.first > b.first)
        return true;
    return false;
}
bool mcomp(pair<long long, long long> a, pair<long long, long long> b) {
    if(a.first < b.first)
        return true;
    return false;   
}
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("A-large.in");
    outfile.open("A-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long k;
        long n;
        infile>>n>>k;
        vector<pair<long long, long long> > arr(n);
        for(long i=0;i<n;i++)
            infile>>arr[i].first>>arr[i].second;
        sort(arr.begin(),arr.end(), scomp);
        // for(int i=0;i<n;i++) {
        //     //cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }
        //cout<<endl;
        double ans = 0;
        for(long i=0;i<k;i++)
            ans += 2*arr[i].first*arr[i].second*M_PI;
        double tempans;
        long j = distance(arr.begin(),max_element(arr.begin(), arr.end(), mcomp));
        // //cout<<arr[j].first<<" is the largest with j = "<<j<<"\n";
        tempans = ans;
        if(j>=k) {
            tempans -= arr[k-1].first*arr[k-1].second*2*M_PI;
            tempans += arr[j].first*arr[j].second*2*M_PI;
        } 
        tempans += M_PI*arr[j].first*arr[j].first;
        j = distance(arr.begin(),max_element(arr.begin(), arr.begin()+k, mcomp));
        //cout<<"j = "<<j<<endl;
        ans += M_PI*arr[j].first*arr[j].first;
        outfile<<"Case #"<<tk<<": "<<std::fixed<<setprecision(10)<<max(ans,tempans);
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
