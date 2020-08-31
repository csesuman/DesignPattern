#include<bits/stdc++.h>

using namespace std;

class Sorting {
public:
    void bubbleSort( int a[] , int n ) {

        for(int i = 0 ; i <  n ;  i++) {
            for(int j = i + 1 ;  j < n  ; j++ ){

                if( compare( a[i] ,  a[j]) ) {
                    swap( a[i] , a[j] );
                }
            }
        }
    }

    void display(int a[],int n) {

        cout<<"Elements : ";
        for(int i = 0 ; i <  n  ;  i++) {
            cout << " " <<a[i];
        }
        cout<<endl;
    }
private:
    virtual bool compare(int a,int b) = 0 ;
};

class Ascending : public Sorting {
private:
    bool compare (int a,int b)  {
        return a < b;
    }
};

class Descending : public Sorting {
private:
    bool compare (int a,int b)  {
        return a > b;
    }
};

int main() {
    int a[] = {80,10,7,50,60,30};
    int n = sizeof(a)/sizeof(int);

    Sorting *srt = new Descending();
    srt->bubbleSort(a, n);
    srt->display(a , n);

    srt = new Ascending();
    srt->bubbleSort(a, n);
    srt->display(a , n);


    return 0;
}
