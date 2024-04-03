#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;

    int steps[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_map<char, int> dirIndex{{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
    char charDir[4]{'N', 'E', 'S', 'W'};
    set<pair<int, int>> lost;

    int x, y, dir;
    char direction;
    while(cin >> x >> y >> direction)
    {
        dir = dirIndex[direction];

        string instructions;
        cin >> instructions;
        bool jumped{false};

        for(auto it: instructions)
            if(it == 'R')
                dir = (dir+1)%4;
            else if (it == 'L')
                dir = (dir==0 ? 3 : dir-1);
            else
            {
                x += steps[dir][0];
                y += steps[dir][1];
                if(x<0 or y<0 or x>X or y>Y)
                {
                    x -= steps[dir][0];
                    y -= steps[dir][1];
                    jumped = !lost.count({x, y});
                    if(jumped)
                    {
                        lost.insert({x, y});
                        break;
                    }
                }
            }

        printf("%d %d %c", x, y, charDir[dir]);
        cout << (jumped ? " LOST\n" : "\n");
        
    }

    return 0;
}