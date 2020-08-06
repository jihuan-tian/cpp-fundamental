// Test of constant pointer and pointer pointing to a constant object.
// Author: Jihuan Tian
// Date: 2017-06-11
// Conclusion: const keyword associates with its closest part. For example,
//   const int * b; means constant integer, which is the content to which the pointer points.
//   int * const b; means constant pointer, the address stored in the pointer cannot be changed.

#include <iostream>

using namespace std;

int main(){
    int a = 5;

    // /////////////////////
    // Constant object
    // /////////////////////
    const int * b = &a;
    // The following is wrong:
    // *b = 3;
    // The following is correct:
    b = NULL;
    cout << "b has been set to NULL." << endl;

    // ////////////////////////////
    // Constant pointer address
    // ////////////////////////////
    // c points to an object which can be changed but c itself is a constant.
    int * const c = &a;
    // The following is correct.
    *c = 3;
    cout << "c points to " << *c << endl;
    // The following is wrong.
    // c = NULL;

    // //////////////////////////////////////
    // Constant object and constant address
    // //////////////////////////////////////
    const int * const d = &a;
    // The following is wrong:
    // *d = 3;
    // The following is wrong.
    // d = NULL;

    return 0;
}
