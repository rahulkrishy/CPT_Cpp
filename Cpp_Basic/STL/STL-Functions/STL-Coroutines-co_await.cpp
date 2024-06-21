// Cpp Coroutines
/*
-A coroutine is a generalization of a function that can pause its execution and yield control back to the caller while maintaining its state. 
-Unlike regular functions, which execute to completion before returning control, coroutines can suspend and resume execution at certain points, allowing for more flexible control flow and asynchronous programming.
-C++ 20 introduces three kewords that help pause and resume coroutines.
  1)co_yield : suspends the execution and returns a value
  2)co_return : completes execution and optionally returns a value
  3)co_await : suspends the execution until resumed
-If a function has one of those keywords, it becomes a coroutine. 
-There is no other special syntax for coroutines.
-It's not every function in C++ that can be a coroutine. 
-The functions can't be coroutines: Constexpr functions, constructors, destructors, the main function -Coroutine keywords can't show up in these functions

Building components of Coroutines:
Promise type
Coroutine handle
Awaiter

-C++ 20 doesn't provide actual usable coroutine types like CoroType
-It provides the low level infrastructure to build them (promises, awaitables, coroutine handles....
-Building your own coroutine types is not recommended. It's only reserved for hard core, highly experienced library developers who really know what they're doing
-It is expected that C++23 will provide high level coroutine types built into C++, ready to use just by including some headers
-If you want to use them know, there are third party libraries that can help, like copcoro and some others

add "-fcoroutines" to the task.json file to work on with coroutines.
*/

// Coroutines co_await

#include <iostream>
#include <coroutine>


struct CoroType // own coroutine type build on coroutine infrastructure
{
    struct promise_type { 
        CoroType get_return_object() { return CoroType(this); }    
        std::suspend_always initial_suspend() { return {}; }        
        std::suspend_always final_suspend() noexcept{ return {}; }
      
        void unhandled_exception() noexcept
        {
            std::rethrow_exception(std::current_exception());
        }
        void return_void(){};
       
    };
    CoroType(promise_type* p)
         : m_handle(std::coroutine_handle<promise_type>::from_promise(*p)) {}
    ~CoroType()
     {
         std::cout << "Handle destroyed..." << std::endl;
          m_handle.destroy();
     }
    std::coroutine_handle<promise_type>   m_handle;
};


CoroType do_work() {
    std::cout << "Doing first thing... " << std::endl;
    co_await std::suspend_always{};
    std::cout << "Doing second thing..." << std::endl;
    co_await std::suspend_always{};
    std::cout << "Doing Third thing..." << std::endl;
}

int main(){

    auto task = do_work();

    //Resume
    task.m_handle();
    std::cout << std::boolalpha;
    std::cout << "coro done : " << task.m_handle.done() << std::endl;


    //Resume for second time
    task.m_handle.resume();
    std::cout << "coro done : " << task.m_handle.done() << std::endl;

    //Resume for third time
    task.m_handle.resume();
    std::cout << "coro done : " << task.m_handle.done() << std::endl;


    //Resuming after coroutine has run to completion : BAD!
   // std::cout << "------" << std::endl;
   // task.m_handle.resume();

    std::cout << "Done!" << std::endl;

    return 0;
}
