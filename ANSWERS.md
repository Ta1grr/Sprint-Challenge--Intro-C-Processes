**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
 - Running - waiting for the cpu to process it
 - Interruptible Sleep - waiting for an event to complete
 - Uninterruptible Sleep - process that cannot be killed or interrupted with a signal
 - Zombie - terminated processes that are waiting to have their status collected
 - Stopped - a process that has been suspended or stop

**2. What is a zombie process?**
 - A zombie process is where the parent fork a seperate process called a child, and it still lingers after executing its task.


**3. How does a zombie process get created? How does one get destroyed?**
 - It gets created when the parents doesn't use wait(), if wait() is called, the parent will "wait" for the child to finish and close that fork.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
 - A complied language is faster since the language is being converted from syntax to machine language (binary). But a non-compiled language is more convenient since you don't have to compile to get your result or struggle trying to debug with Visual Code Studio.
