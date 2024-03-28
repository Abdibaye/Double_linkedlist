#include <iostream>

using namespace std;

struct node
{
    struct node *pre;
    int data;
    struct node *next;
}*head = NULL, *last = NULL;

void create(int A[], int n)
{
    if (n <= 0)
    {
        cout << "Invalid array size!" << endl;
        return;
    }

    head = new node;
    head->data = A[0];
    head->pre = NULL;
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        struct node *temp = new node;
        temp->data = A[i];
        temp->pre = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void insertAtBeginning(int value)
{
    struct node *t = new node;
    t->data = value;
    t->pre = NULL;
    t->next = NULL;

    t->next = head;
    if (head != NULL)
        head->pre = t;
    head = t;
}

void insertAfterValue(int value, int b)
{
    struct node *t = new node;
    t->data = value;
    t->pre = NULL;
    t->next = NULL;

    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    struct node *temp = head;
    while (temp != NULL && temp->data != b)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found in the list!" << endl;
        return;
    }

    t->next = temp->next;
    if (temp->next != NULL)
        temp->next->pre = t;
    t->pre = temp;
    temp->next = t;
}

void deleteNode(int key)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    if (temp->data == key)
    {
        head = temp->next;
        if (head != NULL)
            head->pre = NULL;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found in the list!" << endl;
        return;
    }

    prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->pre = prev;

    delete temp;
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Elements in the list: ";
    struct node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    int A[n];

    int choice = 0;
    while (choice != 4)
    {
        cout << "Press 1 to create a list of numbers" << endl;
        cout << "Press 2 to insert a new node at the beginning of the list" << endl;
        cout << "Press 3 to insert a new node after a specific value" << endl;
        cout << "Press 4 to delete a node with a specific value" << endl;
        cout << "Press 5 to display the elements in the list" << endl;
        cout << "Press 6 to exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; i++)
                cin >> A[i];
            create(A, n);
            cout << "List created successfully!" << endl;
            break;

        case 2:
            int element;
            cout << "Enter the element you want to insert: ";
            cin >> element;
            insertAtBeginning(element);
            cout << "Element inserted successfully!" << endl;
            break;

        case 3:
            int value, b;
            cout << "Enter the value you want to insert: ";
            cin >> value;
            cout << "Enter the value after which you want to insert: ";
            cin >> b;
            insertAfterValue(value, b);
            cout << "Element inserted successfully!" << endl;
            break;

        case 4:
            int key;
            cout << "Enter the value you want to delete: ";
            cin >> key;
            deleteNode(key);
            cout << "Element deleted successfully!" << endl;
            break;

        case 5:
            display();
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}