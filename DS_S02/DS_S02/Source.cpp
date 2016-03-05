#include "iostream"
using namespace std;
int sumArrayInt(int* pArray, int noEl)
{
	int sum = 0;
	for (int i = 0; i < noEl; i++)
		sum += pArray[i]; //index
	//	sum += *(pArray + i)
	return sum;
}
void* sumArray(void* pArray, int noEl, int typeSize)
{
	if (typeSize == sizeof(int))
	{
		int* sumInt = new int(0);
		for (int i = 0; i < noEl; i++){
			*sumInt += ((int*)pArray)[i];
			//*sumInt += *(((int*)pArray) + i);
		}
		return sumInt;
	}
	if (typeSize == sizeof(double))
	{
		double* sumDouble = new double(0.0);
		for (int i = 0; i < noEl; i++){
			*sumDouble += ((double*)pArray)[i];
			//*sumDouble += *(((double*)pArray) + i);
		}
		return sumDouble;
	}
}
double sumArray(int noArgs, ...)
{
	va_list ptrStack;
	_crt_va_start(ptrStack, noArgs);
	double sum = 0;
	for (int i = 0; i < noArgs; i++)
		if (i == 1)
			sum += _crt_va_arg(ptrStack, double);
		else
			sum += _crt_va_arg(ptrStack, int);
	return sum;
}
struct character{
	int : 5;
	int bit : 1;
	int : 2;
};
void main()
{
	int arrayInt[] = { 1, 2, 3, 4, 5 };
	double arrayDouble[] = { 1.1, 2.2, 3.3, 4.4 };
	cout << "Result: " << sumArrayInt(arrayInt, sizeof(arrayInt) / sizeof(int)) << endl;
	cout << "Result: " << *(int*)sumArray(arrayInt, sizeof(arrayInt) / sizeof(int), sizeof(int)) << endl;
	cout << "Result: " << *(double*)sumArray(arrayDouble, sizeof(arrayDouble) / sizeof(double), sizeof(double)) << endl;
	cout << "Result: " << sumArray(5, 1, 2.2, 3, 4, 5) << endl;
	cout << "Result: " << sumArray(3, 1, 2.2, 3) << endl;
	char c = 'a';
	cout << "Initial value: " << c << endl;
	c -= 32;
	cout << "Value: " << c << endl;
	c += 32;
	cout << "Value: " << c << endl;
	c = c & 223;
	cout << "Value: " << c << endl;
	c = c | 32;
	cout << "Value: " << c << endl;
	character* ptrc = NULL;
	ptrc = (character*)&c;
	ptrc->bit = ~ptrc->bit;
	cout << "Value: " << c << endl;


}