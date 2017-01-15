#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("pie_progress.txt");
    outfile.open("output.txt");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        int n,m;
        infile>>n>>m;
        long long ans = 0;
        vector<long long> temp(m);
        vector<vector<long long> > arr(n,temp);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                infile>>arr[i][j];
            }
            sort(arr[i].begin(),arr[i].end());
            for(int j=0;j<m;j++) {
                arr[i][j] += 2*j+1;
            }
        }
        vector<int> start(n,0);
        for(int i=0;i<n;i++) {
            bool seen = false;
            long long tempval;
            int pos;
            for(int j=0;j<=i;j++) {
                if(start[j] == m)
                    continue;
                if(seen) {
                    if( tempval > arr[j][start[j]]){
                        tempval = arr[j][start[j]];
                        pos = j;
                    }
                }
                else{
                    tempval = arr[j][start[j]];
                    pos = j;
                    seen = true;
                }
            }
            start[pos]++;
            ans += tempval;
            cout<<ans<<" "<<pos<<endl;
        }
        cout<<endl;
        outfile<<"Case #"<<tk<<": "<<ans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
