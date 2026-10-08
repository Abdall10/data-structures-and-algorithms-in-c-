class List {
    class node {
    public:
        int key;
        int data;
        node* next;
    };

    node *head, *cursor, *prev;

public:
    List();

    bool ListIsEmpty();
    bool cursorIsEmpty();
    void toFirst();
    bool atFirst();
    void Advance();
    void toEnd();
    bool atEnd();
    int ListCount();
    void updateData(int);
    void updateKey(int);
    int RetrieveData();
    void RetrieveData(int &);
    void insertFirst(int, int);
    void insertAfter(int, int);
    void insertBefore(int, int);
    void insertEnd(int, int);
    void deleteNode();
    void deleteAtFirst();
    void deleteEnd();
    void MakeListEmpty();
    bool searchByKey(const int &k);
    void traverse();
    void orderInsert(const int &k, const int &d);
    int RecursiveList_Size();
    int display();
};
