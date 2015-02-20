section .text
	global _ft_strncpy

_ft_strncpy:
	mov rcx, rdx
	mov r10, rdi

	cld
	rep movsb

	mov rax, r10
	ret
