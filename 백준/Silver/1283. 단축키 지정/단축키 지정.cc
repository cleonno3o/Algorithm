#include <iostream>
#include <string>
using namespace std;

int N;
string opt[31];
int check[30];
bool isFound;
int main()
{
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; i++)
    {
        getline(cin, opt[i]);
        int start = 0;
        isFound = false;
        while (1)
        {
            int hotKey = (tolower(opt[i][start]) - 'a');
            if (check[hotKey] == 0)
            {
                check[hotKey] = 1;
                string key = "[" + string(1, opt[i][start]) + "]";
                opt[i].replace(start, 1, key);
                isFound = true;
                break;
            }
            else
            {
                int idx = opt[i].find(" ", start);
                if (idx == string::npos)
                    break;
                start = idx + 1;
            }
        }
        if (!isFound)
        {
            for (int j = 0; j < opt[i].length(); j++)
            {
                if (opt[i][j] != ' ' && check[tolower(opt[i][j]) - 'a'] == 0)
                {
                    check[tolower(opt[i][j]) - 'a'] = 1;
                    string key = "[" + string(1, opt[i][j]) + "]";
                    opt[i].replace(j, 1, key);
                    break;
                }
            }
        }
    }

    for (int i =1; i <= N; i++)
    {
        cout << opt[i] << "\n";
    }
}