#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<queue>

using namespace std;

struct BiTreeNode {
	char data;
	BiTreeNode* left;
	BiTreeNode* right;
	int flag;
};

BiTreeNode* CreatBiTree(char* s, int &i, int len) { //�ݹ齨��������
	BiTreeNode* root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if(s[i]=='#'||i==len) {
		i++;
		return root=NULL;
	} else {
		root->data=s[i++];
		root->left = CreatBiTree(s, i, len);
		root->right = CreatBiTree(s, i, len);
		return root;
	}
}

void PreOrder_(BiTreeNode* root) { //����ǵݹ�
	stack <BiTreeNode*> q;
	BiTreeNode *head=root;
	q.push(head);
	printf("%c",head->data);
	while(!q.empty()) {
		while(head->left!=NULL) {
			head=head->left;
			q.push(head);
			printf("%c",head->data);
		}
		BiTreeNode* p;
		p=q.top();
		q.pop();
		while(p->right==NULL&&!q.empty()) {
			p=q.top();
			q.pop();
		}
		if(p->right!=NULL) {
			head=p->right;
			q.push(p->right);
			printf("%c",p->right->data);
		}
	}
}

void InOrder_(BiTreeNode* root) { //����ǵݹ�
	stack <BiTreeNode*> q;
	BiTreeNode *head=root;
	q.push(head);
	while(!q.empty()) {
		while(head->left!=NULL) {
			head=head->left;
			q.push(head);
		}
		BiTreeNode* p;
		p=q.top();
		q.pop();
		printf("%c",p->data);
		while(p->right==NULL&&!q.empty()) {
			p=q.top();
			q.pop();
			printf("%c",p->data);
		}
		if(p->right!=NULL) {
			head=p->right;
			q.push(p->right);
		}
	}
}


void PostOrder_(BiTreeNode* root) {
	stack <BiTreeNode*> q;
	BiTreeNode* p=root;
	BiTreeNode* r=NULL;
	while(p||!q.empty()) {
		if (p) {
			q.push(p);
			p=p->left;
		} else {
			p=q.top();
			if (p->right&&p->right!=r) {
				p=p->right;
				q.push(p);
				p=p->left;
			} else {
				q.pop();
				printf("%c",p->data);
				r=p;
				p=NULL;
			}
		}
	}
}

void Print_(stack <BiTreeNode*> q){
	stack <BiTreeNode*> p;
	while(!q.empty()){
		p.push(q.top());
		q.pop();
	}
	cout<<"�˶��������ڴ˽ڵ�"<<endl;
	while(!p.empty()){
		BiTreeNode *a;
		a=p.top();
		p.pop();
		if(!p.empty()){
			cout<<a->data<<"->";
		}
		else
		cout<<a->data;

	}
			cout<<endl;
}

void Findtrace(BiTreeNode* root){
	cout<<"��������Ҫ���ҵĽڵ� "<<endl;
	char s;
	cin>>s;
	stack <BiTreeNode*> q;
	BiTreeNode *head=root;
	q.push(head);
	while(!q.empty()){
		BiTreeNode *p;
		p=q.top();
		if(p->left!=NULL&&p->left->flag!=1){
			q.push(p->left);
			p->left->flag=1;
			if(p->left->data==s){
					Print_(q);
					return ;
				}		
		} 
		else {
			p=q.top();
			if(p->right!=NULL&&p->right->flag!=1){
				q.push(p->right);
				p->right->flag=1;
				if(p->right->data==s){
					Print_(q);
					return ;
				}
			}
			else
			q.pop();
		}
	}
	cout<<"���޴˽ڵ�"<<endl;
} 



int main() {
	cout<<"1.�����������洢�ṹ"<<endl<<"2.���������ǰ�����"<<endl<<"3.����������������"<<endl;
	cout<<"4.��������ĺ�������"<<endl<<"5.��ָ������·��"<<endl<<"6.�˳�ϵͳ"<<endl;
	char str[200];
	int i = 0;
	int len = int(strlen(str));
	BiTreeNode* root;
	while(1) {
		int z;
		cin>>z;
		switch(z) {
			case 1:	
				scanf("%s", str);
				root = CreatBiTree(str, i, len);
				break;
			case 2:
				printf("����ǵݹ������");
				PreOrder_(root);
				printf("\n");
				break;
			case 3:
				printf("����ǵݹ������");
				InOrder_(root);
				printf("\n");
				break;
			case 4:
				printf("����ǵݹ������");
				PostOrder_(root);
				printf("\n");
				break;
				case 5:
					Findtrace(root);
					break;
			case 6:
				exit(0);
		}
	}
	return 0;
}

/*
ABD##EHJ##KL##M#N###CF##G#I##
*/
