#include <bits/stdc++.h>
using namespace std;
int true_index;
void make_all_true(vector<vector<bool> > &ans,int n){
    if(n<=true_index)
        return;
    for(int i=0;i<n;i++){
        ans[i][n] = true;
    }
    for(int i=0;i<n;i++){
        make_all_true(ans,i);
    }
    true_index = n;
}
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("B-large.in");
    outfile.open("B-output.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        long long n,k;
        true_index = 0;
        infile>>n>>k;
        long long maxv = 1<<(n-2);
        if(maxv<k)
            outfile<<"Case #"<<tk<<": IMPOSSIBLE"<<endl;
        else{
            outfile<<"Case #"<<tk<<": POSSIBLE"<<endl;
            if(n==2){
                outfile<<"01\n00\n";
            }else{
                vector<bool> temp(n,false);
                vector<vector<bool> > ans (n,temp);
                maxv = 1<<(n-3);
                int ind = n-2;
                while(maxv!=0){
                    if(maxv<=k){
                        k -= maxv;
                        make_all_true(ans,ind);
                        ans[ind][n-1] = true;
                    }
                    maxv /= 2;
                    ind--;
                }
                if(k==1){
                    ans[0][n-1] = true;
                }
                for(int i=0;i<ans.size();i++){
                    for(int j=0;j<ans[0].size();j++){
                        if(ans[i][j]==true)
                        outfile<<"1";
                        else
                        outfile<<"0";
                    }
                    outfile<<endl;
                }
            }
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
