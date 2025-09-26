#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

};

struct Linkedlist{
     Node* head;
     Linkedlist() {
        head = nullptr;
     }

  void accessList( int giatri) {
      Node*a = head;
      if(head == NULL) {
        cout << "ko the truy cap";
      } else {
          for (int i = 1; i < giatri && a != NULL; i++) {
            a = a->next;
            return;
          }
      }
      if (a == NULL ) {
          cout << "ko the truy cap";
      } else {
      cout << a->data;
      }

  }


  void addfirst(int giatri){
            Node *B = new Node{giatri,Head};
            Head = B;
        }


  void addLast(int x) {
        Node* newNode = new Node(x);
        Node* b = head;
        if(head == NULL) {
            head = newNode;
        }
        else{
            while(a->next != NULL) {
                b = b->next;
            }
            b->next = newNode;
        }
    }

    void deletefirst() {
         if(head == NULL) {
            cout << "ko can xoa";
         }
         Node*a = head;
         head = head->next;
         delete a;
    }




    void deletecuoi() {
        if(head == NULL) {
            cout << "cannot xoa";
        }
        Node* prev = NULL;
        Node* sau = head;
        while (sau->next != NULL) {
            prev = sau;
            sau = sau->next;
        }

    }

    void delete(int giatri) {
        Node*prev =  NULL;
        Node*sau = head;
        if (head == NULL ) {
            cout << "cannot xoa";
        }
        if (giatri == 1 ){
            deletefirst;
        }
        for (int i = 1; i < giatri; i++) {
            prev = sau;
            sau = sau->next;
            if (sau == NULL) {
                cout << "k ton tai";
            }
        }
        if(sau->next == NULL) {
           deletecuoi();
        } else {
          prev->next = sau->next;
          delete sau;
        }
    }


    void print(){
            Node *A = Head;
            while( A != nullptr){
                cout<<A -> data<<" ";
                A = A -> next;
            }
            cout<<endl;
        }

    void innguoc(Node* head) {
        if(head == NULL) {
            cout <<" ";
        }
        innguoc(head -> next); cout <<head->data<<" ";
    }
};


#endif // LINKEDLIST_INCLUDED

