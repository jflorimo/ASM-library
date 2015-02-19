section .text
	global _ft_toupper

_ft_toupper:
	mov r10, rdi
	cmp r10, 97
	jl _returnchar
	cmp r10, 122
	jg _returnchar
	jmp _returnLowerchar

_returnLowerchar:
	sub r10, 32
	jmp _returnchar

_returnchar:
	mov rax, r10
	ret