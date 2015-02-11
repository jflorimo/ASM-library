section	.text
	global _ft_puts

_ft_puts:
	mov r10, rdi

looper:
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rsi, r10
	mov		rdx, 1
	syscall
	inc r10
	cmp byte [r10], 0
	jne looper
	ret
	