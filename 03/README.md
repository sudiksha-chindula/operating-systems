# Assignment 03

This Assignment included programming questions in C on segmentation, signal handlers and semaphores as part of the unit 'Memory Management.'

## Problems

1.  Write a program to simulate Segmentation. Compute the physical address 
    Take as input:
    Segment number
    Base address
    Segment limit

2. Write a C program that handles floating-point exceptions, such as division by zero, using signal handling.
* Implement a signal handler function that catches SIGFPE (Floating-Point Exception) and displays an appropriate error message.
* Use the signal() function to register the handler.
* Prompt the user to input a numerator and a denominator.
* Perform the division operation and display the result.
If a division by zero occurs, the program should invoke the signal handler before terminating.
Note: Use signal(SIGFPE, handler_function) to catch floating-point exceptions.

3. Write a C program using pthreads and semaphores to synchronize two threads, ensuring only one enters the critical section at a time. Use sem_wait() and sem_post() for semaphore control.

## Author

[@sudiksha-chindula](https://github.com/sudiksha-chindula)