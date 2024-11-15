#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    for (int height = 1; height <= total; height++)
    {
        if (total % height != 0) continue;
        int width = total / height;
        if (width < height) break;
        if (height <= 2 && yellow == 0)
        {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
        else if (height >= 3)
        {
            
            int yellowArea = (height - 2) * (width - 2);
            
            if ( yellowArea == yellow && total - yellowArea == brown)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}