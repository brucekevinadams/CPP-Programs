#include <bits/stdc++.h>
using namespace std;

int diff = INT_MAX, global_sum = 0;
struct node{ int data; vector<node*> edges; };

void checkDiff(node &u, node &parent){
    for(node* v : u.edges)
        if(v != &parent) checkDiff(*v, u);
    diff = min(diff, abs(global_sum - u.data*2));
    parent.data += u.data;
}

int main() {
    int n, u, v;
    cin >> n;
    vector<node> tree(n+1);
    for(int i = 1; i <= n; i++){
        cin >> tree[i].data;
        global_sum += tree[i].data;
    }
    while(cin >> u >> v){
        tree[u].edges.push_back(&tree[v]);
        tree[v].edges.push_back(&tree[u]);
    }
    checkDiff(tree[1], tree[0]);
    cout << diff;
    return 0;
}