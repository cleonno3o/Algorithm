#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int v, e;
		cin >> v >> e;
		vector<vector<int>> gr(v + 1);
		vector<int> ch(v + 1);
		for (int j = 0; j < e; j++)
		{
			int a, b;
			cin >> a >> b;
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		bool flag = true;
		for (int k = 1; k <= v; k++)
		{
			queue<int> q;
			if (ch[k] == 0 && flag)
			{
				ch[k] = 1;
				q.push(k);
				while (!q.empty())
				{
					int s = q.front();
					q.pop();
					for (int j = 0; j < gr[s].size(); j++)
					{
						if (ch[gr[s][j]] == 0)
						{
							q.push(gr[s][j]);
							ch[gr[s][j]] = -ch[s];
						}
						else if (ch[gr[s][j]] == ch[s])
						{
							flag = false;
							break;
						}
					}
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
 	}
}