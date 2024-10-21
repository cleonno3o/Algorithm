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
    vector<long long> dist(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> dist[i];
    int minOil = 2147000000;
    int currOil;
    long long totalPrice = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> currOil;
        if (minOil > currOil) minOil = currOil;
        totalPrice += dist[i] * minOil;
    }
    cout << totalPrice;
}