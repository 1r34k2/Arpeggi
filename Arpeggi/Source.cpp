#include "Storage.h"
#include <stdlib.h>
#include <Windows.h>


Net* net = NULL;
Storage file("text.txt");

int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Повторите: ";
	}
	return a;
}

void Add()
{
	int mode = 0;
	string name;
	cout << "Введите название магазина: ";
	cin >> name;
	cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	if (net->Add(mode,name)) cout << "Добавление успешно!\n";
	else cout << "Добавление не успешно!\n";
}
void AddQ()
{
	int mode, mode1=0,mode2, number=0,number1;
	string name, spec;
	cout << "Введите название магазина: ";
	cin >> name;
	cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	if (!net->isEmptyS(name)) {
		cout << "Введите номер отдела, после которого хотите добавить новый: ";
		number = failure();
		cout << "Добавить до(0)/после(1) заданного: ";
		mode1 = failure();
	}
	cout << "Введите номер отдела: ";
	number1 = failure();
	cout << "Введите профиль торговли: ";
	cin >> spec;
	cout << "Проход по подсписку прямой(0)/обратный(1):";
	mode2 = failure();
	if (net->AddQ(mode,mode1,mode2,name,number,number1,spec)) cout << "Добавление успешно!\n";
	else cout << "Добавление не успешно!\n";
}
void Del()
{
	int mode;
	string name;
	cout << "Введите название магазина: ";
	cin >> name;
	cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	if (net->Del(mode,name)) cout << "Удаление успешно!\n";
	else cout << "Удаление не успешно!\n";
}
void DelQ()
{
	int number, mode, mode1;
	string name;
	cout << "Введите название магазина, в котором требуется удалить отдел: ";
	cin >> name;
	cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	cout << "Введите номер отдела: ";
	number = failure();
	cout << "Проход по подсписку прямой(0)/обратный(1):";
	mode1 = failure();
	if (net->DelQ(mode, mode1, name , number)) cout << "Удаление успешно!\n";
	else cout << "Удаление не успешно!\n";
}
void Find()
{
	int mode;
	string name;
	cout << "Введите название магазина: ";
	cin >> name;
	cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	if (net->Find(mode,name)) cout << "Магазин найден!\n";
	else cout << "Магазин не найден!";
}
void FindQ()
{
	int number, mode, mode1;
	string name;
	cout << "Введите название магазина: ";
	cin >> name;
	cout << "Проход по списку прямой(0)/обратный(1):";
	mode = failure();
	cout << "Введите номер отдела: ";
	number = failure();
	cout << "Проход по подсписку прямой(0)/обратный(1):";
	mode1 = failure();
	if (net->FindQ(mode, mode1, name, number)) cout << "Отдел найден!\n";
	else cout << "Отдел не найден!\n";

}
void Show()
{
	{
		int mode, mode1;
		cout << "\nПроход по списку прямой(0)/обратный(1):";
		mode = failure();
		cout << "\nПроход по подсписку прямой(0)/обратный(1):";
		mode1 = failure();
		system("cls");
		cout << "\n----------------------------------------------------\n";
		cout << "|    Торговая сеть '" << net->GetName() << "'";
		cout << "\n----------------------------------------------------";
		cout << "\n|    Название   |" << "        Номер           Профиль         ";
		cout << "\n|    магазина   |" << "        отдела          торговли        \n";
		net->Show(mode, mode1);
		cout << "----------------------------------------------------\n";
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	net = new Net();
	while (true) {
		Show();
		cout << "\n Выберите действие:\n";
		cout << " 1. Добавить магазин\n";
		cout << " 2. Добавить отдел\n";
		cout << " 3. Удалить магазин\n";
		cout << " 4. Удалить отдел\n";
		cout << " 5. Найти магазин\n";
		cout << " 6. Найти отдел\n";
		cout << " 7. Переименовать торговую сеть\n";
		cout << " 8. Удалить торговую сеть и создать пустую\n";
		cout << " 9. Загрузить торговую сеть из файла\n";
		cout << " 10. Выгрузить торговую сеть в файл\n";
		cout << " 0. Выход\n";
		n = failure();
		if (n == 1)
			Add();
		else if (n == 2)
			AddQ();
		else if (n == 3)
			Del();
		else if (n == 4)
			DelQ();
		else if (n == 5)
			Find();
		else if (n == 6)
			FindQ();
		else if (n == 7)
		{
			string newName;
			cout << "Введите название торговой сети: ";
			cin >> newName;
			net->SetName(newName);
		}
		else if (n == 8)
		{
			delete(net);
			net = new Net();
		}
		else if (n == 9)
		{
			delete(net);
			net = new Net();
			if (file.InputData(net)) cout << "Загрузка успешна!";
			else
			{
				cout << "Ошибка!";
				delete(net);
				net = new Net();
			}
		}
		else if (n == 10)
		{
			if (net != NULL)
			{
				if (file.OutputData(net)) cout << "Выгрузка успешна!";
				else cout << "Ошибка";
			}
			else cout << "Ошибка!";
		}
		else if (n == 0) {
			delete(net);
			break;
		}
	}
}
