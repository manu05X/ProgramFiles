//https://cses.fi/problemset/task/1731

// using namespace std;
// #define ll long long

// ll numWays(vector<string>& words, string target) 
// {
//    int n = target.length(), mod = 1e9 + 7;
//         vector<long> res(n + 1);
//         res[0] = 1;
//         for (int i = 0; i < words[0].length(); ++i) 
//         {
//             vector<int> count(26);
//             for (auto& w : words)
//                 count[w[i] - 'a']++;
//             for (int j = n - 1; j >= 0; --j) 
//             {
//                 res[j + 1] += res[j] * count[target[j] - 'a'] % mod;
//             }
//         }
//         return res[n] % mod;
// }
    
// int main()
// {
//     string target;
//     cin >> target;
//     int k ;
//     cin >> k ;
//     vector<string> words(k);
//     while(k--)
//     {
//         cin >> words[k];
//     }

//     ll n = numWays(words,target);
//     cout << n;

//     return 0;
// }
#include <bits/stdc++.h>
 
using namespace std;
 
int64_t n;
string target;
string s;
int64_t MOD = 1000000007;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> target >> n;

  map<pair<int64_t, char>, int64_t> chars_per_pos;

  for (int64_t i = 0; i < n; i++) 
  {
    cin >> s;
    for (int64_t j = 0; j < s.size(); j++) 
    {
      chars_per_pos[{j, s[j]}]++;
    }
  }
  int64_t total = 0;
  for (int64_t mask = 0; mask < (1 << 20); mask++) 
  {
    if (__builtin_popcount(mask) != target.size()) 
    {
      continue;
    }
    int64_t idx = 0;
    int64_t temp = 1;
    for (int64_t j = 0; j < 20; j++) {
      if (mask & (1 << j)) {
        temp = (temp * chars_per_pos[{j, target[idx]}]) % MOD;
        idx++;
      }
    }
    total = (total + temp) % MOD;
  }
  cout << total << '\n';
}

