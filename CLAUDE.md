# CLAUDE.md — ESP32 Starter Kit Documentation

## Project Overview

This is the documentation for the SunFounder ESP32 Starter Kit, built with **Sphinx** using **reStructuredText (.rst)** and the **Read the Docs** theme.

- **Repository**: `sunfounder/esp32-starter-kit`
- **Published docs**: `https://docs.sunfounder.com/projects/esp32-starter-kit/`

## Branch Structure

| Branch | Language | Description |
|--------|----------|-------------|
| `main` | — | Default branch (minimal content) |
| `docs` | English (EN) | Primary documentation branch |
| `docs-de` | German (DE) | German translation of docs |

The `docs-de` branch is a **German translation** of the `docs` branch. Most files exist in both branches with identical structure — the content differs only in language.

## Battery → Power Pack Terminology

When referring to the **SunFounder rechargeable Power Pack product**, always use `Power Pack` — not `battery`, `Akku`, `Batterie`, or `3.7V 18650 battery`.

- **Keep** `battery`/`Batterie` for generic terms (e.g., "battery-operated", "batteriebetriebene"), IR remote battery, and image filenames.
- In German: use `Power Pack` (capitalized, masculine: *der Power Pack*, *des Power Packs*, *den Power Pack*).

**Files affected by the Power Pack terminology** (17 total — 12 text + 5 images):

Text files:
- `docs/source/arduino/basic_projects/ar_motor.rst`
- `docs/source/arduino/basic_projects/ar_plant_monitor.rst`
- `docs/source/arduino/basic_projects/ar_pump.rst`
- `docs/source/arduino/iot_projects/ar_iot_html_cam_led.rst`
- `docs/source/arduino_video_course/video_25_thermistor.rst`
- `docs/source/arduino_video_course/video_54_html_neopixel.rst`
- `docs/source/components/component_esp32_extension.rst`
- `docs/source/components/component_motor.rst`
- `docs/source/micropython/basic_projects/py_motor.rst`
- `docs/source/micropython/basic_projects/py_plant_monitor.rst`
- `docs/source/micropython/basic_projects/py_pump.rst`
- `docs/source/scratch/19_protect_heart.rst`

Image files:
- `docs/source/components/img/components_list.jpg`
- `docs/source/img/wiring/4.1_motor_l293d_bb.png`
- `docs/source/img/wiring/4.2_pump_l293d_bb.png`
- `docs/source/img/wiring/6.8_plant_monitor_l293d_bb.png`
- `docs/source/scratch/img/circuit/10_rotaing_fan_bb.png`

In `component_esp32_extension.rst`, the "Battery Power and Charging" / "Batteriebetrieb und Aufladen" section is **commented out** (using `.. ` prefix) — replaced by references to the Power Pack product page.

## Syncing Between Branches

When making changes to `docs` that should also apply to `docs-de`:

1. **Images**: Checkout directly from docs branch:
   ```bash
   git checkout refs/heads/docs -- <image-path>
   ```
2. **Text**: Translate the changes into German and edit manually. Key German translations:
   - `battery` → `Power Pack` (same term used in German)
   - `battery supply` → `Stromversorgung`
   - `Battery Port` → `Power Pack Port`
   - `insert the battery` → `den Power Pack einzusetzen`

## Documentation Structure

```
docs/source/
├── arduino/                  # Arduino tutorials
│   ├── arduino_start/        # Getting started with Arduino IDE
│   ├── basic_projects/       # Basic component projects
│   ├── iot_projects/         # IoT projects (Blynk, MQTT, etc.)
│   └── for_arduino_user.rst
├── micropython/              # MicroPython tutorials
│   ├── python_start/         # Getting started with MicroPython
│   ├── basic_projects/       # Basic component projects
│   └── for_micropython_user.rst
├── scratch/                  # Scratch/PictoBlox tutorials
│   ├── pictoblox_start/      # Getting started with PictoBlox
│   └── 1_table_lamp.rst ...  # 20 Scratch projects
├── arduino_video_course/     # 55 video tutorials
├── components/               # Component reference docs
├── faq/                      # Troubleshooting & FAQ
├── img/wiring/               # Wiring diagrams
├── conf.py                   # Sphinx configuration
├── index.rst                 # Home page
└── download_code.rst         # Code download instructions
```

## Key Conventions

- **Sphinx config**: `docs/source/conf.py` — includes `sphinx_copybutton` extension and multi-language links
- **Language switching**: `docs/source/_static/lang.js`
- **Image references**: Use relative paths (`../../img/...` or `../img/...`)
- **Code blocks**: Use `.. code-block:: arduino` or `.. code-block:: python`
- **Notes**: Use `.. note::` directive for callouts
