# include<iostream>
using namespace std;
double power(double x,unsigned y)
{
	if(y==0)
		return 1;
	else
		return x*power(x,y-1);
}
int main()
{
	double x;
	unsigned y;
	cout<<"输入x，y"<<endl;
	cin>>x>>y;
	cout<<"x的y次幂为"<<power(x,y)<<endl;
	return 0;
}