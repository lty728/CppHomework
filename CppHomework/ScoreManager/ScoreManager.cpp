# include <iostream>
using namespace std;
struct Student
{
	long num;//ѧ��
	char name[20];//����
	int score;//����
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
                cout<<"-----------�˵�-----------"<<endl;
                cout<<"1)�鿴ѧ������"<<endl;
                cout<<"2)���ѧ��"<<endl;
                cout<<"3)ɾ��ѧ��"<<endl;
				cout<<"4)¼��ɼ�"<<endl;
                cout<<"5)�˳�����"<<endl;

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
                        cout<<"�������˴���Ĳ˵��������ѡ��"<<endl;
                }
        }while(1);
}
void list()
{
	cout<<"--------ѧ������--------"<<endl;
	cout<<"����\t"<<"ѧ��\t"<<"����"<<endl;
	for(int i=1;i<=stuCount;i++){
		cout<<students[i].name<<"\t"<<students[i].num<<"\t"<<students[i].score<<endl;
	}
	cout<<"--------ѧ������--------"<<endl;
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
		cout<<"��ѧ���Ѵ���"<<endl;
}
void deleteStu(){
	struct Student student;
	input(student);
	int i=find(student.num);
	if(i<=stuCount&&strcmp(students[i].name,student.name)==0){
		cout<<students[i].name<<"\t"<<students[i].num<<"\t"<<"��ɾ��"<<endl;
		for(i;i<stuCount;i++){
			students[i]=students[i+1];
		}
		stuCount--;
	}
	else
		cout<<"������Ϣ����"<<endl;
}
void enterScore(){
	long k;
	char n;
	cout<<"���뿪ʼѧ��ѧ��"<<endl;
	cin>>k;
	int i=find(k);
	if(i>stuCount){
		cout<<"��ѧ�Ų�����"<<endl;
		return;
	}
	for(;i<=stuCount;i++){
		cout<<"�����ѧ���ɼ���"<<students[i].name<<"\t"<<students[i].num<<endl;
		cin>>students[i].score;
		if(i==stuCount){
			cout<<"�ѵ�ĩβ"<<endl;
			break;
		}
		cout<<"�Ƿ����¼�룿1:������������:�˳�"<<endl;
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
	cout<<"��������"<<endl;
	cin>>student.name;
	cout<<"����ѧ��"<<endl;
	cin>>student.num;
}