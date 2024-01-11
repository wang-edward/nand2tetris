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
@index
D = A
@segment
A = D + A
D = M // D = ram[segment + index]
@SP
M = D // ram[SP] = ram[segment + index]
A = M // equivalent to @M
@SP   // 
M = M + 1 // ram[SP] = ram[SP]
```

pop segment index

add
sub
neg

eq
gt
lt

and
or
not