#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct cmp {
    bool operator()(const string& s1, const string& s2) const {
        if (s1.length() != s2.length())
            return s1.length() < s2.length();
        else {
            int sum1 = 0, sum2 = 0;
            for (int i = 0; i < s1.length(); i++) {
                if (isdigit(s1[i])) sum1 += s1[i] - '0';
                if (isdigit(s2[i])) sum2 += s2[i] - '0';
            }
            if (sum1 != sum2) return sum1 < sum2;
            else return s1 < s2;
        }
    }
};
int main() {
    int N;
    cin >> N;
    vector<string> strs(N);
    for (int i = 0; i < N; i++) {
        cin >> strs[i];
    }
    sort(strs.begin(), strs.end(), cmp());
    for (int i = 0; i < N; i++) {
        cout << strs[i] << "\n";
    }
}