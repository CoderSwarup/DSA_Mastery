#include<iostream>
using namespace std;


void ChangePointer(int *p1,int *p2){
    p1 =p2;
    *p1 = 33;
}

int QFive(int x , int *py ,int **ppz){
    int y =0  ,z=0;
    **ppz =  **ppz +1;
    z = **ppz;
    *py = *py+ 2;
    y = *py;
    x += 3;
    return (x+y+z);
}

void QSix(char *f,char *s){
    while((*f = *s)){
        *f++;
        *s++;
    }
}

int main(){

     cout << "Q1" << endl;
    char arr[] = "GATE2024";
    char *p = arr;
    cout << (p + p[3] - p[1]) << endl; // 2024

    cout << endl << "Q2" << endl;
    int i = 0 , j =1;
    cout << i << " " << j << endl;
    ChangePointer(&i,&j);
    cout << i << " " << j <<  endl;


    cout << endl << "Q3" << endl;
    int *p1;
    int x =0;
    p1 = &x;
    int y =*p1;
    // *p1 = 78;
    (*p1)++;
    cout << x << " " << y << endl;

    cout << endl << "Q4" << endl;
    int aa =5 , bb =10;
    int &name = aa;
    int *ptr = &aa;
    (*ptr)++;
    ptr = &bb;
    *ptr += 5;
    name += 5;
    cout << aa << " " << bb << endl;


    cout << endl << "Q5" << endl;
    int c , *b , **a;
    c= 4 ; b =&c , a = &b;
    cout << QFive(c,b,a) <<  endl;



    cout << endl << "Q6" << endl; // Question is Like Copy string
    char f[] = "mohit";
    char s[] ="rohan";
    QSix(f,s);

    cout << f;
return 0;
}