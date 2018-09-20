/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 *
 *
 * C++ program from a Hackerrank problem.
*/

#include <iostream>
#include <vector>

#define NODE 100000

using namespace std;

vector<int> adj[NODE+10];
int mod = (int)1e9+7;
int memo[NODE+10][2][2];
int done[NODE+10][2][2];

long long dp(int, int, int, int, int);

int main() {
    int n, a, b;
    cin >> n;

    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << ( dp(1, 0, 0, 0, 0) + dp(1, 0, 0, 1, 0) ) % mod << endl;
    return 0;
}

long long dp(int s, int p, int c, int color, int ally) {

    long long res = 0;

    if (c == adj[s].size())
        return ally;

    int t = adj[s][c];

    if (t == p)
        return dp(s, p, c + 1, color, ally); /// skip back edges

    if (done[t][color][ally] == 1)
        return memo[t][color][ally];

    /// make it ally
    res = ( dp(t, s, 0, color, 1) * dp(s, p, c + 1, color, 1) ) % mod;

    /// make it enemy
    res = ( res + ( dp(t, s, 0, 1 - color, 0) * dp(s, p, c + 1, color, ally) ) % mod ) % mod;

    done[t][color][ally] = 1;
    memo[t][color][ally] = (int)res;

    return res;
}
