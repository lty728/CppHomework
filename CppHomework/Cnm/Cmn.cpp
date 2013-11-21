# include <iostream>
using namespace std;
long cmn(int m,int n)
{
	if(n==0||m==n)
		return 1;
	else
		return m*cmn(m-1,n)/(m-n);
}
int main()
{
	int m,n;
	cout<<"ÊäÈëm£¬n"<<endl;
	cin>>m>>n;
	cout<<"C(m,n)="<<cmn(m,n)<<endl;
	return 0;
}