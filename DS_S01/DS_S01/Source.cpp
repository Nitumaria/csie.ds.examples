#include "iostream"
using namespace std;
//doesn't change values - ptrs sent by value
//switch at pointer level only in function
void switchValues(int* fa, int* fb, int)
{
	int* fc = fa;
	fa = fb;
	fb = fc;
}
//does change values - ptrs sent by value
//switch at value level (a and b from main)
void switchValues(int* fa, int* fb)
{
	int fc = *fa;
	*fa = *fb;
	*fb = fc;
}
//does change values - ptrs sent by references
//switch at pointer level
void switchValuesRef(int*& fa, int*& fb)
{
	int* fc = fa;
	fa = fb;
	fb = fc;
}
//does change values - ptrs sent by pointers
//switch at pointer level
void switchValuesPtr(int** fa, int** fb)
{
	int* fc = *fa;
	*fa = *fb;
	*fb = fc;
}
int d = 3;
char* fct()
{
	char tmp[20];
	//char* tmp = new char[20];
	strcpy(tmp, "Test!");
	cout << tmp << endl;
	return tmp;
}
void main()
{
	int a = 5; int* pa = &a;
	int b = 7; int* pb = &b;
	cout << "Initial values:" << endl;
	cout << "a=" << a << "; b=" << b << endl;
	cout << "pa=" << pa << "(" << *pa << "); pb=" << pb << "(" << *pb << ")" << endl << endl;
	cout << "Values and pointers not switched:" << endl;
	switchValues(pa, pb, 0);
	cout << "a=" << a << "; b=" << b << endl;
	cout << "pa=" << pa << "(" << *pa << "); pb=" << pb << "(" << *pb << ")" << endl << endl;
	cout << "Values switched, ptrs not:" << endl;
	switchValues(pa, pb);
	cout << "a=" << a << "; b=" << b << endl;
	cout << "pa=" << pa << "(" << *pa << "); pb=" << pb << "(" << *pb << ")" << endl << endl;
	cout << "Values not switched, ptrs switched:" << endl;
	switchValuesRef(pa, pb);
	cout << "a=" << a << "; b=" << b << endl;
	cout << "pa=" << pa << "(" << *pa << "); pb=" << pb << "(" << *pb << ")" << endl << endl;
	cout << "Values not switched, ptrs switched:" << endl;
	switchValuesPtr(&pa, &pb);
	cout << "a=" << a << "; b=" << b << endl;
	cout << "pa=" << pa << "(" << *pa << "); pb=" << pb << "(" << *pb << ")" << endl << endl;
	cout << fct() << endl;
	static int c = 4;
}