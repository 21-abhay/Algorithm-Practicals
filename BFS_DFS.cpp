#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;


void BFS(vector<int> l[],int v,int e){
	cout<<"\n                   Calling BFS...";
	vector<int> layer[v];
	bool discovered[v]={false};
	int k=0;
	layer[k].push_back(0);
	discovered[0]=true;
	
	cout<<"\nSTART traversing : \n";
	while(!layer[k].empty()){
		cout<<"\n\nTraverse layer - "<<k+1;
		
		int size=layer[k].size();
		for(int i=0;i<size;i++){
			
			int x=layer[k][i];
			cout<<"\n     element : "<<x;
			for(int j=0;j<l[x].size();j++){
				
				int key=l[x][j];
				cout<<"\n             "<<key;
				if(discovered[key]==false){
					layer[k+1].push_back(key);
					discovered[key]=true;
					cout<<"  added SUCCESSFULLY.....";
				}
				else{
					cout<<" ALREADY added";
				}
			}
		}
		k=k+1;
	}
	
	int i=0;
	cout<<"\n\n----------------FINALLY-------------\n";
	while(!layer[i].empty()){
		cout<<"\nLayer - "<<i+1<<"  :  ";
		for(int j=0;j<layer[i].size();j++){
			int x=layer[i][j];
			cout<<" "<<x;
		}
		i++;
	}
}


void DFS(vector<int> l[],int v,int e){
	cout<<"\n                   Calling DFS...";
	vector<int> layer;
	vector<int> dfs;
	bool discovered[v]={false};
	int k=0;
	layer.push_back(0);
	
	cout<<"\nSTART traversing : \n";
	while(!layer.empty()){
		int x=layer.back();
		cout<<"\n vertices : "<<x;
		if(discovered[x]==false){
			dfs.push_back(x);
			layer.pop_back();
			discovered[x]=true;
			cout<<" : ADD to DFS tree......\n";
		}
		else{
			layer.pop_back();
			cout<<" : ALREADY added to DFS tree......\n";
			continue;;
		}
		
		for(int i=0;i<l[x].size();i++){
			int key=l[x][i];
			cout<<"\n        "<<key;
			if(discovered[key]==false){
				cout<<" add in STACK.";
				layer.push_back(key);
			}
			else{
				cout<<" DFS tree";
			}
		}
		
	}
	
	cout<<"\n\n----------------FINALLY-------------\n";
	cout<<"DFS :  ";
	for(int i=0;i<dfs.size();i++){
		cout<<" "<<dfs[i];
	}
}


int main(){
	int ver,ed;
	cout<<"Enter number of vertices : ";
	cin>>ver;
	cout<<"\nEnter number of edges : ";
	cin>>ed;
	
	char vertices[ver];
	cout<<"Enter vertices of the graph : ";
	for(int i=0;i<ver;i++){
		cin>>vertices[i];
	}
	vector<int> l[ver];
	
	cout<<"\nEnter vetices of Edges : ";
	for(int i=0;i<ed;i++){
		char s,d;
		cout<<"\nEdge-"<<i+1<<" : ";
		cin>>s>>d;
		int s1,d1;
		for(int j=0;j<ver;j++){
			if(vertices[j]==s){
				s1=j;
			}
			if(vertices[j]==d){
				d1=j;
			}
		}
		l[s1].push_back(d1);
		l[d1].push_back(s1);
	}
	
	DFS(l,ver,ed);
	
	return 0;
}

