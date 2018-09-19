/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 * 
 *
 * C++ program from a Hackerrank problem.
*/

#include < bits / stdc++.h >
    using namespace std;
	
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector < pair < int, int >> E[N + 1];
    for (int i = 0; i < M; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        E[x].push_back(make_pair(y, c));
        E[y].push_back(make_pair(x, c));
    }
    int A, B;
    cin >> A >> B;
    /*  bool were[N + 1][1024];
      for (int i = 0; i <= N; i++)
        for (int j = 0; j < 1024; j++)
          were[i][j] = false;
    */
    unordered_map < int, bool > * were;
    were = new unordered_map < int, bool > [N + 1]();

    were[A][0] = true;
    queue < int > BFS;
    BFS.push(A);
    queue < int > K;
    K.push(0);
    while (!BFS.empty()) {
        int a = BFS.front();
        BFS.pop();
        int k = K.front();
        K.pop();
        for (pair < int, int > b: E[a]) {
            if (!were[b.first][k | b.second]) {
                were[b.first][k | b.second] = true;
                BFS.push(b.first);
                K.push(k | b.second);
            }
        }
    }
    for (int i = 0; i < 1024; i++)
        if (were[B][i]) {
            cout << i;
            return 0;
        }
    cout << -1;
    return 0;
}
