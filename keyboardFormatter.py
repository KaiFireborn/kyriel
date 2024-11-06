import re
import pprint
import pyperclip
import json

TABULATOR = "\t"
PADDING_SIZE = 1
tabulator_length = 4


def get_row_halves(row):
    half_index = len(row) // 2
    left_half = row[:half_index]
    right_half = row[half_index:]
    return left_half, right_half


def put_tabs_commas_between_keys(part_of_row):
    # return (","+TABULATOR).join(part_of_row)
    result = ""
    for key in part_of_row:
        padding_length = tabulator_length - len(key)
        # print(padding_length, tabulator_length, key, len(key))
        assert padding_length > 0
        key += ","
        key += " " * (padding_length - 1)
        result += key
    return result


def replace_trailing_comma(str):
    return " ".join(str.rsplit(",", 1))


def format_row(row):
    result = ""
    if len(row) == 12:
        result = format_top_row(row)
    elif len(row) == 16:
        result = format_middle_row(row)
    elif len(row) == 10:
        result = format_bottom_row(row)
    return "\t" * 2 + result + "\n"


def format_top_row(row):
    left_half, right_half = get_row_halves(row)
    result = (
        put_tabs_commas_between_keys(left_half)
        + TABULATOR * 5
        + put_tabs_commas_between_keys(right_half)
        + "\n"
    )
    return result


def format_middle_row(row):
    left_half, right_half = get_row_halves(row)
    result = (
        put_tabs_commas_between_keys(left_half)
        + TABULATOR * 1
        + put_tabs_commas_between_keys(right_half)
        + "\n"
    )
    return result


def format_bottom_row(row):
    left_half, right_half = get_row_halves(row)
    result = (
        TABULATOR * 3
        + put_tabs_commas_between_keys(left_half)
        + TABULATOR * 1
        + put_tabs_commas_between_keys(right_half)
        + TABULATOR * 3
    )
    return replace_trailing_comma(result)


def define_tabulator(keys):
    longest_key = max([key for key in keys], key=len)
    new_tabulator_length = len(longest_key) + PADDING_SIZE

    global tabulator_length
    global TABULATOR
    if new_tabulator_length > tabulator_length:

        tabulator_length = new_tabulator_length
        TABULATOR = " " * new_tabulator_length
    # print("Tabulator set to", tabulator_length, "because", longest_key, "is the longest key", "with", len(longest_key), "characters.")


def parse_layer(str_inside_parentheses, layer_name):
    print("  Parsing layer", layer_name)
    keys = str_inside_parentheses.split(",")
    define_tabulator(keys)
    rows = sort_keys(keys)
    return rows


def sort_keys(keys):

    rows = [keys[0:12], keys[12:24], keys[24:40], keys[40:50]]
    return rows


def format_layer(layer):
    formatted_rows = [format_row(row) for row in layer]
    return "".join(formatted_rows)


def build_code_again(formatted_layers, layer_names):
    code = "{\n"
    for i, layer_name in enumerate(layer_names):
        code += (
            "\t"
            + "["
            + layer_name
            + "] = LAYOUT_split_3x6_5(\n"
            + formatted_layers.pop(0)
            + "\n"
            + "\t"
            + ")"
            + ("" if i == len(layer_names) - 1 else ",\n")
            + "\n"
        )
    code += "}"
    return code


def save_layer_data_for_previews(layers, layer_names):
    data_to_save = {}
    for i, layer in enumerate(layers):
        data_to_save[layer_names[i]] = layer
    
    with open("layers_data.json", "w+") as outfile:
        outfile.write(json.dumps(data_to_save))
    



def format(code):
    layer_names = extract_layer_names(code)
    layers = extract_layers(code)
    parsed_layers = [
        parse_layer(layer, layer_names[i]) for i, layer in enumerate(layers)
    ]
    save_layer_data_for_previews(parsed_layers, layer_names)
    formatted_layers = [format_layer(layer) for layer in parsed_layers]
    formatted_code = build_code_again(formatted_layers, layer_names)

    return formatted_code


def remove_whitespace(code):
    return re.sub(r"\s+", "", code)


def extract_layer_names(code):
    return re.findall(r"\[(.*?)\]", code)


def extract_layers(code):
    layers = []
    split_at_layer_def = code.split("LAYOUT_split_3x6_5(")
    split_at_layer_def.pop(0)
    for layer_def_body in split_at_layer_def:
        body_end_index = layer_def_body.rindex(")")
        layer = layer_def_body[:body_end_index]
        layers.append(layer)
    return layers

def process(inp):
    inp = remove_whitespace(inp)
    out = format(inp)
    return out

if __name__ == "__main__":
    print("Getting from clipboard.")
    inp = pyperclip.paste()
    # inp = """{
    # [ALPHAS] = LAYOUT_split_3x6_5(KC_NO, KC_Q, KC_W, KC_F, KC_B, KC_P, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO, KC_TAB, LGUI_T(KC_A), LCTL_T(KC_R), LSFT_T(KC_S), LALT_T(KC_T), KC_G, KC_M, RALT_T(KC_N), RSFT_T(KC_E), RCTL_T(KC_I), RGUI_T(KC_O), KC_DEL, KC_ESC, KC_Z, KC_X, KC_C, KC_D, KC_V, TT(LM), TT(COSM), TT(FN), TT(RM), KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, TT(GI2), KC_NO, TT(NAV), KC_LSFT, TT(SYM), TT(NUM), KC_SPC, KC_BSPC, TT(MOUSE), KC_NO),

    # [NUM] = LAYOUT_split_3x6_5(KC_NO, KC_LPRN, KC_P7, KC_P8, KC_P9, KC_RPRN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PPLS, KC_PAST, KC_P4, KC_P5, KC_P6, KC_TRNS, KC_LNUM, KC_RALT, KC_RSFT, KC_RCTL, KC_RGUI, KC_DEL, KC_PMNS, KC_PSLS, KC_P1, KC_P2, KC_P3, KC_PERC, KC_COMM, KC_DOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_TRNS, KC_PDOT, KC_PEQL, KC_LSFT, KC_TRNS, KC_TRNS, KC_SPC, KC_BSPC, KC_NO, KC_NO),

    # [FN] = LAYOUT_split_3x6_5(KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_F15, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_F11, KC_F4, KC_F5, KC_F6, KC_F14, KC_NO, KC_RALT, KC_RSFT, KC_RCTL, KC_RGUI, KC_DEL, KC_ESC, KC_F10, KC_F1, KC_F2, KC_F3, KC_F13, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_NO, KC_NO, KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_SPC, KC_BSPC, KC_NO, KC_NO),

    # [SYM] = LAYOUT_split_3x6_5(KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PIPE, KC_NO, KC_TAB, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, KC_BSLS, KC_PLUS, KC_LPRN, KC_LBRC, KC_LCBR, KC_LT, KC_DEL, KC_ESC, KC_PLUS, KC_MINS, KC_SLSH, KC_GRV, KC_EQL, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT, KC_ENT, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_TRNS, KC_NO, KC_SPC, KC_BSPC, KC_NO, KC_NO),

    # [NAV] = LAYOUT_split_3x6_5(KC_NO, KC_NO, KC_NO, KC_FIND, KC_NO, KC_NO, KC_CAPS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_TAB, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, KC_PSCR, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL, KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, LGUI(KC_D), KC_NO /*scv*/, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_NO, KC_NO, KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_SPC, KC_BSPC, KC_NO, KC_NO),

    # [COSM] = LAYOUT_split_3x6_5(KC_NO, KC_NO /*§*/, KC_NO /*€*/, KC_NO /*Δ*/, KC_NO /*℃*/, KC_NO /*⌀*/, KC_NO /*↯*/, KC_NO /*↵*/, KC_NO /*ü*/, KC_NO /*✓*/, KC_NO /*✕*/, KC_NO, KC_TAB, KC_NO /*ä*/, KC_NO, KC_NO /*ß*/, KC_NO, KC_NO, KC_NO /*↑*/, KC_NO /*←*/, KC_NO /*⇐*/, KC_NO /*≤*/, KC_NO /*ö*/, KC_DEL, KC_ESC, KC_NO /*±*/, KC_NO, KC_NO, KC_NO /*≈*/, KC_NO /*≠*/, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO /*↓*/, KC_NO /*→*/, KC_NO /*⇒*/, KC_NO /*≥*/, KC_NO, KC_ENT, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_SPC, KC_BSPC, KC_NO, KC_NO),

    # [MOUSE] = LAYOUT_split_3x6_5(KC_NO, KC_BTN4, KC_BTN5, KC_BTN2, KC_BTN1, KC_BTN3, KC_ACL0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, LSA(KC_PSCR), KC_ACL1, KC_RALT, KC_RSFT, KC_RCTL, KC_RGUI, KC_DEL, KC_ESC, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_LSCR, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SPC, KC_BSPC, KC_TRNS, KC_NO),

    # [LM] = LAYOUT_split_3x6_5(KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TAB, KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_SPC, KC_BSPC, KC_TRNS, KC_NO),

    # [RM] = LAYOUT_split_3x6_5(KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_RSFT, KC_RCTL, KC_RGUI, KC_DEL, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_SPC, KC_BSPC, KC_TRNS, KC_NO),

    # [GI] = LAYOUT_split_3x6_5(KC_NO, KC_M, KC_Q, KC_T, KC_E, KC_B, KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_TAB, KC_LSFT, KC_A, KC_W, KC_D, KC_TRNS, KC_TILD, KC_F, KC_BTN1, KC_BTN2, KC_T, KC_DEL, KC_ESC, KC_Y, KC_V, KC_S, KC_X, KC_C, KC_LALT, KC_ENT, KC_NO, KC_NO, KC_SLSH, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ENT, KC_R, KC_Z, MO(FN), KC_SPC, MO(GI2), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    # [GI2] = LAYOUT_split_3x6_5(KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TAB, KC_LCTL, KC_A, KC_W, KC_D, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_ESC, KC_O, KC_J, KC_S, LGUI(KC_D), KC_L, KC_G, KC_U, KC_NO, KC_NO, RGB_TOG, RGB_TOG, RGB_TOG, RGB_TOG, RGB_TOG, KC_ENT, KC_P, KC_GRV, KC_BSLS, KC_SPC, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    # [KB] = LAYOUT_split_3x6_5(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(ALPHAS), KC_NO, KC_NO, RGB_TOG, QK_BOOT, KC_NO, TO(KB), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
    # }"""
    try:
        out = process(inp)
        print("Processed, copying to clipboard")
        pyperclip.copy(out)
    except Exception as e:
        print(
            "Failed - are you sure your clipboard contains valid keymap code? (including {})\n", str(e)
        )
