section .text
	global _ft_memset

_ft_memset:
	mov r11, rdi; stock le premier param
	mov rcx, rdx; stock 3eme(len) param dans rcx pour stosb 
	mov rax, rsi; stock le 2eme param(char) pour ecrire dans rdi avec stosb
	cld
	rep stosb
	mov rax, r11
	ret

