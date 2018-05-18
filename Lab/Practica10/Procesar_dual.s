.text
	.align 4
	.globl procesar
	.type	procesar, @function
.data
	zeros: .byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

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
	movl $16, %esi #esi lo usaremos como contador
	movl $0, %edx
	divl %esi
	cmp $0, %edx
	jne forunaligned
    movl 8(%ebp), %eax #eax=@mata
    movl $0, %esi #esi lo usaremos como contador
    
    
foraligned1:
	cmpl %esi, %edi
	je fi_for

	movdqa (%eax, %esi), %xmm1
	movdqa (%ebx, %esi), %xmm2
	psubb %xmm2, %xmm1
	pcmpgtb zeros, %xmm1
	movdqa %xmm1, (%ecx, %esi)
	addl $16, %esi #++contador
	jmp foraligned1

forunaligned:
    movl 8(%ebp), %eax #eax=@mata
    movl $0, %esi #esi lo usaremos como contador
forunaligned1:
	cmpl %esi, %edi
	je fi_for

	movdqu (%eax, %esi), %xmm1
	movdqu (%ebx, %esi), %xmm2
	psubb %xmm2, %xmm1
	pcmpgtb zeros, %xmm1
	movdqu %xmm1, (%ecx, %esi)
	addl $16, %esi #++contador
	jmp forunaligned1 
	
fi_for:

# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
