.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo

    movl $1, -8(%ebp)

for:
    movl -8(%ebp), %ecx
    cmpl %ecx, 12(%ebp)
    jle fi_for
    
if:
    movl -8(%ebp), %edx
    movl 8(%ebp), %ecx
    movl -4(%ebp), %eax
    cmpl (%ecx, %edx, 4), %eax
    jle fi_if
    movl (%ecx, %edx, 4), %ecx
    movl %ecx, -4(%ebp)
    
fi_if:
    incl -8(%ebp)
    jmp for
    
fi_for:
    movl -4(%ebp), %eax

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
