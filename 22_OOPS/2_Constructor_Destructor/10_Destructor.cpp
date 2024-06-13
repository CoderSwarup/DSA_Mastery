//destructor never takes an argument or does not return vale 
#include <iostream>
using namespace std;

class num {
public:
    static int count;
    
    num() {
        count++;
        cout << "Constructor is called for object number " << count << endl;
    }
    
    ~num() {
        cout << "Destructor is called for object number " << count << endl;
        count--;
    }
};

int num::count = 0;

int main() {
    // cout << "We are inside the main function" << endl;
    
    // cout << "\nCreating first object n1 " << endl;
    // num n1;
    
    // {
    //     cout << "\nEntering a block" << endl;
    //     cout << "Creating two more objects" << endl;
    //     num n2, n3;
    //     cout << "Exiting the block" << endl;
    // }
    
    // cout << "\nCreating another object n4" << endl;
    // num n4;


	// How To use Pointer with Destructor 
	cout << "\n Creating Obj with Pointer" << endl;
	num *n5 = new num();

	// how to release this memory
	delete n5;
    
    return 0;
}
