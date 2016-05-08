#include <bits/stdc++.h>
using namespace std;
struct party{
    char name;
    int no;
};
bool func(party a, party b){
    if(a.no > b.no)
        return true;
    return false;
}
int main(){
    int t;
    ifstream infile;
    ofstream outfile;
	infile.open("A-large.in");
    outfile.open("A-output1.out");
    infile>>t;
    for(int tk=1;tk<=t;tk++){
        int n;
        infile>>n;
        vector<party> nos(n);
        int total = 0;
        for(int i=0;i<n;i++){
            infile>>nos[i].no;
            nos[i].name = (char)((int)'A' + i);
            total += nos[i].no;
        }
        vector<string> ans;
        sort(nos.begin(),nos.end(),func);
        for(int i =0;i<nos.size();i++)
        while(total!=0){
            if(nos.size()>2){
                bool flag = true;
                for(int i=0;i<nos.size()-1;i++){
                    if(nos[i].no == nos[i+1].no){
                        flag = false;
                        for(int k=0;k<i;k++){
                            while(nos[0].no!=0){
                                string temp = "";
                                if(nos[0].no>1){
                                    temp += nos[0].name;
                                    temp += nos[0].name;
                                    ans.push_back(temp);
                                    total -= 2;
                                    nos[0].no--;
                                    nos[0].no--;
                                } else{
                                    temp += nos[0].name;
                                    ans.push_back(temp);
                                    total -= 1;
                                    nos[0].no--;
                                }
                            }
                            nos.erase(nos.begin());
                        }
                        break;
                    }
                }
                if(nos[0].no == nos[1].no){
                    while(nos.size() != 2){
                        while(nos[2].no!=0){
                            string temp = "";
                            if(nos[2].no>1){
                                temp += nos[2].name;
                                temp += nos[2].name;
                                ans.push_back(temp);
                                total -= 2;
                                nos[2].no--;
                                nos[2].no--;
                            } else{
                                temp += nos[2].name;
                                ans.push_back(temp);
                                total -= 1;
                                nos[2].no--;
                            }
                        }
                        nos.erase(nos.begin()+2);
                    }
                }else{
                    string temp = "";
                    if(nos[0].no > total/2){
                        temp += nos[0].name;
                        temp += nos[0].name;
                        ans.push_back(temp);
                        total -= 2;
                        nos[0].no--;
                        nos[0].no--;
                    }else{
                        temp += nos[0].name;
                        temp += nos[1].name;
                        ans.push_back(temp);
                        total -= 2;
                        nos[0].no--;
                        nos[1].no--;
                    }
                }
                sort(nos.begin(),nos.end(),func);
            }else{
                while(total!=0){
                    string temp= "";
                    temp += nos[0].name;
                    temp += nos[1].name;
                    ans.push_back(temp);
                    total -= 2;
                    nos[0].no--;
                    nos[1].no--;
                }
            }
        }
        outfile<<"Case #"<<tk<<": ";
        for(int i=0;i<ans.size();i++){
            outfile<<ans[i]<<" ";
        }
        outfile<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
