
#include <stack>      // std::stack
#include <exception>  // 栈和异常
// #include <iostream>       // std::cout

using namespace std;

template<typename T> class CStack
{
public:
    CStack(void);
    ~CStack(void);

    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
}

template<typename T> void CStack<T>::appendTail(const T& element)
{
    stack1.push(element);
}

template<typename T> T CStack<T>::deleteHead()
{
    if(stack2.size() <= 0)
    {
        while(stack1.size() > 0)
        {
            T& data = stack1.top();
            stack2.push(data);
            stack1.pop();
        }
    }

    if(stack2.size() == 0)
        throw new exception("queue is empty");
    
    T head = stack2.top();
    stack2.pop();
    return head;
}

//---------------------------------------
// 相关题目：用两个队列实现一个栈。栈的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在栈尾部插入结点和删除结点的功能。

#pragma once
#include <queue>      // std::queue
#include <exception>  // 队列和异常
// #include <iostream>       // std::cout         

using namespace std;  // std命名空间

template <typename T> class CStack
{
public:
    CStack(void);
    ~CStack(void);
    
    // 在栈的末尾添加一个结点
    void appendTail(const T& node);

    // 在栈的末尾删除一个结点
    T deleteTail();

private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T> CStack<T>::CStack(void)
{
}

template <typename T> CStack<T>::~CStack(void)
{
}

template<typename T> void CStack<T>::appendTail(const T& element)
{
    if(queue1.size() <= 0 && queue2.size() <= 0)
    {
        queue1.push(element);
    }else if(queue1.size() > 0 && queue2.size() <= 0)
    {
        queue1.push(element);
    }else if(queue1.size() <= 0 && queue2.size() > 0)
    {
        queue2.push(element);
    }else if(queue1.size() > 0 && queue2.size() > 0)
    {
        throw new exception("there is a exception in appendTail of stack.\n");
    }
} 

template<typename T> T CStack<T>::deleteTail()
{
    if(queue1.size() == 1 && queue2.size() <= 0)
    {
        T tail = queue1.front();
        queue1.pop();

        return tail;        
    }else if(queue1.size() > 1 && queue2.size() <= 0)
    {
        while(queue1.size() > 1)
        {
            T& data = queue1.front();
            queue1.pop();
            queue2.push(data);
        }

        if(queue2.size() == 0)
            throw new exception("there is a exception in deleteTail of stack.\n");
        
        T tail = queue1.front();
        queue1.pop();

        return tail;
    }else if(queue1.size() <= 0 && queue2.size() == 1)
    {
        T tail = queue2.front();
        queue2.pop();

        return tail;        
    }else if(queue1.size() <= 0 && queue2.size() > 1)
    {
        while(queue2.size() > 1)
        {
            T& data = queue2.front();
            queue2.pop();
            queue1.push(data);
        }

        if(queue1.size() == 0)
            throw new exception("there is a exception in deleteTail of stack.\n");
        
        T tail = queue2.front();
        queue2.pop();

        return tail;
    }

}
