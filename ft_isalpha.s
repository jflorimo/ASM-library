section .text
	global _ft_isalpha

_ft_isalpha:
	mov r10, rdi
	cmp r10, 122
	jbe _smallerthanAs
	jmp _retunvaluenok

_smallerthanAs:
	cmp r10, 97
	jge _retunvalueok
	jmp _greaterthanA

_greaterthanA:
	cmp r10, 65
	jge _smallerthanZ
	jmp _retunvaluenok

_smallerthanZ:
	cmp r10, 90
	jle _retunvalueok
	jmp _retunvaluenok

_retunvalueok:
	mov rax, 1
	ret

_retunvaluenok:
	mov rax, 0
	ret