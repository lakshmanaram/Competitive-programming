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
        string s;
        infile>>s;
        for(int i=1;i<s.size();i++){
            if(s[i] >= s[i-1])
                continue;
            for(int j=i;j<s.size();j++)
                s[j] = '9';
            bool reduce = true;
            for(int j=i-1; j>=0;j--){
                if(reduce) {
                    if(s[j] == '0'){
                        s[j] = '9';
                        cout<<"wrong";
                        // never happens
                    } else s[j]--;
                    reduce = false;
                    if(j == 0)
                        break;
                    if(s[j] < s[j-1]) {
                        s[j] = '9';
                        reduce = true;
                    }
                }
            }
            break;
        }
        while(s.size()>1){
            if(s[0]!='0')
                break;
            s = s.substr(1);
        }
        outfile<<"Case #"<<tk<<": "<<s;
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
