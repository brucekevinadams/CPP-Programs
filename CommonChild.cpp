/*
 * Author: Bruce Adams
 * email: ezaroth@gmail.com
 * website: austingamestudios.com
 *
 * C++ program from a Hackerrank problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {

// matrix c stores the char count of child string
vector < vector<int> > c(s1.length()+1,vector<int>(s2.length()+1));
for (int i=1;i<=s1.length();i++) {
    for (int j=1;j<=s2.length();j++) {        
        if (s1[i-1]==s2[j-1]) c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=max(c[i][j-1], c[i-1][j]);
    }
} 

return c[s1.length()][s2.length()]; 

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
