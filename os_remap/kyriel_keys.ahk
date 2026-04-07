#Requires AutoHotkey v2.0
#SingleInstance

; Kyriel Keyboard AHK Remap

; ARROWS
>!l::↑
>!k::↓
>!j::←
>!;::→
>![::⇐
>!]::⇒

; UMLAUTS
>!u::ü
>!a::ä
>!o::ö
>!s::ß
>!c::ā
>!+a::Ä
>!+u::Ü
>!+o::Ö
>!+c::Ā

; NUMBER ROW + ALTGR
>!1::↵
>!2::€
>!3::°
>!4::Δ
>!5::∞
>!6::·
>!7::✓
>!8::✕
>!9::μ
>!0::⌀

; IMPORTANT PUNCTUATION
>!-::−
>!=::≠
>!,::≤
>!.::≥
>!x::≈
SC056::§
+SC056::±

; LOGIC SYMBOLS
>!n::¬
>!/::⇔
>!'::∧
>!\::∨
>!`::↯

; BRIGHTNESS CONTROL
F18:: Send "+!{Up}"
F19:: Send "+!{Down}"