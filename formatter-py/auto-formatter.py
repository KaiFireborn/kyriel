from keyboardFormatter import process as format_layout
from layerPreviewGenerator import generate_previews
from keyboardFormatter import get_file_from_parent_dir

delimiter_in_body_before_layout = "const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = "
delimiter_between_layout_and_previews = ";"
KEYMAP_FILE = "../keymap.c"

def create_keymap_backup(head, body, tail):
    content = head + body + tail
    keymap_backup_filename = "_backup.".join(KEYMAP_FILE.rsplit(".", 1))
    with open(get_file_from_parent_dir(keymap_backup_filename), "w+") as outfile:
        outfile.write(content)
    

def process():
    head, body, tail = extract_code_partitions()
    create_keymap_backup(head, body, tail)
    original_layout_code, original_preview_code = get_original_layout_and_preview_code(body)
    reformatted_layout_code, layers_data = reformat_layout_code(original_layout_code)
    layers_preview_code = generate_preview_code(layers_data)
    inject_processed_code(head, reformatted_layout_code, layers_preview_code, tail)
    
    
def get_original_layout_and_preview_code(body):
    original_layout_code, original_preview_code = body.split(delimiter_between_layout_and_previews, 1)
    return original_layout_code, original_preview_code.strip()
    

def extract_code_partitions():
    head = []
    layout = []
    tail = []
    start_flag_reached = False
    end_flag_reached = False
    
        
    with open(get_file_from_parent_dir(KEYMAP_FILE), "r", errors='ignore') as infile:
        lines = infile.readlines()
        for line in lines:
            if "END FORMAT" in line:
                end_flag_reached = True
                
            if not start_flag_reached:
                head.append(line)
            elif start_flag_reached and not end_flag_reached:
                layout.append(line)
            elif start_flag_reached and end_flag_reached:
                tail.append(line)
            else:
                raiseException("Unreachable code reached")
            
            if "START FORMAT" in line:
                start_flag_reached = True
    
    head = "".join(head)
    layout = "".join(layout)
    tail = "".join(tail)
    
    return head, layout, tail
            
    
def reformat_layout_code(original_layout_code):
    prefix, delimiter, layout_object = original_layout_code.partition(delimiter_in_body_before_layout)
    layout_object, data = format_layout(layout_object)
    return prefix + delimiter + layout_object + delimiter_between_layout_and_previews + "\n\n", data

def generate_preview_code(layers_data):
    return generate_previews(layers_data)

def inject_processed_code(head, layout_code, preview_code, tail):
    full_code =  head + layout_code + preview_code + tail
    with open(get_file_from_parent_dir(KEYMAP_FILE), "w+") as outfile:
        outfile.write(full_code)


if __name__ == "__main__":
    print("      Reformatting...")
    process()
    print("      Done.")