/*
Write a class template for queue class. Assume the programmer using the queue won't make mistakes, 
like exceeding the capacity of the queue or trying to remove an item when the queue is empty. 
Define several queues of different data types and insert and remove data from them.
*/

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
        std::cout<< arr[current_index];
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
    
    // bool dashboard = false;
    
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
