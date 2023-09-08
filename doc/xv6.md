# xv6

## chapt 1



### 1.2 I/O and File description

The xv6 kernel uses the file descriptor as an  index into a per-process table, so that every process has a private space of file descriptors starting at zero.

The system reserves

`0`	standard input

`1`	standard output

`2` 	standard error

Each file descriptor maps to an opened file, for example, `0` maps to File1, henceforth, the data for standard input comes from File1.

``` c
char *argv[2];

argv[0] = "cat";
argv[1] = 0;
if(fork() == 0) {
    close(0);
    open("input.txt", O_RDONLY);
    exec("cat", argv);
}
```

Here, the first parameter of `exec` is the path of the program to be executed, and the second parameter is an array of arguments. In the array, the element at index 0 is used to name your program. Therefore, the actual parameter received by 'cat' is null.



### 1.3 Pips

``` c
int p[2];
char *argv[2];

argv[0] = "wc";
argv[1] = 0;

pipe(p);
if(fork() == 0) {
	close(0);
	dup(p[0]);
	close(p[0]);
	close(p[1]);
	exec("/bin/wc", argv);
} else {
	close(p[0]);
	write(p[1], "hello world\n", 12);
	close(p[1]);
}
```

