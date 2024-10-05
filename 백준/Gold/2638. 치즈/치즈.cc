#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int drow[] = { 1, 0, -1, 0 };
int dcol[] = { 0, -1, 0, 1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector <vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int days = 0;
	while (1)
	{
		// 치즈가 없는지 확인
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1)
					cnt++;
			}
		}
		// 없으면 종료
		if (cnt == 0)
			break;
		// 있으면 녹음
		else
		{
			days++;
			vector<vector<int>> ch(n, vector<int>(m));
			queue<pair<int, int>> q;
			ch[0][0] = 1;
			q.push({ 1, 1 });
			while (!q.empty())
			{
				pair<int, int> pos = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nRow = pos.first + drow[i];
					int nCol = pos.second + dcol[i];
					if (nRow < n && nRow >= 0 &&
						nCol < m && nCol >= 0 &&
						ch[nRow][nCol] != 1)
					{
						if (board[nRow][nCol] == 1)
						{
							ch[nRow][nCol]--;
						}
						else if (board[nRow][nCol] == 0)
						{
							ch[nRow][nCol] = 1;
							q.push({ nRow, nCol });
						}
					}
				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (ch[i][j] <= -2)
						board[i][j] = 0;
				}
			}
		}
	}
	cout << days;
}