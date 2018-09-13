/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 *
 * C++ program from a Hackerrank problem.
*/

#include <iostream>
#include <vector>
#include <bitset>
#define ull unsigned long long
#define M 64
using namespace std;

ull n,t,rs;
vector<bitset<M>> d;

ull cc(std::vector<bitset<M>> const& d, ull conf) {
    bitset<M> all; // all bits
    unsigned cc = 0; // connected components

    for(ull i = 0; i < n; ++i) {
        if(conf & ((ull)1<<i)) { // conf is the power set configuration of the current subset
            bitset<M> aux = d[i];
            if(aux.count() > 1) { // ignore numbers with one bit only (no edges are formed)
                if (!(all & aux).count()) cc++; // check if current value have a common edge with all others from the set
                all |= aux; // update the all set 
            }
        }
    }

    return M - all.count() + cc; 
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        d.emplace_back(bitset<M>(t));
    }

    for(ull i = 0; i < 1<<n; ++i) rs += cc(d, i);

    cout << rs;

    return 0;
}
