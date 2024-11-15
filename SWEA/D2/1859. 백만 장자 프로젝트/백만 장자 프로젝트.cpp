#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
		int N;
		cin >> N;
		vector<int> ch(N);
		vector<int> cost(N);
		for (int i = 0; i < N; i++)
		{
			cin >> cost[i];
		}
		int maxCost = -1;
		for (int i = N - 1; i >= 0; i--)
		{
			if (cost[i] > maxCost) maxCost = cost[i];
				ch[i] = maxCost;
		}
		long long res = 0;
		for (int i = 0; i < N; i++)
		{
			if (cost[i] < ch[i]) res += ch[i] - cost[i];
		}
		cout << res << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}