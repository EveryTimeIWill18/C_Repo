#include<iostream>
#include<string>
#include<vector>
#include<exception>
#include<stdio.h>
// preprocessor macros
#define MAX_SIZE 100
#define GETMAX(A, B) ((a)>(b) ? (a) : (b))
#define STR(x_str) #x_str 
#define GLUE(a,b) a ## b

#line 20 "assigning variable"

// Predefined macro names
// __LINE__ : Integer value representing the current line in source code in fiel be compiled
// __FILE__ : String literal containing the presumed namoe of source file being compiled
// __DATE__ : String literal od date "Mmm dd yyyy"
// __TIME__ : String literal of time, "hh::mm:ss"
// __cplusplus : An int value rep the compiler version
// __STDC_HOSTED__ : 1 if the implementaion is a hosted one, 0 otherwise







// #ifdef: section of code will be compiled only if the keyword has been previously defined
#ifdef MAX_SIZE
int TABLE[MAX_SIZE];
#endif // MAX_SIZE


// #ifndef: compiles only if keyword has not been defined
#ifndef TABLE_SIZE
#define TABLE_SIZE 100
#endif // !TABLE_SIZE

// #if #else #elif directives example
#if MAX_SIZE>200
#undef MAX_SIZE
#define MAX_SIZE 200

#elif TABLE_SIZE<50
#undef TABLE_SIZE
#define TABLE_SIZE 50

#else
#undef TABLE_SIZE
#define TABLE_SIZE 150
#endif // MAX_SIZE>200

// #error aborts compilation process when it is found
#ifndef __cplusplus		// change to somethign undefiend and this error msg will be raised
#error A C++ compiler is required! 
#endif // !__cplusplus



/*
	Pointers Lookup
	---------------
	*x:		pointed to by x
	&x:		address of x
	x.y:	member of x
	x->y:	member, y, of object pointed to by x
	(*x).y: member y of object pointed to by x (equivalent to the previous one)
	x[0]:	first object pointed to by x
	x[1]:   second object pointed to by x
	x[n]:   (n+1)th object pointed to by x


*/


class Rectangle {
private:
	int width, height;
public:
	Rectangle(int x, int y);
	int area(void);
};

Rectangle::Rectangle(int x, int y) : width(x), height(y) {}
int Rectangle::area(void) { return this->width * this->height; }

// Operator Overloading
class CVector {
private:
public:
	int x, y;
	CVector();
	CVector(int a, int b);
	CVector operator + (const  CVector&);	// Overload the + operator
	std::string get_x_and_y();

};

CVector::CVector() {};

CVector::CVector(int a, int b) : x(a), y(b) {}

std::string CVector::get_x_and_y() {
	std::string values;
	values = "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
	return values;
}
CVector CVector::operator+ (const CVector& param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
		
	return temp;
}

class Dummy {
public:
	static int n;
	Dummy() { n++; };
};

// Global Dummy
int Dummy::n = 0;


// Const member functions
//int get() const { return x; }        // const member function
//const int& get() { return x; }       // member function returning a const&
//const int& get() const { return x; } // const member function returning a const& 
class ConstClass {
public:
	int x;
	ConstClass(int val) : x(val) {}
	int get() { return x; }
	int c_get() const { return x; }
};


// Class templates
template <class T>
class  mypair {
	T values[2];
public:
	mypair(T first, T second) {
		values[0] = first;
		values[1] = second;
	}

	void print() {
		std::cout << "values[0] := " << this->values[0] << "\n"
			<< "values[1] := " << this->values[1] << "\n";
	}

};

template <class T>
class Pair {
	T a, b;
public:
	Pair(T first, T second)  {
		a = first;
		b = second;
	}
	T getmax();
};


template <class T>
T Pair<T>::getmax() {
	T ret_val;
	ret_val = a > b ? a : b;
	return ret_val;
}

// Template specialization
template <class T>
class Container {
	T element;
public:
	Container(T arg);
	T increase();
};

template <class T>
Container<T>::Container(T arg) {
	element = arg;
}
template <class T>
T Container<T>::increase() {
	return ++element;
}

// Class template specialization
template <>
class Container <char> {
	char element;
public:
	Container(char arg) { element = arg; }
	char uppercase() {
		if ((element >= 'a') && (element <= 'z')) {
			element += 'A' - 'a';
			return element;
		}
	}

};


// Copy constructor
class Example5 {
	std::string* str_ptr;
public:
	Example5 (const std::string& str) : str_ptr(new std::string(str)) {}
	~Example5() { delete str_ptr; }
	// Copy constructor
	Example5(const Example5& x) : str_ptr(new std::string(x.context())) {}
	// access content
	const std::string& context() const { return *str_ptr; }
};

// Inheritance
class Polygon {
protected:
	int width, height;
public:
	void set_values(int a, int b) { width = a; height = b; }
	// virtual method can be redefined in a derived class
	virtual int area() { return 0; }
};

class Output {
public:
	static void print(int i) {
		std::cout << i << "\n";
	}
};


class NewRectangle : public Polygon, public Output {
public:
	int area() { return width * height; }
};

class Triangle : public Polygon, public Output {
public:
	int area(void) { return (width * height / 2); }
};


// Abstract Base Classes
// Classes with at least one pure virtual function are abstract base clases
class AbstractPolygon {
protected:
	int width, height;
public:
	void set_values(int a, int b) { width = a; height = b; }
	virtual int area() = 0; // has no definition and has '=0' makes it a pure virtual function
};









int main() {

	std::cout << "__LINE__ # " << __LINE__ << "\n";
	std::cout << "__cplusplus " << __cplusplus << "\n";
	std::cout << "__DATE__ " << __DATE__ << "\n";
	std::cout << "__TIME__ " << __TIME__ << "\n";
	std::cout << "__TIMESPATMP__ " << __TIMESTAMP__ << "\n";
	std::cout << STR(test) << std::endl; // preprocessor macro function with preprocessor parameter
	

	// Pointers to classes
	auto rec1 = Rectangle(3, 4);

	// Member access for pointers to classes uses (->)
	Rectangle* foo, * bar, * baz;	// 3 pointers to Rectangle
	foo = &rec1;

	bar = new Rectangle(5, 6);	// Creats a single Rectangle class object
	baz = new Rectangle[2]{ {2, 5}, {3, 6} };	// Creates a array of Rectangle class objects

	std::cout << "BAR.area() := " << bar->area() << "\n";

	for (int i = 0; i < 2; i++) {
		std::cout << "BAZ: Rectangle[" << i << "].area() := " << baz[i].area() << "\n";
	}
	// Deallocate memory of bar and baz once finished
	delete bar;
	delete[] baz;


	// Create instances of CVectors

	auto cv_1 = CVector(10, 20);
	auto cv_2 = CVector(4, 5);
	auto cv_3 = cv_1 + cv_2;
	auto cv_4 = cv_1 + cv_1;
	auto cv_5 = cv_2 + cv_2;
	auto cv_6 = cv_4 + cv_4;

	CVector cv_vectors[6] = { cv_1, cv_2, cv_3, cv_4, cv_5, cv_6 };

	for (int i = 0; i < 6; i++) {
		std::cout << "CV_VECTORS[" << i << "] := " << cv_vectors[i].get_x_and_y() << "\n";
	}


	// Static class variables
	Dummy d_1;
	std::cout << "DUMMY(d_1) := " << d_1.n << "\n";
	Dummy d_n[5];
	Dummy* d_ptr = new Dummy();
	std::cout << "DUMMY(d_1) := " << d_1.n << "\n";


	// Const class
	const ConstClass c_cls_1(10); 
	// c_cls_1.x = 400;		// not valid: x cannot be modified since c_cls_1 is const
	std::cout << "c_cls_1.x := " << c_cls_1.x << "\n"; // valid: const class is READ-ONLY
	//c_cls_1.get(); // not valid: .get() is not const
	std::cout << "c_get() output ==> " << c_cls_1.c_get() << "\n";
	

	// Template classes
	mypair<int> my_p_int(115, 36);
	mypair<double> my_p_dbl(12.5, 999.789);
	my_p_int.print();
	my_p_dbl.print();

	Pair<std::string> str_pair("A", "B");
	std::cout << "MAX ==> " << str_pair.getmax() << "\n";

	Container<char> mychar('j');
	std::cout << "MyCar ==> " << mychar.uppercase() << "\n";



	// Polymorphism
	NewRectangle n_rec_1;
	Triangle t_1;
	Polygon* p_poly_1 = &n_rec_1;  // pointer to a erived class is type-compatible to a pointer to its base class
	Polygon* p_poly_2 = &t_1;
	p_poly_1->set_values(4, 5);
	p_poly_1->set_values(4, 5);
	std::cout << "NewRectanlge area := " << n_rec_1.area() << "\n";
	std::cout << "Triangle area := " << t_1.area() << "\n";


	// exceptions
	try {
		std::string error = "ERROR MSG";
		throw  'c';
	}
	catch (int e) {
		std::cout << "An int exception occurred. Exception # " << e << "\n";
	}
	catch (char e) {
		std::cout << "A char exception occurred. Exception # " << e << "\n";
	}
	catch (std::exception& e) {
		//std::cout << "A string exception occurred. Exception # " << e << "\n";
		std::cout << "Standard Exception (e): " << e.what() << "\n";
	}
	catch (...) {
		std::cout << "A default exception occurred. Exception # " << "\n";
		
	}




	return 0;
}


//  delete preprocessor macros
#undef MAX GETMAX
