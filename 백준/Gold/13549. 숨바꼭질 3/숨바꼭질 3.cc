#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[] = { 1 , -1 };
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> ch(100001, -1);
	queue<int> q;
	q.push(n);
	ch[n] = 0;
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		if (s == k) break;
		else if (s != 0)
		{
			int temp = 2 * s;
			while (temp <= 100000)
			{
				if (ch[temp] == -1 || ch[temp] > ch[s])
				{
					ch[temp] = ch[s];
					q.push(temp);
				}
				temp *= 2;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			if (s + dx[i] >= 0 && s + dx[i] <= 100000 &&
				ch[s + dx[i]] == -1)
			{
				ch[s + dx[i]] = ch[s] + 1;
				q.push(s + dx[i]);
			}
		}
	}
	cout << ch[k];
}