#include "List.h"
#include "Node.h"
#include "SinglyLinked.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = { 15, 3, 19};
    int size = sizeof(arr)/ sizeof(arr[0]);
    SinglyList<int> arrList(arr,size);
    cout<<"Default  \t"<<&arrList<<endl;

    arrList.insert(69,1);
    cout<<"Add 69 at 1\t"<<&arrList<<endl;

    int index = arrList.remove(69);
    cout<<"Remove 69 ["<<index<<"]\t"<<&arrList<<endl;

    cout<<"index [1]\t"<<arrList[1]<<endl;
    cout<<"index [-1]\t"<<arrList[-1]<<endl;

    int* integer = new int(3);
    cout<<"Wheres 3? \t"<<arrList(integer)<<endl;
    delete integer;

    cout<<"iff (15)\t "<<arrList.getIndexFromFront(15)<<endl;
    cout<<"ifr (15)\t "<<arrList.getIndexFromRear(15)<<endl;

    List<int>* a = arrList.sort(true);
    cout << "acending:\t" << (SinglyList<int>*)a << endl;
    delete a;

    List<int>* d = arrList.sort(false);
    cout << "acending:\t" << (SinglyList<int>*)d << endl;
    delete d;

    cout<<"Smallest\t"<<arrList.findSmallest()<<endl;
    cout<<"Biggest \t"<<arrList.findBiggest()<<endl;

    List<int>* c = arrList.clone();
    cout << "clone   \t" << (SinglyList<int>*)c << endl;
    delete c;
}