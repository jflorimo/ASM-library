section .text
	global _ft_isascii

_ft_isascii:
	mov r10, rdi
	cmp r10, 0
	jae _ischar
	jmp _retunvaluenok

_ischar:
	cmp r10, 127
	jle _retunvalueok
	jmp _retunvaluenok

_retunvalueok:
	mov rax, 1
	ret

_retunvaluenok:
	mov rax, 0
	ret