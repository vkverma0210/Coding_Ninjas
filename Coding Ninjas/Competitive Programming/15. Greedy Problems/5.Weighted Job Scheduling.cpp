/* You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap. */

#include<bits/stdc++.h>

using namespace std;

struct Job
{
	int start, finish, profit;
};

bool compare (Job a, Job b)
{
	return a.finish < b.finish;
}

int binarySearch(Job arr[], int index)
{
	int ans = -1, start = 0, end = index - 1;
	
	while(start <= end)
	{
		int mid = (start + end) / 2;
		if(arr[mid].finish <= arr[index].start)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	
	return ans;
}

int findMProfit(Job *arr,  int n)
{
	sort(arr, arr + n, compare);
	int *dp = new int[n]();
	dp[0] = arr[0].profit;

	for(int i = 1; i<n; i++)
	{
		int including = arr[i].profit;
		int excluding = dp[i - 1];
		int betterIndex = -1;
		betterIndex = binarySearch(arr, i);
		
		if(betterIndex != -1)
		{
			including += dp[betterIndex];
		}
				
		dp[i] = max(including, excluding);
	}
	
	int ans = dp[n - 1];
	delete [] dp;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	
	Job* arr = new Job[n];

	for(int i = 0; i<n; i++)
	{
		cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
	}

	cout << findMProfit(arr,  n);
    
	return 0;
}