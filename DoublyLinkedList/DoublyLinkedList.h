#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class DoublyLinkedList
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	Node* GetNode(int index);

public:
	/*CONSTRUCTOR*/
	DoublyLinkedList();
	
	/*METHODS*/
	bool IsEmpty() const;
	bool Equals(DoublyLinkedList other) const;
	bool Contains(int value) const;
	int GetSize() const;
	int IndexOf(int value) const;
	int LastIndexOf(int value) const;
	void Print() const;

	void AddToHead(int value);
	void AddToTail(int value);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteByIndex(int index);
	void Clear();
	void Reverse();	//?
	void SetAt(int index, int value);
	void MergeWith(const DoublyLinkedList& other);
	void Shuffle();
	void SortAsc();
	void SortDesc();
	void InsertInto(int value, int index);

	int* ToArray();

	DoublyLinkedList Clone();

	/*OPERATORS*/
	friend ostream& operator<<(ostream& output, const DoublyLinkedList& src);
	bool operator<(const DoublyLinkedList& list);
	bool operator>(const DoublyLinkedList& list);
	bool operator<=(const DoublyLinkedList& list);
	bool operator>=(const DoublyLinkedList& list);
	bool operator==(const DoublyLinkedList& list);
	bool operator!=(const DoublyLinkedList& list);
	int operator[](int index);
	void operator=(const DoublyLinkedList& other);
	void operator+(int value);
	void operator+=(const DoublyLinkedList& other);
	operator int* ();

	/*DEST*/
	~DoublyLinkedList();
};