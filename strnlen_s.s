	.file	"strnlen_s.c"
	.text
	.globl	strnlen_s
	.def	strnlen_s;	.scl	2;	.type	32;	.endef
	.seh_proc	strnlen_s
strnlen_s:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	cmpq	$0, 16(%rbp)
	jne	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	movq	$0, -8(%rbp)
	jmp	.L4
.L6:
	addq	$1, -8(%rbp)
.L4:
	movq	-8(%rbp), %rax
	cmpq	24(%rbp), %rax
	jnb	.L5
	movq	16(%rbp), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L6
.L5:
	movq	-8(%rbp), %rax
.L3:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 7.4.0"
