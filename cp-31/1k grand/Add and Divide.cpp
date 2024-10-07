#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(v) v.begin(),v.end()
#define ho cout<<"YES"<<endl
#define na cout<<"NO"<<endl
#define show(x) for(auto i:x)cout<<i<<" ";cout<<endl;
const int inf = 1e9;
const int N = 1e6 +7;

#define alliswell Things will get better


int dp[3005][3005];
int mark[3005][3005];
vector<int>prime;
string s1,t1;

void solve();
int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
void solve()
{
	int a,b;cin>>a>>b;
	int mn=inf;
	for(int i=0;i<=30;i++){
		int step=0;
		int temp_b = b;
		int temp_a = a;

		if(temp_b==1){
			temp_b++;
			step++;
		}
		temp_b+=i;
		step+=i;
		while(temp_a>0){
			temp_a/=temp_b;
			step++;
		}
		mn=min(mn,step);
	}
	cout<<mn<<endl;

}

