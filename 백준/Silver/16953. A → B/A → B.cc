#include <iostream>
#include <queue>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a, b;
	cin >> a >> b;

	queue<pair<long long, int>> q;
	q.push({ a, 1 });
	int res = -1;
	while (!q.empty())
	{
		pair<long long, int> cur = q.front();
		q.pop();
		long long num = cur.first;
		int count = cur.second;
		if (num == b)
		{
			res = count;
			break;
		}
		else if (num < b)
		{
			if (num * 2 <= b) q.push({ num * 2, count + 1 });
			if (num * 10 + 1 <= b) q.push({ num * 10 + 1, count + 1 });
		}
	}
	cout << res;
}