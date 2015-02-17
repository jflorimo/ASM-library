extern		_ft_isdigit
extern		_ft_isalpha

section	.text
	global _ft_isalnum

_ft_isalnum:
	call _ft_isdigit
	cmp rax, 1
	je _retunvalueok
	call _ft_isalpha
	cmp rax, 1
	je _retunvalueok
	jmp _retunvaluenok

_retunvalueok:
	mov rax, 1
	ret

_retunvaluenok:
	mov rax, 0
	ret