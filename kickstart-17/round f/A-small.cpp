#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("A-large.in");
    outfile.open("A-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        long n;
        infile>>n;
        vector<long> arr(n);
        for(long i=0;i<n;i++)
            infile>>arr[i];
        long i1, i2;
        i1 = i2 = (arr.size()-1)/2;
        vector<long> farr;
        if(arr.size()%2!=0)
            farr.push_back(arr[i1--]);
        i2++;
        while(i1 >= 0 || i2 < arr.size()){
            if(i1 >= 0)
                farr.push_back(arr[i1--]);
            if(i2 < arr.size())
                farr.push_back(arr[i2++]);
        }
        reverse(farr.begin(), farr.end());
        // for(long i=0;i<farr.size();i++)
        //     cout<<farr[i]<<" ";
        // cout<<endl;
        bool flag = true;
        long range_start = farr[0], range_end = farr[0];
        for(long i=1;i<farr.size();i++){
            if(farr[i] >= range_end){
                range_end = farr[i];
            } else if(farr[i] < range_start) {
                range_start = farr[i];
            } else {
                cout<<range_start<<" "<<range_end<<" with farr "<<farr[i]<<endl;
                flag = false;
                break;
            }
        }
        if(flag)
            outfile<<"Case #"<<tk<<": YES"<<endl;
        else
            outfile<<"Case #"<<tk<<": NO"<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
