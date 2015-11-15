#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    vector<long> children;
    vector<char> edge_val;
    
};
long answer;
// vector<bool> vis(20001);
class graph{
    public:
    node vertex[20001];
    void add(long a, long b,char c){                                //have to arrange them in descending order here
        vertex[a].children.push_back(b);
        vertex[b].children.push_back(a);
        vertex[a].edge_val.push_back(c);
        vertex[b].edge_val.push_back(c);
    }
    bool isleaf(long a,vector<bool> vis){
        vector<long> check = vertex[a].children;
        vector<long>::iterator it;
        for(it = check.begin();it<check.end();it++){
            if(vis[*it] == false)
                return false;
        }
        return true;
    }
    vector<char> find_end(long a,vector<bool> vis,vector<char> path){
        // length_count++;
        vis[a] = true;
        long ans;
        if(isleaf(a,vis)){
            answer = a;
            return path;
        }
        else{
            vector<long> nchildren = vertex[a].children;
            vector<char> nedge_val = vertex[a].edge_val;
            vector<long> vertices;
            vector<char> values;
            vector<long>::iterator it;
            vector<long> ans_values;
            vector<long> ans_edge;
            char high_val = 'a' -1;
            for(it = nchildren.begin();it!= nchildren.end();it++){
                if(vis[*it]!=true){
                    vertices.push_back(*it);
                    char val = *(it - nchildren.begin() + nedge_val.begin());
                    values.push_back(val);
                    if(val>high_val){
                        ans_values.clear();                                                     //dunno whether it will work
                        ans_values.push_back(*it);
                        ans_edge.clear();
                        ans_edge.push_back(val);
                        high_val = val;
                    }
                    else if(val == high_val){
                        ans_values.push_back(*it);
                        ans_edge.push_back(val);
                    }
                }
            }
            if(ans_values.size()>1){
                vector<char> compare_path,temp_path;
                long temp;
                path.push_back(ans_edge[0]);
                compare_path = find_end(ans_values[0],vis,path);
                path.pop_back();
                ans = answer;
                for(long j=1;j<ans_values.size();j++){
                    path.push_back(ans_edge[j]);
                    temp_path = find_end(ans_values[j],vis,path);
                    if(compare_path == temp_path){
                        if(answer>ans)
                            ans = answer;
                    }
                    else if(lexicographical_compare(compare_path.begin(),compare_path.end(),temp_path.begin(),temp_path.end())){
                        compare_path = temp_path;
                        ans = answer;
                    }
                    path.pop_back();
                }
                path = compare_path;
                answer = ans;


                // long temp_length = length_count;
                // long temp;
                // temp = find_end(ans_values[0],vis);
                // ans = temp;
                // long compare_length = length_count;
                // length_count = temp_length;
                // for(long j=1;j<ans_values.size();j++){
                //     temp = find_end(ans_values[j],vis);
                //     if(length_count>compare_length){
                //         compare_length = length_count;
                //         ans = temp;
                //     }
                //     else if(length_count == compare_length){
                //         if(temp>ans)
                //             ans = temp;
                //     }
                //     length_count = temp_length;
                // }
            }
            else{
                long pos = ans_values[0];
                path.push_back(ans_edge[0]);
                path = find_end(pos,vis,path);
            }
        }
        vis[a] = false;
        return path;
    }
    long get_answer(long a){
        vector<bool> vis(20001);
        vector<char> path;
        fill(vis.begin(),vis.end(),false);
        // length_count = 0;
        path = find_end(a,vis,path);
        return answer;
    }
};

int main() {
    long n;
    cin>>n;
    long a,b;
    char ch;
    long i;
    graph g;
    for(i=1;i<n;i++){
        cin>>a>>b>>ch;
        g.add(a,b,ch);
    }
    for(i=1;i<=n;i++){
        cout<<g.get_answer(i)<<" ";
    }
    return 0;
}