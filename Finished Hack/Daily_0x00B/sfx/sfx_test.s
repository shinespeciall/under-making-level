	.include "MPlayDef.s"

	.equ	sfx_test_grp, voicegroup000
	.equ	sfx_test_pri, 0
	.equ	sfx_test_rev, 0
	.equ	sfx_test_mvl, 127
	.equ	sfx_test_key, 0
	.equ	sfx_test_tbs, 1
	.equ	sfx_test_exg, 0
	.equ	sfx_test_cmp, 1

	.section .rodata
	.global	sfx_test
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

sfx_test_1:
	.byte	KEYSH , sfx_test_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 140*sfx_test_tbs/2
	.byte		VOICE , 2
	.byte		VOL   , 100*sfx_test_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W80
	.byte	W03
	.byte		N32   , Gn3 , v056
loop:
	.byte	W12
	.byte		N68   , Gn2 , v064
	.byte		N32   , Dn4 , v072
	.byte	W01
@ 001   ----------------------------------------
	.byte	W23
	.byte		N22   , Dn3 , v068
	.byte		N22   , Gn3 , v072
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn1 , v052
	.byte		N32   , An3 , v076
	.byte	W12
	.byte		        Fs2 , v056
	.byte	W12
	.byte		N22   , Bn0 , v052
	.byte		N22   , Dn3 , v064
	.byte	W12
	.byte		N11   , An3 
	.byte	W12
	.byte		N44   , En2 , v056
	.byte		N11   , Bn2 , v048
	.byte		N22   , En3 , v052
	.byte		N32   , Gn3 , v068
	.byte	W01
@ 002   ----------------------------------------
	.byte	W11
	.byte		N22   , Bn2 , v052
	.byte	W12
	.byte		        Fs3 , v064
	.byte	W12
	.byte		N11   , Bn2 , v048
	.byte	W06
	.byte		N28   , En3 , v060
	.byte	W06
	.byte		N22   , Cn2 , v056
	.byte		N44   , Gn2 
	.byte	W24
	.byte		        En3 , v064
	.byte		N44   , Gn3 
	.byte	W12
	.byte		N22   , Dn3 , v072
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W01
@ 003   ----------------------------------------
	.byte	W11
	.byte		N11   , Dn3 , v072
	.byte	W12
	.byte		N11   
	.byte		N12   , An3 , v076
	.byte	W12
	.byte		N11   , Dn3 , v072
	.byte		N11   , An3 , v064
	.byte	W12
	.byte		N78   , Gn2 
	.byte		N68   , Dn3 , v072
	.byte		N22   , En3 , v064
	.byte		N68   , An3 , v072
	.byte	W24
	.byte		N22   , Cn3 , v076
	.byte	W24
	.byte		        Gn3 , v064
	.byte	W01
@ 004   ----------------------------------------
	.byte	W23
	.byte		N11   , En3 
	.byte		N44   , Gn3 
	.byte		N22   , Cn4 , v068
	.byte	W12
	.byte		N68   , En3 , v060
	.byte	W12
	.byte		N56   , Cn4 , v076
	.byte	W24
	.byte		N32   , Gn3 
	.byte	W24
	.byte		N11   , Cn3 , v072
	.byte	W01
@ 005   ----------------------------------------
	.byte	W11
	.byte		N05   , Gn1 , v064
	.byte		N78   , Bn3 , v072
	.byte	W12
	.byte		N68   , Dn2 , v068
	.byte	W12
	.byte		N56   , Gn2 , v076
	.byte	W12
	.byte		N44   , Bn2 , v072
	.byte	W48
	.byte		        Gn2 , v080
	.byte		N44   , Bn2 
	.byte		N90   , Bn3 , v076
	.byte	W01
@ 006   ----------------------------------------
	.byte	W11
	.byte		N32   , Fs2 , v072
	.byte	W36
	.byte		N12   , Gn2 , v080
	.byte		N22   , Bn2 
	.byte	W12
	.byte		N32   , Gn2 , v076
	.byte	W12
	.byte		N22   , En3 , v072
	.byte	W12
	.byte		N11   , An3 
	.byte	W12
	.byte		N32   , Bn1 , v064
	.byte		N22   , Fs3 , v072
	.byte		N44   , Bn3 , v068
	.byte	W01
@ 007   ----------------------------------------
	.byte	W23
	.byte		N22   , Dn3 , v072
	.byte	W12
	.byte		N11   , Fs3 , v068
	.byte	W12
	.byte		N32   , En3 , v076
	.byte		N32   , Gn3 , v072
	.byte	W24
	.byte		N22   , Bn1 , v052
	.byte	W12
	.byte		TIE   , Fs3 , v068
	.byte	W12
	.byte		N22   , Cn2 , v076
	.byte		N22   , Cn3 , v072
	.byte	W01
@ 008   ----------------------------------------
	.byte	W11
	.byte		N78   , Gn2 
	.byte	W12
	.byte		N44   , Cn3 
	.byte		N68   , En3 , v076
	.byte	W48
	.byte		N22   , Cn3 , v072
	.byte	W18
	.byte		EOT   , Fs3 
	.byte	W06
	.byte		N11   , Fs1 
	.byte		N68   , Fs3 
	.byte	W01
@ 009   ----------------------------------------
	.byte	W11
	.byte		N11   , Fs2 , v076
	.byte	W12
	.byte		N44   , Cn3 
	.byte	W48
	.byte		N11   , Fs2 , v072
	.byte		N44   , Cs3 , v076
	.byte		N44   , En3 , v072
	.byte	W12
	.byte		N22   , Fs2 , v068
	.byte	W12
	.byte		        Cn3 , v076
	.byte	W01
@ 010   ----------------------------------------
	.byte	W11
	.byte		N11   , Gn2 , v072
	.byte	W12
	.byte		N22   , Gn2 , v080
	.byte		N11   , Dn3 
	.byte	W12
	.byte		N32   
	.byte	W12
	.byte		N22   , Gn2 
	.byte	W24
	.byte		N22   
	.byte		N22   , Bn3 
	.byte	W24
	.byte		N44   , Dn2 
	.byte		N11   , Bn3 
	.byte	W01
@ 011   ----------------------------------------
	.byte	W11
	.byte		        Dn3 
	.byte		N11   , An3 
	.byte	W12
	.byte		        Cn3 
	.byte		N11   , An3 
	.byte	W12
	.byte		        Cn3 
	.byte		N11   , An3 
	.byte	W12
	.byte		N22   , An2 
	.byte		N11   , Fs3 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N22   , Dn3 
	.byte		N44   , An3 
	.byte	W24
	.byte		N11   , Dn3 
	.byte	W01
@ 012   ----------------------------------------
	.byte	W11
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte		N11   , Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte		N11   , An3 
	.byte	W12
	.byte		        En2 
	.byte		N11   , Cn3 
	.byte		N11   , Dn4 
	.byte	W12
	.byte		        Dn3 
	.byte		N11   , Gn3 
	.byte		N11   , Cn4 
	.byte	W12
	.byte		        Dn3 
	.byte		N11   , Gn3 
	.byte		N11   , Cn4 
	.byte	W12
	.byte		        Dn3 
	.byte		N11   , Fs3 
	.byte		N44   , Cn4 
	.byte	W12
	.byte		N11   , Dn2 
	.byte	W01
@ 013   ----------------------------------------
	.byte	W11
	.byte		        Dn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N11   
	.byte		N11   , An3 
	.byte	W12
	.byte		        En3 
	.byte		N11   , Cn4 
	.byte	W12
	.byte		        An3 
	.byte		N11   , En4 
	.byte	W12
	.byte		N22   , An3 
	.byte		N44   , Fs4 
	.byte	W24
	.byte		N22   , An3 
	.byte	W01
@ 014   ----------------------------------------
	.byte	W23
	.byte		N44   , Dn4 
	.byte	W48
	.byte		N22   , Bn2 
	.byte		N22   , Gn3 
	.byte	W23
	.byte	GOTO
	 .word	loop

@******************************************************@
	.align	2

sfx_test:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	sfx_test_pri	@ Priority
	.byte	sfx_test_rev	@ Reverb.

	.word	sfx_test_grp

	.word	sfx_test_1

	.end
