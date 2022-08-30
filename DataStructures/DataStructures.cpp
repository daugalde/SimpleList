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
	void sum(int num);
	int length();
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

void List::sum(int num)
{
	if (num == 0) {
		cout << "Sum is Zero";
	}
	else
	{
		while (num != 0)
		{
			int temp = num % 10;
			unshift(temp);
			num = num / 10;
		}
		int suma = 0;
		NodeFirst aux = head;
		while (aux != NULL)
		{
			suma = suma + aux->value;
			aux = aux->NextNode;
		}
		cout << suma << endl;
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
	Lista.unshift(20);
	Lista.display();
	Lista.unshift(2);
	Lista.display();
	Lista.push(10);
	Lista.display();
	cout << endl;
	cout << endl;
	cout << Lista.length();
	Lista.~List();
	cin.get();
	return 0;
}
