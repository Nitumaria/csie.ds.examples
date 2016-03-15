#include "iostream"
using namespace std;
enum EmployeeType { DOCTOR = 10, PROFESSOR = 20, LAWER = 30 };
union EmployeeHours
{
	double overtimeHrs;
	int loadingHrs;
	float barHrs;
};
struct Employee{
	char* name;
	EmployeeType typeEmp;
	EmployeeHours hoursEmp;
};
Employee* buildEmployee(char* name, int type, double hours)
{
	//1.declaring a new element
	Employee* tmp = NULL;
	//2.allocating memory space
	tmp = (Employee*)malloc(sizeof(Employee));
	//3.wrong: tmp->name = name;
	tmp->name = (char*)malloc(strlen(name) + 1);
	strcpy(tmp->name, name);
	switch (type)
	{
	case 10:
		tmp->typeEmp = DOCTOR;
		tmp->hoursEmp.overtimeHrs = hours;
		break;
	case 20:
		tmp->typeEmp = EmployeeType::PROFESSOR;
		tmp->hoursEmp.loadingHrs = hours;
		break;
	case 30:
		tmp->hoursEmp.barHrs = hours;
		tmp->typeEmp = LAWER;
		break;
	default:
		break;
	}
	return tmp;
}
void printArrayElements(Employee**, int);
Employee** addArrayElement(Employee**, Employee*, int&);
void main()
{
	FILE* pFile = NULL;
	pFile = fopen("Text.txt", "r");
	Employee** arrayEl = NULL;
	int noEl = 0;
	if (pFile != NULL)
	{
		//reading operations
		int index = 0;
		fscanf(pFile, "%d", &noEl);
		//arrayEl = new Employee*[noEl];
		arrayEl = (Employee**)malloc(noEl*sizeof(Employee*));
		char buffer[50]; int type = 0;  double hours = 0.0;
		while (!feof(pFile))
		{
			fscanf(pFile, "%s", buffer);
			fscanf(pFile, "%d", &type);
			fscanf(pFile, "%Lf", &hours);
			Employee* newEl = buildEmployee(buffer, type, hours);
			arrayEl[index++] = newEl;
		}
		fclose(pFile);
	}
	printArrayElements(arrayEl, noEl);
	printf("------------------After inserting a new element-------------------\n");
	Employee* newEl = buildEmployee("Filipescu", 30, 12.3);
	arrayEl = addArrayElement(arrayEl, newEl, noEl);
	printArrayElements(arrayEl, noEl);
}
Employee** addArrayElement(Employee** arrayEl, Employee* newEl, int& size)
{
	Employee** result = (Employee**)malloc((size + 1)*sizeof(Employee*));
	for (int i = 0; i < size; i++)
		result[i] = arrayEl[i];
	result[size++] = newEl;
	return result;
}
void printArrayElements(Employee** arrayEl, int noEl)
{
	for (int i = 0; i < noEl; i++)
	{
		printf("Employee name: %s\n", arrayEl[i]->name);
	}
}