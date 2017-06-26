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
        string s;
        infile>>s;
        string ans = s;
        if(s.size()%2 == 0) {
            for(int i=1;i<s.size();i+=2) {
                int x = s[i-1]-'A';
                if(i > 1) x -= ans[i-2]-'A';
                x += 26;
                x %= 26;
                ans[i] = 'A'+x;
            }
            for(int i=s.size()-2;i>=0;i-=2) {
                int x = s[i+1]-'A';
                if(i < s.size()-2) x -= ans[i+2]-'A';
                x += 26;
                x %= 26;
                ans[i] = 'A'+x;
            }
        } else {
            ans = "AMBIGUOUS";
        }
        outfile<<"Case #"<<tk<<": "<<ans;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
