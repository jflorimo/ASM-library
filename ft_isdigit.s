section	.text
	global _ft_isdigit

_ft_isdigit:
	mov r12, rdi
	cmp r12, 48
	jl _retunvaluenok

	cmp r12, 57
	jg _retunvaluenok

	jmp _retunvalueok

_retunvalueok:
	mov rax, 1
	ret

_retunvaluenok:
	mov rax, 0
	ret