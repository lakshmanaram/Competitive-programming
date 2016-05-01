#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("B-large.in");
    outfile.open("B-output.out");
    infile>>t;
    for(int j=1;j<=t; j++){
        vector<int> hash(2500,0);
        int x;
        infile>>x;
        for(int k = 1; k<2*x;k++){
            for(int i=0;i<x;i++){
            int a;
            infile>>a;
            hash[a-1]++;
        }
        }
        vector<int> nos;
        for(int i=0;i<2500;i++){
            if(hash[i]%2 != 0)
                nos.push_back(i+1);
        }
        sort(nos.begin(),nos.end());
        outfile<<"Case #"<<j<<": ";
        for(int i = 0; i<nos.size();i++){
            outfile<<nos[i]<<" ";
        }
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
