// test
// -----------------------------
// set SP to 256
@256
D = A
@SP
M = D

// push 2 and 5 to stack
@2
D = A
@SP
A = M
M = D
@SP
M = M + 1

@3
D = A
@SP
A = M
M = D
@SP
M = M + 1

// gt
// -----------------------------

// collect first pop
@SP
M = M - 1
A = M
D = M // D = y

// accumulate second pop
@SP
M = M - 1
A = M
D = M - D // D = x - y
@SYS_TEST_GT$
D;JGT
@SYS_TEST_GT_NOT$
0;JMP

(SYS_TEST_GT$)
D = -1
@SYS_WRITE$
0;JMP

(SYS_TEST_GT_NOT$)
D = 0
@SYS_WRITE$
0;JMP

(SYS_WRITE$)

// push result to stack
@SP
A = M
M = D
@SP
M = M + 1
