
#include <algorithm>
#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;

void first() {
	cout << "Механизм получает на вход время в минутах которое выделяется на производство деталей каждого сорта, производство одной детали занимает ровно 2 минуты поэтому время должно быть кратным 2 минутам" << endl;

	vector<int> vec = { 74, 22, 14, 86, 74 };
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
	if (all_of(vec.begin(), vec.end(), [](int elem) { return !(elem % 2); }))
		cout << "Все элементы четные числа." << endl;
	else
		cout << "Не все элементы четные числа." << endl;

	vec.pop_back();
	vec.push_back(21);
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
	if (all_of(vec.begin(), vec.end(), [](int elem) { return !(elem % 2); }))
		cout << "Все элементы четные числа." << endl;
	else
		cout << "Не все элементы четные числа." << endl;
}

void second() {
	vector<int> vec = { 74, 22, 14, 86, 21 };
	cout << "Поиск и устранение неверных входных данных(обнуление) " << endl;
	replace_if(vec.begin(), vec.end(), [](int elem) { return (elem % 2); }, 0);

	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}

void third() {
	cout << "Распределение по баллам на группы: сдал, не сдал(у кого больше или равно 50 - сдал)" << endl;

	vector<int> marks = { 53, 33, 95, 99, 24, 70, 65, 45, 75, 100, 0, -5 };
	vector<int> good_markst(12);
	vector<int> bad_markst(12);
	int numberZero = 0;
	for (auto i : marks) {
		if (i == 0) {
			numberZero++;
		}
		cout << i << " ";
	}
	cout << endl;
	partition_copy(marks.begin(), marks.end(), good_markst.begin(), bad_markst.begin(), [](int elem) { return (elem >= 50); });
	vector<int> good_marks;
	vector<int> bad_marks;
	for (auto i : good_markst) {
		if (i != 0) {
			good_marks.push_back(i);
		}
	}
	for (auto i : bad_markst) {
		if (i != 0) {
			bad_marks.push_back(i);
		}
		else if (numberZero > 0) {
			bad_marks.push_back(i);
			numberZero--;
		}
	}
	for (auto i : good_marks)
		cout << i << " ";
	cout << endl;
	for (auto i : bad_marks)
		cout << i << " ";
	cout << endl;
}

void four() {
	cout << "Некоторый механизм при нагреве деетали свыше 91 градуса выходит из строя температура меняется один раз в единицу времени задача найти сколько единиц времени отработал механизм " << endl;

	vector<int> temp = { 53, 33, 90, 87, 24, 70, 65, 45, 75, 23, 33, 56, 45, 81, 100, 10, 24, 124 };
	int time = 0;
	for (auto i : temp) {
		cout << i << " ";
	}
	cout << endl;
	auto it = find_if(temp.begin(), temp.end(), [](int elem) { return !(elem <= 91); });

	for (auto i : temp) {
		if (i == *it) {
			break;
		}
		cout << i << " ";
		time++;
	}
	cout << endl << time << endl;
}

void five() {
	cout << "Найти минимальный элемент " << endl;
	vector<int> vec = { 53, 33, 90, 87, 24, 70, 65, 45, 75, 23, 33, 56, 45, 81, 100, 10, 24, 124 };
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
	auto mn = min_element(vec.begin(), vec.end(), [](int elem1, int elem2) { if (elem1 < 0) { elem1* (-1); }
	if (elem2 < 0) { elem2* (-1); }
	return (elem1 < elem2); });

	cout << endl << *mn << endl;
}

void six() {
	cout << "Отсортировать по возрастанию(по абсолютному значению)" << endl;
	vector<int> vec = { 53, 33, 90, 87, 24, 70, 65, 45, 75, 23, 33, 56, 45, 81, 100, 10, 24, 124 };
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
	nth_element(vec.begin(), vec.begin() + 1, vec.end(), [](int elem1, int elem2) { if (elem1 < 0) { elem1* (-1); }
	if (elem2 < 0) { elem2* (-1); }
	return (elem1 < elem2); });

	for (auto i : vec)
		cout << i << " ";
	cout << endl;


}

void seven() {
	cout << "Выявление наличия выхода за область значений функции" << endl;
	vector<int> vec = { 53, 33, 33, 9, 9, 9, 9, 9, 0, 87, 24, 70, 65, 45, 75, 23, 33, 56, 45, 81, 100, 10, 24, 9, 9, 0, 87, 124 };
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
	if (none_of(vec.begin(), vec.end(), [](int elem) { return !((elem != 0) && (elem < 100) && (elem > -100)); }))
		cout << "Все элементы входят в область определения." << endl;
	else
		cout << "Не все элементы входят в область определения." << endl;

}

void eight() {
	cout << "Копирование элементов подходящих под условие" << endl;
	vector<int> vec1 = { 53, 33, 33, 9, 9, 9, 9, 9, 0, 87, 24, 70, 65, 45, 75, 23, 33, 56, 45, 81, 100, 10, 24, 9, 9, 0, 87, 124 };
	vector <int> vec(28);
	for (auto i : vec1) {
		cout << i << " ";
	}
	cout << endl;
	cout << endl;
	copy_if(vec1.begin(), vec1.end(), vec.begin(), [](int elem) {return ((elem != 0) && (elem < 100) && (elem > -100)); });
	for (auto i : vec) {
		if (i != 0) {
			cout << i << " ";
		}
	}
	cout << endl;
}

void nine() {
	cout << "Сравнение двух последовательностей" << endl;
	vector<int> vec1 = { 53, 33, 33, 9, 9, 9, 9, 9, 0, 87, 24, 70, 65, 45, 75, 23, 33, 56, 45, 81, 100, 10, 24, 9, 9, 0, 87, 124 };
	vector<int> vec2 = { 53, 33, 33, 9, 9, 9, 9, 9, 0, 87, 24, 70, 65, 45, 75, 23, 33, 56, 45, 81, 100, 10, 24, 9, 9, 0, 87, 124 };
	for (auto i : vec1) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : vec2) {
		cout << i << " ";
	}
	cout << endl;
	if (equal(vec1.begin(), vec1.end(), vec2.begin(), [](int elem1, int elem2) { if (elem1 < 0) { elem1* (-1); }
	if (elem2 < 0) { elem2* (-1); }
	return (elem1 == elem2); }))
		cout << "Последовательности совпадают." << endl;
	else
		cout << "Последовательности совпадают." << endl;
}

void ten() {
	cout << "Количество людей набравших не менее 50 баллов" << endl;
	vector<int> marks = { 53, 33, 95, 99, 24, 70, 65, 45, 75, 100, 0, -5 };
	for (auto i : marks) {
		cout << i << " ";
	}
	cout << endl;
	cout << (count_if(marks.begin(), marks.end(), [](int elem) { return elem >= 50; })) << endl;
}


int main() {
	setlocale(LC_ALL, "Rus");


	cout << "№1" << endl;
	first();
	cout << "\n";
	cout << "№2" << endl;
	second();
	cout << "\n";
	cout << "№3" << endl;
	third();
	cout << "\n";
	cout << "№4" << endl;
	four();
	cout << "\n";
	cout << "№5" << endl;
	five();
	cout << "\n";
	cout << "№6" << endl;
	six();
	cout << "\n";
	cout << "№7" << endl;
	seven();
	cout << "\n";
	cout << "№8" << endl;
	eight();
	cout << "\n";
	cout << "№9" << endl;
	nine();
	cout << "\n";
	cout << "№10" << endl;
	ten();
	cout << "\n";

}
