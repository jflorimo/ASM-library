section .text
	global _ft_strchr

_ft_strchr:
	mov r12, rdi

loop:
	cmp byte [rdi], 0
	je _returnnull
	cmp byte [rdi], sil; lower 8bytes of rsi
	je _return
	inc rdi
	jmp loop

_return:
	mov rax, rdi
	mov rdi, r12
	ret

_returnnull:
	mov rax, 0
	ret