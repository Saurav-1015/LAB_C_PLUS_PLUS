/*
Write any program that demonstrates the use of multiple catch handling, re-throwing an exception,
and catching all exceptions.
*/

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




