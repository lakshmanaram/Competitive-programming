#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("B-large.in");
    outfile.open("B-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        int n;
        infile>>n;
        bool flag = true;
        vector<string> arr(n);
        vector<string> ans;
        for(long i=0;i<n;i++){
            infile>>arr[i];
        }
        int ansi = -1, ansj = -1;
        for(long i=0;i<n;i++){
            int temp = 0;
            for(long j=0;j<n;j++) {
                if(arr[i][j] == 'X')
                    temp++;
            }
            if(temp == 1 && ansi == -1) ansi = i;
            else if(temp == 2) ans.push_back(arr[i]);
            else flag = false;
        }
        for(long i=0;i<n;i++){
            int temp = 0;
            for(long j=0;j<n;j++) {
                if(arr[j][i] == 'X')
                    temp++;
            }
            if(temp == 1 && ansj == -1) ansj = i;
            else if(temp == 2) continue;
            else flag = false; 
        }
        if(flag){
            if(arr[ansi][ansj] != 'X')
                flag = false;
        }
        if(flag) {
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i+=2){
                if(ans[i] != ans[i+1]){
                    flag = false;
                }
            }
        }
        if(flag)
            outfile<<"Case #"<<tk<<": POSSIBLE";
        else
            outfile<<"Case #"<<tk<<": IMPOSSIBLE";
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}