// two pointer


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
	int n,d;cin>>n>>d;
	vector<int>v(n);
	for(int i=0;i<n;i++)cin>>v[i];
		sort(v.begin(),v.end());
	int win=0;
	int i=-1,j=n-1;
	while(i<j){
		int k=1;
		while(k*v[j]<=d){
			i++;
			if(i==j)break;
			k++;

		}
		if(k*v[j] > d)
			win++;

		//i++;
		j--;		
	}
	cout<<win<<endl;

}

