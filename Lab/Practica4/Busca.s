 .text
	.align 4
	.globl Buscar
	.type Buscar,@function
Buscar:
        pushl %ebp
        movl $1, -4(%ebp) # trobat = -1
        movl $0, -16(%ebp) # low = 0
        movl $0, -8(%ebp) # mid = low
        movl 24(%ebp), %eax 
        movl %eax, -12(%ebp) #high = N
        addl $-1, -12(%ebp) #high = n-1
while:
        movl -16(%ebp), %ecx #cargo low
        cmpl %ecx, -12(%ebp) # high - low
        jl fi_while
        pushl 32(%ebp) # primer parametre: v
        pushl 20(%ebp) # segon parametre: X
        pushl 24(%ebp)
        pushl 28(%ebp)
        leal 16(%ebp), %ecx # tercer parametro
        pushl %ecx
        leal 12(%ebp), % ecx # cuarto parametro: high
        pushl %ecx
        leal 8(%ebp). %ecx #quinto elemento: low
        call BuscarElemento
        cmpl $0, %eax 
        jl while
fi_while:
        movl %ebp, %esp
        popl %ebp
        ret 
        
        
        
        
        
