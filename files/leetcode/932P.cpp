#include <vector>
#include <iostream>
#include <string>

using namespace std;



vector<int> beautifulArray(int N) {
     if(N == 1) 
          return {1};
     vector<int> odd = beautifulArray((N+1)/2);
     vector<int> even = beautifulArray(N/2);
     vector<int> ans;
     for(int i : odd)
          ans.push_back(i*2-1);
     for(int i : even)
          ans.push_back(i*2);
     return ans;
}

int main(){
     int n;
     cin >> n;
     vector<int> ans;
     ans = beautifulArray(n);
     for(int i = 0; i < ans.size(); ++i)
     {
          cout << ans[i] << endl;
     }
     return 0;
}