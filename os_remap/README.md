# OS Remap Generator

`kyriel_remaps.txt` is the source of truth.

## Generate derived files

```bash
python3 /home/kf/Files/Programming/kyriel/os_remap/generate_remaps.py
```

This rewrites:

- `kyriel_keys.ahk`
- `kyriel_keys.conf`

## Notes

- Keep mapping lines in source as `Left -> Right`.
- Supported left-side forms:
  - `AltGr + KEY`
  - `Shift + KEY`
  - `KEY (no modifier)`
- Brightness section is kept as commented TODO stubs in generated outputs.
