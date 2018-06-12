.data
msgNewline: .asciiz "\n"
msgAskForNumOfCoords: .asciiz "Enter number of coords: "
msgAskForCoords1: .asciiz "Please input coords for vector 1: \n"
msgAskForCoords2: .asciiz "Please input coords for vector 2: \n"
msgPrintOrderV1: .asciiz "Order vector 1: "
msgPrintOrderV2: .asciiz "Order vector 2: "
msgPrintValueV1: .asciiz "Value vector 1: "
msgPrintValueV2: .asciiz "Value vector 2: "
msgPrintScalar: .asciiz "Scalar = "
msgPrintSpace: .asciiz " "
.text

#get number of coords:
			la $a0, msgAskForNumOfCoords
			li $v0, 4
			syscall
			li $v0, 5
			syscall
			move $s5, $v0 # $s5 stores n
	
			mul $a0, $s5, 4	 	    #writes number of elements as parameter
			jal bookMem  		    #gets memory for first vector
			move $s7, $v0               #$s7 stores pointer to first sparce vector
	
			jal bookMem		    #gets memory for second vector
			move $s6, $v0		    #$s6 stores pointer to second sparse vector
	
			li $v0, 4
			la $a0, msgAskForCoords1
			syscall
	
			move $a0, $s7
			move $a1, $s5
			jal readCoords  	    #reads coords for the first vector
			move $s4, $v0	 	
	
			li $v0, 4
			la $a0, msgAskForCoords2
			syscall
	
			move $a0, $s6
			jal readCoords		    #reads coords for the second vector
			move $s3, $v0
	
			move $a0, $s5 		    #loads number of baits to book
			jal bookMem		    #gets memory for first order vector
			move $s2, $v0               #$s2 stores pointer to first order vector
	
			jal bookMem		    #gets memory for second order vector
			move $s1, $v0               #$s1 stores pointer to second order vector
	
			move $t9, $s4		    #stores size of vector value1 in $t9
			move $t8, $s3	            #stores size of vector value2 in $t8
	
			mul $a0, $s4, 4
			jal bookMem		    #gets memory for first value vector
			move $s4, $v0               #s4 stores pointer for first value vector
	
			mul $a0, $s3, 4
			jal bookMem		    #gets memory for second value vector
			move $s3, $v0               #s3 stores pointer for second value vector
	
			move $a0, $s7
			move $a1, $s4
			move $a2, $s2
			jal fillValueAndOrder       # fills arrays for first vector		    

			move $a0, $s6
			move $a1, $s3
			move $a2, $s1
			jal fillValueAndOrder       # fills arrays for second vector
	
			la $a0, msgPrintValueV1
			li $v0, 4
			syscall
	
			move $a0, $s4
			move $a1, $t9
			jal printVector
	
			la $a0, msgPrintValueV2
			li $v0, 4
			syscall
	
			move $a0, $s3
			move $a1, $t8
			jal printVector
	
			la $a0, msgPrintScalar
			li $v0, 4
			syscall
	
			move $a0, $s4
			move $a1, $s3
			move $a2, $s2
			move $a3, $s1
			jal calcScalar              # calculates scalar
	
			move $a0, $v0
			li $v0, 1
			syscall                     # prints scalar
	
			li $v0, 10
			syscall                     # quit
###

#book memory
bookMem:		li $v0, 9
			syscall
			jr $ra

#read coords into booked memory
readCoords:		add $t0, $zero, $zero # $t0 counts stored elements i=0
			add $t1, $zero, $zero # $t1 counts non-zero elements j=0
			move $t2, $a0         # $t2 stores current position in array
getVectorLoop:		li $v0, 5
			syscall		      #reads coord
			sw $v0, ($t2)         #stores coord in array
			beqz $v0, continue
			addi $t1, $t1, 1      #increment if non-zero j++
continue:		addi $t2, $t2, 4      #increments position in array
			addi $t0, $t0, 1      # i++
			blt $t0, $a1, getVectorLoop # if i<n continue loop
			move $v0, $t1
			jr $ra

#fill valueVec and orderVec
fillValueAndOrder:	addi $t0, $zero, 0  #counts elements of vector
			move $t1, $a0 # $t1 points to current position of vector array
			move $t2, $a1 # $t2 points to current position of valueVec
			move $t3, $a2 # $t3 points to current position of orderVec
			addi $t4, $zero, 1 # $t4 always store 1
fillLoop:		lw $t5, ($t1) # loads content of vector array
			sb $zero, ($t3) #fill orderVec
			beqz $t5, skipAssigning
			sw $t5, ($t2) #fill valueVec
			sb $t4, ($t3) #corrects orderVec
			addi $t2, $t2, 4 #increments position of valueVec
skipAssigning:		addi $t3, $t3, 1 #increments position of orderVec
			addi $t0, $t0, 1 #increments loop counter
			addi $t1, $t1, 4 #increments position of vector array
			blt $t0, $s5, fillLoop
			jr $ra

#calculate scalar
calcScalar:		add $v0, $zero, $zero # stores scalar
			add $t0, $zero, $zero  # loop counter i
			move $t1, $a0 # copies pointer to value1
			move $t2, $a1 # copies pointer to value2
			move $t3, $a2 # copies pointer to order1
			move $t4, $a3 # copies pointer to order2
loopScalar:		lb $t5, ($t3)
			lb $t6, ($t4)
			bnez $t5, condB
			condA:
			bnez $t6, Branch2
Branch1:		j loopIncrementAtTheEnd
Branch2:		addi $t2, $t2, 4 # increment pointer to value2
			j loopIncrementAtTheEnd
condB:			bnez $t6, Branch3
Branch4:		addi $t1, $t1, 4 # increment pointer to value1
			j loopIncrementAtTheEnd
Branch3:         	lw $t5, ($t1)
			lw $t6, ($t2)
			mul $t7, $t5, $t6
			add $v0, $v0, $t7
			addi $t1, $t1, 4 # increment pointer to value1
			addi $t2, $t2, 4 # increment pointer to value2
loopIncrementAtTheEnd:	addi $t3, $t3, 1 # increment pointer to order1
			addi $t4, $t4, 1 # increment pointer to order2
			addi $t0, $t0, 1 # increment loop counter
			blt $t0, $s5, loopScalar
			jr $ra

#print vector
printVector:		add $t0, $zero, $zero # loop counter
			add $t1, $zero, $a0   # pointer to vector
printVectorLoop:	lw $a0, ($t1)
			li $v0, 1
			syscall
			la $a0, msgPrintSpace
			li $v0, 4
			syscall
			addi $t1, $t1, 4
			addi $t0, $t0, 1
			blt $t0, $a1, printVectorLoop
			la $a0, msgNewline
			li $v0, 4
			syscall
			jr $ra
