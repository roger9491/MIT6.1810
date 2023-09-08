## File Description

```
/user
	/user.h define C functions that users can call
```



## Start the experimental environment

Run the docker

``` sh
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

Run the program
``` sh
make qemu
{Program name}
```

get grade

``` sh
./grade-lab-util {Need test program name}
# or
make GRADEFLAGS={Need test program name} grade
```