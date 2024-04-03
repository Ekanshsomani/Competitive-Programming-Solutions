// 514

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int temp;

		while(cin >> temp && temp){
			stack<int> des;
			des.push(temp);

			for(int i=1; i<n; i++){
				cin >> temp;
				des.push(temp);
			}

			stack<int> station;
			int a{1};
			bool pos{1};

			while(!des.empty()){
				int curr = des.front();
				des.pop();

				if(curr>=a){
					for(int i=a; i<curr; i++)
						station.push(i);
					a = curr+1;
				}
				else if(curr == station.top()) 
					station.pop();
				else{
					pos = 0;
					break;
				}
			}


			if(pos) cout << "Yes\n";
			else cout << "No\n";	

			
		}
		cout << endl;
	}
	return 0;
}