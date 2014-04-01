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
	.file	"LihuiAD_Baidu_register.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.rodata
	.align	2
.LC0:
	.ascii	"LIHUIAD_BAIDU_VERBOSE\000"
	.align	2
.LC1:
	.ascii	"calling LihuiAD_Baidu func on main thread: InitBdAd"
	.ascii	"\000"
	.section	.text._ZL13InitBdAd_wrapv,"ax",%progbits
	.align	2
	.type	_ZL13InitBdAd_wrapv, %function
_ZL13InitBdAd_wrapv:
.LFB33:
	.file 1 "D:\\10kgratExtension\\LihuiAD_Baidu\\source\\generic\\LihuiAD_Baidu_register.cpp"
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
	.word	InitBdAd(GOT)
	.cfi_endproc
.LFE33:
	.size	_ZL13InitBdAd_wrapv, .-_ZL13InitBdAd_wrapv
	.section	.rodata
	.align	2
.LC2:
	.ascii	"calling LihuiAD_Baidu func on main thread: SetBdAdP"
	.ascii	"osition\000"
	.section	.text._ZL20SetBdAdPosition_wrapi,"ax",%progbits
	.align	2
	.type	_ZL20SetBdAdPosition_wrapi, %function
_ZL20SetBdAdPosition_wrapi:
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
	mov	r1, #1
	ldr	r2, [sp, #4]
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 37 0
	add	sp, sp, #8
	@ sp needed
	ldmfd	sp!, {r4, pc}
.L8:
	.align	2
.L7:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC7+8)
	.word	.LC0-(.LPIC4+8)
	.word	.LC0-(.LPIC5+8)
	.word	.LC2-(.LPIC6+8)
	.word	SetBdAdPosition(GOT)
	.cfi_endproc
.LFE34:
	.size	_ZL20SetBdAdPosition_wrapi, .-_ZL20SetBdAdPosition_wrapi
	.section	.rodata
	.align	2
.LC3:
	.ascii	"calling LihuiAD_Baidu func on main thread: GetBdAdH"
	.ascii	"eight\000"
	.section	.text._ZL18GetBdAdHeight_wrapv,"ax",%progbits
	.align	2
	.type	_ZL18GetBdAdHeight_wrapv, %function
_ZL18GetBdAdHeight_wrapv:
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
	.word	GetBdAdHeight(GOT)
	.cfi_endproc
.LFE35:
	.size	_ZL18GetBdAdHeight_wrapv, .-_ZL18GetBdAdHeight_wrapv
	.section	.rodata
	.align	2
.LC4:
	.ascii	"calling LihuiAD_Baidu func on main thread: showBdIn"
	.ascii	"ter\000"
	.section	.text._ZL16showBdInter_wrapv,"ax",%progbits
	.align	2
	.type	_ZL16showBdInter_wrapv, %function
_ZL16showBdInter_wrapv:
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
	ldr	r4, .L16
.LPIC15:
	add	r4, pc, r4
	.loc 1 47 0
	ldr	r3, .L16+4
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
	beq	.L15
	.loc 1 47 0 is_stmt 0 discriminator 1
	ldr	r3, .L16+8
.LPIC13:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceSetTraceChannel(PLT)
	ldr	r3, .L16+12
.LPIC14:
	add	r3, pc, r3
	mov	r0, r3
	bl	IwDebugTraceLinePrintf(PLT)
.L15:
	.loc 1 48 0 is_stmt 1
	ldr	r3, .L16+16
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	bl	s3eEdkThreadRunOnOS(PLT)
	.loc 1 49 0
	ldmfd	sp!, {r4, pc}
.L17:
	.align	2
.L16:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC15+8)
	.word	.LC0-(.LPIC12+8)
	.word	.LC0-(.LPIC13+8)
	.word	.LC4-(.LPIC14+8)
	.word	showBdInter(GOT)
	.cfi_endproc
.LFE36:
	.size	_ZL16showBdInter_wrapv, .-_ZL16showBdInter_wrapv
	.section	.rodata
	.align	2
.LC5:
	.ascii	"LihuiAD_Baidu\000"
	.section	.text._Z24LihuiAD_BaiduRegisterExtv,"ax",%progbits
	.align	2
	.global	_Z24LihuiAD_BaiduRegisterExtv
	.hidden	_Z24LihuiAD_BaiduRegisterExtv
	.type	_Z24LihuiAD_BaiduRegisterExtv, %function
_Z24LihuiAD_BaiduRegisterExtv:
.LFB37:
	.loc 1 59 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #52
	.cfi_def_cfa_offset 56
	.loc 1 59 0
	ldr	r2, .L19
.LPIC20:
	add	r2, pc, r2
.LBB2:
	.loc 1 62 0
	ldr	r3, .L19+4
.LPIC16:
	add	r3, pc, r3
	str	r3, [sp, #32]
	.loc 1 63 0
	ldr	r3, .L19+8
.LPIC17:
	add	r3, pc, r3
	str	r3, [sp, #36]
	.loc 1 64 0
	ldr	r3, .L19+12
.LPIC18:
	add	r3, pc, r3
	str	r3, [sp, #40]
	.loc 1 65 0
	ldr	r3, .L19+16
.LPIC19:
	add	r3, pc, r3
	str	r3, [sp, #44]
	.loc 1 70 0
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
	.loc 1 75 0
	mov	ip, #16
	add	r1, sp, #32
	add	r3, sp, #16
	ldr	r0, .L19+20
	ldr	r0, [r2, r0]
	str	r0, [sp]
	ldr	r0, .L19+24
	ldr	r2, [r2, r0]
	str	r2, [sp, #4]
	mov	r2, #0
	str	r2, [sp, #8]
	ldr	r2, .L19+28
.LPIC21:
	add	r2, pc, r2
	mov	r0, r2
	mov	r2, ip
	bl	s3eEdkRegister(PLT)
.LBE2:
	.loc 1 76 0
	add	sp, sp, #52
	@ sp needed
	ldr	pc, [sp], #4
.L20:
	.align	2
.L19:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC20+8)
	.word	_ZL13InitBdAd_wrapv-(.LPIC16+8)
	.word	_ZL20SetBdAdPosition_wrapi-(.LPIC17+8)
	.word	_ZL18GetBdAdHeight_wrapv-(.LPIC18+8)
	.word	_ZL16showBdInter_wrapv-(.LPIC19+8)
	.word	_Z17LihuiAD_BaiduInitv(GOT)
	.word	_Z22LihuiAD_BaiduTerminatev(GOT)
	.word	.LC5-(.LPIC21+8)
	.cfi_endproc
.LFE37:
	.size	_Z24LihuiAD_BaiduRegisterExtv, .-_Z24LihuiAD_BaiduRegisterExtv
	.section	.text.RegisterExt,"ax",%progbits
	.align	2
	.global	RegisterExt
	.type	RegisterExt, %function
RegisterExt:
.LFB38:
	.loc 1 95 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 96 0
	bl	_Z24LihuiAD_BaiduRegisterExtv(PLT)
	.loc 1 97 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE38:
	.size	RegisterExt, .-RegisterExt
	.text
.Letext0:
	.file 2 "e:/marmalade/7.0/s3e/h/s3eTypes.h"
	.file 3 "e:/marmalade/7.0/s3e/edk/h/s3eEdk.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x166
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF17
	.byte	0x4
	.4byte	.LASF18
	.4byte	.LASF19
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
	.4byte	.LASF13
	.byte	0x1
	.byte	0x1b
	.4byte	.LFB33
	.4byte	.LFE33-.LFB33
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xa
	.4byte	.LASF20
	.byte	0x1
	.byte	0x21
	.4byte	.LFB34
	.4byte	.LFE34-.LFB34
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xd2
	.uleb128 0xb
	.ascii	"opt\000"
	.byte	0x1
	.byte	0x21
	.4byte	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xc
	.4byte	.LASF21
	.byte	0x1
	.byte	0x27
	.4byte	0x48
	.4byte	.LFB35
	.4byte	.LFE35-.LFB35
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF14
	.byte	0x1
	.byte	0x2d
	.4byte	.LFB36
	.4byte	.LFE36-.LFB36
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF22
	.byte	0x1
	.byte	0x3a
	.4byte	.LASF23
	.4byte	.LFB37
	.4byte	.LFE37-.LFB37
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x138
	.uleb128 0xe
	.4byte	.LBB2
	.4byte	.LBE2-.LBB2
	.uleb128 0xf
	.4byte	.LASF15
	.byte	0x1
	.byte	0x3d
	.4byte	0x138
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xf
	.4byte	.LASF16
	.byte	0x1
	.byte	0x46
	.4byte	0x148
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.byte	0
	.byte	0
	.uleb128 0x10
	.4byte	0x6f
	.4byte	0x148
	.uleb128 0x11
	.4byte	0x78
	.byte	0x3
	.byte	0
	.uleb128 0x10
	.4byte	0x48
	.4byte	0x158
	.uleb128 0x11
	.4byte	0x78
	.byte	0x3
	.byte	0
	.uleb128 0x12
	.4byte	.LASF24
	.byte	0x1
	.byte	0x5e
	.4byte	.LFB38
	.4byte	.LFE38-.LFB38
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
	.uleb128 0xc
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
	.uleb128 0xd
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
	.uleb128 0xe
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0xf
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
	.uleb128 0x10
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x12
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
	.4byte	0x44
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
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF5:
	.ascii	"long long int\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF4:
	.ascii	"unsigned int\000"
.LASF16:
	.ascii	"flags\000"
.LASF12:
	.ascii	"s3eEdkThreadFunc\000"
.LASF1:
	.ascii	"signed char\000"
.LASF7:
	.ascii	"long unsigned int\000"
.LASF6:
	.ascii	"long long unsigned int\000"
.LASF13:
	.ascii	"InitBdAd_wrap\000"
.LASF18:
	.ascii	"D:\\10kgratExtension\\LihuiAD_Baidu\\source\\generi"
	.ascii	"c\\LihuiAD_Baidu_register.cpp\000"
.LASF22:
	.ascii	"LihuiAD_BaiduRegisterExt\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF10:
	.ascii	"char\000"
.LASF19:
	.ascii	"d:\\\\10kgratExtension\\\\LihuiAD_Baidu\\\\build_li"
	.ascii	"huiad_baidu_android_linux_scons_arm\000"
.LASF8:
	.ascii	"long int\000"
.LASF3:
	.ascii	"short int\000"
.LASF23:
	.ascii	"_Z24LihuiAD_BaiduRegisterExtv\000"
.LASF24:
	.ascii	"RegisterExt\000"
.LASF14:
	.ascii	"showBdInter_wrap\000"
.LASF15:
	.ascii	"funcPtrs\000"
.LASF21:
	.ascii	"GetBdAdHeight_wrap\000"
.LASF20:
	.ascii	"SetBdAdPosition_wrap\000"
.LASF11:
	.ascii	"intptr_t\000"
.LASF17:
	.ascii	"GNU C++ 4.8 -fpreprocessed -mbionic -mstructure-siz"
	.ascii	"e-boundary=8 -mfpu=vfp -mfloat-abi=softfp -mthumb-i"
	.ascii	"nterwork -march=armv5te -mtls-dialect=gnu -g -O0 -f"
	.ascii	"no-exceptions -fsigned-char -fno-strict-aliasing -f"
	.ascii	"visibility=hidden -fno-short-enums -fomit-frame-poi"
	.ascii	"nter -fmessage-length=0 -ffunction-sections -fPIC -"
	.ascii	"frtti\000"
.LASF9:
	.ascii	"sizetype\000"
	.ident	"GCC: (GNU) 4.8"
	.section	.note.GNU-stack,"",%progbits
