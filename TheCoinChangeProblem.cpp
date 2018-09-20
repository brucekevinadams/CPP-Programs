/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 *
 * C++ program from a Hackerrank problem.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector <long> c(m);
    for (int i=0;i<m;i++) cin >> c[i];

    vector <long> numways(n+1); // numways[x] means # ways to get sum x
    numways[0]=1; // init base case n=0
    
    // go thru coins 1-by-1 to build up numways[] dynamically
    // just need to consider cases where sum j>=c[i]    
    for (int i=0;i<m;i++) {
        for (int j=c[i];j<=n;j++) {
            // find numways to get sum j given value c[i]
            // it consists of those found earlier plus
            // new ones.
            // E.g. if c[]=1,2,3... and c[i]=3,j=5,
            //      new ones will now include '3' with
            //      numways[2] = 2, that is:
            //      '3' with '2', '3' with '1'+'1'
            numways[j]+=numways[j-c[i]]; 
        }
    }    

    cout << numways[n];    
    return 0;
}