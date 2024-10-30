import json
import pyperclip


def read_data():
    with open("layers_data.json", "r") as infile:
        return json.loads(infile.read())

SYMBOL_LOOKUP = {
    "QK_LOCK": "🔒",
    "LCTL": "^",
    "LSFT": "⇧",
    "LALT": "⌥",
    "LGUI": "⌘",
    "RCTL": "^",
    "RSFT": "⇧",
    "RALT": "⌥",
    "RGUI": "⌘",
    "NO": " ",
    "TRNS": "_",
    "ENT": "↩",
    "BSPC": "⌫",
    "SPC": "␣",
    "ESC": "⎋",
    "TAB": "⇥",
    "CAPS": "⇪",
    "COMM": ",",
    "DOT": ".",
    "SLSH": "/",
    "QUOT": "\"",
    "MUTE": "🔇",
    "VOLD": "🔉",
    "VOLU": "🔊",
    "EXCLM": "!",
    "AT": "@",
    "HASH": "#",
    "DLR": "$",
    "PERC": "%",
    "CIRC": "^",
    "CIRC": "^",
    "ASTR": "*",
    "AMPR": "&",
    "LPRN": "(",
    "RPRN": ")",
    "UNDS": "_",
    "PLUS": "+",
    "LCBR": "{",
    "RCBR": "}",
    "PIPE": "|",
    "COLN": ":",
    "DQUO": "\"",
    "TILD": "~",
    "GRV": "`",
    "EQL": "=",
    "BSLS": "\\",
    "QUES": "?",
    "GRV": "`",
    "TILD": "~",
    "MINS": "-",
    "LBRC": "[",
    "RBRC": "]",
    "GT": ">",
    "LT": "<",
    "PLUS": "+",
    "PERC": "%",
    "PAST": "*",
    "PSLS": "/",
    "PMNS": "-",
    "PDOT": ".",
    "PPLS": "+",
    "F1": "¹",
    "F2": "²",
    "F3": "³",
    "F4": "⁴",
    "F5": "⁵",
    "F6": "⁶",
    "F7": "⁷",
    "F8": "⁸",
    "F9": "⁹",
    "F10": "¹⁰",
    "F11": "¹¹",
    "F12": "¹²",
    "F13": "¹³",
    "F14": "¹⁴",
    "F15": "¹⁵",
    "F16": "¹⁶",
    "F17": "¹⁷",
    "F18": "¹⁸",
    "F19": "¹⁹",
    "F20": "²⁰",
    "F21": "²¹",
    "F22": "²²",
    "F23": "²³",
    "F24": "²⁴",
    "ENT": "↩",
    "EUR": "€",
    "DEG": "°",
    "DELT": "Δ",
    "INF": "∞",
    "AUML": "ä",
    "MATH_AND": "∧",
    "MATH_OR": "∨",
    "SUML": "ß",
    "YES": "✔",
    "NO": "✘",
    "ALMEQ": "≈",
    "ALMNE": "≠",
    "PLSMNS": "±",
    "SECT": "§",
    "ERR": "↯",
    "MDOT": "·",
    "MU": "μ",
    "UUML": "ü",
    "NOT": "¬",
    "GTOET": "≥",
    "LTOET": "≤",
    "LEFTA": "←",
    "RIGHTA": "→",
    "UPA": "↑",
    "DOWNA": "↓",
    "OUML": "ö",
    "EQUIV": "⇔",
    "HOME": "⌂",
    "PGUP": "⇞",
    "PGDN": "⇟",
    "INS": "⇱",
    "END": "≡",
    "UP": "↑",
    "DOWN": "↓",
    "LEFT": "←",
    "RIGHT": "→",
    "CW_TOGG": "↻",
    "SLEP": "💤",
    "EJCT": "⏏",
    "FIND": "🔍",
    "SCRSV": "💾",
    "S(KC_PSCR)": "📷",
    "KC_PSCR": "📷",
    "LSA(KC_PSCR)": "📷",
    "LGUI(D)": "Ð",
 
}

def translate_symbol(symbol):
    symbol = symbol.replace("KC_", "").replace("CKC_", "")
    symbol = SYMBOL_LOOKUP.get(symbol, symbol)
    
    return symbol[0]

def translate_all_symbols_in_layer(layer):
    for i, row in enumerate(layer):
        for j, column in enumerate(row):
            layer[i][j] = translate_symbol(layer[i][j])
    return layer
            
            
def get_row_halves(row):
    half_index = len(row) // 2
    left_half = row[:half_index]
    right_half = row[half_index:]
    return left_half, right_half


def format_row(row):
    result = ""
    if len(row) == 12:
        result = format_top_row(row)
    elif len(row) == 16:
        result = format_middle_row(row)
    elif len(row) == 10:
        result = format_bottom_row(row)
    return "\t" * 2 + result + "\n"

def get_preview_halves(layer):
    layer_preview = {
        "l": [],
        "r": []
    }
    for row in layer:
        left_half, right_half = get_row_halves(row)
        layer_preview["l"].append(left_half)
        layer_preview["r"].append(right_half)
    return layer_preview

def render_top_rows(row, side=""):
    r = " ".join(row)
    if side == "l":
        return r + " "*4
    else:
        return " "*4 + r

def render_middle_row(row, side=""):
    r = " ".join(row)
    return r

def render_bottom_row(row, side=""):
    r = " ".join(row)
    if side == "l":
        return " "*6 + r
    elif side == "r":
        return r + " "*6

def render_half(half, side):
    rendered_half_rows = []
    for i, row in enumerate(half):
        if i <= 1:
            rendered_half_rows.append(render_top_rows(row, side=side))
        elif i == 2:
            rendered_half_rows.append(render_middle_row(row, side=side))
        elif i == 3:
            rendered_half_rows.append(render_bottom_row(row, side=side))
        else:
            raise Exception("Too many rows", half)
    return "\n".join(rendered_half_rows)
            
    

def generate_preview_per_half(layer):
    layer = translate_all_symbols_in_layer(layer)
    layer_preview_halves = get_preview_halves(layer)
    
    rendered_left_half = render_half(layer_preview_halves["l"], "l")
    rendered_right_half = render_half(layer_preview_halves["r"], "r")
    
    
    return (rendered_left_half, rendered_right_half)

def convert_to_code(preview_str, layer_name):
    return f"char {layer_name.casefold()}_preview = \"f{preview_str}\";\n"

def generate_and_output_previews(data):
    def output_preview(preview):
        print(preview)
    
    preview_code_total = ""
    for layer_name in data:
        preview = generate_preview_per_half(data[layer_name])
        print("Rendering", layer_name)
        preview_code_total += convert_to_code(preview, layer_name)
        
    pyperclip.copy(preview_code_total)
    print("Completed and copied to clipboard.")

if __name__ == "__main__":
    data = read_data()
    generate_and_output_previews(data)