#pragma once
#include "Dept.h"
#include <iomanip>
#include <sstream>

class Shop {
private:
	struct shop {
		string name;
	}s;
	Shop* next, * prev;
	Dept* d;
public:
	Shop() {
		s.name = "HEAD";
		this->next = this->prev = this;
		this->d = new Dept();
	}
	Shop(string name) {
		s.name = name;
		this->next = this->prev = this;
		this->d = new Dept();
	}
	~Shop() {
		Dept* current = d->GetNext();
		while (current != d) {
			Dept* temp = current;
			current = current->GetNext();
			delete(temp);
		}
		delete(d);
	}
	bool isEmpty() {
		return d == d->GetNext();
	}
	bool Add(int mode, int mode1,int number,int number1, string spec) {
		if (isEmpty()) {
			Dept* temp = new Dept(number1, spec);
			temp->SetNext(d);
			temp->SetPrev(d);
			d->SetNext(temp);
			d->SetPrev(temp);
			return true;
		}
		if (mode == 2) {
			Dept* temp = new Dept(number1, spec);
			temp->SetNext(d);
			temp->SetPrev(d->GetPrev());
			d->GetPrev()->SetNext(temp);
			d->SetPrev(temp);
			return true;
		}
		Dept* current = nullptr;
		if (mode == 0) current = d->GetNext();
		if (mode == 1) current = d->GetPrev();
		do {
			if (current->GetNumber() == number1) return false;
			if (current->GetNumber() == number) {
				Dept* temp = new Dept(number1, spec);
				if (mode1 == 0) {
					temp->SetNext(current);
					temp->SetPrev(current->GetPrev());
					current->GetPrev()->SetNext(temp);
					current->SetPrev(temp);
				}
				if (mode1 == 1) {
					temp->SetPrev(current);
					temp->SetNext(current->GetNext());
					current->GetNext()->SetPrev(temp);
					current->SetNext(temp);
				}
				return true;
			}
			if (mode == 0) current = current->GetNext();
			if (mode == 1) current = current->GetPrev();
		} while (current != d);
		return false;
	}
	bool Del(int mode,int number) {
		Dept* current = nullptr;
		if (mode == 0) current = d->GetNext();
		if (mode == 1) current = d->GetPrev();
		while (current != d) {
			if (current->GetNumber() == number) {
				Dept* temp = current;
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
	bool Find(int mode, int number) {
		if (!isEmpty()) {
			Dept* current = nullptr;
			if (mode == 0) current = d->GetNext();
			if (mode == 1) current = d->GetPrev();
			while (current != d) {
				if (current->GetNumber() == number) {
					return true;
				}
				if (mode == 0) { current = current->GetNext(); }
				if (mode == 1) { current = current->GetPrev(); }
			}
		}
		return false;
	}
	void Show(int mode) {
		if (!isEmpty()) {
			Dept* current = nullptr;
			if (mode == 0) current = d->GetNext();
			if (mode == 1) current = d->GetPrev();
			while (current != d) {
				if (current != d->GetNext() && mode == 0 || current != d->GetPrev() && mode == 1) cout << "|" << setw(16) << "|";
				cout << setw(13) << current->GetNumber() << setw(8) << " " << setw(10) << current->GetSpec();
				if (current->GetNext() != d && mode == 0 || current->GetPrev() != d && mode == 1) cout << "\n";
				if (mode == 0) current = current->GetNext();
				if (mode == 1) current = current->GetPrev();
			}
		}

	}
	string getString()
	{
		string str = "";
		if (!isEmpty())
		{
			Dept* current = d->GetNext();
			while (current != d){
				stringstream ss;
				str += " ";
				ss << current->GetNumber();
				str += ss.str();
				str += " ";
				str += current->GetSpec();
				current = current->GetNext();
			} 
		}
		return str;
	}
	void SetName(string name) { s.name = name; }
	string GetName() { return s.name; }
	Shop* GetNext() {
		return this->next;
	}
	Shop* GetPrev() {
		return this->prev;
	}
	void SetNext(Shop* next) {
		this->next = next;
	}
	void SetPrev(Shop* prev) {
		this->prev = prev;
	}
};