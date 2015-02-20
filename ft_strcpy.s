extern _ft_strlen
extern _ft_memcpy

section .text
	global _ft_strcpy

_ft_strcpy:
	mov		r12, rdi
	mov		rdi, rsi
	call	_ft_strlen
	mov		rdx, rax
	mov		rdi, r12
	call	_ft_memcpy
	ret