#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(v) v.begin(),v.end()
const int inf = 1e9;
const int N = 1e6 +7;

#define alliswell Things will get better


void solve();
int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--){
		solve();}

		return 0;
	}
	void solve()
	{
		string s;cin>>s;
		int cnt0=0,cnt1=0;
		int n=s.size();
		for(int i=0;i<n;i++){
			if(s[i]=='0')cnt0++;
			else cnt1++;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if((s[i]=='1' and cnt0==0) or (s[i]=='0' and cnt1==0))break;
			else if(s[i]=='1' and cnt0>0){cnt0--;cnt++;}
			else if(s[i]=='0' and cnt1>0){cnt1--;cnt++;}
		}
		cout<<n-cnt<<endl;
	}

/* logic: The logic balances the string using swaps as long as possible and deletes any leftover characters that can't be swapped to achieve the good condition.
swaps: While there are both '0's and '1's remaining, the algorithm simulates balancing them through deletions, which allows for free swaps.
deletions: Once one type of character runs out (no '0's or no '1's left), the remaining characters must be deleted since no more swaps are possible to create a good string.
*/


