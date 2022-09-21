	.include "MPlayDef.s"

	.equ	jazz_test_1_grp, voicegroup000
	.equ	jazz_test_1_pri, 0
	.equ	jazz_test_1_rev, 0
	.equ	jazz_test_1_mvl, 127
	.equ	jazz_test_1_key, 0
	.equ	jazz_test_1_tbs, 1
	.equ	jazz_test_1_exg, 0
	.equ	jazz_test_1_cmp, 1

	.section .rodata
	.global	jazz_test_1
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

jazz_test_1_1:
	.byte	KEYSH , jazz_test_1_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 142*jazz_test_1_tbs/2
	.byte		VOICE , 27
	.byte		VOL   , 100*jazz_test_1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W84
restart_00:
	.byte		N05   , An2 , v060
	.byte		N22   , Dn3 
	.byte		N11   , En3 , v064
	.byte		N32   , An3 , v068
	.byte	W12
@ 001   ----------------------------------------
	.byte		N22   , Dn4 , v064
	.byte	W12
	.byte		N11   , Fn1 , v052
	.byte		N11   , Cn4 , v068
	.byte	W12
	.byte		        As2 , v048
	.byte		N11   , Ds3 , v060
	.byte		N68   , Gs3 , v068
	.byte	W12
	.byte		N48   , As2 , v056
	.byte		N56   , Ds3 
	.byte	W12
	.byte		N22   , Fn1 , v060
	.byte		N32   , Cn4 , v064
	.byte	W12
	.byte		N22   , Ds4 , v068
	.byte	W12
	.byte		N11   , Gn4 
	.byte	W12
	.byte		N05   , As1 , v056
	.byte		N08   , As2 , v052
	.byte	W12
@ 002   ----------------------------------------
	.byte		N22   , Gn2 , v060
	.byte		N22   , As2 , v064
	.byte		N22   , Ds3 , v060
	.byte		N22   , Cn5 , v072
	.byte	W12
	.byte		N24   , As4 , v064
	.byte	W12
	.byte		N11   , Gs1 
	.byte		N11   , Cn5 , v068
	.byte	W03
	.byte		N04   , Gn2 , v056
	.byte	W21
	.byte		N44   , An2 
	.byte		N44   , Cn3 
	.byte		N44   , Ds3 , v068
	.byte		N32   , Cn5 , v064
	.byte	W12
	.byte		N17   , As4 , v068
	.byte		N17   , As5 , v060
	.byte	W12
	.byte		N44   , Gs1 , v064
	.byte		N11   , Gs4 
	.byte	W12
	.byte		N32   , Gn4 , v068
	.byte	W12
@ 003   ----------------------------------------
	.byte		N22   , Cn3 , v052
	.byte		N32   , Fn4 , v064
	.byte	W12
	.byte		N22   , Ds4 , v056
	.byte	W12
	.byte		N11   , Ds2 
	.byte		N17   , Gn2 , v064
	.byte		N22   , Cn3 , v068
	.byte	W12
	.byte		N05   , Gs1 , v056
	.byte		N22   , Cn4 , v072
	.byte	W06
	.byte		N17   , Gs1 , v060
	.byte	W06
	.byte		N44   , Cn2 , v056
	.byte		N11   , As2 , v068
	.byte		N11   , As3 , v064
	.byte	W12
	.byte		N32   , Gs2 , v056
	.byte		N05   , Cn3 , v048
	.byte		N32   , Gn3 , v060
	.byte		N32   , Gs3 
	.byte	W12
	.byte		N44   , Cn3 , v068
	.byte		N90   , Fn3 
	.byte	W12
	.byte		N11   , Gs1 , v060
	.byte	W12
@ 004   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		        Ds1 , v056
	.byte		N22   , Ds3 , v064
	.byte	W12
	.byte		N11   , Cs1 
	.byte		N22   , Fn2 
	.byte		N22   , Cn3 , v060
	.byte	W12
	.byte		N32   , Cs1 , v056
	.byte		N32   , Gs2 , v064
	.byte	W12
	.byte		N22   , Fn2 , v056
	.byte		N22   , Cn3 , v060
	.byte		N32   , Gs3 , v064
	.byte	W12
	.byte		N22   , Cn4 , v068
	.byte	W12
	.byte		        Cs1 , v060
	.byte		N22   , Ds4 , v068
	.byte	W12
	.byte		N11   , Fn2 , v060
	.byte		N11   , Cn3 
	.byte		N22   , Fn3 
	.byte		N22   , Cn4 , v068
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Fn2 , v060
	.byte		N22   , Gs2 , v064
	.byte		N22   , Cn3 , v060
	.byte	W12
	.byte		N11   , Gs3 , v068
	.byte		N11   , Cn4 , v072
	.byte	W12
	.byte		        Gn1 , v056
	.byte		N02   , Gs1 , v048
	.byte		N22   , Fn2 , v068
	.byte		N11   , Gs2 , v064
	.byte		N11   , Cn3 , v056
	.byte		N11   , Fn3 , v068
	.byte		N22   , Fn4 
	.byte	W06
	.byte		N02   , Fn1 , v064
	.byte	W06
	.byte		N32   , As2 , v068
	.byte		N11   , Cn4 , v064
	.byte	W12
	.byte		        Gn1 , v060
	.byte		N11   , Fn2 , v056
	.byte		N11   , Gn2 , v060
	.byte		N11   , As3 , v064
	.byte	W12
	.byte		N17   , Gs1 , v056
	.byte		N11   , Dn4 , v060
	.byte	W12
	.byte		N32   , Fn2 
	.byte		N11   , As2 
	.byte		N44   , As3 , v068
	.byte	W03
	.byte		N08   , Gn1 , v052
	.byte	W03
	.byte		N17   , Dn3 , v060
	.byte	W06
	.byte		N11   , Gn1 , v056
	.byte		N22   , Gn2 , v060
	.byte		N22   , As2 
	.byte		N22   , Gn3 , v064
	.byte	W12
@ 006   ----------------------------------------
	.byte		N11   , Gn1 , v052
	.byte		N11   , Dn3 , v056
	.byte		N11   , Fn3 , v060
	.byte	W12
	.byte		        Dn1 
	.byte		N11   , Ds4 , v064
	.byte	W06
	.byte		N17   , Gn1 , v060
	.byte	W06
	.byte		N11   , As2 
	.byte		N11   , Ds3 , v064
	.byte		N24   , Cn4 , v068
	.byte	W12
	.byte		N32   , As2 , v064
	.byte		N22   , Ds3 
	.byte		N32   , As3 , v060
	.byte	W12
	.byte		N11   , Fs1 
	.byte		N44   , Cn4 , v068
	.byte	W12
	.byte		N17   , Ds2 , v052
	.byte		N11   , Fs2 , v048
	.byte		N17   , Ds3 , v044
	.byte	W12
	.byte		N11   , Fn2 , v052
	.byte		N11   , Gn2 , v056
	.byte		N22   , Cn3 
	.byte	W12
	.byte		        As3 , v068
	.byte	W12
@ 007   ----------------------------------------
	.byte		N11   , Fn1 , v064
	.byte		N11   , Fn2 , v056
	.byte		N11   , Cs3 , v064
	.byte		N11   , Gs3 , v068
	.byte	W12
	.byte		N05   , Gn1 , v048
	.byte		N05   , Gn2 , v064
	.byte		N04   , Gn3 , v068
	.byte	W09
	.byte		N01   , Fn2 
	.byte	W03
	.byte		N11   , Fn1 , v064
	.byte		N17   , Fn2 , v048
	.byte		N22   , Gs2 , v064
	.byte		N22   , Cs3 , v068
	.byte		N11   , Gn3 
	.byte	W24
	.byte		        Fn3 , v060
	.byte	W03
	.byte		N04   , Fn1 
	.byte		N04   , Gn2 , v056
	.byte	W03
	.byte		N05   , Cs4 , v072
	.byte	W06
	.byte		N17   , Fn1 , v048
	.byte		N17   , As1 
	.byte		N17   , Cn4 , v052
	.byte	W12
	.byte		N11   , Fn2 , v060
	.byte		N11   , Cs3 , v064
	.byte		N11   , Ds4 , v068
	.byte	W12
	.byte		N32   , Gn4 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N22   , Gn1 , v060
	.byte		N11   , Fn2 , v056
	.byte		N11   , As2 , v060
	.byte		N11   , Cs3 , v064
	.byte	W12
	.byte		        Ds4 , v056
	.byte	W06
	.byte		N05   , Fn2 , v040
	.byte		N05   , As2 , v048
	.byte		N05   , Cs3 , v040
	.byte		N17   , Dn3 , v052
	.byte	W06
	.byte		N32   , Fn2 , v060
	.byte		N22   , Cs3 , v064
	.byte		N17   , Dn4 , v056
	.byte	W12
	.byte		N05   , As2 , v060
	.byte	W06
	.byte		N28   
	.byte		N18   , Dn3 
	.byte		N28   , Cs4 , v068
	.byte	W06
	.byte		N22   , Fn4 , v064
	.byte	W12
	.byte		N32   , Fs1 , v048
	.byte		N05   , Gn1 , v040
	.byte		N17   , Dn3 , v064
	.byte	W12
	.byte		N11   , Fn2 
	.byte		N11   , As2 
	.byte		N44   , En4 , v056
	.byte		N44   , As4 , v064
	.byte	W12
	.byte		N11   , En2 , v052
	.byte	W12
@ 009   ----------------------------------------
	.byte		N22   , En2 , v056
	.byte		N22   , As2 , v064
	.byte		N22   , Dn3 , v052
	.byte	W24
	.byte		N11   , En2 , v064
	.byte		N11   , As2 , v060
	.byte		N11   , Gn4 , v068
	.byte	W03
	.byte		N08   , Cs3 , v060
	.byte	W09
	.byte		N05   , Gn1 , v048
	.byte		N32   , En2 , v044
	.byte		N11   , Cs5 , v068
	.byte	W06
	.byte		N17   , Gn2 , v056
	.byte	W06
	.byte		N32   , As2 , v064
	.byte		N22   , Cn3 , v044
	.byte		N44   , As4 , v068
	.byte	W12
	.byte		N22   , Gn4 
	.byte	W12
	.byte		N11   , Gn2 , v052
	.byte		N11   , En4 , v064
	.byte	W12
	.byte		N02   , En2 , v060
	.byte		N11   , Cn3 , v064
	.byte		N11   , Cs4 , v068
	.byte	W06
	.byte		N05   , Gn1 , v056
	.byte	W06
@ 010   ----------------------------------------
	.byte		N22   , As1 , v064
	.byte		N05   , As2 , v060
	.byte		N05   , Cn3 , v048
	.byte		N44   , En3 , v060
	.byte	W12
	.byte		N32   , En2 , v056
	.byte		N11   , As2 , v060
	.byte		N11   , Ds3 
	.byte	W12
	.byte		        Gn2 
	.byte		N22   , En4 , v068
	.byte	W12
	.byte		N11   , Gn1 , v056
	.byte		N11   , As3 , v064
	.byte	W12
	.byte		N22   , Gn1 , v060
	.byte		N11   , En2 
	.byte	W12
	.byte		        En2 , v048
	.byte		N11   , As2 , v060
	.byte	W06
	.byte		N17   , As3 , v068
	.byte	W06
	.byte		N05   , Cn1 , v064
	.byte		N05   , Cn3 
	.byte		N22   , En4 , v068
	.byte	W12
	.byte		N32   , En2 , v060
	.byte		N10   , Gn2 , v056
	.byte		N10   , As2 , v060
	.byte		N32   , Cn3 
	.byte	W12
@ 011   ----------------------------------------
	.byte		N11   , As2 , v044
	.byte		N44   , Gn4 , v068
	.byte	W12
	.byte		N11   , En1 , v064
	.byte		N11   , Gn2 , v056
	.byte		N11   , As2 
	.byte	W12
	.byte		N22   , En2 , v052
	.byte		N11   , As2 , v060
	.byte		N44   , Cn3 , v064
	.byte		N22   , As4 , v072
	.byte	W12
	.byte		N11   , As2 , v056
	.byte	W03
	.byte		N08   , Gn2 , v048
	.byte		N08   , Gn3 , v060
	.byte	W09
	.byte		N11   , Gn2 , v044
	.byte		N22   , Cn4 , v064
	.byte		N22   , Cn5 , v068
	.byte	W12
	.byte		N11   , Gn1 , v060
	.byte		N32   , En2 , v056
	.byte		N11   , Ds3 , v064
	.byte	W12
	.byte		N22   , As2 , v060
	.byte		N44   , Ds3 , v064
	.byte		N32   , Cn5 , v072
	.byte	W12
	.byte		        Gn4 , v064
	.byte		N32   , Gn5 , v052
	.byte	W12
@ 012   ----------------------------------------
	.byte		N11   , Gn1 , v056
	.byte		N22   , En2 
	.byte		N22   , As2 , v060
	.byte	W12
	.byte		N11   , Gn1 , v044
	.byte		N22   , Cs4 , v068
	.byte	W12
	.byte		N11   , Ds1 , v064
	.byte		N22   , Ds2 
	.byte		N11   , Gn2 , v060
	.byte		N11   , Dn5 
	.byte	W06
	.byte		N17   , Gs2 , v052
	.byte	W06
	.byte		N32   , Fn2 , v064
	.byte		N78   , Ds4 , v068
	.byte		N12   , Fn4 , v052
	.byte	W12
	.byte		N22   , Gn2 , v064
	.byte		N22   , Cn3 
	.byte		N32   , Fn4 , v068
	.byte	W12
	.byte		N22   , Gs2 , v064
	.byte	W12
	.byte		        Gn2 , v056
	.byte		N22   , Fn3 , v060
	.byte	W06
	.byte		N05   , Ds2 , v052
	.byte	W06
	.byte		N32   , Fn1 , v064
	.byte		N24   , Ds2 , v052
	.byte	W12
@ 013   ----------------------------------------
	.byte		N22   , Gn2 , v060
	.byte		N11   , Cn4 , v068
	.byte	W12
	.byte		        Ds2 , v060
	.byte		N11   , Cn3 , v064
	.byte	W12
	.byte		        Gs1 
	.byte		N32   , Gn4 
	.byte	W06
	.byte		N17   , Cn3 , v068
	.byte	W06
	.byte		N28   , Ds2 , v060
	.byte		N22   , Gn2 
	.byte		N32   , Gs2 
	.byte	W12
	.byte		N11   , Ds1 , v048
	.byte		N22   , Ds4 , v068
	.byte	W12
	.byte		N32   , Ds1 , v064
	.byte		N05   , Gn2 , v056
	.byte		N11   , Ds3 , v064
	.byte		N32   , Gn4 
	.byte	W06
	.byte		N05   , Ds2 , v048
	.byte		N36   , Gn2 
	.byte	W06
	.byte		N32   , Ds2 , v052
	.byte		N32   , Cn3 , v064
	.byte		N11   , As4 , v060
	.byte	W12
	.byte		N22   , Cn5 , v064
	.byte	W12
@ 014   ----------------------------------------
	.byte		        Gs1 , v048
	.byte		N22   , Gn4 , v064
	.byte	W12
	.byte		N56   , Gn2 , v068
	.byte		N22   , Ds3 
	.byte		N44   , Cn5 , v072
	.byte	W06
	.byte		N05   , Cn3 , v056
	.byte	W06
	.byte		N44   , Ds2 , v048
	.byte		N22   , As4 , v064
	.byte	W12
	.byte		N11   , Gs2 
	.byte		N32   , Cn3 
	.byte		N32   , Gs4 , v068
	.byte	W12
	.byte		N11   , Ds1 , v056
	.byte		N22   , Gn4 , v068
	.byte	W12
	.byte		N11   , Gs1 , v052
	.byte		N11   , Fn4 , v064
	.byte	W12
	.byte		N05   , En2 
	.byte		N05   , Fn2 , v060
	.byte		N05   , Gs2 , v056
	.byte		N56   , Cn3 , v060
	.byte		N22   , En4 , v068
	.byte	W12
	.byte		        Fn2 , v060
	.byte		N22   , Gs2 , v064
	.byte		N32   , Fn4 
	.byte	W12
@ 015   ----------------------------------------
	.byte		N22   , En2 , v056
	.byte		N11   , En4 , v068
	.byte	W12
	.byte		N22   , Gs2 , v060
	.byte		N56   , En3 , v068
	.byte	W06
	.byte		N17   , Ds4 , v064
	.byte	W06
	.byte		N22   , En2 , v048
	.byte		N44   , Cs4 , v064
	.byte	W12
	.byte		N32   , Gs2 
	.byte		N11   , Cn3 , v052
	.byte		N32   , Cn4 , v072
	.byte	W12
	.byte		N11   , En2 , v064
	.byte		N22   , Cn3 , v056
	.byte		N22   , Bn3 , v072
	.byte	W12
	.byte		N11   , Gs3 
	.byte	W12
	.byte		N07   , Fn1 , v064
	.byte		N07   , Fn2 
	.byte		N07   , Gs2 
	.byte		N07   , Cn3 
	.byte		N32   , Gn3 , v072
	.byte	W16
	.byte		N03   , Gs2 , v064
	.byte		N03   , Cn3 , v060
	.byte	W04
	.byte		N15   , En1 , v056
	.byte		N24   , Fn3 , v064
	.byte	W04
@ 016   ----------------------------------------
	.byte		N22   , Gs2 , v060
	.byte		N12   , Cn3 , v056
	.byte		TIE   , En3 , v072
	.byte	W12
	.byte		N22   , Cn3 , v060
	.byte		N22   , Dn4 , v068
	.byte	W12
	.byte		N11   , Gs2 , v060
	.byte		N22   , Fn3 , v064
	.byte	W03
	.byte		N08   , Fn1 , v060
	.byte	W09
	.byte		N05   , En1 , v048
	.byte		N11   , Cs4 , v068
	.byte	W06
	.byte		N05   , Gn1 , v060
	.byte	W06
	.byte		N56   
	.byte		N11   , Gn2 
	.byte		N56   , As2 , v056
	.byte		N11   , Dn3 , v048
	.byte	W12
	.byte		N44   , En2 , v056
	.byte		N30   , Gn2 , v060
	.byte		N24   , Dn3 , v064
	.byte	W12
	.byte		N32   , Dn4 
	.byte		N44   , Gn4 
	.byte	W12
	.byte		N22   , Dn3 
	.byte	W06
	.byte		N05   , Dn2 , v060
	.byte		N28   , Gn2 , v068
	.byte	W06
@ 017   ----------------------------------------
	.byte		N17   , Dn1 , v052
	.byte		N32   , As4 , v072
	.byte	W12
	.byte		N11   , Gn1 , v056
	.byte		N11   , Fn2 , v064
	.byte		N11   , As2 
	.byte		N06   , Dn3 , v060
	.byte	W06
	.byte		N17   , Dn3 , v048
	.byte	W06
	.byte		N32   , Fn2 , v052
	.byte		N32   , An4 , v068
	.byte	W03
	.byte		N08   , Gn2 , v044
	.byte	W09
	.byte		N11   , Gn1 , v052
	.byte		N22   , Gn2 , v064
	.byte		N22   , Dn3 
	.byte	W12
	.byte		        Gn1 , v056
	.byte		N22   , Gn4 , v068
	.byte	W12
	.byte		N05   , Dn2 , v052
	.byte		N05   , Fn2 , v064
	.byte		N05   , As2 , v056
	.byte		N22   , Dn3 , v064
	.byte		N22   , Fn4 
	.byte	W12
	.byte		N11   , Gn1 , v052
	.byte	W12
	.byte		N19   , Gn2 , v060
	.byte		N11   , As2 
	.byte		N11   , Dn3 , v064
	.byte		N22   , Dn4 , v068
	.byte	W12
@ 018   ----------------------------------------
	.byte		N08   , Gn1 , v052
	.byte		N09   , Dn3 , v048
	.byte	W09
	.byte		N14   , Gn2 , v064
	.byte		N24   , As2 , v060
	.byte		N36   , Dn3 , v056
	.byte	W03
	.byte		N32   , Cn4 , v068
	.byte	W12
	.byte		N05   , Gn1 , v044
	.byte	W12
	.byte		N11   , As2 , v060
	.byte		N11   , Cs3 
	.byte		N11   , As3 , v068
	.byte	W12
	.byte		        As2 , v064
	.byte		N68   , Fn3 , v060
	.byte	W03
	.byte		N04   , Fs2 , v064
	.byte		N04   , Cs3 , v060
	.byte	W09
	.byte		N11   , Fs2 , v052
	.byte		N11   , As2 , v056
	.byte		N12   , Cs3 
	.byte		N22   , Fn4 , v064
	.byte	W12
	.byte		N32   , Fs2 , v060
	.byte		N32   , As2 , v056
	.byte		N36   , Cs3 , v060
	.byte	W12
	.byte		N11   , Fs1 , v068
	.byte		N32   , Cs4 , v072
	.byte	W12
@ 019   ----------------------------------------
	.byte		N22   , Fs1 , v044
	.byte		N44   , Cn4 , v068
	.byte	W12
	.byte		N11   , Fn2 , v060
	.byte		N22   , Fs2 
	.byte		N22   , Cs3 , v064
	.byte	W12
	.byte		        Fs1 , v052
	.byte		N17   , Fn2 , v064
	.byte	W12
	.byte		N32   , Fn1 , v060
	.byte	W06
	.byte		EOT   , En3 
	.byte		N36   , Dn2 , v064
	.byte		N05   , Fn2 , v056
	.byte		N28   , An2 , v064
	.byte	W06
	.byte		N36   , Fn2 , v060
	.byte		N32   , Bn3 , v068
	.byte	W03
	.byte		N02   , Cn3 , v056
	.byte	W03
	.byte		N06   , Cn3 , v052
	.byte	W06
	.byte		N17   , Cn3 , v060
	.byte	W12
	.byte		N22   , Fn1 , v052
	.byte		N22   , En3 , v064
	.byte	W12
	.byte		N11   , Fn2 , v056
	.byte		N11   , An2 , v060
	.byte		N11   , Cn3 
	.byte		N11   , Fn3 , v068
	.byte	W12
@ 020   ----------------------------------------
	.byte		N22   , Fn1 , v044
	.byte		N22   , En3 , v052
	.byte		N22   , An3 , v064
	.byte	W06
	.byte		N17   , Cn3 
	.byte	W06
	.byte		N05   , En2 , v056
	.byte		N05   , An2 , v060
	.byte		N32   , Cn4 , v072
	.byte	W06
	.byte		N12   , En2 , v056
	.byte		N12   , Fn2 , v052
	.byte		N12   , An2 
	.byte	W06
	.byte		N32   , Fn1 , v064
	.byte		N44   , En4 , v068
	.byte	W06
	.byte		N32   , En2 , v064
	.byte		N16   , Fn2 , v056
	.byte		N30   , An2 , v060
	.byte		N36   , Cn3 , v064
	.byte	W06
	.byte		N32   , Dn3 , v068
	.byte	W06
	.byte		N36   , Dn4 , v072
	.byte	W06
	.byte		N44   , Gs2 , v064
	.byte		N11   , Cn4 , v068
	.byte	W12
	.byte		        An2 , v060
	.byte	W03
	.byte		N04   , An1 , v064
	.byte		N06   , En2 , v056
	.byte	W09
	.byte		N22   , Fn3 , v064
	.byte	W01
	.byte		N02   , Gn1 , v056
	.byte		N09   , An1 
	.byte	W11
	.byte		N22   , Gn2 
	.byte		N11   , Dn3 , v064
	.byte		N32   , Ds4 , v072
	.byte	W12
@ 021   ----------------------------------------
	.byte		N22   , Fn2 , v056
	.byte		N22   , An2 
	.byte		N22   , Dn3 , v064
	.byte		N05   , Cn4 , v060
	.byte	W03
	.byte		N04   , Gn1 , v064
	.byte	W09
	.byte		N05   , Gs2 
	.byte		N22   , Cs3 , v068
	.byte	W03
	.byte		N04   , Gn1 , v056
	.byte	W09
	.byte		N11   , Gn1 , v052
	.byte		N11   , Gn2 , v060
	.byte	W12
	.byte		        As2 , v064
	.byte		N11   , Cs3 
	.byte		N11   , Cn4 , v068
	.byte	W03
	.byte		N04   , Fs1 , v060
	.byte	W03
	.byte		N05   , Fn2 
	.byte	W06
	.byte		N11   , Dn1 , v056
	.byte		N11   , Fs2 , v060
	.byte		N11   , Cs3 , v056
	.byte		N11   , As3 , v064
	.byte	W12
	.byte		        Fn2 , v052
	.byte		N11   , Cn3 , v060
	.byte		N11   , En3 , v056
	.byte		N17   , An3 , v060
	.byte	W12
	.byte		N11   , Fn2 , v064
	.byte		N11   , Cn3 
	.byte		N22   , En3 , v056
	.byte	W24
@ 022   ----------------------------------------
	.byte		N11   , Fn1 
	.byte		N44   , Fn2 , v060
	.byte		N22   , An2 , v068
	.byte		N22   , Cn3 , v064
	.byte		N44   , En3 , v052
	.byte		N44   , An3 , v068
	.byte	W12
	.byte		N11   , Fn1 , v052
	.byte	W12
	.byte		N11   
	.byte		N11   , An2 , v056
	.byte		N11   , Cn3 , v060
	.byte		N23   , En4 , v068
	.byte	W12
	.byte		N11   , Cn4 , v060
	.byte	W12
	.byte		        Gn1 
	.byte		N11   , Fn2 
	.byte		N11   , An2 
	.byte		N11   , Cn3 
	.byte		N11   , En3 , v068
	.byte	W12
	.byte		        Gn1 , v052
	.byte		N11   , Fn2 
	.byte		N11   , Bn2 , v060
	.byte		N32   , Gn4 , v064
	.byte	W03
	.byte		N04   , Gn2 , v040
	.byte	W09
	.byte		N22   , Gn1 , v060
	.byte		N22   , Fn2 , v064
	.byte		N22   , Bn2 , v056
	.byte		N22   , Dn3 , v060
	.byte	W12
	.byte		        En4 , v068
	.byte	W12
@ 023   ----------------------------------------
	.byte		        Gn1 , v064
	.byte		N11   , Fn2 , v060
	.byte		N11   , An2 
	.byte		N11   , Bn2 
	.byte		N11   , Dn4 , v068
	.byte	W12
	.byte		        Bn3 
	.byte	GOTO
	.word	restart_00
	.byte	W12
	.byte		N05   , As2 
	.byte		N11   , Dn3 , v060
	.byte	W23
	.byte		        Dn3 , v080
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

jazz_test_1:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	jazz_test_1_pri	@ Priority
	.byte	jazz_test_1_rev	@ Reverb.

	.word	jazz_test_1_grp

	.word	jazz_test_1_1

	.end
