https://pdos.csail.mit.edu/6.828/2022/labs/cow.html

**branch**: cow

---
## Implement copy-on-write fork([hard](https://pdos.csail.mit.edu/6.828/2022/labs/guidance.html))

### Target
實現 copy-on-write fork 

### Modifications
```c
kernel/defs.h
kernel/kalloc.c
kernel/trap.c
kernel/vm.c
```
### Solution
閱讀 [lec08](https://mit-public-courses-cn-translatio.gitbook.io/mit6-s081/lec08-page-faults-frans/8.1-page-fault-basics)


### debug

![[assets/Pasted image 20250415170733.png]]

第二個錯誤是 引用到了已經釋放物理頁面的地址
本來是另外寫一個函式 來去控制 引數，然後去掉用這個函式

因為不是所有地方都會調用這個函式，所以我直接把引數的控制寫在 `kfree/kalloc`


![[assets/Pasted image 20250505142349.png]]

排除不合法地址。

## sbarkfail 無限迴圈
cow 要回傳正確的失敗，處理好失敗時的策略

