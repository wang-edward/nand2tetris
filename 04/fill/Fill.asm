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
  @SCREEN
  D=M
  @x
  M=D
  @color
  M=0
  @LOOP
  0;JMP

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
  @color
  M=0
  @SET
  0;JMP

(BLACK)
  @color
  M=-1
  @SET
  0;JMP

(SET)
  // get color
  @color
  D=M

  // move to x
  @x
  A=M
  // set color
  M=D

  // increment x
  @x
  M=M+1
  // check if x == max_screen
  D=M
  @max_screen
  D=D-M
  // stay in SET if !=
  @SET
  D;JLT
  // else reset x and go back to LOOP
  @screen
  D=M
  @x
  M=D
  @LOOP
  0;JMP




