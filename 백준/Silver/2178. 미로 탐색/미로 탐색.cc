#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int drow[] = { 1, 0 ,-1, 0 };
int dcol[] = { 0, -1, 0, 1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> miro(n + 1, vector<int>(m + 1));
	vector<vector<int>> ch(n + 1, vector<int>(m + 1));
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			miro[i][j + 1] = temp[j] - '0';
		}
	}
	q.push({ 1,1 });
	ch[1][1] = 1;
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nRow = pos.first + drow[i];
			int nCol = pos.second + dcol[i];
			if (nRow <= n && nRow >= 1 &&
				nCol <= m && nCol >= 1 &&
				miro[nRow][nCol] == 1)
			{
				if (ch[nRow][nCol] == 0)
				{
					ch[nRow][nCol] = ch[pos.first][pos.second] + 1;
					q.push({ nRow, nCol });
				}
			}
		}
	}
	cout << ch[n][m];
}