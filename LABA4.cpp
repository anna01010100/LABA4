#include <iostream>
using namespace std;


struct Stack
{
	int info;
	Stack* next;
}*top=nullptr, *New;

Stack* push(int data)
{
	Stack* t = new Stack;
	t->info = data;
	t->next = top;
	top = t;
	return t;
}

void AddElements(int a)
{
	cout << "Enter the number of elements" << endl;
	int n, number;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		number = rand() % 20;
		push(number);
	}
	if (a == 1) cout << "Create " << n << endl;
	else cout << "Add " << n << endl;
}

void pop() // удаление ВЕРХНЕГО элемента 
{
	if (top == nullptr) return;
	Stack* ptr = top->next;
	delete top;
	top = ptr;
}

void DelStack()
{
	while (top != NULL)
		pop();
	cout << "Stack is deleted"<< endl;
}

void show()
{
	Stack* t = top;
	while (t != nullptr)
	{
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}

int menu(int a)
{
	cout << endl;
	cout << "Main menu" << endl;
	cout << "0- Exit" << '\n' << "1-Create stack" << '\n' << "2-Add element" << '\n';
	cout << "3-Peek" << '\n' << "4-Task" << '\n' << "5-Sort1" << '\n' << "6-Sort2" << endl;
	cin >> a;
	return a;
}

void Sort1()
{
	Stack* t1, * r;
	Stack* t = nullptr;
	if (top->next->next == nullptr) return;
	do {
		for (t1 = top; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while (top->next->next != t);
}

void Sort2()
{
	Stack* t = nullptr;
	Stack* t1; 
	int r;
	do {
		for (t1 = top; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info)
			{
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (top->next != t);
}

void infpop(int* out)
{
	Stack* t = New->next;
	*out = New->info;
	delete New;
	New = t;
}

void Task()
{
	int middle = 0;
	int n=0; 
	Stack* t = top; 
	while (t != nullptr) 
	{
		middle += t->info; 
		n++; 
		t=t->next;
	}
	middle = middle / n;
	cout << "Middle =" << middle << endl;
	Stack* ptr = top; 

	while (ptr != nullptr)
	{
		if (ptr->info >= middle)
		{
			Stack* newptr = new Stack; 
			newptr->info = ptr->info; 
			newptr->next = New;
			New = newptr;
		}
		ptr = ptr->next;
	}
	DelStack(); 
	int k;
	while (New != NULL)
	{
		infpop(&k);
		push(k);
	}
	show(); 
}

int main()
{
	int a = 1;
	while (a != 0)
	{
		a = menu(a);
		switch (a)
		{
		case 0: DelStack();
			exit(0);
			break;

		case 1:
			if (a == 1 && top != NULL)
			{
				DelStack();
				AddElements(a);
			}
			else {
		case 2: AddElements(a);
			break;
			}

		case 3: show();
			break;

		case 4: Task();
			break;

		case 5: push(0);
			Sort1();
			pop();
			break;

		case 6:  Sort2();
			break;
		}

	}
	return 0;
}

