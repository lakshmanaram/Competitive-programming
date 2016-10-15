#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
map<char,int> gethash(string s) {
    map<char,int> h;
    for(int i=0;i<s.size();i++)
        h[s[i]]++;
    return h;
}
map<string, map<char, int> > alls;
long long func(string x, int i){
    // cout<<i<<endl;
    if(x.size()==i)
        return 1;
    long long ansx = 0;
    map<string, map<char, int> >::iterator mit;
    for(mit = alls.begin(); mit != alls.end(); mit++) {
        string s = mit->first;
        if(x.substr(i).size() < s.size())
            continue;
        if(mit->second == gethash(x.substr(i,s.size())))
            ansx += func(x,i+s.size());
    }
    return ansx;
}
int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("B-large.in");
    outfile.open("B-output.out");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        int m,n;
        alls.clear();
        infile>>m>>n;
        vector<string> strings(m);
        for(int i=0;i<m;i++){
            infile>>strings[i]; 
            alls[strings[i]] = gethash(strings[i]);
        }
        outfile<<"Case #"<<tk<<":";
        while(n--){
            string x;
            infile>>x;
            outfile<<" "<<func(x,0);
        }
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
