#include <iostream>
using namespace std;

int pack[60];
int sole[60];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int minPack = 2147000000;
	int minSole = 2147000000;
	for (int i = 0; i < m; i++)
	{
		cin >> pack[i] >> sole[i];
		if (pack[i] < minPack) minPack = pack[i];
		if (sole[i] < minSole) minSole = sole[i];
	}
	int packCnt = n / 6;
	int leftCnt = n % 6;
	int res = 0;
	if (packCnt != 0)
	{
		if (packCnt * minPack < packCnt * 6 * minSole) res += packCnt * minPack;
		else res += packCnt * 6 * minSole;
	}
	if (leftCnt != 0)
	{
		if (leftCnt * minSole < minPack) res += leftCnt * minSole;
		else res += minPack;
	}
	cout << res;
	return 0;
}