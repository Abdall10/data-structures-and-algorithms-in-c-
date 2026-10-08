
class Stack {
    
public:
  Stack(int nelements = 128);
  Stack(const Stack &);
  ~Stack();
  void push(int);
  void push(char);
  void pop(int &);
  void pop(char);
  void stackTOP(int &) const;
  bool stackIsEmpty() const;
  bool stackIsFull() const;
  void findMiddle(int &);
  void deleteMiddle();
  int stackSize();

  private:
  int *stack;
  int top , maxSize;
  int cont;


};