/*
* Author: Bruce Adams
* www.austingamestudios.com
* C++ program
* Hackerrank problem
*/

#include < bits / stdc++.h >

using namespace std;

int main() {

int q;
cin >> q;

for (int a0 = 0; a0 < q; a0++) {
	string s;
	cin >> s;

	if (s.length() % 2) cout << -1 << endl;
	else {
		vector < int > s1(26);
		vector < int > s2(26);
		for (int i = 0; i < s.length() / 2; i++) {
			s1[s[i] - 'a']++;
			s2[s[i + s.length() / 2] - 'a']++;
		}

		int min = 0;
		for (int i = 0; i < 26; i++)
			if (s2[i] > s1[i]) min += (s2[i] - s1[i]);
		cout << min << endl;
	}
}

return 0;
}
