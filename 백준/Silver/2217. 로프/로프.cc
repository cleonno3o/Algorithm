#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> rope(n);
    for (int i = 0; i < n; i++)
        cin >> rope[i];
    sort(rope.begin(), rope.end());
    int maxWeight = 0;
    for (int i = 0; i < n; i++)
    {
        int weight = (n - i) * rope[i];
        if (weight > maxWeight) maxWeight = weight;
    }
    cout << maxWeight;
}