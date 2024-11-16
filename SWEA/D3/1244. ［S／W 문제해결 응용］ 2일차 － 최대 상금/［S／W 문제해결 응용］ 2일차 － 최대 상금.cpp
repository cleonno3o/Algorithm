#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int T;
vector<int> num;
int maxMoney;
vector<int> nToVector(int n)
{
	vector<int> res;
	while (1)
	{
		res.push_back(n % 10);
		n /= 10;
		if (n == 0) break;
	}
	reverse(res.begin(), res.end());
	return res;
}
void runTest()
{
	maxMoney = 0;
	int n, change;
	cin >> n >> change;
	set<int> ch[11];
	ch[0].insert(n);
	int digits = nToVector(n).size();
	for (int i = 1; i <= change; i++)
	{
		for (set<int>::iterator j = ch[i - 1].begin(); j != ch[i - 1].end(); j++)
		{
			vector<int> target = nToVector(*j);
			for (int k = 0; k <= target.size() - 2; k++)
			{
				for (int l = k + 1; l <= target.size() - 1; l++)
				{
					swap(target[k], target[l]);
					int currN = 0;
					for (int m = 0; m < target.size(); m++)
					{
						currN = currN * 10 + target[m];
					}
					ch[i].insert(currN);
					swap(target[k], target[l]);
				}
			}
		}
	}
	cout << *ch[change].rbegin() << "\n";
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cout << "#" << i << " ";
		runTest();
	}
	return 0;
}