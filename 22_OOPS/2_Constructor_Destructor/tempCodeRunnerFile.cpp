    cout << "We are inside the main function" << endl;
    
    cout << "\nCreating first object n1 " << endl;
    num n1;
    
    {
        cout << "\nEntering a block" << endl;
        cout << "Creating two more objects" << endl;
        num n2, n3;
        cout << "Exiting the block" << endl;
    }
    
    cout << "\nCreating another object n4" << endl;
    num n4;
