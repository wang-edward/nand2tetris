// setup
// -----------------------------

// to begin, set LOCAL to 64
@64
D = A
@LCL
M = D
// set SP to 256
@256
D = A
@SP
M = D
// set the value at SP to 29
@29
D = A
@255
M = D

// pop
// -----------------------------

// SP--
@SP
M = M - 1 // x = ram[SP]

A = M
D = M
@{segment}.{index}
M = D
