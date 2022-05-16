### [return to main page](https://github.com/shaolin-peanut/pipex)

# Explanation
This program is a great initiation to the concept of pipes, and redirection of pipes, in Unix.
In this program, we're gonna imitate the pipe operator (`|`), which allows to "pipe" the output of a program to another one.
But beyond that, we have to take a file as input, and write the output of the last command, to another file.
Seems tricky, but simple when you get the moving parts
## [Processes](https://en.wikipedia.org/wiki/Process_(computing)) in computing
As the wikipedia page (linked above) explains in detail, a process is an instance, a "happening", of your program when it executes. You can see it as an event, but formalized. 
In this formalized event, this **process**, you get the memory space where variables are stored for the duration of time the program is executing, and the connection to the system you run on, through [standard streams](https://en.wikipedia.org/wiki/Standard_streams) (STDIN, STDOUT) for example.
We have to understand processes, because to be able to run programs from within our program, we'll need to create a new process for it, and launch the command from there. It will be our job to direct the input and output of this "child" process to the right place.
## The tools
To understand processes further, I have to describe the essential tools we have at our disposal.
#### fork()
Fork is going to create a child process. This is a great illustration, taken from [this website](http://www.it.uu.se/education/course/homepage/os/vt18/module-2/process-management/), which explains the parent/child process thing better than me.
![](http://www.it.uu.se/education/course/homepage/os/vt18/images/module-2/fork-exec-exit-wait.png).
The child process is a literal copy of the parent process. It has the same variables in memory, fds, standards streams, etc.
This function will return 0 if you're in the child process, and the process id if you're in the parent process. By checking fork's output you can give different instructions given which process is running.
#### wait()/waitpid()
Pauses the parent process until the child process exits. Essential for you to get the output at the right place.
#### pipe()
Important one. This will create a communication channel between the two processes. An array of two ints (fd[2] for ex) is given as argument, before the fork.
After the fork, the array being duplicated, you can use fd[1] to write data to the other process, and fd[0] to read from it.
Looks cool, but that's not what we'll do with it. We're going to _rotate_ this pipe, redirect so that the standard streams of our child processes write and read from it.
#### dup2()
This is what will allow us to rotate/redirect the pipe. Takes two file descriptors as arguments, and replaces one by another
#### execve()
The command we'll use to launch another program from within our program.
When it successfully runs, it replaces the current process by an instance of the program you asked it to launch.
The program changes, but the file descriptors and standard streams stay the same. When it exits, its STDOUT goes where you told your child process' STDOUT to go.
