//swap交换同一个变量则值不变

#include <iostream>

using namespace std;

int main(){
    int test = 1;
    swap(test, test);
    cout << test << endl;
    return 0;
}