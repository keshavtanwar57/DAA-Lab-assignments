#include<bits/stdc++.h>
using namespace std;

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input2.txt","r",stdin);
		freopen("output2.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	
	vector<double> items(n);
	vector<double> val(n);
	vector<vector<double>> job;//to store pair of
	
	for(int i=0;i<n;i++){
		cin>>items[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>val[i];
		job.push_back({val[i]/items[i],items[i], i+1});
	}
	
	double k;
	cin>>k;
	
	sort(job.rbegin(), job.rend());//sort acc to val per wt
	
	vector<pair<double,double>> ls;
	
	float profit =0;
	
	for(int i=0;i<n;i++)
	{
		if(job[i][1] >= k)
		{
			profit += k*job[i][0];
			ls.push_back(make_pair(k, job[i][2]));
			break;
		}
		else
		{
			profit += job[i][1]*job[i][0];
		}
		ls.push_back(make_pair(job[i][1], job[i][2]));
		k = k - job[i][1];
	}
	
	cout<<"Maximum Value is: "<<profit<<endl;
	cout<<"Item - Weight"<<endl;
	
	for(auto it: ls)
		cout<<it.first<<" - "<<it.second<<endl;
	
	return 0;
}
