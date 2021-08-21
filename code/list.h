#ifndef EXTRACLASE_1_DATOS_II_LIST_H
#define EXTRACLASE_1_DATOS_II_LIST_H

class list {
private:

    struct node {
        int data;
        node* next;
    };

    typedef struct node* nodePtr;

    nodePtr head;
    nodePtr current;
    nodePtr temp;

public: // This is where the functions go

    list();
    void addNode(int addData);
    void deleteNode(int delData);
    void printList();

    const node *getHead() const;

};

#endif //EXTRACLASE_1_DATOS_II_LIST_H
