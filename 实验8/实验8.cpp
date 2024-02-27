#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

struct book{
	string book_no;
	string book_name;
	string author;	
	string press;
	int flag;
	struct book *next;
};

struct borrow{
	string book_no;
	string reader_no;
	float borrow_time;
	float return_time;
	int flag;
	struct borrow *next;
};

struct reader{
	string reader_no;
	string name;
	string sex;
	string company;
	int top;
	int number;
	int flag;
	struct reader *next;
};

void insert_book(book *head){
	ifstream fin;

	fin.open("图书信息表.txt",ios::in);
	if(!fin.is_open()) {
		std::cerr<<"未打开文件"<<endl;
		exit(0);
	}
	fin>>head->book_no>>head->book_name>>head->author>>head->press>>head->flag;
	head->next=NULL;
	book *q=head;
	while(!fin.eof()) {
		book *p=new book;
		fin>>p->book_no>>p->book_name>>p->author>>p->press>>p->flag;
		p->next=NULL;
		q->next=p;
		q=q->next;
	}
	fin.close();
}

void insert_borrow(borrow *head){
	ifstream fin;

	fin.open("借阅信息表.txt",ios::in);
	if(!fin.is_open()) {
		std::cerr<<"未打开文件"<<endl;
		exit(0);
	}
	fin>>head->book_no>>head->reader_no>>head->borrow_time>>head->return_time>>head->flag;
	head->next=NULL;
	borrow *q=head;
	while(!fin.eof()) {
		borrow *p=new borrow;
		fin>>p->book_no>>p->reader_no>>p->borrow_time>>p->return_time>>p->flag;
		p->next=NULL;
		q->next=p;
		q=q->next;
	}
	fin.close();
}

void insert_reader(reader *head){
	ifstream fin;

	fin.open("读者信息表.txt",ios::in);
	if(!fin.is_open()) {
		std::cerr<<"未打开文件"<<endl;
		exit(0);
	}
	fin>>head->reader_no>>head->name>>head->sex>>head->company>>head->top>>head->number>>head->flag;
	head->next=NULL;
	reader *q=head;
	while(!fin.eof()) {
		reader *p=new reader;
		fin>>p->reader_no>>p->name>>p->sex>>p->company>>p->top>>p->number>>p->flag;
		p->next=NULL;
		q->next=p;
		q=q->next;
	}
	fin.close();
}

void print_book(book *head){
	cout<<"图书信息表："<<endl;
	while(head!=NULL){
		cout<<head->book_no<<"  "<<head->book_name<<"  "<<head->author<<"  "<<head->press<<"  ";
		if(head->flag==0)
			cout<<"可借"<<"\n";
			else 
				cout<<"已借出"<<"\n";
		head=head->next;
	}
	cout<<endl;
}

void print_borrow(borrow *head){
	cout<<"借阅信息表："<<endl;
	while(head!=NULL){
		cout<<head->book_no<<"  "<<head->reader_no<<"  "<<head->borrow_time<<"  ";
		if(head->return_time!=0){
			cout<<head->return_time<<"（已归还）"<<" ";
		}
		else cout<<"尚未归还"<<" ";
		if(head->flag==0)
			cout<<"完成"<<endl;
			else if(head->flag==1) 
				cout<<"进行中"<<endl;
				else 
				cout<<"超期"<<endl; 
		head=head->next;
	}
		cout<<endl;
}

void print_reader(reader *head){
	cout<<"读者信息表："<<endl;
	while(head!=NULL){
		cout<<head->reader_no<<"  "<<head->name<<"  "<<head->sex<<"  "<<head->company<<"  "<<head->top<<"  "<<head->number<<"  ";
		if(head->flag==0)
			cout<<"正常可借"<<endl;
			else 
				cout<<"异常"<<endl;
		head=head->next;
	}
		cout<<endl;
}

void reader_borrow(borrow *borrow_head,book *book_head,reader *reader_head){
	cout<<"输入借书的书号、读者号、借阅时间"<<endl;
	int flag1=0;
	int flag2=0;
	string a,b;
	float c;
	cin>>a>>b>>c;
	while(borrow_head->next!=NULL){
		borrow_head=borrow_head->next;
	}
	borrow *p=new borrow;
	p->book_no=a;
	p->reader_no=b;
	p->borrow_time=c;
	p->return_time=0;
	p->flag=1;
	p->next=NULL;
	borrow_head->next=p;
	
	fstream f;
	f.open("借阅信息表.txt",ios::out|ios::app);
	f<<endl;
	f<<a<<" "<<b<<" "<<c<<" "<<0<<" "<<1;
	f.close();
	
	book* q=book_head;
	while(book_head->next!=NULL){
		if(a==book_head->book_no){
			break;
			flag1=1;
		}
		book_head=book_head->next;
	}
	if(a==book_head->book_no)
		flag1=1;
	if(flag1=1){
		book_head->flag=1;
	}
	fstream f1;
	f1.open("图书信息表.txt",ios::out);
	while(q->next!=NULL){
		f1<<q->book_no<<" "<<q->book_name<<" "<<q->author<<" "<<q->press<<" "<<q->flag<<endl;
		q=q->next;
	}
	f1<<q->book_no<<" "<<q->book_name<<" "<<q->author<<" "<<q->press<<" "<<q->flag;
	f1.close();
	
	reader* w=reader_head;
	while(reader_head->next!=NULL){
		if(b==reader_head->reader_no){
			break;
			flag2=1;
		}
		reader_head=reader_head->next;
	}
	if(b==reader_head->reader_no)
		flag2=1;
	if(flag2=1){
		reader_head->number++;
	}
	if(reader_head->number>reader_head->top)
		reader_head->flag=1;
	
	fstream f2;
	f2.open("读者信息表.txt",ios::out);
	while(w->next!=NULL){
		f2<<w->reader_no<<" "<<w->name<<" "<<w->sex<<" "<<w->company<<" "<<w->top<<" "<<w->number<<" "<<w->flag<<endl;
		w=w->next;
	}
	f2<<w->reader_no<<" "<<w->name<<" "<<w->sex<<" "<<w->company<<" "<<w->top<<" "<<w->number<<" "<<w->flag;
	f2.close();
}

void book_return(borrow *borrow_head,book *book_head,reader *reader_head){
	cout<<"输入归还的书号、读者号、归还时间"<<endl;
	int flag1=0;
	int flag2=0;
	int flag3=0;
	string a,b;
	float c;
	cin>>a>>b>>c;
	borrow *e=borrow_head;
	while(borrow_head!=NULL){
		if(borrow_head->book_no==a&&borrow_head->reader_no==b&&borrow_head->flag==1){
			flag1=1;
			break;
		}
		borrow_head=borrow_head->next;
	} 
	if(flag1==1){
		borrow_head->return_time=c;
		if(c<borrow_head->borrow_time+2)
			borrow_head->flag=0;
		else
			borrow_head->flag=2;
	}
	fstream f;
	f.open("借阅信息表.txt",ios::out);
	while(e->next!=NULL){
		f<<e->book_no<<" "<<e->reader_no<<" "<<e->borrow_time<<" "<<e->return_time<<" "<<e->flag<<endl;
		e=e->next;
	}
	f<<e->book_no<<" "<<e->reader_no<<" "<<e->borrow_time<<" "<<e->return_time<<" "<<e->flag;
	f.close();
	
	book* q=book_head;
	while(book_head->next!=NULL){
		if(a==book_head->book_no){
			break;
			flag3=1;
		}
		book_head=book_head->next;
	}
	if(a==book_head->book_no)
		flag3=1;
	if(flag3=1){
		book_head->flag=0;
	}
	fstream f1;
	f1.open("图书信息表.txt",ios::out);
	while(q->next!=NULL){
		f1<<q->book_no<<" "<<q->book_name<<" "<<q->author<<" "<<q->press<<" "<<q->flag<<endl;
		q=q->next;
	}
	f1<<q->book_no<<" "<<q->book_name<<" "<<q->author<<" "<<q->press<<" "<<q->flag;
	f1.close();
	
	reader* w=reader_head;
	while(reader_head->next!=NULL){
		if(b==reader_head->reader_no){
			break;
			flag2=1;
		}
		reader_head=reader_head->next;
	}
	if(b==reader_head->reader_no)
		flag2=1;
	if(flag2=1){
		reader_head->number--;
	}
	if(reader_head->number<reader_head->top)
		reader_head->flag=0;
	
	fstream f2;
	f2.open("读者信息表.txt",ios::out);
	while(w->next!=NULL){
		f2<<w->reader_no<<" "<<w->name<<" "<<w->sex<<" "<<w->company<<" "<<w->top<<" "<<w->number<<" "<<w->flag<<endl;
		w=w->next;
	}
	f2<<w->reader_no<<" "<<w->name<<" "<<w->sex<<" "<<w->company<<" "<<w->top<<" "<<w->number<<" "<<w->flag;
	f2.close();
}

void Search_book_no(book *book_head){
	cout<<"输入想要查询的书号："<<endl;
	int flag=0;
	string a;
	cin>>a;
	book *head=book_head;
	while(head!=NULL){
		if(head->book_no==a){
			cout<<head->book_no<<"  "<<head->book_name<<"  "<<head->author<<"  "<<head->press<<"  ";
		if(head->flag==0)
			cout<<"可借"<<"\n";
			else 
				cout<<"已借出"<<"\n";
			cout<<endl;
			flag++;
			break;
		}
			head=head->next;
	}
	if(flag==0)
		cout<<"查询失败"<<endl; 
}

void Search_book_name(book *book_head){
	cout<<"输入想要查询的书名："<<endl;
	string a;
	int flag=0;
	cin>>a;
	book *head=book_head;
	while(head!=NULL){
		if(head->book_name==a){
			flag++;
			cout<<head->book_no<<"  "<<head->book_name<<"  "<<head->author<<"  "<<head->press<<"  ";
		if(head->flag==0)
			cout<<"可借"<<"\n";
			else 
				cout<<"已借出"<<"\n";
			cout<<endl;
		}
			head=head->next;
	}
	if(flag==0)
		cout<<"查询失败"<<endl; 
}

void Search_book_author(book *book_head){
	cout<<"输入想要查询的作者："<<endl;
	string a;
	int flag=0;
	cin>>a;
	book *head=book_head;
	while(head!=NULL){
		if(head->author==a){
			flag++;
			cout<<head->book_no<<"  "<<head->book_name<<"  "<<head->author<<"  "<<head->press<<"  ";
		if(head->flag==0)
			cout<<"可借"<<"\n";
			else 
				cout<<"已借出"<<"\n";
			cout<<endl;
		}
			head=head->next;
	}
	if(flag==0)
		cout<<"查询失败"<<endl; 
}

void Search_book_press(book *book_head){
	cout<<"输入想要查询的出版社："<<endl;
	string a;
	int flag=0;
	cin>>a;
	book *head=book_head;
	while(head!=NULL){
		if(head->press==a){
			flag++;
			cout<<head->book_no<<"  "<<head->book_name<<"  "<<head->author<<"  "<<head->press<<"  ";
		if(head->flag==0)
			cout<<"可借"<<"\n";
			else 
				cout<<"已借出"<<"\n";
			cout<<endl;
		}
			head=head->next;
	}
	if(flag==0)
		cout<<"查询失败"<<endl; 
}
int main(){
	book *book_head=new book;
	borrow *borrow_head=new borrow;
	reader *reader_head=new reader; 
	insert_book(book_head); 
	insert_borrow(borrow_head); 
	insert_reader(reader_head); 
	
	cout<<"1、查看文件内容"<<endl<<"2、插入借阅记录"<<endl<<"3、插入还书记录"<<endl;
	cout<<"4、查询书号"<<endl<<"5、查询书名"<<endl<<"6、查询作者"<<endl<<"7、查询出版社"<<endl<<"8、退出系统"<<endl;
while(1) {
		int z;
		cin>>z;
		switch(z) {
			case 1:
				print_book(book_head);
				print_borrow(borrow_head);
				print_reader(reader_head);
				break;
			case 2:
				reader_borrow(borrow_head,book_head,reader_head);
				break;
			case 3:
				book_return(borrow_head,book_head,reader_head);
				break;
			case 4:
				Search_book_no(book_head);
				break;
			case 5:
				Search_book_name(book_head);
				break;
			case 6:
				Search_book_author(book_head);
				break;
			case 7:
				Search_book_press(book_head);
				break;	
			case 8:
				exit(0); 
		}
	}

	
	return 0;
}
