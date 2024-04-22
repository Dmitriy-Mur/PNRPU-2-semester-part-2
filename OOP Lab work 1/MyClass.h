#pragma once

class MyClass {
private:
	double first;
	unsigned int second;
public:
	void Init(double, unsigned int);
	void Read();
	void Show();
	double element(int j);
};

MyClass make_MyClass(double F, unsigned int S);
