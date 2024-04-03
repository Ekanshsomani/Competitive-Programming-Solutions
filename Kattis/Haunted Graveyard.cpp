#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int, int> edgeTuple;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e7;

int rows, columns;
bool notIn[30][30], notOut[30][30];
// int dist[30][30];

inline bool isInside(int r, int c)
{
    return (r>-1 and c>-1 and r<rows and c<columns);
}


int main()
{
    int rAround[]{-1, 0, 1, 0};
    int cAround[]{0, 1, 0, -1};

    while(cin >> rows >> columns and (rows or columns))
    {
        memset(notIn, false, sizeof notIn);
        memset(notOut, false, sizeof notOut);

        int graves;
        cin >> graves;
        while(graves--)
        {
            int r, c;
            cin >> r >> c;
            notIn[r][c] = true;
        }

        int E;
        cin >> E;
        vector<edgeTuple> edgeList(E);

        while(E--)
        {
            int ur, uc, vr, vc, w;
            cin >> ur >> uc >> vr >> vc >> w;
            edgeList[E] = {ur, uc, vr, vc, w};
            notOut[ur][uc] = true;
        }
        notOut[rows-1][columns-1] = true;

        for(int i=0; i<rows; i++)
            for(int j=0; j<columns; j++)
                if(not notOut[i][j])
                    for(int k=0; k<4; k++)
                    {
                        int r = i+rAround[k];
                        int c = j+cAround[k];
                        if(isInside(r, c) and not notIn[r][c])
                            edgeList.emplace_back(i, j, r, c, 1);
                    }

        vector<vi> dist(rows, vi(columns, INF));

        int V = rows*columns;
        dist[0][0] = 0;
        for (int i = 0; i < V-1; ++i)  // total O(V*E)
        {
            bool modified{false};
            for(auto &[ur, uc, vr, vc, w]: edgeList)
                if(dist[ur][uc]!=INF and (dist[ur][uc]+w) < dist[vr][vc])
                {
                    dist[vr][vc] = dist[ur][uc]+w; // relax operation
                    modified = true; // optimization
                }
            if (not modified) break; // optimization
        }

        bool hasNegative{false};
        for (int i = 0; i < V and not hasNegative; ++i) // one more pass to check
            for(auto &[ur, uc, vr, vc, w]: edgeList)
                if (dist[ur][uc]!=INF and dist[ur][uc]+w < dist[vr][vc]) // should be false
                {
                    hasNegative = true;
                    break;
                }

        if(hasNegative) printf("Never\n");
        else if(dist[rows-1][columns-1]==INF) printf("Impossible\n");
        else printf("%d\n", dist[rows-1][columns-1]);
    }
    return 0;
}