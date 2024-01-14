// test
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
// set the value at LOCAL+3 to 29
@29
D = A
@67
M = D

// push
// -----------------------------

// move to segment + index
@3
D = A
@LCL
A = D + M
D = M // D = ram[segment + index]
@SP
A = M // equivalent to @M
M = D // ram[SP] = ram[segment + index]
 
@SP   // 
M = M + 1 // ram[SP] = ram[SP]
