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
	.file	"LihuiSocial_register.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.rodata
	.align	2
.LC0:
	.ascii	"LIHUISOCIAL_VERBOSE\000"
	.align	2
.LC1:
	.ascii	"calling LihuiSocial func on main thread: connectToW"
	.ascii	"X\000"
	.section	.text._ZL16connectToWX_wrapv,"ax",%progbits
	.align	2
	.type	_ZL16connectToWX_wrapv, %function
_ZL16connectToWX_wrapv:
.LFB33:
	.file 1 "D:\\GitRepo\\BB3OriginalSource\\koa\\third_party\\LihuiSocial\\source\\generic\\LihuiSocial_register.cpp"
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
	.word	connectToWX(GOT)
	.cfi_endproc
.LFE33:
	.size	_ZL16connectToWX_wrapv, .-_ZL16connectToWX_wrapv
	.section	.rodata
	.align	2
.LC2:
	.ascii	"calling LihuiSocial func on main thread: sendMessag"
	.ascii	"eOnWX\000"
	.section	.text._ZL20sendMessageOnWX_wrapv,"ax",%progbits
	.align	2
	.type	_ZL20sendMessageOnWX_wrapv, %function
_ZL20sendMessageOnWX_wrapv:
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
	.word	sendMessageOnWX(GOT)
	.cfi_endproc
.LFE34:
	.size	_ZL20sendMessageOnWX_wrapv, .-_ZL20sendMessageOnWX_wrapv
	.section	.rodata
	.align	2
.LC3:
	.ascii	"calling LihuiSocial func on main thread: isWXLogged"
	.ascii	"In\000"
	.section	.text._ZL17isWXLoggedIn_wrapv,"ax",%progbits
	.align	2
	.type	_ZL17isWXLoggedIn_wrapv, %function
_ZL17isWXLoggedIn_wrapv:
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
	ldr	r4, .L12
.LPIC11:
	add	r4, pc, r4
	.loc 1 41 0
	ldr	r3, .L12+4
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
	ldr	r3, .L12+8
.LPIC9:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L12+12
.LPIC10:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L10:
	.loc 1 42 0 is_stmt 1
	ldr	r3, .L12+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	mov	r3, r0
	.loc 1 43 0
	mov	r0, r3
	ldmfd	sp!, {r4, pc}
.L13:
	.align	2
.L12:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC11+8)
	.word	.LC0-(.LPIC8+8)
	.word	.LC0-(.LPIC9+8)
	.word	.LC3-(.LPIC10+8)
	.word	isWXLoggedIn(GOT)
	.cfi_endproc
.LFE35:
	.size	_ZL17isWXLoggedIn_wrapv, .-_ZL17isWXLoggedIn_wrapv
	.section	.text.LihuiSocialRegister,"ax",%progbits
	.align	2
	.global	LihuiSocialRegister
	.hidden	LihuiSocialRegister
	.type	LihuiSocialRegister, %function
LihuiSocialRegister:
.LFB36:
	.loc 1 52 0
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
	.loc 1 53 0
	ldr	r3, [sp, #20]
	ldr	r2, [sp, #12]
	str	r2, [sp]
	mov	r2, #0
	str	r2, [sp, #4]
	ldr	r0, .L16
	mov	r1, #2
	mov	r2, r3
	ldr	r3, [sp, #16]
	bl	s3eEdkCallbacksRegister(PLT)
	mov	r3, r0
	.loc 1 54 0
	mov	r0, r3
	add	sp, sp, #28
	@ sp needed
	ldr	pc, [sp], #4
.L17:
	.align	2
.L16:
	.word	-898311781
	.cfi_endproc
.LFE36:
	.size	LihuiSocialRegister, .-LihuiSocialRegister
	.section	.text.LihuiSocialUnRegister,"ax",%progbits
	.align	2
	.global	LihuiSocialUnRegister
	.hidden	LihuiSocialUnRegister
	.type	LihuiSocialUnRegister, %function
LihuiSocialUnRegister:
.LFB37:
	.loc 1 57 0
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
	.loc 1 58 0
	ldr	r3, [sp, #12]
	mov	r2, #0
	str	r2, [sp]
	ldr	r0, .L20
	mov	r1, #2
	mov	r2, r3
	ldr	r3, [sp, #8]
	bl	s3eEdkCallbacksUnRegister(PLT)
	mov	r3, r0
	.loc 1 59 0
	mov	r0, r3
	add	sp, sp, #20
	@ sp needed
	ldr	pc, [sp], #4
.L21:
	.align	2
.L20:
	.word	-898311781
	.cfi_endproc
.LFE37:
	.size	LihuiSocialUnRegister, .-LihuiSocialUnRegister
	.section	.rodata
	.align	2
.LC4:
	.ascii	"LihuiSocial\000"
	.section	.text._Z22LihuiSocialRegisterExtv,"ax",%progbits
	.align	2
	.global	_Z22LihuiSocialRegisterExtv
	.hidden	_Z22LihuiSocialRegisterExtv
	.type	_Z22LihuiSocialRegisterExtv, %function
_Z22LihuiSocialRegisterExtv:
.LFB38:
	.loc 1 62 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #60
	.cfi_def_cfa_offset 64
	.loc 1 62 0
	ldr	r2, .L23
.LPIC17:
	add	r2, pc, r2
.LBB2:
	.loc 1 65 0
	ldr	r3, .L23+4
.LPIC12:
	add	r3, pc, r3
	str	r3, [sp, #36]
	.loc 1 66 0
	ldr	r3, .L23+8
.LPIC13:
	add	r3, pc, r3
	str	r3, [sp, #40]
	.loc 1 67 0
	ldr	r3, .L23+12
.LPIC14:
	add	r3, pc, r3
	str	r3, [sp, #44]
	.loc 1 68 0
	ldr	r3, .L23+16
.LPIC15:
	add	r3, pc, r3
	str	r3, [sp, #48]
	.loc 1 69 0
	ldr	r3, .L23+20
.LPIC16:
	add	r3, pc, r3
	str	r3, [sp, #52]
	.loc 1 74 0
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
	.loc 1 79 0
	mov	ip, #20
	add	r1, sp, #36
	add	r3, sp, #16
	ldr	r0, .L23+24
	ldr	r0, [r2, r0]
	str	r0, [sp]
	ldr	r0, .L23+28
	ldr	r2, [r2, r0]
	str	r2, [sp, #4]
	mov	r2, #0
	str	r2, [sp, #8]
	ldr	r2, .L23+32
.LPIC18:
	add	r2, pc, r2
	mov	r0, r2
	mov	r2, ip
	bl	s3eEdkRegister(PLT)
.LBE2:
	.loc 1 80 0
	add	sp, sp, #60
	@ sp needed
	ldr	pc, [sp], #4
.L24:
	.align	2
.L23:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC17+8)
	.word	LihuiSocialRegister-(.LPIC12+8)
	.word	LihuiSocialUnRegister-(.LPIC13+8)
	.word	_ZL16connectToWX_wrapv-(.LPIC14+8)
	.word	_ZL20sendMessageOnWX_wrapv-(.LPIC15+8)
	.word	_ZL17isWXLoggedIn_wrapv-(.LPIC16+8)
	.word	_Z15LihuiSocialInitv(GOT)
	.word	_Z20LihuiSocialTerminatev(GOT)
	.word	.LC4-(.LPIC18+8)
	.cfi_endproc
.LFE38:
	.size	_Z22LihuiSocialRegisterExtv, .-_Z22LihuiSocialRegisterExtv
	.section	.text.RegisterExt,"ax",%progbits
	.align	2
	.global	RegisterExt
	.type	RegisterExt, %function
RegisterExt:
.LFB39:
	.loc 1 99 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 100 0
	bl	_Z22LihuiSocialRegisterExtv(PLT)
	.loc 1 101 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE39:
	.size	RegisterExt, .-RegisterExt
	.text
.Letext0:
	.file 2 "e:/marmalade/7.0/s3e/h/s3eTypes.h"
	.file 3 "e:/marmalade/7.0/s3e/edk/h/s3eEdk.h"
	.file 4 "../h/LihuiSocial.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x22d
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF31
	.byte	0x4
	.4byte	.LASF32
	.4byte	.LASF33
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
	.4byte	.LASF8
	.byte	0x2
	.byte	0x54
	.4byte	0x48
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x4
	.4byte	.LASF9
	.byte	0x2
	.byte	0x74
	.4byte	0x48
	.uleb128 0x5
	.4byte	.LASF12
	.byte	0x4
	.byte	0x2
	.byte	0xcf
	.4byte	0x93
	.uleb128 0x6
	.4byte	.LASF10
	.sleb128 0
	.uleb128 0x6
	.4byte	.LASF11
	.sleb128 1
	.byte	0
	.uleb128 0x4
	.4byte	.LASF12
	.byte	0x2
	.byte	0xd3
	.4byte	0x7a
	.uleb128 0x4
	.4byte	.LASF13
	.byte	0x2
	.byte	0xed
	.4byte	0xa9
	.uleb128 0x7
	.byte	0x4
	.4byte	0xaf
	.uleb128 0x8
	.4byte	0x6f
	.4byte	0xc3
	.uleb128 0x9
	.4byte	0xc3
	.uleb128 0x9
	.4byte	0xc3
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF14
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF15
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF16
	.uleb128 0xb
	.4byte	.LASF17
	.byte	0x3
	.2byte	0x283
	.4byte	0xe6
	.uleb128 0x7
	.byte	0x4
	.4byte	0xec
	.uleb128 0xc
	.4byte	0xc3
	.uleb128 0x5
	.4byte	.LASF18
	.byte	0x4
	.byte	0x4
	.byte	0x15
	.4byte	0x110
	.uleb128 0x6
	.4byte	.LASF19
	.sleb128 0
	.uleb128 0x6
	.4byte	.LASF20
	.sleb128 1
	.uleb128 0x6
	.4byte	.LASF21
	.sleb128 2
	.byte	0
	.uleb128 0xd
	.4byte	.LASF22
	.byte	0x1
	.byte	0x1b
	.4byte	.LFB33
	.4byte	.LFE33-.LFB33
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF23
	.byte	0x1
	.byte	0x21
	.4byte	.LFB34
	.4byte	.LFE34-.LFB34
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xe
	.4byte	.LASF34
	.byte	0x1
	.byte	0x27
	.4byte	0x48
	.4byte	.LFB35
	.4byte	.LFE35-.LFB35
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xf
	.4byte	.LASF26
	.byte	0x1
	.byte	0x33
	.4byte	0x93
	.4byte	.LFB36
	.4byte	.LFE36-.LFB36
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x18a
	.uleb128 0x10
	.4byte	.LASF24
	.byte	0x1
	.byte	0x33
	.4byte	0xf1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x11
	.ascii	"fn\000"
	.byte	0x1
	.byte	0x33
	.4byte	0x9e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x10
	.4byte	.LASF25
	.byte	0x1
	.byte	0x33
	.4byte	0xc3
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xf
	.4byte	.LASF27
	.byte	0x1
	.byte	0x38
	.4byte	0x93
	.4byte	.LFB37
	.4byte	.LFE37-.LFB37
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x1bf
	.uleb128 0x10
	.4byte	.LASF24
	.byte	0x1
	.byte	0x38
	.4byte	0xf1
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x11
	.ascii	"fn\000"
	.byte	0x1
	.byte	0x38
	.4byte	0x9e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0x12
	.4byte	.LASF28
	.byte	0x1
	.byte	0x3d
	.4byte	.LASF35
	.4byte	.LFB38
	.4byte	.LFE38-.LFB38
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x1ff
	.uleb128 0x13
	.4byte	.LBB2
	.4byte	.LBE2-.LBB2
	.uleb128 0x14
	.4byte	.LASF29
	.byte	0x1
	.byte	0x40
	.4byte	0x1ff
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x14
	.4byte	.LASF30
	.byte	0x1
	.byte	0x4a
	.4byte	0x20f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.byte	0
	.uleb128 0x15
	.4byte	0xc3
	.4byte	0x20f
	.uleb128 0x16
	.4byte	0xcc
	.byte	0x4
	.byte	0
	.uleb128 0x15
	.4byte	0x48
	.4byte	0x21f
	.uleb128 0x16
	.4byte	0xcc
	.byte	0x4
	.byte	0
	.uleb128 0x17
	.4byte	.LASF36
	.byte	0x1
	.byte	0x62
	.4byte	.LFB39
	.4byte	.LFE39-.LFB39
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
	.uleb128 0x10
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
	.4byte	0x4c
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
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF28:
	.ascii	"LihuiSocialRegisterExt\000"
.LASF35:
	.ascii	"_Z22LihuiSocialRegisterExtv\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF25:
	.ascii	"pData\000"
.LASF18:
	.ascii	"LihuiSocialCallback\000"
.LASF10:
	.ascii	"S3E_RESULT_SUCCESS\000"
.LASF34:
	.ascii	"isWXLoggedIn_wrap\000"
.LASF7:
	.ascii	"long unsigned int\000"
.LASF9:
	.ascii	"int32\000"
.LASF31:
	.ascii	"GNU C++ 4.8 -fpreprocessed -mbionic -mstructure-siz"
	.ascii	"e-boundary=8 -mfpu=vfp -mfloat-abi=softfp -mthumb-i"
	.ascii	"nterwork -march=armv5te -mtls-dialect=gnu -g -O0 -f"
	.ascii	"no-exceptions -fsigned-char -fno-strict-aliasing -f"
	.ascii	"visibility=hidden -fno-short-enums -fomit-frame-poi"
	.ascii	"nter -fmessage-length=0 -ffunction-sections -fPIC -"
	.ascii	"frtti\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF21:
	.ascii	"LIHUISOCIAL_CALLBACK_MAX\000"
.LASF27:
	.ascii	"LihuiSocialUnRegister\000"
.LASF22:
	.ascii	"connectToWX_wrap\000"
.LASF8:
	.ascii	"intptr_t\000"
.LASF4:
	.ascii	"unsigned int\000"
.LASF30:
	.ascii	"flags\000"
.LASF6:
	.ascii	"long long unsigned int\000"
.LASF33:
	.ascii	"d:\\\\GitRepo\\\\BB3OriginalSource\\\\koa\\\\third_"
	.ascii	"party\\\\LihuiSocial\\\\build_lihuisocial_android_l"
	.ascii	"inux_scons_arm\000"
.LASF24:
	.ascii	"cbid\000"
.LASF11:
	.ascii	"S3E_RESULT_ERROR\000"
.LASF20:
	.ascii	"LIHUISOCIAL_CALLBACK_SHARE_FAILED\000"
.LASF15:
	.ascii	"sizetype\000"
.LASF5:
	.ascii	"long long int\000"
.LASF26:
	.ascii	"LihuiSocialRegister\000"
.LASF16:
	.ascii	"char\000"
.LASF29:
	.ascii	"funcPtrs\000"
.LASF36:
	.ascii	"RegisterExt\000"
.LASF13:
	.ascii	"s3eCallback\000"
.LASF3:
	.ascii	"short int\000"
.LASF32:
	.ascii	"D:\\GitRepo\\BB3OriginalSource\\koa\\third_party\\L"
	.ascii	"ihuiSocial\\source\\generic\\LihuiSocial_register.c"
	.ascii	"pp\000"
.LASF23:
	.ascii	"sendMessageOnWX_wrap\000"
.LASF14:
	.ascii	"long int\000"
.LASF1:
	.ascii	"signed char\000"
.LASF12:
	.ascii	"s3eResult\000"
.LASF17:
	.ascii	"s3eEdkThreadFunc\000"
.LASF19:
	.ascii	"LIHUISOCIAL_CALLBACK_SHARE_SUCCESSFUL\000"
	.ident	"GCC: (GNU) 4.8"
	.section	.note.GNU-stack,"",%progbits
