# MIPI DCS HAL for HAGL Graphics Library

HAL for HAGL graphics library for display drivers supporting the [MIPI Display Command Set](https://www.mipi.org/specifications/display-command-set). This covers most displays currently used by hobbyists. Tested with ST7735S, ST7789V, ST7789V2 and ILI9341.

[![Software License](https://img.shields.io/badge/license-MIT-brightgreen.svg?style=flat-square)](LICENSE.md)

## Usage

To use with an ESP-IDF project you include this HAL and the [HAGL graphics library](https://github.com/tuupola/hagl) itself.

```
$ cd components
$ git submodule add git@github.com:tuupola/hagl_esp_mipi.git
$ git submodule add git@github.com:tuupola/hagl.git
```

You can alter display behaviour via `menuconfig`. If you choose to use back buffer all drawing operations will be fast. Downside is that back buffer requires lot of memory. To reduce flickering you can also choose to lock back buffer while flushing. Locking will slow down draw operations though.

```
$ make menuconfig
```

[Default configs](https://github.com/tuupola/hagl_esp_mipi/tree/master/sdkconfig/) are provided for popular dev boards. For example to compile for M5Stack do something like the following:

```
$ cp components/hagl_esp_mipi/sdkconfig/m5stack.defaults sdkconfig.defaults
$ make menuconfig
```

For example usage see [ESP GFX](https://github.com/tuupola/esp_gfx), [ESP effects](https://github.com/tuupola/esp_effects) and [Mandelbrot](https://github.com/tuupola/esp-examples/tree/master/014-mandelbrot).

## License

The MIT License (MIT). Please see [License File](LICENSE.txt) for more information.
