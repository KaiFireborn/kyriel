#Requires AutoHotkey v2.0
; Kyriel Keyboard AHK Remap
; Source: kyriel_remaps.txt

; ARROWS
RAlt & l:: Send "↑"
RAlt & k:: Send "↓"
RAlt & j:: Send "←"
RAlt & `;:: Send "→"
RAlt & [:: Send "⇐"
RAlt & ]:: Send "⇒"

; UMLAUTS
RAlt & u:: Send "ü"
RAlt & a:: Send "ä"
RAlt & o:: Send "ö"
RAlt & s:: Send "ß"
RAlt & c:: Send "ā"
>!+a::Ä
>!+u::Ü
>!+c::Ā

; NUMBER ROW + ALTGR
RAlt & 1:: Send "↵"
RAlt & 2:: Send "€"
RAlt & 3:: Send "°"
RAlt & 4:: Send "Δ"
RAlt & 5:: Send "∞"
RAlt & 6:: Send "·"
RAlt & 7:: Send "✓"
RAlt & 8:: Send "✕"
RAlt & 9:: Send "μ"
RAlt & 0:: Send "⌀"

; IMPORTANT PUNCTUATION
RAlt & -:: Send "−"
RAlt & =:: Send "≠"
RAlt & ,:: Send "≤"
RAlt & .:: Send "≥"
RAlt & \:: Send "≈"
+\:: Send "±"

; MATH SYMBOLS
RAlt & n:: Send "¬"
RAlt & /:: Send "⇔"
RAlt & ':: Send "∧"
+n:: Send "∨" ; TODO for this find out proper keycode too
RAlt & `:: Send "↯"

; BRIGHTNESS CONTROL
F18:: Send "+!{Up}"
F19:: Send "+!{Down}"

