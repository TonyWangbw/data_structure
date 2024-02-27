#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int flag=0;

struct Node {
	string flight_no;
	string origin_station;
	string destination;
	string flight_time;
	int departue_time;
	int arrival_time;
	string type;
	int cost;
};

void insert(Node *head) {
	cout<<"���ļ���:"<<endl;
		ifstream fin;
	fin.open("������Ϣ.txt",ios::in);
	if(!fin.is_open()) {
		std::cerr<<"δ���ļ�"<<endl;
		exit(0);
	}
	int i=0;
	while(!fin.eof()) {
		fin>>head[i].flight_no>>head[i].origin_station>>head[i].destination>>head[i].flight_time>>head[i].departue_time>>head[i].arrival_time>>head[i].type>>head[i].cost;
		i++;
		flag++;
	}
	fin.close();
	cout<<"�ļ�����д��ɹ�"<<endl;
}

void search1(Node *head) {
	cout<<"��������Ҫ���ҵĺ����"<<endl;
	string a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].flight_no==a)
			break;
	}
	if(i!=flag) {
		cout<<"����ţ�"<<head[i].flight_no<<"  "<<"���վ��"<<head[i].origin_station<<"  "<<"�յ�վ��"<<head[i].destination<<"  ";
		cout<<"�����ڣ�"<<head[i].flight_time<<"  "<<"���ʱ�䣺"<<head[i].departue_time<<"  "<<"����ʱ�䣺"<<head[i].arrival_time<<"  ";	
		cout<<"���ͣ�"<<head[i].type<<"  "<<"Ʊ�ۣ�"<<head[i].cost<<endl;
	} else cout<<"����ʧ��"<<endl;
}

void search2(Node *head) {
	cout<<"��������Ҫ���ҵ����վ"<<endl;
	string a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].origin_station==a)
			break;
	}
	if(i!=flag) {
		cout<<"����ţ�"<<head[i].flight_no<<"  "<<"���վ��"<<head[i].origin_station<<"  "<<"�յ�վ��"<<head[i].destination<<"  ";
		cout<<"�����ڣ�"<<head[i].flight_time<<"  "<<"���ʱ�䣺"<<head[i].departue_time<<"  "<<"����ʱ�䣺"<<head[i].arrival_time<<"  ";	
		cout<<"���ͣ�"<<head[i].type<<"  "<<"Ʊ�ۣ�"<<head[i].cost<<endl;
	} else cout<<"����ʧ��"<<endl;
}

void search3(Node *head) {
	cout<<"��������Ҫ���ҵ��յ�վ"<<endl;
	string a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].destination==a)
			break;
	}
	if(i!=flag) {
		cout<<"����ţ�"<<head[i].flight_no<<"  "<<"���վ��"<<head[i].origin_station<<"  "<<"�յ�վ��"<<head[i].destination<<"  ";
		cout<<"�����ڣ�"<<head[i].flight_time<<"  "<<"���ʱ�䣺"<<head[i].departue_time<<"  "<<"����ʱ�䣺"<<head[i].arrival_time<<"  ";	
		cout<<"���ͣ�"<<head[i].type<<"  "<<"Ʊ�ۣ�"<<head[i].cost<<endl;
	} else cout<<"����ʧ��"<<endl;
}

void search4(Node *head) {
	cout<<"��������Ҫ���ҵ����ʱ��"<<endl;
	int a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].departue_time==a)
			break;
	}
	if(i!=flag) {
		cout<<"����ţ�"<<head[i].flight_no<<"  "<<"���վ��"<<head[i].origin_station<<"  "<<"�յ�վ��"<<head[i].destination<<"  ";
		cout<<"�����ڣ�"<<head[i].flight_time<<"  "<<"���ʱ�䣺"<<head[i].departue_time<<"  "<<"����ʱ�䣺"<<head[i].arrival_time<<"  ";	
		cout<<"���ͣ�"<<head[i].type<<"  "<<"Ʊ�ۣ�"<<head[i].cost<<endl;
	} else cout<<"����ʧ��"<<endl;
}

void search5(Node *head) {
	cout<<"��������Ҫ���ҵĵ���ʱ��"<<endl;
	int a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].arrival_time==a)
			break;
	}
	if(i!=flag) {
		cout<<"����ţ�"<<head[i].flight_no<<"  "<<"���վ��"<<head[i].origin_station<<"  "<<"�յ�վ��"<<head[i].destination<<"  ";
		cout<<"�����ڣ�"<<head[i].flight_time<<"  "<<"���ʱ�䣺"<<head[i].departue_time<<"  "<<"����ʱ�䣺"<<head[i].arrival_time<<"  ";	
		cout<<"���ͣ�"<<head[i].type<<"  "<<"Ʊ�ۣ�"<<head[i].cost<<endl;
	} else cout<<"����ʧ��"<<endl;
}



void shellsort(Node *head) {
	int d,i,j;
	Node t;
	for(d=flag/2; d>=1; d=d/2) {
		for(i=d; i<flag; i++) {
			t=head[i];
			for(j=i-d; j>=0&&t.departue_time<head[j].departue_time; j=j-d) {
				head[j+d]=head[j];
			}
			head[j+d]=t;
		}
	}
	cout<<"���������£�"<<endl;
	for(i=1; i<flag; i++) {
		cout<<"����ţ�"<<head[i].flight_no<<"  "<<"���վ��"<<head[i].origin_station<<"  "<<"�յ�վ��"<<head[i].destination<<"  ";
		cout<<"�����ڣ�"<<head[i].flight_time<<"  "<<"���ʱ�䣺"<<head[i].departue_time<<"  "<<"����ʱ�䣺"<<head[i].arrival_time<<"  ";	
		cout<<"���ͣ�"<<head[i].type<<"  "<<"Ʊ�ۣ�"<<head[i].cost<<endl;
	}
}

int main() {
	cout<<"1���Ժ�������ʱ���������"<<endl<<"2����ѯ�����"<<endl<<"3����ѯ���վ"<<endl;
	cout<<"4����ѯ�յ�վ"<<endl<<"5����ѯ���ʱ��"<<endl<<"6����ѯ����ʱ��"<<endl<<"7����������"<<endl;
	Node *head;
	head=new Node[15];
	insert(head);
	while(1) {
		int z;
		cin>>z;
		switch(z) {
			case 1:
				shellsort(head);
				break;
			case 2:
				search1(head);
				break;
			case 3:
				search2(head);
				break;
			case 4:
				search3(head);
				break;
			case 5:
				search4(head);
				break;
			case 6:
				search5(head);
				break;
			case 7:
				exit(0); 
		}
	}
}
