#pragma once

//Структура односвязного списка
template <typename T>
class LinkedList {
private:
	struct Node {
		T value;
		Node* next = nullptr;
	};
	Node* head = nullptr;
public:
	//Функция добавления элемента в начало списка
	void push_front(const T& value);
	//Удаления первого элемента из списка
	void pop_front();
	//Функция реверс (переставляет начало на конец списка)
	void reverse();
	//Функция реверс с использованием хвостовой рекурсии
	void recursion(Node* &current, Node* &previouse);
	void recursion_reverse();

	/*Дополнительные функции для получения указателя
	 * на заголовок односвязного списка
	 */
	Node* get_head() { return head; }
	const Node* get_head() const { return head; }
	~LinkedList();
};

//Функция добавления элемента в начало списка
template <typename T>
void LinkedList<T>::push_front(const T& value){
	Node *new_value = new Node;
	new_value -> next = head;
	new_value -> value = value;
	head = new_value;
}

//Удаления первого элемента из списка
template <typename T>
void LinkedList<T>::pop_front(){
	if(head != nullptr){
		Node* next_value = head -> next;
		head->next = nullptr;
		delete head;
		head = next_value;
	}
}

//Функция реверс (переставляет начало на конец списка)
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

//Функция реверс с использованием хвостовой рекурсии
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

//Деструктор (освобождает память и удаляет все элементы списка)
template <typename T>
LinkedList<T>::~LinkedList(){
	while(head != nullptr){
		pop_front();
	}
	delete head;
}
