#include <iostream>
#include <cstring>
using namespace std;

int cuts[51]; // n;

/*

// lower bound -> gives me first element >= val
// to get the closest use this element and the one before it.
// use whichever is closer to cut and recurse.

int getCost(int start, int length)
{
    // int ceidx{lower_bound(cuts, cuts+n, start+length) - cuts};
    int csidx{(int)(upper_bound(cuts, cuts+n, start) - cuts)};
    if(csidx>=n or cuts[csidx]>=start+length)
        return 0;

    int gmid{(int)(lower_bound(cuts, cuts+n, start+(length>>1)) - cuts)};
    int cutlocation;
    if(gmid>=n or cuts[gmid]>=(start+length))
    {
        while(cuts[csidx]<(start+(length>>1)))
            csidx++;
        cutlocation = cuts[csidx-1];
    }
    else if(gmid==0)
        cutlocation = cuts[gmid];
    else
    {
        cutlocation = 
        ((cuts[gmid]-(start+(length>>1)))<((start+(length>>1))-cuts[gmid-1])) ?
        cuts[gmid] : cuts[gmid-1];
    }

    printf(
        "Cutting for gmid: %d, cuts[gmid]: %d, cuts[gmid-1]: %d at: %d\n", 
        gmid, cuts[gmid], cuts[gmid-1], cutlocation);
    if(cutlocation==0) return 0;

    return length + 
    getCost(start, cutlocation-start) + 
    getCost(cutlocation, start+length-cutlocation);
}
/**/

// [n+2]*[n+2] states: given by the indexes of cutting locations of ends
    // we also store 0 at cuts[0] and l at cuts[n+1];
    // for all such states: find minimum cost
// function becomes minCost(int left, int right)
    // base case: left+1==right (no cuts possible) return 0;
    // iterate from left+1 to right (upto right-1)
    // and take minimum cost

int memo[51][51];

int minCost(int left, int right)
{
    if((left+1)==right)
        return 0;

    int &ans = memo[left][right];
    if(ans!=-1) return ans;

    ans = (right-left)*(cuts[right]-cuts[left]);
    for(int i=(left+1); i<right; i++)
        ans = min(ans, minCost(left, i)+minCost(i, right));
    ans += cuts[right]-cuts[left];

    return ans;
}

int main()
{
    int l;
    cuts[0] = 0;
    while(cin >> l and l)
    {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> cuts[i];
        cuts[n+1] = l;

        memset(memo, -1, sizeof memo);
        printf( "The minimum cutting is %d.\n" ,minCost(0, n+1));
    }
    return 0;
}