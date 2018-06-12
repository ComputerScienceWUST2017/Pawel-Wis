.data
msgPrintSpace: .asciiz " "
msgPrintNewline: .asciiz "\n"
msgAskForNumOfElem: .asciiz "Give number of elements to sort: "
msgAskForElem: .asciiz "Enter number to sort one by one: \n"
msgPrintSorted: .asciiz "Sorted array: "
.text
		la $a0, msgAskForNumOfElem
		li $v0, 4
		syscall
		
		li $v0,5
		syscall       # read n
		move $s7, $v0 # s7 stores n

		mul $a0, $s7, 4 
		jal bookMem   # get memory for array
		move $s6, $v0 # s6 stores pointer to 1st element of array  with numbers
		
		la $a0, msgAskForElem
		li $v0, 4
		syscall
		
		move $a0, $s7
		move $a1, $s6
		jal scanNumbers # gets numbers in loop
		
		move $a0, $s7
		move $a1, $s6
		jal bubbleSortB
		
		la $a0, msgPrintSorted
		li $v0, 4
		syscall
		
		move $a0, $s7
		move $a1, $s6
		jal printArr	
						
		li $v0, 10
		syscall

###
#books memory
bookMem:	li $v0, 9
		syscall
		jr $ra
		
#read numbers in loop
scanNumbers:	add $t0, $zero, $zero # loop counter (i)
		move $t1, $a0 # stores n
		move $t2, $a1 # stores pointer to array of numbers (ptr)
scanNumLoop:	bge $t0, $t1, exitSNL
		li $v0, 5
		syscall
		sw $v0, ($t2)
		addi $t0, $t0, 1 # i++
		addi $t2, $t2, 4 # ptr++		
		j scanNumLoop
exitSNL:	jr $ra
			
# bubble sort
bubbleSortB:	add $t0, $zero, $zero # counter for outer loop i
		addi $t1, $zero, 1 # counter for inner loop j		
		move $t2, $a0         # stores n
		move $t3, $a1         # pointer to current element in array
BSLoopB:	lw $t4, ($t3)         # t5 stores value of curr
		lw $t5, 4($t3)         # t6 stores value of next
		ble $t4, $t5, afterSwapB
		addi $sp, $sp, -20
		sw $t0, ($sp)
		sw $t1, 4($sp)
		sw $a0, 8($sp)
		sw $a1, 12($sp)
		sw $ra, 16($sp)
		move $a0, $t3
		addi $a1, $t3, 4
		jal swap
		lw $t0, ($sp)
		lw $t1, 4($sp)
		lw $a0, 8($sp)
		lw $a1, 12($sp)
		lw $ra, 16($sp)
		addi $sp, $sp, 20
afterSwapB:	addi $t3, $t3, 4      # increment pointer to current element
		addi $t1, $t1, 1
		blt $t1, $t2, BSLoopB
		#inner loop finished
		addi $t0, $t0, 1      # i++		
		move $t1, $t0         # j:=i
		move $t3, $a1         # t3 again points to first element of array
		blt $t0, $t2, BSLoopB  # start loop once again
		jr $ra				
		
#print sequence of ints in loop																
printArr:	add $t0, $zero, $zero # i=0
		move $t1, $a0	      # stores n
		move $t2, $a1         # stores pointer to array
printArrLoop:	li $v0, 1
		lw $a0, ($t2)
		syscall
		li $v0, 4
		la $a0, msgPrintSpace
		syscall
		addi $t0, $t0, 1
		addi $t2, $t2, 4
		blt $t0, $t1, printArrLoop
		li $v0, 4
		la $a0, msgPrintSpace
		syscall
		jr $ra

# bubble sort
bubbleSortA:	add $t0, $zero, $zero # counter for outer loop i
		addi $t1, $zero, 1 # counter for inner loop j		
		move $t2, $a0         # stores n
		move $t3, $a1         # pointer to current element in array
BSLoopA:	lw $t4, ($t3)         # t5 stores value of curr
		lw $t5, 4($t3)         # t6 stores value of next
		ble $t4, $t5, afterSwapA
		sw $t4, 4($t3)  #swaps
		sw $t5, ($t3)  #swaps
afterSwapA:	addi $t3, $t3, 4      # increment pointer to current element
		addi $t1, $t1, 1
		blt $t1, $t2, BSLoopA
		#inner loop finished
		addi $t0, $t0, 1      # i++		
		move $t1, $t0         # j:=i
		move $t3, $a1         # t3 again points to first element of array
		blt $t0, $t2, BSLoopA  # start loop once again
		jr $ra
					
#swaps two elements	
swap:		lw $t0, ($a0)
		lw $t1, ($a1)
		sw $t0, ($a1)
		sw $t1, ($a0)
		jr $ra
										
																
																								
																																
																																								
																																																								
												
