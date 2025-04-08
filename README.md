# HUDColor

## Change Sven Co-op HUD color

![TitleIMG](https://github.com/DrAbcrealone/HUDColor/blob/main/img/IMG-1.png)

# Install

1. Download and install [MetaHookSv](https://github.com/hzqst/MetaHookSv).

2. Build or download .dll, put it into `svencoop/metahook/plugins` directory.

3. Add `HUDColor.dll` in `svencoop/metahook/configs/plugins.lst` as a newline.

4. Enjoy.

# New CVar
|CVar|Value|Comment|
|---|---|---|
|hud_color_r|0~255|change main color of HUD|
|hud_color_g|0~255|change main color of HUD|
|hud_color_b|0~255|change main color of HUD|
|hud_color_pain_r|0~255|change dying color of HUD|
|hud_color_pain_g|0~255|change dying color of HUD|
|hud_color_pain_b|0~255|change dying color of HUD|
|hud_color_dizzy|0/1/2|0 Disable dizzy effect, 1 RGB disappear effect, 2 Rainbow cycle effect|
|hud_color_dizzy_time|0~9999999|time of dizzy disappearance|

# Build

1. `git --recursive https://github.com/hzqst/HUDColor`

2. Open `.sln` with visual studio.

3. Build.
