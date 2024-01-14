// push constant {
    @17
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @17
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// eq {
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
// }
// push constant {
    @17
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @16
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// eq {
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
// }
// push constant {
    @16
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @17
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// eq {
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
// }
// push constant {
    @892
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @891
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// lt {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = M - D

    @SYS_TEST_LT$
    D;JLT
    @SYS_TEST_LT_NOT$
    0;JMP

    (SYS_TEST_LT$)
    D = -1
    @SYS_WRITE$
    0;JMP

    (SYS_TEST_LT_NOT$)
    D = 0
    @SYS_WRITE$
    0;JMP

    (SYS_WRITE$)
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @891
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @892
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// lt {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = M - D

    @SYS_TEST_LT$
    D;JLT
    @SYS_TEST_LT_NOT$
    0;JMP

    (SYS_TEST_LT$)
    D = -1
    @SYS_WRITE$
    0;JMP

    (SYS_TEST_LT_NOT$)
    D = 0
    @SYS_WRITE$
    0;JMP

    (SYS_WRITE$)
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @891
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @891
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// lt {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = M - D

    @SYS_TEST_LT$
    D;JLT
    @SYS_TEST_LT_NOT$
    0;JMP

    (SYS_TEST_LT$)
    D = -1
    @SYS_WRITE$
    0;JMP

    (SYS_TEST_LT_NOT$)
    D = 0
    @SYS_WRITE$
    0;JMP

    (SYS_WRITE$)
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @32767
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @32766
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// gt {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = M - D
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
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @32766
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @32767
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// gt {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = M - D
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
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @32766
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @32766
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// gt {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = M - D
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
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @57
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @31
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @53
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// add {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = D + M // ADD

    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @112
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// sub {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = M - D // SUB

    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// neg {
    @SP
    M = M - 1
    A = M
    D = -M // NEG

    @SP
    A = M
    M = D
    @SP
    M = M + 1
}
// and {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = D & M // AND

    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push constant {
    @82
    D = A
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// or {
    @SP
    M = M - 1
    A = M
    D = M

    @SP
    M = M - 1
    A = M
    D = D | M // OR

    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// not {
    @SP
    M = M - 1
    A = M
    D = !M // NOT

    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
