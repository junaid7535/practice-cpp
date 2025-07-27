#include<iostream>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

class Animal{
    private:
    int age;

    public: 
    Animal(){
        age = 5;
    }

    friend void Cat(Animal);
};

void Cat(Animal a){
    cout << a.age;
}
int main(){
    Animal a;
    Cat(a);
}