#pragma once
template <class T>
class LinkedList
{
protected:
	class Node
	{
	public:
		Node(T* data, Node* next) 
		{
			this->data = data;
			this->next = next;
		}
		~Node()
		{

		}
		T* data = nullptr;
		Node* next = nullptr;
	};

public:
	LinkedList()
	{
		head = new Node(nullptr, nullptr);
		listsize = 0;
	}

	~LinkedList()
	{
		Node* current = head;
		if (listsize == 0)
		{
			delete head;
		}
		else
		{
			while (current->next)
			{
				Node* temp = current->next;
				delete current;
				current = temp;
				temp = temp->next;
			}
			delete current;
		}
	}

	void add(T* data) //add to end of list
	{
		add(listsize, data);
	}
	void add(int index, T* data) //add to list at index
	{
		Node* current = head;
		for (int i = -1; i < index - 1; i++)
		{
			current = current->next;
		}

		Node* add_node = new Node(data, current->next);
		current->next = add_node;
		listsize++;
	}

	void remove(int index)
	{
		Node* current = head;
		for (int i = -1; i < index - 1; i++) //loops until reaching 1 index before what is to be removed
		{
			current = current->next;
		}
		Node* node_to_remove = current->next; //points to node to remove
		current->next = current->next->next; //points to the next node after the next (main list passes node that is to be removed)
		delete node_to_remove; //deletes node (if it was allocated on the heap)
		listsize--;
	}

	T* get(int index)
	{
		Node* current = head;
		for (int i = -1; i < index; i++)
		{
			current = current->next;
		}
		return current->data;
	}

	int size()
	{
		return listsize;
	}

private:
	int listsize;
	Node* head;
};