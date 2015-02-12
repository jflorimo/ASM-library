section	.text
	global _ft_isdigit

_ft_isdigit:
	mov r10, rdi
	cmp r10, 48
	jge _greaterthanzero


_greaterthanzero:
	cmp r10, 57
	jg _retunvaluenok
	jmp _retunvalueok

_retunvalueok:
	mov rax, 1
	ret

_retunvaluenok:
	mov rax, 0
	ret