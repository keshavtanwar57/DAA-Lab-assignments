#include<bits/stdc++.h>
using namespace std;

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input1.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	vector<int> st(n), dline(n);
	vector<vector<int>> activity;

	for(int i=0;i<n;i++){
		cin>>st[i];
	}

	for(int i=0;i<n;i++){
		cin>>dline[i];
		activity.push_back({dline[i],st[i], i+1});
	}

	sort(activity.begin(), activity.end());

	vector<int> selected;
	int count=0;
	int currentEnd = -1;

	for(int i=0;i<n;i++){
		if(activity[i][1]>currentEnd){
			count++;
			currentEnd = activity[i][0];
			selected.push_back(activity[i][2]);
		}
	}

	cout<<"No. of non-conflictin activities: "<<count<<endl;
	cout<<"List of selected activites: ";

	for(auto i: selected){
		cout<<i<<" ";
	}
	return 0;
}
