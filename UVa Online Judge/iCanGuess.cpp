// 11995

#include <iostream>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

int main()
{
    int cmds;
    while(cin >> cmds)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bitset<3> valid("111");

        while(cmds--)
        {
            int op, el;
            cin >> op >> el;

            if(op==1)
            {
                if(valid[0]) s.push(el);
                if(valid[1]) q.push(el);
                if(valid[2]) pq.push(el); 
            }
            else
            {
                if(valid[0]) 
                {
                    if(s.empty() || s.top()!=el) 
                        valid[0] = 0;
                    else
                        s.pop();
                }
                if(valid[1])
                {
                    if(q.empty() || q.front()!=el)
                        valid[1] = 0;
                    else
                        q.pop();
                }
                if(valid[2])
                {
                    if(pq.empty()||pq.top()!=el)
                        valid[2]=0;
                    else
                        pq.pop();
                }
            }
        }
    
        if(valid.count()==1)
        {
            if(valid[0]) cout << "stack";
            else if(valid[1]) cout << "queue";
            else cout << "priority queue";
        }
        else if(valid.count()>1)
            cout << "not sure";
        else 
            cout << "impossible";
        
        cout << endl;

    }
    return 0;
}
