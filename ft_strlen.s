section .text
	global _ft_strlen

_ft_strlen:
	mov r11, rdi
	mov rcx, -1
	;not rcx
	cld
	mov al, 0
	repnz scasb
	sub rdi, r11
	dec rdi
	mov rax, rdi
	ret