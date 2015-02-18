section .text
	global _ft_memcpy

_ft_memcpy:
	mov rcx, rdx
	mov r11, rdi
	cld
	rep movsb
	mov rax, r11
	ret