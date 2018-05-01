#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
template <class t>
class node{
 public:
      t alias;
      node<t> *next;

      node()
      {
          next = NULL;
      }
};
template <class t>
class linkedlist
{
public:
    node<t> *head;


    linkedlist()
    {
        head = NULL;
    }

    node<t> *create_node(t ele)
    {
        node<t> *temp = new node<t>;
        temp->alias = ele;
        temp->next = NULL;
        return temp;
    }
    int LLsize()
    {
        int counter = 0;
        node<t> *temp = head;
         while(temp != NULL)
        {
            ++counter;
            temp = temp->next;
        }
        return counter;
    }
    void forwtraversal()
    {
       node<t> *temp;
        temp = head;
        while(temp != NULL) //calling while until linked list exist
        {
            cout<<temp->alias<<"  ";
            temp = temp->next;
        }
    }

    void backtraversalrecu(node<t> *head)
    {
       node<t> *temp;
        temp = head;
        if(temp != NULL)
             backtraversalrecu(temp->next);

        cout<<temp->data;
    }

    node<t>* searchll(t ele)
    {
       node<t> *temp;
       temp = head;
       while(temp != NULL)
       {
           if(temp->data == ele)
           {
               cout<<"\n Found at returned pointer !!";
               return temp;
           }
           else
            temp = temp->next;

       }
       cout<<"\n NOT Found !!! \n Returned NULL. ";
       return temp;
    }

    void Insertionbeginning(t ele)
    {
      node<t> *temp,*p ;
      temp = create_node(ele);
         if (head == NULL)
          {
            head = temp;
            head->next = NULL;
          }
        else
          {
            p = head;
            head = temp;
            head->next = p;
          }
    }

    void Insertionpos(t ele , int pos)
    {
        int sizell;
        node<t> *temp,*ptr,*s;
        sizell = LLsize();
        temp = create_node(ele);
        if(pos == 1)
        {   head = temp;
            head->next = NULL;
        }
        else if(pos > 1  && pos <= sizell){
                ptr = head;

            for(int i=1 ; i<sizell ;i++)
                ptr = ptr->next;

            s = ptr->next;
            ptr->next = temp;
            temp->next = s;
        }
        else
            cout<<"\n Error 8888 [position out of range] ";

    }
    void Insertlast(t ele)
    {
        node<t> *temp;

        temp = create_node(ele);

        if (head == NULL)
            head = temp;
        else {
            node<t> *curr;
            curr = head;

            while (curr->next != NULL)
                curr = curr->next;

            curr->next = temp;
        }
    }

    void reverse_3ptr()
    {
       node<t> *curr, *prev, *Next;
       cout<<"\n REVERSING linkedlist ...";
       curr = head;
       prev = NULL;
       while(curr!=NULL)
       {
         Next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = Next;
       }
       head = prev;
    }

    void reverse_2ptr()
    {
      node<t> *prev,*Next;
      cout<<"\n REVERSING linkedlist ...";
      Next = head->next;
      prev = NULL;
      while(head->next != NULL)
      {
        head->next = prev;
        prev = head;
        head  = Next;
        Next = head->next;
      }
      head->next = prev;
    }
    void reverse_1ptr(node<t> * temp)
    {
      if(temp == NULL)
        return;
      if(temp->next == NULL)
      {
        head = temp;
        return;
      }
      reverse_1ptr(temp->next);
      temp->next->next = temp;
      temp->next = temp;
    }
    node<t>* concatenate(node<t> *head1 , node<t> *head2)
    {
      node<t> *temp;
      temp = head1;
        if(head1 == NULL)
        {
          return head2;
        }else if(head2 == NULL)
        {
          return head1;
        }else{
          while(temp->next != NULL)
          {
            temp = temp->next;
          }
          temp->next = head2;
          return head1;
        }
    }

    void deletenode(node<t> *head , int pos)
    {
      int k = 1;
      node<t> *p,*q;
      if(head == NULL)
      {
        cout<<"\n Empty Linked List !!";
        return;
      }
      p = head;
      if(pos == 1)
      {
        head = head->next;
        free(p);
        return;
      }
      else{
        while((p != NULL)&&(k<pos))
        {
          k++;
          q=p;
          p = p->next;
        }
        if(p == NULL)
          cout<<"\n position Does not exist !!";
        else{
          q->next = p->next;
          free(p);
        }
      }
    }
};
//overloading + operator for concatenation
template <class t>
    linkedlist<t> operator + (linkedlist<t> const &l1,linkedlist<t> const &l2)
    {
      linkedlist<t> c;
      c.head = c.concatenate(l1.head,l2.head);
      return c;
    }
