#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;
class Node{
    public:
    int data;
    Node* xnode;

};
Node* Xor(Node* x, Node* y){
    return reinterpret_cast<Node*>(
           reinterpret_cast<uintptr_t>(x)
         ^reinterpret_cast<uintptr_t>(y));
}
void insert(Node** head_ref, int data)
{
    Node* new_node = new Node();
    new_node->data=data;
    new_node->xnode=*head_ref;
    if(*head_ref!=NULL)
    {
        (*head_ref)->xnode = Xor(new_node, (*head_ref)->xnode);
    }
    *head_ref = new_node;

}

Node* delEnd(Node** head_ref){
  if(*head_ref==NULL){
    cout<<"Empty list\n";
  }
  else{
    Node* curr = *head_ref;
    Node* prev = NULL;
    Node* next;
    while(Xor(curr->xnode,prev)!=NULL){
      next = Xor(prev, curr->xnode);
      prev = curr;
      curr = next;
    }
    if (prev != NULL)
      prev->xnode = Xor(Xor(prev->xnode, curr), NULL);
    else
            *head_ref = NULL;
 
    free(curr);
  }
  return *head_ref;
}
void printList(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    cout<<"The nodes are:\n";
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        next = Xor(prev, curr->xnode);
        prev=curr;
        curr=next;
    }
}
int main()
{
    Node *head = NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    printList(head);
    Node *h=delEnd(&head);
    printList(h);
}
