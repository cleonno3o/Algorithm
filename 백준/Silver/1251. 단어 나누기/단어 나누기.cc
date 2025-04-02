#include <iostream>
#include <string>

using namespace std;

string result = "";
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = 1; i <= s.length() - 2; i++)
    {
        for (int j = 1; j <= s.length() - i - 1; j++)
        {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, j);
            string s3 = s.substr(i + j, s.length() - i - j);

            string r1(s1.rbegin(), s1.rend());
            string r2(s2.rbegin(), s2.rend());
            string r3(s3.rbegin(), s3.rend());
            string r = r1 + r2 + r3;
            if (result == "") result = r;
            else if (r < result) result = r;
        }
    }
    cout << result;
}