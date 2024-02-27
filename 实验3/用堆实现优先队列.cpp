#include<iostream>

using namespace std;

typedef struct Queue {
	int num;
	int weight;
} Queue;

int n=0;

void Insertqueue(Queue a[20]) {
	cout<<"请输入想要插入的数据及优先级，输入0即停止："<<endl;
	int x,y;
	while(1) {
		cin>>x>>y;
		if(x==0||y==0) {
			break;
		} else {
			a[n].num=x;
			a[n].weight=y;
			n++;
		}
	}
	n--;
}

void swap(Queue *q,Queue *p) {
	Queue t;
	t=*q;
	*q=*p;
	*p=t;
}

void Printqueue(Queue a[20]) {
	for(int i=0; i<=n; i++) {
		cout<<a[i].num<<"  ";
	}
	cout<<endl;
}

void Heapsort(Queue a[20]) {
	int i=n;
	int max;
	int m=0;
	int k=n;
	while(m!=n) {
		if(i%2==0) {
			max=i;
			if(a[i].weight<a[i-1].weight)
				max=i-1;
			else
				max=i;
			if(a[i/2-1].weight<a[max].weight)
				swap(&a[i/2-1],&a[max]);
			i=i-2;
		} else {
			max=i;
			if(a[i/2].weight<a[max].weight)
				swap(&a[i/2],&a[max]);
			i=i-1;
		}
		for(i; i>0; i=i-2) {
			if(a[i].weight<a[i-1].weight)
				max=i-1;
			else
				max=i;
			if(a[i/2-1].weight<a[max].weight)
				swap(&a[i/2-1],&a[max]);
		}
		swap(&a[k],&a[0]);
		k--;
		i=k;
		m++;
	}
}

void popqueue(Queue a[20]) {
	cout<<"值："<<a[n].num<<"  "<<"权值："<<a[n].weight<<endl;
	n--;
}

void correctqueue(Queue a[20]) {
	cout<<"请输入想要调整元素的优先级："<<endl;
	int x,y;
	cin>>x>>y;
	for(int i=0; i<=n; i++) {
		if(a[i].num==x) {
			a[i].weight=y;
		}
	}
	Heapsort(a);
}

void sumqueue(Queue[20]){
	cout<<"优先队列长度为："<<n+1<<endl;
}

void searchqueue(Queue a[20]){
	cout<<"请输入想要查询的值"<<endl;
	int q;
	cin>>q;
	for(int i=0; i<=n; i++) {
		if(a[i].num==q) {
			cout<<"值："<<a[i].num<<"权值："<<a[i].weight<<endl;
		}
	}
}

int main() {
	cout<<"1.优先队列的插入操作"<<endl<<"2.最大优先级元素出队列操作"<<endl<<"3.调整优先队列某个元素的优先级"<<endl;
	cout<<"4.求优先队列的长度"<<endl<<"5.优先队列的查询操作"<<endl<<"6.退出系统"<<endl;
	Queue a[20];
	while(1) {
		int z;
		cin>>z;
		switch(z) {
			case 1:
				Insertqueue(a);
				Heapsort(a);
				Printqueue(a);
				break;
			case 2:
				popqueue(a);
				Printqueue(a);
				break;
			case 3:
				correctqueue(a);
				Heapsort(a);
				Printqueue(a);
				break;
			case 4:
				sumqueue(a);
				break;
			case 5:
				searchqueue(a);
				break;
			case 6:
				exit(0);
		}
	}	
	return 0;
}
