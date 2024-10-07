#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cand[51] = { 0 };
	int maxAddition = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> cand[i];
		if (i != 1) maxAddition += cand[i];
	}
	int addition = 0;
	for (addition = 0; addition <= maxAddition; addition++)
	{
		int myVote = cand[1] + addition;
		int leftVote = addition;
		bool flag = true;
		for (int j = 2; j <= n; j++)
		{
			if (cand[j] >= myVote)
			{
				int needAmount = cand[j] - myVote + 1;
				if (needAmount > leftVote)
				{
					flag = false;
					break;
				}
				else
				{
					leftVote -= needAmount;
				}
			}
		}
		if (flag)
			break;
	}
	cout << addition;
}