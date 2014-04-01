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
	.file	"LihuiAD_Baidu.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text._Z17LihuiAD_BaiduInitv,"ax",%progbits
	.align	2
	.global	_Z17LihuiAD_BaiduInitv
	.hidden	_Z17LihuiAD_BaiduInitv
	.type	_Z17LihuiAD_BaiduInitv, %function
_Z17LihuiAD_BaiduInitv:
.LFB0:
	.file 1 "D:\\10kgratExtension\\LihuiAD_Baidu\\source\\generic\\LihuiAD_Baidu.cpp"
	.loc 1 15 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	.cfi_offset 14, -4
	.loc 1 17 0
	bl	_Z26LihuiAD_BaiduInit_platformv(PLT)
	mov	r3, r0
	.loc 1 18 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE0:
	.size	_Z17LihuiAD_BaiduInitv, .-_Z17LihuiAD_BaiduInitv
	.section	.text._Z22LihuiAD_BaiduTerminatev,"ax",%progbits
	.align	2
	.global	_Z22LihuiAD_BaiduTerminatev
	.hidden	_Z22LihuiAD_BaiduTerminatev
	.type	_Z22LihuiAD_BaiduTerminatev, %function
_Z22LihuiAD_BaiduTerminatev:
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
	bl	_Z31LihuiAD_BaiduTerminate_platformv(PLT)
	.loc 1 24 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE1:
	.size	_Z22LihuiAD_BaiduTerminatev, .-_Z22LihuiAD_BaiduTerminatev
	.section	.text.InitBdAd,"ax",%progbits
	.align	2
	.global	InitBdAd
	.hidden	InitBdAd
	.type	InitBdAd, %function
InitBdAd:
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
	bl	_Z17InitBdAd_platformv(PLT)
	.loc 1 29 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE2:
	.size	InitBdAd, .-InitBdAd
	.section	.text.SetBdAdPosition,"ax",%progbits
	.align	2
	.global	SetBdAdPosition
	.hidden	SetBdAdPosition
	.type	SetBdAdPosition, %function
SetBdAdPosition:
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
	bl	_Z24SetBdAdPosition_platformi(PLT)
	.loc 1 34 0
	add	sp, sp, #12
	@ sp needed
	ldr	pc, [sp], #4
	.cfi_endproc
.LFE3:
	.size	SetBdAdPosition, .-SetBdAdPosition
	.section	.text.GetBdAdHeight,"ax",%progbits
	.align	2
	.global	GetBdAdHeight
	.hidden	GetBdAdHeight
	.type	GetBdAdHeight, %function
GetBdAdHeight:
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
	bl	_Z22GetBdAdHeight_platformv(PLT)
	mov	r3, r0
	.loc 1 39 0
	mov	r0, r3
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE4:
	.size	GetBdAdHeight, .-GetBdAdHeight
	.section	.text.showBdInter,"ax",%progbits
	.align	2
	.global	showBdInter
	.hidden	showBdInter
	.type	showBdInter, %function
showBdInter:
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
	bl	_Z20showBdInter_platformv(PLT)
	.loc 1 44 0
	ldmfd	sp!, {r3, pc}
	.cfi_endproc
.LFE5:
	.size	showBdInter, .-showBdInter
	.text
.Letext0:
	.file 2 "e:/marmalade/7.0/s3e/h/s3eTypes.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x10a
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF14
	.byte	0x4
	.4byte	.LASF15
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
	.4byte	.LASF16
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
	.4byte	.LASF16
	.byte	0x2
	.byte	0xd3
	.4byte	0x60
	.uleb128 0x7
	.4byte	.LASF17
	.byte	0x1
	.byte	0xe
	.4byte	.LASF18
	.4byte	0x79
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x8
	.4byte	.LASF10
	.byte	0x1
	.byte	0x14
	.4byte	.LASF19
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF12
	.byte	0x1
	.byte	0x1a
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xa
	.4byte	.LASF20
	.byte	0x1
	.byte	0x1f
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xe7
	.uleb128 0xb
	.ascii	"opt\000"
	.byte	0x1
	.byte	0x1f
	.4byte	0x44
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0xc
	.4byte	.LASF11
	.byte	0x1
	.byte	0x24
	.4byte	0x44
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.4byte	.LASF13
	.byte	0x1
	.byte	0x29
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
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
	.4byte	0x44
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
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF13:
	.ascii	"showBdInter\000"
.LASF11:
	.ascii	"GetBdAdHeight\000"
.LASF8:
	.ascii	"S3E_RESULT_SUCCESS\000"
.LASF0:
	.ascii	"unsigned char\000"
.LASF7:
	.ascii	"long unsigned int\000"
.LASF2:
	.ascii	"short unsigned int\000"
.LASF14:
	.ascii	"GNU C++ 4.8 -fpreprocessed -mbionic -mstructure-siz"
	.ascii	"e-boundary=8 -mfpu=vfp -mfloat-abi=softfp -mthumb-i"
	.ascii	"nterwork -march=armv5te -mtls-dialect=gnu -g -O0 -f"
	.ascii	"no-exceptions -fsigned-char -fno-strict-aliasing -f"
	.ascii	"visibility=hidden -fno-short-enums -fomit-frame-poi"
	.ascii	"nter -fmessage-length=0 -ffunction-sections -fPIC -"
	.ascii	"frtti\000"
.LASF17:
	.ascii	"LihuiAD_BaiduInit\000"
.LASF18:
	.ascii	"_Z17LihuiAD_BaiduInitv\000"
.LASF4:
	.ascii	"unsigned int\000"
.LASF6:
	.ascii	"long long unsigned int\000"
.LASF12:
	.ascii	"InitBdAd\000"
.LASF9:
	.ascii	"S3E_RESULT_ERROR\000"
.LASF19:
	.ascii	"_Z22LihuiAD_BaiduTerminatev\000"
.LASF5:
	.ascii	"long long int\000"
.LASF10:
	.ascii	"LihuiAD_BaiduTerminate\000"
.LASF3:
	.ascii	"short int\000"
.LASF20:
	.ascii	"SetBdAdPosition\000"
.LASF15:
	.ascii	"D:\\10kgratExtension\\LihuiAD_Baidu\\source\\generi"
	.ascii	"c\\LihuiAD_Baidu.cpp\000"
.LASF1:
	.ascii	"signed char\000"
.LASF16:
	.ascii	"s3eResult\000"
	.ident	"GCC: (GNU) 4.8"
	.section	.note.GNU-stack,"",%progbits
