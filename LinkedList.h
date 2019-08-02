#pragma once

//��������� ������������ ������
template <typename T>
class LinkedList {
private:
	struct Node {
		T value;
		Node* next = nullptr;
	};
	Node* head = nullptr;
public:
	//������� ���������� �������� � ������ ������
	void push_front(const T& value);
	//�������� ������� �������� �� ������
	void pop_front();
	//������� ������ (������������ ������ �� ����� ������)
	void reverse();
	//������� ������ � �������������� ��������� ��������
	void recursion(Node* &current, Node* &previouse);
	void recursion_reverse();

	/*�������������� ������� ��� ��������� ���������
	 * �� ��������� ������������ ������
	 */
	Node* get_head() { return head; }
	const Node* get_head() const { return head; }
	~LinkedList();
};

//������� ���������� �������� � ������ ������
template <typename T>
void LinkedList<T>::push_front(const T& value){
	Node *new_value = new Node;
	new_value -> next = head;
	new_value -> value = value;
	head = new_value;
}

//�������� ������� �������� �� ������
template <typename T>
void LinkedList<T>::pop_front(){
	if(head != nullptr){
		Node* next_value = head -> next;
		head->next = nullptr;
		delete head;
		head = next_value;
	}
}

//������� ������ (������������ ������ �� ����� ������)
template<typename T>
void LinkedList<T>::reverse(){
	Node* next = new Node;
	Node* current = head;
	Node* previouse = nullptr;
	while(current != nullptr){
		next = current->next;
		current->next = previouse;
		previouse = current;
		current = next;
	}
	next = nullptr;
	delete next;
	head = previouse;
}

//������� ������ � �������������� ��������� ��������
template <typename T>
void LinkedList<T>::recursion(Node* &current, Node* &previouse){
	if(current != nullptr){
		Node* next = current->next;
		current->next = previouse;
		previouse = current;
		current = next;
		recursion(current, previouse);
	}
	else{
		return;
	}
}
template <typename T>
void LinkedList<T>::recursion_reverse(){
	Node* current = head;
	Node* previouse = nullptr;
	recursion(current, previouse);
	head = previouse;
}

//���������� (����������� ������ � ������� ��� �������� ������)
template <typename T>
LinkedList<T>::~LinkedList(){
	while(head != nullptr){
		pop_front();
	}
	delete head;
}
