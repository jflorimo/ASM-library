section .text
	global _ft_tolower

_ft_tolower:
	mov r10, rdi
	cmp r10, 65
	jl _returnchar
	cmp r10, 90
	jg _returnchar
	jmp _returnLowerchar

_returnLowerchar
	add r10, 32
	jmp _returnchar

_returnchar:
	mov rax, r10
	ret