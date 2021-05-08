#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<bool> > vvb;

int lis(vi &v){
    int n = v.size(), left = 0, right = 0, midpoint = 0;
    vi dp;
    dp.push_back(v[0]);
    for(int i = 1; i < n; i++){
        left = 0, right = dp.size() - 1;
        while(left < right){
            midpoint = left + (right - left)/2;
            dp[midpoint] < v[i] ? left = midpoint + 1 : right = midpoint;
        }
        if(left == dp.size() - 1){
           if(dp[left] >= v[i]) dp[left] = v[i];
           else dp.push_back(v[i]);
        }
        else{
            if(dp[left] > v[i]) dp[left] = v[i];
        }
    }
    return dp.size();
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(); 

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int max_len = lis(v);
    cout << max_len << '\n';
}
