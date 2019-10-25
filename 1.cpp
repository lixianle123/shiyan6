#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cmath>
#include <windows.h>
using namespace std;

class Triangle
{
private:
	double a, b, c; //a,b,c为三角形三边
public:
	void setABC(double x, double y, double z)
	{
		if ((x + y) > z && (x - y) < z)
		{
			cout << "三边输入的格式正确" << endl;
			a = x;
			b = y;
			c = z;
		}

		else cout << "三边输入的格式不正确" << endl;
	};
	//置三边的值

	void getABC(double *x, double *y, double *z)
	{
		*x = a;
		*y = b;
		*z = c;
	};//取三边的值

	double perimeter(void)
	{
		double C;
		C = a + b + c;
		return C;
	}//计算并返回三角形的周长

	double area(void)
	{
		double S;
		double p;
		p = (a + b + c) / 2;
		S = sqrt(p*(p - a)*(p - b)*(p - c));
		return S;
	}//计算并返回三角形的面积

	double vary(void)
	{
		double t, V;
		if (a > b)
			if (a > c)
				t = a;
			else t = c;
		if (a < b)
		{
			if (b > c)
				t = b;
			else t = c;
		}
		V = cos(b * b + c * c - t * t / 2 * b * c);
		return V;
	}

	void display()
	{
		cout << "调用该函数的对象的this指针是";
		cout << this << endl;                           //输出当前主调对象的地址     
		cout << "当前对象a成员的起始地址: ";         	//输出当前对象的a成员的地址
		cout << &this->a << endl;
		cout << "当前对象b成员的起始地址: ";        	//输出当前对象的b成员的地址
		cout << &this->b << endl;
		cout << "当前对象c成员的起始地址: ";        	//输出当前对象的b成员的地址
		cout << &this->c << endl;
		cout << "a=" << this->a << " ,b=" << this->b << "  ,c=" << this->c << endl;  //输出this所指对象的值
	}

};

int main()
{
	Triangle tri1, tri2;	//定义三角形类的一个实例（对象）
	double x, y, z, V;
	cout << "请输入三角形的三边：" << endl;
	cin >> x >> y >> z;    //将自己所设三角形的三边长输入
	cout << "tri1所占的内存为=" << sizeof(tri1) << endl;
	if ((x + y) > z && (x - y) < z)
	{
		tri1.setABC(x, y, z);	   //为三边置初值
		tri1.getABC(&x, &y, &z);   //将三边的值为x,y,z赋值
		cout << "三条边长分别为：" << x << '\t' << y << '\t' << z << endl;
		cout << "三角形的周长为：" << tri1.perimeter() << endl;
		cout << "三角形的面积为：" << tri1.area() << '\t' << endl;
		V = tri1.vary();
		if (V > 0)
			cout << "此三角形为钝角三角形" << endl;
		else if (V < 0)
			cout << "此三角形为锐角三角形" << endl;
		else
			cout << "此三角形为直角三角形" << endl;
	}

	else cout << "三边输入的格式不正确" << endl;

	tri2.setABC(3, 4, 5);	//为三边置初值
	cout << "DateA地址:" << &tri1 << endl;     
	tri1.display();                  //输出对象DateA的地址
	cout << "DateB地址:" << &tri2 << endl;
	tri2.display();                  //输出对象DateB的地址  
	system("pause");
	return 0;
}
