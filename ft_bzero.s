section .text
	global _ft_bzero

_ft_bzero:
	cmp rsi, 0
	je _returnvalue
	mov byte[rdi + rsi - 1 ], 0
	dec rsi
	jmp	_ft_bzero

_returnvalue:
	ret