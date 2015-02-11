section .data
	msg db 10

section	.text
	global _ft_puts

_ft_puts:
	mov r10, rdi
	mov r11, 0

_count:
	cmp byte[r10 + r11], 0
	je _loop
	inc r11
	jmp _count

_loop:
	cmp r11, 0
	je _returnchar
	jmp _displayword


_displayword:
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rsi, r10
	mov		rdx, r11
	syscall
	jmp _returnchar

_returnchar:
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rsi, msg
	mov		rdx, 1
	syscall
	mov rax, 1
	ret
