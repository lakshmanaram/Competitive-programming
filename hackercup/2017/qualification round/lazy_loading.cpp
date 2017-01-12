#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("input.txt");
    outfile.open("output.txt");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        int n;
        infile>>n;
        vector<int> arr;
        int ans = 0;
        for(int i=0;i<n;i++) {
            int x;
            infile>>x;
            if(x >= 50)
                ans++;
            else    
                arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        int start = 0, end = arr.size()-1;
        while(start < end) {
            int items = ceil(50.0/(float)arr[end]);
            items--;
            // cout<<items<<" required"<<endl;
            if(start+items <= end){
                ans++;
            }
            start += items;
            end--;
        }
        outfile<<"Case #"<<tk<<": "<<ans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}