	.include "MPlayDef.s"

	.equ	bgm_grp, voicegroup000
	.equ	bgm_pri, 0
	.equ	bgm_rev, 0
	.equ	bgm_mvl, 127
	.equ	bgm_key, 0
	.equ	bgm_tbs, 1
	.equ	bgm_exg, 0
	.equ	bgm_cmp, 1

	.section .rodata
	.global	bgm
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

bgm_1:
	.byte		VOL   , 127*bgm_mvl/mxv
	.byte	KEYSH , bgm_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 25
	.byte		TIE   , As0 , v036
restart_position:
	.byte		N13   , An1 , v048
	.byte		N52   , As1 
	.byte		N52   , Cs2 , v052
	.byte		N52   , Fn2 , v056
	.byte		N52   , As2 , v060
	.byte		N60   , Cs3 , v064
	.byte		N52   , En3 
	.byte	W52
	.byte	W01
	.byte		N03   , Gs0 , v032
	.byte		N03   , Gs1 , v044
	.byte		N10   , As1 , v048
	.byte		N10   , Cs2 , v052
	.byte		N10   , Fn2 , v056
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N06   
	.byte	W03
	.byte		N22   , Cs3 , v064
	.byte	W04
	.byte		N03   , Fn3 , v068
	.byte	W04
	.byte		        Gs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N03   , As2 , v060
	.byte		N03   , Cs3 , v064
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N03   , As2 , v060
	.byte		N03   , Cs3 , v064
	.byte		N03   , Ds3 
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N03   , As2 , v060
	.byte		N07   , Cs3 , v064
	.byte		N03   , Ds3 
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N03   , As2 , v060
	.byte		N03   , Ds3 , v064
	.byte	W02
@ 001   ----------------------------------------
	.byte	W01
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N03   , As2 , v060
	.byte		N03   , Cs3 , v064
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N03   , As2 , v060
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        As2 , v060
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		N06   , Gs2 , v056
	.byte		N02   , Cs3 , v064
	.byte	W03
	.byte		N07   , As2 , v060
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N12   , Bn2 , v060
	.byte	W04
	.byte		N03   , As2 
	.byte	W04
	.byte		N06   , Ds3 , v064
	.byte	W03
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N15   , Fs4 , v080
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N06   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N14   , Gs3 , v068
	.byte	W04
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		EOT   , As0 
	.byte		N03   , Bn2 , v060
	.byte	W03
	.byte		N07   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N15   , Ds4 , v076
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N06   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N14   , Gs3 , v068
	.byte	W04
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W03
	.byte		N07   , En2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N15   , Ds4 , v076
	.byte	W02
@ 002   ----------------------------------------
	.byte	W02
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		N06   , Fs2 , v056
	.byte		N14   , As3 , v072
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N07   , Ds3 , v064
	.byte	W03
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N07   , Fn1 , v044
	.byte		N03   , Fn2 , v056
	.byte		N14   , Ds4 , v076
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N03   
	.byte		N02   , Ds3 , v064
	.byte	W03
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Fn2 
	.byte		N14   , Gs3 , v068
	.byte	W03
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Cn2 , v048
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        Gs2 , v056
	.byte	W04
	.byte		N06   , Gs1 , v044
	.byte		N03   , Fn2 , v056
	.byte		N14   , Fn3 , v068
	.byte	W03
	.byte		N02   , Gs2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        Gs2 , v056
	.byte	W03
	.byte		N07   , Cn2 , v048
	.byte		N03   , Fn2 , v056
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N06   , Gs1 , v044
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		N02   , Gs2 , v056
	.byte	W03
	.byte		N07   , Fn1 , v044
	.byte		N03   , As1 , v048
	.byte		N14   , As3 , v072
	.byte	W04
	.byte		N03   , Dn2 , v052
	.byte	W03
	.byte		N07   , Ds2 
	.byte		N03   , As2 , v060
	.byte	W02
@ 003   ----------------------------------------
	.byte	W02
	.byte		        Fn2 , v056
	.byte	W04
	.byte		N03   
	.byte		N03   , As2 , v060
	.byte		N14   , Fn3 , v068
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W03
	.byte		N02   , Dn2 , v052
	.byte		N06   , As2 , v060
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N15   , Dn3 , v064
	.byte	W03
	.byte		N03   , Dn2 , v052
	.byte	W04
	.byte		N04   , Fn2 , v056
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fn2 , v056
	.byte	W04
	.byte		N06   , Dn2 , v052
	.byte		N02   , As2 , v060
	.byte		N14   , As3 , v072
	.byte	W03
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		        As1 , v048
	.byte		N07   , Fn2 , v056
	.byte	W03
	.byte		N03   , Dn2 , v052
	.byte	W04
	.byte		N07   , Ds1 , v040
	.byte		N03   , Ds2 , v052
	.byte		N07   , As2 , v060
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N03   
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		N02   , Fs2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N15   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N06   , Fs1 , v044
	.byte		N03   , Ds2 , v052
	.byte		N14   , As3 , v072
	.byte	W04
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N03   
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N07   , Ds2 , v052
	.byte		N15   , Fs3 , v068
	.byte	W02
@ 004   ----------------------------------------
	.byte	W02
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N06   , Gs1 , v044
	.byte		N02   , Ds2 , v052
	.byte		N14   , Fn3 , v068
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N07   , Gs2 
	.byte		N03   , Bn2 , v060
	.byte	W03
	.byte		        Fn2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N14   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N06   , Bn1 , v048
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , Ds2 , v052
	.byte		N14   , Gs3 , v068
	.byte	W03
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N07   , Gs2 
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		        Fn2 , v056
	.byte	W04
	.byte		N06   , Ds2 , v052
	.byte		N14   , Fn3 , v068
	.byte	W03
	.byte		N02   , Fn2 , v056
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		        Fn2 , v056
	.byte	W03
	.byte		N07   , Fs1 , v044
	.byte		N07   , As1 , v048
	.byte		N03   , Fs2 , v056
	.byte		N14   , As3 , v072
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N06   , Ds2 , v052
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		N02   , As2 , v060
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Fs2 , v056
	.byte		N14   , Ds4 , v076
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		N07   , Fs1 , v044
	.byte		N03   , Ds3 , v064
	.byte	W02
@ 005   ----------------------------------------
	.byte	W02
	.byte		        As2 , v060
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , Fn2 , v056
	.byte		N14   , As3 , v072
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		N06   , Ds2 , v052
	.byte		N02   , Ds3 , v064
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Dn2 , v052
	.byte		N03   , Fn2 , v056
	.byte		N15   , Fn4 , v080
	.byte	W03
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Fn1 , v044
	.byte		N03   , Dn3 , v064
	.byte	W04
	.byte		        Gs2 , v056
	.byte	W04
	.byte		N06   , Ds1 , v040
	.byte		N02   , Ds2 , v052
	.byte		N14   , Ds4 , v076
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N03   
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		N04   , Fs2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N14   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		N02   , Fs2 , v056
	.byte	W04
	.byte		N07   , Fs1 , v044
	.byte		N03   , Ds2 , v052
	.byte		N15   , Fs3 , v068
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N03   
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N06   , Ds2 , v052
	.byte		N14   , Ds3 , v064
	.byte	W04
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N07   , Gs1 , v044
	.byte		N03   , Gs2 , v056
	.byte		N15   , Gs3 , v068
	.byte	W02
@ 006   ----------------------------------------
	.byte	W02
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , Gs2 , v056
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        Bn2 , v060
	.byte	W03
	.byte		N06   , Ds2 , v052
	.byte		N02   , Gs2 , v056
	.byte		N06   , Ds3 , v064
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N03   , Ds3 , v064
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , Gs2 , v056
	.byte		N14   , Gs3 , v068
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N06   , Gs2 , v056
	.byte		N02   , Ds3 , v064
	.byte	W03
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N14   , Gs3 , v068
	.byte	W03
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        Bn2 , v060
	.byte	W04
	.byte		N06   , Fn1 , v044
	.byte		N03   , Dn2 , v052
	.byte		N14   , Gs3 , v068
	.byte	W03
	.byte		N02   , Fn2 , v056
	.byte	W04
	.byte		N03   
	.byte		N03   , Gs2 
	.byte	W04
	.byte		        Fn2 
	.byte	W03
	.byte		N07   , Dn2 , v052
	.byte		N14   , Fn3 , v068
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N06   , An1 , v048
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N02   , Fn2 
	.byte	W03
	.byte		N07   , Gs1 , v044
	.byte		N03   , Dn2 , v052
	.byte		N14   , Dn3 , v064
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W03
	.byte		N07   , Gs2 
	.byte	W02
@ 007   ----------------------------------------
	.byte	W02
	.byte		N03   , Fn2 
	.byte	W04
	.byte		        Dn2 , v052
	.byte		N03   , Fn2 , v056
	.byte		N07   , Gs2 
	.byte	W04
	.byte		N03   , Fn2 
	.byte	W03
	.byte		N06   , Dn2 , v052
	.byte		N02   , Gs2 , v056
	.byte	W04
	.byte		N03   , Fn2 
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , As1 , v048
	.byte		N15   , Fn3 , v068
	.byte	W03
	.byte		N03   , Dn2 , v052
	.byte	W04
	.byte		N04   , Fn2 , v056
	.byte		N03   , Gs2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		N06   , Dn2 , v052
	.byte		N14   , Dn3 , v064
	.byte	W03
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		        Fn2 
	.byte	W04
	.byte		N07   , Fn1 , v044
	.byte		N03   , As1 , v048
	.byte		N14   , As2 , v060
	.byte	W04
	.byte		N03   , Dn2 , v052
	.byte	W04
	.byte		        Fn2 , v056
	.byte		N03   , Gs2 
	.byte	W03
	.byte		N02   , Fn2 
	.byte	W04
	.byte		N07   , Dn2 , v052
	.byte		N07   , Gs2 , v056
	.byte	W04
	.byte		N03   , Fn2 
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		N06   , Ds1 , v040
	.byte		N03   , Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N02   
	.byte	W03
	.byte		N03   
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N07   , Ds2 , v052
	.byte		N07   , As2 , v060
	.byte	W02
@ 008   ----------------------------------------
	.byte	W02
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N06   , Fs1 , v044
	.byte		N02   , Ds2 , v052
	.byte		N14   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N03   
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N14   , Fs3 , v068
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N02   , As2 , v060
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , Gs2 , v056
	.byte		N14   , Gs3 , v068
	.byte	W03
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , Gs2 , v056
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        Bn2 , v060
	.byte	W04
	.byte		N06   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N06   , Ds3 , v064
	.byte	W03
	.byte		N02   , Bn2 , v060
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        Bn2 , v060
	.byte	W03
	.byte		N07   , Gs1 , v044
	.byte		N03   , Gs2 , v056
	.byte		N14   , Bn3 , v072
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N06   , Gs2 , v056
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		N07   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N14   , Gs3 , v068
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Ds3 , v064
	.byte	W02
@ 009   ----------------------------------------
	.byte	W02
	.byte		        Bn2 , v060
	.byte	W04
	.byte		N07   , Fn1 , v044
	.byte		N03   , Dn2 , v052
	.byte		N14   , Bn3 , v072
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W03
	.byte		N03   
	.byte		N02   , Gs2 
	.byte	W04
	.byte		N03   , Fn2 
	.byte	W04
	.byte		N07   , Dn2 , v052
	.byte		N15   , Fn3 , v068
	.byte	W03
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N07   , An1 , v048
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		N06   , Gs1 , v044
	.byte		N02   , Dn2 , v052
	.byte		N14   , Dn3 , v064
	.byte	W03
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N07   , Gs2 
	.byte	W03
	.byte		N03   , Fn2 
	.byte	W04
	.byte		        Dn2 , v052
	.byte		N03   , Fn2 , v056
	.byte		N14   , As2 , v060
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N06   , Dn2 , v052
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		N02   , Fn2 
	.byte	W04
	.byte		N07   , Fn1 , v044
	.byte		N03   , As1 , v048
	.byte		N22   , Fn3 , v068
	.byte	W04
	.byte		N03   , Dn2 , v052
	.byte	W03
	.byte		        Fn2 , v056
	.byte		N03   , Gs2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		N06   , Dn2 , v052
	.byte	W04
	.byte		N02   , Fn2 , v056
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , Gs2 , v056
	.byte		N07   , As3 , v072
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W03
	.byte		N07   , Fn1 , v044
	.byte		N03   , As1 , v048
	.byte		N07   , Dn3 , v064
	.byte	W02
@ 010   ----------------------------------------
	.byte	W02
	.byte		N03   , Dn2 , v052
	.byte	W04
	.byte		        Fn2 , v056
	.byte		N03   , Gs2 
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W03
	.byte		N06   , Dn2 , v052
	.byte		N14   , Fn3 , v068
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N07   , Fn0 , v032
	.byte		N07   , Dn2 , v052
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		        Fn2 
	.byte	W04
	.byte		N08   , As0 , v036
	.byte		N15   , As2 , v060
	.byte	W08
	.byte		N07   , Cn1 , v036
	.byte		N03   , As1 , v048
	.byte		N07   , Fn2 , v056
	.byte	W03
	.byte		N03   , Dn2 , v052
	.byte	W04
	.byte		N14   , Dn1 , v040
	.byte		N06   , Dn2 , v052
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N02   , Fn2 , v056
	.byte	W03
	.byte		N03   , Dn2 , v052
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N14   , As0 , v036
	.byte		N07   , As1 , v048
	.byte		N14   , Dn3 , v064
	.byte	W03
	.byte		N03   , Dn2 , v052
	.byte	W04
	.byte		N06   , Fn2 , v056
	.byte	W04
	.byte		N02   , Dn2 , v052
	.byte	W03
	.byte		N07   
	.byte		N07   , Ds2 
	.byte		N14   , Fn3 , v068
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		        Dn2 , v052
	.byte		N07   , Fn2 , v056
	.byte	W04
	.byte		N03   , Dn2 , v052
	.byte	W03
	.byte		N07   , Ds1 , v040
	.byte		N03   , Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N06   , Fn2 
	.byte		N02   , As2 , v060
	.byte	W01
@ 011   ----------------------------------------
	.byte	W02
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N15   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N06   , Fs1 , v044
	.byte		N02   , Ds2 , v052
	.byte		N06   , As2 , v060
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N06   , Fn2 , v056
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N07   , Bn0 , v036
	.byte		N03   , Bn1 , v048
	.byte		N07   , Fs2 , v056
	.byte		N15   , Bn2 , v060
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   , Fs2 , v056
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N06   , Bn1 , v048
	.byte		N14   , Bn2 , v060
	.byte	W04
	.byte		N02   , Cs2 , v052
	.byte		N02   , Ds2 
	.byte	W03
	.byte		N03   , Bn1 , v048
	.byte		N07   , Fs2 , v056
	.byte	W04
	.byte		N03   , Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   , Bn0 , v036
	.byte		N07   , Fs1 , v044
	.byte		N15   , Bn2 , v060
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W03
	.byte		N07   , Gs1 , v044
	.byte		N07   , Fs2 , v056
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N06   , Bn1 
	.byte		N14   , Ds3 , v064
	.byte	W01
@ 012   ----------------------------------------
	.byte	W02
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N07   , Fs2 , v056
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W03
	.byte		N07   , Fn1 , v044
	.byte		N03   , Fn2 , v056
	.byte		N03   , Gs2 
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N06   , Bn1 , v048
	.byte		N06   , Fn2 , v056
	.byte		N02   , Ds3 , v064
	.byte	W03
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Dn2 , v052
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		N07   , Fn1 , v044
	.byte		N07   , Bn1 , v048
	.byte		N03   , Ds3 , v064
	.byte	W03
	.byte		        Gs2 , v056
	.byte	W04
	.byte		N06   , As0 , v036
	.byte		N06   , Fn1 , v044
	.byte		N03   , As1 , v048
	.byte		N10   , Fn2 , v056
	.byte	W04
	.byte		N02   , Dn2 , v052
	.byte	W03
	.byte		N07   , Cn1 , v036
	.byte		N07   , As1 , v048
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		N07   , Dn1 , v040
	.byte		N07   , Fn1 , v044
	.byte		N03   , Dn2 , v052
	.byte	W03
	.byte		        Fn2 , v056
	.byte	W04
	.byte		N06   , As0 , v036
	.byte		N06   , Gs1 , v044
	.byte		N03   , As1 , v048
	.byte	W04
	.byte		N02   , Dn2 , v052
	.byte	W03
	.byte		N28   , Ds1 , v040
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N07   , Fs1 , v044
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N02   , As2 , v060
	.byte	W01
@ 013   ----------------------------------------
	.byte	W02
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , Ds1 , v040
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N06   , Fs1 , v044
	.byte		N02   , Ds2 , v052
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N07   , Ds1 , v040
	.byte		N03   , Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N03   
	.byte	W04
	.byte		N06   , Fn2 
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N07   , Ds2 , v052
	.byte		N07   , As2 , v060
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N06   , Fs1 , v044
	.byte		N03   , Ds2 , v052
	.byte		N14   , Ds3 , v064
	.byte	W04
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N03   
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N07   , Fn3 , v068
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , As2 , v060
	.byte		N07   , Fs3 , v068
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N02   , Ds2 , v052
	.byte		N06   , Bn2 , v060
	.byte	W01
@ 014   ----------------------------------------
	.byte	W02
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , Bn2 , v060
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N07   , Ds2 , v052
	.byte		N14   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N06   , Bn2 , v060
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N14   , Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte		N14   , Fs3 , v068
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , Bn2 , v060
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N06   , Ds2 , v052
	.byte		N14   , Bn3 , v072
	.byte	W04
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N07   , Bn2 , v060
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Fn2 
	.byte		N03   , Gs2 
	.byte	W03
	.byte		N03   
	.byte	W04
	.byte		N06   , Dn3 , v064
	.byte	W04
	.byte		N02   , Gs2 , v056
	.byte	W03
	.byte		N07   , Fn2 
	.byte		N14   , Gs3 , v068
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Dn3 , v064
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		N07   , Dn2 , v052
	.byte		N03   , Fn2 , v056
	.byte		N07   , As2 , v060
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N06   , Dn3 , v064
	.byte	W01
@ 015   ----------------------------------------
	.byte	W02
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Fn2 
	.byte		N07   , Bn2 , v060
	.byte		N07   , Bn3 , v072
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		N07   , As2 , v060
	.byte		N07   , Dn3 , v064
	.byte		N07   , As3 , v072
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N02   , Ds2 , v052
	.byte		N02   , Fs2 , v056
	.byte		N06   , Bn3 , v072
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        As2 , v060
	.byte		N07   , Ds3 , v064
	.byte		N07   , As3 , v072
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N07   , Gs3 , v068
	.byte	W03
	.byte		N10   , Fs2 , v056
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte		N06   , Fs3 , v068
	.byte	W04
	.byte		N02   , Ds2 , v052
	.byte	W03
	.byte		N03   , Fn2 , v056
	.byte		N03   , Gs2 
	.byte		N07   , Fn3 , v068
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Ds3 , v064
	.byte	W03
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N06   , Fn2 
	.byte		N06   , Dn3 , v064
	.byte	W04
	.byte		N02   , Gs2 , v056
	.byte	W03
	.byte		N07   , Dn2 , v052
	.byte		N03   , Bn2 , v060
	.byte		N07   , Dn3 , v064
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N07   , As2 , v060
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        As2 , v060
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N02   , Ds2 , v052
	.byte		N02   , Fs2 , v056
	.byte	W01
@ 016   ----------------------------------------
	.byte	W02
	.byte		N11   
	.byte	W04
	.byte		N07   , Fn2 
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W03
	.byte		N03   
	.byte		N28   , As3 , v072
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N06   , Ds3 , v064
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N11   
	.byte	W04
	.byte		N07   , Fn2 
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N06   , Gs2 , v056
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N02   
	.byte	W03
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N14   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N07   , As2 , v060
	.byte	W03
	.byte		N03   , Bn2 
	.byte	W04
	.byte		N03   
	.byte		N06   , Ds3 , v064
	.byte	W04
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		N07   , Gs2 , v056
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W03
	.byte		N07   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N06   , Ds3 , v064
	.byte	W01
@ 017   ----------------------------------------
	.byte	W02
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte		N15   , Fs3 , v068
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		        Ds3 , v064
	.byte		N07   , As3 , v072
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N14   , Fs2 , v056
	.byte		N14   , As3 , v072
	.byte	W03
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        Ds3 , v064
	.byte	W04
	.byte		        As2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte		N03   , As2 , v060
	.byte		N14   , Ds4 , v076
	.byte	W03
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N06   , Ds3 , v064
	.byte	W04
	.byte		N02   , As2 , v060
	.byte	W03
	.byte		N07   , Fs2 , v056
	.byte		N15   , Fs4 , v080
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N07   , Ds3 , v064
	.byte	W03
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N06   , Gs1 , v044
	.byte		N03   , Dn2 , v052
	.byte		N14   , Gs2 , v056
	.byte		N08   , Gs3 , v068
	.byte	W04
	.byte		N02   , Fn2 , v056
	.byte	W03
	.byte		N03   , Dn3 , v064
	.byte	W02
	.byte		N08   , Gs3 , v068
	.byte	W02
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		        Dn2 , v052
	.byte		N03   , Fn2 , v056
	.byte		N15   , Fn3 , v068
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W03
	.byte		N07   , As1 , v048
	.byte	W04
	.byte		N03   , Fn2 , v056
	.byte	W04
	.byte		N02   , Ds2 , v052
	.byte		N02   , Fs2 , v056
	.byte		N06   , As2 , v060
	.byte	W01
@ 018   ----------------------------------------
	.byte	W02
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        As2 , v060
	.byte		N07   , Fs3 , v068
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N14   , Ds3 , v064
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N06   , As1 , v048
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N14   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		        Ds3 , v064
	.byte		N06   , Fn3 , v068
	.byte	W03
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N09   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N09   , Gs3 , v068
	.byte	W04
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Ds3 , v064
	.byte	W03
	.byte		N04   , Gs3 , v068
	.byte	W01
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N14   , Dn2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		N03   
	.byte	W04
	.byte		N06   , Cn2 , v048
	.byte		N03   , Dn3 , v064
	.byte	W01
	.byte		N06   , Fn3 , v068
	.byte	W03
	.byte		N02   , As2 , v060
	.byte	W03
	.byte		N07   , Dn2 , v052
	.byte		N10   , Gs2 , v056
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , Dn3 , v064
	.byte	W07
	.byte		N15   , Ds3 
	.byte	W08
	.byte		N08   , Gs2 , v056
	.byte	W01
@ 019   ----------------------------------------
	.byte	W07
	.byte		N07   , Ds2 , v052
	.byte		N15   , Gs2 , v056
	.byte	W07
	.byte		N03   , Bn1 , v048
	.byte	W08
	.byte		N07   , Gs1 , v044
	.byte		N15   , Bn2 , v060
	.byte	W08
	.byte		N07   , Gs2 , v056
	.byte	W07
	.byte		N08   , Ds2 , v052
	.byte		N15   , Gs2 , v056
	.byte	W09
	.byte		N03   , Bn1 , v048
	.byte	W07
	.byte		N07   , Fs1 , v044
	.byte		N15   , Fs3 , v068
	.byte	W07
	.byte		N07   , Fs2 , v056
	.byte	W08
	.byte		        Ds2 , v052
	.byte		N15   , Fs2 , v056
	.byte	W08
	.byte		N03   , As1 , v048
	.byte	W08
	.byte		N07   , Fs1 , v044
	.byte		N15   , As2 , v060
	.byte	W07
	.byte		N07   , Fs2 , v056
	.byte	W05
@ 020   ----------------------------------------
	.byte	W03
	.byte		        Ds2 , v052
	.byte		N15   , Fs2 , v056
	.byte	W08
	.byte		N03   , As1 , v048
	.byte	W07
	.byte		N07   , Gs1 , v044
	.byte		N15   , En3 , v064
	.byte	W08
	.byte		N07   , En2 , v052
	.byte	W08
	.byte		        Cs2 
	.byte		N14   , En2 
	.byte	W07
	.byte		N03   , Gs1 , v044
	.byte	W07
	.byte		N08   , En1 , v040
	.byte		N16   , Gs2 , v056
	.byte	W09
	.byte		N07   , En2 , v052
	.byte	W07
	.byte		        Cs2 
	.byte		N14   , En2 
	.byte	W08
	.byte		N03   , Gs1 , v044
	.byte	W07
	.byte		N07   , Fs1 
	.byte		N16   , Cs3 , v064
	.byte	W08
	.byte		N08   , En2 , v052
	.byte	W08
	.byte		N07   , Cs2 
	.byte		N14   , En2 
	.byte	W01
@ 021   ----------------------------------------
	.byte	W07
	.byte		N02   , Fs1 , v044
	.byte	W07
	.byte		N07   , En1 , v040
	.byte		N15   , Fs2 , v056
	.byte	W07
	.byte		N07   , En2 , v052
	.byte	W08
	.byte		N08   , Cs2 
	.byte		N15   , En2 
	.byte	W08
	.byte		N02   , Fs1 , v044
	.byte	W07
	.byte		N07   
	.byte		N03   , Ds2 , v052
	.byte		N15   , Fs3 , v068
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N02   , Ds2 , v052
	.byte		N14   , Ds3 , v064
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N07   , Gs1 , v044
	.byte		N03   , Gs2 , v056
	.byte		N28   , Bn3 , v072
	.byte	W04
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N03   , Ds3 , v064
	.byte	W03
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        Bn2 , v060
	.byte	W04
@ 022   ----------------------------------------
	.byte		N07   , Gs1 , v044
	.byte		N03   , Bn2 , v060
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        Bn2 , v060
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N03   , En2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N06   , As3 , v072
	.byte	W04
	.byte		N02   , Gs2 , v056
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Cs3 , v064
	.byte		N07   , Gs3 , v068
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		N07   , Cs2 , v052
	.byte		N03   , En2 
	.byte		N07   , Fs3 , v068
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Ds2 , v052
	.byte		N03   , Cs3 , v064
	.byte		N14   , En3 
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		N06   , Cs2 , v052
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N07   , Fs2 , v056
	.byte		N03   , Cs3 , v064
	.byte	W04
	.byte		        As2 , v060
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , Fs2 , v056
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N06   , Fs1 , v044
	.byte		N02   , Cs3 , v064
	.byte	W03
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , Bn1 , v048
	.byte		N07   , Bn2 , v060
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W03
	.byte		N07   , En2 
	.byte		N07   , Cs3 , v064
	.byte		N07   , Ds3 
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N06   , Ds3 , v064
	.byte	W03
	.byte		N02   , Gs2 , v056
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Bn2 , v060
	.byte		N07   , Fs3 , v068
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
@ 023   ----------------------------------------
	.byte		N07   , En1 , v040
	.byte		N03   , Bn1 , v048
	.byte		N07   , Gs3 , v068
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N06   , Cs2 
	.byte		N03   , Gs2 , v056
	.byte		N06   , Cs3 , v064
	.byte	W04
	.byte		N02   , En2 , v052
	.byte	W03
	.byte		N07   , Ds2 
	.byte		N07   , Bn3 , v072
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W03
	.byte		N07   , Gs1 , v044
	.byte		N03   , En2 , v052
	.byte		N03   , Gs2 , v056
	.byte		N07   , Gs3 , v068
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N14   , As1 , v048
	.byte		N03   , Cs2 , v052
	.byte		N07   , Fs2 , v056
	.byte		N07   , Fs3 , v068
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W03
	.byte		N02   , Fs2 , v056
	.byte		N06   , En3 , v064
	.byte	W03
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N15   , Fs1 , v044
	.byte		N03   , Cs2 , v052
	.byte		N07   , Ds3 , v064
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		        Cs2 
	.byte		N07   , Cs3 , v064
	.byte	W04
	.byte		N03   , As1 , v048
	.byte	W04
	.byte		N28   , Fs1 , v044
	.byte		N02   , Bn1 , v048
	.byte		N02   , Ds2 , v052
	.byte	W03
	.byte		N03   
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , Bn1 
	.byte	W04
	.byte		        Ds2 , v052
	.byte	W04
	.byte		N06   , Bn1 , v048
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N02   , Ds2 , v052
	.byte	W03
	.byte		N07   , Gs1 , v044
	.byte		N16   , En3 , v064
	.byte	W08
@ 024   ----------------------------------------
	.byte		N08   , As1 , v048
	.byte		N08   , Gs2 , v056
	.byte	W09
	.byte		N07   , Bn1 , v048
	.byte		N07   , En2 , v052
	.byte		N14   , Gs2 , v056
	.byte	W07
	.byte		N02   , Gs1 , v044
	.byte		N06   , Bn1 , v048
	.byte	W08
	.byte		N07   , Gs1 , v044
	.byte		N07   , En2 , v052
	.byte		N15   , Bn2 , v060
	.byte	W07
	.byte		N07   , Gs2 , v056
	.byte	W08
	.byte		N08   , En2 , v052
	.byte		N15   , Gs2 , v056
	.byte	W08
	.byte		N06   , Bn1 , v048
	.byte	W07
	.byte		N07   , En1 , v040
	.byte		N07   , Ds2 , v052
	.byte		N07   , Fs2 , v056
	.byte	W08
	.byte		        Bn1 , v048
	.byte		N07   , En2 , v052
	.byte		N07   , Fs2 , v056
	.byte	W07
	.byte		        Cs2 , v052
	.byte		N07   , Ds2 
	.byte		N36   , Fs2 , v056
	.byte	W08
	.byte		N07   , Fs1 , v044
	.byte		N07   , Cs2 , v052
	.byte		N07   , Ds2 
	.byte	W07
	.byte		        Ds1 , v040
	.byte		N07   , As1 , v048
	.byte		N07   , Ds2 , v052
	.byte	W08
	.byte		        Bn1 , v048
	.byte		N07   , Ds2 , v052
	.byte		N07   , As2 , v060
	.byte	W04
@ 025   ----------------------------------------
	.byte	W04
	.byte		N10   , Bn1 , v048
	.byte		N08   , Cs2 , v052
	.byte		N08   , Gs2 , v056
	.byte	W08
	.byte		N06   , Fs1 , v044
	.byte		N06   , Ds2 , v052
	.byte		N06   , Fs2 , v056
	.byte	W07
	.byte		N03   , Cs2 , v052
	.byte		N03   , En2 
	.byte		N07   , Gs2 , v056
	.byte	W03
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N07   , Cs2 
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        En2 , v052
	.byte	W04
	.byte		N06   , Gs1 , v044
	.byte		N06   , Gs2 , v056
	.byte		N03   , Cs4 , v076
	.byte	W03
	.byte		N02   , Cs3 , v064
	.byte		N02   , En3 
	.byte	W03
	.byte		N07   , Cs2 , v052
	.byte		N03   , En3 , v064
	.byte		N03   , Cs4 , v076
	.byte	W04
	.byte		        En2 , v052
	.byte		N03   , En4 , v076
	.byte	W04
	.byte		N07   , Cs1 , v040
	.byte		N03   , Cs2 , v052
	.byte		N04   , Fs4 , v080
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W01
	.byte		N05   , En4 , v076
	.byte	W03
	.byte		N06   , Cs2 , v052
	.byte		N03   , Gs2 , v056
	.byte	W02
	.byte		N04   , Ds4 , v076
	.byte	W02
	.byte		N02   , En2 , v052
	.byte	W03
	.byte		N07   , Gs1 , v044
	.byte		N07   , Gs2 , v056
	.byte		N03   , Cs4 , v076
	.byte	W04
	.byte		        Cs3 , v064
	.byte		N03   , En3 
	.byte	W04
	.byte		N07   , Cs2 , v052
	.byte		N03   , En3 , v064
	.byte		N01   , Cs4 , v076
	.byte	W01
	.byte		N02   , Ds4 
	.byte	W02
	.byte		N03   , En2 , v052
	.byte		N03   , En4 , v076
	.byte	W04
	.byte		        As1 , v048
	.byte		N14   , Cs2 , v052
	.byte		N28   , Fs4 , v080
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W03
	.byte		N02   
	.byte		N02   , As2 , v060
	.byte	W03
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N07   , As2 , v060
	.byte		N03   , Cs4 , v076
	.byte	W04
@ 026   ----------------------------------------
	.byte		        Cs3 , v064
	.byte		N03   , En3 
	.byte	W04
	.byte		N07   , Cs2 , v052
	.byte		N03   , En3 , v064
	.byte		N03   , Cs4 , v076
	.byte	W04
	.byte		        En2 , v052
	.byte		N03   , En4 , v076
	.byte	W04
	.byte		N06   , En1 , v040
	.byte		N02   , As1 , v048
	.byte		N07   , Cs2 , v052
	.byte		N04   , Gs4 , v080
	.byte	W03
	.byte		N03   , En2 , v052
	.byte	W01
	.byte		N04   , Fs4 , v080
	.byte	W03
	.byte		N14   , Cs2 , v052
	.byte		N03   , As2 , v060
	.byte	W02
	.byte		N04   , En4 , v076
	.byte	W01
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N07   , As2 , v060
	.byte		N03   , Cs4 , v076
	.byte	W04
	.byte		        Cs3 , v064
	.byte		N03   , En3 
	.byte	W04
	.byte		N06   , Cs2 , v052
	.byte		N03   , Cs3 , v064
	.byte		N03   , En3 
	.byte		N01   , Cs4 , v076
	.byte	W01
	.byte		N02   , Ds4 
	.byte	W02
	.byte		        As2 , v060
	.byte		N02   , En4 , v076
	.byte	W03
	.byte		N07   , Ds1 , v040
	.byte		N03   , Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte		N28   , Fs4 , v080
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N03   
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte	W04
	.byte		N06   , Fs1 , v044
	.byte		N06   , Fs2 , v056
	.byte		N03   , Bn3 , v072
	.byte	W04
	.byte		N02   , Bn2 , v060
	.byte		N02   , Fs3 , v068
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Fs3 , v068
	.byte		N01   , Bn3 , v072
	.byte	W01
	.byte		N02   , Cs4 , v076
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte		N03   , Ds4 , v076
	.byte	W04
	.byte		N07   , Bn0 , v036
	.byte		N07   , Bn2 , v060
	.byte		N04   , En4 , v076
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W01
	.byte		N05   , Ds4 , v076
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Bn2 , v060
	.byte	W03
	.byte		N04   , Cs4 , v076
	.byte	W01
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N06   , Fs1 , v044
	.byte		N02   , Bn2 , v060
	.byte		N02   , Bn3 , v072
	.byte		N10   , Fs4 , v080
	.byte	W03
	.byte		N03   , Bn2 , v060
	.byte		N03   , Fs3 , v068
	.byte	W04
	.byte		N15   , Bn1 , v048
	.byte		N03   , Ds3 , v064
	.byte		N03   , Fs3 , v068
	.byte		N03   , Bn3 , v072
	.byte	W04
@ 027   ----------------------------------------
	.byte		        Fs2 , v056
	.byte		N03   , Ds4 , v076
	.byte	W04
	.byte		        En2 , v052
	.byte		N24   , En4 , v076
	.byte	W04
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N06   , En2 , v052
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N07   , Bn2 , v060
	.byte		N03   , Bn3 , v072
	.byte	W03
	.byte		        En3 , v064
	.byte		N03   , Gs3 , v068
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N03   , Gs3 , v068
	.byte		N03   , Bn3 , v072
	.byte	W04
	.byte		        En2 , v052
	.byte		N03   , En4 , v076
	.byte	W04
	.byte		N06   , Fs1 , v044
	.byte		N03   , Gs2 , v056
	.byte		N28   , Fs4 , v080
	.byte	W03
	.byte		N02   , Gs2 , v056
	.byte	W03
	.byte		N07   , Fs2 
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		        Gs2 , v056
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N07   , Bn2 , v060
	.byte		N03   , Bn3 , v072
	.byte	W04
	.byte		        En3 , v064
	.byte		N03   , Gs3 , v068
	.byte	W04
	.byte		N06   , En2 , v052
	.byte		N03   , En3 , v064
	.byte		N03   , Gs3 , v068
	.byte		N03   , Bn3 , v072
	.byte	W04
	.byte		N02   , Gs2 , v056
	.byte		N02   , En4 , v076
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte		N14   , Ds3 , v064
	.byte		N14   , Fs3 , v068
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , En2 , v052
	.byte		N03   , Bn2 , v060
	.byte	W03
	.byte		        Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte		N14   , Bn3 , v072
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N06   , Bn2 , v060
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , Gs2 , v056
	.byte		N15   , Bn3 , v072
	.byte	W04
@ 028   ----------------------------------------
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		N07   , Fs2 , v056
	.byte		N03   , Ds3 , v064
	.byte	W04
	.byte		        Bn2 , v060
	.byte	W04
	.byte		N02   , Ds2 , v052
	.byte		N06   , En2 
	.byte		N14   , Ds3 , v064
	.byte		N14   , Gs3 , v068
	.byte	W03
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		N03   
	.byte		N03   , Bn2 , v060
	.byte	W03
	.byte		N11   , Gs2 , v056
	.byte	W04
	.byte		N03   , Cs2 , v052
	.byte		N14   , En3 , v064
	.byte	W04
	.byte		N07   , En2 , v052
	.byte	W04
	.byte		N06   , Ds3 , v064
	.byte	W03
	.byte		N02   , En2 , v052
	.byte	W03
	.byte		N03   , Cs2 
	.byte		N03   , En2 
	.byte		N07   , Gs2 , v056
	.byte		N15   , Cs3 , v064
	.byte	W04
	.byte		N07   , En2 , v052
	.byte	W04
	.byte		        Gs2 , v056
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		        Fs2 , v056
	.byte		N03   , As2 , v060
	.byte		N28   , En3 , v064
	.byte	W04
	.byte		N02   , As2 , v060
	.byte	W03
	.byte		N07   , Fs2 , v056
	.byte		N07   , Gs2 
	.byte	W04
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N07   , Fs1 , v044
	.byte		N03   , Cs2 , v052
	.byte		N07   , As2 , v060
	.byte	W03
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N07   , Cs2 
	.byte		N03   , As2 , v060
	.byte		N07   , Bn2 
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W03
	.byte		N06   , Bn0 , v036
	.byte		N02   , Bn1 , v048
	.byte		N14   , Ds3 , v064
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   , En2 
	.byte		N03   , Fs2 , v056
	.byte	W04
@ 029   ----------------------------------------
	.byte		        Ds2 , v052
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte		N14   , Bn2 , v060
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N06   , Fs2 , v056
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N14   , Ds3 , v064
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   , En2 
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N02   , Ds2 , v052
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N03   
	.byte		N03   , Bn2 , v060
	.byte	W04
	.byte		        Ds2 , v052
	.byte		N11   , Fs2 , v056
	.byte	W04
	.byte		N03   , Cs2 , v052
	.byte		N07   , Gs2 , v056
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N06   , Ds2 
	.byte		N06   , Fs2 , v056
	.byte		N03   , Gs2 
	.byte	W04
	.byte		N02   , En2 , v052
	.byte	W03
	.byte		N07   , Cs2 
	.byte		N07   , Gs2 , v056
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N03   
	.byte		N03   , Gs2 , v056
	.byte		N07   , As2 , v060
	.byte	W03
	.byte		N11   , En2 , v052
	.byte	W04
	.byte		N03   , Fs2 , v056
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N03   
	.byte	W03
	.byte		N02   , Fs2 , v056
	.byte		N06   , Gs2 
	.byte		N02   , Cs3 , v064
	.byte		N06   , Fs3 , v068
	.byte	W03
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , Cs2 , v052
	.byte		N15   , En3 , v064
	.byte		N03   , Fs3 , v068
	.byte	W04
@ 030   ----------------------------------------
	.byte		        En2 , v052
	.byte		N03   , Gs3 , v068
	.byte	W04
	.byte		N07   , Cs2 , v052
	.byte		N03   , As2 , v060
	.byte		N03   , As3 , v072
	.byte	W04
	.byte		        En2 , v052
	.byte		N03   , Bn3 , v072
	.byte	W04
	.byte		N06   , Bn1 , v048
	.byte		N06   , Bn2 , v060
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   , En2 
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Ds2 , v052
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N06   , Fs2 , v056
	.byte	W03
	.byte		N02   , Ds2 , v052
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N07   , En2 
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N02   
	.byte	W03
	.byte		N07   , Fs2 , v056
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		        Cs2 
	.byte		N11   , Fs2 , v056
	.byte	W03
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N06   
	.byte	W03
	.byte		        As1 , v048
	.byte		N14   , Cs2 , v052
	.byte	W03
	.byte		N07   , En2 
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N03   , Fs2 , v056
	.byte	W04
@ 031   ----------------------------------------
	.byte		N07   , En2 , v052
	.byte	W04
	.byte		        Cs2 
	.byte	W04
	.byte		N03   , En2 
	.byte	W04
	.byte		N06   , Cs2 
	.byte		N06   , Ds2 
	.byte		N02   , Fs2 , v056
	.byte	W03
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N07   , As1 , v048
	.byte		N03   , En2 , v052
	.byte		N03   , As2 , v060
	.byte	W03
	.byte		        En2 , v052
	.byte	W04
	.byte		N07   , Cs2 
	.byte		N03   , Fs2 , v056
	.byte		N07   , As2 , v060
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N06   , Bn0 , v036
	.byte		N03   , Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		N07   , Cs2 
	.byte		N07   , En2 
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N14   , Cs2 , v052
	.byte		N03   , Ds2 
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N06   , Fs2 , v056
	.byte	W04
	.byte		N02   , Ds2 , v052
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N14   , Cs2 , v052
	.byte	W04
	.byte		N03   , Ds2 
	.byte	W04
	.byte		N07   , En2 
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Ds2 , v052
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N07   , Cs2 , v052
	.byte		N03   , Ds2 
	.byte	W04
	.byte		N03   
	.byte	W03
	.byte		N02   
	.byte		N14   , Fs2 , v056
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N15   , Cs1 , v040
	.byte		N03   , Cs2 , v052
	.byte		N03   , En2 
	.byte	W04
@ 032   ----------------------------------------
	.byte		N03   
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N28   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        En2 , v052
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N14   , Cs2 , v052
	.byte	W03
	.byte		N03   , En2 
	.byte	W04
	.byte		N07   , Bn1 , v048
	.byte		N03   , Gs2 , v056
	.byte	W03
	.byte		        En2 , v052
	.byte	W04
	.byte		N07   , Cs2 
	.byte	W04
	.byte		N03   , En2 
	.byte	W04
	.byte		N06   , Cs2 
	.byte		N22   , Ds2 
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		N02   , En2 , v052
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , En2 , v052
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        En2 , v052
	.byte	W04
	.byte		N07   , Cs2 
	.byte		N03   , Fs2 , v056
	.byte		N07   , As2 , v060
	.byte	W04
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N06   , Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   
	.byte	W03
	.byte		        En2 
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		        Ds2 , v052
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte	W03
	.byte		N03   
	.byte	W04
	.byte		N07   , Fs2 , v056
	.byte	W04
	.byte		N03   , Ds2 , v052
	.byte	W03
	.byte		N06   , Bn1 , v048
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N07   , En2 
	.byte		N03   , Fs2 , v056
	.byte	W04
@ 033   ----------------------------------------
	.byte		        Ds2 , v052
	.byte	W04
	.byte		        Bn1 , v048
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N06   , Fs2 , v056
	.byte	W03
	.byte		N03   , Ds2 , v052
	.byte	W04
	.byte		N14   , Cs1 , v040
	.byte		N03   , Cs2 , v052
	.byte	W03
	.byte		        En2 
	.byte	W04
	.byte		N07   , Gs1 , v044
	.byte		N28   , Ds2 , v052
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        En2 , v052
	.byte	W04
	.byte		N06   , As1 , v048
	.byte		N14   , Cs2 , v052
	.byte	W03
	.byte		N02   , En2 
	.byte	W03
	.byte		N07   , Bn1 , v048
	.byte		N03   , Gs2 , v056
	.byte	W04
	.byte		        En2 , v052
	.byte	W04
	.byte		N07   , Cs2 
	.byte	W04
	.byte		N03   , En2 
	.byte	W04
	.byte		N06   , Cs2 
	.byte		N28   , Ds2 
	.byte		N03   , Fs2 , v056
	.byte	W04
	.byte		N02   , En2 , v052
	.byte	W03
	.byte		N07   , As1 , v048
	.byte		N03   , En2 , v052
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		        En2 , v052
	.byte	W04
	.byte		N07   , Cs2 
	.byte		N03   , Fs2 , v056
	.byte		N07   , As2 , v060
	.byte	W03
	.byte		N03   , En2 , v052
	.byte	W04
	.byte		N15   , Bn1 , v048
	.byte		N30   , Bn2 , v060
	.byte	W07
	.byte		N08   , Ds2 , v052
	.byte	W09
	.byte		N07   , Cs2 
	.byte		N15   , Fs2 , v056
	.byte	W02
@ 034   ----------------------------------------
	.byte	W05
	.byte		N07   , Bn1 , v048
	.byte	W08
	.byte		N15   , As1 
	.byte	W08
	.byte		N07   , Cs2 , v052
	.byte	W07
	.byte		        Bn1 , v048
	.byte		N15   , En2 , v052
	.byte	W08
	.byte		N07   , Cs2 
	.byte	W08
	.byte		N03   , As1 , v048
	.byte		N18   , Fs2 , v056
	.byte	W04
	.byte		N03   , Bn1 , v048
	.byte	W03
	.byte		        Cs2 , v052
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        En2 
	.byte	W03
	.byte		        Fs2 , v056
	.byte	W04
	.byte		N02   , Gs2 
	.byte	W03
	.byte		N03   , As2 , v060
	.byte	W04
	.byte		N15   , Bn2 
	.byte	W15
	.byte		N07   , Cs2 , v052
	.byte		N16   , As2 , v060
	.byte	W08
	.byte GOTO
	.word restart_position

	.byte	FINE


@******************************************************@
	.align	2

bgm:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_pri	@ Priority
	.byte	bgm_rev	@ Reverb.

	.word	bgm_grp

	.word	bgm_1

	.end
