#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int drow[] = { 1, 0, -1, 0 };
int dcol[] = { 0, -1, 0, 1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n;
	cin >> m >> n;
	vector<vector<int>> box(n, vector<int>(m));
	vector<vector<int>> ch(n, vector<int>(m));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tomato;
			cin >> tomato;
			box[i][j] = tomato;
		}
	}
	int day = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 1)
			{
				ch[i][j] = 1;
				q.push({ i, j });
			}
		}
	}
	while (1)
	{
		int qSize = q.size();
		for (int j = 0; j < qSize; j++)
		{
			pair<int, int> pos = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nRow = pos.first + drow[i];
				int nCol = pos.second + dcol[i];
				if (nRow < n && nRow >= 0 &&
					nCol < m && nCol >= 0 &&
					ch[nRow][nCol] == 0 &&
					box[nRow][nCol] == 0)
				{
					ch[nRow][nCol] = box[nRow][nCol] = 1;
					q.push({ nRow, nCol });
				}
			}
		}
		if (!q.empty())
			day++;
		else
			break;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 0)
				break;
			else
				cnt++;
		}
	}
	if (cnt != n * m)
		cout << -1;
	else
		cout << day;
}