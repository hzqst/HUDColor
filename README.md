# HUDColor

## Change Sven Co-op HUD color

![TitleIMG](https://github.com/DrAbcrealone/HUDColor/blob/main/img/IMG-1.png)

# Install

1. Download and install [MetaHookSv](https://github.com/hzqst/MetaHookSv).

2. Build or download .dll, put it into `/SteamLibrary/steamapps/common/Sven Co-op/svencoop/metahook/plugins` directory.

3. Add `HUDColor.dll` in `/SteamLibrary/steamapps/common/Sven Co-op/svencoop/metahook/configs/plugins.lst` as a newline.

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

Requirements: Windows, Visual Studio 2022, CMake 3.21 or newer. The first configure downloads VC-LTL 5.3.1 into `thirdparty/cache`.

1. Run `scripts\build-HUDColor-x86-Release.bat` (or `scripts\build-HUDColor-x86-Debug.bat`).

2. The plugin and its PDB are installed to `install\x86\<Configuration>\svencoop\metahook\plugins`.

3. Copy `HUDColor.dll` into `svencoop/metahook/plugins`, as described in Install.

The MetaHook SDK is fetched automatically at a pinned commit. To build against a local MetaHook source tree instead, pass it on the command line or export the same environment variable before configuring:

```
scripts\build-HUDColor-x86-Release.bat -DMETAHOOK_SOURCE_PATH=D:\MetaHook
```

The path is the repository root that provides `include/metahook.h`, `include/HLSDK`, `include/Interface` and `include/SourceSDK`.
