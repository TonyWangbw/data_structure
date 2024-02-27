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
	cout<<"打开文件中:"<<endl;
		ifstream fin;
	fin.open("航班信息.txt",ios::in);
	if(!fin.is_open()) {
		std::cerr<<"未打开文件"<<endl;
		exit(0);
	}
	int i=0;
	while(!fin.eof()) {
		fin>>head[i].flight_no>>head[i].origin_station>>head[i].destination>>head[i].flight_time>>head[i].departue_time>>head[i].arrival_time>>head[i].type>>head[i].cost;
		i++;
		flag++;
	}
	fin.close();
	cout<<"文件内容写入成功"<<endl;
}

void search1(Node *head) {
	cout<<"请输入想要查找的航班号"<<endl;
	string a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].flight_no==a)
			break;
	}
	if(i!=flag) {
		cout<<"航班号："<<head[i].flight_no<<"  "<<"起点站："<<head[i].origin_station<<"  "<<"终点站："<<head[i].destination<<"  ";
		cout<<"航班期："<<head[i].flight_time<<"  "<<"起飞时间："<<head[i].departue_time<<"  "<<"到达时间："<<head[i].arrival_time<<"  ";	
		cout<<"机型："<<head[i].type<<"  "<<"票价："<<head[i].cost<<endl;
	} else cout<<"查找失败"<<endl;
}

void search2(Node *head) {
	cout<<"请输入想要查找的起点站"<<endl;
	string a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].origin_station==a)
			break;
	}
	if(i!=flag) {
		cout<<"航班号："<<head[i].flight_no<<"  "<<"起点站："<<head[i].origin_station<<"  "<<"终点站："<<head[i].destination<<"  ";
		cout<<"航班期："<<head[i].flight_time<<"  "<<"起飞时间："<<head[i].departue_time<<"  "<<"到达时间："<<head[i].arrival_time<<"  ";	
		cout<<"机型："<<head[i].type<<"  "<<"票价："<<head[i].cost<<endl;
	} else cout<<"查找失败"<<endl;
}

void search3(Node *head) {
	cout<<"请输入想要查找的终点站"<<endl;
	string a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].destination==a)
			break;
	}
	if(i!=flag) {
		cout<<"航班号："<<head[i].flight_no<<"  "<<"起点站："<<head[i].origin_station<<"  "<<"终点站："<<head[i].destination<<"  ";
		cout<<"航班期："<<head[i].flight_time<<"  "<<"起飞时间："<<head[i].departue_time<<"  "<<"到达时间："<<head[i].arrival_time<<"  ";	
		cout<<"机型："<<head[i].type<<"  "<<"票价："<<head[i].cost<<endl;
	} else cout<<"查找失败"<<endl;
}

void search4(Node *head) {
	cout<<"请输入想要查找的起飞时间"<<endl;
	int a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].departue_time==a)
			break;
	}
	if(i!=flag) {
		cout<<"航班号："<<head[i].flight_no<<"  "<<"起点站："<<head[i].origin_station<<"  "<<"终点站："<<head[i].destination<<"  ";
		cout<<"航班期："<<head[i].flight_time<<"  "<<"起飞时间："<<head[i].departue_time<<"  "<<"到达时间："<<head[i].arrival_time<<"  ";	
		cout<<"机型："<<head[i].type<<"  "<<"票价："<<head[i].cost<<endl;
	} else cout<<"查找失败"<<endl;
}

void search5(Node *head) {
	cout<<"请输入想要查找的到达时间"<<endl;
	int a;
	cin>>a;
	int i;
	for(i=0; i<flag; i++) {
		if(head[i].arrival_time==a)
			break;
	}
	if(i!=flag) {
		cout<<"航班号："<<head[i].flight_no<<"  "<<"起点站："<<head[i].origin_station<<"  "<<"终点站："<<head[i].destination<<"  ";
		cout<<"航班期："<<head[i].flight_time<<"  "<<"起飞时间："<<head[i].departue_time<<"  "<<"到达时间："<<head[i].arrival_time<<"  ";	
		cout<<"机型："<<head[i].type<<"  "<<"票价："<<head[i].cost<<endl;
	} else cout<<"查找失败"<<endl;
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
	cout<<"排序结果如下："<<endl;
	for(i=1; i<flag; i++) {
		cout<<"航班号："<<head[i].flight_no<<"  "<<"起点站："<<head[i].origin_station<<"  "<<"终点站："<<head[i].destination<<"  ";
		cout<<"航班期："<<head[i].flight_time<<"  "<<"起飞时间："<<head[i].departue_time<<"  "<<"到达时间："<<head[i].arrival_time<<"  ";	
		cout<<"机型："<<head[i].type<<"  "<<"票价："<<head[i].cost<<endl;
	}
}

int main() {
	cout<<"1、对航班的起飞时间进行排序"<<endl<<"2、查询航班号"<<endl<<"3、查询起点站"<<endl;
	cout<<"4、查询终点站"<<endl<<"5、查询起飞时间"<<endl<<"6、查询到达时间"<<endl<<"7、结束程序"<<endl;
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
