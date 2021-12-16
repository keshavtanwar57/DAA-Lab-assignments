#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input1.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

	int n;
	cout<<"for values INF enter -1"<<endl;
	cin>>n;
	int a;

	int arr[n][n], dist[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a;
			if(a<0){
				arr[i][j] = INF;
			}
			else
				arr[i][j] = a;
			dist[i][j] = arr[i][j];
		}
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][k]+dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}

	cout<<"Shortest Distance Matrix: "<<endl;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]==INF){
				cout<<"INF ";
			}
			else
				cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
