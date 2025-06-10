#include<iostream>

using namespace std;


// tham so 1: tong tien dien nuoc, tham so 2: tiền nước uống, tham số 3 phụ trợ
// điện nước class2 = 2/3 class2, tiền nước uống chia đều

int main()
{
	double DN = 0,sNu = 0;
	cout<<"Nhap Dien Nuoc: ";
	cin>>DN;
	cout<<"Nhap nuoc uong (so binh): ";
	cin>>sNu;
	//3x + 2 * 2/3 x = DN
	//
	//3x + y + z = DN
	//2/3 x = y
	//z = 1/3 x
	//
	//3x + 2/3x + 1/3x = DN
	//4x = DN
	//x = DN / 4
	//
	double Nu = sNu*3;
	double x = DN/4;
	double y = (2*x)/3;
	double z = x/3;
	cout<<"Tong Tien class1: "<<x + Nu<<"K/Nguoi"<<endl;
	cout<<"Tong Tien class2: "<<y+Nu<<"K/Nguoi"<<endl;
	cout<<"Tong tien class3: "<<z+Nu<<"K/nguoi"<<endl;
	system("pause");
}