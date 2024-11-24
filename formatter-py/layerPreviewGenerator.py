import json
import pyperclip
from keyboardFormatter import get_file_from_parent_dir


def read_data():
    with open("formatter-py/layers_data.json", "r") as infile:
        return json.loads(infile.read())


SYMBOL_LOOKUP = {
    "XXXXXXX": " ",
    "_______": " ",
    "QK_LOCK": "l",
    "LCTL": "c",
    "LSFT": "s",
    "LALT": "a",
    "LGUI": "g",
    "RCTL": "c",
    "RSFT": "s",
    "RALT": "a",
    "RGUI": "g",
    "NO": " ",
    "TRNS": " ",
    "ENT": "r",
    "BSPC": "b",
    "SPC": "_",
    "ESC": "e",
    "TAB": "t",
    "CAPS": "P",
    "COMM": ",",
    "DOT": ".",
    "SLSH": "/",
    "QUOT": "'",
    "MUTE": "m",
    "VOLD": "v",
    "VOLU": "v",
    "EXCLM": "!",
    "AT": "@",
    "HASH": "#",
    "DLR": "$",
    "PERC": "%",
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
    "DQUO": '"',
    "TILD": "~",
    "GRV": "`",
    "EQL": "=",
    "BSLS": "\\\\",
    "QUES": "?",
    "MINS": "-",
    "LBRC": "[",
    "RBRC": "]",
    "GT": ">",
    "LT": "<",
    "PAST": "*",
    "PSLS": "/",
    "PMNS": "-",
    "PDOT": ".",
    "PPLS": "+",
    "F1": "f",
    "F2": "f",
    "F3": "f",
    "F4": "f",
    "F5": "f",
    "F6": "f",
    "F7": "f",
    "F8": "f",
    "F9": "f",
    "F10": "f",
    "F11": "f",
    "F12": "f",
    "F13": "f",
    "F14": "f",
    "F15": "f",
    "F16": "f",
    "F17": "f",
    "F18": "f",
    "F19": "f",
    "F20": "f",
    "F21": "f",
    "F22": "f",
    "F23": "f",
    "F24": "f",
    "EUR": "€",
    "DEG": "g",
    "DELT": "d",
    "INF": "f",
    "AUML": "a",
    "MATH_AND": "^",
    "MATH_OR": "v",
    "SUML": "s",
    "YES": "y",
    "NO": "n",
    "ALMEQ": "q",
    "ALMNE": "n",
    "PLSMNS": "n",
    "SECT": "t",
    "ERR": "e",
    "MDOT": "d",
    "MU": "m",
    "UUML": "u",
    "NOT": "n",
    "GTOET": "g",
    "LTOET": "l",
    "LEFTA": "L",
    "RIGHTA": "R",
    "UPA": "U",
    "DOWNA": "D",
    "OUML": "o",
    "EQUIV": "v",
    "HOME": "h",
    "PGUP": "p",
    "PGDN": "p",
    "INS": "i",
    "END": "e",
    "UP": "u",
    "DOWN": "d",
    "LEFT": "l",
    "RIGHT": "r",
    "CW_TOGG": "W",
    "SLEP": "s",
    "EJCT": "j",
    "FIND": "f",
    "SCRSV": "s",
    "S(KC_PSCR)": "s",
    "KC_PSCR": "w",
    "LSA(KC_PSCR)": "a",
    "LGUI(D)": "d",
    "A_TAB": "t",
    "C_ESC": "e",
    "TO(ALPHAS)": "r",
    "MO(COSM)": "c",
    "MO(FN)": "f",
    "MO(NUM)": "n",
    "TG(GI)": "g",
    "MO(LM)": "m",
    "MO(NAV)": "v",
    "MO(SYM)": "s",
    "MO(RM)": "m",
}


def translate_symbol(symbol):
    symbol = symbol.replace("KC_", "").replace("CKC_", "")
    symbol = SYMBOL_LOOKUP.get(symbol, symbol[0])

    return symbol


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


def get_preview_halves(layer):
    layer_preview = {"l": [], "r": []}
    for row in layer:
        left_half, right_half = get_row_halves(row)
        layer_preview["l"].append(left_half)
        layer_preview["r"].append(right_half)
    return layer_preview


def render_top_rows(row, side=""):
    r = " ".join(row)
    if side == "l":
        return r + " " * 4
    else:
        return " " * 4 + r


def render_middle_row(row, side=""):
    r = " ".join(row)
    return r


def render_bottom_row(row, side=""):
    r = " ".join(row)
    if side == "l":
        return " " * 6 + r
    elif side == "r":
        return r + " " * 6


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
    return "\\n".join(rendered_half_rows)


def generate_preview_per_half(layer):
    layer = translate_all_symbols_in_layer(layer)
    layer_preview_halves = get_preview_halves(layer)

    rendered_left_half = render_half(layer_preview_halves["l"], "l")
    rendered_right_half = render_half(layer_preview_halves["r"], "r")

    return (rendered_left_half, rendered_right_half)


def convert_to_code(preview, layer_name):
    r = ""
    half_names = ["l", "r"]
    for i, preview_half in enumerate(preview):
        r += f'char PROGMEM {layer_name.casefold()}_preview_{half_names[i]}[] = "{preview_half}";\n'
    return r


def output_preview(preview):
    pyperclip.copy(preview)
    print("Completed and copied to clipboard.")


def generate_previews(data):
    preview_code_total = ""
    for layer_name in data:
        preview = generate_preview_per_half(data[layer_name])
        print("Rendering", layer_name)
        preview_code_total += convert_to_code(preview, layer_name)

    return preview_code_total


if __name__ == "__main__":
    data = read_data()
    preview = generate_previews(data)
    output_preview(preview)
