#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>& a, const pair<int, int>& b){
	return b.first > a.first;
}

vector<int> parent(100);
vector<int> sz(100);

void make_set(int v)
{
	parent[v]=v;
	sz[v] = 1;
}

int find_set(int v)
{
	if(v==parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b){//dont belong to same set
		if(sz[a] < sz[b])
			swap(a,b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input3.txt","r",stdin);
		freopen("output3.txt","w",stdout);
	#endif

	int n,e;
	cin>>n>>e;
	for(int i=0;i<n;i++)
		make_set(i);
	
	vector<vector<int>> graph;
	
	for(int i=0;i<e;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph.push_back({w,u,v});
		graph.push_back({w,v,u});
	}
	
	sort(graph.rbegin(), graph.rend());//sort according to weight
	
	int total_weight = 0;
	
	for(auto i: graph){
		int w = i[0];
		int u = i[1];
		int v = i[2];
		int x = find_set(u);
		int y = find_set(v);
		if(x == y){
			continue;
		}
		else{
		//cout<<u<<" "<<v<<endl;
				total_weight += w;
		union_set(u,v);//add to set
		}
	}
	
	cout<<"Maximum Spanning Weight is: "<<total_weight;
	return 0;
}
