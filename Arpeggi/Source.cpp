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
		cout << "������ �����. ���������: ";
	}
	return a;
}

void Add()
{
	int mode = 0;
	string name;
	cout << "������� �������� ��������: ";
	cin >> name;
	cout << "������ �� ������ ������(0)/��������(1):";
	mode = failure();
	if (net->Add(mode,name)) cout << "���������� �������!\n";
	else cout << "���������� �� �������!\n";
}
void AddQ()
{
	int mode, mode1=0,mode2, number=0,number1;
	string name, spec;
	cout << "������� �������� ��������: ";
	cin >> name;
	cout << "������ �� ������ ������(0)/��������(1):";
	mode = failure();
	if (!net->isEmptyS(name)) {
		cout << "������� ����� ������, ����� �������� ������ �������� �����: ";
		number = failure();
		cout << "�������� ��(0)/�����(1) ���������: ";
		mode1 = failure();
	}
	cout << "������� ����� ������: ";
	number1 = failure();
	cout << "������� ������� ��������: ";
	cin >> spec;
	cout << "������ �� ��������� ������(0)/��������(1):";
	mode2 = failure();
	if (net->AddQ(mode,mode1,mode2,name,number,number1,spec)) cout << "���������� �������!\n";
	else cout << "���������� �� �������!\n";
}
void Del()
{
	int mode;
	string name;
	cout << "������� �������� ��������: ";
	cin >> name;
	cout << "������ �� ������ ������(0)/��������(1):";
	mode = failure();
	if (net->Del(mode,name)) cout << "�������� �������!\n";
	else cout << "�������� �� �������!\n";
}
void DelQ()
{
	int number, mode, mode1;
	string name;
	cout << "������� �������� ��������, � ������� ��������� ������� �����: ";
	cin >> name;
	cout << "������ �� ������ ������(0)/��������(1):";
	mode = failure();
	cout << "������� ����� ������: ";
	number = failure();
	cout << "������ �� ��������� ������(0)/��������(1):";
	mode1 = failure();
	if (net->DelQ(mode, mode1, name , number)) cout << "�������� �������!\n";
	else cout << "�������� �� �������!\n";
}
void Find()
{
	int mode;
	string name;
	cout << "������� �������� ��������: ";
	cin >> name;
	cout << "������ �� ������ ������(0)/��������(1):";
	mode = failure();
	if (net->Find(mode,name)) cout << "������� ������!\n";
	else cout << "������� �� ������!";
}
void FindQ()
{
	int number, mode, mode1;
	string name;
	cout << "������� �������� ��������: ";
	cin >> name;
	cout << "������ �� ������ ������(0)/��������(1):";
	mode = failure();
	cout << "������� ����� ������: ";
	number = failure();
	cout << "������ �� ��������� ������(0)/��������(1):";
	mode1 = failure();
	if (net->FindQ(mode, mode1, name, number)) cout << "����� ������!\n";
	else cout << "����� �� ������!\n";

}
void Show()
{
	{
		int mode, mode1;
		cout << "\n������ �� ������ ������(0)/��������(1):";
		mode = failure();
		cout << "\n������ �� ��������� ������(0)/��������(1):";
		mode1 = failure();
		system("cls");
		cout << "\n----------------------------------------------------\n";
		cout << "|    �������� ���� '" << net->GetName() << "'";
		cout << "\n----------------------------------------------------";
		cout << "\n|    ��������   |" << "        �����           �������         ";
		cout << "\n|    ��������   |" << "        ������          ��������        \n";
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
		cout << "\n �������� ��������:\n";
		cout << " 1. �������� �������\n";
		cout << " 2. �������� �����\n";
		cout << " 3. ������� �������\n";
		cout << " 4. ������� �����\n";
		cout << " 5. ����� �������\n";
		cout << " 6. ����� �����\n";
		cout << " 7. ������������� �������� ����\n";
		cout << " 8. ������� �������� ���� � ������� ������\n";
		cout << " 9. ��������� �������� ���� �� �����\n";
		cout << " 10. ��������� �������� ���� � ����\n";
		cout << " 0. �����\n";
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
			cout << "������� �������� �������� ����: ";
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
			if (file.InputData(net)) cout << "�������� �������!";
			else
			{
				cout << "������!";
				delete(net);
				net = new Net();
			}
		}
		else if (n == 10)
		{
			if (net != NULL)
			{
				if (file.OutputData(net)) cout << "�������� �������!";
				else cout << "������";
			}
			else cout << "������!";
		}
		else if (n == 0) {
			delete(net);
			break;
		}
	}
}
