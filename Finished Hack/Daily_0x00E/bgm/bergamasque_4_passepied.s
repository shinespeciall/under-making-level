	.include "MPlayDef.s"

	.equ	bergamasque_4_passepied_grp, voicegroup000
	.equ	bergamasque_4_passepied_pri, 0
	.equ	bergamasque_4_passepied_rev, 0
	.equ	bergamasque_4_passepied_mvl, 127
	.equ	bergamasque_4_passepied_key, 0
	.equ	bergamasque_4_passepied_tbs, 1
	.equ	bergamasque_4_passepied_exg, 0
	.equ	bergamasque_4_passepied_cmp, 1

	.section .rodata
	.global	bergamasque_4_passepied
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

bergamasque_4_passepied_1:
	.byte	KEYSH , bergamasque_4_passepied_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 172*bergamasque_4_passepied_tbs/2
	.byte		VOICE , 25
	.byte		PAN   , c_v-13
	.byte		VOL   , 100*bergamasque_4_passepied_mvl/mxv
restart_position:
	.byte		N06   , Fs1 , v056
	.byte	W12
	.byte		        Cs2 , v072
	.byte	W12
	.byte		        An2 , v064
	.byte	W12
	.byte		        Cs2 , v056
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 , v064
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Cs2 , v056
	.byte	W12
@ 001   ----------------------------------------
	.byte		        An1 , v060
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        Cs3 , v072
	.byte	W12
	.byte		        Fs2 , v060
	.byte	W12
	.byte		        Bn1 , v056
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        Dn3 , v076
	.byte	W12
	.byte		        Fs2 , v060
	.byte	W12
@ 002   ----------------------------------------
	.byte		        Fs1 , v056
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Cs2 , v068
	.byte	W12
	.byte		        An2 , v072
	.byte		N12   , Cs4 , v068
	.byte	W12
	.byte		N06   , Cs2 , v056
	.byte	W12
	.byte		        Gs1 , v064
	.byte		N72   , Bn3 
	.byte	W12
	.byte		N06   , Cs2 , v068
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Cs2 , v060
	.byte	W12
@ 003   ----------------------------------------
	.byte		        An1 , v056
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        Cs3 , v076
	.byte		N06   , An3 , v060
	.byte	W12
	.byte		        Fs2 
	.byte		N06   , Gs3 , v056
	.byte	W12
	.byte		        Bn1 , v060
	.byte		N12   , Fs3 , v056
	.byte	W12
	.byte		N06   , Fs2 , v060
	.byte	W12
	.byte		        Dn3 , v080
	.byte		N06   , En3 , v060
	.byte	W12
	.byte		        Fs2 , v052
	.byte		N06   , Dn3 , v056
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Fs1 , v052
	.byte		N24   , Cs3 
	.byte	W12
	.byte		N06   , Cs2 , v068
	.byte	W12
	.byte		        An2 , v072
	.byte		N12   , Dn3 , v056
	.byte	W12
	.byte		N06   , Cs2 , v060
	.byte		N12   , En3 , v072
	.byte	W12
	.byte		N06   , An1 , v060
	.byte		N24   , Fs3 , v068
	.byte	W12
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		        Cs3 , v076
	.byte		N22   , An3 , v072
	.byte	W12
	.byte		N06   , Fs2 , v056
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Cs2 
	.byte		TIE   , Gs3 , v060
	.byte	W12
	.byte		N06   , Gs2 , v068
	.byte	W12
	.byte		        En3 , v076
	.byte	W12
	.byte		        Gs2 , v056
	.byte	W12
	.byte		        Bn1 , v052
	.byte	W12
	.byte		        Gs2 , v068
	.byte	W12
	.byte		        Cs3 , v072
	.byte	W12
	.byte		        Gs2 , v060
	.byte	W12
@ 006   ----------------------------------------
	.byte		        An1 , v056
	.byte	W12
	.byte		EOT   , Gs3 
	.byte		N06   , Fs2 , v068
	.byte		N06   , Fs3 , v056
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N06   , Gs3 , v064
	.byte	W12
	.byte		        Fs2 , v060
	.byte		N12   , An3 , v064
	.byte	W12
	.byte		N06   , Gs1 , v052
	.byte		N24   , Fs3 
	.byte		N56   , Bn3 , v072
	.byte	W12
	.byte		N06   , Cs2 , v064
	.byte	W12
	.byte		        Bn2 , v072
	.byte		N24   , Fn3 , v048
	.byte	W12
	.byte		N06   , Cs2 , v060
	.byte	W12
@ 007   ----------------------------------------
	.byte		        Fs1 , v064
	.byte		N22   , Cs3 , v052
	.byte	W12
	.byte		N06   , Cs2 , v064
	.byte		N12   , An3 , v060
	.byte	W12
	.byte		N06   , Bn2 , v068
	.byte		N12   , Bn3 , v064
	.byte	W12
	.byte		N06   , Cs2 , v056
	.byte		N12   , Cs4 , v068
	.byte	W12
	.byte		N06   , Gs1 , v052
	.byte		N24   , An3 , v056
	.byte		N56   , Dn4 , v064
	.byte	W12
	.byte		N06   , En2 , v068
	.byte	W12
	.byte		        Dn3 , v076
	.byte		N24   , Gs3 , v056
	.byte	W12
	.byte		N06   , En2 , v060
	.byte	W12
@ 008   ----------------------------------------
	.byte		        An1 
	.byte		N22   , En3 
	.byte	W12
	.byte		N06   , En2 , v072
	.byte		N12   , Cs4 , v056
	.byte	W12
	.byte		N06   , An2 , v060
	.byte		N12   , Dn4 , v064
	.byte	W12
	.byte		N06   , Cs3 , v068
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Dn2 , v056
	.byte		N68   , Dn4 
	.byte		TIE   , Fs4 , v068
	.byte	W12
	.byte		N06   , An2 
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Fs3 , v068
	.byte	W12
@ 009   ----------------------------------------
	.byte		        An2 , v056
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W12
	.byte		        Fs3 , v072
	.byte	W12
	.byte		        An3 , v068
	.byte	W12
	.byte		N68   , Fs3 , v044
	.byte	W01
	.byte		EOT   , Fs4 
	.byte	W11
	.byte		N06   , Dn3 , v048
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Bn2 , v044
	.byte	W12
@ 010   ----------------------------------------
	.byte		        An2 , v060
	.byte	W12
	.byte		        Cs3 , v068
	.byte	W12
	.byte		        An2 , v060
	.byte		N12   , Cs4 , v076
	.byte	W12
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		        Gs2 , v068
	.byte		N72   , Bn3 , v072
	.byte	W12
	.byte		N06   , Bn2 , v068
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
@ 011   ----------------------------------------
	.byte		        En2 , v056
	.byte	W12
	.byte		        Bn2 , v064
	.byte	W12
	.byte		        En3 , v068
	.byte		N06   , An3 , v056
	.byte	W12
	.byte		        Bn2 , v060
	.byte		N06   , Gs3 , v056
	.byte	W12
	.byte		        Bn1 , v052
	.byte		N12   , Fs3 , v056
	.byte	W12
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		        Dn3 , v076
	.byte		N06   , En3 , v056
	.byte	W12
	.byte		        En2 , v060
	.byte		N06   , Dn3 , v064
	.byte	W12
@ 012   ----------------------------------------
	.byte		        An1 , v060
	.byte	W12
	.byte		        En2 , v072
	.byte		N12   , Cs3 , v056
	.byte	W12
	.byte		N06   , An2 , v068
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , En2 , v056
	.byte		N12   , En3 , v068
	.byte	W12
	.byte		N06   , Dn2 , v064
	.byte		N24   , Fs3 , v072
	.byte	W12
	.byte		N06   , An2 , v080
	.byte	W12
	.byte		        Dn3 , v076
	.byte		N24   , An3 , v080
	.byte	W12
	.byte		N06   , Cs2 , v060
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Cn2 , v072
	.byte		TIE   , Fs3 , v068
	.byte		TIE   , Gs3 
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte	W12
	.byte		        Ds3 , v088
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W12
	.byte		        Cn2 , v056
	.byte	W12
	.byte		        Gs2 , v072
	.byte	W12
	.byte		        Ds3 , v080
	.byte	W12
	.byte		        Gs2 , v056
	.byte	W12
@ 014   ----------------------------------------
	.byte		        Cn2 , v052
	.byte	W12
	.byte		        Gs2 , v068
	.byte	W12
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Gs2 , v060
	.byte	W12
	.byte		EOT   , Fs3 
	.byte		        Gs3 
	.byte		N06   , Cs2 , v056
	.byte		N24   , Fs3 , v068
	.byte		N24   , An3 
	.byte	W12
	.byte		N06   , An2 , v072
	.byte	W12
	.byte		        En3 , v076
	.byte		N06   , En4 , v084
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        An2 , v064
	.byte	W12
@ 015   ----------------------------------------
	.byte		        Cn2 , v060
	.byte		N48   , Fs3 , v064
	.byte		N48   , Gs3 
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte	W12
	.byte		        Ds3 , v088
	.byte	W12
	.byte		        Gs2 , v068
	.byte	W12
	.byte		        Bn1 
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N06   , En2 , v080
	.byte	W12
	.byte		        Gs2 , v104
	.byte		N06   , Dn3 
	.byte		N06   , Cs4 
	.byte		N06   , En4 
	.byte	W12
	.byte		        En2 , v076
	.byte	W12
@ 016   ----------------------------------------
	.byte		        An1 , v084
	.byte		N24   , Cs3 , v060
	.byte		N24   , En3 
	.byte	W12
	.byte		N06   , En2 , v092
	.byte	W12
	.byte		        Cs3 , v104
	.byte	W12
	.byte		        En2 , v076
	.byte	W12
	.byte		        Fs1 , v096
	.byte		N24   , Bn2 
	.byte		N24   , Ds3 
	.byte	W12
	.byte		N06   , Bn1 , v112
	.byte	W12
	.byte		        Bn2 , v120
	.byte		N06   , An3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Bn1 , v096
	.byte	W12
@ 017   ----------------------------------------
	.byte		        Cs1 , v088
	.byte		TIE   , Gs2 
	.byte		TIE   , Cs3 
	.byte	W12
	.byte		N06   , Gs1 , v108
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gs1 , v088
	.byte	W12
	.byte		        Cs1 , v092
	.byte	W12
	.byte		        Gs1 , v104
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Gs1 , v092
	.byte	W12
@ 018   ----------------------------------------
	.byte		        Cs1 , v088
	.byte	W12
	.byte		        Gs1 , v108
	.byte	W12
	.byte		        Fn2 , v116
	.byte	W12
	.byte		        Gs1 , v092
	.byte	W12
	.byte		EOT   , Gs2 
	.byte		        Cs3 
	.byte		N06   , Bn1 , v064
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        An2 , v068
	.byte		N06   , Fs3 , v080
	.byte		N06   , An3 
	.byte	W12
	.byte		        Cs3 , v068
	.byte	W12
@ 019   ----------------------------------------
	.byte		        En2 , v060
	.byte		N60   , En3 
	.byte		N60   , Gs3 
	.byte	W12
	.byte		N06   , Bn2 , v072
	.byte	W12
	.byte		        Dn3 , v076
	.byte	W12
	.byte		        Bn2 , v064
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Bn2 , v076
	.byte		N12   , Fs3 
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , En2 , v068
	.byte		N44   , Gs3 , v080
	.byte		N44   , Bn3 
	.byte	W12
	.byte		N06   , Bn1 , v072
	.byte	W12
@ 020   ----------------------------------------
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 , v076
	.byte	W12
	.byte		        En2 , v080
	.byte		N22   , An3 , v072
	.byte		N22   , Cs4 
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte	W12
	.byte		        Bn1 , v064
	.byte		N24   , Bn2 , v056
	.byte		N24   , Dn3 
	.byte	W12
	.byte		N06   , Fs2 , v076
	.byte	W12
	.byte		        An2 
	.byte		N22   , Fs3 , v064
	.byte		N22   , An3 
	.byte	W12
	.byte		N06   , Cs3 , v084
	.byte	W12
@ 021   ----------------------------------------
	.byte		        En2 , v068
	.byte		N60   , En3 , v064
	.byte		N60   , Gs3 
	.byte	W12
	.byte		N06   , Bn2 , v080
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        En2 , v068
	.byte	W12
	.byte		        Bn2 , v076
	.byte		N12   , Fs3 
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , En2 , v064
	.byte		N48   , Gs3 , v080
	.byte		N48   , Bn3 
	.byte	W12
	.byte		N06   , Bn1 , v072
	.byte	W12
@ 022   ----------------------------------------
	.byte		        En1 , v068
	.byte	W12
	.byte		        Bn1 , v084
	.byte	W12
	.byte		        En2 
	.byte		N24   , En3 , v072
	.byte		N24   , Gs3 
	.byte	W12
	.byte		N06   , Gs2 , v080
	.byte	W12
	.byte		        Bn1 , v072
	.byte		N24   , Fs3 , v084
	.byte		N24   , An3 
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		        Dn3 , v108
	.byte		N22   , Gs3 , v088
	.byte		N22   , Bn3 
	.byte	W12
	.byte		N06   , En2 , v080
	.byte	W12
@ 023   ----------------------------------------
	.byte		        An1 
	.byte		N44   , Gn3 , v076
	.byte		N44   , Bn3 
	.byte		N15   , Cs4 , v100
	.byte	W12
	.byte		N06   , En2 , v088
	.byte	W03
	.byte		N16   , Cs4 , v092
	.byte	W09
	.byte		N06   , An2 , v096
	.byte	W07
	.byte		N15   , En4 , v112
	.byte	W05
	.byte		N06   , Cs3 , v092
	.byte	W12
	.byte		        Dn2 , v076
	.byte		N44   , Fs3 , v080
	.byte		N44   , An3 
	.byte		N16   , Cs4 , v088
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W03
	.byte		N16   , Bn3 , v088
	.byte	W09
	.byte		N06   , Dn3 , v092
	.byte	W07
	.byte		N15   , Cs4 , v100
	.byte	W05
	.byte		N06   , An2 , v080
	.byte	W12
@ 024   ----------------------------------------
	.byte		        Fs2 , v084
	.byte		N44   , En3 , v080
	.byte		N44   , Fs3 
	.byte		N24   , An3 , v076
	.byte	W12
	.byte		N06   , An2 , v092
	.byte	W12
	.byte		        Cs3 
	.byte		N24   , Bn3 , v080
	.byte	W12
	.byte		N06   , An2 
	.byte	W12
	.byte		        Bn1 , v076
	.byte		N90   , Dn3 , v084
	.byte		N44   , An3 
	.byte		N68   , Bn3 
	.byte	W12
	.byte		N06   , Fs2 , v092
	.byte	W12
	.byte		        Bn2 , v088
	.byte	W12
	.byte		        Fs2 , v084
	.byte	W12
@ 025   ----------------------------------------
	.byte		        En1 , v072
	.byte	W12
	.byte		        Bn1 , v092
	.byte	W12
	.byte		        En2 , v096
	.byte		N24   , Cs4 , v092
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        En1 , v076
	.byte		N23   , Dn3 , v088
	.byte		N42   , An3 , v080
	.byte	W12
	.byte		N06   , An1 , v088
	.byte	W12
	.byte		        Gn2 , v096
	.byte		N22   , Bn2 , v080
	.byte	W12
	.byte		N06   , An1 , v076
	.byte	W12
@ 026   ----------------------------------------
	.byte		        Fs1 , v080
	.byte		N16   , Cs3 , v092
	.byte		N90   , Fs3 , v088
	.byte		TIE   , An3 
	.byte	W12
	.byte		N06   , Cs2 , v084
	.byte	W03
	.byte		N16   , Dn3 , v096
	.byte	W09
	.byte		N06   , An2 
	.byte	W07
	.byte		N16   , Bn2 , v084
	.byte	W05
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        En1 , v080
	.byte		N16   , Cs3 , v092
	.byte	W12
	.byte		N06   , An1 , v088
	.byte	W03
	.byte		N16   , Dn3 , v092
	.byte	W09
	.byte		N06   , Fs2 
	.byte	W07
	.byte		N15   , En3 , v096
	.byte	W05
	.byte		N06   , An1 , v080
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Dn1 , v076
	.byte		N16   , Fs3 , v092
	.byte	W12
	.byte		N06   , An1 
	.byte	W03
	.byte		N16   , Gs3 , v096
	.byte	W03
	.byte		EOT   , An3 
	.byte	W06
	.byte		N06   , Dn2 , v092
	.byte	W07
	.byte		N16   , En3 , v076
	.byte	W05
	.byte		N06   , Fs2 , v092
	.byte	W12
	.byte		        An1 , v080
	.byte		N16   , Fs3 
	.byte	W12
	.byte		N06   , Dn2 , v092
	.byte	W03
	.byte		N16   , Gs3 , v088
	.byte	W09
	.byte		N06   , Fs2 
	.byte	W07
	.byte		N15   , An3 
	.byte	W05
	.byte		N06   , An2 
	.byte	W12
@ 028   ----------------------------------------
	.byte		        Dn2 , v076
	.byte		N16   , Bn3 , v080
	.byte	W12
	.byte		N06   , An2 , v092
	.byte	W03
	.byte		N16   , Cs4 , v084
	.byte	W09
	.byte		N06   , Dn3 , v096
	.byte	W07
	.byte		N16   , An3 , v076
	.byte	W05
	.byte		N06   , Fs3 , v100
	.byte	W12
	.byte		        Cs2 , v072
	.byte		N16   , Bn3 , v080
	.byte	W12
	.byte		N06   , Fs2 , v088
	.byte	W03
	.byte		N16   , Cs4 
	.byte	W09
	.byte		N06   , An2 
	.byte	W07
	.byte		N15   , Dn4 , v092
	.byte	W05
	.byte		N06   , Dn3 , v096
	.byte	W12
@ 029   ----------------------------------------
	.byte		        Bn1 , v060
	.byte		N12   , Fs3 , v072
	.byte		N48   , Dn4 
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Fs2 , v068
	.byte	W12
	.byte		        Bn2 , v064
	.byte		N12   , Cs4 , v072
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Dn3 , v064
	.byte	W12
	.byte		        Bn1 , v056
	.byte		N68   , Bn3 
	.byte		N48   , Fn4 , v068
	.byte		N48   , Bn4 
	.byte	W12
	.byte		N06   , Fn2 , v072
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
@ 030   ----------------------------------------
	.byte		        Bn1 , v056
	.byte		N22   , Fs4 , v060
	.byte	W12
	.byte		N06   , Fs2 , v068
	.byte	W12
	.byte		        Bn2 
	.byte		N06   , An3 , v044
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N06   , Gs3 , v056
	.byte	W12
	.byte		        Bn1 , v052
	.byte		N12   , Fs3 , v056
	.byte	W12
	.byte		N06   , Fs2 , v072
	.byte	W12
	.byte		        Gs2 , v068
	.byte		N06   , En3 , v056
	.byte	W12
	.byte		        Fs2 , v060
	.byte		N06   , Dn3 , v056
	.byte	W12
@ 031   ----------------------------------------
	.byte		        An1 , v052
	.byte		N24   , Cs3 , v056
	.byte	W12
	.byte		N06   , Fs2 , v068
	.byte	W12
	.byte		        An2 , v060
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , Fs2 
	.byte		N12   , En3 , v072
	.byte	W12
	.byte		N06   , Fs1 , v056
	.byte		N12   , Fs3 , v064
	.byte	W12
	.byte		N06   , Cs2 , v068
	.byte	W12
	.byte		        An2 , v072
	.byte		N12   , An3 , v064
	.byte	W12
	.byte		N06   , Cs2 , v056
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Cn2 , v060
	.byte		TIE   , Fs3 , v076
	.byte		TIE   , Gs3 
	.byte	W12
	.byte		N06   , Fs2 , v068
	.byte	W12
	.byte		        Ds3 , v080
	.byte	W12
	.byte		        Fs2 , v056
	.byte	W12
	.byte		        Cs2 , v052
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Fs2 , v060
	.byte	W12
@ 033   ----------------------------------------
	.byte		        Ds2 , v064
	.byte	W12
	.byte		EOT   , Fs3 
	.byte		        Gs3 
	.byte		N06   , Fs2 
	.byte		TIE   , Fs3 , v068
	.byte	W12
	.byte		N06   , Cn3 , v080
	.byte		N12   , Gs3 , v072
	.byte	W12
	.byte		N06   , Fs2 , v064
	.byte		N12   , An3 , v072
	.byte	W12
	.byte		N06   , En2 , v068
	.byte		N56   , Bn3 , v076
	.byte	W12
	.byte		N06   , Fs2 , v068
	.byte	W12
	.byte		        Cs3 , v084
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
@ 034   ----------------------------------------
	.byte		        Ds2 , v072
	.byte	W12
	.byte		        Fs2 , v076
	.byte		N12   , An3 , v068
	.byte	W12
	.byte		N06   , Cn3 , v084
	.byte		N12   , Bn3 , v068
	.byte	W12
	.byte		N06   , Fs2 , v072
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , Gs1 , v064
	.byte		N56   , Gs3 , v072
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W12
	.byte		        Cn3 , v088
	.byte	W12
	.byte		        Ds2 , v064
	.byte	W12
	.byte		EOT   , Fs3 
@ 035   ----------------------------------------
	.byte		N06   , Gs1 , v056
	.byte	W12
	.byte		        Dn2 , v072
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Bn2 , v080
	.byte		N12   , En3 , v068
	.byte	W12
	.byte		N05   , Dn2 , v064
	.byte		N11   , Dn3 , v068
	.byte	W12
	.byte		N12   , En1 , v060
	.byte		N48   , Cs3 , v104
	.byte	W12
	.byte		N12   , Dn2 , v064
	.byte	W12
	.byte		        En2 , v076
	.byte	W12
	.byte		        Gs2 
	.byte	W12
@ 036   ----------------------------------------
	.byte		N96   , Cs3 , v080
	.byte	W12
	.byte		N12   , Gs2 , v060
	.byte	W12
	.byte		        Dn2 , v056
	.byte	W12
	.byte		N11   , En1 , v048
	.byte	W12
	.byte		N12   , Cs1 , v060
	.byte	W12
	.byte		        Gs1 , v064
	.byte	W12
	.byte		        Fn2 , v068
	.byte	W12
	.byte		N11   , Bn2 
	.byte	W12
@ 037   ----------------------------------------
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		N11   , Gs1 , v052
	.byte	W12
	.byte		N12   , Cs4 , v080
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fn3 , v056
	.byte	W12
	.byte		N11   , Gs2 , v048
	.byte	W12
@ 038   ----------------------------------------
	.byte		N24   , Fs4 , v088
	.byte	W12
	.byte		N12   , Fs2 , v060
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N24   , Cs5 , v120
	.byte	W12
	.byte		N11   , An3 , v076
	.byte	W12
	.byte		N44   , Fs4 , v056
	.byte		N44   , An4 
	.byte		N44   , Cn5 , v060
	.byte	W12
	.byte		N12   , An2 , v056
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N11   , Cn4 , v076
	.byte	W12
@ 039   ----------------------------------------
	.byte		N24   , Cs5 , v068
	.byte	W12
	.byte		N12   , Cs3 , v052
	.byte	W12
	.byte		        Fs3 , v060
	.byte		N24   , Fs4 , v056
	.byte		N24   , An4 
	.byte		N24   , En5 , v076
	.byte	W12
	.byte		N11   , En4 , v072
	.byte	W12
	.byte		N16   , Ds5 , v064
	.byte	W12
	.byte		N12   , Bn2 , v056
	.byte	W03
	.byte		N15   , Fs4 
	.byte		N16   , Bn4 
	.byte	W09
	.byte		N12   , Fs3 , v068
	.byte	W07
	.byte		N15   , An4 , v056
	.byte	W05
	.byte		N11   , Ds4 , v076
	.byte	W12
@ 040   ----------------------------------------
	.byte		N24   , Fs4 , v056
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Cs3 , v064
	.byte		N24   , Cs5 , v060
	.byte	W12
	.byte		N11   , An3 , v080
	.byte	W12
	.byte		N44   , Fs4 , v056
	.byte		N44   , An4 
	.byte		N44   , Cn5 , v064
	.byte	W12
	.byte		N12   , An2 , v056
	.byte	W12
	.byte		        Dn3 , v072
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N11   , Cn4 , v076
	.byte	W12
@ 041   ----------------------------------------
	.byte		N24   , Cs5 , v068
	.byte	W12
	.byte		N12   , Cs3 , v060
	.byte	W12
	.byte		        Fs3 , v072
	.byte		N22   , Fs4 , v056
	.byte		N22   , An4 
	.byte		N22   , En5 , v072
	.byte	W12
	.byte		N11   , En4 , v076
	.byte	W12
	.byte		N16   , Ds5 , v060
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W03
	.byte		N15   , Fs4 , v056
	.byte		N16   , Bn4 
	.byte	W09
	.byte		N12   , Fs3 , v072
	.byte	W07
	.byte		N15   , Ds5 , v068
	.byte	W05
	.byte		N11   , Ds4 , v080
	.byte	W12
@ 042   ----------------------------------------
	.byte		N24   , Cs4 , v056
	.byte	W12
	.byte		N12   , Cs2 , v080
	.byte	W12
	.byte		        Fs2 
	.byte		N24   , Fs3 , v076
	.byte		N24   , An3 
	.byte		N24   , En4 , v060
	.byte	W12
	.byte		N11   , En3 , v108
	.byte	W12
	.byte		N16   , Ds4 , v088
	.byte	W12
	.byte		N12   , Bn1 , v072
	.byte	W03
	.byte		N15   , Fs3 , v080
	.byte		N15   , An3 
	.byte		N16   , Bn3 , v076
	.byte	W09
	.byte		N12   , Fs2 
	.byte	W07
	.byte		N15   , Ds4 , v088
	.byte	W05
	.byte		N11   , Ds3 , v104
	.byte	W12
@ 043   ----------------------------------------
	.byte		N48   , Ds3 , v080
	.byte		N48   , Fs3 
	.byte		N48   , Cs4 
	.byte	W12
	.byte		N12   , An1 , v076
	.byte	W12
	.byte		        Fs2 , v084
	.byte	W12
	.byte		N11   , Cs3 , v100
	.byte	W12
	.byte		N24   , En3 , v080
	.byte		N24   , Gs3 
	.byte		N24   , Bn3 
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        En2 , v088
	.byte		N22   , Bn2 , v080
	.byte		N22   , En3 
	.byte		N22   , Gs3 
	.byte	W12
	.byte		N11   , Gs1 , v084
	.byte	W12
@ 044   ----------------------------------------
	.byte		N48   , An2 , v076
	.byte		N48   , Cs3 
	.byte		N16   , En3 , v072
	.byte	W12
	.byte		N12   , Fs1 , v076
	.byte	W03
	.byte		N16   , Fs3 , v088
	.byte	W09
	.byte		N12   , Cs2 , v092
	.byte	W07
	.byte		N16   , Gs3 , v088
	.byte	W05
	.byte		N11   , Fs1 , v076
	.byte	W12
	.byte		N24   , An2 , v080
	.byte		N24   , En3 
	.byte		N48   , Fs3 , v076
	.byte	W12
	.byte		N12   , Bn0 , v072
	.byte	W12
	.byte		        Bn1 , v084
	.byte		N24   , Ds3 
	.byte	W12
	.byte		N11   , Bn0 , v064
	.byte	W12
@ 045   ----------------------------------------
	.byte		N12   , En1 , v080
	.byte		N22   , Cs3 
	.byte		N60   , En3 , v076
	.byte		N72   , Gs3 
	.byte	W12
	.byte		N12   , Bn1 , v084
	.byte	W12
	.byte		        En2 , v076
	.byte		N24   , Bn2 , v088
	.byte	W12
	.byte		N12   , Gs2 , v080
	.byte	W12
	.byte		        Bn2 , v076
	.byte	W12
	.byte		N30   , En3 , v088
	.byte	W12
	.byte		N19   , Gs3 
	.byte	W12
	.byte		N11   , Bn3 , v096
	.byte	W12
@ 046   ----------------------------------------
	.byte		N48   , Gn3 , v088
	.byte		N48   , As3 
	.byte		N24   , Cs4 , v096
	.byte	W12
	.byte		N12   , Gn2 , v068
	.byte	W12
	.byte		        Cs3 , v076
	.byte		N24   , En4 , v104
	.byte	W12
	.byte		N11   , En3 , v080
	.byte	W12
	.byte		N44   , Gs3 , v096
	.byte		N15   , Bn3 
	.byte		N16   , Ds4 , v080
	.byte	W12
	.byte		N12   , Gs2 , v068
	.byte	W03
	.byte		N30   , Bn3 , v076
	.byte	W09
	.byte		N12   , Bn2 , v068
	.byte	W07
	.byte		N15   , Ds4 , v092
	.byte	W05
	.byte		N11   , Ds3 , v076
	.byte	W12
@ 047   ----------------------------------------
	.byte		N48   , En3 , v080
	.byte		N48   , Gs3 
	.byte		N48   , Cs4 
	.byte	W12
	.byte		N12   , Cs2 , v064
	.byte	W12
	.byte		        Gs2 , v068
	.byte	W12
	.byte		N11   , Cs3 , v080
	.byte	W12
	.byte		N24   , Ds3 , v068
	.byte		N24   , Gs3 
	.byte		N24   , Bn3 
	.byte	W12
	.byte		N12   , Gs1 , v064
	.byte	W12
	.byte		        Ds2 , v072
	.byte		N22   , Bn2 , v080
	.byte		N22   , Ds3 
	.byte		N22   , Gs3 
	.byte	W12
	.byte		N11   , Gs2 , v076
	.byte	W12
@ 048   ----------------------------------------
	.byte		N48   , As2 
	.byte		N48   , Cs3 
	.byte		N16   , En3 
	.byte	W12
	.byte		N12   , Fs1 , v064
	.byte	W03
	.byte		N16   , Fs3 , v084
	.byte	W09
	.byte		N12   , Cs2 , v076
	.byte	W07
	.byte		N16   , Gs3 , v092
	.byte	W05
	.byte		N11   , Fs1 , v068
	.byte	W12
	.byte		N24   , Ds3 , v104
	.byte		N72   , Fs3 , v092
	.byte		N72   , As3 
	.byte	W12
	.byte		N12   , En1 , v072
	.byte	W12
	.byte		        Cs2 , v084
	.byte		N48   , Cs3 , v100
	.byte	W12
	.byte		N11   , En1 , v072
	.byte	W12
@ 049   ----------------------------------------
	.byte		N12   , Ds1 , v076
	.byte	W12
	.byte		        Bn1 , v084
	.byte	W12
	.byte		        Ds2 , v088
	.byte		N24   , Bn2 , v100
	.byte		N24   , Fs3 
	.byte		N24   , Bn3 
	.byte	W12
	.byte		N12   , Fs2 , v088
	.byte	W12
	.byte		        Bn2 , v084
	.byte		N24   , Fs3 , v108
	.byte		N24   , Bn3 
	.byte		N24   , Ds4 
	.byte	W12
	.byte		N12   , Ds3 , v092
	.byte	W12
	.byte		        Fs3 
	.byte		N12   , Bn3 , v108
	.byte		N24   , Ds4 
	.byte		N24   , Fs4 
	.byte	W12
	.byte		N12   , Bn3 , v104
	.byte	W12
@ 050   ----------------------------------------
	.byte		N24   , Ds4 , v056
	.byte		TIE   , En4 , v068
	.byte		TIE   , Gs4 
	.byte	W12
	.byte		N12   , Cs3 , v052
	.byte	W12
	.byte		        En3 , v056
	.byte		N24   , Cs4 , v052
	.byte	W12
	.byte		N11   , Gs3 , v076
	.byte	W12
	.byte		N24   , Ds4 , v064
	.byte	W12
	.byte		N12   , Bn2 , v056
	.byte	W12
	.byte		        En3 , v072
	.byte		N24   , Cs4 , v064
	.byte	W12
	.byte		N11   , Gs3 , v076
	.byte	W12
@ 051   ----------------------------------------
	.byte		N24   , Ds4 , v072
	.byte	W12
	.byte		N12   , As2 , v064
	.byte	W12
	.byte		        En3 , v080
	.byte		N24   , Cs4 , v064
	.byte	W12
	.byte		N11   , Gs3 , v092
	.byte	W12
	.byte		EOT   , En4 
	.byte		        Gs4 
	.byte		N44   , En4 , v084
	.byte		N44   , Gs4 
	.byte		N16   , Bn4 , v076
	.byte	W12
	.byte		N12   , Gs2 , v068
	.byte	W03
	.byte		N16   , Ds5 , v088
	.byte	W09
	.byte		N12   , En3 , v092
	.byte	W07
	.byte		N15   , Bn4 , v072
	.byte	W05
	.byte		N11   , Bn3 , v096
	.byte	W12
@ 052   ----------------------------------------
	.byte		N24   , Ds4 , v060
	.byte		TIE   , En4 , v076
	.byte		TIE   , Gs4 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        En3 , v084
	.byte		N24   , Cs4 , v060
	.byte	W12
	.byte		N11   , Gs3 , v092
	.byte	W12
	.byte		N24   , Ds4 , v064
	.byte	W12
	.byte		N12   , Bn2 , v088
	.byte	W12
	.byte		        En3 , v100
	.byte		N24   , Cs4 , v064
	.byte	W12
	.byte		N11   , Gs3 , v108
	.byte	W12
@ 053   ----------------------------------------
	.byte		N22   , Ds4 , v076
	.byte	W12
	.byte		N12   , As2 , v092
	.byte	W12
	.byte		EOT   , En4 
	.byte		        Gs4 
	.byte		N12   , En3 , v112
	.byte		N24   , En4 , v116
	.byte		N24   , Gs4 
	.byte		N24   , Cs5 
	.byte	W12
	.byte		N11   , Gs3 , v104
	.byte	W12
	.byte		N24   , Cs4 , v092
	.byte		N24   , Fs4 
	.byte		N24   , As4 
	.byte	W12
	.byte		N12   , Fs2 , v084
	.byte	W12
	.byte		        Cs3 , v104
	.byte		N22   , An3 , v080
	.byte		N22   , En4 
	.byte		N22   , Gs4 
	.byte	W12
	.byte		N11   , Fs3 , v104
	.byte	W12
@ 054   ----------------------------------------
	.byte		N24   , Cs4 , v064
	.byte		TIE   , Dn4 , v084
	.byte		TIE   , Fs4 
	.byte	W12
	.byte		N12   , Bn2 , v080
	.byte	W12
	.byte		        Dn3 , v088
	.byte		N24   , Bn3 , v060
	.byte	W12
	.byte		N11   , Fs3 , v100
	.byte	W12
	.byte		N24   , Cs4 , v072
	.byte	W12
	.byte		N12   , An2 , v080
	.byte	W12
	.byte		        Dn3 , v084
	.byte		N24   , Bn3 , v060
	.byte	W12
	.byte		N11   , Fs3 , v092
	.byte	W12
@ 055   ----------------------------------------
	.byte		N24   , Cs4 , v064
	.byte	W12
	.byte		N12   , Gs2 , v080
	.byte	W12
	.byte		        Dn3 , v104
	.byte		N24   , Bn3 , v060
	.byte	W12
	.byte		N11   , Fs3 , v100
	.byte	W12
	.byte		EOT   , Dn4 
	.byte		        Fs4 
	.byte		N44   , Dn4 , v076
	.byte		N44   , Fs4 
	.byte		N16   , An4 , v100
	.byte	W12
	.byte		N12   , Fs2 , v080
	.byte	W03
	.byte		N16   , Cs5 , v108
	.byte	W09
	.byte		N12   , Dn3 
	.byte	W07
	.byte		N15   , An4 , v096
	.byte	W05
	.byte		N11   , An3 , v120
	.byte	W12
@ 056   ----------------------------------------
	.byte		N24   , Cs4 , v080
	.byte		TIE   , Dn4 , v076
	.byte		TIE   , Fs4 
	.byte	W12
	.byte		N12   , Bn2 , v080
	.byte	W12
	.byte		        Dn3 , v088
	.byte		N24   , Bn3 , v080
	.byte	W12
	.byte		N11   , Fs3 , v096
	.byte	W12
	.byte		N24   , Cs4 , v100
	.byte	W12
	.byte		N12   , An2 , v080
	.byte	W12
	.byte		        Dn3 , v088
	.byte		N24   , Bn3 , v100
	.byte	W12
	.byte		N11   , Fs3 , v096
	.byte	W12
@ 057   ----------------------------------------
	.byte		N22   , Cs4 , v092
	.byte	W12
	.byte		N12   , Gs2 , v076
	.byte	W12
	.byte		EOT   , Dn4 
	.byte		        Fs4 
	.byte		N12   , Dn3 , v092
	.byte		N24   , Dn4 
	.byte		N24   , Fs4 
	.byte		N24   , Bn4 
	.byte	W12
	.byte		N11   , Fs3 , v088
	.byte	W12
	.byte		N24   , Bn3 , v076
	.byte		N24   , En4 
	.byte		N24   , Gs4 
	.byte	W12
	.byte		N12   , En2 , v068
	.byte	W12
	.byte		        Bn2 , v076
	.byte		N22   , Gs3 , v068
	.byte		N22   , Dn4 
	.byte		N22   , Fs4 
	.byte	W12
	.byte		N11   , En2 
	.byte	W12
@ 058   ----------------------------------------
	.byte		N12   , An1 , v064
	.byte		N24   , An3 , v072
	.byte		N24   , Cs4 
	.byte		N24   , En4 
	.byte	W12
	.byte		N12   , En2 , v076
	.byte	W12
	.byte		        An2 
	.byte		N06   , En3 , v064
	.byte		N06   , An3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Cs3 , v080
	.byte		N06   , En3 , v072
	.byte		N06   , An3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Cs3 , v076
	.byte		N12   , En3 , v072
	.byte		N12   , An3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        An2 , v068
	.byte	W12
	.byte		        En2 
	.byte		N24   , An3 , v088
	.byte		N24   , Cs4 
	.byte		N24   , En4 
	.byte	W12
	.byte		N12   , An1 , v064
	.byte	W12
@ 059   ----------------------------------------
	.byte		        Fs1 , v068
	.byte		N24   , An3 , v088
	.byte		N24   , Cs4 
	.byte		N24   , Fs4 
	.byte	W12
	.byte		N12   , Cs2 , v084
	.byte	W12
	.byte		        Fs2 , v080
	.byte		N06   , An3 , v076
	.byte		N06   , Cs4 
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , Cs3 , v084
	.byte		N06   , Bn3 , v076
	.byte		N06   , Cs4 
	.byte		N06   , Gs4 
	.byte	W12
	.byte		N12   , Cs3 
	.byte		N06   , An3 , v068
	.byte		N06   , Cs4 
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , Fs2 
	.byte		N06   , Bn3 , v072
	.byte		N06   , Cs4 
	.byte		N06   , Gs4 
	.byte	W12
	.byte		N12   , Cs2 , v068
	.byte		N24   , An3 , v076
	.byte		N24   , Cs4 
	.byte		N24   , Fs4 
	.byte	W12
	.byte		N12   , Fs1 , v064
	.byte	W12
@ 060   ----------------------------------------
	.byte		        An1 , v076
	.byte		N24   , An3 
	.byte		N24   , Cs4 
	.byte		N24   , En4 
	.byte	W12
	.byte		N12   , En2 , v084
	.byte	W12
	.byte		        An2 , v080
	.byte		N06   , Gs3 , v064
	.byte		N06   , An3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Cs3 , v088
	.byte		N06   , Gs3 , v072
	.byte		N06   , An3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Cs3 , v076
	.byte		N12   , Fs3 
	.byte		N12   , An3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 , v080
	.byte		N12   , En3 , v072
	.byte		N12   , Fs3 
	.byte		N12   , An3 
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
@ 061   ----------------------------------------
	.byte		        Dn1 , v080
	.byte		N96   , Dn3 , v127
	.byte		N96   , Fs3 
	.byte		N96   , An3 
	.byte		N96   , Cs4 
	.byte	W12
	.byte		N12   , An1 , v088
	.byte	W12
	.byte		        Dn2 , v096
	.byte	W12
	.byte		        Fs2 , v084
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn2 , v080
	.byte	W12
	.byte		        An1 , v084
	.byte	W12
	.byte		        Dn1 , v076
	.byte	W12
@ 062   ----------------------------------------
	.byte		        Gn1 , v040
	.byte		N24   , Dn3 , v044
	.byte		N24   , Gn3 
	.byte		N24   , Bn3 
	.byte	W12
	.byte		N12   , Dn2 , v040
	.byte	W12
	.byte		        Gn2 , v044
	.byte		N06   , Bn2 , v036
	.byte		N06   , Dn3 
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   , Dn2 
	.byte		N06   , Bn2 , v040
	.byte		N06   , Dn3 
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   , Gn1 
	.byte		N12   , Bn2 
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Dn2 , v044
	.byte	W12
	.byte		        Gn2 , v040
	.byte		N12   , Dn3 , v044
	.byte		N12   , Gn3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Dn2 , v040
	.byte	W12
@ 063   ----------------------------------------
	.byte		        Dn1 , v036
	.byte		N24   , Cn3 , v044
	.byte		N24   , Fn3 
	.byte		N24   , An3 
	.byte	W12
	.byte		N12   , An1 , v048
	.byte	W12
	.byte		        Fn2 , v044
	.byte		N06   , Cn3 
	.byte		N06   , Fn3 
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , An1 , v036
	.byte		N06   , Dn3 , v044
	.byte		N06   , Fn3 
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , Fn1 , v040
	.byte		N06   , Cn3 
	.byte		N06   , Fn3 
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , Cn2 
	.byte		N06   , Dn3 , v044
	.byte		N06   , Fn3 
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , An2 
	.byte		N12   , En3 
	.byte		N12   , Fn3 
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cn2 , v032
	.byte	W12
@ 064   ----------------------------------------
	.byte		        Gn1 , v036
	.byte		N24   , Dn3 , v044
	.byte		N24   , Gn3 
	.byte		N24   , Bn3 
	.byte	W12
	.byte		N12   , Dn2 , v048
	.byte	W12
	.byte		        Gn2 
	.byte		N06   , Bn2 , v040
	.byte		N06   , Dn3 
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   , Dn2 
	.byte		N06   , Bn2 , v036
	.byte		N06   , Dn3 
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   , Fn1 , v040
	.byte		N12   , Bn2 
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Dn2 , v044
	.byte	W12
	.byte		        Gn2 
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Dn2 , v040
	.byte	W12
@ 065   ----------------------------------------
	.byte		        En1 , v036
	.byte		N48   , En3 , v048
	.byte		N48   , Gs3 
	.byte		N48   , Bn3 
	.byte	W12
	.byte		N12   , Bn1 , v052
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        En2 
	.byte		N36   , En3 
	.byte	W12
	.byte		N12   , Gs2 , v072
	.byte	W12
	.byte		        Bn2 , v080
	.byte	W12
	.byte		        En3 , v092
	.byte	W12
@ 066   ----------------------------------------
	.byte		        An2 , v080
	.byte		N24   , An3 , v116
	.byte		N24   , Cs4 
	.byte		N24   , En4 
	.byte	W12
	.byte		N12   , Cs3 , v092
	.byte	W12
	.byte		        En3 , v096
	.byte		N06   , An3 , v084
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Cs3 , v076
	.byte		N06   , An3 , v088
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Gs2 , v080
	.byte		N12   , An3 , v088
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Cs3 , v092
	.byte	W12
	.byte		        En3 
	.byte		N24   , An3 , v100
	.byte		N24   , Cs4 
	.byte		N24   , En4 
	.byte	W12
	.byte		N12   , Cs3 , v080
	.byte	W12
@ 067   ----------------------------------------
	.byte		        Fs2 
	.byte		N24   , An3 , v100
	.byte		N24   , Cs4 
	.byte		N24   , Fs4 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Fs3 , v096
	.byte		N06   , An3 , v088
	.byte		N06   , Cs4 
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , Cs3 , v072
	.byte		N06   , Bn3 , v088
	.byte		N06   , Cs4 
	.byte		N06   , Gs4 
	.byte	W12
	.byte		N12   , Dn2 , v076
	.byte		N06   , An3 , v084
	.byte		N06   , Dn4 
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , An2 , v092
	.byte		N06   , An3 , v088
	.byte		N06   , Dn4 
	.byte		N06   , Gs4 
	.byte	W12
	.byte		N12   , Fs3 , v104
	.byte		N24   , An3 , v088
	.byte		N24   , Cs4 
	.byte		N24   , Fs4 
	.byte	W12
	.byte		N12   , An2 , v080
	.byte	W12
@ 068   ----------------------------------------
	.byte		        An1 , v072
	.byte		N24   , An3 , v092
	.byte		N24   , Cs4 
	.byte		N24   , En4 
	.byte	W12
	.byte		N12   , En2 , v088
	.byte	W12
	.byte		        Cs3 , v100
	.byte		N06   , Gs3 , v076
	.byte		N06   , An3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , En2 
	.byte		N06   , Gs3 , v080
	.byte		N06   , An3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Fs1 , v072
	.byte		N12   , Fs3 , v088
	.byte		N12   , An3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        An2 
	.byte		N24   , En3 , v084
	.byte		N24   , Fs3 
	.byte		N24   , An3 
	.byte	W12
	.byte		N12   , Cs2 , v080
	.byte	W12
@ 069   ----------------------------------------
	.byte		        Bn0 , v072
	.byte		TIE   , Ds3 , v120
	.byte		TIE   , Fs3 
	.byte		TIE   , An3 
	.byte		TIE   , Cs4 
	.byte	W12
	.byte		N12   , Fs1 , v092
	.byte	W12
	.byte		        Bn1 , v088
	.byte	W12
	.byte		        Fs1 , v080
	.byte	W12
	.byte		        Fs1 , v084
	.byte	W12
	.byte		        Bn1 , v096
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn1 , v080
	.byte	W12
@ 070   ----------------------------------------
	.byte		        Bn1 , v096
	.byte	W12
	.byte		        Fs2 , v108
	.byte	W12
	.byte		EOT   , Ds3 
	.byte		        Fs3 
	.byte		        An3 
	.byte		        Cs4 
	.byte		N12   , Bn2 , v104
	.byte		N12   , Fs3 , v088
	.byte		N12   , An3 
	.byte	W12
	.byte		        Fs2 , v092
	.byte		N12   , Bn2 , v096
	.byte		N12   , Fs3 
	.byte		N12   , An3 
	.byte	W12
	.byte		        Fs1 , v084
	.byte		N24   , Bn2 , v088
	.byte		N24   , Ds3 
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   , Cs2 , v104
	.byte	W12
	.byte		        Fs2 
	.byte		N24   , En3 
	.byte		N24   , Fs3 
	.byte		N24   , An3 
	.byte	W12
	.byte		N12   , Cs2 , v092
	.byte	W12
@ 071   ----------------------------------------
	.byte		        Bn1 
	.byte		N24   , Ds3 , v112
	.byte		N24   , An3 
	.byte		N24   , Cs4 
	.byte	W12
	.byte		N12   , Fs2 , v108
	.byte	W12
	.byte		        Bn2 
	.byte		N12   , Fs3 , v088
	.byte		N12   , An3 
	.byte	W12
	.byte		        Fs2 , v096
	.byte		N12   , Bn2 , v100
	.byte		N12   , Fs3 
	.byte		N12   , An3 
	.byte	W12
	.byte		        Fs1 , v084
	.byte		N24   , Bn2 , v088
	.byte		N24   , Ds3 
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   , Cs2 , v108
	.byte	W12
	.byte		        Fs2 , v104
	.byte		N24   , En3 
	.byte		N24   , Fs3 
	.byte		N24   , An3 
	.byte	W12
	.byte		N12   , Cs2 , v092
	.byte	W12
@ 072   ----------------------------------------
	.byte		        Bn1 
	.byte		N24   , Ds3 , v112
	.byte		N24   , An3 
	.byte		N24   , Cs4 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte		N48   , Cs3 , v088
	.byte		N48   , Fs3 
	.byte		N48   , An3 
	.byte	W12
	.byte		N12   , Fs2 , v100
	.byte	W12
	.byte		        Fs1 , v084
	.byte	W12
	.byte		        Cs2 , v112
	.byte	W12
	.byte		        Fs2 , v104
	.byte		N24   , Fs3 
	.byte		N24   , An3 
	.byte		N24   , Cs4 
	.byte	W12
	.byte		N12   , Cs2 , v096
	.byte	W12
@ 073   ----------------------------------------
	.byte		        Gs3 , v127
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Ds3 , v068
	.byte	W12
	.byte		        Gs0 , v088
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Gs1 , v104
	.byte	W12
	.byte		        Gs1 , v100
	.byte	W12
	.byte		        Ds2 , v108
	.byte	W12
	.byte		        Ds3 , v127
	.byte	W12
	.byte		N11   , Gs2 , v120
	.byte	W12
@ 074   ----------------------------------------
	.byte		N12   , Gs2 , v100
	.byte	W12
	.byte		        Ds3 , v124
	.byte	W12
	.byte		        Ds4 , v127
	.byte	W12
	.byte		N11   , Gs3 , v112
	.byte	W12
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Ds4 , v120
	.byte	W12
	.byte		        Ds5 , v127
	.byte	W12
	.byte		N11   , Gs4 , v112
	.byte	W12
@ 075   ----------------------------------------
	.byte		N12   , Gs3 , v032
	.byte		N24   , Cn5 , v036
	.byte		N24   , Ds5 
	.byte	W12
	.byte		N12   , Cn4 , v032
	.byte	W12
	.byte		        Ds4 , v044
	.byte		N24   , Cn5 , v028
	.byte	W12
	.byte		N11   , Cn4 , v044
	.byte	W12
	.byte		N12   , Gs3 , v036
	.byte		N48   , Bn4 
	.byte		N24   , Ds5 , v044
	.byte	W12
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Ds4 , v048
	.byte		N24   , Gn5 , v044
	.byte	W12
	.byte		N11   , Bn3 , v040
	.byte	W12
@ 076   ----------------------------------------
	.byte		N12   , Gs3 , v032
	.byte		N44   , Cn5 , v040
	.byte		N44   , Ds5 , v032
	.byte	W12
	.byte		N12   , Cn4 , v036
	.byte	W12
	.byte		        Ds4 , v044
	.byte	W12
	.byte		N11   , Cn4 , v040
	.byte	W12
	.byte		N12   , Gn3 , v044
	.byte		N96   , Gs4 , v036
	.byte		N24   , Cn5 
	.byte	W12
	.byte		N12   , Gs3 , v040
	.byte	W12
	.byte		        Cn4 , v044
	.byte		N24   , Ds5 , v036
	.byte	W12
	.byte		N11   , Gn3 
	.byte	W12
@ 077   ----------------------------------------
	.byte		N12   , Fn3 
	.byte		N16   , Cn5 , v040
	.byte	W12
	.byte		N12   , Gs3 , v036
	.byte	W03
	.byte		N16   , As4 , v040
	.byte	W09
	.byte		N12   , Cn4 
	.byte	W07
	.byte		N16   , Cn5 , v044
	.byte	W05
	.byte		N11   , Gs3 , v040
	.byte	W12
	.byte		N12   , Ds3 , v032
	.byte		N48   , Gn4 , v028
	.byte		N24   , Gs4 , v040
	.byte	W12
	.byte		N12   , Gn3 , v036
	.byte	W12
	.byte		        Gs3 , v044
	.byte		N24   , Cn5 , v040
	.byte	W12
	.byte		N11   , Gn3 , v044
	.byte	W12
@ 078   ----------------------------------------
	.byte		N12   , Cs3 , v036
	.byte		N44   , Fn4 , v040
	.byte		N44   , As4 , v044
	.byte	W12
	.byte		N12   , Fn3 , v036
	.byte	W12
	.byte		        Gs3 , v044
	.byte	W12
	.byte		N11   , Fn3 , v040
	.byte	W12
	.byte		N12   , Ds3 , v036
	.byte		N24   , As3 , v028
	.byte	W12
	.byte		N12   , Fn3 , v048
	.byte	W12
	.byte		        Gs3 , v056
	.byte		N22   , Cn4 , v052
	.byte	W12
	.byte		N11   , Fn3 
	.byte	W12
@ 079   ----------------------------------------
	.byte		N44   , Fn3 , v060
	.byte		N48   , Cs4 , v064
	.byte	W12
	.byte		N12   , Gs3 , v068
	.byte	W12
	.byte		        As3 , v060
	.byte	W12
	.byte		N11   , Gs3 , v052
	.byte	W12
	.byte		N44   , Ds3 , v044
	.byte		N24   , Cn4 , v052
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte		N22   , Fn4 
	.byte	W12
	.byte		N11   , Gn3 , v040
	.byte	W12
@ 080   ----------------------------------------
	.byte		N44   , Cs3 , v036
	.byte		N48   , As3 , v032
	.byte	W12
	.byte		N12   , Fn3 , v040
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N11   , Fn3 , v036
	.byte	W12
	.byte		N42   , Cn3 , v032
	.byte		N24   , Gs3 , v028
	.byte	W12
	.byte		N12   , Ds3 , v032
	.byte	W12
	.byte		        Fn3 , v028
	.byte		N22   , Fn4 , v032
	.byte	W12
	.byte		N11   , Ds3 , v024
	.byte	W12
@ 081   ----------------------------------------
	.byte		N44   , As2 , v016
	.byte		N48   , Gn3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N11   , Cs3 , v020
	.byte	W12
	.byte		N44   , Gs2 
	.byte		N24   , Fn3 , v012
	.byte	W12
	.byte		N12   , Cn3 , v024
	.byte	W12
	.byte		        Cs3 , v028
	.byte		N24   , Fn4 , v032
	.byte	W12
	.byte		N11   , Cn3 , v020
	.byte	W12
@ 082   ----------------------------------------
	.byte		N44   , Gn2 , v016
	.byte		TIE   , Ds3 , v024
	.byte	W12
	.byte		N12   , As2 , v016
	.byte	W12
	.byte		        Cs3 , v024
	.byte	W12
	.byte		N11   , As2 
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W12
	.byte		N12   , As2 , v028
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N22   , Ds2 
	.byte	W12
	.byte		N12   , As2 
	.byte		N12   , Cs3 
	.byte	W12
@ 083   ----------------------------------------
	.byte		        Gs1 , v036
	.byte	W12
	.byte		        Ds2 , v032
	.byte	W06
	.byte		EOT   , Ds3 
	.byte	W06
	.byte		N12   , Gs1 , v036
	.byte		N24   , Cn3 , v040
	.byte	W12
	.byte		N11   , Ds2 
	.byte	W12
	.byte		N12   , Gn1 
	.byte		N48   , Bn2 , v036
	.byte		N24   , Ds3 , v044
	.byte	W12
	.byte		N12   , Ds2 , v036
	.byte	W12
	.byte		        Gn1 
	.byte		N24   , Gn3 , v044
	.byte	W12
	.byte		N11   , Ds2 , v036
	.byte	W12
@ 084   ----------------------------------------
	.byte		N12   , Gs1 , v040
	.byte		N48   , Cn3 , v036
	.byte		N48   , Ds3 , v044
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Gs1 , v036
	.byte	W12
	.byte		N11   , Ds2 , v040
	.byte	W12
	.byte		N12   , Gn1 
	.byte		N48   , As2 
	.byte		N24   , Cn3 , v032
	.byte	W12
	.byte		N12   , Ds2 , v048
	.byte	W12
	.byte		        Gn1 , v036
	.byte		N24   , Ds3 , v032
	.byte	W12
	.byte		N11   , Ds2 , v036
	.byte	W12
@ 085   ----------------------------------------
	.byte		N12   , Fn1 , v032
	.byte		N48   , Gs2 , v036
	.byte		N16   , Cn3 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W03
	.byte		N16   , As2 
	.byte	W09
	.byte		N12   , Fn1 
	.byte	W07
	.byte		N16   , Cn3 , v044
	.byte	W05
	.byte		N11   , Cn2 , v036
	.byte	W12
	.byte		N12   , Ds1 
	.byte		N48   , Gn2 , v044
	.byte		N24   , Gs2 , v040
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Ds1 
	.byte		N24   , Cn3 , v044
	.byte	W12
	.byte		N11   , Cn2 
	.byte	W12
@ 086   ----------------------------------------
	.byte		N12   , Gs0 , v032
	.byte		N90   , Dn2 , v040
	.byte		N90   , Fn2 
	.byte		N48   , As2 , v048
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Gs0 , v036
	.byte	W12
	.byte		        Gs1 , v048
	.byte	W12
	.byte		        Gs0 , v040
	.byte		N24   , Gs2 
	.byte	W12
	.byte		N12   , Gs1 , v044
	.byte	W12
	.byte		        Gs0 , v036
	.byte		N22   , As2 , v040
	.byte	W12
	.byte		N12   , Gs1 , v044
	.byte	W12
@ 087   ----------------------------------------
	.byte	TEMPO , 184*bergamasque_4_passepied_tbs/2
	.byte		N05   , Gs1 , v020
	.byte		N23   , En3 , v032
	.byte		N23   , Gs3 
	.byte		N23   , Bn3 
	.byte	W11
	.byte		N06   , En2 , v028
	.byte	W12
	.byte		        Bn2 , v024
	.byte		N06   , En3 , v020
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        En2 
	.byte		N06   , En3 
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Gs1 , v016
	.byte		N12   , En3 , v020
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		        Bn2 , v028
	.byte		N12   , En3 , v020
	.byte		N12   , Gs3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		        Gs1 
	.byte		N24   , En3 , v028
	.byte		N24   , Gs3 
	.byte		N24   , Cs4 
	.byte	W01
@ 088   ----------------------------------------
	.byte	W11
	.byte		N06   , En2 , v024
	.byte	W12
	.byte		        As2 , v028
	.byte		N06   , En3 , v024
	.byte		N06   , Gs3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        En2 , v020
	.byte		N06   , En3 , v028
	.byte		N06   , Gs3 
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Gs1 , v024
	.byte		N06   , En3 , v016
	.byte		N06   , Gs3 
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        En2 , v024
	.byte		N06   , En3 
	.byte		N06   , Gs3 
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        As2 , v020
	.byte		N12   , En3 , v024
	.byte		N12   , Gs3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , En2 , v020
	.byte	W12
	.byte		        Gs1 , v016
	.byte		N24   , En3 , v020
	.byte		N24   , Gs3 
	.byte		N24   , Bn3 
	.byte	W01
@ 089   ----------------------------------------
	.byte	W11
	.byte		N06   , En2 , v024
	.byte	W12
	.byte		        Bn2 
	.byte		N06   , En3 , v016
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        En2 
	.byte		N06   , En3 , v028
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Gs1 , v020
	.byte		N12   , En3 , v024
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , En2 , v028
	.byte	W12
	.byte		        Bn2 , v024
	.byte		N12   , En3 , v028
	.byte		N12   , Gs3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , En2 , v024
	.byte	W12
	.byte		        Gs1 , v020
	.byte		N96   , Dn3 , v024
	.byte		N60   , Fn3 
	.byte		N96   , Gs3 
	.byte		N96   , As3 
	.byte	W01
@ 090   ----------------------------------------
	.byte	W11
	.byte		N06   , Fn2 , v028
	.byte	W12
	.byte		        As2 , v024
	.byte	W12
	.byte		        Fn2 , v020
	.byte	W12
	.byte		        Gs2 , v024
	.byte	W12
	.byte		N24   , Fn3 , v028
	.byte	W12
	.byte		N06   , Bn3 , v024
	.byte	W12
	.byte		N12   , Fn3 , v020
	.byte	W12
	.byte		N06   , Gs2 , v024
	.byte		N24   , En4 , v028
	.byte		N24   , Gs4 
	.byte		N24   , Bn4 
	.byte	W01
@ 091   ----------------------------------------
	.byte	W11
	.byte		N06   , En3 , v024
	.byte	W12
	.byte		        Bn3 , v028
	.byte		N06   , En4 , v020
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        En3 
	.byte		N06   , En4 
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        Gs2 
	.byte		N12   , En4 , v024
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		        Bn3 , v020
	.byte		N12   , En4 , v024
	.byte		N12   , Gs4 
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , En3 , v016
	.byte	W12
	.byte		        Gs2 , v020
	.byte		N24   , En4 , v024
	.byte		N24   , Gs4 
	.byte		N24   , Cs5 
	.byte	W01
@ 092   ----------------------------------------
	.byte	W11
	.byte		N06   , En3 
	.byte	W12
	.byte		        As3 , v028
	.byte		N06   , En4 , v016
	.byte		N06   , Gs4 
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        En3 
	.byte		N06   , En4 , v024
	.byte		N06   , Gs4 
	.byte		N06   , Ds5 
	.byte	W12
	.byte		        Gs2 
	.byte		N06   , En4 , v020
	.byte		N06   , Gs4 
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        En3 , v032
	.byte		N06   , En4 , v024
	.byte		N06   , Gs4 
	.byte		N06   , Ds5 
	.byte	W12
	.byte		        As3 
	.byte		N12   , En4 
	.byte		N12   , Gs4 
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , En3 , v020
	.byte	W12
	.byte		        Gs2 , v016
	.byte		N24   , En4 , v024
	.byte		N24   , Gs4 
	.byte		N24   , Bn4 
	.byte	W01
@ 093   ----------------------------------------
	.byte	W11
	.byte		N06   , En3 
	.byte	W12
	.byte		        Bn3 , v028
	.byte		N06   , En4 , v016
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        En3 , v020
	.byte		N06   , En4 , v024
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        Gs2 , v020
	.byte		N12   , En4 , v024
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   , En3 , v028
	.byte	W12
	.byte		        Bn3 , v024
	.byte		N12   , En4 
	.byte		N12   , Gs4 
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , En3 , v020
	.byte	W12
	.byte		TIE   , Gs2 
	.byte		N12   , Fn4 
	.byte		N12   , As4 
	.byte	W01
@ 094   ----------------------------------------
	.byte	W11
	.byte		        Dn4 , v016
	.byte	W12
	.byte		        Dn3 
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N11   , As3 , v020
	.byte	W12
	.byte		N12   , Fn4 , v032
	.byte		N12   , As4 
	.byte	W12
	.byte		        Dn4 , v024
	.byte	W12
	.byte		        Dn3 , v016
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N11   , As3 , v020
	.byte	W12
	.byte		N12   , Fn4 , v028
	.byte		N12   , As4 
	.byte	W01
@ 095   ----------------------------------------
	.byte	W11
	.byte		        Dn4 , v024
	.byte	W12
	.byte		        Dn3 , v020
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N11   , As3 
	.byte	W12
	.byte		N12   , Fn4 , v024
	.byte		N12   , As4 
	.byte	W12
	.byte		        Dn4 , v020
	.byte	W12
	.byte		        Dn3 
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N11   , As3 
	.byte	W12
	.byte		N12   , Fn4 , v028
	.byte		N12   , As4 
	.byte	W01
@ 096   ----------------------------------------
	.byte	W11
	.byte		        Dn4 , v016
	.byte	W12
	.byte		        Dn3 , v024
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        As3 , v032
	.byte	W12
	.byte		        Fs4 , v036
	.byte		N12   , As4 
	.byte	W12
	.byte		        Ds4 , v028
	.byte	W12
	.byte		        Ds3 
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Bn3 , v044
	.byte	W12
	.byte		EOT   , Gs2 
	.byte		N96   , Bn2 , v020
	.byte		N12   , Gs4 , v048
	.byte		N12   , Cs5 
	.byte	W01
@ 097   ----------------------------------------
	.byte	W11
	.byte		        Fn4 , v028
	.byte	W12
	.byte		        Fn3 
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Cs4 , v036
	.byte	W12
	.byte		        Fs4 , v032
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Ds4 , v016
	.byte	W12
	.byte		N11   , Ds3 , v008
	.byte		N11   , Fs3 
	.byte	W12
	.byte		N12   , Bn3 , v028
	.byte	W12
	.byte		N96   , Gs2 , v044
	.byte		N12   , Fn4 , v052
	.byte		N12   , As4 
	.byte	W01
@ 098   ----------------------------------------
	.byte	W11
	.byte		        Dn4 , v044
	.byte	W12
	.byte		        Dn3 , v028
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N11   , As3 , v048
	.byte	W12
	.byte		N12   , Fs4 , v056
	.byte		N12   , As4 
	.byte	W12
	.byte		        Ds4 , v040
	.byte	W12
	.byte		        Ds3 , v036
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N11   , Bn3 , v068
	.byte	W12
	.byte		N96   , Bn2 , v044
	.byte		N12   , Gs4 , v080
	.byte		N12   , Cs5 
	.byte	W01
@ 099   ----------------------------------------
	.byte	W11
	.byte		        Fn4 , v056
	.byte	W12
	.byte		        Fn3 , v040
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N11   , Cs4 , v056
	.byte	W12
	.byte		N12   , Fs4 , v064
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Ds4 , v040
	.byte	W12
	.byte		        Ds3 
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N11   , Bn3 , v044
	.byte	W12
	.byte		N96   , Gs2 , v040
	.byte		N12   , Fn4 , v052
	.byte		N12   , As4 
	.byte	W01
@ 100   ----------------------------------------
	.byte	W11
	.byte		        Dn4 , v040
	.byte	W12
	.byte		        Dn3 , v036
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N11   , As3 , v056
	.byte	W12
	.byte		N12   , Fs4 , v068
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Ds4 , v048
	.byte	W12
	.byte		        Ds3 , v044
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N11   , Bn3 
	.byte	W12
	.byte		TIE   , Bn2 
	.byte		N12   , Gs4 , v080
	.byte		N12   , Cs5 
	.byte	W01
@ 101   ----------------------------------------
	.byte	W11
	.byte		        Fn4 , v068
	.byte	W12
	.byte		        Fn3 , v048
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N11   , Cs4 , v056
	.byte	W12
	.byte		N12   , Gs4 , v080
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Fn4 , v068
	.byte	W12
	.byte		        Fn3 , v048
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N11   , Cs4 , v052
	.byte	W12
	.byte		N12   , Gs4 , v080
	.byte		N12   , Cs5 
	.byte	W01
@ 102   ----------------------------------------
	.byte	W11
	.byte		        Fn4 , v064
	.byte	W12
	.byte		        Fn3 , v044
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N11   , Cs4 , v052
	.byte	W12
	.byte		N12   , Gs4 , v080
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Fn4 , v068
	.byte	W12
	.byte		        Fn3 , v044
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N11   , Cs4 , v052
	.byte	W12
	.byte		EOT   , Bn2 
	.byte		N12   , Gs4 , v080
	.byte		N12   , Cs5 
	.byte	W01
@ 103   ----------------------------------------
	.byte	W11
	.byte		        Fn4 , v044
	.byte	W12
	.byte		        Fn3 , v032
	.byte		N12   , An3 
	.byte	W12
	.byte		N11   , Cs4 
	.byte	W12
	.byte		N12   , Gs4 , v052
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Fn4 , v040
	.byte	W12
	.byte		        Fn3 , v032
	.byte		N12   , An3 
	.byte	W12
	.byte		N11   , Cs4 
	.byte	W12
	.byte		N12   , Gs4 , v052
	.byte		N12   , Cs5 
	.byte	W01
@ 104   ----------------------------------------
	.byte	W11
	.byte		        Fn4 , v048
	.byte	W12
	.byte		        Fn3 , v032
	.byte		N12   , An3 
	.byte	W12
	.byte		N11   , Cs4 , v036
	.byte	W12
	.byte		N12   , Gs4 , v052
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Fn4 , v044
	.byte	W12
	.byte		        Fn3 , v036
	.byte		N12   , An3 
	.byte	W12
	.byte		N11   , Cs4 
	.byte	W12
	.byte		N96   , En3 , v080
	.byte		N12   , Fs3 , v072
	.byte		N12   , Cs5 , v084
	.byte	W01
@ 105   ----------------------------------------
	.byte	W11
	.byte		        An4 , v076
	.byte	W12
	.byte		        Cs4 
	.byte		N12   , Fs4 , v056
	.byte	W12
	.byte		N11   , Cs4 , v048
	.byte	W12
	.byte		N72   , Bn3 , v068
	.byte		N12   , Cs5 , v080
	.byte	W12
	.byte		        An4 , v072
	.byte	W12
	.byte		        Fs4 , v056
	.byte	W12
	.byte		N11   , Cs4 , v044
	.byte	W12
	.byte		N48   , Ds3 , v060
	.byte		N12   , Cs5 , v076
	.byte	W01
@ 106   ----------------------------------------
	.byte	W11
	.byte		        An4 
	.byte	W12
	.byte		N06   , An3 , v056
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Gs3 , v060
	.byte		N11   , Cs4 , v052
	.byte	W12
	.byte		N36   , Dn3 , v060
	.byte		N24   , Fs3 , v056
	.byte		N12   , Cs5 , v076
	.byte	W12
	.byte		        An4 , v072
	.byte	W12
	.byte		N06   , En3 , v060
	.byte		N12   , Fs4 , v056
	.byte	W12
	.byte		        Dn3 
	.byte		N11   , Cs4 , v052
	.byte	W12
	.byte		N48   , Fs2 
	.byte		N24   , Cs3 , v056
	.byte		N12   , Cs5 , v080
	.byte	W01
@ 107   ----------------------------------------
	.byte	W11
	.byte		        An4 , v076
	.byte	W12
	.byte		N06   , Dn3 , v068
	.byte		N12   , Fs4 , v060
	.byte	W12
	.byte		N06   , En3 , v068
	.byte		N11   , Cs4 , v052
	.byte	W12
	.byte		N24   , An2 , v060
	.byte		N12   , Fs3 , v064
	.byte		N12   , Cs5 , v076
	.byte	W12
	.byte		        An4 , v072
	.byte	W12
	.byte		N24   , Bn2 , v060
	.byte		N12   , An3 , v068
	.byte		N12   , Fs4 , v056
	.byte	W12
	.byte		N11   , Cs4 , v048
	.byte	W12
	.byte		N96   , Cs3 , v060
	.byte		N96   , Gs3 
	.byte		N12   , Cs5 , v076
	.byte	W01
@ 108   ----------------------------------------
	.byte	W11
	.byte		        Bn4 
	.byte	W12
	.byte		        Fs4 , v056
	.byte	W12
	.byte		N11   , Cs4 , v048
	.byte	W12
	.byte		N12   , Cs5 , v080
	.byte	W12
	.byte		        Bn4 , v084
	.byte	W12
	.byte		        Fn4 , v052
	.byte	W12
	.byte		N11   , Cs4 , v044
	.byte	W12
	.byte		N12   , An1 , v056
	.byte	W01
@ 109   ----------------------------------------
	.byte	W11
	.byte		        Fs2 , v064
	.byte		N12   , Fs3 , v056
	.byte	W12
	.byte		        Cs3 , v072
	.byte		N12   , Gs3 , v068
	.byte	W12
	.byte		        Fs2 , v056
	.byte		N12   , An3 , v068
	.byte	W12
	.byte		        Gs1 , v056
	.byte		N24   , Fs3 
	.byte		N56   , Bn3 , v064
	.byte	W12
	.byte		N12   , Cs2 , v068
	.byte	W12
	.byte		        Bn2 
	.byte		N24   , Fn3 , v052
	.byte	W12
	.byte		N12   , Cs2 , v060
	.byte	W12
	.byte		        Gs1 , v064
	.byte		N22   , Cs3 , v056
	.byte	W01
@ 110   ----------------------------------------
	.byte	W11
	.byte		N12   , Cs2 , v064
	.byte		N12   , An3 , v060
	.byte	W12
	.byte		        An2 , v072
	.byte		N12   , Bn3 , v064
	.byte	W12
	.byte		        Cs2 , v052
	.byte		N12   , Cs4 , v068
	.byte	W12
	.byte		        Bn1 , v064
	.byte		N24   , An3 , v056
	.byte		N56   , Dn4 , v072
	.byte	W12
	.byte		N12   , En2 , v060
	.byte	W12
	.byte		        Dn3 , v080
	.byte		N24   , Gs3 , v052
	.byte	W12
	.byte		N12   , En2 , v056
	.byte	W12
	.byte		        An1 
	.byte		N22   , En3 , v060
	.byte	W01
@ 111   ----------------------------------------
	.byte	W11
	.byte		N12   , En2 , v068
	.byte		N12   , Cs4 , v060
	.byte	W12
	.byte		        An2 , v068
	.byte		N12   , Dn4 , v064
	.byte	W12
	.byte		        Cs3 , v072
	.byte		N12   , En4 , v064
	.byte	W12
	.byte		        Dn2 , v084
	.byte		N96   , Dn4 , v108
	.byte		N96   , Fs4 
	.byte	W12
	.byte		N12   , An2 , v104
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An2 , v088
	.byte	W01
@ 112   ----------------------------------------
	.byte	W11
	.byte		        Dn3 , v104
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		        An3 , v096
	.byte	W12
	.byte		N68   , Fs3 , v060
	.byte	W12
	.byte		N12   , Dn3 , v076
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Bn2 , v084
	.byte	W12
	.byte		        An2 
	.byte	W01
@ 113   ----------------------------------------
	.byte	W11
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte		N12   , Cs4 , v104
	.byte	W12
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v088
	.byte		N72   , Bn3 , v096
	.byte	W12
	.byte		N12   , Bn2 , v088
	.byte	W12
	.byte		        En3 , v100
	.byte	W12
	.byte		        Fs2 , v076
	.byte	W12
	.byte		        En2 , v084
	.byte	W01
@ 114   ----------------------------------------
	.byte	W11
	.byte		        Bn2 , v092
	.byte	W12
	.byte		        En3 , v096
	.byte		N06   , An3 , v084
	.byte	W12
	.byte		N12   , Bn2 
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   , Bn1 , v072
	.byte		N12   , Fs3 , v084
	.byte	W12
	.byte		        Gs2 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte		N06   , En3 , v076
	.byte	W12
	.byte		N12   , En2 
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N12   , An1 , v080
	.byte		N24   , Cs3 
	.byte	W01
@ 115   ----------------------------------------
	.byte	W11
	.byte		N12   , En2 , v092
	.byte	W12
	.byte		        An2 
	.byte		N12   , Dn3 , v096
	.byte	W12
	.byte		        En2 , v080
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		        Dn2 , v084
	.byte		N24   , Fs3 , v100
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn3 , v108
	.byte		N24   , An3 
	.byte	W12
	.byte		N12   , Cs2 , v088
	.byte	W12
	.byte		        Cn2 , v092
	.byte		TIE   , Fs3 , v112
	.byte		TIE   , Gs3 
	.byte	W01
@ 116   ----------------------------------------
	.byte	W11
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Ds3 , v116
	.byte	W12
	.byte		        Gs2 , v088
	.byte	W12
	.byte		        Cn2 , v084
	.byte	W12
	.byte		        Gs2 , v100
	.byte	W12
	.byte		        Ds3 , v104
	.byte	W12
	.byte		        Gs2 , v084
	.byte	W12
	.byte		        Cn2 , v076
	.byte	W01
@ 117   ----------------------------------------
	.byte	W11
	.byte		        Gs2 , v096
	.byte	W12
	.byte		        Ds3 , v100
	.byte	W12
	.byte		        Gs2 , v080
	.byte	W12
	.byte		EOT   , Fs3 
	.byte		        Gs3 
	.byte		N12   , Cs2 
	.byte		N24   , Fs3 , v084
	.byte		N24   , An3 
	.byte	W12
	.byte		N12   , An2 , v096
	.byte	W12
	.byte		        En3 , v104
	.byte		N06   , En4 , v108
	.byte		N06   , Gs4 
	.byte	W12
	.byte		N12   , An2 , v080
	.byte	W12
	.byte		        Cn2 , v076
	.byte		N24   , Fs3 , v068
	.byte		N24   , Gs3 
	.byte	W01
@ 118   ----------------------------------------
	.byte	W11
	.byte		N12   , Gs2 , v088
	.byte	W12
	.byte		        Ds3 , v104
	.byte	W12
	.byte		        Gs2 , v080
	.byte	W12
	.byte		        Bn1 , v072
	.byte		N24   , Dn3 , v076
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   , En2 , v096
	.byte	W12
	.byte		        Gs2 , v116
	.byte		N12   , Ds3 
	.byte		N06   , Cs4 , v112
	.byte		N06   , En4 
	.byte	W12
	.byte		N12   , En2 , v088
	.byte	W12
	.byte		        An1 
	.byte		N24   , Cs3 , v080
	.byte		N24   , En3 
	.byte	W01
@ 119   ----------------------------------------
	.byte	W11
	.byte		N12   , En2 , v100
	.byte	W12
	.byte		        An2 , v104
	.byte	W12
	.byte		        En2 , v096
	.byte	W12
	.byte		        Fs1 , v080
	.byte		N24   , Bn2 , v088
	.byte		N24   , Ds3 
	.byte	W12
	.byte		N12   , Bn1 , v100
	.byte	W12
	.byte		        An2 , v120
	.byte		N06   , An3 , v127
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Bn1 , v100
	.byte	W12
	.byte		        Cs1 , v084
	.byte		TIE   , Gs2 , v096
	.byte		TIE   , Cs3 
	.byte	W01
@ 120   ----------------------------------------
	.byte	W11
	.byte		N12   , Gs1 , v104
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gs1 , v088
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 , v104
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W12
	.byte		        Cs1 
	.byte	W01
@ 121   ----------------------------------------
	.byte	W11
	.byte		        Gs1 , v096
	.byte	W12
	.byte		        Fn2 , v088
	.byte	W12
	.byte		        Gs1 , v076
	.byte	W12
	.byte		EOT   , Gs2 
	.byte		        Cs3 
	.byte		N12   , Cs1 
	.byte		N24   , Gn2 , v080
	.byte		N24   , Bn2 
	.byte	W12
	.byte		N12   , Gs1 , v088
	.byte	W12
	.byte		        En2 , v092
	.byte		N06   , Gn3 , v100
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , Gs1 , v080
	.byte	W12
	.byte		        Cs1 , v072
	.byte		TIE   , Gs2 , v068
	.byte		TIE   , Cs3 
	.byte	W01
@ 122   ----------------------------------------
	.byte	W11
	.byte		N12   , Gs1 , v092
	.byte	W12
	.byte		        Fn2 , v096
	.byte	W12
	.byte		        Gs1 , v076
	.byte	W12
	.byte		        Cs1 , v072
	.byte	W12
	.byte		        Gs1 , v088
	.byte	W12
	.byte		        Fn2 , v096
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W12
	.byte		        Cs1 , v076
	.byte	W01
@ 123   ----------------------------------------
	.byte	W11
	.byte		        Gs1 , v088
	.byte	W12
	.byte		        Fn2 , v092
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W12
	.byte		EOT   , Gs2 
	.byte		        Cs3 
	.byte		N12   , Cs1 , v056
	.byte		N24   , Gn2 , v064
	.byte		N24   , Bn2 
	.byte	W12
	.byte		N12   , Gs1 , v072
	.byte	W12
	.byte		        En2 , v064
	.byte		N06   , Gn3 , v080
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , Gs1 , v060
	.byte	W12
	.byte		        Dn1 , v052
	.byte		N15   , Fs2 , v060
	.byte		N15   , An2 
	.byte	W01
@ 124   ----------------------------------------
	.byte	W11
	.byte		N12   , An1 , v064
	.byte	W04
	.byte		N16   , Fs2 , v060
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W08
	.byte		N16   , Fs2 , v064
	.byte	W04
	.byte		N12   , An1 , v052
	.byte	W12
	.byte		        Dn1 , v056
	.byte		N24   , Fs2 , v060
	.byte	W12
	.byte		N12   , An1 , v056
	.byte	W12
	.byte		        Dn2 , v060
	.byte		N24   , Fs2 , v064
	.byte		N24   , An2 
	.byte	W12
	.byte		N12   , An1 , v056
	.byte	W12
	.byte		        Dn1 , v048
	.byte		N15   , Fs2 , v060
	.byte		N15   , Bn2 
	.byte	W01
@ 125   ----------------------------------------
	.byte	W11
	.byte		N12   , Gs1 
	.byte	W04
	.byte		N16   , Fs2 , v068
	.byte		N16   , Bn2 
	.byte	W08
	.byte		N12   , Dn2 , v064
	.byte	W08
	.byte		N16   , Fs2 
	.byte		N16   , Bn2 
	.byte	W04
	.byte		N12   , Gs1 , v056
	.byte	W12
	.byte		        Dn1 , v052
	.byte		N15   , Fs2 , v064
	.byte		N15   , Bn2 
	.byte	W12
	.byte		N12   , Gs1 , v060
	.byte	W04
	.byte		N16   , Fs2 , v064
	.byte		N16   , Cs3 
	.byte	W08
	.byte		N12   , Dn2 , v060
	.byte	W08
	.byte		N16   , Fs2 
	.byte		N16   , Bn2 
	.byte	W04
	.byte		N12   , Gs1 , v056
	.byte	W12
	.byte		        Dn1 , v048
	.byte		N15   , Fs2 , v064
	.byte		N15   , An2 
	.byte	W01
@ 126   ----------------------------------------
	.byte	W11
	.byte		N12   , An1 , v060
	.byte	W04
	.byte		N16   , Fs2 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W08
	.byte		N16   , Fs2 , v064
	.byte	W04
	.byte		N12   , An1 , v056
	.byte	W12
	.byte		        Dn1 , v048
	.byte		N24   , Fs2 , v068
	.byte	W12
	.byte		N12   , An1 , v060
	.byte	W12
	.byte		        Dn2 
	.byte		N24   , Fs2 , v068
	.byte		N24   , An2 
	.byte	W12
	.byte		N12   , An1 , v060
	.byte	W12
	.byte		        Dn1 , v048
	.byte		N36   , Fs2 , v052
	.byte		N48   , Gs2 
	.byte	W01
@ 127   ----------------------------------------
	.byte	W11
	.byte		N12   , Bn1 , v056
	.byte	W12
	.byte		        Dn2 , v060
	.byte	W12
	.byte		N60   , Fs2 , v068
	.byte	W12
	.byte		N48   , Gs2 , v060
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		N11   , Fs3 , v072
	.byte	W12
	.byte		N12   , Dn1 , v060
	.byte		N15   , Dn3 , v084
	.byte		N15   , Fs3 
	.byte		N15   , An3 
	.byte	W01
@ 128   ----------------------------------------
	.byte	W11
	.byte		N12   , Bn1 , v068
	.byte	W04
	.byte		N16   , Dn3 
	.byte		N16   , Fs3 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte		N16   , Fs3 
	.byte	W04
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        An2 , v064
	.byte		N24   , Dn3 , v068
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   , Fs2 , v060
	.byte	W12
	.byte		        Dn2 , v064
	.byte		N24   , Dn3 , v076
	.byte		N24   , Fs3 
	.byte		N24   , An3 
	.byte	W12
	.byte		N11   , An1 , v056
	.byte	W12
	.byte		N12   , Dn1 , v060
	.byte		N15   , Dn3 , v076
	.byte		N15   , Fs3 
	.byte		N15   , Bn3 
	.byte	W01
@ 129   ----------------------------------------
	.byte	W11
	.byte		N12   , Bn1 , v064
	.byte	W04
	.byte		N16   , Dn3 , v072
	.byte		N16   , Fs3 
	.byte		N16   , Bn3 
	.byte	W08
	.byte		N12   , Dn2 , v068
	.byte	W08
	.byte		N16   , Dn3 , v064
	.byte		N16   , Fs3 
	.byte		N16   , Bn3 
	.byte	W04
	.byte		N12   , Fs2 , v072
	.byte	W12
	.byte		        An2 , v064
	.byte		N15   , Dn3 
	.byte		N15   , Fs3 
	.byte		N15   , Bn3 
	.byte	W12
	.byte		N12   , Fs2 , v060
	.byte	W04
	.byte		N16   , En3 , v076
	.byte		N16   , Fs3 
	.byte		N16   , Cs4 
	.byte	W08
	.byte		N12   , Dn2 , v064
	.byte	W08
	.byte		N16   , Dn3 
	.byte		N16   , Fs3 
	.byte		N16   , Bn3 
	.byte	W04
	.byte		N11   , An1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte		N15   , Dn3 , v068
	.byte		N15   , Fs3 
	.byte		N15   , An3 
	.byte	W01
@ 130   ----------------------------------------
	.byte	W11
	.byte		N12   , Bn1 , v064
	.byte	W04
	.byte		N16   , Dn3 
	.byte		N16   , Fs3 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W08
	.byte		N16   , Dn3 , v068
	.byte		N16   , Fs3 
	.byte	W04
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		        An2 
	.byte		N24   , Dn3 , v072
	.byte		N24   , Fs3 
	.byte	W12
	.byte		N12   , Fs2 , v056
	.byte	W12
	.byte		        Dn2 
	.byte		N24   , Cs3 , v076
	.byte		N24   , Dn3 
	.byte		N24   , Fs3 
	.byte		N24   , An3 
	.byte	W12
	.byte		N11   , An1 , v052
	.byte	W12
	.byte		N12   , En1 , v060
	.byte		N84   , Bn2 , v108
	.byte		N96   , Dn3 
	.byte		N96   , Fs3 
	.byte		N96   , Gs3 
	.byte	W01
@ 131   ----------------------------------------
	.byte	W11
	.byte		N12   , Bn1 , v064
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Gs2 , v068
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W01
@ 132   ----------------------------------------
	.byte	W11
	.byte		N11   , Bn2 , v060
	.byte	W12
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N11   , En3 , v064
	.byte	W12
	.byte		N12   , Fs3 , v088
	.byte	W12
	.byte		        Gs3 , v104
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W12
	.byte		        Dn4 , v108
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W01
@ 133   ----------------------------------------
	.byte	W11
	.byte		        Dn4 , v084
	.byte	W12
	.byte		        Bn3 , v076
	.byte	W12
	.byte		        Fs3 , v064
	.byte	W12
	.byte		N48   , Fs3 , v076
	.byte		N96   , Gs3 
	.byte	W12
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Dn4 , v104
	.byte	W12
	.byte		N11   , En4 , v092
	.byte	W12
	.byte		N12   , Fs4 , v096
	.byte	W01
@ 134   ----------------------------------------
	.byte	W11
	.byte		        Dn4 , v092
	.byte	W12
	.byte		        Bn3 , v080
	.byte	W12
	.byte		        En3 , v060
	.byte	W12
	.byte		N48   , En3 , v076
	.byte		N96   , Gs3 
	.byte	W12
	.byte		N12   , Bn3 , v092
	.byte	W12
	.byte		        Dn4 , v108
	.byte	W12
	.byte		N11   , En4 , v092
	.byte	W12
	.byte		N12   , Fs4 , v068
	.byte	W01
@ 135   ----------------------------------------
	.byte	W11
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 , v052
	.byte	W12
	.byte		        Fs3 , v048
	.byte	W12
	.byte		N48   , Fs3 , v056
	.byte		N96   , Gs3 
	.byte	W12
	.byte		N12   , Bn3 , v064
	.byte	W12
	.byte		        Dn4 , v068
	.byte	W12
	.byte		N11   , En4 , v064
	.byte	W12
	.byte		N12   , Fs4 , v060
	.byte	W01
@ 136   ----------------------------------------
	.byte	W11
	.byte		        Dn4 , v052
	.byte	W12
	.byte		        Bn3 , v056
	.byte	W12
	.byte		        En3 , v044
	.byte	W12
	.byte		N48   , En3 , v056
	.byte		N48   , Gs3 
	.byte	W12
	.byte		N12   , Bn3 , v064
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N11   , En4 
	.byte	W12
	.byte		N12   , Fs4 , v040
	.byte	W01
@ 137   ----------------------------------------
	.byte	W11
	.byte		        Fs2 , v036
	.byte	W12
	.byte		        Cs3 , v048
	.byte		N12   , Fs3 
	.byte		N12   , Cs5 , v052
	.byte	W12
	.byte		N11   , An3 , v044
	.byte	W12
	.byte		N48   , Fs4 , v036
	.byte		N48   , An4 
	.byte		N48   , Cn5 , v044
	.byte	W12
	.byte		N12   , An2 , v036
	.byte	W12
	.byte		        Dn3 , v044
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N11   , Cn4 , v048
	.byte	W12
	.byte		N24   , Cs5 , v040
	.byte	W01
@ 138   ----------------------------------------
	.byte	W11
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte		N24   , Fs4 , v036
	.byte		N24   , An4 
	.byte		N24   , En5 , v040
	.byte	W12
	.byte		N11   , En4 , v048
	.byte	W12
	.byte		N16   , Ds5 , v040
	.byte	W12
	.byte		N12   , Bn2 , v044
	.byte	W04
	.byte		N15   , Fs4 
	.byte		N16   , Bn4 , v036
	.byte	W08
	.byte		N12   , Fs3 , v052
	.byte	W08
	.byte		N15   , An4 , v044
	.byte	W04
	.byte		N11   , Ds4 , v052
	.byte	W12
	.byte		N12   , Fs4 , v036
	.byte	W01
@ 139   ----------------------------------------
	.byte	W11
	.byte		        Fs2 , v040
	.byte	W12
	.byte		        Cs3 , v052
	.byte		N12   , Fs3 
	.byte		N12   , Cs5 , v048
	.byte	W12
	.byte		N11   , An3 
	.byte	W12
	.byte		N48   , Fs4 , v032
	.byte		N48   , An4 
	.byte		N48   , Cn5 , v044
	.byte	W12
	.byte		N12   , An2 , v036
	.byte	W12
	.byte		        Dn3 , v040
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N11   , Cn4 , v048
	.byte	W12
	.byte		N24   , Cs5 , v040
	.byte	W01
@ 140   ----------------------------------------
	.byte	W11
	.byte		N12   , Cs3 , v032
	.byte	W12
	.byte		        Fs3 , v036
	.byte		N24   , Fs4 , v040
	.byte		N24   , An4 
	.byte		N24   , En5 , v048
	.byte	W12
	.byte		N11   , En4 
	.byte	W12
	.byte		N16   , Ds5 , v040
	.byte	W12
	.byte		N12   , Bn2 , v036
	.byte	W04
	.byte		N15   , Fs4 
	.byte		N16   , Bn4 , v040
	.byte	W08
	.byte		N12   , Fs3 , v044
	.byte	W08
	.byte		N15   , An4 , v036
	.byte	W04
	.byte		N11   , Ds4 , v052
	.byte	W12
	.byte		N24   , Cs4 , v032
	.byte	W01
@ 141   ----------------------------------------
	.byte	W11
	.byte		N12   , Cs2 , v040
	.byte	W12
	.byte		        Fs2 , v052
	.byte		N24   , Fs3 , v036
	.byte		N24   , An3 
	.byte		N24   , En4 , v052
	.byte	W12
	.byte		N11   , En3 , v072
	.byte	W12
	.byte		N16   , Ds4 , v060
	.byte	W12
	.byte		N12   , Bn1 , v048
	.byte	W04
	.byte		N15   , Fs3 , v036
	.byte		N16   , Bn3 , v048
	.byte	W08
	.byte		N12   , Fs2 , v052
	.byte	W08
	.byte		N15   , An3 , v044
	.byte	W04
	.byte		N11   , Ds3 , v056
	.byte	W12
	.byte		N12   , An1 , v036
	.byte		N96   , Cs4 , v048
	.byte	W01
@ 142   ----------------------------------------
	.byte	W11
	.byte		N12   , Ds2 , v040
	.byte	W12
	.byte		        Fs2 , v044
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 , v052
	.byte	W12
	.byte		        Ds3 , v056
	.byte	W12
	.byte		        Fs3 , v044
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W01
@ 143   ----------------------------------------
	.byte	W11
	.byte		        Ds4 
	.byte	W12
	.byte		        Fs4 , v044
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cs5 , v040
	.byte	W12
	.byte		        Ds5 , v048
	.byte	W12
	.byte		        Fs5 , v044
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N11   , Gs1 , v040
	.byte		N96   , Bn5 , v048
	.byte		N96   , Cs6 
	.byte	W01
@ 144   ----------------------------------------
	.byte	W11
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Bn2 , v044
	.byte	W12
	.byte		        Cs3 , v056
	.byte		N12   , Fn3 , v040
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 , v044
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W12
	.byte		        Fn4 , v032
	.byte	W01
@ 145   ----------------------------------------
	.byte	W11
	.byte		        Gs4 , v040
	.byte	W12
	.byte		        Bn4 , v048
	.byte	W12
	.byte		N11   , Cs5 
	.byte	W12
	.byte		N12   , Fn5 , v036
	.byte	W12
	.byte		        Gs5 , v048
	.byte	W12
	.byte		        Bn5 , v040
	.byte	W12
	.byte		        Cs6 , v048
	.byte	W12
	.byte		N48   , Fs0 , v020
	.byte		N48   , Cs1 
	.byte		N48   , Fs1 
	.byte		N12   , Cs6 
	.byte		N12   , Fs6 
	.byte	W01
@ 146   ----------------------------------------
	.byte	W11
	.byte		        Fs5 , v016
	.byte	W12
	.byte		        Cs6 , v032
	.byte		N12   , Fs6 
	.byte	W12
	.byte		        Fs5 , v028
	.byte	W12
	.byte		N48   , Cs1 , v016
	.byte		N48   , Fs1 
	.byte		N48   , Cs2 
	.byte		N12   , Fs5 , v024
	.byte		N12   , Cs6 
	.byte	W12
	.byte		        Cs5 , v016
	.byte	W12
	.byte		        Fs5 , v028
	.byte		N12   , Cs6 
	.byte	W12
	.byte		        Cs5 , v020
	.byte	W12
	.byte		N90   , Bn0 
	.byte		N90   , Fs1 
	.byte		N90   , Bn1 
	.byte		N12   , Fs5 , v028
	.byte		N12   , Ds6 
	.byte	W01
@ 147   ----------------------------------------
	.byte	W11
	.byte		        Ds5 , v020
	.byte	W12
	.byte		        Fs5 , v028
	.byte		N12   , Ds6 
	.byte	W12
	.byte		        Ds5 , v020
	.byte	W12
	.byte		        Fs5 , v028
	.byte		N12   , Bn5 
	.byte	W12
	.byte		        Bn4 , v020
	.byte	W12
	.byte		        Fs5 , v032
	.byte		N12   , Bn5 
	.byte	W12
	.byte		N11   , Bn4 
	.byte	W12
	.byte		N48   , Fs0 , v016
	.byte		N48   , Cs1 
	.byte		N48   , Fs1 
	.byte		N12   , Cs5 , v028
	.byte		N12   , Fs5 
	.byte	W01
@ 148   ----------------------------------------
	.byte	W11
	.byte		        Fs4 , v024
	.byte	W12
	.byte		        Cs5 , v028
	.byte		N12   , Fs5 
	.byte	W12
	.byte		        Fs4 , v020
	.byte	W12
	.byte		N48   , Cs1 , v016
	.byte		N48   , Fs1 
	.byte		N48   , Cs2 
	.byte		N12   , Fs4 , v020
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Cs4 , v016
	.byte	W12
	.byte		        Fs4 , v028
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Cs4 , v024
	.byte	W12
	.byte		N90   , Bn0 , v020
	.byte		N90   , Fs1 
	.byte		N90   , Bn1 
	.byte		N12   , Fs4 , v024
	.byte		N12   , Ds5 
	.byte	W01
@ 149   ----------------------------------------
	.byte	W11
	.byte		        Ds4 , v016
	.byte	W12
	.byte		        Fs4 , v024
	.byte		N12   , Ds5 
	.byte	W12
	.byte		        Ds4 , v016
	.byte	W12
	.byte		        Fs4 , v028
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Bn3 , v020
	.byte	W12
	.byte		        Fs4 , v032
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Bn3 , v020
	.byte	W12
	.byte		N48   , Fs0 , v024
	.byte		N48   , Cs1 
	.byte		N48   , Fs1 
	.byte		N12   , Cs4 , v020
	.byte		N12   , Fs4 
	.byte	W01
@ 150   ----------------------------------------
	.byte	W11
	.byte		        Fs3 , v016
	.byte	W12
	.byte		        Cs4 , v024
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Fs3 , v020
	.byte	W12
	.byte		N48   , Cs1 , v024
	.byte		N48   , Fs1 
	.byte		N48   , Cs2 
	.byte		N12   , Fs3 , v028
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Cs3 , v024
	.byte	W12
	.byte		        Fs3 , v028
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Cs3 , v024
	.byte	W12
	.byte		        Bn0 , v020
	.byte		N72   , Ds3 , v028
	.byte		N84   , Fs3 
	.byte		N90   , Ds4 
	.byte	W01
@ 151   ----------------------------------------
	.byte	W11
	.byte		N12   , Fs1 , v024
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Ds2 , v028
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Bn2 , v028
	.byte	W12
	.byte		N19   , Ds3 , v024
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W01
@ 152   ----------------------------------------
	.byte	W11
	.byte		        Ds4 
	.byte	W12
	.byte		        Fs4 , v028
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds4 , v020
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn4 , v024
	.byte	W12
	.byte		        Ds5 , v020
	.byte	W12
	.byte		N11   , Fs0 
	.byte		N11   , Cs1 
	.byte		N11   , Fs1 
	.byte		N12   , Fs5 , v028
	.byte		N12   , Cs6 
	.byte		N12   , Fs6 
	.byte	W01
@ 153   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Fs1 , v020
	.byte		N12   , Cs2 
	.byte		N12   , An2 
	.byte		N12   , Fs3 
	.byte		N12   , Cs4 
	.byte		N12   , Fs4 
	.byte	W01
@ 154   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Fs0 
	.byte		N12   , Fs1 
	.byte		N12   , Fs4 , v024
	.byte		N12   , Fs5 
	.byte	W01
@ 155   ----------------------------------------
	.byte	W11
	.byte GOTO
	.word restart_position

	.byte	FINE

@******************************************************@
	.align	2

bergamasque_4_passepied:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bergamasque_4_passepied_pri	@ Priority
	.byte	bergamasque_4_passepied_rev	@ Reverb.

	.word	bergamasque_4_passepied_grp

	.word	bergamasque_4_passepied_1

	.end
