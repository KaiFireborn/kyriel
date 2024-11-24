Use-case: programming, writing, light gaming.


### ALPHAS
I chose Colemak-DH for the base layer (was a *great* idea to learn both a new layout and a radically different keyboard at once), but any other layout would do too.
Because I use them much more often than `<>`, I made `shift+,` and `shift+.` output `;` and `;` instead.

### MODIFIERS
Since I found homerow mods uncomfortable at high typing speeds, homerowmodless layouts like Callum inspired the following contract:

> "The homerow keys on the same hand as the thumb key that triggers the current layer must contain the modifiers"

This includes my LM and RM layers, which are transparent and only contain the respective modifiers to enable using mods with the ALPHAS layer or individually (e.g IntelliJ search)

All further layers follow this philosophy.

The order:
GCSA - ASCG

GUI is on the weakest finger, while Alt is between Ctrl and Shift to make modifier combinations like Shift+Alt, Ctrl+Shift and Ctrl+Shift+Alt as easy as possible. Ctrl and Alt could be swapped, but I use Ctrl more often and wish to take pressure off my index/mouse fingers.

### THUMB-/SIDEKEYS

### NUM
Numpad-like layout with some extra operators (also on the same keys on SYM).

### FN

Straight-forward. The f-numbers mirror on the same keys as the respective numbers on the NUM layer. 

### SYM

The paired symbols like ({[< are on the homerow and below sorted by frequency of use, inspired by the Seniply layout. The top row intentionally resembles the traditional shifted number row, and symbols that appear on the NUM layer are on the same keys for easier mapping. Shifted symbols have their own keys so you don't have to hold down both that and the layer key.

### COSM

Mostly keys combined with AltGr to send unicode symbols like äöüß or ↯↵€°Δ∞·✓✕μ⌀¬ ≠⇐⇒≈∧∨≤≥⇔←↓↑→. This could be implemented with a custom language layout (e.g with Microsoft Layout Creator) or with an AHK script. I decided against the hardware send unicode functionality for ease of change.

### NAV
Perhaps the most interesting layer.
Partly inspired by modal editors like vim or emacs. However, I shifted the arrows by one to the right to get rid of that extra hand movement, as well as reshuffled the directions accordingly. This, once again, helps relieve pressure off my mouse fingers.

Also includes Home/End/PgUp/PgDn etc.

### GAME (GI/ GI2)
The central idea is to implement `wasd` with `eq`, `space` and `1234`. However, one a row-staggered keyboard, you can easily press `2` and `3` with your ring and index fingers while holding down `w` - which is not possible on an ortholinear keyboard. That's why there's an empty (or secondary function) key right above `w` and thus between `2` and `3`. Additionally, I 'angled' `1` to the left for quicker reach.

All other keys and the secondary layer can be adapted to whatever games one plays especially often without rebinding the keys internally.

### MOUSE
Self-explanatory.

# Acknowledgements
Miryoku - https://github.com/manna-harbour/miryoku/tree/master/docs/reference
Seniply - https://stevep99.github.io/seniply/
Callum - https://github.com/manna-harbour/miryoku/tree/master/docs/reference
SplitKB Kyria (Discord, too)
QMK (Discord, too)