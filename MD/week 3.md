# WEEK 3

## 顺序表类的定义

    public:
        seqList(int initSize = 10);
        ~seqList() {delete [] data;}
        void clear() {currentLength = 0;}
        int length() const {return currentLength;}
        void insert(int i, const elemType &x);
        void remove(int i);
        int search(const elemType &x) const;
        elemType visit(int i) const;
        void traverse() const;

### 构造函数

    template <class elemType>
    seqList<elemType>::seqList(int initSize){
        if (initSize < 0) throw IllegalSize();
        data = new elemType[initSize];
        maxSize = initSize;
        currentLength = 0;
    }

## insert

    template <class elemType>
    void seqList<elemType>::insert(int i, const elemType &x){
        if (i < 0 || i > currentLength) throw OutOfBound();
        if (currentLength == maxSize) doubleSpace();
        for(int j = currentLength; j>i;j--) data[j] = data[j-1];
        data[i] = x;
        ++currentLength;
    }

## remove

    template <class elemType>
    void seqList<elemType>::remove(int i){
        if (i < 0 || i > currentLength) throw OutOfBound();
        ...

## doubleSpace

---

    elemType *tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for(int i = 0; i < currentLength; ++i)
        data[i] = tmp [i];
    delete [] tmp;

## 双联表类的实现

---

### 设计

#### 数据成员

* 头指针、尾指针、currentLength

#### 必须实现线性表的所有操作

* 从线性表抽象类继承

#### 链表的插入、删除操作

* 需将指针移到被操作节点的前一节点
* 特设计move函数实现

### 节点及其组成

#### 包含三个部分

* 数据字段、前趋指针、后继指针
* 数据字段为任何类型(elemType)
* 指针字段存放相应地址值

### 双联表类的定义

    template <class elemType>
    class linkList: public list<elemType>{
        private；
            struct node{
                elemType data;
                node* prev, * next;
                node(const elemType &x, node* p = NULL, node* n = NULL){
                    data = x; next = n; prev = p;
                }
                node():next(NULL),prev(NULL){};
                ~node (){}
            };
            node* head, * tail;
            int currentLength;
            node* move(int i) const;
        public:
            linkList();
            ~linkList(){
                clear(); delete head; delete tail;
            }
            void clear();
            int length()const{
                return currentLength;
            }
            void insert(int i, const elemType &x);
            void remove(int i);
            int search()...
    }

    template <class elemType>
    linkList<elemType>::linkList(){
        head = new node;
        head->next = tail = new node;
        tail->prev = head;
        currentLength = 0;
    }

    template <class elemType>
    linkList<elemType>::clear(){
        node* p = head->next, *q;
        head->next = tail;
        tail->prev = head;
        while(p != tail){
            q = p->next; delete p; p = q;
            currentLength = 0;
        }
    }

    template <class elemType>
    void linkList<elemType>::insert(int i, const elemType &x){
        node* pos, * tmp;
        pos = move(i);
        tmp = new node(x, pos->prev, pos);
        pos->prev->next = tmp;
        pos -> prev = ....
    }

## C++的模板机制

---

* 实现容器与数据类型的无关
  * 在数据储存上
  * 容器：可以持有其他对象或是指向其他任何对象类型的指针。
* 实现算法与数据类型的无关

## 迭代器机制

### 线性查找find()定义

    template <class T>
    T * find(T * first, T * last, const T &value){
        while (first != last && *first != value) ++first;
        return first;
    }
* 怎么解决++

#### 迭代器

    template <class Node>
    class List{
        Node * head;
        class iterator{
            Node * ptr;
            public:
                iterator(Node *p = 0):ptr(p){}
                iterator &operator++(){ptr = ptr->next; return *this;}
                iterator operator++(int){
                    iterator old = *this; ptr = ptr->next;return old;
                }
                Node operator*()const {return *ptr;}
                bool operator==(const iterator &i)const{return ptr == i.ptr;}
                bool operator!=(const iterator &i)const
                {return ptr != i.ptr;}
        };
        iterator begin(){return iterator(head);}
        iterator end(){return iterator();}
        ...
    }
