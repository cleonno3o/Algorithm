#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<vector<int> > board;
vector<vector<int> > ch;
int drow[] = { -1, 1, 0, 0 };
int dcol[] = { 0, 0, -1, 1 };
pair<int, int> start;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	board = vector<vector<int> >(n, vector<int>(m));
	ch = vector<vector<int> >(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				start = make_pair(i, j);
		}
	}
	deque<pair<int, int> > q;
	q.push_back(make_pair(start.first , start.second));
	ch[start.first][start.second] = 0;
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nRow = pos.first + drow[i];
			int nCol = pos.second + dcol[i];
			if (nRow >= n or nRow < 0 or nCol >= m or nCol < 0)
				continue;
			if (ch[nRow][nCol] != -1) continue;
			if (board[nRow][nCol] == 0) continue;
			ch[nRow][nCol] = ch[pos.first][pos.second] + 1;
			q.push_back(make_pair(nRow, nCol));
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0) cout << 0 << " ";
			else cout << ch[i][j] << ' ';
		}
		cout << "\n";
	}
}