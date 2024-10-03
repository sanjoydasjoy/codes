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
void solve() {
    int n;cin>>n;
    vector<pair<int,int>>v,u;
    while(n--){
    	int m;cin>>m;
    	vector<int>vv(m);
    	for(int i=0;i<m;i++){
    		cin>>vv[i];
    	}
    	sort(vv.begin(),vv.end());
    	v.push_back({vv[1],vv[0]});
    	u.push_back({vv[0],vv[1]});
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    int sum=0;
    for(int i=1;i<v.size();i++){
    	sum+=v[i].first;
    	//cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<sum+min(v[0].second,u[0].first)<<endl;
    
}



/*
3
2
2
1 2
2
4 3
1
3
100 1 6
3
4
1001 7 1007 5
3
8 11 6
2
2 9
*/
