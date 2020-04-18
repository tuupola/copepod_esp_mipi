/*

MIT License

Copyright (c) 2019-2020 Mika Tuupola

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-cut-

This file is part of the MIPI DCS HAL for Copepod graphics library:
https://github.com/tuupola/copepod_esp_mipi/

SPDX-License-Identifier: MIT

*/

#ifndef _COPEPOD_HAL_H
#define _COPEPOD_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <bitmap.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define DISPLAY_WIDTH       (CONFIG_MIPI_DISPLAY_WIDTH)
#define DISPLAY_HEIGHT      (CONFIG_MIPI_DISPLAY_HEIGHT)
#define DISPLAY_DEPTH       (16)

#define POD_HAS_HAL_BLIT
#define POD_HAS_HAL_SCALE_BLIT
#define POD_HAS_HAL_HLINE
#define POD_HAS_HAL_VLINE
#define POD_HAS_HAL_INIT
#define POD_HAS_HAL_FLUSH

bitmap_t *pod_hal_init(void);
void pod_hal_flush();
void pod_hal_put_pixel(int16_t x0, int16_t y0, uint16_t color);
void pod_hal_blit(uint16_t x0, uint16_t y0, bitmap_t *src);
void pod_hal_scale_blit(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, bitmap_t *src);
void pod_hal_hline(int16_t x0, int16_t y0, uint16_t w, uint16_t color);
void pod_hal_vline(int16_t x0, int16_t y0, uint16_t h, uint16_t color);

#ifdef __cplusplus
}
#endif
#endif /* _COPEPOD_HAL_H */