#include <iostream>
#include <string>
#include <deque>
using namespace std;
struct Gear {
	deque<int> info;
	int dir = 0;
};
constexpr int N = 0;
constexpr int S = 1;
Gear gears[5];
void rotate(Gear& gear, int dir)
{
	// 반시계방향
	if (dir == -1)
	{
		int temp = gear.info.front();
		gear.info.pop_front();
		gear.info.push_back(temp);
	}
	// 시계
	else if (dir == 1)
	{
		int temp = gear.info.back();
		gear.info.pop_back();
		gear.info.push_front(temp);
	}
}
int main()
{
	for (int i = 1; i <= 4; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++)
			gears[i].info.push_back(temp[j] - '0');
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int num, dir;
		cin >> num >> dir;
		gears[num].dir = dir;
		for (int j = num - 1; j > 0; j--)
		{
			if (gears[j].info[2] != gears[j + 1].info[6])
				gears[j].dir = -gears[j + 1].dir;
			else
				gears[j].dir = 0;
		}
		for (int j = num + 1; j <= 4; j++)
		{
			if (gears[j].info[6] != gears[j - 1].info[2])
				gears[j].dir = -gears[j - 1].dir;
			else
				gears[j].dir = 0;
		}
		for (int j = 1; j <= 4; j++)
		{
			rotate(gears[j], gears[j].dir);
		}
	}
	int res = 0;
	for (int i = 1; i <= 4; i++)
	{
		int headValue = gears[i].info[0];
		if (headValue == S)
		{
			switch (i)
			{
			case 1:
				res += 1;
				break;
			case 2:
				res += 2;
				break;
			case 3:
				res += 4;
				break;
			case 4:
				res += 8;
				break;
			}
		}
	}
	cout << res;
}