// push {
    @local.2
    D = M
    @SP
    A = M
    M = D
    @SP
    M = M + 1
// }
// push {
    @argument.3
    D = M
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
