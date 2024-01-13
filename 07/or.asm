// test
// -----------------------------
// set SP to 256
@256
D = A
@SP
M = D

// push 2 and 5 to stack
@3
D = A
@SP
A = M
M = D
@SP
M = M + 1

@5
D = A
@SP
A = M
M = D
@SP
M = M + 1

// or
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
D = D | M // OR

// push result to stack
@SP
A = M
M = D
@SP
M = M + 1
