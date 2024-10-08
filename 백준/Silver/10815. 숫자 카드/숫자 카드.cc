#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, temp;
	cin >> n;
	unordered_map<int, int> ch;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		ch[temp] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		if (ch[temp] == 0)
			cout << 0 << " ";
		else
			cout << 1 << " ";
	}
}