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

// not
// -----------------------------

// collect first pop
@SP
M = M - 1
A = M
D = M

D = !D // NOT

// push result to stack
@SP
A = M
M = D
@SP
M = M + 1
