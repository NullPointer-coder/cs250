# Use recursion to calculate the area of a pyramid
# composed of unit squares with a given base width
# Jon Beck

  .data
prompt:
  .asciiz "Enter width of base: "
output1:
  .asciiz "The area of a pyramid with base "
output2:
  .asciiz " is "

  .text
  .globl main
main:
  # s0 the pyrimid width
  # s1 the pyrimid area

  li    $v0, 4              # print string
  la    $a0, prompt
  syscall

  li    $v0, 5              # read int
  syscall

  move  $s0, $v0            # store width
  move  $a0, $v0            # set up argument
  jal   get_area            # call function
  move  $s1, $v0            # store area

  li    $v0, 4              # print_string
  la    $a0, output1
  syscall

  li    $v0, 1              # print int
  move  $a0, $s0
  syscall

  li    $v0, 4
  la    $a0, output2
  syscall

  li    $v0, 1              # print_int
  move  $a0, $s1
  syscall

  li    $v0, 11             # print character
  li    $a0, 10             # newline
  syscall

  li    $v0, 10             # exit
  syscall

get_area:
  bne   $a0, $zero, recurse # check for base case
  li    $v0, 0              # return 0
  jr    $ra

recurse:
  # need to save:
  #   ra
  #   a0

  subu  $sp, $sp, 8         # two words on the stack
  sw    $ra, -4($sp)        # push ra
  sw    $a0, 0($sp)         # push a0

  subu  $a0, $a0, 1         # width - 1
  jal   get_area            # get_area(width - 1)

  lw    $a0, 0($sp)         # recover width
  addu  $v0, $v0, $a0       # result + width

  lw    $ra, -4($sp)        # recover ra
  addiu $sp, $sp, 8         # restore stack pointer
  jr    $ra                 # return
