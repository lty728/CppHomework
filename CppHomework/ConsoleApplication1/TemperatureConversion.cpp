
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
	cout<<"���뻪�϶�";
	cin>>f;
	cout<<"���϶�Ϊ"<<ftoc(f)<<endl;
	cout<<"�������϶�";
	cin>>c;
	cout<<"���϶�Ϊ"<<ctof(c)<<endl;
	return 0;
}