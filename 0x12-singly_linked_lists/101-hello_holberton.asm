	global main
	extern printf

	section .data
	hello db 'Hello, Holberton', 0
	fmt db '%s\n', 0

	section .text
main:
	;;  Prepare arguments for printf
	mov rdi, fmt
	mov rsi, hello
	xor rax, rax 	; Clear RAX
	call printf	; Call printf function

	;;  Return 0 to indicate successful execution
	xor rax, rax
	ret
	
