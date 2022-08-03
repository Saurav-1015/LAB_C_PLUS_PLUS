/*
Modify the stack class given in the previous lab to add the exception when a user tries to add an
item while the stack is full and when the user tries to pop the item while the stack is empty.
Throw exceptions in both of the cases and handle these exceptions.
*/

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
