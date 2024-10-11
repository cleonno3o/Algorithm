#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Beacon {
	pair<int, int> pos;
	int cover;
	int power;
	
	bool operator<(const Beacon& b) const
	{
		if (power != b.power) return power > b.power;
	}
};
// 입력
int test_case;
int T;
int M, A;
int Adir[101], Bdir[101];
int drow[] = { 0, 0, 1, 0, -1 };
int dcol[] = { 0, -1, 0, 1, 0 };
Beacon beacons[9];
pair<int, int> apos;
pair<int, int> bpos;
int totalCharge;
void getInput()
{
	cin >> M >> A;
	for (int i = 1; i <= M; i++)
		cin >> Adir[i];
	for (int i = 1; i <= M; i++)
		cin >> Bdir[i];
	for (int i = 1; i <= A; i++)
	{
		int r, c, cover, power;
		cin >> r >> c >> cover >> power;
		beacons[i].pos = make_pair(r, c);
		beacons[i].cover = cover;
		beacons[i].power = power;
	}
	// Initialize
	apos = make_pair(1, 1);
	bpos = make_pair(10, 10);
	Adir[0] = Bdir[0] = 0;
	totalCharge = 0;
}
int getDist(pair<int, int> pos1, pair<int, int> pos2)
{
	return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}
void movePlayer(int turn)
{
	apos.first += drow[Adir[turn]];
	apos.second += dcol[Adir[turn]];
	bpos.first += drow[Bdir[turn]];
	bpos.second += dcol[Bdir[turn]];
}
void charge()
{
	vector<Beacon> Acand;
	vector<Beacon> Bcand;
	for (int i = 1; i <= A; i++)
	{
		if (getDist(apos, beacons[i].pos) <= beacons[i].cover) 
			Acand.push_back(beacons[i]);
		if (getDist(bpos, beacons[i].pos) <= beacons[i].cover)
			Bcand.push_back(beacons[i]);
	}
	sort(Acand.begin(), Acand.end());
	sort(Bcand.begin(), Bcand.end());
	int prev = totalCharge;
	if (Acand.size() == 0 && Bcand.size() == 0) totalCharge += 0;
	else if (Acand.size() == 0 && Bcand.size() >= 1) 
		totalCharge += Bcand[0].power;
	else if (Acand.size() >= 1 && Bcand.size() == 0)
		totalCharge += Acand[0].power;
	else if (Acand[0].pos != Bcand[0].pos) 
		totalCharge += (Acand[0].power + Bcand[0].power);
	else
	{
		if (Acand.size() == 1 && Bcand.size() == 1) 
			totalCharge += Acand[0].power;
		else if (Acand.size() == 1 && Bcand.size() >= 2) 
			totalCharge += (Acand[0].power + Bcand[1].power);
		else if (Bcand.size() == 1 && Acand.size() >= 2)
			totalCharge += (Acand[1].power + Bcand[0].power);
		else
		{
			int maxCharge = max((Acand[0].power + Bcand[1].power),
				(Acand[1].power + Bcand[0].power));
			totalCharge += maxCharge;
		}
	}
}
int main()
{
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		getInput();
		for (int i = 0; i <= M; i++)
		{
			movePlayer(i);
			charge();
		}
		cout << "#" << test_case << " " << totalCharge << "\n";
	}
	return 0;
}