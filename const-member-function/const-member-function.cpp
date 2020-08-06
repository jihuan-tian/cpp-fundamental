// This code demonstrates the correct definition and usage of const member functions.
//
// Author: Jihuan Tian
// Date: 2017-07-01

#include <iostream>

using namespace std;

class A {
public:
    friend ostream& operator<<(ostream& os, const A& a);

    // Class static variables: it can be modified by const member functions.
    static int object_num;

    // Default constructor, which will increase the class counter whenever a new object is created.
    A() : value(0), pointer(0) { cout << "Number of A objects: " << ++object_num << endl; }
    // Constructor
    A(int val, int* pt) : value(val), pointer(pt) { cout << "Number of A objects: " << ++object_num << endl; }
    // Destructor: reduce the class counter whenever an object is destroyed.
    ~A() { cout << "Number of A objects: " << --object_num << endl; }

    // //////////////////////////////
    // Const member access functions
    // //////////////////////////////
    // Note: if these const member access functions are not defined, const object
    // of A cannot be accessed. Therefore, they are mandatory.

    // Const member function can only return const reference to class member.
    const int& GetValue() const { return value; }
    // Const member function can only return class member variables as const.
    // Note: the value pointed by the member pointer can be changed actually.
    int * const GetPointer() const { return pointer; }

    // The following definitions are invalid: if they operate on const object instance, they try to
    // convert the const member variables to mutable as the return value, which of course is not valid.
    // const member function can only return const reference to class members.
    //
    // The generated error message is:
    //   In member function 'int& A::GetValue() const':
    //     37:36: error: invalid initialization of reference of type 'int&' from expression of type
    //     'const int'
    // which is a direct indication that the member variables are automatically treated as const.
    // int& GetValue() const { return value; }
    // // Const member function can only return const pointer to class members.
    // // Note: the value pointed by the member pointer can be changed actually.
    // int* GetPointer() const { return pointer; }

    // //////////////////////////////////////////////
    // Non-const version of member access functions.
    // //////////////////////////////////////////////
    // If non-const version of member access functions are not defined, the const-
    // version of member access functions can still be used to access member
    // variables but in read-only mode, this because a mutable value can be converted to a const
    // value, but not vice versa.
    // Therefore, if we want to use the returned member variables as lvalue, we need these non-const
    // version member access functions.
    int& GetValue() { return value; }
    int* GetPointer() { return pointer; }

    // Because const keyword for member functions only applies to class member
    // variables, the value pointed by member pointer can be changed actually,
    // even though the member function is declared as const.
    int& GetPointerValue() const {
    	int present_object_num = object_num;

        // This line shows the const member function can really modify the class
        // static variable.
        A::object_num = 10;
        cout << "A::object_num is overwritten as 10" << endl;
        object_num = present_object_num;
        cout << "A::object_num is restored to " << object_num << endl;

        return *pointer;
    }

private:
    int value;
    int * pointer;
};

// Initialize the class object number to zero, which is a class static variable.
int A::object_num = 0;

ostream& operator<<(ostream& os, const A& a) {
    os << "value=" << a.value << ", " << "pointer value=" << *a.pointer << endl;

    return os;
}

int main(){
    int local_int = 3;
    int value1 = 5;
    int value2 = 8;

    // Define a mutable object.
    A a(value1, &local_int);
    cout << "object a is: " << a;
    // Change the member of a mutable object.
    a.GetValue() = value2;
    cout << "object a is changed to: " << a;

    // Define a const object.
    const A b(value1, &local_int);
    cout << "const object b is " << b;
    // Overwrite the value pointed by the pointer stored in the const class.
    *b.GetPointer() = 5;
    cout << b.GetPointerValue() << endl;
    // Get the member variable value of a const object. If const version of
    // member access functions are not defined, this is invalid and will produce
    // the following error:
    //   error: passing 'const A' as 'this' argument of 'int& A::GetValue()'
    //   discards qualifiers [-fpermissive]
    // This can be understood like this:
    // Everyone class member function's inherent first argument is the this pointer pointing to the
    // current instance, so it has the following form:
    //   result_type member_function(A* this_pointer, ...)
    // When the const keyword is appended to the member function, it is equivalent to declare:
    //   restul_type member_function(const A* this_pointer, ...)
    // which automatically makes the current object instance constant.
    // The situation we are facing is trying to pass a constant object to a non-const member function,
    // so the type casting from mutable to const is invalid.
    cout << "Member variable value in b is: " << b.GetValue() << endl;
    // Modify a const object: this should be invalid.
    // b.GetValue() = value2;
    // cout << "Const object b is changed to: " << b;

    // The following function executes:
    // 1. Modify the value pointed by member pointer in a const object: this is
    // valid even though the member function is const.
    // 2. Modify the class static variable, which does not belong to the (*this)
    // instance and is valid.
    b.GetPointerValue() = 1;
    cout << "Const object b is changed to: " << b;

    return 0;
}
