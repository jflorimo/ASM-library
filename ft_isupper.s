section .text
	global _ft_isupper

_ft_isupper:
	cmp rdi, 'A'
	jb _retunvaluenok
	cmp rdi, 'Z'
	jbe _retunvalueok
	jmp _retunvaluenok

_retunvalueok:
	mov rax, 1
	ret

_retunvaluenok:
	mov rax, 0
	ret