.section	.text
.globl		compare_and_swap
.type		compare_and_swap,	@function

// 1. *ptr  	%rdi
// 2. expected 	%esi
// 3. new_value %edx
// cmpxchg desc: https://www.felixcloutier.com/x86/cmpxchg
compare_and_swap:
    movl		%esi,		%eax
    lock cmpxchg	%edx,		(%rdi)	
    ret

