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
	.file	"LihuiLB.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text._Z11LihuiLBInitv,"ax",%progbits
	.align	2
	.global	_Z11LihuiLBInitv
	.hidden	_Z11LihuiLBInitv
	.type	_Z11LihuiLBInitv, %function
_Z11LihuiLBInitv:
.LFB0:
	.file 1 "D:\\10kgratExtension\\ExMarmalade\\LihuiLB\\LihuiLB\\source\\generic\\LihuiLB.cpp"
	.loc 1 15 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 17 0
	bl	_Z20LihuiLBInit_platformv(PLT)
	mov	r3, r0
	.loc 1 18 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE0:
	.size	_Z11LihuiLBInitv, .-_Z11LihuiLBInitv
	.section	.text._Z16LihuiLBTerminatev,"ax",%progbits
	.align	2
	.global	_Z16LihuiLBTerminatev
	.hidden	_Z16LihuiLBTerminatev
	.type	_Z16LihuiLBTerminatev, %function
_Z16LihuiLBTerminatev:
.LFB1:
	.loc 1 21 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 23 0
	bl	_Z25LihuiLBTerminate_platformv(PLT)
	.loc 1 24 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE1:
	.size	_Z16LihuiLBTerminatev, .-_Z16LihuiLBTerminatev
	.section	.text.initLB,"ax",%progbits
	.align	2
	.global	initLB
	.hidden	initLB
	.type	initLB, %function
initLB:
.LFB2:
	.loc 1 27 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 28 0
	bl	_Z15initLB_platformv(PLT)
	.loc 1 29 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE2:
	.size	initLB, .-initLB
	.section	.text.updateScore,"ax",%progbits
	.align	2
	.global	updateScore
	.hidden	updateScore
	.type	updateScore, %function
updateScore:
.LFB3:
	.loc 1 32 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 16
	str	r0, [sp, #4]
	.loc 1 33 0
	ldr	r0, [sp, #4]
	bl	_Z20updateScore_platformi(PLT)
	.loc 1 34 0
	add	sp, sp, #12
	@ sp needed
	ldr	pc, [sp], #4
	.cfi_endproc
.LFE3:
	.size	updateScore, .-updateScore
	.section	.text.receiveRank,"ax",%progbits
	.align	2
	.global	receiveRank
	.hidden	receiveRank
	.type	receiveRank, %function
receiveRank:
.LFB4:
	.loc 1 37 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 38 0
	bl	_Z20receiveRank_platformv(PLT)
	.loc 1 39 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE4:
	.size	receiveRank, .-receiveRank
	.section	.text.getScore,"ax",%progbits
	.align	2
	.global	getScore
	.hidden	getScore
	.type	getScore, %function
getScore:
.LFB5:
	.loc 1 42 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 16
	str	r0, [sp, #4]
	.loc 1 43 0
	ldr	r0, [sp, #4]
	bl	_Z17getScore_platformi(PLT)
	mov	r3, r0
	.loc 1 44 0
	mov	r0, r3
	add	sp, sp, #12
	@ sp needed
	ldr	pc, [sp], #4
	.cfi_endproc
.LFE5:
	.size	getScore, .-getScore
	.section	.text.getUserRank,"ax",%progbits
	.align	2
	.global	getUserRank
	.hidden	getUserRank
	.type	getUserRank, %function
getUserRank:
.LFB6:
	.loc 1 47 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 48 0
	bl	_Z20getUserRank_platformv(PLT)
	mov	r3, r0
	.loc 1 49 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE6:
	.size	getUserRank, .-getUserRank
	.section	.text.getNextWeekLeftSeconds,"ax",%progbits
	.align	2
	.global	getNextWeekLeftSeconds
	.hidden	getNextWeekLeftSeconds
	.type	getNextWeekLeftSeconds, %function
getNextWeekLeftSeconds:
.LFB7:
	.loc 1 52 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 53 0
	bl	_Z31getNextWeekLeftSeconds_platformv(PLT)
	mov	r3, r0
	.loc 1 54 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE7:
	.size	getNextWeekLeftSeconds, .-getNextWeekLeftSeconds
	.section	.text.notUnlimetedLives,"ax",%progbits
	.align	2
	.global	notUnlimetedLives
	.hidden	notUnlimetedLives
	.type	notUnlimetedLives, %function
notUnlimetedLives:
.LFB8:
	.loc 1 57 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 58 0
	bl	_Z26notUnlimetedLives_platformv(PLT)
	mov	r3, r0
	.loc 1 59 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE8:
	.size	notUnlimetedLives, .-notUnlimetedLives
	.section	.text.setBeijingTime,"ax",%progbits
	.align	2
	.global	setBeijingTime
	.hidden	setBeijingTime
	.type	setBeijingTime, %function
setBeijingTime:
.LFB9:
	.loc 1 62 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 63 0
	bl	_Z23setBeijingTime_platformv(PLT)
	.loc 1 64 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE9:
	.size	setBeijingTime, .-setBeijingTime
	.section	.text.notShared,"ax",%progbits
	.align	2
	.global	notShared
	.hidden	notShared
	.type	notShared, %function
notShared:
.LFB10:
	.loc 1 67 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 68 0
	bl	_Z18notShared_platformv(PLT)
	mov	r3, r0
	.loc 1 69 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE10:
	.size	notShared, .-notShared
	.section	.text.setShareTime,"ax",%progbits
	.align	2
	.global	setShareTime
	.hidden	setShareTime
	.type	setShareTime, %function
setShareTime:
.LFB11:
	.loc 1 72 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 73 0
	bl	_Z21setShareTime_platformv(PLT)
	.loc 1 74 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE11:
	.size	setShareTime, .-setShareTime
	.text
.Letext0:
	.file 2 "e:/marmalade/7.0/s3e/h/s3eTypes.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x19e
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF22
	.byte	0x4
	.4byte	.LASF23
	.4byte	.LASF24
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
	.4byte	.LASF25
	.byte	0x4
	.byte	0x2
	.byte	0xcf
	.4byte	0x7d
	.uleb128 0x5
	.4byte	.LASF8
	.sleb128 0
	.uleb128 0x5
	.4byte	.LASF9
	.sleb128 1
	.byte	0
	.uleb128 0x6
	.4byte	.LASF25
	.byte	0x2
	.byte	0xd3
	.4byte	0x64
	.uleb128 0x7
	.4byte	.LASF26
	.byte	0x1
	.byte	0xe
	.4byte	.LASF27
	.4byte	0x7d
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x8
	.4byte	.LASF14
	.byte	0x1
	.byte	0x14
	.4byte	.LASF28
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF10
	.byte	0x1
	.byte	0x1a
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xa
	.4byte	.LASF29
	.byte	0x1
	.byte	0x1f
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xeb
	.uleb128 0xb
	.4byte	.LASF12
	.byte	0x1
	.byte	0x1f
	.4byte	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x9
	.4byte	.LASF11
	.byte	0x1
	.byte	0x24
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xc
	.4byte	.LASF30
	.byte	0x1
	.byte	0x29
	.4byte	0x48
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x124
	.uleb128 0xb
	.4byte	.LASF13
	.byte	0x1
	.byte	0x29
	.4byte	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xd
	.4byte	.LASF15
	.byte	0x1
	.byte	0x2e
	.4byte	0x48
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF16
	.byte	0x1
	.byte	0x33
	.4byte	0x48
	.4byte	.LFB7
	.4byte	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF17
	.byte	0x1
	.byte	0x38
	.4byte	0x163
	.4byte	.LFB8
	.4byte	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.4byte	.LASF18
	.uleb128 0x9
	.4byte	.LASF19
	.byte	0x1
	.byte	0x3d
	.4byte	.LFB9
	.4byte	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF20
	.byte	0x1
	.byte	0x42
	.4byte	0x163
	.4byte	.LFB10
	.4byte	.LFE10-.LFB10
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF21
	.byte	0x1
	.byte	0x47
	.4byte	.LFB11
	.4byte	.LFE11-.LFB11
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
	.uleb128 0x5
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
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
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
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
	.uleb128 0x6e
	.uleb128 0xe
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
	.uleb128 0x8
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
	.byte	0
	.byte	0
	.uleb128 0x9
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
	.uleb128 0xa
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
	.uleb128 0xd
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
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x74
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.4byte	.LFB7
	.4byte	.LFE7-.LFB7
	.4byte	.LFB8
	.4byte	.LFE8-.LFB8
	.4byte	.LFB9
	.4byte	.LFE9-.LFB9
	.4byte	.LFB10
	.4byte	.LFE10-.LFB10
	.4byte	.LFB11
	.4byte	.LFE11-.LFB11
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.4byte	.LFB0
	.4byte	.LFE0
	.4byte	.LFB1
	.4byte	.LFE1
	.4byte	.LFB2
	.4byte	.LFE2
	.4byte	.LFB3
	.4byte	.LFE3
	.4byte	.LFB4
	.4byte	.LFE4
	.4byte	.LFB5
	.4byte	.LFE5
	.4byte	.LFB6
	.4byte	.LFE6
	.4byte	.LFB7
	.4byte	.LFE7
	.4byte	.LFB8
	.4byte	.LFE8
	.4byte	.LFB9
	.4byte	.LFE9
	.4byte	.LFB10
	.4byte	.LFE10
	.4byte	.LFB11
	.4byte	.LFE11
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF16:
	.ascii	"getNextWeekLeftSeconds\000"
.LASF13:
	.ascii	"rank\000"
.LASF18:
	.ascii	"bool\000"
.LASF15:
	.ascii	"getUserRank\000"
.LASF28:
	.ascii	"_Z16LihuiLBTerminatev\000"
.LASF12:
	.ascii	"score\000"
.LASF10:
	.ascii	"initLB\000"
.LASF8:
	.ascii	"S3E_RESULT_SUCCESS\000"
.LASF21:
	.ascii	"setShareTime\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF7:
	.ascii	"long unsigned int\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF22:
	.ascii	"GNU C++ 4.8 -fpreprocessed -mbionic -mstructure-siz"
	.ascii	"e-boundary=8 -mfpu=vfp -mfloat-abi=softfp -mthumb-i"
	.ascii	"nterwork -march=armv5te -mtls-dialect=gnu -g -O0 -f"
	.ascii	"no-exceptions -fsigned-char -fno-strict-aliasing -f"
	.ascii	"visibility=hidden -fno-short-enums -fomit-frame-poi"
	.ascii	"nter -fmessage-length=0 -ffunction-sections -fPIC -"
	.ascii	"frtti\000"
.LASF20:
	.ascii	"notShared\000"
.LASF19:
	.ascii	"setBeijingTime\000"
.LASF24:
	.ascii	"d:\\\\10kgratExtension\\\\ExMarmalade\\\\LihuiLB\\\\"
	.ascii	"LihuiLB\\\\build_lihuilb_android_linux_scons_arm\000"
.LASF30:
	.ascii	"getScore\000"
.LASF11:
	.ascii	"receiveRank\000"
.LASF4:
	.ascii	"unsigned int\000"
.LASF6:
	.ascii	"long long unsigned int\000"
.LASF9:
	.ascii	"S3E_RESULT_ERROR\000"
.LASF27:
	.ascii	"_Z11LihuiLBInitv\000"
.LASF5:
	.ascii	"long long int\000"
.LASF26:
	.ascii	"LihuiLBInit\000"
.LASF3:
	.ascii	"short int\000"
.LASF17:
	.ascii	"notUnlimetedLives\000"
.LASF14:
	.ascii	"LihuiLBTerminate\000"
.LASF1:
	.ascii	"signed char\000"
.LASF23:
	.ascii	"D:\\10kgratExtension\\ExMarmalade\\LihuiLB\\LihuiLB"
	.ascii	"\\source\\generic\\LihuiLB.cpp\000"
.LASF25:
	.ascii	"s3eResult\000"
.LASF29:
	.ascii	"updateScore\000"
	.ident	"GCC: (GNU) 4.8"
	.section	.note.GNU-stack,"",%progbits
