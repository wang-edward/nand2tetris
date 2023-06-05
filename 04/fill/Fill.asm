// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
  @24575
  D=A
  @max_screen
  M=D
  @color
  M=0
(LOOP)
  @KBD
  D=M
  // if D == 0 go to white
  @WHITE
  D;JEQ
  // else go to black
  @BLACK
  0;JMP

(WHITE)
  // n is a pointer
  // reset n
  @n
  M=0
  (WLOOP)
    // move to correct address
    @n
    D=M
    @SCREEN
    A=D+M
    // set to white
    M=-1
    // increment n
    @n
    M=M+1
    // repeat?
    D=M
    @max_screen
    D=M-D
    @WLOOP
    D;JLT
    @LOOP
    0;JMP

(BLACK)
  @n
  M=0
  (BLOOP)
    // select address
    @n
    D=M
    @SCREEN
    A=D+M
    // set to black
    M=0
    // increment n 
    @n 
    M=M+1
    // repeat?
    D=M
    @max_screen
    D=M-D
    @BLOOP
    D;JLT
    @LOOP
    0;JMP
