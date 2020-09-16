#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.
vector<long> getPrevSmaller(vector<long>& arr) {
  int n = arr.size();
  vector<long> result(n + 1, -1);
  stack<long> s;
  s.push(0);
  result[0] = -1;
  for (int i = 1; i < n; i++) {
    while (!s.empty() && arr[s.top()] >= arr[i])
      s.pop();

    result[i] = (s.empty()) ? -1 : (s.top());
    s.push(i);
  }

  return result;
}

vector<long> getNextSmaller(vector<long>& arr) {
  int n = arr.size();
  vector<long> result(n + 1, n);
  stack<long> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && arr[s.top()] > arr[i]) {
      result[s.top()] = i;
      s.pop();
    }

    s.push(i);
  }

  return result;
}

vector<long> riddle(vector<long> arr) {
  int n = arr.size();
  vector<long> ans(n + 1, 0);
  vector<long> nextSmallerElements = getNextSmaller(arr);
  vector<long> prevSmallerElements = getPrevSmaller(arr);

  for (int i=0; i<n; i++) {
    int len = nextSmallerElements[i] - prevSmallerElements[i] - 1; 
    ans[len] = max(ans[len], arr[i]); 
  } 

  for (int i = n-1; i >= 1; i--) 
    ans[i] = max(ans[i], ans[i+1]);

  ans.erase(ans.begin());
  return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
