/*
				PROBLEM STATEMENT
You want to paint your house. The total area of your house is D units. There are a total of N
workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes 
available for hiring from time Ti and remains available after that. Once available, you can hire
him with cost Xi, after which he will start painting the house immediately, covering exactly Yi 
units of house with paint per time unit. You may or may not hire a worker and can also hire or
fire him at any later point of time. However, no more than 1 worker can be painting the house
at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such 
that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.


*/

#include <bits/stdc++.h>

using namespace std;

bool mySort(vector<long long> a, vector<long long> b){
	
	if (a[0] == b[0]) {
		if (a[2] == b[2]) {
			return (a[1] < b[1]);
		}
		return (a[2] > b[2]);
	}
	return (a[0] < b[0]);
}

long long go(vector<vector<long long>> worker, long long area){
	long long n = worker.size();
	sort(worker.begin(),worker.end(),mySort);

	long long cost = worker.at(0)[1];
	long long area_done = 0;
	long long current_worker = 0;
	long long last = 0;

	for (int i = 1; i < n && area_done<area; ++i)
	{
		last = i-1;
		long long time_gap = worker.at(i)[0]-worker.at(last)[0];

		// cout << "Worker: "<<current_worker << '\n';
		// cout << "Timegap: "<<time_gap << '\n';
		
		area_done += time_gap*(worker.at(current_worker)[2]);

		// cout <<"Cost: "<<cost<< '\n';
		// cout <<"Area done: "<<area_done<< '\n'<<endl;

		
		if (area_done>=area)
		{
		
			return cost;
 			
		}
		if (worker.at(current_worker)[2]<worker.at(i)[2])
		{
			current_worker = i;
			cost += worker.at(current_worker)[1];
		}	
	}
	return cost;
}
/*

*/

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	long long n;
	long long d;
	cin>>n>>d;
	vector<vector<long long>> worker;

	while(n--){
		long long t,x,y;
		cin>>t>>x>>y;

		vector<long long> temp;
		temp.push_back(t);
		temp.push_back(x);
		temp.push_back(y);

		worker.push_back(temp);
	}
	cout << go(worker, d) << '\n';
	return 0 ; 
}


/*
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
  
// Main greedy function to solve problem 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    //    sorting Item on basis of ratio 
    sort(arr, arr + n, cmp); 
  
    //    Uncomment to see new order of Items with their ratio 
    /* 
    for (int i = 0; i < n; i++) 
    { 
        cout << arr[i].value << "  " << arr[i].weight << " : " 
             << ((double)arr[i].value / arr[i].weight) << endl; 
    } 
    */
  
/*   int curWeight = 0;  // Current weight in knapsack 
    double finalvalue = 0.0; // Result (value in Knapsack) 
  
    // Looping through all Items 
    for (int i = 0; i < n; i++) 
    { 
        // If adding Item won't overflow, add it completely 
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        // If we can't add current Item, add fractional part of it 
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
  
    // Returning final value 
    return finalvalue; 
} 
*/