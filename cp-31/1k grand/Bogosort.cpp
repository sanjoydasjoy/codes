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
	int n;cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for (int i = n-1; i >= 0; i--)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
 
 
}
