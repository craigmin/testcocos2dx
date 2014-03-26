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
	.file	"Lihui2048Api_register.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.rodata
	.align	2
.LC0:
	.ascii	"LIHUI2048API_VERBOSE\000"
	.align	2
.LC1:
	.ascii	"calling Lihui2048Api func on main thread: isMovable"
	.ascii	"\000"
	.section	.text._ZL14isMovable_wrapv,"ax",%progbits
	.align	2
	.type	_ZL14isMovable_wrapv, %function
_ZL14isMovable_wrapv:
.LFB33:
	.file 1 "D:\\10kgratExtension\\ExMarmalade\\Project\\TestGame\\third_party\\Lihui2048Api\\source\\generic\\Lihui2048Api_register.cpp"
	.loc 1 28 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 28 0
	ldr	r4, .L4
.LPIC3:
	add	r4, pc, r4
	.loc 1 29 0
	ldr	r3, .L4+4
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
	ldr	r3, .L4+8
.LPIC1:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L4+12
.LPIC2:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L2:
	.loc 1 30 0 is_stmt 1
	ldr	r3, .L4+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	.loc 1 31 0
	mov	r0, r3
	ldmfd	sp!, {r4, pc}
.L5:
	.align	2
.L4:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC3+8)
	.word	.LC0-(.LPIC0+8)
	.word	.LC0-(.LPIC1+8)
	.word	.LC1-(.LPIC2+8)
	.word	isMovable(GOT)
	.cfi_endproc
.LFE33:
	.size	_ZL14isMovable_wrapv, .-_ZL14isMovable_wrapv
	.section	.rodata
	.align	2
.LC2:
	.ascii	"calling Lihui2048Api func on main thread: move\000"
	.section	.text._ZL9move_wrapi,"ax",%progbits
	.align	2
	.type	_ZL9move_wrapi, %function
_ZL9move_wrapi:
.LFB34:
	.loc 1 34 0
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
	.loc 1 34 0
	ldr	r4, .L8
.LPIC7:
	add	r4, pc, r4
	.loc 1 35 0
	ldr	r3, .L8+4
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
	beq	.L7
	.loc 1 35 0 is_stmt 0 discriminator 1
	ldr	r3, .L8+8
.LPIC5:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L8+12
.LPIC6:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L7:
	.loc 1 36 0 is_stmt 1
	ldr	r3, .L8+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #1
	ldr	r2, [sp, #4]
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 37 0
	add	sp, sp, #8
	@ sp needed
	ldmfd	sp!, {r4, pc}
.L9:
	.align	2
.L8:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC7+8)
	.word	.LC0-(.LPIC4+8)
	.word	.LC0-(.LPIC5+8)
	.word	.LC2-(.LPIC6+8)
	.word	move(GOT)
	.cfi_endproc
.LFE34:
	.size	_ZL9move_wrapi, .-_ZL9move_wrapi
	.section	.rodata
	.align	2
.LC3:
	.ascii	"calling Lihui2048Api func on main thread: getCurren"
	.ascii	"tScore\000"
	.section	.text._ZL20getCurrentScore_wrapv,"ax",%progbits
	.align	2
	.type	_ZL20getCurrentScore_wrapv, %function
_ZL20getCurrentScore_wrapv:
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
	ldr	r4, .L13
.LPIC11:
	add	r4, pc, r4
	.loc 1 41 0
	ldr	r3, .L13+4
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
	beq	.L11
	.loc 1 41 0 is_stmt 0 discriminator 1
	ldr	r3, .L13+8
.LPIC9:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L13+12
.LPIC10:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L11:
	.loc 1 42 0 is_stmt 1
	ldr	r3, .L13+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	mov	r3, r0
	.loc 1 43 0
	mov	r0, r3
	ldmfd	sp!, {r4, pc}
.L14:
	.align	2
.L13:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC11+8)
	.word	.LC0-(.LPIC8+8)
	.word	.LC0-(.LPIC9+8)
	.word	.LC3-(.LPIC10+8)
	.word	getCurrentScore(GOT)
	.cfi_endproc
.LFE35:
	.size	_ZL20getCurrentScore_wrapv, .-_ZL20getCurrentScore_wrapv
	.section	.rodata
	.align	2
.LC4:
	.ascii	"calling Lihui2048Api func on main thread: getBestSc"
	.ascii	"ore\000"
	.section	.text._ZL17getBestScore_wrapv,"ax",%progbits
	.align	2
	.type	_ZL17getBestScore_wrapv, %function
_ZL17getBestScore_wrapv:
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
	ldr	r4, .L18
.LPIC15:
	add	r4, pc, r4
	.loc 1 47 0
	ldr	r3, .L18+4
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
	beq	.L16
	.loc 1 47 0 is_stmt 0 discriminator 1
	ldr	r3, .L18+8
.LPIC13:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L18+12
.LPIC14:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L16:
	.loc 1 48 0 is_stmt 1
	ldr	r3, .L18+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	mov	r3, r0
	.loc 1 49 0
	mov	r0, r3
	ldmfd	sp!, {r4, pc}
.L19:
	.align	2
.L18:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC15+8)
	.word	.LC0-(.LPIC12+8)
	.word	.LC0-(.LPIC13+8)
	.word	.LC4-(.LPIC14+8)
	.word	getBestScore(GOT)
	.cfi_endproc
.LFE36:
	.size	_ZL17getBestScore_wrapv, .-_ZL17getBestScore_wrapv
	.section	.rodata
	.align	2
.LC5:
	.ascii	"calling Lihui2048Api func on main thread: reset\000"
	.section	.text._ZL10reset_wrapv,"ax",%progbits
	.align	2
	.type	_ZL10reset_wrapv, %function
_ZL10reset_wrapv:
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
	ldr	r4, .L22
.LPIC19:
	add	r4, pc, r4
	.loc 1 53 0
	ldr	r3, .L22+4
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
	beq	.L21
	.loc 1 53 0 is_stmt 0 discriminator 1
	ldr	r3, .L22+8
.LPIC17:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L22+12
.LPIC18:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L21:
	.loc 1 54 0 is_stmt 1
	ldr	r3, .L22+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 55 0
	ldmfd	sp!, {r4, pc}
.L23:
	.align	2
.L22:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC19+8)
	.word	.LC0-(.LPIC16+8)
	.word	.LC0-(.LPIC17+8)
	.word	.LC5-(.LPIC18+8)
	.word	reset(GOT)
	.cfi_endproc
.LFE37:
	.size	_ZL10reset_wrapv, .-_ZL10reset_wrapv
	.section	.rodata
	.align	2
.LC6:
	.ascii	"calling Lihui2048Api func on main thread: isWin\000"
	.section	.text._ZL10isWin_wrapv,"ax",%progbits
	.align	2
	.type	_ZL10isWin_wrapv, %function
_ZL10isWin_wrapv:
.LFB38:
	.loc 1 58 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 58 0
	ldr	r4, .L27
.LPIC23:
	add	r4, pc, r4
	.loc 1 59 0
	ldr	r3, .L27+4
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
	beq	.L25
	.loc 1 59 0 is_stmt 0 discriminator 1
	ldr	r3, .L27+8
.LPIC21:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L27+12
.LPIC22:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L25:
	.loc 1 60 0 is_stmt 1
	ldr	r3, .L27+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	mov	r3, r0
	cmp	r3, #0
	moveq	r3, #0
	movne	r3, #1
	and	r3, r3, #255
	.loc 1 61 0
	mov	r0, r3
	ldmfd	sp!, {r4, pc}
.L28:
	.align	2
.L27:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC23+8)
	.word	.LC0-(.LPIC20+8)
	.word	.LC0-(.LPIC21+8)
	.word	.LC6-(.LPIC22+8)
	.word	isWin(GOT)
	.cfi_endproc
.LFE38:
	.size	_ZL10isWin_wrapv, .-_ZL10isWin_wrapv
	.section	.rodata
	.align	2
.LC7:
	.ascii	"calling Lihui2048Api func on main thread: getValue\000"
	.section	.text._ZL13getValue_wrapii,"ax",%progbits
	.align	2
	.type	_ZL13getValue_wrapii, %function
_ZL13getValue_wrapii:
.LFB39:
	.loc 1 64 0
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
	str	r1, [sp]
	.loc 1 64 0
	ldr	r4, .L32
.LPIC27:
	add	r4, pc, r4
	.loc 1 65 0
	ldr	r3, .L32+4
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
	beq	.L30
	.loc 1 65 0 is_stmt 0 discriminator 1
	ldr	r3, .L32+8
.LPIC25:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L32+12
.LPIC26:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L30:
	.loc 1 66 0 is_stmt 1
	ldr	r3, .L32+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #2
	ldr	r2, [sp, #4]
	ldr	r3, [sp]
	bl	s3eEdkThreadRunOnOS(PLT)
	mov	r3, r0
	.loc 1 67 0
	mov	r0, r3
	add	sp, sp, #8
	@ sp needed
	ldmfd	sp!, {r4, pc}
.L33:
	.align	2
.L32:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC27+8)
	.word	.LC0-(.LPIC24+8)
	.word	.LC0-(.LPIC25+8)
	.word	.LC7-(.LPIC26+8)
	.word	getValue(GOT)
	.cfi_endproc
.LFE39:
	.size	_ZL13getValue_wrapii, .-_ZL13getValue_wrapii
	.section	.rodata
	.align	2
.LC8:
	.ascii	"Lihui2048Api\000"
	.section	.text._Z23Lihui2048ApiRegisterExtv,"ax",%progbits
	.align	2
	.global	_Z23Lihui2048ApiRegisterExtv
	.hidden	_Z23Lihui2048ApiRegisterExtv
	.type	_Z23Lihui2048ApiRegisterExtv, %function
_Z23Lihui2048ApiRegisterExtv:
.LFB40:
	.loc 1 80 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 56
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #76
	.cfi_def_cfa_offset 80
	.loc 1 80 0
	ldr	r2, .L35
.LPIC35:
	add	r2, pc, r2
.LBB2:
	.loc 1 83 0
	ldr	r3, .L35+4
.LPIC28:
	add	r3, pc, r3
	str	r3, [sp, #44]
	.loc 1 84 0
	ldr	r3, .L35+8
.LPIC29:
	add	r3, pc, r3
	str	r3, [sp, #48]
	.loc 1 85 0
	ldr	r3, .L35+12
.LPIC30:
	add	r3, pc, r3
	str	r3, [sp, #52]
	.loc 1 86 0
	ldr	r3, .L35+16
.LPIC31:
	add	r3, pc, r3
	str	r3, [sp, #56]
	.loc 1 87 0
	ldr	r3, .L35+20
.LPIC32:
	add	r3, pc, r3
	str	r3, [sp, #60]
	.loc 1 88 0
	ldr	r3, .L35+24
.LPIC33:
	add	r3, pc, r3
	str	r3, [sp, #64]
	.loc 1 89 0
	ldr	r3, .L35+28
.LPIC34:
	add	r3, pc, r3
	str	r3, [sp, #68]
	.loc 1 94 0
	add	r3, sp, #16
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
	.loc 1 99 0
	mov	ip, #28
	add	r1, sp, #44
	add	r3, sp, #16
	ldr	r0, .L35+32
	ldr	r0, [r2, r0]
	str	r0, [sp]
	ldr	r0, .L35+36
	ldr	r2, [r2, r0]
	str	r2, [sp, #4]
	mov	r2, #0
	str	r2, [sp, #8]
	ldr	r2, .L35+40
.LPIC36:
	add	r2, pc, r2
	mov	r0, r2
	mov	r2, ip
	bl	s3eEdkRegister(PLT)
.LBE2:
	.loc 1 100 0
	add	sp, sp, #76
	@ sp needed
	ldr	pc, [sp], #4
.L36:
	.align	2
.L35:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC35+8)
	.word	_ZL14isMovable_wrapv-(.LPIC28+8)
	.word	_ZL9move_wrapi-(.LPIC29+8)
	.word	_ZL20getCurrentScore_wrapv-(.LPIC30+8)
	.word	_ZL17getBestScore_wrapv-(.LPIC31+8)
	.word	_ZL10reset_wrapv-(.LPIC32+8)
	.word	_ZL10isWin_wrapv-(.LPIC33+8)
	.word	_ZL13getValue_wrapii-(.LPIC34+8)
	.word	_Z16Lihui2048ApiInitv(GOT)
	.word	_Z21Lihui2048ApiTerminatev(GOT)
	.word	.LC8-(.LPIC36+8)
	.cfi_endproc
.LFE40:
	.size	_Z23Lihui2048ApiRegisterExtv, .-_Z23Lihui2048ApiRegisterExtv
	.section	.text.RegisterExt,"ax",%progbits
	.align	2
	.global	RegisterExt
	.type	RegisterExt, %function
RegisterExt:
.LFB41:
	.loc 1 119 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 120 0
	bl	_Z23Lihui2048ApiRegisterExtv(PLT)
	.loc 1 121 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE41:
	.size	RegisterExt, .-RegisterExt
	.text
.Letext0:
	.file 2 "e:/marmalade/7.0/s3e/h/s3eTypes.h"
	.file 3 "e:/marmalade/7.0/s3e/edk/h/s3eEdk.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x1cd
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF21
	.byte	0x4
	.4byte	.LASF22
	.4byte	.LASF23
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
	.uleb128 0x4
	.4byte	.LASF11
	.byte	0x2
	.byte	0x54
	.4byte	0x48
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x5
	.byte	0x4
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF8
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF9
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF10
	.uleb128 0x6
	.4byte	.LASF12
	.byte	0x3
	.2byte	0x283
	.4byte	0x92
	.uleb128 0x7
	.byte	0x4
	.4byte	0x98
	.uleb128 0x8
	.4byte	0x6f
	.uleb128 0x9
	.4byte	.LASF14
	.byte	0x1
	.byte	0x1b
	.4byte	0xb2
	.4byte	.LFB33
	.4byte	.LFE33-.LFB33
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.4byte	.LASF13
	.uleb128 0xa
	.4byte	.LASF24
	.byte	0x1
	.byte	0x21
	.4byte	.LFB34
	.4byte	.LFE34-.LFB34
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xdd
	.uleb128 0xb
	.4byte	.LASF18
	.byte	0x1
	.byte	0x21
	.4byte	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x9
	.4byte	.LASF15
	.byte	0x1
	.byte	0x27
	.4byte	0x48
	.4byte	.LFB35
	.4byte	.LFE35-.LFB35
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF16
	.byte	0x1
	.byte	0x2d
	.4byte	0x48
	.4byte	.LFB36
	.4byte	.LFE36-.LFB36
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xc
	.4byte	.LASF25
	.byte	0x1
	.byte	0x33
	.4byte	.LFB37
	.4byte	.LFE37-.LFB37
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF17
	.byte	0x1
	.byte	0x39
	.4byte	0xb2
	.4byte	.LFB38
	.4byte	.LFE38-.LFB38
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF26
	.byte	0x1
	.byte	0x3f
	.4byte	0x48
	.4byte	.LFB39
	.4byte	.LFE39-.LFB39
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x15f
	.uleb128 0xe
	.ascii	"x\000"
	.byte	0x1
	.byte	0x3f
	.4byte	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0xe
	.ascii	"y\000"
	.byte	0x1
	.byte	0x3f
	.4byte	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0xf
	.4byte	.LASF27
	.byte	0x1
	.byte	0x4f
	.4byte	.LASF28
	.4byte	.LFB40
	.4byte	.LFE40-.LFB40
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x19f
	.uleb128 0x10
	.4byte	.LBB2
	.4byte	.LBE2-.LBB2
	.uleb128 0x11
	.4byte	.LASF19
	.byte	0x1
	.byte	0x52
	.4byte	0x19f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x11
	.4byte	.LASF20
	.byte	0x1
	.byte	0x5e
	.4byte	0x1af
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.byte	0
	.byte	0
	.uleb128 0x12
	.4byte	0x6f
	.4byte	0x1af
	.uleb128 0x13
	.4byte	0x78
	.byte	0x6
	.byte	0
	.uleb128 0x12
	.4byte	0x48
	.4byte	0x1bf
	.uleb128 0x13
	.4byte	0x78
	.byte	0x6
	.byte	0
	.uleb128 0x14
	.4byte	.LASF29
	.byte	0x1
	.byte	0x76
	.4byte	.LFB41
	.4byte	.LFE41-.LFB41
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
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
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
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0
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
	.byte	0
	.byte	0
	.uleb128 0xa
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
	.uleb128 0xb
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
	.uleb128 0xc
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
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0x1
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
	.uleb128 0xe
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
	.uleb128 0xf
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
	.uleb128 0x10
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x11
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
	.uleb128 0x12
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x14
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
	.4byte	0x5c
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
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF12:
	.ascii	"s3eEdkThreadFunc\000"
.LASF13:
	.ascii	"bool\000"
.LASF24:
	.ascii	"move_wrap\000"
.LASF14:
	.ascii	"isMovable_wrap\000"
.LASF7:
	.ascii	"long unsigned int\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF22:
	.ascii	"D:\\10kgratExtension\\ExMarmalade\\Project\\TestGam"
	.ascii	"e\\third_party\\Lihui2048Api\\source\\generic\\Lihu"
	.ascii	"i2048Api_register.cpp\000"
.LASF28:
	.ascii	"_Z23Lihui2048ApiRegisterExtv\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF27:
	.ascii	"Lihui2048ApiRegisterExt\000"
.LASF16:
	.ascii	"getBestScore_wrap\000"
.LASF11:
	.ascii	"intptr_t\000"
.LASF4:
	.ascii	"unsigned int\000"
.LASF20:
	.ascii	"flags\000"
.LASF25:
	.ascii	"reset_wrap\000"
.LASF6:
	.ascii	"long long unsigned int\000"
.LASF21:
	.ascii	"GNU C++ 4.8 -fpreprocessed -mbionic -mstructure-siz"
	.ascii	"e-boundary=8 -mfpu=vfp -mfloat-abi=softfp -mthumb-i"
	.ascii	"nterwork -march=armv5te -mtls-dialect=gnu -g -O0 -f"
	.ascii	"no-exceptions -fsigned-char -fno-strict-aliasing -f"
	.ascii	"visibility=hidden -fno-short-enums -fomit-frame-poi"
	.ascii	"nter -fmessage-length=0 -ffunction-sections -fPIC -"
	.ascii	"frtti\000"
.LASF9:
	.ascii	"sizetype\000"
.LASF5:
	.ascii	"long long int\000"
.LASF10:
	.ascii	"char\000"
.LASF19:
	.ascii	"funcPtrs\000"
.LASF29:
	.ascii	"RegisterExt\000"
.LASF18:
	.ascii	"type\000"
.LASF3:
	.ascii	"short int\000"
.LASF23:
	.ascii	"d:\\\\10kgratExtension\\\\ExMarmalade\\\\Project\\\\"
	.ascii	"TestGame\\\\third_party\\\\Lihui2048Api\\\\build_li"
	.ascii	"hui2048api_android_linux_scons_arm\000"
.LASF8:
	.ascii	"long int\000"
.LASF1:
	.ascii	"signed char\000"
.LASF15:
	.ascii	"getCurrentScore_wrap\000"
.LASF17:
	.ascii	"isWin_wrap\000"
.LASF26:
	.ascii	"getValue_wrap\000"
	.ident	"GCC: (GNU) 4.8"
	.section	.note.GNU-stack,"",%progbits
