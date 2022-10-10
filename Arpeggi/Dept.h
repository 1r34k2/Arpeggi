#pragma once
#include <iostream>

using namespace std;

class Dept {
private:
	struct dept {
		int number;
		string spec;
	}d;
	Dept* next, * prev;
public:
	Dept() {
		d.number = 0;
		d.spec = "HEAD";
		this->next = this->prev = this;
	}
	Dept(int number, string spec) {
		d.number = number;
		d.spec = spec;
		this->next = this->prev = this;
	}
	~Dept()
	{
		this->next = this->prev = nullptr;
	}
	int GetNumber() {
		return d.number;
	}
	string GetSpec() {
		return d.spec;
	}
	void SetNumber(int number) {
		d.number = number;
	}
	void SetSpec(string spec) {
		d.spec = spec;
	}
	Dept* GetNext() {
		return this->next;
	}
	Dept* GetPrev() {
		return this->prev;
	}
	void SetNext(Dept* next) {
		this->next = next;
	}
	void SetPrev(Dept* prev) {
		this->prev = prev;
	}
};