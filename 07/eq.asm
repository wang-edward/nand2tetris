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

@2
D = A
@SP
A = M
M = D
@SP
M = M + 1

// add
// -----------------------------

// collect first pop
@SP
M = M - 1
A = M
D = M

// accumulate second pop
@SP
M = M - 1
A = M
D = D - M
@SYS_TEST_EQUAL$
D;JEQ
@SYS_TEST_EQUAL_NOT$
0;JMP

(SYS_TEST_EQUAL$)
D = -1
@SYS_WRITE$
0;JMP

(SYS_TEST_EQUAL_NOT$)
D = 0
@SYS_WRITE$
0;JMP

(SYS_WRITE$)

// push sum to stack
@SP
A = M
M = D
@SP
M = M + 1
