# include <iostream>
using namespace std;
struct Student
{
	long num;//学号
	char name[20];//姓名
	int score;//分数
}students[200];
void list();
void addStu();
void deleteStu();
void enterScore();
void input(struct Student &student);
int find(long num);
int findn(char name[20]);
int stuCount = 0;

int main()
{
	char action;
	do{
                cout<<"-----------菜单-----------"<<endl;
                cout<<"1)查看学生名单"<<endl;
                cout<<"2)添加学生"<<endl;
                cout<<"3)删除学生"<<endl;
				cout<<"4)录入成绩"<<endl;
                cout<<"5)退出程序"<<endl;

                cin>>action;
				switch(action){
                case '1':
                        list();
                        break;
                case '2':
                        addStu();
                        break;
                case '3':
                        deleteStu();
                        break;
				case '4':
					    enterScore();
					    break;
                case '5':
                        return 0;
                default:
                        cout<<"您输入了错误的菜单项，请重新选择！"<<endl;
                }
        }while(1);
}
void list()
{
	cout<<"--------学生名单--------"<<endl;
	cout<<"姓名\t"<<"学号\t"<<"分数"<<endl;
	for(int i=1;i<=stuCount;i++){
		cout<<students[i].name<<"\t"<<students[i].num<<"\t"<<students[i].score<<endl;
	}
	cout<<"--------学生名单--------"<<endl;
}
void addStu()
{
	struct Student student;
	input(student);
	int i=find(student.num);
	if(i>stuCount){
		strcpy(students[i].name,student.name);
		students[i].num=student.num;
		stuCount++;
	}
	else
		cout<<"该学号已存在"<<endl;
}
void deleteStu(){
	struct Student student;
	input(student);
	int i=find(student.num);
	if(i<=stuCount&&strcmp(students[i].name,student.name)==0){
		cout<<students[i].name<<"\t"<<students[i].num<<"\t"<<"已删除"<<endl;
		for(i;i<stuCount;i++){
			students[i]=students[i+1];
		}
		stuCount--;
	}
	else
		cout<<"输入信息有误"<<endl;
}
void enterScore(){
	long k;
	char n;
	cout<<"输入开始学生学号"<<endl;
	cin>>k;
	int i=find(k);
	if(i>stuCount){
		cout<<"该学号不存在"<<endl;
		return;
	}
	for(;i<=stuCount;i++){
		cout<<"输入该学生成绩："<<students[i].name<<"\t"<<students[i].num<<endl;
		cin>>students[i].score;
		if(i==stuCount){
			cout<<"已到末尾"<<endl;
			break;
		}
		cout<<"是否继续录入？1:继续；其他键:退出"<<endl;
		cin>>n;
		if(n!='1')
			break;
	}
}
int findn(char name[20]){
	int i;
	for(i=0;i<=stuCount;){
		if(strcmp(students[i].name,name)==0)
			break;
		else
			i++;
	}
	return i;
	}
int find(long num){
	int i;
	for(i=0;i<=stuCount;){
		if(students[i].num==num)
			break;
		else
			i++;
	}
	return i;
}
void input(struct Student &student){
	cout<<"输入姓名"<<endl;
	cin>>student.name;
	cout<<"输入学号"<<endl;
	cin>>student.num;
}