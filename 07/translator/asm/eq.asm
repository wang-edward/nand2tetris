@SP
M = M - 1
A = M
D = M
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
@SP
A = M
M = D
@SP
M = M + 1