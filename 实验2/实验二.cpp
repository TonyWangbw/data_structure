#include<iostream>
#include<cstdlib>

using namespace std;

struct Node{
	int num;
	struct Node *next;
};

void Joseph(int *name,int end,int m,int n){
	int flag=0;
	cout<<"数组方法投入的编号"<<endl;
	int i=1,j=1;
	while(flag<end){
		if(name[j]!=0){
			if(i==m){
				cout<<name[j];
				cout<<"  ";
				name[j]=0;
				flag++;
			}
			i=i%m+1;
		}
		j=j%n+1;
	}
}



void JosephNode(Node *head,int end,int m,Node *tail){
	int flag=0;
	Node *q=head->next;
	Node *p=tail;
	int i=1;
	cout<<"链表方法投入的编号"<<endl;
	while(flag<end){
		if(i==m){
			p->next=q->next;
			flag++;
			cout<<q->num<<"  ";
		}
		else
		p=p->next;
		q=q->next;
		i=i%m+1;
	}
	cout<<endl;
}

int main(){
	cout<<"依次输入人数与报的数字"<<endl;
	int n,m;
	cin>>n>>m;
	int end=n/2;
	int name[n+1];
	name[0]=0;
	Node *head;
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	Node *p=head;
	for(int i=1;i<n+1;i++){
		Node *q;
		q=(Node*)malloc(sizeof(Node));
		q->next=NULL;
		q->num=i;
		p->next=q;
		p=q;
		name[i]=i;
	}
	Node *tail;
	tail=p;
	tail->next=head->next;
	JosephNode(head,end,m,tail);
	Joseph(name,end,m,n);
}
