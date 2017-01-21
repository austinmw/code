############################################################################
#                       Lab 3
#                       EC413
#
#    		Assembly Language Lab -- Programming with Loops.
#
############################################################################
#  DATA
############################################################################
        .data           # Data segment
Hello:  .asciiz " \nAustin Welch \n "  # declare a zero terminated string
AnInt:	.word	17		# a word initialized to 17
space:	.asciiz	" "	# declare a zero terminate string
WordAvg:   .word 0		#use this variable for part 4
ValidInt:  .word 0		#
ValidInt2: .word 0		#
lf:     .byte	10,0	# string with carriage return and line feed
InLenW:	.word   4       # initialize to number of words in input1 and input2
InLenB:	.word   16      # initialize to number of bytes in input1 and input2
        .align  4
Input1:	.word	0x01020304,0x05060708
	    .word	0x090A0B0C,0x0D0E0F10
        .align  4
Input2: .word   0x01221117,0x090b1d1f   # input
        .word   0x0e1c2a08,0x06040210
        .align  4
Copy:  	.space  0x80    # space to copy input word by word
        .align  4
 
############################################################################
#  CODE
############################################################################
        .text                   # code segment
#
# print out greeting
#
main:
        la      $a0,Hello       # address of string to print
        li      $v0,4		# system call code for print_str
        syscall                 # print the string
#
# Code for Item 3 -- 
# Print the integer value of AnInt
#
        lw     $a0, AnInt       # integer to print
        li     $v0, 1           # system call code for print_int
        syscall                 # print the integer 

        la     $a0, lf          # address of carriage return
        li     $v0, 4           # system call code for print_str
        syscall                 # print the string
#
# Code for Item 4 -- 
# Print the integer values of each byte in the array Input1 (with spaces)
#
# unsure of how ValidInt and ValidInt2 were intended to be used for this problem
# loop initialization      
        la      $s0, Input1     # address of base to save
        li      $s1, 0          # start counter at zero
        li      $s2, 16         # length of array in bytes
Loop1:
        bge     $s1, $s2, Done1 # loop test - at 16 yet?
        add     $t0, $s0, $s1   # address of byte to print
        lb      $a0, 0($t0)     # load current byte of Input1
        li      $v0, 1          # system call code for print_int
        syscall                 # print the integer
        la      $a0, space      # address of space string
        li      $v0, 4          # system code for print_str
        syscall                 # print the string 
        add     $s1, $s1, 1     # iterate count
        j       Loop1           # go to top of Loop1
Done1:        
        la      $a0, lf         # address of carriage return
        li      $v0, 4          # system call code for print_str
        syscall                 # print the string
#
# Code for Item 5 -- 
# Write code to copy the contents of Input2 to Copy
#
# loop initialization      
        la      $s0, Input2     # address of the base of Input2
        la      $s1, Copy       # address of the base of Copy
        li      $s3, 0          # initialize counter to 0
        lw      $s4, InLenW     # loop limit constant 
Loop2:
        bge     $s3, $s4, Done2 # loop test - at 4 yet?
        lw      $t0, 0($s0)     # get the contents of *Input2
        sw      $t0, 0($s1)     #   and store into *Copy
        add     $s0, $s0, 4     # *Input2++
        add     $s1, $s1, 4     # *Copy++
        add     $s3, $s3, 1     # count++
        j       Loop2           # go to top of Loop2
Done2:        
#
# Code for Item 6 -- 
# Print the integer average of the contents of array Input2
#
# loop initialization
        la      $s0, Input2     # address of base of Input2
        lw      $s1, InLenB     # loop limit constant
        li      $s2, 0          # initialize counter to 0
        li      $s3, 0          # initialize sum to 0
Loop3:
        beq     $s1, $s2, Done3 # loop test - at 16 yet?       
        lb      $t0, 0($s0)     # load current byte
        add     $s3, $s3, $t0   # add current byte to sum
        add     $s0, $s0, 1     # *Input2++     
        add     $s2, $s2, 1     # counter++
        j       Loop3           # go to top of Loop3
Done3:
        div     $s3, $s3, $s1   # divide sum by number of bytes
        sw      $s3, WordAvg    # store average in WordAvg
        lw      $a0, WordAvg    # integer value to print
        li      $v0, 1          # system call code for print_int
        syscall                 # print WordAvg
        la      $a0, lf         # address of carriage return
        li      $v0, 4          # system call code for print_str
        syscall                 # print the string
#
# Code for Item 7 -- 
# Display the first 25 integers that are divisible by either 11 and 17 (with spaces)
#
#loop initialization
        li      $s0, 0          # initialize counter to 0
        li      $s1, 25         # loop limit constant
        li      $s2, 11         # first number to mod
        li      $s3, 17         # second number to mod
        li      $s4, 0          # zero for modulus
        li      $s5, 0          # current int
Loop4:
        beq     $s0, $s1, Done4 # loop test - at 25 yet?
        rem     $t0, $s5, $s2   # mod current integer by 11
        beq     $t0, $s4, Prnt  # if n%11=0, jump to print
        rem     $t0, $s5, $s3   # mod current integer by 17
        beq     $t0, $s4, Prnt  # if n%17=0, jump to print
        add     $s5, $s5, 1     # number++
        j       Loop4           # go back to top of loop
Prnt:  
        add     $s0, $s0, 1     # count++
        sw      $s5, ValidInt   # store current int into ValidInt
        lw      $a0, ValidInt   # address of current int
        li      $v0, 1          # system call go for print_int
        syscall                 # print the int
        la      $a0, space      # address of space string
        li      $v0, 4          # system code for print_str
        syscall                 # print the string        
        add     $s5, $s5, 1     # int++
        j       Loop4           # go back to top of loop   
Done4:        
        la      $a0, lf         # address of carriage return
        li      $v0, 4          # system call code for print_str
        syscall                 # print the string
#
# Code for Item 8 -- 
# Repeat step 7 but display the integers in 5 lines with 5 integers with spaces per line
# This must be implemented using a nested loop.
#
# loop initialization
        li      $s0, 0          # initialize counter to 0
        li      $s1, 25         # loop limit constant
        li      $s2, 11         # first number to mod
        li      $s3, 17         # second number to mod
        li      $s4, 0          # zero for modulus
        li      $s5, 0          # current int
        li      $s6, 5          # 5 per line
Loop5:
        beq     $s0, $s1, Done5 # loop test - at 25 yet?
        rem     $t0, $s5, $s2   # mod current integer by 11
        beq     $t0, $s4, Prnt2 # if n%11=0, jump to print
        rem     $t0, $s5, $s3   # mod current integer by 17
        beq     $t0, $s4, Prnt2 # if n%17=0, jump to print
        add     $s5, $s5, 1     # number++
        j       Loop5           # go back to top of loop
Prnt2:  
        add     $s0, $s0, 1     # count++
        sw      $s5, ValidInt   # store current int into ValidInt
        lw      $a0, ValidInt   # address of current int
        li      $v0, 1          # system call go for print_int
        syscall                 # print the int
        la      $a0, space      # address of space string
        li      $v0, 4          # system code for print_str
        syscall                 # print the string        
        add     $s5, $s5, 1     # int++
        rem     $s7, $s0, $s6   # int % 5
        bne     $s7, $s4, Loop5 # int % 5 not equal to 0
        la      $a0, lf         # address of carriage return
        li      $v0, 4          # system call code for print_str
        syscall                 # print the string
        j      Loop5            # go back to top of loop 
Done5:        
        la      $a0, lf         # address of carriage return
        li      $v0, 4          # system call code for print_str
        syscall                 # print the string

# End of file