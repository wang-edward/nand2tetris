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

@5
D = A
@SP
A = M
M = D
@SP
M = M + 1

// neg
// -----------------------------

// collect first pop
@SP
M = M - 1
A = M
D = -M // NEG

// push num to stack and negate
@SP
A = M
M = D
@SP
M = M + 1
