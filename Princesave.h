#include<iostream>
#include <stdlib.h>
#include <time.h>   
using namespace std;

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);  //randomize 
} 
                                               // don vi tien te (vnd)
class Gate
{
protected:
	int numberG;
public:
	Gate()
	{
		numberG = 0;
	}
	Gate(int n)
	{
		numberG = n;
	}
 virtual bool method(int mo)
 {
	 return 1;
 }
 virtual int Lost() { return 1; }
 virtual int type() { return 1; }
 virtual ~Gate() { cout<<" Gate: ";}
};

class EGate :public Gate
{
	int cost;
	int quantity;
public:
	EGate() {
		cost = 0;
		quantity = 0;
		numberG = 0;
	}
	EGate(int cos, int quan, int number) :Gate(number)
	{
		cost = cos;
		quantity = quan;
	}
    bool method(int mo) override
	{
		if (mo >= cost * quantity)
			return 1;
		return 0;
	}
    int Lost() override
    {
	    return cost * quantity;
    }
	int type()
	{
		return 1;
	}
	~EGate()
	{
		cout << "Prince passed EGate! ";
	}
};

class TGate : public Gate
{
	int IQquest;
public:
	TGate()
	{
		IQquest = 0;
	}
	TGate(int iq, int n) : Gate(n)
	{
		IQquest = iq;
	}
   bool method(int mo) override
	{
	   if (mo >= IQquest)
		   return 1;
	   return 0;
	}
   int type()
   {
	   return 2;
   }
   ~TGate()
   {
	   cout << "Prince has passed TGate! ";
   }
};

class SGate : public Gate
{
	int Strong;
public:
	SGate()
	{
		Strong = 0;
	}
	SGate(int psi, int n) : Gate(n)
	{
		Strong = psi;
	}
	bool method(int mo) override
	{
		if (mo >= Strong)
			return 1;
		return 0;
	}
int Lost() override
{
	return Strong;
}
int type()
{
	return 3;
}
~SGate()
{
	cout << "Prince passed this SGate! ";
}

};

class Prince
{
	int money, iq, rsi;
public:
	Prince()
	{
		money = 0;
		iq = 0;
		rsi = 0;
	}
	Prince(int m, int i, int r)
	{
		money = m;
		iq = i;
		rsi = r;
	}
	void Setmoney(int a)
	{
		money = money - a;
	}
	void SetRsi(int a)
	{
		rsi = rsi - a;
	}
	~Prince()
	{
		cout << "Prince failed in an attemp to across gate ";
	}
};
