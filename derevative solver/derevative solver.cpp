// derevative solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum OPER {
	ADD,
	SUB,
	MUL,
	DIV,
	EXP,
	LOG,
};
enum MATHENUM {
	CONSTANT,
	VARIABLE,
	OPERATION,
};
union math {
	mathunit mat;
	int con;
};

struct mathunit {
    math& a;
    math& b;
	MATHENUM a1;
	MATHENUM b1;
    OPER c;

	mathunit(math& a, math& b, MATHENUM a1, MATHENUM b1, OPER c) : a(a), b(b), a1(a1), b1(b1), c(c) {}


	mathunit& DERIVATIVE() {
		if (a1 == OPERATION and b1== OPERATION) {
			switch (c) {
			case ADD:
				return *new mathunit((math&)a.mat.DERIVATIVE(), (math&)b.mat.DERIVATIVE(),a1,b1,ADD);
			case SUB:
				return *new mathunit((math&)a.mat.DERIVATIVE(), (math&)b.mat.DERIVATIVE(), a1, b1, ADD);
			case MUL:
				return *new mathunit(
					(math&)*(new mathunit((math&)a.mat.DERIVATIVE(), (math&)b.mat, a1, b1, MUL)),
					(math&)*(new mathunit((math&)a.mat, (math&)b.mat.DERIVATIVE(), a1, b1, MUL)),
					OPERATION, OPERATION, ADD);
			case DIV:
				return *new mathunit(
					(math&)*new mathunit(
					(math&)*(new mathunit((math&)a.mat.DERIVATIVE(), (math&)b.mat, a1, b1, MUL)),
					(math&)*(new mathunit((math&)a.mat, (math&)b.mat.DERIVATIVE(), a1, b1, MUL)),
					OPERATION, OPERATION, SUB), (math&)*(new mathunit((math&)b.mat, (math&)b.mat,b1,b1,MUL)),
					OPERATION, OPERATION, DIV
					);
			}
		}
	}
};


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
