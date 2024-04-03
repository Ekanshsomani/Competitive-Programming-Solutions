#include <bits/stdc++.h>

using namespace std;

const int INF = 20000;

int main()
{
    // person1 -> 25 years old
    // person2 -> 40+

    unordered_map<char, int> ageGroup{{'Y', 0}, {'M', 1}};
    set<int> meeting;

    int AM[2][26][26];
    int E;
    while(cin >> E and E)
    {
        memset(AM, INF, sizeof AM);
        while(E--)
        {
            char age, isBi, u, v;
            int w;
            cin >> age >> isBi >> u >> v >> w;
            AM[ageGroup[age]][u-'A'][v-'A'] = w;
            if(isBi == 'B')
                AM[ageGroup[age]][v-'A'][u-'A'] = w;
        }

        int count = 2;
        while(count --)
            for(int i=0; i<26; i++)
                AM[count][i][i] = 0;
        count = 2;
        while(count--)
            for(int k=0; k<26; k++)
                for(int i=0; i<26; i++)
                    for(int j=0; j<26; j++)
                        AM[count][i][j] = min(AM[count][i][j], AM[count][i][k]+AM[count][k][j]);

        char me, miguel;
        cin >> me >> miguel;

        int s0{me-'A'}, s1{miguel-'A'};

        int minTotal{INF<<1};
        for(int i=0; i<26; i++)
            if(AM[0][s0][i]<INF and AM[1][s1][i]<INF)
            {
                int curr = AM[0][s0][i] + AM[1][s1][i];
                if(curr==minTotal)
                    meeting.insert(i);
                else if(curr<minTotal)
                {
                    meeting.clear();
                    meeting.insert(i);
                    minTotal = curr;
                }
            }
        
        if(minTotal==INF<<1)
            printf("You will never meet.\n");
        else
        {
            printf("%d", minTotal);
            for(auto it: meeting)
                printf(" %c", it+'A');
            printf("\n");
        }

    }
    return 0;
}