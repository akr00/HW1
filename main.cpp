#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

struct pnode {
    void *data;
    pnode *next;
    pnode *prev;
};


class doubleLinkList {
public:

    node *front, *rear;
    int size;
    pnode *pFront, *pRear;

    doubleLinkList() {
        (*front).next = nullptr;
        (*rear).next = nullptr;
        (*front).prev = nullptr;
        (*rear).prev = nullptr;
        (*front).data = 0;
        (*rear).data = 0;
        (*pFront).data = nullptr;
        (*pRear).data = nullptr;
        (*pFront).next = nullptr;
        (*pRear).next = nullptr;
        (*pFront).prev = nullptr;
        (*pRear).prev = nullptr;

        size = 0;

    }


    void insertFront(node **f, node **r, int data) {
        node *p;
        p = new node;
        p->data = data;
        p->prev = nullptr;
        if(f == nullptr){ // list is empty
            p->next = nullptr;
            *f = *r = p;

        } else{ // 1 or more in list
            p->next = *f;
            *f = p;
        }

    }

    void insert_front(pnode **f, pnode **r, void *data) {
        pnode *p;
        p = new pnode;
        p->data = data;
        p->prev = nullptr;
        if(f == nullptr){ // list is empty
            p->next = nullptr;
            *f = *r = p;

        } else{ // 1 or more in list
            p->next = *f;
            *f = p;
        }
    }

    void insert_rear(node **f, node **r, int data) {
        node *p;
        p = new node;
        p->data = data;
        p->next = nullptr;
        if(*f == nullptr){ // list is empty
            (*f) = p;
            (*r) = p;
            p->prev = nullptr;
        }else{ // 1 or more in list
            p->prev = (*r);
            (*r)->next= p;
            (*r) = p;

        }
    }

    void insert_rear(pnode **f, pnode **r, int *data) {
        pnode *p;
        p = new pnode;
        p->data = data;
        p->next = nullptr;
        if(*f == nullptr){ // list is empty
            (*f) = p;
            (*r) = p;
            p->prev = nullptr;
        }else{ // 1 or more in list
            p->prev = (*r);
            (*r)->next= p;
            (*r) = p;

        }
    }

    int remove_front_i(node **f, node **r) {
        int hold;
        node *p;

        if(*f == nullptr){ // 0 nodes
            hold = -0;

        } else if(*f == *r){ // 1 node
            hold = (*f)->data;
            p = *f;
            delete p;
            p = nullptr;
            (*f) =  nullptr;
            p->next = nullptr;
        } else{ // more than 1 node
            hold = (*f)->data;
            (*f)->prev = nullptr;
            p = *f;
            *f = (*f)->next;
            delete p;
            p->next = nullptr;
        }
        return hold;
    }

    void *remove_front_p(pnode **f, pnode **r) {
        void * hold;
        pnode *p;

        if(*f == nullptr){ // 0 nodes
            hold = nullptr;

        } else if(*f == *r){ // 1 node
            hold = (*f)->data;
            p = *f;
            delete p;
            p = nullptr;
            (*f) =  nullptr;
            p->next = nullptr;
        } else{ // more than 1 node
            hold = (*f)->data;
            (*f)->prev = nullptr;
            p = *f;
            *f = (*f)->next;
            delete p;
            p->next = nullptr;
        }
        return hold;
    }

    int remove_rear_i(node **f, node **r) {
        int hold;
        if((*r) == nullptr){//empty
            hold = -0;
        }else if((*f) == (*r)){//1
            hold = (*r)->data;
            delete (*r);
            (*f) = (*r) = nullptr;
        }else{//more than 1
            hold = (*r)->data;
            (*r) = (*r)->prev;
            delete (*r)->next;
            (*r)-> next = nullptr;
        }
        return hold;
    }

    void *remove_rear_p(pnode **f, pnode **r) {
        void *hold;
        if((*r) == nullptr){//empty
            hold = nullptr;
        }else if((*f) == (*r)){//1
            hold = (*r)->data;
            delete (*r);
            (*f) = (*r) = nullptr;
        }else{//more than 1
            hold = (*r)->data;
            (*r) = (*r)->prev;
            delete (*r)->next;
            (*r)-> next = nullptr;
            return hold;
        }



    }

    int empty(node **f, node **r){
        while((*f)->next != nullptr){
            remove_front_i(f, r);
        }
        remove_front_i(f, r);
    }

};


int main() {

    doubleLinkList dll;

    void *g;



    dll.insertFront(&dll.front, &dll.rear, 5);
    dll.insert_front(&dll.pFront, &dll.pRear, g);
    int ans = (dll.remove_front_i(&dll.front, &dll.rear));
    cout << to_string(ans);
    return 0;
}
