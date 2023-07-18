#include <iostream>
using namespace std;
struct node {
    int data;
    node* link;
    node() : data(0), link(nullptr) {}
};
void insert_front(node*& head, int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->link = head;
    head = new_node;
}
void insert_middle(node*& head, int data, int position)
{
    //No list exsits
    if (head == nullptr)
    {
        insert_front(head, data);
        return;
    }
    int i = 0;
    node* current = head;
    while (current->link != nullptr && i < position-1)
    {
        current = current->link;
        ++i;
    }
    node* new_node = new node;
    new_node->data = data;
    new_node->link = current->link;
    current->link = new_node;
}
void print_list(const node* head)
{
    const node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->link;
    }
    std::cout << '\n';
}
int main()
{
    node* head = new node;
    head->data = 5;
    insert_front(head, 10);
    insert_front(head, 15);
    print_list(head);
}