#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("D-large.in");
    outfile.open("D-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        long e, n;
        infile>>e>>n;
        vector<long long> arr(n);
        for(long i=0;i<n;i++)
            infile>>arr[i];
        sort(arr.begin(),arr.end());
        vector<long long> cum_arr = arr;
        for(long i=1;i<cum_arr.size();i++)
            cum_arr[i] += cum_arr[i-1];
        long ans = 0;
        vector<long long>::iterator it1, it2;
        vector<long long>::iterator cit1, cit2;
        it1 = arr.begin();
        it2 = arr.end();
        it2--;
        cit1 = cum_arr.begin();
        cit2 = cum_arr.end();
        ans = lower_bound(cit1, cit2, e) - cit1;
        while(*it1 < e) {
            // e -= *it1;
            it1++;
            cit1++;
            if(it1 >= it2) break;
            e += *it2;
            it2--;
            cit2--;
            // cout<<"for energy = "<<e<<" ans is "<<lower_bound(cit1, cit2, e) - cit1<<" "<<lower_bound(cit1, cit2, e)-cum_arr.begin()<<endl;
            ans = max(ans, lower_bound(cit1, cit2, e) - cit1);
        }
        outfile<<"Case #"<<tk<<": "<<ans<<endl; 
        cout<<"Case #"<<tk<<": "<<ans<<endl; 
    }
    infile.close();
    outfile.close();
    return 0;
}
