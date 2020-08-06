// This code demonstrates the initialization order of constructors and
// destructors when there is class inheritance.
//
// Author: Jihuan Tian
// Date:

#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "A() default" << endl; }
    A(int i) : x(i) { cout << "A()" << endl;}
    ~A() { cout << "~A()" << endl; }
    int x;
};

class B {
public:
    B(int i = 0) : x(i) { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
    int x;
};

class C : public A {
public:
    // Note:
    // The basic rule is before the constructor's bracket, everything should be initialized.

    // The order of the initialization list in the constructor is not related to the real
    // initialization order. The real order depends on the order of: （下面的初始化顺序是先父辈后自己）
    // 1. Parent class is initialized first. If the parent has its own parent, then the grandfather is
    //    initialized first. This is equivalent to the depth-prioritized search.
    // 2. The member objects contained in the class are initialized following the order of their
    //    declarations.
    // 3. Finally, the current class' own constructor is called.
    // 4. For local objects, they are constructed in the order of their declarations.
    C(int i = 0) : x(i), A(i) { cout << "C()" << endl; }
    // The order of destruction
    // 1. Member objects are destructed first in the reverse order of their declarations.
    // 2. Parent class is destructed following the order of depth-prioritized search.
    // 3. The current class' own destructor is called.
    // 4. For local objects, they are destructed in the reverse order of their declarations.
    ~C() { cout << "~C()" << endl; }
    B x;
};

int main(){
    C c(1);
    A a;
    B b(1);

    return 0;
}
