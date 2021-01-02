#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	cout <<"("<< arr[i].first << "->" << arr[i].second <<")";
	// }
	// cout << endl;

	sort(arr.begin(), arr.end());

	// for (int i = 0; i < n; i++)
	// {
	// 	cout <<"("<< arr[i].first << "->" << arr[i].second <<")";
	// }
	// cout << "\n";
	int i = 0, j = n - 1;
	while (i < j)
	{
		//cout <<"("<< arr[i].first << "+" << arr[j].first <<") = "<<arr[i].first + arr[j].first << endl;
        // if got the target
		if (arr[i].first + arr[j].first == x)
		{
			cout << arr[i].second << " " << arr[j].second;
			return 0;
		}
        // smaller than target then increase starting e.i i++
		if (arr[i].first + arr[j].first < x)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
