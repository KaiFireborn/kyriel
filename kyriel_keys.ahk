#Requires AutoHotkey v2.0

; AltGr + Number row
RAlt & 1:: Send "↵" ; never use this
RAlt & 2:: Send "€"
RAlt & 3:: Send "°"
RAlt & 4:: Send "Δ" ; never use this
RAlt & 5:: Send "∞"
RAlt & 6:: Send "·"
RAlt & 7:: Send "✓" ; never use this
RAlt & 8:: Send "✕" ; never use this
RAlt & 9:: Send "μ" ;  never use this
RAlt & 0:: Send "⌀" ; never use this

; AltGr + Letters
RAlt & u:: Send "ü"
RAlt & n:: Send "¬" ; never use this
RAlt & a:: Send "ä"
RAlt & s:: Send "ß"
RAlt & o:: Send "ö"
RAlt & c:: Send "ā"

; AltGr + Punctuation
RAlt & ,:: Send "≤"
RAlt & .:: Send "≥"
RAlt & l:: Send "↑"
RAlt & k:: Send "↓"
RAlt & j:: Send "←"
RAlt & `;:: Send "→"
RAlt & [:: Send "⇐"
RAlt & ]:: Send "⇒"
RAlt & =:: Send "≠"
RAlt & \:: Send "≈"
RAlt & /:: Send "⇔" ; never use this
RAlt & ':: Send "∧" ; never use this

; Shift combinations
+`:: Send "±"
RAlt & `:: Send "↯" ; never use this
`:: Send "§"
\:: Send "``"
+\:: Send "~"
RAlt & -:: Send "−"

; Brightness key remap # TODO: find the actual ids of those keys on windows
; Brightness_Up:: Send "+!Up"
; Brightness_Down:: Send "+!Down"

