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
		int n,k;cin>>n>>k;
		vector<int>v(n);
		int mn=inf;
		int even=0;
		for(int i=0;i<n;i++){
			int el;cin>>el;
			if(el%2==0)even++;
			int x = (((el+k-1)/k) *k)-el;
			mn = min(mn, x);
		}
		if(k!=4)cout<<mn<<endl;
		else {
			if(even==1)cout<<min(mn,(int)1)<<endl;
			else if(even==0)cout<<min(mn,(int)2)<<endl;
			else cout<<0<<endl;
		}

	}

/* logic: since 2,3,5 are prime, we need atleast one 2,3,4 in the array so that the total multiplication is divisible by k. 
its because prime numbers are divisible by themselves and 1 only.
when it comes to composite numbers, like 4. it has other factors like we can make 2*2 and make this dvisible by 4
so we need to take care of this '4' case 
so we will find the minimum way to make a number 4, also we will find out how many even numbers are there. and work this way. */



