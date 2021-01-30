	.cpu arm7tdmi
	.eabi_attribute 23, 1
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"WarioSpeedResetWithCondCheck.c"
	.text
	.align	1
	.p2align 2,,3
	.global	WarioSpeedResetWithCondCheck
	.arch armv4t
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	WarioSpeedResetWithCondCheck, %function
WarioSpeedResetWithCondCheck:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
	.syntax divided
@ 46 "G:/under making level/WarioSpeedResetWithCondCheck.c" 1
	mov r3, r4
	
@ 0 "" 2
	.thumb
	.syntax unified
	ldr	r2, .L14
	ldrb	r2, [r2]
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	cmp	r2, #0
	bne	.L2
	ldr	r2, .L14+4
	ldrb	r2, [r2]
	cmp	r2, #4
	beq	.L13
.L2:
	ldr	r3, .L14+8
	bl	.L16
.L3:
	movs	r2, #0
	ldr	r3, .L14+12
	str	r2, [r3]
	ldr	r3, .L14+16
	ldr	r1, .L14+20
	str	r2, [r3]
	ldr	r3, [r1]
	lsls	r3, r3, #16
	lsrs	r3, r3, #16
	cmp	r3, #4
	beq	.L1
	ldr	r3, .L14+24
	str	r2, [r1]
	str	r2, [r3]
.L1:
	@ sp needed
	pop	{r4}
	pop	{r0}
	bx	r0
.L13:
	ldr	r2, .L14+28
	ldrb	r2, [r2]
	cmp	r3, #38
	bne	.L2
	cmp	r2, #4
	bne	.L2
	b	.L3
.L15:
	.align	2
.L14:
	.word	50337944
	.word	50337945
	.word	134282537
	.word	50338096
	.word	50338100
	.word	50338112
	.word	50338116
	.word	50338120
	.size	WarioSpeedResetWithCondCheck, .-WarioSpeedResetWithCondCheck
	.ident	"GCC: (GNU Arm Embedded Toolchain 9-2020-q2-update) 9.3.1 20200408 (release)"
	.code 16
	.align	1
.L16:
	bx	r3
