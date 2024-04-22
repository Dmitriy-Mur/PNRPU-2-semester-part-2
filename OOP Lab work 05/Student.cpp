#include "Student.h"

void Student::Show() {
	cout << name << ' ' << age << ' ' << subject << ' ' << mark << '\n';
}

Student::Student() {
	name = "";
	subject = "";
	age = 0;
	mark = 0;
}
Student::Student(string name, int age, string subject, int mark) {
	this->name = name;
	this->age = age;
	this->subject = subject;
	this->mark = mark;
}
Student::Student(const Student& copied) {
	name = copied.name;
	age = copied.age;
	subject = copied.subject;
	mark = copied.mark;
}
void Student::setSubject(string subject) {
	this->subject = subject;
}
void Student::setMark(int mark) {
	this->mark = mark;
}
string Student::getSubject() {
	return subject;
}
int Student::getMark() {
	return mark;
}
void Student::BadMark() {
	switch (mark) {
	case(1):
		cout << this->name << " имеет ужасную оценку\n";
		break;
	case(2):
		cout << this->name << " имеет плохую оценку\n";
		break;
	case(3):
		cout << this->name << " имеет удовлитворительную оценку\n";
		break;
	case(4):
		cout << this->name << " имеет хорошую оценку\n";
		break;
	case(5):
		cout << this->name << " имеет отличную оценку\n";
		break;
	default:
		cout << "Не может быть такой оценки\n";
	}
}

istream& operator>>(istream& in, Student& cur) {
	cout << "Введите данные в формате:\nимя возвраст предмет оценка\n";
	return (in >> cur.name >> cur.age >> cur.subject >> cur.mark);
}
ostream& operator<<(ostream& out, const Student& cur) {
	return (out << cur.name << ' ' << cur.age << ' ' << cur.subject << ' ' << cur.mark << '\n');
}
Student& Student::operator=(const Student& m_student) {//перегрузка оператора присваивания
	if (&m_student != this) {
		name = m_student.name;
		age = m_student.age;
		subject = m_student.subject;
		mark = m_student.mark;
	}
	return *this;
}