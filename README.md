# WU Algorithm
###### made by tmaluh __(\_ipal)__

Testing Xiaolin Wu's line algorithm on C using SDL2.

![screenshot](https://github.com/Iipal/WU_Algorithm/blob/master/screenshot.png)

Randomatic start and end line positions on each `./wu_algo` starts. If you wants to change randomatic lines counter - change this define:[MAX_LINES](https://github.com/Iipal/WU_Algorithm/blob/ab396293a42375948b3b7655b0100b47e00d87ab/includes/wu_algo_structs.h#L16) and type `make re` for re-compile all project and for correct work with new constant value.

## Requirements pre-installations:

__Fedora:__

```bash
$> sudo dnf install SDL2-devel-2.0.9-3.fc30.x86_64
```

__MacOS:__

```bash
$> brew install sdl2
```

## Compiling

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

When you have already installed SDL2 library you can use this simple rules:
- **make**: Compile all. (On Fedora can require password if SDL2 libraries not installed)
- **make clean**: Delete all ./wu_algo temporary(`*.o`) files.
- **make del**: In this project equals to **make fclean**.
- **make fclean**: Expands `make clean` to delete also executable ./wu_algo.
- **make re**: It's rules - **make fclean** & **make** in one.
- **make pre**: It's rules - **make del** & **make** in one.
- **make debug**: Re-compile ./wu_algo without optimization flags but with `-g3` for debug.

## Keybinds:

| Description                  | Key            |
| ---------------------------- | -------------- |
| Re-random all line positions | <kbd>R</kbd>   |
| Exit.                        | <kbd>ESC</kbd> |

## Flags:

| Flag            | Description                                       | Shortcut | Default value                                                                                                                          | Param type                                                  |
| --------------- | ------------------------------------------------- | -------- | -------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------- |
| --maxLineLength | Set max random line length.                       | -mll     | equals to [WIN_X](https://github.com/Iipal/WU_Algorithm/blob/bcbaa30b6ce8457508e0c923e22c800e99c02556/includes/wu_algo_macroses.h#L18) | Unsigned integer. (Min: 100; Max: equals to Default Value;) |
| --linesCounter  | Set how much lines radnomize, calculate and draw. | -lc      | 10                                                                                                                                     | Unsigned Integer. (Min: 1; Max: 100000)                     |
