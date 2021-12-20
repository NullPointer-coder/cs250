# A complete program that implements strlen as a function
# and calls that function on a string.
# Jon Beck

  .data
string:
  .asciiz "Foobar"
output_str1:
  .asciiz "The length of "
output_str2:
  .asciiz " is "

  .text
  .globl main

main:
  # s0 address of string
  # s1 length of string

  la    $s0, string
  move  $a0, $s0            # copy address into a0 argument

  jal   mystrlen

  move  $s1, $v0            # save return value into s1

  li    $v0, 4              # print_string
  la    $a0, output_str1
  syscall

  la    $a0, string
  syscall

  la    $a0, output_str2
  syscall

  li    $v0, 1              # print_int
  move  $a0, $s1
  syscall

  li    $v0, 11             # print character
  li    $a0, 10             # newline
  syscall

  li    $v0, 10             # exit
  syscall
  .end main

mystrlen:
  # a0 base address of string
  # t0 string index
  # t1 the current character
  # t2 the address of the current character

  move  $t0, $zero          # start with index 0
loop:
  addu  $t2, $t0, $a0       # t2 = &base[index]
  lbu   $t1, 0($t2)         # t1 = base[index]
  beq   $t1, $zero, exit    # exit if null character
  addiu $t0, 1              # t0++
  j     loop

exit:
  move  $v0, $t0            # return value: the index of
                            # the last non-null character
  jr    $ra                 # return
