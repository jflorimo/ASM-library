section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 'a'
	jb _retunvaluenok
	cmp rdi, 'z'
	jbe _retunvalueok
	jmp _retunvaluenok

_retunvalueok:
	mov rax, 1
	ret

_retunvaluenok:
	mov rax, 0
	ret