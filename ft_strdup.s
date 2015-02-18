section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen

_ft_strdup:
	xor rax, rax ;priotection pour initialier rax(al) a 0

	mov r13, rdi
	call _ft_strlen
	inc rax; inc_for_0
	mov r12, rax ;stock la longeur

	mov rdi, r12
	call _malloc

	test rax, rax
	je _returnnull

	mov r14, rax ; stcok pointeur sur le debut
	mov rdi, rax ; stock resultat de malloc dans rdi pour copie
	mov rsi, r13; chaine a copier
	
	mov rcx, r12 ; lentgh
	cld
	rep movsb

	mov rax, r14

	ret

_returnnull:
	ret