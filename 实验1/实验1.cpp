#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct Link_list{
	string name;
	string phone;
	struct Link_list *next;
}Link; 

Link* Creat_link(){
	Link *p=new Link;
	p->next==NULL;
	p->name="0";
	return p;
}

void Insert_link(Link* head){
	printf("请依次输入联系人的姓名和电话：\n");
	string a,b;
	cin>>a;
	cin>>b;
	if(head->name=="0") {
	head->name=a;
	head->phone=b;
	head->next=NULL;
	return ;
	}

	while(head->next!=NULL){
		head=head->next;
	}
	Link*p=new Link;
	
	p->name=a;
	p->phone=b;
	head->next=p;
	p->next=NULL;
	return ;	
}

void Print_link(Link* head){
	while(head->next!=NULL){
		cout<<head->name<<"  "<<head->phone<<endl;
		head=head->next;
	}
	cout<<head->name<<"  "<<head->phone<<endl;
}

void Search_link(Link* head){
	string a,b;
	int flag1=0,flag2=0;
	cout<<"输入1查找姓名，输入2查找电话"<<endl;
	Link* q=head;
	int n;
	scanf("%d",&n);
	if(n==1){
		cout<<"请输入姓名"<<endl;
		cin>>a;
		while(q!=NULL){
		if(q->name==a){
			flag1=1;
			break;
		}
		q=q->next;
	}	
	}
	if(n==2){
		cout<<"请输入电话"<<endl;
		cin>>b;
		while(q!=NULL){
		if(q->phone==b)
		{
		flag2=1;
		break;
	}
	q=q->next;
	}	
	
	}
	if(flag1==1||flag2==1){
	cout<<"查有此人"<<endl;
	cout<<q->name<<"   "<<q->phone<<endl; 		
	}
	else
	cout<<"查无此人"<<endl;
} 

void Correct_link(Link*head){
	Link* q=head;
	int n,flag1=0,flag2=0;
	string a,b,c,d;
	cout<<"选择你想要更改的信息：1为姓名，2为电话"<<endl;
	scanf("%d",&n);
	if(n==1){
		cout<<"请输入姓名以及要更改的姓名"<<endl;
		cin>>a;
		cin>>b;
		while(q!=NULL){
		if(q->name==a){
			flag1=1;
			break;
		}
		q=q->next;
	}
	if(flag1==1){
		q->name=b;
		cout<<"修改成功数据更改为："<<endl;
		cout<<q->name<<"   "<<q->phone<<endl;	
	}	
	else{
		cout<<"更改失败"<<endl;
	}
}
	if(n==2){
		cout<<"请输入电话以及要更改的电话"<<endl;
		cin>>c;
		cin>>d;
		while(q!=NULL){
		if(q->phone==c)
		{
		flag2=1;
		break;
	}
	q=q->next;
	}	
	if(flag2==1){
		q->phone=d;
		cout<<"修改成功数据更改为："<<endl;
		cout<<q->name<<"   "<<q->phone<<endl;	
	}	
	else{
		cout<<"更改失败"<<endl;
	}
	}
}

Link* Delete_link(Link* head){
	cout<<"请输入想要删除的数据,1为姓名，2为电话"<<endl;
	Link *p=head;
	int n;
	cin>>n; 
	if(n==1){
		cout<<"请输入要删除的姓名："<<endl;
		string a;
		cin>>a;
		if(head->name==a){
			head=head->next;
			cout<<"删除成功"<<endl;
		}
		else{
			while(p->next!=NULL){
				if(p->next->name==a){
				 p=p->next->next;
				 cout<<"删除成功"<<endl;
				 break;
			}
			p=p->next;
		}
	}
	return head;
} 
	else{
		cout<<"请输入要删除的电话："<<endl;
		string a;
		cin>>a;
		if(head->phone==a){
			head=head->next;
		}
		else{
			while(p->next!=NULL){
				if(p->next->phone==a){
				 p=p->next;
				 break;
			}
			p=p->next;
		}
	}
	return head;
	}
}

int main(){
	Link* head;
	cout<<"1.通讯录链表的建立"<<endl<<"2.通讯者信息的插入(输入0停止)"<<endl<<"3.通讯者信息的查询"<<endl;
	cout<<"4.通讯者信息的修改"<<endl<<"5.通讯者信息的删除"<<endl<<"6.通讯录链表的输出"<<endl;
	cout<<"7.退出管理系统"<<endl;
	while(1){
		cout<<"请选择：1 - 8："<<endl;
	int n;
	cin>>n;
	switch(n){
		case 1:
			head=Creat_link();
			break;
		case 2:
			Insert_link(head);	
			break;
		case 3:
			Search_link(head);
			break;
		case 4:
			Correct_link(head);
			break;
		case 5:
			head=Delete_link(head);
			break;
		case 6:
			Print_link(head);
			break;
		case 7:
			exit(0);				 
	}
}
	return 0;
}

 
