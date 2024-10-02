#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int docs, target;
		cin >> docs >> target;
		vector<int> values(docs);
		queue<pair<int,int>> q;
		for (int j = 0; j < docs; j++)
		{
			cin >> values[j];
			q.push({j, values[j]});
		}
		int targetValue = values[target];
		sort(values.begin(), values.end(), greater<int>());
		int idx = 0;
		int cnt = 0;
		while (1)
		{
			pair<int, int> doc = q.front();
			if (doc.second >= values[idx])
			{
				q.pop();
				idx++;
				cnt++;
				if (doc.first == target)
					break;
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
		cout << cnt << '\n';
	}
}