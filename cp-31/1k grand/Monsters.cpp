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
		solve();
	}

	return 0;
}
bool sortbyCond(const pair<int, int> &a, const pair<int, int> &b) {
    // First element descending
    if (a.first != b.first) {
        return a.first > b.first;  // Sort by first in descending order
    }

    // Second element ascending (if first elements are equal)
    return a.second < b.second;  // Sort by second in ascending order
}

void solve() {
	int n,k;cin>>n>>k;
	vector<int>v(n);
	vector<pair<int,int>>vv;
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]%k==0){cout<<i+1<<" ";}
		else vv.push_back({v[i]%k,i+1});
	}
	sort(vv.begin(),vv.end(),sortbyCond);
	for(int i=0;i<vv.size();i++){
		cout<<vv[i].second<<" ";
	}
	cout<<endl;


}



