#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b){
	return a.first > b.first;
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input2.txt","r",stdin);
		freopen("output2.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	
	int p[n];
	int d[n];
	
	for(int i=0;i<n;i++)
		cin>>p[i];
	
	for(int i=0;i<n;i++)
		cin>>d[i];
	
	vector<pair<int,int> > jobs;
	
	int profit,deadline;
	
	for(int i=0;i<n;i++){
		jobs.push_back(make_pair(p[i],d[i]));
	}
	
	sort(jobs.begin(),jobs.end(),compare);
	int maxEndTime = 0;
	
	for(int i=0;i<n;i++){
		if(jobs[i].second > maxEndTime)
			maxEndTime = jobs[i].second;
	}
	
	vector<int> ans;
	int fill[maxEndTime];
	int count = 0, maxProfit = 0;
	
	for(int i=0;i<n;i++) fill[i] = -1;
		for(int i=0;i<n;i++){
			int j = jobs[i].second - 1;
			while(j>=0 && fill[i]!=-1) j--;
			if(j>=0 && fill[j]==-1){
				fill[j] = i;
				ans.push_back(i);
				count++;
				maxProfit = maxProfit + jobs[i].first;
			}
		}
	
	cout<<"Maximum no of tasks : "<<count<<endl;
	cout<<"Selected task numbers : ";
	
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	
	return 0;
}
