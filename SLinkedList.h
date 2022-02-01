#pragma once
#include<iostream>

template <typename T>
struct Node
{
	T value;
	Node* next;

	Node(const T& value)
	{
		this->value = value;
		this->next = NULL;
	}

	Node(const T& value, Node* next)
	{
		this->value = value;
		this->next = next;
	}
};

template <typename T>
class SLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	SLinkedList();
	SLinkedList(const SLinkedList& list);
	SLinkedList(SLinkedList&& list) noexcept;

	T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);

	unsigned int size() const;

	void add(const T& value);

	void remove(const T& value);

	void print(std::ostream& out = std::cout) const;

	SLinkedList<T>& operator=(const SLinkedList<T> list);

	~SLinkedList();
};

template<typename T>
inline SLinkedList<T>::SLinkedList() :head{ NULL }, tail{ NULL }
{
}

template<typename T>
inline SLinkedList<T>::SLinkedList(const SLinkedList& list) : head{ NULL }, tail{ NULL }
{
	Node<T>* curr = list.head;

	while (curr != NULL)
	{
		this->add(curr->value);
		curr = curr->next;
	}
}

template<typename T>
inline SLinkedList<T>::SLinkedList(SLinkedList&& list) noexcept : head{ list.head }
{
	list->head = NULL;
}

template<typename T>
inline T& SLinkedList<T>::operator[](unsigned int index) const
{
	if (this->head == NULL)
		throw std::exception("List is empty\n");

	Node<T>* curr = this->head;
	unsigned int count = 0;

	while (curr != NULL && count != index)
	{
		curr = curr->next;
		count++;
	}

	if (curr == NULL)
		throw std::exception("Index out of range\n");

	return curr->value;
}

template<typename T>
inline T& SLinkedList<T>::operator[](unsigned int index)
{
	if (this->head == NULL)
		throw std::exception("List is empty\n");

	Node<T>* curr = this->head;
	unsigned int count = 0;

	while (curr != NULL && count != index)
	{
		curr = curr->next;
		count++;
	}

	if (curr == NULL)
		throw std::exception("Index out of range\n");

	return curr->value;
}

template<typename T>
inline unsigned int SLinkedList<T>::size() const
{
	unsigned int size = 0;
	Node<T>* curr = this->head;

	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}

	return size;
}

template<typename T>
inline void SLinkedList<T>::add(const T& value)
{
	if (this->head == NULL)
	{
		this->head = new(std::nothrow) Node<T>(value);

		if (this->head == nullptr)
			throw std::exception("Cannot allocate the memory\n");

		this->tail = this->head;
	}

	else
	{
		Node<T>* newNode = new(std::nothrow)Node<T>(value);

		if (newNode == nullptr)
			throw std::exception("Cannot allocate the memory\n");

		this->tail->next = newNode;
		this->tail = this->tail->next;
	}
}

template<typename T>
inline void SLinkedList<T>::remove(const T& value)
{
	if (this->head == NULL)
		throw std::exception("List is empty\n");

	if (this->head->value == value)
	{
		Node<T>* curr = this->head;
		this->head = this->head->next;
		delete curr;
	}

	else
	{
		Node<T>* curr = this->head;
		Node<T>* prev = nullptr;

		while (curr->next != NULL && curr->next->value != value)
		{
			prev = curr;
			curr = curr->next;
		}

		if (curr->next == NULL && curr->value != value)
		{
			throw std::exception("No such element at the list\n");
		}

		if (curr->next == NULL)
		{
			if (prev == nullptr)
			{
				this->head = NULL;
				this->tail = NULL;

				delete curr;
			}

			else
			{
				prev->next = NULL;
				this->tail = prev;

				delete curr;
			}
		}

		else
		{
			Node<T>* tmp = curr->next;
			curr->next = curr->next->next;
			delete tmp;
		}
	}
}

template<typename T>
inline void SLinkedList<T>::print(std::ostream& out) const
{
	if (this->head == NULL)
		throw std::exception("List is empty\n");

	Node<T>* curr = this->head;

	while (curr != NULL)
	{
		out << curr->value << "\n";
		curr = curr->next;
	}
}

template<typename T>
inline SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T> list)
{
	Node<T>* curr = list.head;

	while (curr != NULL)
	{
		this->add(curr->value);
		curr = curr->next;
	}

	return *this;
}

template<typename T>
inline SLinkedList<T>::~SLinkedList()
{
	while (this->head != NULL)
	{
		Node<T>* tmp = this->head;
		this->head = this->head->next;
		delete tmp;
	}
}