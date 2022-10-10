#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Net.h"
#include <fstream>

using namespace std;

class Storage
{
private:
	string address;
public:
	Storage(string _address) {
		address = _address;
	};

	bool InputData(Net* _net) {
		string name,spec;
		int number;
		char buffer[100];
		char* f;

		ifstream file(address);

		if (!file.is_open()) return false;
		file.getline(buffer, 100);
		if (buffer != " ")
		{
			name = buffer;
			_net->SetName(name);
		}
		else {
			cout << "Файл пуст\n";
			return false;
		}
		while (!file.eof()) {
			file.getline(buffer, 100);
			f = strtok(buffer, " ");
			if (f == NULL) continue;
			name = buffer;
			_net->Add(0,name);
			f = strtok(NULL, " ");
			while (f) {
				number = atoi(f);
				f = strtok(NULL, " ");
				spec = f;
				_net->AddQ(0, 2, 0, name, 0, number, spec);
				f = strtok(NULL, " ");
			}
		}
		file.close();
		return true;
	}

	bool OutputData(Net* _net) {
		ofstream file(address);
		if (!file.is_open())
			return false;
		file << _net->GetName() + '\n' + _net->getString();
		file.close();
		return true;
	};

	~Storage() { };
};




