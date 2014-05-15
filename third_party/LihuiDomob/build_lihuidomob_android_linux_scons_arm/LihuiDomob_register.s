	.arch armv5te
	.eabi_attribute 27, 3
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"LihuiDomob_register.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.rodata
	.align	2
.LC0:
	.ascii	"LIHUIDOMOB_VERBOSE\000"
	.align	2
.LC1:
	.ascii	"calling LihuiDomob func on main thread: initDoAd\000"
	.section	.text._ZL13initDoAd_wrapv,"ax",%progbits
	.align	2
	.type	_ZL13initDoAd_wrapv, %function
_ZL13initDoAd_wrapv:
.LFB33:
	.file 1 "D:\\10kgratExtension\\ExMarmalade\\Project\\2048Test\\third_party\\LihuiDomob\\source\\generic\\LihuiDomob_register.cpp"
	.loc 1 28 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 28 0
	ldr	r4, .L3
.LPIC3:
	add	r4, pc, r4
	.loc 1 29 0
	ldr	r3, .L3+4
.LPIC0:
	add	r3, pc, r3
	mov	r0, r3
	mov	r1, #1
	bl	IwDebugTraceIsChannelOn(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L2
	.loc 1 29 0 is_stmt 0 discriminator 1
	ldr	r3, .L3+8
.LPIC1:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L3+12
.LPIC2:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L2:
	.loc 1 30 0 is_stmt 1
	ldr	r3, .L3+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 31 0
	ldmfd	sp!, {r4, pc}
.L4:
	.align	2
.L3:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC3+8)
	.word	.LC0-(.LPIC0+8)
	.word	.LC0-(.LPIC1+8)
	.word	.LC1-(.LPIC2+8)
	.word	initDoAd(GOT)
	.cfi_endproc
.LFE33:
	.size	_ZL13initDoAd_wrapv, .-_ZL13initDoAd_wrapv
	.section	.rodata
	.align	2
.LC2:
	.ascii	"calling LihuiDomob func on main thread: showDoBanne"
	.ascii	"r\000"
	.section	.text._ZL17showDoBanner_wrapv,"ax",%progbits
	.align	2
	.type	_ZL17showDoBanner_wrapv, %function
_ZL17showDoBanner_wrapv:
.LFB34:
	.loc 1 34 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 34 0
	ldr	r4, .L7
.LPIC7:
	add	r4, pc, r4
	.loc 1 35 0
	ldr	r3, .L7+4
.LPIC4:
	add	r3, pc, r3
	mov	r0, r3
	mov	r1, #1
	bl	IwDebugTraceIsChannelOn(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L6
	.loc 1 35 0 is_stmt 0 discriminator 1
	ldr	r3, .L7+8
.LPIC5:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L7+12
.LPIC6:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L6:
	.loc 1 36 0 is_stmt 1
	ldr	r3, .L7+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 37 0
	ldmfd	sp!, {r4, pc}
.L8:
	.align	2
.L7:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC7+8)
	.word	.LC0-(.LPIC4+8)
	.word	.LC0-(.LPIC5+8)
	.word	.LC2-(.LPIC6+8)
	.word	showDoBanner(GOT)
	.cfi_endproc
.LFE34:
	.size	_ZL17showDoBanner_wrapv, .-_ZL17showDoBanner_wrapv
	.section	.rodata
	.align	2
.LC3:
	.ascii	"calling LihuiDomob func on main thread: showDoInter"
	.ascii	"\000"
	.section	.text._ZL16showDoInter_wrapv,"ax",%progbits
	.align	2
	.type	_ZL16showDoInter_wrapv, %function
_ZL16showDoInter_wrapv:
.LFB35:
	.loc 1 40 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 40 0
	ldr	r4, .L11
.LPIC11:
	add	r4, pc, r4
	.loc 1 41 0
	ldr	r3, .L11+4
.LPIC8:
	add	r3, pc, r3
	mov	r0, r3
	mov	r1, #1
	bl	IwDebugTraceIsChannelOn(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L10
	.loc 1 41 0 is_stmt 0 discriminator 1
	ldr	r3, .L11+8
.LPIC9:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L11+12
.LPIC10:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L10:
	.loc 1 42 0 is_stmt 1
	ldr	r3, .L11+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 43 0
	ldmfd	sp!, {r4, pc}
.L12:
	.align	2
.L11:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC11+8)
	.word	.LC0-(.LPIC8+8)
	.word	.LC0-(.LPIC9+8)
	.word	.LC3-(.LPIC10+8)
	.word	showDoInter(GOT)
	.cfi_endproc
.LFE35:
	.size	_ZL16showDoInter_wrapv, .-_ZL16showDoInter_wrapv
	.section	.rodata
	.align	2
.LC4:
	.ascii	"calling LihuiDomob func on main thread: showDoSplas"
	.ascii	"h\000"
	.section	.text._ZL17showDoSplash_wrapv,"ax",%progbits
	.align	2
	.type	_ZL17showDoSplash_wrapv, %function
_ZL17showDoSplash_wrapv:
.LFB36:
	.loc 1 46 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 46 0
	ldr	r4, .L15
.LPIC15:
	add	r4, pc, r4
	.loc 1 47 0
	ldr	r3, .L15+4
.LPIC12:
	add	r3, pc, r3
	mov	r0, r3
	mov	r1, #1
	bl	IwDebugTraceIsChannelOn(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L14
	.loc 1 47 0 is_stmt 0 discriminator 1
	ldr	r3, .L15+8
.LPIC13:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L15+12
.LPIC14:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L14:
	.loc 1 48 0 is_stmt 1
	ldr	r3, .L15+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 49 0
	ldmfd	sp!, {r4, pc}
.L16:
	.align	2
.L15:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC15+8)
	.word	.LC0-(.LPIC12+8)
	.word	.LC0-(.LPIC13+8)
	.word	.LC4-(.LPIC14+8)
	.word	showDoSplash(GOT)
	.cfi_endproc
.LFE36:
	.size	_ZL17showDoSplash_wrapv, .-_ZL17showDoSplash_wrapv
	.section	.rodata
	.align	2
.LC5:
	.ascii	"calling LihuiDomob func on main thread: checkPoints"
	.ascii	"\000"
	.section	.text._ZL16checkPoints_wrapv,"ax",%progbits
	.align	2
	.type	_ZL16checkPoints_wrapv, %function
_ZL16checkPoints_wrapv:
.LFB37:
	.loc 1 52 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 52 0
	ldr	r4, .L19
.LPIC19:
	add	r4, pc, r4
	.loc 1 53 0
	ldr	r3, .L19+4
.LPIC16:
	add	r3, pc, r3
	mov	r0, r3
	mov	r1, #1
	bl	IwDebugTraceIsChannelOn(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L18
	.loc 1 53 0 is_stmt 0 discriminator 1
	ldr	r3, .L19+8
.LPIC17:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L19+12
.LPIC18:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L18:
	.loc 1 54 0 is_stmt 1
	ldr	r3, .L19+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 55 0
	ldmfd	sp!, {r4, pc}
.L20:
	.align	2
.L19:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC19+8)
	.word	.LC0-(.LPIC16+8)
	.word	.LC0-(.LPIC17+8)
	.word	.LC5-(.LPIC18+8)
	.word	checkPoints(GOT)
	.cfi_endproc
.LFE37:
	.size	_ZL16checkPoints_wrapv, .-_ZL16checkPoints_wrapv
	.section	.rodata
	.align	2
.LC6:
	.ascii	"calling LihuiDomob func on main thread: usePoints\000"
	.section	.text._ZL14usePoints_wrapi,"ax",%progbits
	.align	2
	.type	_ZL14usePoints_wrapi, %function
_ZL14usePoints_wrapi:
.LFB38:
	.loc 1 58 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	sub	sp, sp, #8
	.cfi_def_cfa_offset 16
	str	r0, [sp, #4]
	.loc 1 58 0
	ldr	r4, .L23
.LPIC23:
	add	r4, pc, r4
	.loc 1 59 0
	ldr	r3, .L23+4
.LPIC20:
	add	r3, pc, r3
	mov	r0, r3
	mov	r1, #1
	bl	IwDebugTraceIsChannelOn(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L22
	.loc 1 59 0 is_stmt 0 discriminator 1
	ldr	r3, .L23+8
.LPIC21:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L23+12
.LPIC22:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L22:
	.loc 1 60 0 is_stmt 1
	ldr	r3, .L23+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #1
	ldr	r2, [sp, #4]
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 61 0
	add	sp, sp, #8
	@ sp needed
	ldmfd	sp!, {r4, pc}
.L24:
	.align	2
.L23:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC23+8)
	.word	.LC0-(.LPIC20+8)
	.word	.LC0-(.LPIC21+8)
	.word	.LC6-(.LPIC22+8)
	.word	usePoints(GOT)
	.cfi_endproc
.LFE38:
	.size	_ZL14usePoints_wrapi, .-_ZL14usePoints_wrapi
	.section	.rodata
	.align	2
.LC7:
	.ascii	"calling LihuiDomob func on main thread: getPoints\000"
	.section	.text._ZL14getPoints_wrapv,"ax",%progbits
	.align	2
	.type	_ZL14getPoints_wrapv, %function
_ZL14getPoints_wrapv:
.LFB39:
	.loc 1 64 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 64 0
	ldr	r4, .L27
.LPIC27:
	add	r4, pc, r4
	.loc 1 65 0
	ldr	r3, .L27+4
.LPIC24:
	add	r3, pc, r3
	mov	r0, r3
	mov	r1, #1
	bl	IwDebugTraceIsChannelOn(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L26
	.loc 1 65 0 is_stmt 0 discriminator 1
	ldr	r3, .L27+8
.LPIC25:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L27+12
.LPIC26:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L26:
	.loc 1 66 0 is_stmt 1
	ldr	r3, .L27+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 67 0
	ldmfd	sp!, {r4, pc}
.L28:
	.align	2
.L27:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC27+8)
	.word	.LC0-(.LPIC24+8)
	.word	.LC0-(.LPIC25+8)
	.word	.LC7-(.LPIC26+8)
	.word	getPoints(GOT)
	.cfi_endproc
.LFE39:
	.size	_ZL14getPoints_wrapv, .-_ZL14getPoints_wrapv
	.section	.text.LihuiDomobRegister,"ax",%progbits
	.align	2
	.global	LihuiDomobRegister
	.hidden	LihuiDomobRegister
	.type	LihuiDomobRegister, %function
LihuiDomobRegister:
.LFB40:
	.loc 1 80 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #28
	.cfi_def_cfa_offset 32
	str	r0, [sp, #20]
	str	r1, [sp, #16]
	str	r2, [sp, #12]
	.loc 1 81 0
	ldr	r3, [sp, #20]
	ldr	r2, [sp, #12]
	str	r2, [sp]
	mov	r2, #0
	str	r2, [sp, #4]
	ldr	r0, .L31
	mov	r1, #6
	mov	r2, r3
	ldr	r3, [sp, #16]
	bl	s3eEdkCallbacksRegister(PLT)
	mov	r3, r0
	.loc 1 82 0
	mov	r0, r3
	add	sp, sp, #28
	@ sp needed
	ldr	pc, [sp], #4
.L32:
	.align	2
.L31:
	.word	-695751919
	.cfi_endproc
.LFE40:
	.size	LihuiDomobRegister, .-LihuiDomobRegister
	.section	.text.LihuiDomobUnRegister,"ax",%progbits
	.align	2
	.global	LihuiDomobUnRegister
	.hidden	LihuiDomobUnRegister
	.type	LihuiDomobUnRegister, %function
LihuiDomobUnRegister:
.LFB41:
	.loc 1 85 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #20
	.cfi_def_cfa_offset 24
	str	r0, [sp, #12]
	str	r1, [sp, #8]
	.loc 1 86 0
	ldr	r3, [sp, #12]
	mov	r2, #0
	str	r2, [sp]
	ldr	r0, .L35
	mov	r1, #6
	mov	r2, r3
	ldr	r3, [sp, #8]
	bl	s3eEdkCallbacksUnRegister(PLT)
	mov	r3, r0
	.loc 1 87 0
	mov	r0, r3
	add	sp, sp, #20
	@ sp needed
	ldr	pc, [sp], #4
.L36:
	.align	2
.L35:
	.word	-695751919
	.cfi_endproc
.LFE41:
	.size	LihuiDomobUnRegister, .-LihuiDomobUnRegister
	.section	.rodata
	.align	2
.LC8:
	.ascii	"LihuiDomob\000"
	.section	.text._Z21LihuiDomobRegisterExtv,"ax",%progbits
	.align	2
	.global	_Z21LihuiDomobRegisterExtv
	.hidden	_Z21LihuiDomobRegisterExtv
	.type	_Z21LihuiDomobRegisterExtv, %function
_Z21LihuiDomobRegisterExtv:
.LFB42:
	.loc 1 90 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 72
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #92
	.cfi_def_cfa_offset 96
	.loc 1 90 0
	ldr	r2, .L38
.LPIC37:
	add	r2, pc, r2
.LBB2:
	.loc 1 93 0
	ldr	r3, .L38+4
.LPIC28:
	add	r3, pc, r3
	str	r3, [sp, #16]
	.loc 1 94 0
	ldr	r3, .L38+8
.LPIC29:
	add	r3, pc, r3
	str	r3, [sp, #20]
	.loc 1 95 0
	ldr	r3, .L38+12
.LPIC30:
	add	r3, pc, r3
	str	r3, [sp, #24]
	.loc 1 96 0
	ldr	r3, .L38+16
.LPIC31:
	add	r3, pc, r3
	str	r3, [sp, #28]
	.loc 1 97 0
	ldr	r3, .L38+20
.LPIC32:
	add	r3, pc, r3
	str	r3, [sp, #32]
	.loc 1 98 0
	ldr	r3, .L38+24
.LPIC33:
	add	r3, pc, r3
	str	r3, [sp, #36]
	.loc 1 99 0
	ldr	r3, .L38+28
.LPIC34:
	add	r3, pc, r3
	str	r3, [sp, #40]
	.loc 1 100 0
	ldr	r3, .L38+32
.LPIC35:
	add	r3, pc, r3
	str	r3, [sp, #44]
	.loc 1 101 0
	ldr	r3, .L38+36
.LPIC36:
	add	r3, pc, r3
	str	r3, [sp, #48]
	.loc 1 106 0
	add	r3, sp, #52
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	mov	r1, #0
	str	r1, [r3]
	add	r3, r3, #4
	.loc 1 111 0
	mov	ip, #36
	add	r1, sp, #16
	add	r3, sp, #52
	ldr	r0, .L38+40
	ldr	r0, [r2, r0]
	str	r0, [sp]
	ldr	r0, .L38+44
	ldr	r2, [r2, r0]
	str	r2, [sp, #4]
	mov	r2, #0
	str	r2, [sp, #8]
	ldr	r2, .L38+48
.LPIC38:
	add	r2, pc, r2
	mov	r0, r2
	mov	r2, ip
	bl	s3eEdkRegister(PLT)
.LBE2:
	.loc 1 112 0
	add	sp, sp, #92
	@ sp needed
	ldr	pc, [sp], #4
.L39:
	.align	2
.L38:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC37+8)
	.word	LihuiDomobRegister-(.LPIC28+8)
	.word	LihuiDomobUnRegister-(.LPIC29+8)
	.word	_ZL13initDoAd_wrapv-(.LPIC30+8)
	.word	_ZL17showDoBanner_wrapv-(.LPIC31+8)
	.word	_ZL16showDoInter_wrapv-(.LPIC32+8)
	.word	_ZL17showDoSplash_wrapv-(.LPIC33+8)
	.word	_ZL16checkPoints_wrapv-(.LPIC34+8)
	.word	_ZL14usePoints_wrapi-(.LPIC35+8)
	.word	_ZL14getPoints_wrapv-(.LPIC36+8)
	.word	_Z14LihuiDomobInitv(GOT)
	.word	_Z19LihuiDomobTerminatev(GOT)
	.word	.LC8-(.LPIC38+8)
	.cfi_endproc
.LFE42:
	.size	_Z21LihuiDomobRegisterExtv, .-_Z21LihuiDomobRegisterExtv
	.section	.text.RegisterExt,"ax",%progbits
	.align	2
	.global	RegisterExt
	.type	RegisterExt, %function
RegisterExt:
.LFB43:
	.loc 1 131 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 132 0
	bl	_Z21LihuiDomobRegisterExtv(PLT)
	.loc 1 133 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE43:
	.size	RegisterExt, .-RegisterExt
	.text
.Letext0:
	.file 2 "e:/marmalade/7.0/s3e/h/s3eTypes.h"
	.file 3 "e:/marmalade/7.0/s3e/edk/h/s3eEdk.h"
	.file 4 "../h/LihuiDomob.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x28e
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF39
	.byte	0x4
	.4byte	.LASF40
	.4byte	.LASF41
	.4byte	.Ldebug_ranges0+0
	.4byte	0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF3
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF4
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x4
	.4byte	.LASF10
	.byte	0x2
	.byte	0x74
	.4byte	0x48
	.uleb128 0x5
	.4byte	.LASF11
	.byte	0x4
	.byte	0x2
	.byte	0xcf
	.4byte	0x88
	.uleb128 0x6
	.4byte	.LASF8
	.sleb128 0
	.uleb128 0x6
	.4byte	.LASF9
	.sleb128 1
	.byte	0
	.uleb128 0x4
	.4byte	.LASF11
	.byte	0x2
	.byte	0xd3
	.4byte	0x6f
	.uleb128 0x4
	.4byte	.LASF12
	.byte	0x2
	.byte	0xed
	.4byte	0x9e
	.uleb128 0x7
	.byte	0x4
	.4byte	0xa4
	.uleb128 0x8
	.4byte	0x64
	.4byte	0xb8
	.uleb128 0x9
	.4byte	0xb8
	.uleb128 0x9
	.4byte	0xb8
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF13
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF14
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF15
	.uleb128 0xb
	.4byte	.LASF16
	.byte	0x3
	.2byte	0x283
	.4byte	0xdb
	.uleb128 0x7
	.byte	0x4
	.4byte	0xe1
	.uleb128 0xc
	.4byte	0xb8
	.uleb128 0x5
	.4byte	.LASF17
	.byte	0x4
	.byte	0x4
	.byte	0x15
	.4byte	0x11d
	.uleb128 0x6
	.4byte	.LASF18
	.sleb128 0
	.uleb128 0x6
	.4byte	.LASF19
	.sleb128 1
	.uleb128 0x6
	.4byte	.LASF20
	.sleb128 2
	.uleb128 0x6
	.4byte	.LASF21
	.sleb128 3
	.uleb128 0x6
	.4byte	.LASF22
	.sleb128 4
	.uleb128 0x6
	.4byte	.LASF23
	.sleb128 5
	.uleb128 0x6
	.4byte	.LASF24
	.sleb128 6
	.byte	0
	.uleb128 0xd
	.4byte	.LASF25
	.byte	0x1
	.byte	0x1b
	.4byte	.LFB33
	.4byte	.LFE33-.LFB33
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF26
	.byte	0x1
	.byte	0x21
	.4byte	.LFB34
	.4byte	.LFE34-.LFB34
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF27
	.byte	0x1
	.byte	0x27
	.4byte	.LFB35
	.4byte	.LFE35-.LFB35
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF28
	.byte	0x1
	.byte	0x2d
	.4byte	.LFB36
	.4byte	.LFE36-.LFB36
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF29
	.byte	0x1
	.byte	0x33
	.4byte	.LFB37
	.4byte	.LFE37-.LFB37
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xe
	.4byte	.LASF42
	.byte	0x1
	.byte	0x39
	.4byte	.LFB38
	.4byte	.LFE38-.LFB38
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x196
	.uleb128 0xf
	.4byte	.LASF31
	.byte	0x1
	.byte	0x39
	.4byte	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xd
	.4byte	.LASF30
	.byte	0x1
	.byte	0x3f
	.4byte	.LFB39
	.4byte	.LFE39-.LFB39
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x10
	.4byte	.LASF34
	.byte	0x1
	.byte	0x4f
	.4byte	0x88
	.4byte	.LFB40
	.4byte	.LFE40-.LFB40
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x1ea
	.uleb128 0xf
	.4byte	.LASF32
	.byte	0x1
	.byte	0x4f
	.4byte	0xe6
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x11
	.ascii	"fn\000"
	.byte	0x1
	.byte	0x4f
	.4byte	0x93
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0xf
	.4byte	.LASF33
	.byte	0x1
	.byte	0x4f
	.4byte	0xb8
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x10
	.4byte	.LASF35
	.byte	0x1
	.byte	0x54
	.4byte	0x88
	.4byte	.LFB41
	.4byte	.LFE41-.LFB41
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x21f
	.uleb128 0xf
	.4byte	.LASF32
	.byte	0x1
	.byte	0x54
	.4byte	0xe6
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x11
	.ascii	"fn\000"
	.byte	0x1
	.byte	0x54
	.4byte	0x93
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0x12
	.4byte	.LASF36
	.byte	0x1
	.byte	0x59
	.4byte	.LASF43
	.4byte	.LFB42
	.4byte	.LFE42-.LFB42
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x260
	.uleb128 0x13
	.4byte	.LBB2
	.4byte	.LBE2-.LBB2
	.uleb128 0x14
	.4byte	.LASF37
	.byte	0x1
	.byte	0x5c
	.4byte	0x260
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x14
	.4byte	.LASF38
	.byte	0x1
	.byte	0x6a
	.4byte	0x270
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.byte	0
	.byte	0
	.uleb128 0x15
	.4byte	0xb8
	.4byte	0x270
	.uleb128 0x16
	.4byte	0xc1
	.byte	0x8
	.byte	0
	.uleb128 0x15
	.4byte	0x48
	.4byte	0x280
	.uleb128 0x16
	.4byte	0xc1
	.byte	0x8
	.byte	0
	.uleb128 0x17
	.4byte	.LASF44
	.byte	0x1
	.byte	0x82
	.4byte	.LFB43
	.4byte	.LFE43-.LFB43
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x15
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x6c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB33
	.4byte	.LFE33-.LFB33
	.4byte	.LFB34
	.4byte	.LFE34-.LFB34
	.4byte	.LFB35
	.4byte	.LFE35-.LFB35
	.4byte	.LFB36
	.4byte	.LFE36-.LFB36
	.4byte	.LFB37
	.4byte	.LFE37-.LFB37
	.4byte	.LFB38
	.4byte	.LFE38-.LFB38
	.4byte	.LFB39
	.4byte	.LFE39-.LFB39
	.4byte	.LFB40
	.4byte	.LFE40-.LFB40
	.4byte	.LFB41
	.4byte	.LFE41-.LFB41
	.4byte	.LFB42
	.4byte	.LFE42-.LFB42
	.4byte	.LFB43
	.4byte	.LFE43-.LFB43
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.4byte	.LFB33
	.4byte	.LFE33
	.4byte	.LFB34
	.4byte	.LFE34
	.4byte	.LFB35
	.4byte	.LFE35
	.4byte	.LFB36
	.4byte	.LFE36
	.4byte	.LFB37
	.4byte	.LFE37
	.4byte	.LFB38
	.4byte	.LFE38
	.4byte	.LFB39
	.4byte	.LFE39
	.4byte	.LFB40
	.4byte	.LFE40
	.4byte	.LFB41
	.4byte	.LFE41
	.4byte	.LFB42
	.4byte	.LFE42
	.4byte	.LFB43
	.4byte	.LFE43
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF17:
	.ascii	"LihuiDomobCallback\000"
.LASF40:
	.ascii	"D:\\10kgratExtension\\ExMarmalade\\Project\\2048Tes"
	.ascii	"t\\third_party\\LihuiDomob\\source\\generic\\LihuiD"
	.ascii	"omob_register.cpp\000"
.LASF43:
	.ascii	"_Z21LihuiDomobRegisterExtv\000"
.LASF23:
	.ascii	"LIHUIDO_CALLBACK_CONSUME_FAILED\000"
.LASF27:
	.ascii	"showDoInter_wrap\000"
.LASF31:
	.ascii	"point\000"
.LASF13:
	.ascii	"long int\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF19:
	.ascii	"LIHUIDO_CALLBACK_SPLASH_FAILED\000"
.LASF34:
	.ascii	"LihuiDomobRegister\000"
.LASF33:
	.ascii	"pData\000"
.LASF21:
	.ascii	"LIHUIDO_CALLBACK_POINT_FAILED\000"
.LASF12:
	.ascii	"s3eCallback\000"
.LASF8:
	.ascii	"S3E_RESULT_SUCCESS\000"
.LASF6:
	.ascii	"long long unsigned int\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF7:
	.ascii	"long unsigned int\000"
.LASF10:
	.ascii	"int32\000"
.LASF26:
	.ascii	"showDoBanner_wrap\000"
.LASF39:
	.ascii	"GNU C++ 4.8 -fpreprocessed -mbionic -mstructure-siz"
	.ascii	"e-boundary=8 -mfpu=vfp -mfloat-abi=softfp -mthumb-i"
	.ascii	"nterwork -march=armv5te -mtls-dialect=gnu -g -O0 -f"
	.ascii	"no-exceptions -fsigned-char -fno-strict-aliasing -f"
	.ascii	"visibility=hidden -fno-short-enums -fomit-frame-poi"
	.ascii	"nter -fmessage-length=0 -ffunction-sections -fPIC -"
	.ascii	"frtti\000"
.LASF30:
	.ascii	"getPoints_wrap\000"
.LASF3:
	.ascii	"short int\000"
.LASF4:
	.ascii	"unsigned int\000"
.LASF38:
	.ascii	"flags\000"
.LASF28:
	.ascii	"showDoSplash_wrap\000"
.LASF32:
	.ascii	"cbid\000"
.LASF9:
	.ascii	"S3E_RESULT_ERROR\000"
.LASF37:
	.ascii	"funcPtrs\000"
.LASF14:
	.ascii	"sizetype\000"
.LASF5:
	.ascii	"long long int\000"
.LASF15:
	.ascii	"char\000"
.LASF29:
	.ascii	"checkPoints_wrap\000"
.LASF44:
	.ascii	"RegisterExt\000"
.LASF24:
	.ascii	"LIHUIDOMOB_CALLBACK_MAX\000"
.LASF41:
	.ascii	"d:\\\\10kgratExtension\\\\ExMarmalade\\\\Project\\\\"
	.ascii	"2048Test\\\\third_party\\\\LihuiDomob\\\\build_lihu"
	.ascii	"idomob_android_linux_scons_arm\000"
.LASF42:
	.ascii	"usePoints_wrap\000"
.LASF36:
	.ascii	"LihuiDomobRegisterExt\000"
.LASF20:
	.ascii	"LIHUIDO_CALLBACK_POINT_SUCCESSFUL\000"
.LASF18:
	.ascii	"LIHUIDO_CALLBACK_SPLASH_SUCCESSFUL\000"
.LASF35:
	.ascii	"LihuiDomobUnRegister\000"
.LASF25:
	.ascii	"initDoAd_wrap\000"
.LASF1:
	.ascii	"signed char\000"
.LASF22:
	.ascii	"LIHUIDO_CALLBACK_CONSUME_SUCCESSFUL\000"
.LASF11:
	.ascii	"s3eResult\000"
.LASF16:
	.ascii	"s3eEdkThreadFunc\000"
	.ident	"GCC: (GNU) 4.8"
	.section	.note.GNU-stack,"",%progbits
