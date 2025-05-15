https://pdos.csail.mit.edu/6.S081/2022/labs/traps.html



## 前置知識
https://mit-public-courses-cn-translatio.gitbook.io/mit6-s081/lec05-calling-conventions-and-stack-frames-risc-v/5.5-stack

https://pdos.csail.mit.edu/6.1810/2022/lec/l-riscv.txt

ch4, ch5

---

## Backtrace ([moderate](https://pdos.csail.mit.edu/6.S081/2022/labs/guidance.html))

### Modifications
```
mplement a backtrace() function in kernel/printf.c
```

`*(uint64 *)`
`(uint64 *)`: 轉型
`*`: 取指標裡的地址的值
因為`r_fp()` 回傳的是 stack frame 的地址，而 stack frame 裡面的地址，是存放函式的各種訊息的位置，所以要獲取該訊息就必須解引用

Done

---
## Alarm ([hard](https://pdos.csail.mit.edu/6.S081/2022/labs/guidance.html))
```
新增一個新的 sigaarm(interval, handler) 系統呼叫


```



