## lab 9 

### 1. Create a function called sum() that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a program that applies this function to data of various types.

```c++
#include <iostream>

template <class T>
T sum() 
{
    T temp_sum =0 ;
    T arr[10] ={ 1,2,3,4,5,6,7,8,9,10 } ;
    for ( size_t i = 0 ; i< 10 ; i++ )
    {
        temp_sum += arr[i] ;
    }

    return temp_sum; 
}

int main()
{

    std::cout<< "The sum of all the element of array is: "<< sum<int>() << std:: endl;

    return 0;
}
```
### 2.Write a class template for queue class. Assume the programmer using the queue won't make mistakes, like exceeding the capacity of the queue or trying to remove an item when the queue is empty. Define several queues of different data types and insert and remove data from them.

```c++
#include <iostream>

template <class T> 
class Queue
{
    private: 
    T arr[10];
    int current_index;

    public:
    Queue () 
    {
        current_index =-1;
        for (size_t i = 0; i < 10; i++)
            arr[i] = 0;
    }   

    void insert() 
    {
        std::cout<< "Add in stack:  "<< std::endl;
        std::cin>> arr[++current_index] ;
 
    }
    
    void remove() 
    {
        arr[current_index--] = 0 ;
        if( arr[0] == 0  ) { std::cout<< "Stack is empty"; }
    }

    void display() 
    {
        if ( arr[0] != 0 ) 
        {
            for (size_t i = 0; i <= current_index ; i++)
                std::cout<< arr[i] << " ";
        }else
        {
            std::cout<<"The queue is empty\n" << std::endl;
        }
        
    }
};

int main()
{
    Queue<int> q1; 
    int choice;
    
    while (true ) 
    {
        std::cout<< "\n------------------Dashboard--------------------\n"<< std::endl;
        std::cout<<"\t1. Insert in queue\n\t2. Remove from queue\n\t3. Display data\n\t4. Quit\n";
        std::cout<< "\n-----------------------------------------------\n";
        std::cout<< "Your choice: ";
        std::cin>>choice;
        
        switch (choice)
        {
        case 1:
            q1.insert();
            break;

        case 2: 
            q1.remove();
            break;                  

        case 3: 
            q1.display(); 
            break;

        case 4: 
            exit(0);

        default:
            std::cout<< "Please enter valid choice:\n ";
            break;

        }
    }

    return 0;
}
```
### 3. Modify the stack class given in the previous lab to add the exception when a user tries to add an item while the stack is full and when the user tries to add the item while the stack is empty. Throw exceptions in both of the cases and handle these exceptions.

```c++
#include <iostream>

template <class T>
class Queue
{
private:
    int current_index ;
    T arr[10];

public:
    Queue()
    {
        current_index = -1;
        for (size_t i = 0; i < 10; i++)
            arr[i] = 0;
    }

    void insert();
    void remove();
    void display();
};

template <class T>
void Queue<T>::insert()
{
        try
        {
            if ( arr[9] != 0)
                throw arr;
            std::cout << "Add in stack:  " << std::endl;
            std::cin >> arr[++current_index];
        }
        catch (T *arr)
        {
            std::cout << "Stack is full:" << std::endl;
        }
}

template <class T>
void Queue<T>::remove()
{
        try
        {
            if (arr[0] == 0)
                throw arr;

            arr[current_index--] = 0;
            std::cout << "Removed";
        }

        catch (T *arr)
        {
            std::cout << "Stack is empty";
        }
}

template <class T>
void Queue<T>::display()
{
           try
        {
            if (arr[0] != 0)
            {
                for (size_t i = 0; i <= current_index; i++)
                    std::cout << arr[i] << " ";
            }
            else
                throw arr;
        }
        catch (T *arr)
        {
            std::cout << "Stack is empty";
        }
}

int main()
{
    Queue<int> q1;
    int choice;

    while (true)
    {
        std::cout << "\n------------------Dashboard--------------------\n"
                  << std::endl;
        std::cout << "\t1. Insert in queue\n\t2. Remove from queue\n\t3. Display data\n\t4. Quit\n";
        std::cout << "\n-----------------------------------------------\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            q1.insert();
            break;

        case 2:
            q1.remove();
            break;

        case 3:
            q1.display();
            break;

        case 4:
            exit(0);

        default:
            std::cout << "Please enter valid choice:\n ";
            break;
        }
    }

    return 0;
}

```
### 4. Write any program that demonstrates the use of multiple catch handling, re-throwing an exception, and catching all exceptions.

```c++
#include <iostream>
#define MAX  2 

class Stack 
{
    private:
    int arr[MAX];
    int top;
    
    public:
    class Full{} ;
    class Empty{} ;
    class status{};

    Stack() { top = -1;}
    void push(int x )
    {
        try 
        {
            if( top == MAX -1 )
                throw Full();

            arr[++top] = x ;
            std::cout<<"\nPushed on stack success\n";
        }
        catch(Stack::Full)
        {
            std::cout<<"\nThe stack is Full\n";
            throw status();
        }
        
    }

    int pop()
    {
        if( top = -1 )
            throw Empty();
            
        return arr[top--];
    }

};

int main()
{
    Stack s;
    try
    {
        s.push(10);
        s.push(12);
        s.push(2); // will throw an error

        s.pop();
        s.pop();
        s.pop() ; // will throw an error
    }
    catch(Stack::Full)
    {
        std::cout<<"\nThe stack is Full\n"<< std::endl;
    }
    catch (Stack::status)
    {
        std::cout<<"\nCould not push on the stack\n"<< std::endl;
    }
    
    catch (Stack::Empty)
    {
        std::cout<<"\nThe stack is empty"<< std::endl;
    }

    
    return 0;
}
```
