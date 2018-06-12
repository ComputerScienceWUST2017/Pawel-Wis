.data
Aheight: .word 0
Awidth: .word 0
Bheight: .word 0
Bwidth: .word 0
Cheight: .word 0 
Cwidth: .word 0
msgAskForDimenA: .asciiz "Enter dimensions of matrix A:\n"
msgAskForDimenB: .asciiz "Enter dimensions of matrix B:\n"
msgAskForMatA: .asciiz "Enter elements of matrix A one by one:\n"
msgAskForMatB: .asciiz "Enter elements of matrix B one by one:\n"
msgPrintMatA: .asciiz "Matrix A:\n"
msgPrintMatB: .asciiz "Matrix B:\n"
msgPrintMatC: .asciiz "Matrix C = AB:\n"
msgSpace: .asciiz " "
msgNewline: .asciiz "\n"
.text
main:			la $a0, msgAskForDimenA  # gets dimensions of matrix A
			la $a1, Aheight
			la $a2, Awidth
			jal readDim
			
			la $a0, msgAskForDimenB  # gets dimensions of matrix B
			la $a1, Bheight
			la $a2, Bwidth
			jal readDim
	
			lw $t0, Awidth		 # checks if dimensions are ok
			lw $t1, Bheight
			bne $t0, $t1, main 
					
			sw $t0, Cheight 	 # obtain dimensions of matrix C = AB
			sw $t1, Cwidth
			
			lw $a0, Aheight		 # book memory for matrix A
			lw $a1, Awidth
			jal bookMemForMatrix
			move $s7, $v0 		 # s7 stores pointer to matrix A
			
			lw $a0, Bheight		 # book memory for matrix B
			lw $a1, Bwidth
			jal bookMemForMatrix
			move $s6, $v0 		 # s6 stores pointer to matrix B
			
			lw $a0, Cheight		 # book memory for matrix C
			lw $a1, Cwidth
			jal bookMemForMatrix
			move $s5, $v0 		 # s5 stores pointer to matrix C
			
			la $a0, msgAskForMatA
			li $v0, 4
			syscall
			
			move $a0, $s7		# fills matrix A
			lw $t0, Aheight
			lw $t1, Awidth
			mul $a1, $t0, $t1
			jal fillMat
	
			la $a0, msgAskForMatB
			li $v0, 4
			syscall
			
			move $a0, $s6		# fills matrix B
			lw $t0, Bheight
			lw $t1, Bwidth
			mul $a1, $t0, $t1
			jal fillMat
	
			la $a0, msgPrintMatA
			li $v0, 4
			syscall
				
			move $a0, $s7		# prints matrix A
			lw $a1, Aheight
			lw $a2, Awidth
			jal printMat
			
			la $a0, msgPrintMatB
			li $v0, 4
			syscall

			move $a0, $s6		# prints matrix B
			lw $a1, Bheight
			lw $a2, Bwidth
			jal printMat
				
			move $a0, $s7           # multiply A and B
			move $a1, $s6
			move $a2, $s5
			jal matrixMul
			
			la $a0, msgPrintMatC
			li $v0, 4
			syscall

			move $a0, $s5		# prints matrix C
			lw $a1, Cheight
			lw $a2, Cwidth
			jal printMat
		
			li $v0, 10		# quit
			syscall
			

#read dimensions
readDim:		li $v0, 4
			syscall    # print msg
			li $v0, 5
			syscall    # get height
			sw $v0, ($a1)
			li $v0, 5
			syscall    # get width
			sw $v0, ($a2)
			jr $ra
			
#book memory for matrix
bookMemForMatrix:	mul $a0, $a0, $a1
			mul $a0, $a0, 4
			li $v0, 9
			syscall		
			jr $ra
			
#fill matrix
fillMat:		move $s0, $a0 # pointer to matrix
			move $s1, $a1 # number of elements to get
			add $t0, $zero, $zero
fillLoop:		bge $t0, $s1, fillLoopEnded
			li $v0, 5
			syscall
			sw $v0, ($s0)
			addi $s0, $s0, 4
			addi $t0, $t0, 1
			j fillLoop
fillLoopEnded:		jr $ra
			
#matrix multiplication  
matrixMul:		move $t3, $a0 #A
			move $t4, $a1 #B
			move $t5, $a2 #C
			lw $s0, Aheight #m
			lw $s1, Awidth #n
			lw $s2, Bwidth #q
			lw $s3, Bheight #p
			
matMulLoopStart:	add $t6, $zero, $zero # stores value to save in matrix C
			add $t0, $zero, $zero # i=0
matMulLoop1:		bge $t0, $s0, matMulLoopEnd # multiplication done
			add $t1, $zero, $zero # j=0
matMulLoop2:		bge $t1, $s2, matMulLoop2Finished
			add $t2, $zero, $zero # k=0
matMulLoop3:		bge $t2, $s3, matMulLoop3Finished
			mul $t7, $s1, $t0 # A[i]
			add $t7, $t7, $t2 # A[i][k]
			mul $t7, $t7, 4
			add $t7, $t3, $t7 # increment pointer
			mul $t8, $s2, $t2 # B[k]
			add $t8, $t8, $t1 # B[k][j]
			mul $t8, $t8, 4
			add $t8, $t4, $t8 # increment pointer
			lw $t7, ($t7)
			lw $t8, ($t8)
			mul $t7, $t7, $t8     # A[i][k]*B[k][j]
			add $t6, $t6, $t7     # add t7 to current sum
			addi $t2, $t2, 1
			j matMulLoop3
matMulLoop3Finished:	mul $t8, $s2, $t0 # C[i]
			add $t8, $t8, $t1 # C[i][j]
			mul $t8, $t8, 4
			add $t8, $t5, $t8 # increment pointer
			sw $t6, ($t8)     # stores sum of products in C
			add $t6, $zero, $zero # clears $t6
			addi $t1, $t1, 1
			move $t3, $a0 # restore pointers to arrays
			move $t4, $a1 
			move $t5, $a2 
			j matMulLoop2	
matMulLoop2Finished:	addi $t0, $t0, 1
			j matMulLoop1	
matMulLoopEnd:		jr $ra

#print matrix
printMat:		move $s0, $a0 # pointer to matrix
			move $s1, $a1 # height of matrix
			move $s2, $a2 # width of matrix
			add $t0, $zero, $zero
printRawLoop:		bge $t0, $s1, exitPrintMat
			add $t1, $zero, $zero
printColLoop:		bge $t1, $s2, printColLoopFinished
			lw $a0, ($s0)
			li $v0, 1
			syscall
			la $a0, msgSpace
			li $v0, 4
			syscall	
			addi $s0, $s0, 4
			addi $t1, $t1, 1	
			j printColLoop	
printColLoopFinished:	la $a0, msgNewline
			li $v0, 4
			syscall		
			addi $t0, $t0, 1
			j printRawLoop
exitPrintMat: 		jr $ra			
			
			
			
			
