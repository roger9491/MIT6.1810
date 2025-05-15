
https://pdos.csail.mit.edu/6.828/2022/labs/pgtbl.html

---
## Speed up system calls ([easy](https://pdos.csail.mit.edu/6.S081/2022/labs/guidance.html))
**pgaccess: FAIL  正常，下面任務需要完成**

### 需求理解
任務: 使得 ugetpid() 可以得到值
```c
#ifdef LAB_PGTBL
int
ugetpid(void)
{
  struct usyscall *u = (struct usyscall *)USYSCALL;
  return u->pid;
}
#endif
```
在 用戶態調用 USYSCALL，須得到 pid
代表進程的 `page table` 需要有 USYSCALL，
所以任務就是把 `usyscall` 需要的資料塞進去。

### 流程
從提示我們可以得知，創建進程的流程，會從 `allocproc()` 開始，接者創建 page_tabe，在這個流程中我們要把所需要的資料建立好塞進去。\

---
## Detect which pages have been accessed ([hard](https://pdos.csail.mit.edu/6.S081/2022/labs/guidance.html))

### Target
檢查進程的虛擬內存是否有被訪問過。

> implement pgaccess()
> three arguments
> 1. starting virtual address of the first user page to check
> 2. number of pages to check.
> 3.  user address to a buffer to store the results into a bitmask

使用 `argaddr()` , `argint()` 拿到參數

```c
int pgaccess(void *base, int len, void *mask);
檢查 base 每一頁是否有被調用
len 代表要檢查到多少頁
mask 以位元代表頁數有沒有被訪問
```

`copyout` 函数的作用是将数据从内核空间复制到用户空间中的某个虚拟地址

`walk` 函数用于遍历并定位给定虚拟地址（`va`）在页表（`pagetable`）中的页表条目（PTE）。如果该页表条目不存在且 `alloc` 参数为非零，则会动态创建所需的页表页。
### Modifications
```c
kernel/sysproc.c  sys_pgaccess()
kernel/riscv.h  define PTE_A
```