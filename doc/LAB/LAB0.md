# [Lab util: Unix utilities](https://pdos.csail.mit.edu/6.828/2022/labs/util.html)

使用別人建好的 docker

``` shell
sudo docker pull linxi177229/mit6.s081

sudo docker run --name mit6.s081 -v /home/roger/code/MIT6.1810:/root/MIT6.1810 -itd linxi177229/mit6.s081 
sudo docker attach mit6.s081 
```

Build and run xv6:

``` sh
make qemu
```

To quit qemu！！

``` sh
ctrl + a # release
x
```



## sleep(easy)

The solution is in the `user/sleep.c` file.

**Target** 

Implement the UNIX program `sleep` for `xv6`; 

**Approach**

use `sleep` from `user/user.h`.

**Purpose**

To help me understand how to develop programs in xv6, what functions can I call? Where can I find them?



Run the program
``` sh
make qemu
sleep 10
```

get grade

``` sh
./grade-lab-util sleep
# or
make GRADEFLAGS=sleep grade
```



## pingpong

The solution is in the `user/pingpong.c` file.

**Target**

> Write a program that uses UNIX system calls to ''ping-pong'' a byte between two processes over a pair of pipes, one for each direction. The parent should send a byte to the child; the child should print "<pid>: received ping", where <pid> is its process ID, write the byte on the pipe to the parent, and exit; the parent should read the byte from the child, print "<pid>: received pong", and exit. Your solution should be in the file `user/pingpong.c`.

**Approach**

use `pipe`, `read`,  `write`,  `printf`



## primes

> Write a concurrent version of prime sieve using pipes. This idea is due to Doug McIlroy, inventor of Unix pipes. The picture halfway down [this page](http://swtch.com/~rsc/thread/) and the surrounding text explain how to do it. Your solution should be in the file `user/primes.c`.

// todo

No idea



## find

The solution is in the `user/find.c` file.

> Write a simple version of the UNIX find program: find all the files in a directory tree with a specific name. Your solution should be in the file `user/find.c`.
