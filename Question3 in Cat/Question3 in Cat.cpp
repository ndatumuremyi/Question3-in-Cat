// Question3 in Cat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
};

ListNode* oos(ListNode* list) {
    const int max = 3;
    ListNode* current = list;
    ListNode* allnode[max];
    allnode[0] = current;
    int i = 1;
    while (current->next) {
        allnode[i] = current->next;
        current = current->next;
        i++;
    }
    /*for (int j = max - 2; j >= 0; j--) {
        allnode[j + 1]->next = allnode[j];
    }*/
    allnode[2]->next = allnode[0];
    
    allnode[0]->next = allnode[1];

    list = allnode[max - 1];
    allnode[1]->next = nullptr;
    return list;
}
void print(ListNode* l) {
    while (l) {
        cout << l->data << "    ";
        l = l->next;
    }
    cout << endl;
}

int main()
{
    ListNode* first = new ListNode;
    first->data = 1;
    ListNode* second = new ListNode;
    second->data = 2;
    ListNode* third = new ListNode;
    third->data = 3;
    first->next = second;
    second->next = third;
    third->next = nullptr;
    print(first);
    first = oos(first);
    print(first);
    //cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
