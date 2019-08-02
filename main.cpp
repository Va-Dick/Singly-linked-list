#include "LinkedList.h"
#include "test_runner.h"
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

//Функция для приведения списка к вектору (необходим для наглядности)
template <typename T>
vector<T> to_vector(const LinkedList<T>& list) {
	vector<T> result;
	for (auto node = list.get_head(); node; node = node->next) {
		result.push_back(node->value);
	}
	return result;
}

//Проверка функции reverse
void test_reverse(){
	vector<int> vect = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	LinkedList<int> list;
	for(int i = 0; i < 10; ++i){
		list.push_front(i);
	}
	list.reverse();
	ASSERT_EQUAL(vect, to_vector(list));
}

//Проверка функции recursion_reverse
void test_recursion_reverse(){
	vector<int> vect = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	LinkedList<int> list;
	for(int i = 0; i < 10; ++i){
		list.push_front(i);
	}
	list.recursion_reverse();
	ASSERT_EQUAL(vect, to_vector(list));
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, test_reverse);
	RUN_TEST(tr, test_recursion_reverse);
	return 0;
}
