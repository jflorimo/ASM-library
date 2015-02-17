section .text
	global _ft_isprint

_ft_isprint:
	mov r10, rdi
	cmp r10, 32
	jae _ischar
	jmp _retunvaluenok

_ischar:
	cmp r10, 126
	jle _retunvalueok
	jmp _retunvaluenok

_retunvalueok:
	mov rax, 1
	ret

_retunvaluenok:
	mov rax, 0
	ret