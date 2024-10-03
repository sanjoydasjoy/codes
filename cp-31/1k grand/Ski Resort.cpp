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
 
	if (a.first != b.first) {
		return a.first > b.first; 
	}
	return a.second < b.second; 
}
 
long long factorial(int n) {
    long long result = 1; 
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
long long nPr(int n, int r) {
    return factorial(n) / factorial(n - r);
}
 
void solve() {
	int n,k,q;cin>>n>>k>>q;
	std::vector<int> v(n),u;
	int cnt1=0,cnt2=0,sum=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		//if(v[i]<=q)cnt1++;
	}
	for (int i = 0; i < n; ++i)
	{
		if(v[i]<=q){
			cnt2++;
		} else {
			if(cnt2>=k)u.push_back(cnt2);
			cnt2=0;
		}
	}
	if(cnt2>=k)u.push_back(cnt2);
	for (int i = 0; i < u.size(); ++i)
	{
		//cout<<u[i]<<" "<<endl;
		int x = u[i]-k+1;
		int y = (u[i]-k+2);
 
		sum+=((x*y)/2);
 
	}
	
	cout<<sum<<endl;
 
 
}
