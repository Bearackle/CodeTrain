#include <iostream>

using namespace std;

int main()
{
	int n,i = 1,j = 4;
	cin>>n;
	int i = n-1;
		int j = 1;
	while(j <=n )
	{
		for(int m = 0; m<i; m++)
		{
			cout<<" ";
		}
		for(int m = 0; m < j ; m++)
		{
			cout<<"*";
		}
		cout<<endl;
		i--;
		j++;
	}	
}