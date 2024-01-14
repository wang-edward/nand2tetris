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
