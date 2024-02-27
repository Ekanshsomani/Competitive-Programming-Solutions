// 11201

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


int n;
double total, sum;

double probs[26]
{
    12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00,
    4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 
    0.02, 0.22, 0.90, 0.52
};

unordered_set<int> vowels = {0, 4, 8, 'o'-'a', 'u'-'a'};
char vowel[5] {'a', 'e','i','o','u'};

int count[26] = {0};

void generateAv(double score, int index)
{
    if(index==n)
    {
        sum += score;
        total++;
        return;
    }

    if(index%2==1)
    {
        for(char i='a'; i<(26+'a'); i++)
            if(not vowels.count(i-'a') and count[i-'a']<2)
            {
                count[i-'a']++;
                generateAv(score + index*probs[i-'a'], index+1);
                count[i-'a']--;
            }
    }
    else
    {
        for(auto it: vowel)
            if(count[it-'a']<2)
            {
                count[it-'a']++;
                generateAv(score+index*probs[it-'a'], index+1);
                count[it-'a']--;
            }
    }
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        sum = 0;
        total = 0;

        string s;
        cin >> s;
        n = s.size()+1;

        generateAv(probs[s[0]-'a'], 2);

        double score{0};
        for(int i=0; i<s.size(); i++)
            score += (i+1)*probs[s[i]-'a'];

        if(score>=(sum/total))
            printf("above or equal\n");
        else
            printf("below\n");
    }
    return 0;
}
