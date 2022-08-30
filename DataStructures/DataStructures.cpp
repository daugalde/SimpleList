#include <iostream>
using namespace std;

class Node {

private:
	int value = 0;
	Node* NextNode;
	friend class List;

public:  // Constructors

	Node(int v)
	{
		value = v;
		NextNode = NULL;
	}

	Node(int v, Node* newNextNode)
	{
		value = v;
		NextNode = newNextNode;
	}

};

typedef Node* NodeFirst; //Alias

class List {

private:
	NodeFirst head;
	NodeFirst current;

public:
	List() { head = NULL; current = NULL; }
	~List();

	void unshift(int v); // Insert at Beginning
	void push(int v); // Insert at End
	void splice(int v, int pos); // Insert at Index Position
	bool isEmpty() { return head == NULL; }
	void display();
	void next();
	void first();
	void last();
	void pop();
	void shift();
	void removeAtIndex(int pos);
	int Average(int num);
	int length();
	int CountEvenNumbers();
	void PowerNumber(int num);
	void SumPowerNumbers(int num1);
};



List::~List()
{
	NodeFirst aux;

	while (head) {
		aux = head;
		head = head->NextNode;
		delete aux;
	}

	head = NULL;
}

int List::length() {
	int cont = 0;

	NodeFirst aux = head;
	if (isEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
		cout << endl;
	}

}

void List::unshift(int v)
{
	if (isEmpty())
	{
		head = new Node(v);
	}
	else
	{
		head = new Node(v, head);
	}
}

void List::push(int v)
{
	if (isEmpty()) {
		head = new Node(v);
	}
	else
	{
		NodeFirst aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(v);
	}
}

void List::splice(int v, int pos)
{
	if (isEmpty()) {
		head = new Node(v);
	}
	else {
		if (pos <= 1)
		{
			unshift(v);
		}
		else {
			Node* aux = head;
			int i = 2;
			while ((i != pos) && (aux->NextNode != NULL)) {
				i++;
				aux = aux->NextNode;
			}
			NodeFirst newNodeFirst = new Node(v);
			newNodeFirst->NextNode = aux->NextNode;
			aux->NextNode = newNodeFirst;
		}
	}
}

void List::pop()
{
	if (isEmpty()) {
		cout << "Empty List:" << endl;
	}
	else {

		if (head->NextNode == NULL)
		{
			NodeFirst temp = head;
			head = NULL;
			delete temp;
		}
		else {

			NodeFirst aux = head;
			while (aux->NextNode->NextNode != NULL) {
				aux = aux->NextNode;
			}

			NodeFirst temp = aux->NextNode;
			aux->NextNode = NULL;

			delete temp;
		}
	}
}

void List::shift()
{
	if (isEmpty()) {
		cout << "Empty List:" << endl;
	}
	else {
		if (head->NextNode == NULL)
		{
			NodeFirst temp = head;
			head = NULL;
			delete temp;
		}
		else
		{
			NodeFirst aux = head;
			head = head->NextNode;
			delete aux;
		}
	}
}

void List::removeAtIndex(int index) {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		if ((index > length()) || (index < 0)) {
			cout << "An Index should be greater than zero" << endl;
		}
		else {
			if (index == 1)
			{
				NodeFirst temp = head;
				head = head->NextNode;
				delete temp;
			}
			else {
				int cont = 2;
				NodeFirst aux = head;
				while (cont < index) {
					aux = aux->NextNode;
					cont++;
				}
				NodeFirst temp = aux->NextNode;
				aux->NextNode = aux->NextNode->NextNode;
				delete temp;
			}
		}
	}
}

void List::display()
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty Here";
	}
	else
	{
		aux = head;
		while (aux)
		{
			cout << aux->value << "-> ";
			aux = aux->NextNode;
		}
		cout << endl;
	}
}

//Exercise 1
int List::CountEvenNumbers()
{
	int count = 0;
	Node* aux;
	if (head == NULL) {
		cout << "Empty Here";
	}
	else
	{
		aux = head;
		while (aux)
		{
			if (aux->value % 2 == 0)
			{
				count++;
			}

			aux = aux->NextNode;
		}
	}
	return count;
}

//Exercise 2
int List::Average(int num)
{
	if (num == 0) {
		cout << "Sum is Zero";
	}
	else
	{
		int length = 0;
		while (num != 0)
		{
			int temp = num % 10;
			unshift(temp);
			num = num / 10;
			length++;
		}
		
		int sum = 0;
		NodeFirst aux = head;
		while (aux != NULL)
		{
			sum = sum + aux->value;
			aux = aux->NextNode;
		}
		return sum / length;
	}
	return 0;
}

//Exercise 3
void List::PowerNumber(int num) {
	if (num == 0) {
		cout << "num is Zero";
	}
	else
	{
		while (num != 0)
		{
			int temp = num % 10;
			unshift(temp);
			num = num / 10;
		}

		NodeFirst aux = head;
		while (aux != NULL)
		{
			aux->value = (aux->value * aux->value);
			aux = aux->NextNode;
		}
	}
}

//Exercise 4
void List::SumPowerNumbers(int num1) {

	int sum = 0;
	int times = 1;

	if (num1 == 0) {
		cout << "num1 is Zero";
	}


	if (!isEmpty()) {

		NodeFirst aux = head;
		sum = aux->value;
		aux = aux->NextNode;
		times = aux->value ;
	}

	while (num1 != 0 )
	{
		int temp1 = num1 % 10; 

		if (isEmpty()) {
			if (temp1 % 2 == 0)
			{
				sum += temp1 * temp1 * temp1;

			}
			else {
				times *= temp1 * temp1;

			}
		}
		else {
			if (temp1 % 2 != 0)
			{
				sum += temp1 * temp1 * temp1;

			}
			else {
				times *= temp1 * temp1 ;

			}
		}
		 
		num1 = num1 / 10; 
	}
	if (isEmpty()) {

		unshift(sum);
		push(times);
	}
	else {
		NodeFirst aux = head;
		aux->value =  sum;
		aux = aux->NextNode;
		aux->value = times;
	}
	
}

void List::next()
{
	if (current) current = current->NextNode;
}

void List::first()
{
	current = head;
}

void List::last()
{
	current = head;
	if (!isEmpty())
		while (current->NextNode) next();
}

int main()
{
	List Lista;// Init as NULL
	
	cout << "***************************************************************************************" << endl;

	Lista.push(10);
	Lista.push(7);
	Lista.push(9);
	Lista.push(20);

	Lista.display();

	cout << ("La cantidad de numeros pares es "  );
	cout << Lista.CountEvenNumbers();
	cout << endl;

	cout << "***************************************************************************************" << endl;
	Lista.~List();

	cout << ("El promedio del los digitos del numero 123 es :");
	cout << Lista.Average(123);

	cout << "***************************************************************************************" << endl;
	Lista.~List();
	cout << ("El inserta los digitos del numero 123 y eleva al cuadrado :");
	Lista.PowerNumber(123);
	Lista.display();

	cout << "***************************************************************************************" << endl;
	Lista.~List();
	cout << ("El inserta 2 numeros :");
	Lista.SumPowerNumbers( 2345);
	Lista.SumPowerNumbers(4567);
	Lista.display();

	cout << endl;
	cout << endl;

	Lista.~List();
	cin.get();
	return 0;
}
