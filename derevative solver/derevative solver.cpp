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
union mathun {
	mathunit* mat;
	int con;
	char var;
};
struct math {
	mathun mat;
	MATHENUM a1;
	math(mathunit* mat1){
		a1 = OPERATION;
		mat.mat = mat1;
	}
	math(int con){
		a1 = CONSTANT;
		mat.con = con;
	}
	math(char var){
		a1 = VARIABLE;
		mat.var = var;
	}
	math* DERIVATIVETRUE() const{
		switch (a1)
		{
		case CONSTANT:
			return new math(0);
			break;
		case VARIABLE:
			return new math(1);
			break;
		case OPERATION:
			return mat.mat->DERIVATIVE();
			break;
		default:
			break;
		}
	}
};


struct mathunit {
    math* a;
    math* b;
    OPER c;

	mathunit(math* a, math* b, OPER c) : a(a), b(b), c(c) {}


	math* DERIVATIVE() const{
		if (a->a1 != CONSTANT and b->a1 != CONSTANT) {
			switch (c) {
			case ADD:
				return new math(new mathunit(a->DERIVATIVETRUE(), b->DERIVATIVETRUE(),ADD));
			case SUB:
				return new math(new mathunit(a->DERIVATIVETRUE(), b->DERIVATIVETRUE(), SUB));
			case MUL:
				return new math(new mathunit(
							new math(new mathunit(a->DERIVATIVETRUE(), b, MUL)), 
							new math(new mathunit(a, b->DERIVATIVETRUE(), MUL))
					,ADD));
			case DIV:
				return new math(new mathunit(
						new math(new mathunit(
							new math(new mathunit(a->DERIVATIVETRUE(), b, MUL)),
							new math(new mathunit(a, b->DERIVATIVETRUE(), MUL)), SUB)), 
						new math(new mathunit(b,b,MUL)),DIV));
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
