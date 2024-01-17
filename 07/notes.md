# segments
0           stack pointer
1           local segment
2           argument segment
3           this segment
4           that segment
5-12        temp segment
13-15       extra variables
16-255      static variables
256-2047    stack

# what is the stack?
represented by a stack pointer @SP
- Push = sp++
- Pop = sp--

push segment index
- pushes segment[index] onto the stack
    - increment SP
    - write to SP
```
// move to segment + index
@3
D = A
@LCL
A = D + M
D = M // D = ram[segment + index]

// write to ram[SP]
@SP
A = M // equivalent to @M
M = D // ram[SP] = ram[segment + index]
 
// ++
@SP  
M = M + 1 // ram[SP] = ram[SP]
```

pop segment index
- pops the top of the stack
- stores it in segment[index]

```
// move to stack pointer
@SP
A = M // 
D = M // D = ram[SP]


```

add
- pop top 2 and add them
sub
neg

eq
gt
lt

and
or
not
