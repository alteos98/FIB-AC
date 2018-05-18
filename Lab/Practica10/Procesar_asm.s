.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo

	movl 8(%ebp), %eax #eax=@mata
	movl 12(%ebp), %ebx #ebx=@matb
	movl 16(%ebp), %ecx #ecx=@matc
	movl 20(%ebp), %edi #edi=n
	imul %edi, %edi #edi=n*n
	movl $0, %esi #esi lo usaremos como contador

for:
	cmpl %esi, %edi
	je fi_for
	movb (%eax, %esi), %dl
	subb (%ebx, %esi), %dl

if:
	cmpb $0, %dl
	jle else
	movb $255, (%ecx, %esi)
	jmp fi_if

else:
	movb $0, (%ecx, %esi)

fi_if:
	incl %esi #++contador
	jmp for
	
fi_for:

# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
