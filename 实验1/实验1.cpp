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
	printf("������������ϵ�˵������͵绰��\n");
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
	cout<<"����1��������������2���ҵ绰"<<endl;
	Link* q=head;
	int n;
	scanf("%d",&n);
	if(n==1){
		cout<<"����������"<<endl;
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
		cout<<"������绰"<<endl;
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
	cout<<"���д���"<<endl;
	cout<<q->name<<"   "<<q->phone<<endl; 		
	}
	else
	cout<<"���޴���"<<endl;
} 

void Correct_link(Link*head){
	Link* q=head;
	int n,flag1=0,flag2=0;
	string a,b,c,d;
	cout<<"ѡ������Ҫ���ĵ���Ϣ��1Ϊ������2Ϊ�绰"<<endl;
	scanf("%d",&n);
	if(n==1){
		cout<<"�����������Լ�Ҫ���ĵ�����"<<endl;
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
		cout<<"�޸ĳɹ����ݸ���Ϊ��"<<endl;
		cout<<q->name<<"   "<<q->phone<<endl;	
	}	
	else{
		cout<<"����ʧ��"<<endl;
	}
}
	if(n==2){
		cout<<"������绰�Լ�Ҫ���ĵĵ绰"<<endl;
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
		cout<<"�޸ĳɹ����ݸ���Ϊ��"<<endl;
		cout<<q->name<<"   "<<q->phone<<endl;	
	}	
	else{
		cout<<"����ʧ��"<<endl;
	}
	}
}

Link* Delete_link(Link* head){
	cout<<"��������Ҫɾ��������,1Ϊ������2Ϊ�绰"<<endl;
	Link *p=head;
	int n;
	cin>>n; 
	if(n==1){
		cout<<"������Ҫɾ����������"<<endl;
		string a;
		cin>>a;
		if(head->name==a){
			head=head->next;
			cout<<"ɾ���ɹ�"<<endl;
		}
		else{
			while(p->next!=NULL){
				if(p->next->name==a){
				 p=p->next->next;
				 cout<<"ɾ���ɹ�"<<endl;
				 break;
			}
			p=p->next;
		}
	}
	return head;
} 
	else{
		cout<<"������Ҫɾ���ĵ绰��"<<endl;
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
	cout<<"1.ͨѶ¼����Ľ���"<<endl<<"2.ͨѶ����Ϣ�Ĳ���(����0ֹͣ)"<<endl<<"3.ͨѶ����Ϣ�Ĳ�ѯ"<<endl;
	cout<<"4.ͨѶ����Ϣ���޸�"<<endl<<"5.ͨѶ����Ϣ��ɾ��"<<endl<<"6.ͨѶ¼��������"<<endl;
	cout<<"7.�˳�����ϵͳ"<<endl;
	while(1){
		cout<<"��ѡ��1 - 8��"<<endl;
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

 
