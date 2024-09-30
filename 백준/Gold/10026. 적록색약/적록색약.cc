#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int drow[] = { 1, 0, -1, 0 };
int dcol[] = { 0, -1, 0, 1 };
void bfs(vector<vector<char>>& image, vector<vector<int>>& ch)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ch[i][j] = 0;
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ch[i][j] == 0)
			{
				cnt++;
				ch[i][j] = 1;
				q.push({ i, j });
				while (!q.empty())
				{
					pair<int, int> pos = q.front();
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nRow = pos.first + drow[k];
						int nCol = pos.second + dcol[k];
						if (nRow < n && nRow >= 0 &&
							nCol < n && nCol >= 0 &&
							ch[nRow][nCol] == 0 &&
							image[nRow][nCol] == image[pos.first][pos.second])
						{
							ch[nRow][nCol] = 1;
							q.push({ nRow, nCol });
						}
					}
				}
			}
		}
	}
	cout << cnt << ' ';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	vector<vector<char>> image(n, vector<char>(n));
	vector<vector<int>> ch(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			image[i][j] = c;
		}
	}
	bfs(image, ch);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (image[i][j] == 'G')
				image[i][j] = 'R';
		}
	}
	bfs(image, ch);
}