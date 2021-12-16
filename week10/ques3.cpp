#include <bits/stdc++.h>
using namespace std;

string majorityElement(int *arr, int n)
{
	int count = 1, max_ele = -1, temp = arr[0], ele, f=0;
	for(int i=1;i<n;i++)
	{
		if(temp==arr[i])
		{
			count++;
		}
		else
		{
			count = 1;
			temp = arr[i];
		}
		if(max_ele<count)
		{
			max_ele = count;
			ele = arr[i];
			if(max_ele>(n/2))
			{
				f = 1;
				break;
			}
		}
	}
	return (f==1 ? "yes" : "no");
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input3.txt","r",stdin);
		freopen("output3.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr, arr+n);

	cout<<majorityElement(arr, n)<<endl;

	if(n%2 == 0){
		cout<<(arr[n/2 -1]+arr[n/2])/2;
	}
	else{
		cout<<arr[n/2];
	}

	return 0;
}
