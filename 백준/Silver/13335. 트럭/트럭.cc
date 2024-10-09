#include <iostream>
#include <vector>
using namespace std;
int n, bridgeLen, limitWeight;
int bridge[100];
int truck[1000];
int truckIdx;
int currWeight, currCnt;
int main()
{
	cin >> n >> bridgeLen >> limitWeight;
	for (int i = 0; i < n; i++)
		cin >> truck[i];
	int elapsedTime = 0;
	while (1)
	{
		if (currWeight == 0 && truckIdx == n) break;
		else
		{
			// 한칸 이동
			// 머리 무게가 0이아니면 트럭이 빠지는 것
			if (bridge[0] != 0)
			{
				currCnt--;
				currWeight -= bridge[0];
			}
			// 한칸씩 밀기
			for (int i = 0; i < bridgeLen - 1; i++)
			{
				bridge[i] = bridge[i + 1];
			}
			bridge[bridgeLen - 1] = 0;
			// 추가로 올릴수있으면 올림
			if (truckIdx < n && currCnt < bridgeLen && currWeight + truck[truckIdx] <= limitWeight)
			{
				bridge[bridgeLen - 1] = truck[truckIdx];
				currWeight += truck[truckIdx];
				currCnt++;
				truckIdx++;
			}
			elapsedTime++;
		}
	}
	cout << elapsedTime;
}