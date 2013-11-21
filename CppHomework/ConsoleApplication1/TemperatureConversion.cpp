
# include <iostream>
using namespace std;
int ftoc(int f)
{
	return (5/9.0*(f-32));
}
int ctof(int c)
{
	return (c*1.8+32);
}
int main()
{
	int c,f;
	cout<<"输入华氏度";
	cin>>f;
	cout<<"摄氏度为"<<ftoc(f)<<endl;
	cout<<"输入摄氏度";
	cin>>c;
	cout<<"华氏度为"<<ctof(c)<<endl;
	return 0;
}