//Alan Achtenberg
//CSCE 113-501
//Lab 7

#include "std_lib_facilities_3.h"

class B1{
	public:
		B1(){};

		virtual void pvf()=0;

		virtual  void vf(){
			cout<<"B1::vf()"<<endl;
		}
		void f(){
			cout<<"B1::f()"<<endl;
		}
};

class B2{
	public:
		B2(){};

		virtual void pvf()=0;
};


class D1:public B1{
public:
	D1(){};

	void f(){// implemented when f is called directly by an object of D1, a D1 object referenced to a B1 will call the other f
		cout<<"D1::f()"<<endl;
	}

	virtual void pvf(){
		cout<<"D1::pvf()"<<endl;
	}
	virtual  void vf(){
		cout<<"D1::vf()"<<endl;
	}

};

class D2:public D1{
public:
	virtual void pvf(){
		cout<<"D2::pvf()"<<endl;
	}
};

class D21:public B2{
	string data;
public:
	D21(string s):data(s){};
	virtual void pvf(){
		cout<<data<<endl;
	}
};

class D22:public B2{
	int data_int;
public:
	D22(int s):data_int(s){};
	virtual void pvf(){
		cout<<data_int<<endl;
	}
};


void print(B2& b){
		b.pvf();
}
int main(){
	//B1 test1; cant instantiate anymore because a pure virtual function makes it an abstract class
	D1 test2;
	D2 test3;
	B1& ref1=test2;

	test2.f();
	test2.vf();
	ref1.f();
	ref1.vf();//still calls the vf defined in D1 because that is the object type, this allows you to call functions
			//without knowing the specific sub class
	test3.f();
	test3.vf();
	test3.pvf();

	D21 test4("string");
	D22 test5(5);

	print(test4);
	print(test5);
	keep_window_open();

	return 0;
}