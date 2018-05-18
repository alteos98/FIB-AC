.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo
    movl $0, -4(%ebp) 
    movl $0, -8(%ebp)
for1:
    cmpl $3, -8(%ebp)
    jle fi_for1
    movl $0, -12(%ebp)
for2:
    cmpl $3, -12(%ebp)
    je fi_for2
    #Cuerpo del for 2
    movl 8(%ebp), %ecx
    movl -8(%ebp), %edx
    imul $16, %edx
    movl (%ecx, %edx) , %ecx
    addl -12(%ebp), %ecx
    subl %ecx, -4(%ebp)
    incl -12(%ebp)
    jmp for2
fi_for2:
    movl 12(%ebp), %ecx
    addl %ecx, -8(%ebp)
    jmp for1
fi_for1:


# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
