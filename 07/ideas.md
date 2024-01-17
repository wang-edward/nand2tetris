# what is the stack?
- The stack is the subset of memory mapped on 256 - 2047
- We keep a stack pointer SP that holds the memory address of the top value of the stack
    - This is different to all the segments, which hold the base value

push segment index
- push the value of segment[index] on to the stack
    - segment is **argument, local, static, constant, this, that, pointer, temp**
    - index is a nonnegative integer

```asm

```



pop segment index

add
```
pop
```

sub
neg
eq
lt
gt
and
or
not
