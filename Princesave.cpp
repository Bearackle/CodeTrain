
#include "Princesave.h"
int main()
{
	int n;
	cout << "Nhap so Gate: ";
	cin >> n;
	Gate** X = new Gate * [n];
	srand((int)time(0));
	int type, rand1, rand2;
	for (int i = 0; i < n; i++)
	{
		type = random(1,3);
		if (type == 1)
		{
			rand1 = random(1, 10);
			rand2 = random(1, 20);
			X[i] = new EGate(rand1, rand2, n);
		}
		else if (type == 2)
		{
			rand1 = random(100, 300);
			X[i] = new TGate(rand1, n);
		}
		else
		{
			rand1 = random(160, 1160);     // psi , max suc manh 1160 tuong duong mot con gau siberia (siberia bear)
			X[i] = new SGate(rand1, n);
		}
	}
	int money, iq, rsi;
	cout << "Prince index: ";
	cout << endl << "money = ";
	cin >> money;
	cout << "IQ = ";
	cin >> iq;
	cout << "Strong = ";
	cin >> rsi;
	Prince* T = new Prince(money, iq, rsi);
	int checker = -1;
	for (int i = 0; i < n; i++)
	{
		if (X[i]->type() == 1)
		{
			if (X[i]->method(money))
			{
				T->Setmoney(X[i]->Lost());
				delete X[i];
				cout << i<<endl;
			}
			else
			{
				delete T;
				cout << i << endl;
				break;
			}
		}
		else if (X[i]->type() == 2)
		{
			if (X[i]->method(iq))
			{
				delete X[i];
				cout << i<<endl;
			}
			else
			{
				delete T;
				cout << i<<endl;
				break;
			}
		}
		else
		{
			if (X[i]->method(rsi))
			{
				T->SetRsi(X[i]->Lost());
				delete X[i];
				cout << i<<endl;
			}
			else
			{
				delete T;
				cout << i<<endl;
				break;
			}
		}
		checker = i;
	}
	if (checker == n - 1) cout << "Success Save Princess";
}
