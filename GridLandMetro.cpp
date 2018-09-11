#include <bits/stdc++.h>
using namespace std;
vector< pair <int,int> > merge(vector< pair <int,int> > &v) {
    vector< pair <int,int> > merged;
    
    if(v.size() != 0) {
        sort(v.begin(), v.end());
    }
    stack< pair<int,int> > s;
    int n=v.size();
    s.push(v[0]);    
    for(int i=1;i<n;i++){
        pair <int,int> top;
        top=s.top();
        if(v[i].first > top.second)
            s.push(v[i]);
        else if(top.second < v[i].second){   // if v[i].first <= top.second 
            top.second=v[i].second;
            s.pop();
            s.push(top);
        }
    }
    while(!s.empty()){
        merged.push_back(s.top());
        s.pop();
    }
    return merged;
}

int main() {
    map< int,vector< pair <int,int> > > track;
    int n, m, k; 
    cin >> n >> m >> k;
    
    
    for(long i = 0; i < k; ++i) {
        int r, c1, c2; cin >> r >> c1 >> c2;
        track[r].push_back(make_pair(c1, c2));
    }
    long totalcells = ((long)n) * ((long)m);    // total no of cells in gridland
    
    for(auto &node : track){             //  merging the tracks of each row one by one
        node.second = merge(node.second);
        vector< pair <int,int> > tr=node.second;   
        // counting one by one by through each row, cells covered by tracks and 
        // subtracting them from totalcells                                                         
        for(int i=0;i<tr.size();i++){
               totalcells-=((long)tr[i].second)-((long)tr[i].first)+1;
        }
    }    
    cout<<totalcells<<endl;
    return 0;
}