#include "Header.h"

enum COMMANDS {
	CREATE_TRAM = 1,
	TRAMS_IN_STOP,
	STOPS_IN_TRAM,
	TRAMS,
	EXIT
};

int main() {
	cout << "Commands:\nCREATE_TRAM = 1  Command in the form of tram name (space) number of stops (space) stops (separated by a space)\nTRAMS_IN_STOP=2  Enter the name of the stop\n";
	cout << "STOPS_IN_TRAM=3  Specify the name of the tram\nTRAMS=4\nEXIT=5\n";
	string command;
	map<string, vector<string>> stop;
	map<string, vector<string>> alltram;
	while (1) {
		cin >> command;
		if (command == "CREATE_TRAM" || command == to_string(CREATE_TRAM)) {
			create_tram(stop, alltram);//Создание нового трамвайного маршрута с указанием остановок
		}
		else if (command == "TRAMS_IN_STOP" || command == to_string(TRAMS_IN_STOP)) {
			trams_in_stop(stop);//Отображение всех трамваев проходящих через остановку
		}
		else if (command == "STOPS_IN_TRAM" || command == to_string(STOPS_IN_TRAM)) {
			stops_in_tram(stop, alltram);//Отображение всех остановок для конкретного трамвая а также трамваев проходящих через остановки этого трамвая
		}
		else if (command == "TRAMS" || command == to_string(TRAMS)) {
			trams(stop);//Отображение всех трамвайных маршрутов с указанием остановок
		}
		else if (command == "EXIT" || command == to_string(EXIT)) {
			exit(0);//Выход из программы
		}
		else {
			cout << "Incorrect command" << endl;
		}
	}
}
