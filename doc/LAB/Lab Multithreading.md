https://pdos.csail.mit.edu/6.828/2022/labs/thread.html

**branch : thread

----
## Uthread: switching between threads ([moderate](https://pdos.csail.mit.edu/6.828/2022/labs/guidance.html))

### Target
實現用戶級線程切換，不使用內核的線程。

### Modifications
```c
user/uthread.c
user/uthread_switch.s
```

### Solution
 可以參考 `kernel/proc.c: scheduler()` 如何切換線程，以及保存那些寄存器
 分配 stack 空間
 儲存 函式調用位置


## Using threads ([moderate](https://pdos.csail.mit.edu/6.828/2022/labs/guidance.html))
### Target
併發插入hash table，會損失key
練習使用
pthread_mutex_t lock;            // declare a lock
pthread_mutex_init(&lock, NULL); // initialize the lock
pthread_mutex_lock(&lock);       // acquire lock
pthread_mutex_unlock(&lock);     // release lock

### Modifications
```c
notxv6/ph.c
```



## Barrier ([moderate](https://pdos.csail.mit.edu/6.828/2022/labs/guidance.html))
### Target          
實作 barrier ，練習使用 
pthread_cond_wait(&cond, &mutex);  // go to sleep on cond, releasing lock mutex, acquiring upon wake up
pthread_cond_broadcast(&cond);     // wake up every thread sleeping on con，使得每一個線程都會在同一個回合。

### Modifications
```c
notxv6/barrier.c
```

### Solution
增加回合數和判斷不是原子，需要使用鎖。