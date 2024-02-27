// 1047

#include <iostream>
using namespace std;

int cserved[20], csa[10], csaCustomer[10];

int main()
{
    int tplanned, tbuilt, t{0};
    while(cin >> tplanned >> tbuilt && tplanned)
    {

        for(int i=0; i<tplanned; i++) cin >> cserved[i];

        int m;
        cin >> m;
        for(int i=0; i<m; i++) 
        {
            csa[i] = 0;

            int tNum;
            cin >> tNum;
            while(tNum--)
            {
                int tower;
                cin >> tower;
                csa[i] |= (1<<(tower-1));
            }

            cin >> csaCustomer[i];
        }

        int size {1<<tplanned}, maxc{0}, tchose;
        for(int i=0; i<size; i++)
        {
            int currentPoles{0};
            for(int j=0; j<tplanned; j++)
                if(i&(1<<j)) currentPoles++;
            if(currentPoles!=tbuilt) continue;

            int ans{0};

            for(int j=0; j<tplanned; j++)
                if(i&(1<<j))
                    ans += cserved[j];

            for(int j=0; j<m; j++)
            {
                int ctr{-1}, match{csa[j]&i};
                for(int k=0; k<tplanned; k++)
                    if(match&(1<<k))
                        ctr++;

                if(ctr>0)
                    ans -= csaCustomer[j]*ctr;
            }

            if(ans>maxc)
            {
                tchose = i;
                maxc = ans;
            }
            else if(ans==maxc)
                for(int j=0; j<tplanned; j++)
                {
                    int a = i&(1<<j);
                    int b = tchose&(1<<j);
                    if(a!=b)
                    {
                        if(a)
                            tchose = i;
                        break;
                    }
                }
        }

        t++;
        cout <<  "Case Number  " << t << endl;
        cout << "Number of Customers: " << maxc << endl;
        cout << "Locations recommended: ";
        int cnt{0};
        for(int i=0; i<=tplanned; i++)
            if(tchose&(1<<i))
            {
                cout << i+1;
                cnt++;
                if(cnt<tbuilt) cout << ' ';
            }

        cout << endl;
        cout << endl;
    }
    return 0;
}