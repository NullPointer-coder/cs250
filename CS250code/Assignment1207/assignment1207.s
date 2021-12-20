# to determine whether the character is contained in the string
# Jingbo Wang

  .data
prompt1:
  .asciiz "Please enter a string: "
prompt2:
  .asciiz "Please enter a character: "
output1:
  .asciiz " contains "
output2:
  .asciiz " does not contain "
buffer:
  .space 11
newline:
  .asciiz "\n"

  .text
  .globl main
main:
  # s0: the input string
  # s1: the input character 
  # s2: the boolean found result

  li    $v0, 4              # print_string 
  la    $a0, prompt1        # print "Please enter a string: "
  syscall
  
  li    $v0, 8              # read_string
  la    $a0, buffer         # load byte space into address
  li    $a1, 11             # allot the byte space for string
  syscall

  move  $s0, $a0            # save string to s0
  move  $a1, $a0            # set up argument for string

  li    $v0, 4              # print_string 
  la    $a0, newline        # print newline character
  syscall

  li    $v0, 4              # print_string 
  la    $a0, prompt2        # print "Please enter a character: "
  syscall
  
  li    $v0, 12             # read_character
  syscall
  move  $s1, $v0            # store character into s1
  move  $a2, $v0            # set up argument for character

  jal   strcintaubsi        # call function
  move  $s2, $v0            # store the found result

  li    $v0, 4              # print_string 
  la    $a0, newline        # print newline character
  syscall
if:
  bne   $s2, 1, else        # bool found or not

  li    $v0, 4              # print_string 
  la    $a1, buffer         # load byte space into address
  move  $a0, $s0            # print input string
  syscall                   
  
  li    $v0, 4              # print_string 
  la    $a0, output1        # print " contains "
  syscall
  
  li    $v0, 11             # print_character
  move  $a0, $s1            # print input character
  syscall

  li    $v0, 4              # print_string 
  la    $a0, newline        # print newline character
  syscall
  j    end_main
else:
  li    $v0, 4              # print_string 
  la    $a1, buffer         # load byte space into address
  move  $a0, $a1            # print input string
  syscall

  li    $v0, 4              # print_string 
  la    $a0, output2        # print " does not contains "
  syscall

  li    $v0, 11             # print_character
  move  $a0, $s1            # print input character
  syscall

  li    $v0, 4              # print_string 
  la    $a0, newline        # print newline character
  syscall
  
end_main:  
  li    $v0, 10             # exit
  syscall
  .end main

toupper:
  # a0: the character parameter
  # v0: the return value

  addiu  $v0, $a0, 0        # copy a0 to v0
  blt   $v0, 0x61, tu_end   # 0x61 = 'a'; ignore chars less them
  bgt   $v0, 0x7a, tu_end   # 0x7a = 'z'; ignore chars greater them
  subu  $v0, $v0, 0x20      # 0x20 = 'a' - 'A'

tu_end:
  jr    $ra

strcintaubsi:
  # a0: the character into toupper function
  # a1: the input string parameter
  # a2: the input character parameter
  # t0: the uppercase string[i]
  # t1: the string[i]
  # t2: the uppercase character
  # t3: string index
  # t4: the boolean found value

  move  $t3, $zero          # i = 0
  move  $t4, $zero          # found = 0
  move  $a0, $a2            # set up argument, copy char into $a0
  
  addi  $sp, $sp, -4        # "push" opearation into register
  sw    $ra, 0($sp)         # save the current return

  jal   toupper
  move  $t2, $v0            # store uppercase character into $t2

while:
  addu  $t1, $t3, $a1       # $t1 = &string[i]
  lbu   $a0, 0($t1)         # $a0 = string[i]
  jal   toupper
  move  $t0, $v0            # store uppercase string[i] into $t0

enter:
  bne   $t0, $zero, else_if # uppercase string[i] != '\0' goto else if
  j     exit

else_if:
  bne   $t0, $t2, else2     # uppercase string[i] != character goto exit2
  addiu $t4, 1              # found = 1
  j     exit

else2:
  addiu $t3, 1              # i++
  j     while

exit:
  
  lw    $ra, 0($sp)          #  restore the $ra into register
  addi  $sp, $sp, 4          #  "pop" operateration

  move  $v0, $t4             #  return value: the boolean found result
  jr    $ra                  #  return


