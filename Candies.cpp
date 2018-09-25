#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n); // children ratings
    vector<int> c(n); // candies allocated to each child
    
    // take in r[] and parse left to right
    int numcandies=1; // num of candies to give
    c[0]=1;
    cin >> r[0];
    for (int i=1;i<n;i++) {
        cin >> r[i];
        if (r[i]>r[i-1]) numcandies++;
        else if (r[i]<=r[i-1]) numcandies=1;
        c[i]=numcandies;
    }

    // 2nd parse right to left and accumulate total
    numcandies=1;
    long total=c[n-1];
    for (int i=n-2;i>=0;i--) {
        if (r[i]>r[i+1]) numcandies++;
        else if (r[i]<=r[i+1]) numcandies=1;
        c[i]=(numcandies>c[i]?numcandies:c[i]); //use the larger of 2 parses
        total+=c[i];
    }    
    
    cout << total;
    return 0;
}