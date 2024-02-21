#include <iostream>
#include <sstream>
#include <string>

#include "Node.h"
#include "List.h"
#include "CLinkedList.h"
#include "CLinkedList.cpp"
#include "List.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"


using namespace std;


/* -------------------------------------------------------------------------- */
/*                                 PLEASE READ                                */
/* -------------------------------------------------------------------------- */
/*
    Hello 110 Student :). This main.cpp provides very very basic testing that should help prevent some errors
    in your code. However, it is not a complete test suite. You should write your own tests to ensure that your
    code is working as expected

    Please do not be surprised if this main works but your FF upload fails as the FF main is different from this one.
    This Assignment has many edge cases, please test as much as possible.
*/



void t1(){
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<int> list;
    cout<<"Testing basics"<<endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    list.insert(4, 3);
    list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
    list.remove(0);//remember remove works based of index
    list.remove(0);
    list.remove(100);//test for invalid
    list.remove(1);
    list.removeElements(2);
    list.print();// Output should be "Empty\n
    list.append(1);
    list.append(1);
    list.print();// Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print();// Output should be "Empty\n
}

void t2(){
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<int> list;
    cout<<"Testing rotations"<<endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.RRotate(2);
    list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    list.LRotate(7);
    list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    cout<<"Testing Assignment operator and rotation"<<endl;
    CLinkedList<int> list2;
    list2= list;
    list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    list2.RRotate(2);
    list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
}

void testEdgeCases() {
    cout << "Testing CLinkedList" << endl;

    // Test with an empty list
    CLinkedList<int> list1;
    cout << "\nTesting empty list" << endl;
    cout<<"Print:\t";list1.print();
    list1.reverse();
    cout<<"Reverse:\t";list1.print();
    list1.filter("==",7);
    cout<<"Filter:\t";list1.print();
    list1.swap(0,0);
    cout<<"Swap:\t";list1.print();
    list1.LRotate(3);
    cout<<"LRotate:\t";list1.print();
    list1.RRotate(3);
    cout<<"RRotate:\t";list1.print();
    list1.slice(0,0);
    cout<<"Slice  :\t";list1.print();
    list1.remove(0);
    list1.removeElements(2);
    cout<<"Remove:\t";list1.print();

    // Test with a list of size 1
    CLinkedList<int> list2;
    list2.append(1);
    cout << "\nTesting list of size 1" << endl;
    cout<<"Print:  \t";list2.print();
    list2.reverse();
    cout<<"Reverse:\t";list2.print();
    list2.swap(0,0);
    cout<<"Swap:   \t";list2.print();
    list2.LRotate(3);
    cout<<"LRotate:\t";list2.print();
    list2.RRotate(3);
    cout<<"RRotate:\t";list2.print();
    list2.slice(0,0);
    cout<<"Slice  :\t";list2.print();
    list2.filter("<",7);
    cout<<"Filter: \t";list2.print();
    list2.filter(">=",7);
    cout<<"Filter: \t";list2.print();
    list2.remove(0);
    list2.removeElements(2);
    cout<<"Remove: \t";list2.print();

    // Test with a list of size 2 or more
    CLinkedList<int> list3;
    list3.append(1);
    list3.append(2);
    list3.append(3);
    list3.prepend(4);
    list3.insert(5, 2);

    cout << "Testing list of size 5" << endl;
    cout<<"Print:  \t";list3.print();
    list3.reverse();
    cout<<"Reverse:\t";list3.print();
    list3.swap(0,4);
    cout<<"Swap:   \t";list3.print();
    list3.swap(1,3);
    cout<<"Swap:   \t";list3.print();
    list3.LRotate(3);
    cout<<"LRotate:\t";list3.print();
    list3.RRotate(3);
    cout<<"RRotate:\t";list3.print();
    list3.slice(1,3);
    cout<<"Slice:  \t";list3.print();
    list3.prepend(4);
    list3.prepend(3);
    cout<<"Reset:  \t";list3.print();
    list3.filter("<",7);
    cout<<"Filter: \t";list3.print();
    list3.filter(">=",2);
    cout<<"Filter: \t";list3.print();
    list3.removeElements(2);
    list3.remove(0);
    cout<<"Remove: \t";list3.print();
}

void testLinkedListFunctions() {
    CLinkedList<int> list1;
    CLinkedList<int> list2;
    CLinkedList<int> list3;

    cout << "Testing functions" << endl;
    // Test operator= and operator==
    list1.append(1);
    list1.append(2);
    list2 = list1;
    
    list1.append(3);
    list2.append(4);

    list1.print();
    list2.print();
    list3.print();
    cout<<endl;
    
    // Test operator+=
    list3.append(5);
    list1 += list3;

    list1.print();
    list2.print();
    list3.print();
    cout<<endl;

    // Test operator-
    list3.clear();
    list3.append(3);
    list3.append(5);
    CLinkedList<int>* temp = list1 - list3;
    list1 = *temp;
    delete temp;

    list1.print();
    list2.print();
    list3.print();
    cout<<endl;

    // Test removeDuplicates
    list1.append(2);
    list1.removeDuplicates();

    list1.print();
    list2.print();
    list3.print();
    cout<<endl;

    // Test consume
    list3.append(6);
    list1.consume(list3);
    list1.consume(list1);

    list1.print();
    list2.print();
    list3.print();
    cout<<endl;

    int arr[] = {3, 1, 2, 4, 5, 2, 1, 2, 3, 5};
    for (int i = 0; i < 10; i++)
        list3.append(arr[i]);

    list1.clear();
    int arrr[] = {1, 1, 2, 2, 2, 3, 3, 4, 5, 5};
    for (int i = 0; i < 10; i++)
        list1.append(arrr[i]);

    if (list1 == list3)
        cout<<"list1 == list3\n";
    else
        cout<<"list1 != list3\n";

    list3.print();
    list3.removeDuplicates();
    list3.print();

    cout << "All tests passed!" << endl;
}

void t3(){
    cout<<"Testing Stack"<<endl;
    Stack<int> stack;
    cout<<"Testing basics"<<endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout<<stack.pop()<<endl;// Output should be "4\n"
    cout<<stack.peek()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "2\n"
    cout<<stack.pop()<<endl;// Output should be "1\n"
    cout<<stack.pop()<<endl;// Output should be "0\n" since we are returning the default val
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout<<"Testing copy constructor"<<endl;
    Stack<int> stack2(stack);
    cout<<stack2.pop()<<endl;// Output should be "3\n"
    cout<<stack2.pop()<<endl;// Output should be "2\n"
    cout<<stack2.pop()<<endl;// Output should be "1\n"
    cout<<stack2.pop()<<endl;// Output should be "0\n" since we are returning the default val
    cout<<stack.pop()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "2\n"
    cout<<stack.pop()<<endl;// Output should be "1\n"
    cout<<stack.pop()<<endl;// Output should be "0\n" since we are returning the default val
    //loading up items to test destructor
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
}

void t4(){
    cout<<"Testing Queue"<<endl;
    Queue<int> queue;
    cout<<"Testing basics"<<endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout<<queue.dequeue()<<endl;// Output should be "1\n"
    cout<<queue.peek()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "3\n"
    cout<<queue.dequeue()<<endl;// Output should be "4\n"
    cout<<queue.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout<<"Testing copy constructor"<<endl;
    Queue<int> queue2(queue);
    cout<<queue2.dequeue()<<endl;// Output should be "1\n"
    cout<<queue2.dequeue()<<endl;// Output should be "2\n"
    cout<<queue2.dequeue()<<endl;// Output should be "3\n"
    cout<<queue2.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    cout<<queue.dequeue()<<endl;// Output should be "1\n"
    cout<<queue.dequeue()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "3\n"
    cout<<queue.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    //loading up items to test destructor
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

}

void comsumetest1(){
    CLinkedList<int> l1; 
    CLinkedList<int> l2; 

    l1.consume(l2);
    cout<<"Empty consumes empty:";l1.print();
    cout<<"Left:";l2.print();
    cout<<endl;   
}

void comsumetest2(){
    CLinkedList<int> l1; 
    CLinkedList<int> l2; 
    l1.append(1);
    l1.append(2);

    l1.consume(l2);
    cout<<"Non-empty consumes empty:";l1.print();
    cout<<"Left:";l2.print();
    cout<<endl;   
}

void comsumetest3(){
    CLinkedList<int> l1; 
    CLinkedList<int> l2; 
    l2.append(2);
    l2.append(3);

    l1.consume(l2);
    cout<<"Empty consumes non-empty:";l1.print();
    cout<<"Left:";l2.print();
    cout<<endl;   
}

void comsumetest4(){
    CLinkedList<int> l1; 
    CLinkedList<int> l2; 
    l1.append(1);
    l1.append(2);
    l2.append(2);
    l2.append(3);

    l1.consume(l2);
    cout<<"Non-empty consumes non-empty:";l1.print();
    cout<<"Left:";l2.print();
    cout<<endl;   
}

int main(){
    t1();
    t2();
    testEdgeCases();
    testLinkedListFunctions();
    t3();
    t4();

    comsumetest1();
    comsumetest2();
    comsumetest3();
    comsumetest4();

    return 0;
}