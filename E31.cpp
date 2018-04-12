#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
	
class Rational
{
private:
	int a, b;
public:
	Rational(int q, int w)
		:a(q), b(w)
	{
		if (w == 0)
		{
			cout << "ERROR:除零错误!\n";
		}
	}
	void set_z(int x)
	{
		a = x;
	}
	void set_m(int x)
	{
		b = x;
	}
	int get_z()
	{
		return a;
	}
	int get_m()
	{
		return b;
	}
	void tf()
	{
		int q = gcd(a,b);
		a /= q;
		b /= q;
	}
	Rational cheng(Rational y)  
	{
		Rational ans(a*y.get_z(), b * y.get_m());
		ans.tf();
		return ans;
	}
	Rational chu(Rational y)
	{
		Rational ans(a*y.get_m(), b * y.get_z());
		ans.tf();
		return ans;
	}
	Rational plus(Rational y)
	{
		Rational ans(0, 1);
		int tfm = b * y.get_m();
		int fz = a * y.get_m() + y.get_z()*b;
		ans.set_m(tfm);
		ans.set_z(fz);
		ans.tf();
		return ans;
	}
	Rational jian(Rational y)
	{
		Rational ans(0, 1);
		int tfm = b * y.get_m();
		int fz = a * y.get_m() - y.get_z()*b;
		ans.set_m(tfm);
		ans.set_z(fz);
		ans.tf();
		return ans;
	}
	void print()
	{
		if (a < 0 && b < 0)
		{
			cout << -a << '/' << -b << " ";
			return;
		}

		if (a <0 &&b > 0)
		{
			cout << '-';
			cout << -a << '/' << b << " "; return;
		}
		if (a >0 && b < 0)
		{
			cout << '-';
			cout << a << '/' << -b << " "; return;
		}
		if (a%b == 0)
		{
			cout << a / b << " ";
			return;
		}
		if(b!=0) 
		cout << a << '/' << b << " ";
		else
		{
			cout << "ERROR:除零错误!\n";
		}
	}
};


int main()
{
	/*int q, w, e, r;
	cout << "请输入a的分子：";
	cin >> q;
	cout << "分母:";
	cin >> w;
	cout << "请输入b的分子：";
	cin >> e;
	cout << "分母:";
	cin >> r;
	Rational a(q, w), b(e, r),c(0,1);
	//c=a.cheng(b);
	cout << "a="; a.print();
	cout << " b="; b.print(); 
	cout << ":\na+b= ";
	c = a.plus(b);
	c.print();
	cout << "\na-b= ";
	c = a.jian(b);
	c.print();
	cout << "\na*b= ";
	c = a.cheng(b);
	c.print();
	cout << "\na/b= ";
	c = a.chu(b);
	c.print();*/
	
	
	string s;
	cin>>s;
	int k=s.size(),l=0;
    Rational ans(0,1),la(0,1);
    int q=0,w=0,e=0,r=0;
	for(int i=0;i<k;i++)
	{
		if(s[i]=='-'||s[i]=='+')
		{
			l++;bool v=0;
			for(int j=0;j<i;j++)
			{
				if(!v)
				{
					if(s[j]=='/')
					{
						v=1;continue;
					}
					q=q*10+s[j]-'0';
				}
				if(v)
				{
					w=w*10+s[j]-'0';
				}
				
			}
			break;
		}
	} 
	cout<<q<<" "<<w;
	return 0;
}


