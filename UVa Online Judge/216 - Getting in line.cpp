#include <bits/stdc++.h>
using namespace std;

double dist[8][8], minLength;
int x[8], y[8], n;
int path[8];
int bestPath[8];
set<pair<int, pair<int, double>>> memo;

inline double sqr(int p){ return (double)(p * p); }

void tsp(int node, int connect, int vis, double length)
{
    if(connect == n)
    {
        if(length < minLength)
        {
            minLength = length;
            for(int i=0; i<n; i++)
                bestPath[i] = path[i];
        }
        return;
    }
    if(memo.count({node, {vis, length}}))
        return;
    memo.insert({node, {vis, length}});

    for(int i=0; i<n; i++)
        if(not (vis & ( 1 << i)))
        {
            path[connect] = i;
            tsp(i, connect+1, vis|(1<<i), length + dist[node][i]);
        }
    return;
}

int main()
{
    int test{1};
    while(cin >> n and n)
    {

        for(int i=0; i<n; i++)
            cin >> x[i] >> y[i];

        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                dist[i][j] = sqrt(sqr(abs(x[j]-x[i])) + sqr(abs(y[j]-y[i]))) + 16.0;
                dist[j][i] = dist[i][j];
            }

        memo.clear();
        minLength = (double) INT_MAX;
        for(int i=0; i<n; i++)
        {
            path[0] = i;
            tsp(i, 1, 1<<i, 0.0);
        }

        printf("**********************************************************\n");
        printf("Network #%d\n", test++);
        for(int i=0; i<n-1; i++)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
            x[bestPath[i]], y[bestPath[i]], x[bestPath[i+1]], y[bestPath[i+1]],
            dist[bestPath[i]][bestPath[i+1]]);
        printf("Number of feet of cable required is %.2f.\n", minLength);
    }
    return 0;
}