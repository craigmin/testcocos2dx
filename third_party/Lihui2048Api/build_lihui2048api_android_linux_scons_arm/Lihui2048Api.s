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
	.file	"Lihui2048Api.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text._Z16Lihui2048ApiInitv,"ax",%progbits
	.align	2
	.global	_Z16Lihui2048ApiInitv
	.hidden	_Z16Lihui2048ApiInitv
	.type	_Z16Lihui2048ApiInitv, %function
_Z16Lihui2048ApiInitv:
.LFB0:
	.file 1 "D:\\10kgratExtension\\ExMarmalade\\Project\\TestGame\\third_party\\Lihui2048Api\\source\\generic\\Lihui2048Api.cpp"
	.loc 1 15 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 17 0
	bl	_Z25Lihui2048ApiInit_platformv(PLT)
	mov	r3, r0
	.loc 1 18 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE0:
	.size	_Z16Lihui2048ApiInitv, .-_Z16Lihui2048ApiInitv
	.section	.text._Z21Lihui2048ApiTerminatev,"ax",%progbits
	.align	2
	.global	_Z21Lihui2048ApiTerminatev
	.hidden	_Z21Lihui2048ApiTerminatev
	.type	_Z21Lihui2048ApiTerminatev, %function
_Z21Lihui2048ApiTerminatev:
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
	bl	_Z30Lihui2048ApiTerminate_platformv(PLT)
	.loc 1 24 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE1:
	.size	_Z21Lihui2048ApiTerminatev, .-_Z21Lihui2048ApiTerminatev
	.section	.text.isMovable,"ax",%progbits
	.align	2
	.global	isMovable
	.hidden	isMovable
	.type	isMovable, %function
isMovable:
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
	bl	_Z18isMovable_platformv(PLT)
	mov	r3, r0
	.loc 1 29 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE2:
	.size	isMovable, .-isMovable
	.section	.text.move,"ax",%progbits
	.align	2
	.global	move
	.hidden	move
	.type	move, %function
move:
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
	bl	_Z13move_platformi(PLT)
	.loc 1 34 0
	add	sp, sp, #12
	@ sp needed
	ldr	pc, [sp], #4
	.cfi_endproc
.LFE3:
	.size	move, .-move
	.section	.text.getCurrentScore,"ax",%progbits
	.align	2
	.global	getCurrentScore
	.hidden	getCurrentScore
	.type	getCurrentScore, %function
getCurrentScore:
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
	bl	_Z24getCurrentScore_platformv(PLT)
	mov	r3, r0
	.loc 1 39 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE4:
	.size	getCurrentScore, .-getCurrentScore
	.section	.text.getBestScore,"ax",%progbits
	.align	2
	.global	getBestScore
	.hidden	getBestScore
	.type	getBestScore, %function
getBestScore:
.LFB5:
	.loc 1 42 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 43 0
	bl	_Z21getBestScore_platformv(PLT)
	mov	r3, r0
	.loc 1 44 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE5:
	.size	getBestScore, .-getBestScore
	.section	.text.reset,"ax",%progbits
	.align	2
	.global	reset
	.hidden	reset
	.type	reset, %function
reset:
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
	bl	_Z14reset_platformv(PLT)
	.loc 1 49 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE6:
	.size	reset, .-reset
	.section	.text.isWin,"ax",%progbits
	.align	2
	.global	isWin
	.hidden	isWin
	.type	isWin, %function
isWin:
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
	bl	_Z14isWin_platformv(PLT)
	mov	r3, r0
	.loc 1 54 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE7:
	.size	isWin, .-isWin
	.section	.text.getValue,"ax",%progbits
	.align	2
	.global	getValue
	.hidden	getValue
	.type	getValue, %function
getValue:
.LFB8:
	.loc 1 57 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 16
	str	r0, [sp, #4]
	str	r1, [sp]
	.loc 1 58 0
	ldr	r0, [sp, #4]
	ldr	r1, [sp]
	bl	_Z17getValue_platformii(PLT)
	.loc 1 59 0
	mov	r0, r3
	add	sp, sp, #12
	@ sp needed
	ldr	pc, [sp], #4
	.cfi_endproc
.LFE8:
	.size	getValue, .-getValue
	.text
.Letext0:
	.file 2 "e:/marmalade/7.0/s3e/h/s3eTypes.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x16d
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF19
	.byte	0x4
	.4byte	.LASF20
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
	.4byte	.LASF21
	.byte	0x4
	.byte	0x2
	.byte	0xcf
	.4byte	0x79
	.uleb128 0x5
	.4byte	.LASF8
	.sleb128 0
	.uleb128 0x5
	.4byte	.LASF9
	.sleb128 1
	.byte	0
	.uleb128 0x6
	.4byte	.LASF21
	.byte	0x2
	.byte	0xd3
	.4byte	0x60
	.uleb128 0x7
	.4byte	.LASF22
	.byte	0x1
	.byte	0xe
	.4byte	.LASF23
	.4byte	0x79
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x8
	.4byte	.LASF10
	.byte	0x1
	.byte	0x14
	.4byte	.LASF24
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF11
	.byte	0x1
	.byte	0x1a
	.4byte	0xc7
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.4byte	.LASF12
	.uleb128 0xa
	.4byte	.LASF16
	.byte	0x1
	.byte	0x1f
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xf2
	.uleb128 0xb
	.4byte	.LASF18
	.byte	0x1
	.byte	0x1f
	.4byte	0x44
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x9
	.4byte	.LASF13
	.byte	0x1
	.byte	0x24
	.4byte	0x44
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF14
	.byte	0x1
	.byte	0x29
	.4byte	0x44
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xc
	.4byte	.LASF25
	.byte	0x1
	.byte	0x2e
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF15
	.byte	0x1
	.byte	0x33
	.4byte	0xc7
	.4byte	.LFB7
	.4byte	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xd
	.4byte	.LASF17
	.byte	0x1
	.byte	0x38
	.4byte	0x44
	.4byte	.LFB8
	.4byte	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xe
	.ascii	"x\000"
	.byte	0x1
	.byte	0x38
	.4byte	0x44
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0xe
	.ascii	"y\000"
	.byte	0x1
	.byte	0x38
	.4byte	0x44
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
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
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x5c
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
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF25:
	.ascii	"reset\000"
.LASF22:
	.ascii	"Lihui2048ApiInit\000"
.LASF16:
	.ascii	"move\000"
.LASF12:
	.ascii	"bool\000"
.LASF17:
	.ascii	"getValue\000"
.LASF8:
	.ascii	"S3E_RESULT_SUCCESS\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF15:
	.ascii	"isWin\000"
.LASF7:
	.ascii	"long unsigned int\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF19:
	.ascii	"GNU C++ 4.8 -fpreprocessed -mbionic -mstructure-siz"
	.ascii	"e-boundary=8 -mfpu=vfp -mfloat-abi=softfp -mthumb-i"
	.ascii	"nterwork -march=armv5te -mtls-dialect=gnu -g -O0 -f"
	.ascii	"no-exceptions -fsigned-char -fno-strict-aliasing -f"
	.ascii	"visibility=hidden -fno-short-enums -fomit-frame-poi"
	.ascii	"nter -fmessage-length=0 -ffunction-sections -fPIC -"
	.ascii	"frtti\000"
.LASF4:
	.ascii	"unsigned int\000"
.LASF6:
	.ascii	"long long unsigned int\000"
.LASF14:
	.ascii	"getBestScore\000"
.LASF13:
	.ascii	"getCurrentScore\000"
.LASF9:
	.ascii	"S3E_RESULT_ERROR\000"
.LASF24:
	.ascii	"_Z21Lihui2048ApiTerminatev\000"
.LASF5:
	.ascii	"long long int\000"
.LASF11:
	.ascii	"isMovable\000"
.LASF23:
	.ascii	"_Z16Lihui2048ApiInitv\000"
.LASF10:
	.ascii	"Lihui2048ApiTerminate\000"
.LASF18:
	.ascii	"type\000"
.LASF3:
	.ascii	"short int\000"
.LASF1:
	.ascii	"signed char\000"
.LASF21:
	.ascii	"s3eResult\000"
.LASF20:
	.ascii	"D:\\10kgratExtension\\ExMarmalade\\Project\\TestGam"
	.ascii	"e\\third_party\\Lihui2048Api\\source\\generic\\Lihu"
	.ascii	"i2048Api.cpp\000"
	.ident	"GCC: (GNU) 4.8"
	.section	.note.GNU-stack,"",%progbits
