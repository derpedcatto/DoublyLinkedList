#include "DoublyLinkedList.h"

/*CONSTRUCTOR*/
DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& original)
{
	Node* og_current = original.head;

	while (og_current != nullptr)
	{
		AddToTail(og_current->data);
		og_current = og_current->next;
	}
}

/*PRIVATE*/
Node* DoublyLinkedList::GetNode(int index)
{
	if (index < 0 || index > size - 1)
		throw "ERROR";

	Node* tmp;
	if (index <= size / 2)
	{
		tmp = head;
		while (index > 0)
		{
			tmp = tmp->next;
			index--;
		}
	}
	else
	{
		tmp = tail;
		while (index < size - 1)
		{
			tmp = tmp->prev;
			index++;
		}
	}
	return tmp;
}

/*METHODS*/
bool DoublyLinkedList::IsEmpty() const
{
	return size == 0;
}
bool DoublyLinkedList::Equals(DoublyLinkedList other) const
{
	if (size != other.size)
		return false;

	Node* first = head;
	Node* second = other.head;
	while (first != nullptr)
	{
		if (first->data != second->data)
			return false;

		first = first->next;
		second = second->next;
	}
	return true;
}
bool DoublyLinkedList::Contains(int value) const
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data == value)
			return true;
		current = current->next;
	}
	return false;
}
int DoublyLinkedList::GetSize() const
{
	return size;
}
int DoublyLinkedList::IndexOf(int value) const
{
	if (IsEmpty())
	{
		cout << "Empty list!\n";
		return -1;
	}

	Node* temp = head;
	for (int i = 0; i < size; i++)
	{
		if (value == temp->data)
		{
			return i;
		}
		temp = temp->next;
	}

	return -1;
}
int DoublyLinkedList::LastIndexOf(int value) const
{
	if (IsEmpty())
	{
		cout << "Empty list!\n";
		return -1;
	}

	Node* temp = tail;
	for (int i = size - 1; i > 0; i--)
	{
		if (value == temp->data)
		{
			return i;
		}
		temp = temp->prev;
	}

	return -1;
}
void DoublyLinkedList::Print() const
{
	if (IsEmpty())
	{
		cout << "Empty list!\n";
		return;
	}

	Node* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void DoublyLinkedList::AddToHead(int value)
{
	Node* newnode = new Node();
	newnode->data = value;
	newnode->next = head;
	if (IsEmpty())
	{
		tail = newnode;
	}
	else
	{
		head->prev = newnode;
	}
	head = newnode;
	size++;
}
void DoublyLinkedList::AddToTail(int value)
{
	Node* newnode = new Node();
	newnode->data = value;
	newnode->prev = tail;
	if (IsEmpty())
	{
		head = newnode;
	}
	else
	{
		tail->next = newnode;
	}
	tail = newnode;
	size++;
}
void DoublyLinkedList::DeleteFromHead()
{
	if (IsEmpty())
	{
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;

	if (head == nullptr)
	{
		tail = nullptr;
	}
	else
	{
		head->prev = nullptr;
	}
	size--;
}
void DoublyLinkedList::DeleteFromTail()
{
	if (IsEmpty())
	{
		return;
	}

	Node* temp = tail;
	tail = tail->prev;
	delete temp;

	if (tail == nullptr)
	{
		head = nullptr;
	}
	else
	{
		tail->next = nullptr;
	}
	size--;
}
void DoublyLinkedList::DeleteByIndex(int index)
{
	if (index < 0 || index > size - 1)
		throw "ERROR";

	if (index == 0)
	{
		DeleteFromHead();
		return;
	}
	if (index == size - 1)
	{
		DeleteFromTail();
		return;
	}

	Node* del = GetNode(index);
	del->prev->next = del->next;
	del->next->prev = del->prev;
	delete del;
	size--;
}
void DoublyLinkedList::Clear()
{
	while (head != nullptr)
	{
		DeleteFromHead();
	}
}
void DoublyLinkedList::Reverse()
{
	if (size == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* current = head;
	Node* previous = nullptr;
	Node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}
void DoublyLinkedList::SetAt(int index, int value)
{
	Node* tmp = GetNode(index);
	tmp->data = value;
}
void DoublyLinkedList::MergeWith(const DoublyLinkedList& other)
{
	size += other.size;

	Node* current = other.head;
	int tmpsize = other.size;
	while (tmpsize > 0)
	{
		AddToTail(current->data);
		current = current->next;
		tmpsize--;
	}
}
void DoublyLinkedList::Shuffle()
{
	srand(time(NULL));
	if (size == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	int* arr = new int[size];

	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		arr[i] = current->data;
		current = current->next;
	}

	for (int i = 0; i < size; i++)
		swap(arr[i], arr[rand() % size]);

	current = head;
	for (int i = 0; i < size; i++)
	{
		current->data = arr[i];
		current = current->next;
	}

	delete[] arr;
}
void DoublyLinkedList::SortAsc()
{
	if (size == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* index = head;
	Node* current;

	while (index != tail)
	{
		current = tail;
		while (current != index)
		{
			if (index->data > current->data)
				swap(index->data, current->data);

			current = current->prev;
		}

		index = index->next;
	}
}
void DoublyLinkedList::SortDesc()
{
	if (size == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* index = head;
	Node* current;

	while (index != tail)
	{
		current = tail;
		while (current != index)
		{
			if (index->data < current->data)
				swap(index->data, current->data);

			current = current->prev;
		}

		index = index->next;
	}
}
void DoublyLinkedList::InsertInto(int value, int index)
{
	if (index >= size)
	{
		AddToTail(value);
		return;
	}
	else if (index <= 0)
	{
		AddToHead(value);
		return;
	}

	Node* newnode = new Node();
	Node* prevnode = GetNode(index - 1);
	Node* nextnode = GetNode(index);

	prevnode->next = newnode;
	nextnode->prev = newnode;
	newnode->prev = prevnode;
	newnode->next = nextnode;
	newnode->data = value;

	size++;
}

int* DoublyLinkedList::ToArray()
{
	int* arr = new int[size];

	Node* current = head;
	for (int i = 0; i < size; i++)
	{
		arr[i] = current->data;
		current = current->next;
	}

	return arr;
}

DoublyLinkedList DoublyLinkedList::Clone()
{
	DoublyLinkedList* newlist = new DoublyLinkedList();

	Node* current = head;
	while (current != nullptr)
	{
		newlist->AddToTail(current->data);
		current = current->next;
	}

	return *newlist;
}

/*OPERATORS*/
ostream& operator<<(ostream& output, const DoublyLinkedList& src)
{
	src.Print();
	return output;
}
bool DoublyLinkedList::operator<(const DoublyLinkedList& other)
{
	return size < other.size;
}
bool DoublyLinkedList::operator>(const DoublyLinkedList& other)
{
	return size > other.size;
}
bool DoublyLinkedList::operator<=(const DoublyLinkedList& other)
{
	return size <= other.size;
}
bool DoublyLinkedList::operator>=(const DoublyLinkedList& other)
{
	return size >= other.size;
}
bool DoublyLinkedList::operator==(const DoublyLinkedList& other)
{
	return Equals(other);
}
bool DoublyLinkedList::operator!=(const DoublyLinkedList& other)
{
	return !(Equals(other));
}
int DoublyLinkedList::operator[](int index)
{
	if (index >= size || index < 0)
		throw "ERROR";

	Node* current = GetNode(index);
	return current->data;
}
void DoublyLinkedList::operator=(const DoublyLinkedList& other)
{
	Clear();
	MergeWith(other);
}
void DoublyLinkedList::operator+(int value)
{
	AddToTail(value);
}
void DoublyLinkedList::operator+=(const DoublyLinkedList& other)
{
	MergeWith(other);
}
DoublyLinkedList::operator int* ()
{
	return ToArray();
}

/*DEST*/
DoublyLinkedList::~DoublyLinkedList()
{
	Clear();
}