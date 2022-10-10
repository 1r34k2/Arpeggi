#pragma once
#include "Shop.h"

class Net {
private:
	struct net {
		string name;
	}n;
	Shop* s;
public:
	Net() {
		n.name = "";
		s = new Shop();
	}
	Net(string name) {
		n.name = name;
		s = new Shop();
	}
	~Net() {
		Shop* current = s->GetNext();
		while (current != s) {
			Shop* temp = current;
			current = current->GetNext();
			delete(temp);
		}
		delete(s);
	}
	bool isEmpty() { return s == s->GetNext(); }
	bool isEmptyS(string name) {
		Shop* current = s->GetNext();
		while (current != s) {
			if (current->GetName() == name) return current->isEmpty();
			current = current->GetNext();
		}
		return 0;
	}
	bool Add(int mode,string name) {
		/*if (isEmpty()) {
			Shop* temp = new Shop(name);
			temp->SetNext(s);
			temp->SetPrev(s);
			s->SetNext(temp);
			s->SetPrev(temp);
			return true;
		}*/
		if (mode == 0) {
			Shop* temp = new Shop(name);
			Shop* current = s->GetNext();
			do {
				if (current->GetName() == name) return false;
				if (current->GetName() > name) {
					temp->SetNext(current);
					temp->SetPrev(current->GetPrev());
					current->GetPrev()->SetNext(temp);
					current->SetPrev(temp);
					if (current == s) s = temp;
					return true;
				}
				current = current->GetNext();
			} while (current != s);
			temp->SetNext(current);
			temp->SetPrev(current->GetPrev());
			current->GetPrev()->SetNext(temp);
			current->SetPrev(temp);
			return true;
		}
		if (mode == 1) {
			Shop* temp = new Shop(name);
			Shop* current = s->GetPrev();
			do {
				if (current->GetName() == name) return false;
				if (current->GetName() < name ) {
					temp->SetPrev(current);
					temp->SetNext(current->GetNext());
					current->GetNext()->SetPrev(temp);
					current->SetNext(temp);
					return true;
				}
				current = current->GetPrev();
			} while (current != s);
			temp->SetPrev(current);
			temp->SetNext(current->GetNext());
			current->GetNext()->SetPrev(temp);
			current->SetNext(temp);
			return true;
		}
		return false;
	}
	bool Del(int mode, string name) {
		Shop* current = nullptr;
		if (mode == 0) current = s->GetNext();
		if (mode == 1) current = s->GetPrev();
		while (current != s) {
			if (current->GetName() == name) {
				Shop* temp = current;
				current->GetNext()->SetPrev(current->GetPrev());
				current->GetPrev()->SetNext(current->GetNext());
				delete(temp);
				return true;
			}
			if (mode == 0) current = current->GetNext();
			if (mode == 1) current = current->GetPrev();
		}
		return false;
	}
	bool Find(int mode, string name) {
		if (!isEmpty()) {
			Shop* current = nullptr;
			if (mode == 0) current = s->GetNext();
			if (mode == 1) current = s->GetPrev();
			while (current != s) {
				if (current->GetName() == name) {
					return true;
				}
				if (mode == 0) { current = current->GetNext(); }
				if (mode == 1) { current = current->GetPrev(); }
			}
		}
		return false;
	}
	bool AddQ(int mode,int mode1,int mode2,string name,int number,int number1,string spec) {
		if (!isEmpty()) {
			Shop* current = nullptr;
			if (mode == 0) { current = s->GetNext(); }
			if (mode == 1) { current = s->GetPrev(); }
			do {
				if (current->GetName() == name) {
					return current->Add(mode1, mode2, number, number1, spec);
				}
				if (mode == 0) { current = current->GetNext(); }
				if (mode == 1) { current = current->GetPrev(); }
			} while (current != s);
		}
		return false;
	}
	bool DelQ(int mode,int mode1,string name,int number) {
		if (!isEmpty()) {
			Shop* current = nullptr;
			if (mode == 0) { current = s->GetNext(); }
			if (mode == 1) { current = s->GetPrev(); }
			do {
				if (current->GetName() == name) {
					return current->Del(mode1,number);
				}
				if (mode == 0) { current = current->GetPrev(); }
				if (mode == 1) { current = current->GetPrev(); }
			} while (current != s);
		}
		return false;
	}
	bool FindQ(int mode,int mode1,string name, int number) {
		if (!isEmpty()) {
			Shop* current = nullptr;
			if (mode == 0) { current = s->GetNext(); }
			if (mode == 1) { current = s->GetPrev(); }
			do {
				if (current->GetName() == name) {
					return current->Find(mode1, number);
				}
				if (mode == 0) { current = current->GetNext(); }
				if (mode == 1) { current = current->GetPrev(); }
			} while (current != s);
		}
		return false;
	}
	void Show(int mode, int mode1) {
		if (!isEmpty()) {
			if (mode == 0) {
				Shop* current = s->GetNext();
				do {
					cout << "----------------------------------------------------\n";
					cout << "|" << setw(8) << current->GetName() << setw(8) << "|";
					current->Show(mode1);
					cout << "\n";
					current = current->GetNext();
				} while (current != s);
			}
			if (mode == 1) {
				Shop* current = s->GetPrev();
				do {
					cout << "----------------------------------------------------\n";
					cout << "|" << setw(8) << current->GetName() << setw(8) << "|";
					current->Show(mode1);
					cout << "\n";
					current = current->GetPrev();
				} while (current != s);
			}
		}
	}
	string getString()
	{
		string str = "";
		Shop* current = s->GetNext();
		do {
			str += current->GetName();
			str += current->getString();
			str += '\n';
			current = current->GetNext();
		} while (current != s);
		return str;
	}
	void SetName(string name) { n.name = name; }
	string GetName() { return n.name; }
};