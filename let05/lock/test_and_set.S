.section 	.text
.globl 		test_and_set
.type 		test_and_set, 	@function
test_and_set:
    movl	%esi,		%eax
    lock xchg	(%rdi),		%eax
    ret
