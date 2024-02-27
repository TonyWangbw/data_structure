#include<iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void Creatgraph(string name[],int **m1,int n) {
	cout<<"城市的名字："<<endl;
	for(int i=0; i<n; i++) {
		cin>>name[i];
	}
	cout<<"城市之间的道路数："<<endl;
	int k,z,a,b,c;
	cin>>k;
	cout<<"输入各城市之间的距离："<<endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			m1[i][j]=9999;
		}
	for(int i=0; i<k; i++) {
		cin>>a;
		cin>>b;
		cin>>c;
		m1[a-1][b-1]=c;
		m1[b-1][a-1]=c;
	}
	cout<<"构造完成"<<endl;
}

void Dijkstra(int n,int **m1,string *name) {
	cout<<"请输入想要查找的城市姓名："<<endl;
	string s;
	cin>>s;
	int start;
	for(start=0; start<n; start++) {
		if(name[start]==s)
			break;
	}
	int dist1[n];
	memset(dist1,9999,sizeof dist1);
	int st[n];
	memset(st,0,sizeof st);
	dist1[start]=0;
	for(int i=0; i<n; i++) {
		int t=-1;
		for(int j=0; j<n; j++)
			if(!st[j]&&(t==-1||dist1[t]>dist1[j]))
				t=j;
		st[t]=1;
		for(int j=0; j<n; j++)
			if(dist1[j]>dist1[t]+m1[t][j])
				dist1[j]=dist1[t]+m1[t][j];
	}
	for(int i=0; i<n; i++) {
		if(i!=start) {
			cout<<name[start]<<"->"<<name[i]<<"的最短距离为:"<<dist1[i]<<endl;
		}
	}
}

void Floyd(int n,int **m1,string *name) {
	cout<<"请输入想要查找的两个城市名字"<<endl;
	string s,l;
	cin>>s>>l;
	int start,end;
	for(start=0; start<n; start++) {
		if(name[start]==s)
			break;
	}
	for(end=0; end<n; end++) {
		if(name[end]==l)
			break;
	}
	int dist2[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			dist2[i][j]=m1[i][j];
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dist2[i][j]=min(dist2[i][j],dist2[i][k]+dist2[k][j]);
	cout<<name[start]<<"->"<<name[end]<<"的最短距离为:"<<dist2[start][end]<<endl;
}

int main() {
	cout<<"请输入交通咨询系统的城市总数："<<endl;
	int n;
	cin>>n;
	int **m1=new int*[n];
	for(int i=0; i<n; i++)
		m1[i]=new int[n];
	string name[n];
	cout<<"1.时间"<<endl<<"2.路程"<<endl<<"3.费用"<<endl;
	int a;
	cin>>a;
	cout<<"1.建立交通网络图的存储结构"<<endl<<"2.解决单源最短路径问题"<<endl<<"3.实现两个城市之间的最短路径问题"<<endl<<"4.退出查询"<<endl;
	int b;
	while(1) {
		cin>>b;
		switch(b) {
			case 1:
				Creatgraph(name,m1,n);
				break;
			case 2:
				Dijkstra(n,m1,name);
				break;
			case 3:
				Floyd(n,m1,name);
				break;
			case 4:
				exit(0);
		}
	}

}
