#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include<iostream>

using namespace std;
int seed=200;

struct node
{
    float item;
    node* next;
    
    node(float num, node *nextptr = NULL)
    {
        item = num;
        next = nextptr;
    }
    
};

class singlylinkedlist
{
private:
    
    int size;
    node* tail;
    node* head;
    
public:
    
    singlylinkedlist();
    void singlyaddtohead(float num);
    void singlyaddtotail(float num);
    void singlydeletehead();
    void singlydeletetail();
    void singlydeletenode(int position);
    void singlyaddnode(int position, float num);
    void singlysorthightolow();
    void singlysortlowtohigh();
    void singlyprintlinkedlist();
    int singlyreturnsize();
    int singlysearch(int position);
    int singlyhow_many(float num);
    bool singlycontains(float num);
    singlylinkedlist operator +( singlylinkedlist &name);
    singlylinkedlist operator ++(int);
    singlylinkedlist operator -( singlylinkedlist &name);
    ~singlylinkedlist();
    bool isempty();
    void singlyshuffleList();
    void singlyinterleave(node* head, node* second);
    node* singlysplitAtHalf(node* head);
    void singlyprint7cardhand();
    
    
};

singlylinkedlist::singlylinkedlist()
{
    tail = head = NULL;
    size = 0;
    
}

void singlylinkedlist::singlyaddtohead(float num)
{
    if (size == 0)
        head = tail = new node(num);
    else
    {
        head = new node(num,head);
    }
    size++;
    
}

void singlylinkedlist::singlyaddtotail(float num)
{
    if(size==0)
        tail = head = new node(num);
    else
    {
        tail->next = new node(num);
        tail = tail->next;
    }
    size++;
    
    
}

void singlylinkedlist::singlydeletehead()
{
    if(size==0)
        cout<<"List is empty"<<endl;
    else
    {
        node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void singlylinkedlist::singlydeletetail()
{
    if(size==0)
        cout<<"List is Empty"<<endl;
    else
    {
        node* temp1 = new node(NULL);
        temp1 = head;
        while(temp1->next!=tail)
        {
            temp1 = temp1->next;
        }
             tail = temp1;
        
            size--;
    }
}


void singlylinkedlist::singlydeletenode(int position)
{
    if (position == 0)
    {
        singlydeletehead();
    }
    else if (position == size - 1)
    {
        singlydeletetail();
        
    }
    else
    {
        node *current = head;
        node *previous;
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        current = NULL;
    }
    size--;
}



void singlylinkedlist::singlyaddnode(int position, float num)
{
    if (position == 0)
    {
        singlyaddtohead(num);
    }
    
    else if (position == size-1)
        
    {
        singlyaddtotail(num);
    }
    else
    {
        node *previous;
        node *current = head;
        node *temp = new node(num);
        
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        temp->item = num;
        previous->next = temp;
        temp->next = current;
    }
    size++;
}

void singlylinkedlist::singlysorthightolow()
{
    
    for(int i = size ; i > 1 ; i-- )
        
    {
        
        node *temp, *swap1;
        
        swap1 = head;
        
        for(int j = 0 ; j < size-1 ; j++ )
            
        {
            
            if(swap1->item < swap1->next->item)
                
            {
                
                node *swap2 = swap1->next;
                
                swap1->next = swap2->next;
                
                swap2->next = swap1;
                
                if(swap1 == head)
                    
                {
                    
                    head = swap2;
                    
                    swap1 = swap2;
                    
                }
                
                else
                    
                {
                    
                    swap1 = swap2;
                    
                    temp->next = swap2;
                    
                }
                
            }
            
            temp = swap1;
            
            swap1 = swap1->next;
            
        }
        
    }
    
}

void singlylinkedlist::singlysortlowtohigh()
{
    
    for(int i = size ; i > 1 ; i-- )
        
    {
        
        node *temp, *swap1;
        
        swap1 = head;
        
        for(int j = 0 ; j < size-1 ; j++ )
            
        {
            
            if(swap1->item > swap1->next->item)
                
            {
                
                node *swap2 = swap1->next;
                
                swap1->next = swap2->next;
                
                swap2->next = swap1;
                
                if(swap1 == head)
                    
                {
                    
                    head = swap2;
                    
                    swap1 = swap2;
                    
                }
                
                else
                    
                {
                    
                    swap1 = swap2;
                    
                    temp->next = swap2;
                    
                }
                
            }
            
            temp = swap1;
            
            swap1 = swap1->next;
            
        }
        
    }
    
}

void singlylinkedlist::singlyprintlinkedlist()
{
    if(size==0)
    {
        cout<<"The List is Empty:"<<endl;
        return;
    }
    else
    {
        node* temp;
    temp = head;
    while (temp != NULL)
    {
        cout<< temp->item <<" ";
        temp = temp->next;
    }
    cout<<endl;
    }
}


int singlylinkedlist::singlyreturnsize()
{
    if(size==0)
    {
        cout<<"The List is Empty, total nodes in list are ";
        return size;
    }
    
    return size;
}


int singlylinkedlist::singlysearch(int position)
{
    if (position == 0)
    {
        return head->item;
    }
    
    else if (position == size-1)
        
    {
        return head->item;
    }
    else
    {
        
        node *temp = head;
        
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        return temp->item;
    }
    
}

singlylinkedlist::~singlylinkedlist()
{
    while (size!=0)
    {
        singlydeletehead();
        
    }
}

bool singlylinkedlist::isempty()
{
    if(head==NULL)
    {
        return true;
        
    }
    return false;
    
}

int singlylinkedlist::singlyhow_many(float num)
{
    node *temp = head;
    int count = 0;
    if(temp->item==0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < size-1; i++)
        {
            if(temp->item == num)
                count++;
            temp = temp->next;
        }
        return count;
    }
}


bool singlylinkedlist::singlycontains(float num)
{
    for ( node *temp = head; temp != NULL; temp = temp->next )
        
    {
        if ( temp->item == num )
        {
            return true;
        }
    }
    
    return false;
}

singlylinkedlist singlylinkedlist::operator+(singlylinkedlist &name)
{
    
    singlylinkedlist temporary;
    
    temporary.size = size + name.size;
    tail->next = name.head;
    temporary.head = head;
    temporary.tail = name.tail;
    
    return temporary;
}

singlylinkedlist singlylinkedlist::operator ++(int)
{
    singlylinkedlist temporary;
    
    int num = ((rand() % 100) + 1);
    
    if (size == 0)
        head = tail = new node(num) ;
    else
    {
        node *temp = head;
        
        head = temp;
        
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp = NULL;
        delete temp;
        size++;
    }
    
    return temporary;
}




singlylinkedlist singlylinkedlist::operator -(singlylinkedlist &name)
{
    singlylinkedlist temporary;
    
    if (size == 1)
        head = tail = NULL;
    else
    {
        node *tmp = head;
        
        head = head->next;
        size=1;
        delete tmp;
        tmp = head;
        
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        
        tmp = NULL;
        delete tmp;
    }
    
    size--;
    return temporary;
    
    
}



node* singlylinkedlist::singlysplitAtHalf(node* head)
{
    node* temp =new node(NULL);
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next->next;
        head = head->next;
    }
    
    node* result = head->next;
    head->next = NULL;
    return result;
}

void singlylinkedlist::singlyinterleave(node* head, node* second)
{
    node* tail = NULL;
    while (second != NULL)
    {
        if (tail == NULL)
        {
            tail = second;
        } else
        {
            tail->next = second;
        }
        
        node* next = second->next;
        second->next = head;
        second = next;
        tail = head;
        
        next = head->next;
        head->next = NULL;
        head = next;
    }
}
void singlylinkedlist::singlyshuffleList()
{
    node* half = new node(NULL);
    half = singlysplitAtHalf(head);
    singlyinterleave(head, half);
    head = half;
}

    

void singlylinkedlist::singlyprint7cardhand()
{
    float x;
    for(int i=0;i<7;i++)
        {
            x = tail->item;
            cout<<x<<endl;
            singlydeletetail();
        }
}


struct charnode
{
    char item;
    charnode* next;
    
    charnode(char word, charnode *nextptr = NULL)
    {
        item = word;
        next = nextptr;
    }
    
};

class stringlinkedlist
{
private:
    
    int size;
    charnode* tail;
    charnode* head;
    
public:
    
    stringlinkedlist();
    void stringaddtohead(char word);
    void stringaddtotail(char word);
    void stringdeletehead();
    void stringdeletetail();
    void stringdeletenode(int position);
    void stringaddnode(int position,char word);
    void stringsorthightolow();
    void stringsortlowtohigh();
    void stringprintlinkedlist();
    int stringreturnsize();
    char stringsearch(int position);
    int stringhow_many(char word);
    bool stringcontains(char word);
    stringlinkedlist operator +(const stringlinkedlist &name);
    stringlinkedlist operator ++(int);
    stringlinkedlist operator -( stringlinkedlist &name);
    ~stringlinkedlist();
    bool stringisempty();
    
    
};



stringlinkedlist::stringlinkedlist()
{
    tail = head = NULL;
    size = 0;
    
}

void stringlinkedlist::stringaddtohead(char word)
{
    if (size == 0)
        head = tail = new charnode(word);
    else
    {
        head = new charnode(word,head);
    }
    size++;
    
}

void stringlinkedlist::stringaddtotail(char word)
{
    if(size==0)
    {
        tail = new charnode(word);
        head = tail;
    }
    else
    
    {
        tail->next = new charnode(word);
        tail=tail->next;
    }
    size++;
    
    
}

void stringlinkedlist::stringdeletehead()
{
    if(size==0)
        cout<<"List is empty"<<endl;
    else
    {
        charnode* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void stringlinkedlist::stringdeletetail()
{
    if(size==0)
        cout<<"List is Empty"<<endl;
    else
    {
        charnode* temp1 = head;
        while(temp1->next!=tail)
        {
            temp1 = temp1->next;
        }
        charnode* temp2 = temp1->next;
        delete temp2;
        tail = temp1;
        size--;
    }
}


void stringlinkedlist::stringdeletenode(int position)
{
    if (position == 0)
    {
        stringdeletehead();
    }
    else if (position == size - 1)
    {
        stringdeletetail();
        
    }
    else
    {
        charnode *current = head;
        charnode *previous;
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        current = nullptr;
    }
    size--;
}



void stringlinkedlist::stringaddnode(int position, char word)
{
    if (position == 0)
    {
        stringaddtohead(word);
    }
    
    else if (position == size-1)
        
    {
        stringaddtotail(word);
    }
    else
    {
        charnode *previous;
        charnode *current = head;
        charnode *temp = new charnode(word);
        
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        temp->item = word;
        temp->next = current;
    }
    size++;
}

void stringlinkedlist::stringsorthightolow()
{
    
    for(int i = size ; i > 1 ; i-- )
        
    {
        
        charnode *temp, *swap1;
        
        swap1 = head;
        
        for(int j = 0 ; j < size-1 ; j++ )
            
        {
            
            if(swap1->item < swap1->next->item)
                
            {
                
                charnode *swap2 = swap1->next;
                
                swap1->next = swap2->next;
                
                swap2->next = swap1;
                
                if(swap1 == head)
                    
                {
                    
                    head = swap2;
                    
                    swap1 = swap2;
                    
                }
                
                else
                    
                {
                    
                    swap1 = swap2;
                    
                    temp->next = swap2;
                    
                }
                
            }
            
            temp = swap1;
            
            swap1 = swap1->next;
            
        }
        
    }
    
}

void stringlinkedlist::stringsortlowtohigh()
{
    
    for(int i = size ; i > 1 ; i-- )
        
    {
        
        charnode *temp, *swap1;
        
        swap1 = head;
        
        for(int j = 0 ; j < size-1 ; j++ )
            
        {
            
            if(swap1->item > swap1->next->item)
                
            {
                
                charnode *swap2 = swap1->next;
                
                swap1->next = swap2->next;
                
                swap2->next = swap1;
                
                if(swap1 == head)
                    
                {
                    
                    head = swap2;
                    
                    swap1 = swap2;
                    
                }
                
                else
                    
                {
                    
                    swap1 = swap2;
                    
                    temp->next = swap2;
                    
                }
                
            }
            
            temp = swap1;
            
            swap1 = swap1->next;
            
        }
        
    }
    
}

void stringlinkedlist::stringprintlinkedlist()
{
    
    charnode* temp = new charnode(NULL);
    temp = head;
    while (temp != NULL)
    {
        cout<< temp->item <<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int stringlinkedlist::stringreturnsize()
{
    if(size==0)
    {
        cout<<"The List is Empty, total nodes in list are ";
        return size;
    }
    
    return size;
}


char stringlinkedlist::stringsearch(int position)
{
    if (position == 0)
    {
        return head->item;
    }
    
    else if (position == size-1)
        
    {
        return head->item;
    }
    else
    {
        
        charnode *temp = head;
        
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        return temp->item;
    }
    
}

stringlinkedlist::~stringlinkedlist()
{
    while (size != 0)
    {
        stringdeletenode(size);
    }
    cout<<" the list is empty"<<endl;
}

bool stringlinkedlist::stringisempty()
{
    if(head==NULL)
    {
        return true;
        
    }
    return false;
    
}

int stringlinkedlist::stringhow_many(char word)
{
    charnode *temp = head;
    int count = 0;
    if(temp == NULL)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < size-1; i++)
        {
            if(temp->item == word)
                count++;
            temp = temp->next;
        }
        return count;
    }
}


bool stringlinkedlist::stringcontains(char word)
{
    for ( charnode *temp = head; temp != NULL; temp = temp->next )
        
    {
        if ( temp->item == word)
        {
            return true;
        }
    }
    
    return false;
}

stringlinkedlist stringlinkedlist::operator+(const stringlinkedlist &name)
{
    
    stringlinkedlist temporary;
    
    temporary.size = size + name.size;
    tail->next = name.head;
    temporary.head = head;
    temporary.tail = name.tail;
    
    return temporary;
}

stringlinkedlist stringlinkedlist::operator ++(int)
{
    stringlinkedlist temporary;
    string x;
    char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i=0;i<6;i++)
    {
        x=a[rand()%26+1];
    }
    
    if (size == 0)
        head = tail = new charnode(NULL) ;
    else
    {
        charnode *temp = head;
        
        head = temp;
        
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp = NULL;
        delete temp;
        size++;
    }
    
    return temporary;
}




stringlinkedlist stringlinkedlist::operator -(stringlinkedlist &name)
{
    stringlinkedlist temporary;
    
    if (size == 1)
        head = tail = NULL;
    else
    {
        charnode *tmp = head;
        
        head = head->next;
        size=1;
        delete tmp;
        tmp = head;
        
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        
        tmp = NULL;
        delete tmp;
    }
    
    size--;
    return temporary;
}
    
    
    class stack
    {
    private:
        singlylinkedlist container;
        int top;
        int size;
    public:
        stack();
        void stackpush(float num);
        void stackpop();
        void stackprint();
        void stacksortvalue();
        void stacksortcolor();
        void stackprintrandomhand();
        bool stackcontains(float num);
        int stackreturnsize();
        void stackclear();
        int stackhowmany_stack(float num);
        int stacksearch(int position);
        void stackprint7cardhand();
        stack operator +( stack &name);
        int operator ++(int);
        stack operator -( stack &name);
        void stackshuffle();
        ~stack();
        
    };
     stack::~stack()
{
        {
           container.singlydeletehead();
        }
    
}
    stack::stack()
    {
        
        top = 0;
        size = 0;
        
    }
    
    void stack::stackpush(float num)
    {
        container.singlyaddtotail(num);
        top = num;
        size++;
    }
    void stack::stackpop()
    {
        if(size==0)
        {
            cout<<"The Stack is Empty"<<endl;
        }
        else
        {
            container.singlydeletetail();
            int position = container.singlyreturnsize()-1;
            top = container.singlysearch(position);
            size--;
            
        }
    }
    
    void stack::stackprint()
    {
        container.singlyprintlinkedlist();
        
    }
    
    void stack::stacksortvalue()
    {
        container.singlyprintlinkedlist();
    }
    
    void stack::stacksortcolor()
    {
        container.singlysortlowtohigh();
    }
    
    bool stack::stackcontains(float num)
    {
        return container.singlycontains(num);
    }
    
    int stack::stackreturnsize()
    {
        return container.singlyreturnsize();
    }
    
    void stack::stackclear()
    {
        container.~singlylinkedlist();
    }
    
    int stack::stackhowmany_stack(float num)
    {
        return container.singlyhow_many(num);
        
    }
    
    int stack::stacksearch(int position)

    {
        return container.singlysearch(position);
    }
    
    void stack::stackprint7cardhand()
    {
    
        {
        container.singlyprint7cardhand();
            
        }
    }
    
    void stack::stackshuffle()
    {
        container.singlyshuffleList();
    }
    
    
    stack stack::operator+( stack &name)
    {
        singlylinkedlist list1 = name.container;
        singlylinkedlist operator +(singlylinkedlist list1);
        name.container = list1;
        return name;
    }
    
    int stack::operator ++(int)
    {
        srand((unsigned)time(0));
        float random = rand()%6+1;
        container.singlyaddtotail(random);
        return size++;
        
    }
    
    
    
    
    stack stack::operator -( stack &name)
    {
        singlylinkedlist temporary = name.container;
        
        singlylinkedlist operator -(singlylinkedlist temporary);
        return name;
        
        
    }
    
class queue
{
private:
    stringlinkedlist container2;
    charnode *front= NULL;
    charnode *rear = NULL;
    charnode *temp1,*temp2;
    int size;
    
public:
    
    queue();
    void enqueue(char word);
    void dequeue();
    void queueprint();
    void queuesortalphabetically();
    bool queuecontains(char word);
    int queuereturnsize();
    ~queue();
    int queuehowmany_queue(char word);
    void queuelistsearch(fstream&file, char word);
    queue operator +( queue &name);
    int operator ++(int);
    void operator -( queue &name);
};
    
struct circularnode
{
    int item;
    circularnode* next;
    
    circularnode(int num, circularnode *nextptr = NULL)
    {
        item = num;
        next = nextptr;
    }
    
};

class circularlinkedlist
{
private:
    
    int size;
    circularnode* tail;
    circularnode* head;
    
public:
    
    circularlinkedlist();
    void circularaddtohead(int num);
    void circularaddtotail(int num);
    void circulardeletehead();
    void circulardeletetail();
    void circulardeletenode(int position);
    void circularaddnode(int position, int num);
    void circularsorthightolow();
    void circularsortlowtohigh();
    void circularprintlinkedlist();
    int circularreturnsize();
    int circularsearch(int position);
    int circularhow_many(int num);
    bool circularcontains(int num);
    circularlinkedlist operator +(circularlinkedlist &name);
    circularlinkedlist operator ++(int);
    circularlinkedlist operator -(const circularlinkedlist &name);
    ~circularlinkedlist();
    bool circularisempty();
    
    
};

circularlinkedlist::circularlinkedlist()
{
    tail = head = NULL;
    size = 0;
    
}

void circularlinkedlist::circularaddtohead(int num)
{
    circularnode* tmp = new circularnode(num);
    if(head == NULL)
    {
        tmp->next = head;
        head = tmp;
        size++;
    }
    else
    {
        tmp->next = head;
        
        circularnode* last = tail;
        last->next = tmp;
        
        head = tmp;
        size++;
    }
    
}


void circularlinkedlist::circularaddtotail(int num)
{
    circularnode* temp = new circularnode(num);
    
    if(head == NULL)
    {
        
        head = temp;
        temp->next = NULL;
    }
    else
    {
        circularnode* last = new circularnode(NULL);
        last = tail;
            last->next = temp;
        temp->next = head;
    }
    size++;
}


void circularlinkedlist::circulardeletehead()
{
    if(size==0)
        cout<<"List is empty"<<endl;
    else
    {
        circularnode* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void circularlinkedlist::circulardeletetail()
{
    if(size==0)
        cout<<"List is Empty"<<endl;
    else
    {
        circularnode* temp1 = head;
        while(temp1->next!=tail)
        {
            temp1 = temp1->next;
        }
        circularnode* temp2 = temp1->next;
        
        tail = temp1;
        delete temp2;
        tail->next=head;
        size--;
    }
}



void circularlinkedlist::circulardeletenode(int position)
{
    if (position == 0)
    {
        circulardeletehead();
    }
    else if (position == size - 1)
    {
        circulardeletetail();
        
    }
    else
    {
        circularnode *current = head;
        circularnode *previous;
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        current = nullptr;
    }
    size--;
}




void circularlinkedlist::circularaddnode(int position, int num)
{
    if (position < 1 || position > size)
        cout <<"The list is empty"<<endl;
    else if (size == 1 || position == 1)
        circularaddtohead(num);
    else
    {
        
        circularnode *tmp = tail->next;
        
        while (size!= size- 1)
            tmp = tmp->next;
        tmp->item = num;
        
        tmp = tmp->next->next;
        while (tmp->next != tail->next)
        {
            tmp = tmp->next;
        }
        
        size++;
        
        tmp = NULL;
        delete tmp;
    }
}


void circularlinkedlist::circularsorthightolow()
{
    for(int i = size ; i > 1 ; i-- )
        
    {
        
        circularnode *temp, *swap1;
        
        swap1 = head;
        
        for(int j = 0 ; j < size-1 ; j++ )
            
        {
            
            if(swap1->item < swap1->next->item)
                
            {
                
                circularnode *swap2 = swap1->next;
                
                swap1->next = swap2->next;
                
                swap2->next = swap1;
                
                if(swap1 == head)
                    
                {
                    
                    head = swap2;
                    
                    swap1 = swap2;
                    
                }
                
                else
                    
                {
                    
                    swap1 = swap2;
                    
                    temp->next = swap2;
                    
                }
                
            }
            
            temp = swap1;
            
            swap1 = swap1->next;
            
        }
        
    }
    
}

void circularlinkedlist::circularsortlowtohigh()
{
    
    for(int i = size ; i > 1 ; i-- )
        
    {
        
        circularnode *temp, *swap1;
        
        swap1 = head;
        
        for(int j = 0 ; j < size-1 ; j++ )
            
        {
            
            if(swap1->item > swap1->next->item)
                
            {
                
                circularnode *swap2 = swap1->next;
                
                swap1->next = swap2->next;
                
                swap2->next = swap1;
                
                if(swap1 == head)
                    
                {
                    
                    head = swap2;
                    
                    swap1 = swap2;
                    
                }
                
                else
                    
                {
                    
                    swap1 = swap2;
                    
                    temp->next = swap2;
                    
                }
                
            }
            
            temp = swap1;
            
            swap1 = swap1->next;
            
        }
        
    }
}

void circularlinkedlist::circularprintlinkedlist()
{
    
    circularnode* temp;
    temp = head;
    while (temp != NULL)
    {
        cout<< temp->item <<" ";
        temp = temp->next;
    }
    
}


int circularlinkedlist::circularreturnsize()
{
    if(size==0)
    {
        cout<<"The List is Empty, total nodes in list are ";
        return size;
    }
    
    return size;
}


int circularlinkedlist::circularsearch(int position)
{
    circularnode *temp = head;
    while(temp != NULL && temp->item != position)
    {
        temp = temp->next;
    }
    int x;
    x = temp->item;
    return x;
    
}



circularlinkedlist::~circularlinkedlist()
{
    while (size != 0)
    {
        circulardeletenode(size);
    }
    cout<<" the list is empty"<<endl;
}

bool circularlinkedlist::circularisempty()
{
    if(head==NULL)
    {
        return true;
        
    }
    return false;
    
}

int circularlinkedlist::circularhow_many(int num)
{
    circularnode *temp = head;
    int count = 0;
    if(temp->item==0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < size-1; i++)
        {
            if(temp->item == num)
                count++;
            temp = temp->next;
        }
        return count;
    }
}

bool circularlinkedlist::circularcontains(int num)
{
    for ( circularnode *temp = head; temp != NULL; temp = temp->next )
        
    {
        if ( temp->item == num )
        {
            return true;
        }
    }
    
    return false;
    
}

circularlinkedlist circularlinkedlist::operator+(circularlinkedlist &name)
{
    
    circularlinkedlist temporary;
    
    temporary.size = size + name.size;
    tail->next = name.head;
    temporary.head = head;
    temporary.tail = name.tail;
    tail->next = head;
    
    return temporary;
}

circularlinkedlist circularlinkedlist::operator ++(int)
{
    circularlinkedlist temporary;
    
    int num = ((rand() % 100) + 1);
    
    if (size == 0)
        head = tail = new circularnode(num) ;
    else
    {
        circularnode *temp = head;
        
        head = temp;
        
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = head;
        delete temp;
        size++;
    }
    
    return temporary;
}




circularlinkedlist circularlinkedlist::operator -(const circularlinkedlist &name)
{
    circularlinkedlist temporary;
    
    if (size == 1)
        head = tail = NULL;
    else
    {
        circularnode *tmp = head;
        
        head = head->next;
        size=1;
        delete tmp;
        tmp = head;
        
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        
        tmp->next = head;
        delete tmp;
    }
    
    size--;
    return temporary;
    
    
}






queue::queue()

{
    front = rear = NULL;
    temp1 = temp2 = NULL;
    size = 0;

}


void queue::enqueue(char word)
{
    
    container2.stringaddtotail(word);
    int position = container2.stringreturnsize()-1;
    container2.stringsearch(position);
    size++;
 
}

void queue::dequeue()
{
    
    container2.stringdeletehead();
    int position = container2.stringreturnsize()-1;
    rear->item = container2.stringsearch(position);
    size--;
}

void queue::queueprint()
{
    container2.stringprintlinkedlist();
}

void queue::queuesortalphabetically()
{
    container2.stringsortlowtohigh();
}

bool queue::queuecontains(char word)
{
    return container2.stringcontains(word);
}

int queue::queuereturnsize()
{
    return container2.stringreturnsize();
}

int queue::queuehowmany_queue(char word)
{
    
    return container2.stringhow_many(word);
}

void queue::queuelistsearch(fstream&file,char word)
{
    int count = 0;
    charnode *temp = front;
    
    for (int i = 1; i <= size; i++)
    {
        if (temp->item == word)
            count++;
    }
    
    if (count == 0)
        cout << "Word was not found in file.";
    else if (count == 1)
        cout << "Word was found 1 time.";
    else
        cout << "Word was found " << count << " times.";
    
    temp = NULL;
    delete temp;
}


queue::~queue()
{
    while(front!=NULL)
    {
        charnode *temp3 = front;
        front = front->next;
        delete temp3;
    }
    rear = NULL;
}

queue queue::operator+(queue &name)
{
    queue newqueue = name;
    
    stringlinkedlist temporary = newqueue.container2;
    
    temporary.operator+(temporary);
    
    return newqueue ;
}

int queue::operator ++(int)
{
    queue temp;
    
    
    container2.stringaddtotail(NULL);
    size++;
    return size;
    
}




void queue::operator -(queue &name)
{
    stringlinkedlist list1 = name.container2;
    stringlinkedlist operator -(stringlinkedlist list1);
}

struct doublenode
{
    int item;
    doublenode* next;
    doublenode* previous;
    
    doublenode(int num, doublenode *nextptr = NULL, doublenode *previousptr = NULL)
    {
        item = num;
        next = nextptr;
        previous = previousptr;
        
    }
    
};

class doublelinkedlist
{
private:
    
    int size;
    doublenode* tail;
    doublenode* head;
    
public:
    
    doublelinkedlist();
    void doubleaddtohead(int num);
    void doubleaddtotail(int num);
    void doubledeletehead();
    void doubledeletetail();
    void doubledeletenode(int position);
    void doubleaddnode(int position, int num);
    void doublesorthightolow();
    void doublesortlowtohigh();
    void doubleprintlinkedlist();
    int doublereturnsize();
    int doublesearch(int position);
    int doublehow_many(int num);
    bool doublecontains(int num);
    doublelinkedlist operator +(const doublelinkedlist &name);
    doublelinkedlist operator ++(int);
    doublelinkedlist operator -( doublelinkedlist &name);
    ~doublelinkedlist();
    bool doubleisempty();
    
    
};




doublelinkedlist::doublelinkedlist()
{
    tail = head = NULL;
    size = 0;
    
}


void doublelinkedlist::doubleaddtohead(int num)
{
    doublenode *temp = new doublenode(num);
    if(head==NULL)
    {
        head = tail = temp;
    }
    else
    {
        head->previous = temp;
        temp->next = head;
        head = temp;
    }
    size++;
}

void doublelinkedlist::doubleaddtotail(int num)
{
    doublenode *temp = new doublenode(num);
    if(tail == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->previous = temp;
        temp->previous = tail;
        tail = temp;
    }
    size++;
}

void doublelinkedlist::doubledeletehead()
{
    if(doubleisempty())
        cout<<"List is empty"<<endl;
    else
    {
        doublenode* temp = head;
        if(head == tail)
        {
            tail = NULL;
            head = NULL;
        }
        temp = temp->next;
        head = temp;
        delete temp;
        size--;
    }
}

void doublelinkedlist::doubledeletetail()
{
    if(doubleisempty())
        cout<<"List is Empty"<<endl;
    else
    {
        doublenode* temp = tail;
        if(head==tail)
        {
            head=NULL;
            tail=NULL;
        }
        tail->next = NULL;
        tail= tail->previous;
        delete temp;
        size--;
    }
}


void doublelinkedlist::doubledeletenode(int position)
{
    
    doublenode* tmp2 = head;
    
    for(int i=1;i<position-1;i++)
    {
        tmp2 = tmp2->next;
    }
    tmp2->next = tmp2->next->next;
    tmp2 = tmp2->next->next;
    tmp2 = NULL;
    tmp2->previous = NULL;
    tmp2->next = NULL;
    
    
    
    
}



void doublelinkedlist::doubleaddnode(int position, int num)
{
    if(position==0)
    {
        doubleaddtohead(num);
    }
    doublenode* temp1 =new doublenode(num);
    temp1->item = num;
    temp1->next = NULL;
    doublenode* tmp2 = head;
    
    for(int i=1;i<position-1;i++)
    {
        tmp2 = tmp2->next;
    }
    temp1->next=tmp2->next;
    tmp2->next = temp1;
    
    
}

void doublelinkedlist::doublesorthightolow()
{
    
    for(int i = size ; i > 1 ; i-- )
        
    {
        
        doublenode *temp, *swap1;
        
        swap1 = head;
        
        for(int j = 0 ; j < size-1 ; j++ )
            
        {
            
            if(swap1->item < swap1->next->item)
                
            {
                
                doublenode *swap2 = swap1->next;
                
                swap1->next = swap2->next;
                
                swap2->next = swap1;
                
                if(swap1 == head)
                    
                {
                    
                    head = swap2;
                    
                    swap1 = swap2;
                    
                }
                
                else
                    
                {
                    
                    swap1 = swap2;
                    
                    temp->next = swap2;
                    
                }
                
            }
            
            temp = swap1;
            
            swap1 = swap1->next;
            
        }
        
    }
    
}

void doublelinkedlist::doublesortlowtohigh()
{
    for(int i = size ; i > 1 ; i-- )
        
    {
        
        doublenode *temp, *swap1;
        
        swap1 = head;
        
        for(int j = 0 ; j < size-1 ; j++ )
            
        {
            
            if(swap1->item > swap1->next->item)
                
            {
                
                doublenode *swap2 = swap1->next;
                
                swap1->next = swap2->next;
                
                swap2->next = swap1;
                
                if(swap1 == head)
                    
                {
                    
                    head = swap2;
                    
                    swap1 = swap2;
                    
                }
                
                else
                    
                {
                    
                    swap1 = swap2;
                    
                    temp->next = swap2;
                    
                }
                
            }
            
            temp = swap1;
            
            swap1 = swap1->next;
            
        }
        
    }
}

void doublelinkedlist::doubleprintlinkedlist()
{
    if(size==0)
    {
        cout<<"The Doublelinkedlist is Empty:"<<endl;
    }
    doublenode* temp;
    temp = head;
    while (temp != NULL)
    {
        cout<< temp->item <<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int doublelinkedlist::doublereturnsize()
{
    if(size==0)
    {
        cout<<"The List is Empty, total nodes in list are ";
        return size;
    }
    
    return size;
}


int doublelinkedlist::doublesearch(int position)
{
    
    if (position == 0)
    {
        return head->item;
    }
    
    else if (position == size-1)
        
    {
        return head->item;
    }
    else
    {
        
        doublenode *temp = head;
        
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        return temp->item;
    }
    
}


doublelinkedlist::~doublelinkedlist()
{
    while (size != 0)
    {
        doubledeletehead();
    }
}

bool doublelinkedlist::doubleisempty()
{
    if(head==NULL)
    {
        return true;
        
    }
    return false;
    
}

int doublelinkedlist::doublehow_many(int num)
{
    doublenode *temp = head;
    int count = 0;
    if(temp->item==0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < size-1; i++)
        {
            if(temp->item == num)
                count++;
            temp = temp->next;
        }
        return count;
    }
}

bool doublelinkedlist::doublecontains(int num)
{
    doublenode* temp = head;
    if (head->next!=NULL)
    {
        while (temp)
        {
            if (temp->item == num)
            {
                return true;
            }
            temp = temp->next;
        }
        
    }
    return false;
}



doublelinkedlist doublelinkedlist::operator+(const doublelinkedlist &name)
{
    doublelinkedlist temp;
    temp.head = head;
    temp.tail = tail;
    temp.tail->next = name.head;
    name.head->previous = temp.tail;
    temp.tail = name.tail;
    temp.size = size;
    temp.size = temp.size + name.size;
    return temp;
}




doublelinkedlist doublelinkedlist::operator ++(int)
{
    doublelinkedlist temporary;
    
    int num = ((rand() % 100) + 1);
    
    if (size == 0)
        head = tail = new doublenode(num) ;
    else
    {
        doublenode *temp = head;
        
        head = temp;
        
        while (temp->next != NULL)
        {
            temp = temp->next;
            
        }
        
        doublenode * temp2 = new doublenode(num);
        temp->next = temp2;
        temp2->previous = temp->next;
        delete temp;
        size++;
    }
    
    return temporary;
    
    
}
doublelinkedlist doublelinkedlist::operator -( doublelinkedlist &name)
{
    doublelinkedlist tmpList;
    
    if (size == 1)
        head = tail = nullptr;
    else
    {
        doublenode *tmp = head;
        
        if (size == 1)
            head = tail = nullptr;
        else
        {
            head = head->next;
            head->previous = NULL;
            size = 1;
            delete tmp;
            tmp = head;
            
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
                size--;
            }
            
            tmp = nullptr;
        }
        
        delete tmp;
        size--;
    }
    
    return tmpList;
}





    
int main()
    
    {
        
        // fill each list with 100 random numbers, sort from high to low and low to high
        
        //fill stack with 52 values representing cards in a deck, then print- 7 card hand
        
        // for a queue read in a paragraph of at least  100 words from a file, sort it by alphabetical order
        
        //after each print, empty container and print show its empty
        
        
        srand((unsigned)time(0));
        
        singlylinkedlist list1;
        float random;
        for (int i = 0; i <100; i++)
        {
            random = rand()%99+1;
            list1.singlyaddtohead(random);
            
        }
        //Singly linkedlist stores 100 numbers, sorts, and prints. Then deletes and prints.
        
        cout<<"singly Linkedlist low to high"<<endl;
        list1.singlysortlowtohigh();
        list1.singlyprintlinkedlist();
        cout<<"Singly linkedlist high to low"<<endl;
        list1.singlysorthightolow();
        list1.singlyprintlinkedlist();
        list1.~singlylinkedlist();
        list1.singlyprintlinkedlist();
       
       
        //Double linkedlist stores 100 numbers, sorts, and prints. Then deletes and prints.
        
        doublelinkedlist list2;

        float random2;
        for (int j = 0; j <100; j++)
        {
            random2 = rand()%99+1;
            list2.doubleaddtohead(random2);

        }
        cout<<"Double Linkedlist low to high"<<endl;
        list2.doublesortlowtohigh();
        list2.doubleprintlinkedlist();
        cout<<"Double LinkedList high to low"<<endl;
        list2.doublesorthightolow();
        list2.doubleprintlinkedlist();
        list2.~doublelinkedlist();
        list2.doubleprintlinkedlist();

        //deck of cards has 52
        //13 spades
        //13 hearts
        //13 clubs
        //13 diamonds
        //    4.01 - 4.13 = spades 1 - king
        //    3.01 - 3.13 = hearts 1 - king
        //    2.01 - 2.13 = Clubs 1 - king
        //    1.01 - 1.13 = diamonds 1- king
        //    stack is filled in order from lowest number to greatest
        //     the sorting function in stack class sorts by suit
        
        stack deck;
        float num1=1;
        float num2=2;
        float num3=3;
        float num4=4;
       
// The for loops in the stack are to fill the stack in order by number
// Loop to read in diamonds fist in order
       
        for(int n = 0;n<13;n++)
        {
            num1=num1+0.01;
            deck.stackpush(num1);
            num2=num2+0.01;
            deck.stackpush(num2);
            num3=num3+0.01;
            deck.stackpush(num3);
            num4=num4+0.01;
            deck.stackpush(num4);
            
        }
        
        // Prints the deck, shuffles it and prints hand
        cout<<"Deck of Cards in which every value has an assigned card"<<endl;
        deck.stackprint();
        deck.stackshuffle();
        cout<<"Shuffled Deck hand drawn"<<endl;
        deck.stackprint7cardhand();
        cout<<endl;
        deck.~stack();//deletes and prints list is deleted
        cout<<"Stack has been cleared and ";
        deck.stackprint();//confirms list is deleted
        
        // Circular LinkedList
        
        float random4=0;
        circularlinkedlist list11;
        for (int i = 0; i <100; i++)
        {
            random4 = rand()%99+1;
            list11.circularaddtotail(random4);
            
        }
        //Singly linkedlist stores 100 numbers, sorts, and prints. Then deletes and prints.
        
        cout<<"singly Linkedlist low to high"<<endl;
        list11.circularsortlowtohigh();
        list11.circularprintlinkedlist();
        cout<<"Singly linkedlist high to low"<<endl;
        list11.circularsorthightolow();
        list11.circularprintlinkedlist();
        list11.~circularlinkedlist();
        list11.circularprintlinkedlist();



        // Queue linked list reads in file, sorts strings alphabetically and then prints. Then deletes.
        
        queue paragraph;
        
      
        //supposed to read from file and store into array. The array is then passed into the queue
        
        
        
        
        
        char letters[1000];
        char letter;
        fstream song("song.txt",ios::in);
       
        
        int i=0;
        int size;
        
        song.open("song.txt",ios::in);
       
        if (! song)
        {
            cout << "File not found" << endl;
            return 0;
            
        }
        while (!song.eof())
        {
            song>>letters[i];
            letter = letters[i];
            paragraph.enqueue(letter);
            i++;
        }
        
     
        
        
        

        
        
        
        
        //xcode could not find other files, I decide to include the lyrics of a verse in bohemian rhapsody by queen because it is really catchy
    
char
    array[398]={'m','a','m','a','j','u','s','t','k','i','l','l','e','d','a','m','a','n','P','u','t','a','g','u','n','a','g','a','i','n','s','t','h','i','s','h','e','a','d','P','u','l','l','e','d','m','y','t','r','i','g','g','e','r','n','o','w','h','e','s','d','e','a','d','a','m','a','l','i','f','e','h','a','d','j','u','s','t','b','e','g','u','n','B','u','t','n','o','w','I','v','e','g','o','n','e','a','n','d','t','h','r','o','w','n','i','t','a','l','l','a','w','a','y','M','a','m','a','o','h','o','h','D','i','d','n','t','m','e','a','n','t','o','m','a','k','e','y','o','u','c','r','y','I','f','I','m','n','o','t','b','a','c','k','a','g','a','i','n','t','h','i','s','t','i','m','e','t','o','m','o','r','r','o','w','C','a','r','r','y','o','n','c','a','r','r','y','o','n','a','s','i','f','n','o','t','h','i','n','g','r','e','a','l','l','y','m','a','t','t','e','r','s','t','o','o','l','a','t','e','m','y','t','i','m','e','h','a','s','c','o','m','e','S','e','n','d','s','s','h','i','v','e','r','s','d','o','w','n','m','y','s','p','i','n','e','B','o','d','y','s','e','a','c','h','i','n','g','a','l','l','t','h','e','t','i','m','e','G','o','o','d','b','y','e','v','e','r','y','b','o','d','y','I','v','e','g','o','t','t','o','g','o','G','o','t','t','a','l','e','a','v','e','y','o','u','a','l','l','b','e','h','i','n','d','a','n','d','f','a','c','e','t','h','e','t','r','u','t','h','M','a','m','a','o','h','o','h','I','d','o','n','t','w','a','n','t','t','o','d','i','e','S','o','m','e','t','i','m','e','s','w','i','s','h','I','n','e','v','e','r','b','e','e','n','b','o','r','n','a','t','a','l','l'};

        for(int y= 0;y<395;y++)
        {
            paragraph.enqueue(array[y]);
        }


                cout<<"Queue";
                paragraph.queueprint();

                cout<<"Sorted Queue"<<endl;
                paragraph.queuesortalphabetically();
                paragraph.queueprint();
                paragraph.~queue();
};



