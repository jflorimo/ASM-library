section .text
	global _ft_strcat

_ft_strcat:
	mov r10, rdi

_begin:
	cmp byte[rdi], 0
	je _startcopy
	inc rdi
	jmp _begin

_startcopy:
	cmp byte[rsi], 0
	je _endfunction
	mov r11b, byte[rsi]
	mov byte[rdi], r11b
	inc rdi
	inc rsi
	jmp _startcopy

_endfunction:
	mov byte [rdi], 0
	mov rax, r10
	ret
