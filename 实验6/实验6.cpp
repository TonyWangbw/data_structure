#include<iostream>
#include<stdlib.h>

using namespace std;

int flag=1;

struct Node {
	int num;
	string name;
	int mathg;
	int englishg;
	int peg;
	int musicg;
	int totalg;
};

void insert(Node *head) {
	cout<<"��������ѧ�š���������ѧ�ɼ���Ӣ��ɼ��������ɼ������ֳɼ���"<<endl;
	cout<<"����0ʱֹͣ"<<endl;
	int a;
	string b;
	int c,d,e,f;
	while(1) {
		cin>>a;
		cin>>b>>c>>d>>e>>f;
		if(a==0)
			break;
		head[flag].num=a;
		head[flag].name=b;
		head[flag].mathg=c;
		head[flag].englishg=d;
		head[flag].peg=e;
		head[flag].musicg=f;
		head[flag].totalg=c+d+e+f;
		flag++;
	}
}

void search(Node *head) {
	cout<<"��������Ҫ���ҵ�ѧ��"<<endl;
	int a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].num==a)
			break;
	}
	if(i!=flag) {
		cout<<head[i].num<<"  "<<head[i].name<<"  "<<head[i].mathg<<"  "<<head[i].englishg<<"  ";
		cout<<head[i].peg<<"  "<<head[i].musicg<<"  "<<head[i].totalg<<endl;
	} else cout<<"����ʧ��"<<endl;
}

void correct(Node *head) {
	cout<<"��������Ҫ�޸ĵ�ѧ��"<<endl;
	int a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].num==a)
			break;
	}
	if(i!=flag) {
		cout<<"������������ĺ������"<<endl;
		string b;
		int c,d,e,f;
		cin>>b>>c>>d>>e>>f;
		head[i].name=b;
		head[i].mathg=c;
		head[i].englishg=d;
		head[i].peg=e;
		head[i].musicg=f;
		head[i].totalg=c+d+e+f;
		cout<<"���ĳɹ�"<<endl;
	} else cout<<"���޴���"<<endl;
}

void bidbubblesort(Node *head) {
	int left, right, shift, i; 
	left=1;
	right=flag ;
	shift=1;
	while(left<right) { 
		for(i=left;i< right;i++) {
			if(head[i].totalg>head[i+1].totalg) { 
				Node t;
				t=head[i];
				head[i]=head[i+1];
				head[i+1]=t;
				shift=i;
			}
		}
		right=shift;
		for(i=right-1;i>=left;i--) { 
			if(head[i].totalg>head[i+1].totalg) { 
				Node t;
				t=head[i];
				head[i]=head[i+1];
				head[i+1]=t;
				shift=i+1;
			}
		}
		left=shift;
	}
	cout<<"˫��ð�����������£�"<<endl;
	for(i=flag; i>1; i--) {
		cout<<head[i].num<<"  "<<head[i].name<<"  "<<head[i].totalg<<"  "<<endl;
	}
}

void shellsort(Node *head) {
	int d,i,j;
	Node t;
	for(d=flag/2; d>=1; d=d/2) {
		for(i=d; i<flag; i++) {
			t=head[i];
			for(j=i-d; j>=0&&t.totalg<head[j].totalg; j=j-d) {
				head[j+d]=head[j];
			}
			head[j+d]=t;
		}
	}
	cout<<"ϣ�����������£�"<<endl;
	for(i=flag; i>1; i--) {
		cout<<head[i].num<<"  "<<head[i].name<<"  "<<head[i].totalg<<"  "<<endl;
	}
}

void quicksort(Node *head,int begin,int end) {
	if(begin > end)
		return;
	Node t=head[begin];
	int i=begin;
	int j=end;
	while(i!=j) {
		while(head[j].totalg>=t.totalg&&j>i)
			j--;
		while(head[i].totalg<=t.totalg&&j>i)
			i++;
		if(j > i) {
			Node t1;
			t1=head[i];
			head[i]=head[j];
			head[j]=t1;
		}
	}
	head[begin]=head[i];
	head[i]=t;
	quicksort(head,begin,i-1);
	quicksort(head,i+1,end);
}

void swap(Node *q,Node *p) {
	Node t;
	t=*q;
	*q=*p;
	*p=t;
}

void heapsort(Node *head) {
	int i=flag;
	int max;
	int m=0;
	int k=flag;
	while(m!=flag) {
		if(i%2==0) {
			max=i;
			if(head[i].totalg<head[i-1].totalg)
				max=i-1;
			else
				max=i;
			if(head[i/2-1].totalg<head[max].totalg)
				swap(&head[i/2-1],&head[max]);
			i=i-2;
		} else {
			max=i;
			if(head[i/2].totalg<head[max].totalg)
				swap(&head[i/2],&head[max]);
			i=i-1;
		}
		for(i; i>0; i=i-2) {
			if(head[i].totalg<head[i-1].totalg)
				max=i-1;
			else
				max=i;
			if(head[i/2-1].totalg<head[max].totalg)
				swap(&head[i/2-1],&head[max]);
		}
		swap(&head[k],&head[0]);
		k--;
		i=k;
		m++;
	}
	cout<<"�����������£�"<<endl;
	for(i=flag; i>1; i--) {
		cout<<head[i].num<<"  "<<head[i].name<<"  "<<head[i].totalg<<"  "<<endl;
	}
}

void print(Node *head){
	cout<<"���������£�"<<endl;
	for(int i=flag; i>1; i--) {
		cout<<head[i].num<<"  "<<head[i].name<<"  "<<head[i].mathg<<"  ";
		cout<<head[i].englishg<<"  "<<head[i].peg<<"  "<<head[i].musicg<<"  ";
		cout<<head[i].totalg<<"  "<<flag-i+1<<endl;
	}
}

int main() {
	cout<<"1��ѧ����Ϣ¼��"<<endl<<"2��ѧ����Ϣ��ѯ"<<endl<<"3��ѧ����Ϣ�޸�"<<endl;
	cout<<"4��ѧ���ɼ�����"<<endl<<"5��ѧ���ɼ����"<<endl<<"6����������"<<endl;
	Node *head;
	head=new Node[15];
	while(1) {
		int z;
		cin>>z;
		switch(z) {
			case 1:
				insert(head);
				break;
			case 2:
				search(head);
				break;
			case 3:
				correct(head);
				break;
			case 4:
				bidbubblesort(head);
				shellsort(head);
				quicksort(head,1,flag);
				cout<<"����ð�����������£�"<<endl;
				int i;
				for(i=flag; i>1; i--) {
					cout<<head[i].num<<"  "<<head[i].name<<"  "<<head[i].totalg<<"  "<<endl;
				}
				heapsort(head);
				break;
			case 5:
				print(head);
				break;
			case 6:
				exit(0);
		}
	}
}
