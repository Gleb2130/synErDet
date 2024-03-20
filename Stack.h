#pragma once


template<class T>
class Stack
{
	Node<T>* first = nullptr;
	size_t   size = 0;

public:
	Stack();
	Stack(initializer_list<T> list);

	~Stack();
	Stack(const Stack<T>& obj);
	Stack<T>& operator=(const Stack<T>& obj);

	void push(const T& value);
	const T& peek() const;
	void pop();
	bool isEmpty() const;
	size_t length() const;
	void clear();

	void print() const;
};

template<class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::Stack(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->push(elem);
	}
}

template<class T>
Stack<T>::~Stack()
{
	this->clear();
}

template<class T>
inline Stack<T>::Stack(const Stack<T>& obj)
{
	Node<T>* objTemp = obj.first;
	while (objTemp)
	{
		this->push(objTemp->value);
		objTemp = objTemp->next;
	}
}

template<class T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& obj)
{
	if (this != &obj)
	{
		this->clear();

		Node<T>* objTemp = obj.first;
		while (objTemp)
		{
			this->push(objTemp->value);
			objTemp = objTemp->next;
		}
	}
	return *this;

}


template<class T>
void Stack<T>::push(const T& value)
{
	if (size == 0)
	{
		first = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first = newNode;
	}
	size++;
}

template<class T>
const T& Stack<T>::peek() const
{
	assert(size > 0);
	return first->value;
}

template<class T>
void Stack<T>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T>
bool Stack<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
size_t Stack<T>::length() const
{
	return size;
}

template<class T>
void Stack<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T>
void Stack<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}