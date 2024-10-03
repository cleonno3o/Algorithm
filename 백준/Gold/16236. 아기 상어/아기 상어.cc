#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Shark {
	pair<int, int> pos;
	int lv;
	int combo;
	Shark(pair<int, int> _pos, int _lv, int _combo)
		: pos(_pos), lv(_lv), combo(_combo) {}
};
int drow[] = { 1, 0, -1, 0 };
int dcol[] = { 0, -1, 0, 1 };
Shark shark({0,0}, 0, 0);
int n, playTime;
bool isEat = true;
void bfs(vector<vector<int>>& board)
{
	isEat = false;
	vector<vector<int>> ch(n, vector<int>(n));
	queue<pair<int, int>> q;
	vector <pair<int, int>> targets;
	q.push(shark.pos);
	ch[shark.pos.first][shark.pos.second] = 1;
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();
		// 먹을 수 있는 대상 발견
		if (board[pos.first][pos.second] != 0 && board[pos.first][pos.second] < shark.lv)
		{
			isEat = true;
			targets.push_back(pos);
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nRow = pos.first + drow[i];
			int nCol = pos.second + dcol[i];
			if (nRow < n && nRow >= 0 && nCol < n && nCol >= 0 &&
				ch[nRow][nCol] == 0 && board[nRow][nCol] <= shark.lv)
			{
				ch[nRow][nCol] = ch[pos.first][pos.second] + 1;
				q.push({ nRow, nCol });
			}
		}
	}
	if (isEat)
	{
		// 큐 내부 검사
		while (!q.empty())
		{
			pair<int, int> pos = q.front();
			// 같은 거리인지 확인
			if (ch[pos.first][pos.second] == ch[targets[0].first][targets[0].second] &&
				// 먹을 수 있는 것인지 확인
				board[pos.first][pos.second] != 0 && board[pos.first][pos.second] < shark.lv)
			{
				targets.push_back(q.front());
			}
			q.pop();
		}
		// 먹이 대상 기준에 따라 정렬
		sort(targets.begin(), targets.end());
		// 최우선 먹이로 이동
		playTime += ch[targets[0].first][targets[0].second] - 1;
		board[targets[0].first][targets[0].second] = 0;
		shark.pos = targets[0];
		shark.combo++;
		if (shark.combo == shark.lv)
		{
			shark.lv++;
			shark.combo = 0;
		}
	}
}

int main()
{
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				shark.pos = { i, j };
				shark.lv = 2;
				shark.combo = 0;
				board[i][j] = 0;
			}
		}
	}
	while (isEat)
		bfs(board);
	cout << playTime;
}