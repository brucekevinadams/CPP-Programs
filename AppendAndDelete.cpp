#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int i=0;
    int count=0;
    while(s[i]==t[i]){
        count++;
        i++;
    }
    
    int s_size=s.length();
    int s_si=s_size-count;
    int t_size=t.length();
    int t_si=t_size-count;
    
    if((s_si+t_si <= k && (s_si+t_si)%2 ==k%2 ) || s_size+t_size < k) 
        return "Yes";
    else
        return "No";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
