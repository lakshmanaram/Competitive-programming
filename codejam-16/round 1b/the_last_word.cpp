#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("A-large.in");
    outfile.open("A-output.out");
    infile>>t;
    for(int j=1;j<=t; j++){
        string x,temp = "";
        infile>>x;
        if(x.size() == 1){
            temp = x;
        }else{
            if(x[1]>x[0]){
                temp = x.substr(1,1)+x.substr(0,1);
            } else{
                temp = x.substr(0,2);
            }
            for(int i = 2; i < x.size();i++){
                if(x[i]>=temp[0]){
                    temp = x.substr(i,1) + temp;
                }else{
                    temp = temp + x.substr(i,1);
                }
            }
        }
        outfile<<"Case #"<<j<<": "<<temp<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
