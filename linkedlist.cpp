#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>   
#include <cmath>
#include<climits>
#include <unordered_map>
#include <unordered_set> 

using namespace std;

struct Node
{
  
int data;
Node *next;



Node(int x)
{
 
  data = x;
  next = NULL;
 
}
};

void printList(Node *head)
{
 Node *curr = head;
  while(curr!=NULL)
  {
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}
void insert_beg(Node *&head,int i)
{
Node *temp = new Node(i);
temp->next = head;
head = temp;
//return temp;
}

Node* insert_end(Node *head,int i)
{
  
  Node *temp = new Node(i);
  Node *curr = head;

  if(head==NULL)
  return temp;

while(curr->next!=NULL)
curr = curr->next;

curr->next = temp;
return head;
}
void delete_last(Node *head)
{
   Node *curr = head;
   
while(curr->next->next!=NULL)
curr = curr->next;

Node *temp = curr->next;
curr->next = NULL;

delete temp;


}
Node *insert_atpos(Node *head,int i,int pos)
{
  Node *temp = new Node(i);
  if(pos==1)
  {
    temp->next = head;
return temp;
  }

int curr_pos=2;
Node *curr = head;

while(curr_pos!=pos)
{
curr=curr->next;
curr_pos++;
}

temp->next = curr->next;
curr->next = temp;

return head;
}

Node *middle(Node *head)
{
 
 Node *slow_curr = head;
 Node *fast_curr = head;


 while(fast_curr!=NULL && fast_curr->next!=NULL)
 {
  fast_curr = fast_curr->next->next;
  slow_curr = slow_curr->next;
 }
return slow_curr;
}
int list_size(Node* head)
{
Node *curr = head;
int l = 0;
  while(curr!=NULL)
  {
    curr = curr->next;
    l++;
  }
  return l;
}
Node *rev(Node *head)
{
  Node *curr = head;
  Node *prev = NULL;
  Node *next;

  while(curr!=NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
Node *rec_rev(Node *head,Node *next,Node *prev,Node *curr)
{
  if(curr==NULL)
  return prev;

  next = curr->next;
  curr->next = prev;
  prev = curr;
  curr = next;

  return rec_rev(head,next,prev,curr);
}
bool match(Node *head,Node *middle)
    {
        while(middle!=NULL)
        {
            if(head->data!=middle->data)
            return false;

            head = head->next;
            middle = middle->next;
        }
        return true;
    }
    bool isPalindrome(Node* head)
     {
        Node *middle_ptr = middle(head);
        // cout<<middle_ptr->data;
        middle_ptr = rev(middle_ptr);
        printList(head);
        return match(head,middle_ptr);
    }
    void swap_nodes(int &x,int &y)
    {
      int temp = x;
      x = y;
      y = temp;
    }
    Node* oddEvenList(Node* head)
     {
    Node *even_head = head->next;
    Node *curr_even = head->next;
    Node *curr = head;

while(curr_even!=NULL && curr_even->next!=NULL)
 {
    curr->next = curr->next->next;
    curr=curr->next;

    curr_even->next = curr_even->next->next;
    curr_even = curr_even->next;
 }
    curr->next = even_head;

    return head;
    }

    Node *merge(Node *head1, Node *head2)
    {
     Node *dummy = new Node(-1);
     Node *curr = dummy;

    
      while(head1!=NULL && head2!=NULL)
      {
        if(head1->data>head2->data)
        {
           curr->next = head2;
          head2 = head2->next;
         
        }
        else 
        {
          curr->next = head1;
          head1 = head1->next;    
        }
        curr = curr->next;
      }
        if (head1 != NULL) 
        curr->next = head1;
     else 
        curr->next = head2;
    
      Node *res =  dummy->next;
      delete dummy;

      return res;
    }
int main()
 {
  
Node *head1 = new Node(5);
head1 = insert_end(head1,7);
head1 = insert_end(head1,19);

Node *head2 = new Node(3);
head2 = insert_end(head2,4);
head2 = insert_end(head2,8);
head2 = insert_end(head2,9);



Node *dummy = merge(head1,head2);
printList(dummy);
}

