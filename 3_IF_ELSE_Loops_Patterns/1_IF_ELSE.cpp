#include<iostream>
using namespace std;


int main(){
    int A;
    cin>>A;

    if(A>0){
        cout<<"A is Positive"<<endl;
    }else{

        cout<<"A is Negative"<<endl;
    }

    A = cin.get(); // get as a charater '1' and then convert it into integer
    cout <<A<<endl;



     int a ,b , c;
     
     cout << "enter 3 number (a b c) : " << endl;

     cin >> a;
     cin >> b;
     cin >> c;

     if (a >b)
     {                          // c > a > b
       if (a>c)
       {
           cout << "a is greater :" << a << endl;
       }
       else{
           cout << "c is greater : "<< c << endl;
       }  
     }

      else{
          if (b > c)                  // c > b > a
          {
              cout << "b is greater : " << b << endl;
          }else{
              cout << "c is greater : " << c << endl;
          }
          
      }


    // -- Switch case Statment 

    int day;
        cout << "enter day (0 to 6) :" << endl;
        cin >> day;

        // switch statement

           switch (day)
           {
           case 0:
               cout << "today is monday"<< endl;
               break;
           case 1:
               cout << "today is tuesday"<< endl;
               break;
           case 2:
               cout << "today is wednesday"<< endl;
               break;
           case 3:
               cout << "today is thuesday"<< endl;
               break;
           case 4:
               cout << "today is friday"<< endl;
               break;
           case 5:
               cout << "today is saturday"<< endl;
               break;
           case 6:
               cout << "today is sunday"<< endl;
               break;
           
           default:
                cout << "wrong day please enter 0 to 6"<< endl;
               break;
           }
     


    
    return 0;
}

