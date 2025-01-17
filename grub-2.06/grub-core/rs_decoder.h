	.file	"reed_solomon.c"
	.text
	.type	pol_evaluate, @function
pol_evaluate:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	movl	%eax, %ebx
	movl	%ecx, %edi
	movl	%edx, %esi
	xorl	%edx, %edx
	xorl	%eax, %eax
.L2:
	testl	%esi, %esi
	js	.L11
	movzbl	(%ebx,%esi), %ecx
	testb	%cl, %cl
	je	.L3
	movzbl	1049088(%ecx), %ecx
	xorb	1048576(%edx,%ecx), %al
.L3:
	addl	%edi, %edx
	cmpl	$254, %edx
	jle	.L4
	subl	$255, %edx
.L4:
	decl	%esi
	jmp	.L2
.L11:
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	pol_evaluate, .-pol_evaluate
	.type	gf_mul, @function
gf_mul:
	testb	%dl, %dl
	je	.L14
	testb	%al, %al
	je	.L14
	movzbl	%al, %eax
	movzbl	1049088(%eax), %ecx
	movzbl	%dl, %edx
	movzbl	1049088(%edx), %eax
	movb	1048576(%ecx,%eax), %al
	ret
.L14:
	xorl	%eax, %eax
	ret
	.size	gf_mul, .-gf_mul
	.type	gauss_solve.constprop.0, @function
gauss_solve.constprop.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	%eax, -40(%ebp)
	movl	%edx, -28(%ebp)
	movl	%ecx, -44(%ebp)
	xorl	%eax, %eax
.L16:
	cmpl	-40(%ebp), %eax
	jge	.L42
	movl	$-1, 1049344(,%eax,4)
	incl	%eax
	jmp	.L16
.L42:
	xorl	%eax, %eax
.L18:
	cmpl	-28(%ebp), %eax
	jge	.L43
	movl	-44(%ebp), %edi
	movb	$0, (%edi,%eax)
	incl	%eax
	jmp	.L18
.L43:
	movl	-28(%ebp), %eax
	incl	%eax
	movl	%eax, -36(%ebp)
	xorl	%ecx, %ecx
	movl	$0, -32(%ebp)
.L20:
	movl	-32(%ebp), %edi
	cmpl	%edi, -40(%ebp)
	jle	.L31
	xorl	%ebx, %ebx
.L32:
	cmpl	%ebx, -28(%ebp)
	jle	.L21
	cmpb	$0, 1052672(%ebx,%ecx)
	jne	.L23
	incl	%ebx
	jmp	.L32
.L21:
	jne	.L23
.L30:
	incl	-32(%ebp)
	addl	-36(%ebp), %ecx
	jmp	.L20
.L23:
	movl	-32(%ebp), %eax
	movl	%ebx, 1049344(,%eax,4)
	movzbl	1052672(%ebx,%ecx), %eax
	movzbl	1049088(%eax), %edx
	movl	$255, %eax
	subl	%edx, %eax
	xorl	%esi, %esi
	leal	1052672(%ecx), %edi
	movl	%edi, -48(%ebp)
	movzbl	1048576(%eax), %edx
.L24:
	cmpl	%esi, -28(%ebp)
	jl	.L44
	movl	%ecx, -56(%ebp)
	movl	-48(%ebp), %eax
	leal	(%eax,%esi), %edi
	movzbl	(%edi), %eax
	movl	%edx, -52(%ebp)
	call	gf_mul
	movb	%al, (%edi)
	incl	%esi
	movl	-56(%ebp), %ecx
	movl	-52(%ebp), %edx
	jmp	.L24
.L44:
	movl	-32(%ebp), %eax
	incl	%eax
	movl	%eax, -48(%ebp)
	movl	-36(%ebp), %eax
	leal	(%ecx,%eax), %edi
.L26:
	movl	-48(%ebp), %esi
	cmpl	%esi, -40(%ebp)
	je	.L30
	xorl	%esi, %esi
	movzbl	1052672(%ebx,%edi), %edx
	leal	1052672(%edi), %eax
	movl	%eax, -52(%ebp)
.L27:
	cmpl	%esi, -28(%ebp)
	jl	.L45
	movzbl	1052672(%esi,%ecx), %eax
	movl	%ecx, -60(%ebp)
	movl	%edx, -56(%ebp)
	call	gf_mul
	movl	-52(%ebp), %edx
	xorb	%al, (%edx,%esi)
	incl	%esi
	movl	-60(%ebp), %ecx
	movl	-56(%ebp), %edx
	jmp	.L27
.L45:
	incl	-48(%ebp)
	addl	-36(%ebp), %edi
	jmp	.L26
.L31:
	movl	-40(%ebp), %esi
	decl	%esi
	movl	-36(%ebp), %ebx
	imull	%esi, %ebx
	addl	-28(%ebp), %ebx
.L33:
	testl	%esi, %esi
	js	.L46
	movl	1049344(,%esi,4), %edi
	cmpl	$-1, %edi
	je	.L34
	movl	%ebx, %eax
	subl	-28(%ebp), %eax
	movl	%eax, -36(%ebp)
	movb	$0, -32(%ebp)
	xorl	%ecx, %ecx
.L35:
	cmpl	%ecx, -28(%ebp)
	jle	.L47
	movl	-44(%ebp), %eax
	movzbl	(%eax,%ecx), %edx
	movl	-36(%ebp), %eax
	movzbl	1052672(%ecx,%eax), %eax
	movl	%ecx, -40(%ebp)
	call	gf_mul
	xorb	%al, -32(%ebp)
	movl	-40(%ebp), %ecx
	incl	%ecx
	jmp	.L35
.L47:
	movb	-32(%ebp), %al
	xorb	1052672(%ebx), %al
	movl	-44(%ebp), %ecx
	movb	%al, (%ecx,%edi)
.L34:
	decl	%esi
	subl	-28(%ebp), %ebx
	decl	%ebx
	jmp	.L33
.L46:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	gauss_solve.constprop.0, .-gauss_solve.constprop.0
	.globl	grub_reed_solomon_recover
	.type	grub_reed_solomon_recover, @function
grub_reed_solomon_recover:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	%eax, -68(%ebp)
	movl	%edx, -36(%ebp)
	movl	%ecx, -32(%ebp)
	testl	%ecx, %ecx
	je	.L48
	addl	%edx, %eax
	movl	%eax, -44(%ebp)
	leal	-1(%eax,%ecx), %ecx
	movl	%ecx, %eax
.L50:
	cmpl	-44(%ebp), %eax
	jb	.L51
	cmpb	$0, (%eax)
	jne	.L51
	decl	%eax
	jmp	.L50
.L51:
	subl	%eax, %ecx
	movl	$2, %ebx
	movl	-32(%ebp), %eax
	cltd
	idivl	%ebx
	cmpl	%eax, %ecx
	jg	.L48
	movb	$0, 1049088
	movl	$1048576, %edx
	movb	$1, %al
.L56:
	movb	%al, (%edx)
	movb	%al, 255(%edx)
	movzbl	%al, %ecx
	movb	%dl, 1049088(%ecx)
	testb	%al, %al
	jns	.L54
	leal	(%ecx,%ecx), %eax
	xorl	$29, %eax
	jmp	.L55
.L54:
	sall	%eax
.L55:
	incl	%edx
	cmpl	$1048831, %edx
	jne	.L56
.L57:
	cmpl	$0, -36(%ebp)
	je	.L48
	movl	-36(%ebp), %ecx
	addl	-32(%ebp), %ecx
	cmpl	$102400, %ecx
	jbe	.L87
	imull	$200, -36(%ebp), %eax
	xorl	%edx, %edx
	divl	%ecx
	sall	$9, %eax
	movl	%eax, -48(%ebp)
	imull	$200, -32(%ebp), %eax
	xorl	%edx, %edx
	divl	%ecx
	sall	$9, %eax
	movl	%eax, -52(%ebp)
	jmp	.L58
.L87:
	movl	-32(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -48(%ebp)
.L58:
	movl	$511, -64(%ebp)
	movl	$0, -56(%ebp)
.L61:
	movl	-48(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	-52(%ebp), %edx
	addl	-64(%ebp), %edx
	cmpl	$511, %edx
	jbe	.L59
	cmpl	$511, %eax
	jbe	.L59
	shrl	$9, %eax
	movl	%eax, -40(%ebp)
	movl	-68(%ebp), %eax
	addl	-56(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	%eax, %ecx
	xorl	%eax, %eax
	jmp	.L60
.L99:
	movl	%edx, %edi
	shrl	$10, %edi
	xorl	%ebx, %ebx
	movl	-40(%ebp), %eax
	movl	-28(%ebp), %esi
	leal	-1(%eax,%esi), %esi
.L66:
	movl	%ebx, %ecx
	movl	%esi, %edx
	movl	$1052160, %eax
	call	pol_evaluate
	movb	%al, 1051904(%ebx)
	incl	%ebx
	cmpl	%ebx, -28(%ebp)
	jg	.L66
	xorl	%eax, %eax
.L69:
	cmpb	$0, 1051904(%eax)
	jne	.L70
	incl	%eax
	cmpl	%eax, -28(%ebp)
	jg	.L69
	jne	.L70
.L85:
	xorl	%eax, %eax
.L71:
	movb	1052160(%eax), %dl
	movl	-60(%ebp), %edi
	movb	%dl, (%edi)
	incl	%eax
	addl	$512, -60(%ebp)
	cmpl	%eax, -40(%ebp)
	jg	.L71
.L59:
	incl	-56(%ebp)
	decl	-64(%ebp)
	cmpl	$512, -56(%ebp)
	jne	.L61
	movl	-48(%ebp), %ebx
	addl	%ebx, -68(%ebp)
	movl	-52(%ebp), %edi
	addl	%edi, -44(%ebp)
	subl	%ebx, -36(%ebp)
	subl	%edi, -32(%ebp)
	jmp	.L57
.L60:
	cmpl	-40(%ebp), %eax
	jge	.L98
	movb	(%ecx), %bl
	movb	%bl, 1052160(%eax)
	incl	%eax
	addl	$512, %ecx
	jmp	.L60
.L98:
	movl	%edx, %eax
	shrl	$9, %eax
	movl	%eax, -28(%ebp)
	movl	-44(%ebp), %ecx
	addl	-56(%ebp), %ecx
	xorl	%eax, %eax
.L64:
	cmpl	-28(%ebp), %eax
	jge	.L99
	movb	(%ecx), %bl
	movl	-40(%ebp), %esi
	movb	%bl, 1052160(%esi,%eax)
	incl	%eax
	addl	$512, %ecx
	jmp	.L64
.L70:
	leal	1(%edi), %esi
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	jmp	.L68
.L72:
	movb	1051904(%edx,%eax), %bl
	movb	%bl, 1052672(%eax,%ecx)
	incl	%eax
	cmpl	%edi, %eax
	jle	.L72
	incl	%edx
	addl	%esi, %ecx
.L68:
	xorl	%eax, %eax
	cmpl	%edi, %edx
	jl	.L72
.L73:
	cmpl	%eax, %edi
	jle	.L100
	movb	$0, 1050368(%eax)
	incl	%eax
	jmp	.L73
.L100:
	movl	$1050368, %ecx
	movl	%edi, %edx
	movl	%edi, %eax
	call	gauss_solve.constprop.0
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	movl	-40(%ebp), %eax
	addl	-28(%ebp), %eax
	movl	%eax, -72(%ebp)
	decl	%eax
	movl	%eax, -80(%ebp)
.L75:
	movl	%ebx, -76(%ebp)
	cmpl	-72(%ebp), %esi
	jge	.L101
	movl	$255, %ecx
	subl	%esi, %ecx
	leal	-1(%edi), %edx
	movl	$1050368, %eax
	call	pol_evaluate
	cmpb	1048576(%esi), %al
	jne	.L76
	movb	%al, 1050624(%ebx)
	incl	%ebx
	movl	-80(%ebp), %eax
	subl	%esi, %eax
	movl	-76(%ebp), %edx
	movl	%eax, 1050880(,%edx,4)
.L76:
	incl	%esi
	jmp	.L75
.L101:
	xorl	%eax, %eax
.L78:
	cmpl	%eax, %ebx
	je	.L102
	movb	$1, 1052672(%eax)
	incl	%eax
	jmp	.L78
.L102:
	movb	1051904, %al
	movb	%al, 1052672(%ebx)
	leal	1(%ebx), %ecx
	leal	(%ebx,%ebx), %eax
	movl	%eax, -72(%ebp)
	movl	%ecx, -76(%ebp)
	movl	$0, -80(%ebp)
	movl	$1, %edi
.L80:
	cmpl	%edi, -28(%ebp)
	jle	.L103
	xorl	%esi, %esi
.L82:
	cmpl	%esi, %ebx
	je	.L104
	movl	%ecx, -84(%ebp)
	movl	-80(%ebp), %eax
	movzbl	1052672(%eax,%esi), %edx
	movzbl	1050624(%esi), %eax
	call	gf_mul
	movl	-76(%ebp), %edx
	movb	%al, 1052672(%esi,%edx)
	incl	%esi
	movl	-84(%ebp), %ecx
	jmp	.L82
.L104:
	movb	1051904(%edi), %al
	movl	-72(%ebp), %esi
	movb	%al, 1052673(%esi)
	incl	%edi
	addl	%ecx, -72(%ebp)
	addl	%ecx, -80(%ebp)
	addl	%ecx, -76(%ebp)
	jmp	.L80
.L103:
	movl	$1052416, %ecx
	movl	%ebx, %edx
	movl	-28(%ebp), %eax
	call	gauss_solve.constprop.0
	xorl	%eax, %eax
.L83:
	cmpl	%eax, %ebx
	je	.L85
	movl	1050880(,%eax,4), %edx
	movb	1052416(%eax), %cl
	xorb	%cl, 1052160(%edx)
	incl	%eax
	jmp	.L83
.L48:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	grub_reed_solomon_recover, .-grub_reed_solomon_recover
	.section	.note.GNU-stack,"",@progbits
