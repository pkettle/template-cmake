/**
 * Copyright 2017 Paul Kettle
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef XCORR_INCLUDE
#define XCORR_INCLUDE

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _xcorr_status{
    uint16_t selfmalloc:1;
    uint16_t valid:1;
}xcorr_status;

typedef struct _xcorr_instance {
    uint16_t size;
    xcorr_status status;
    float * buffer;
}xcorr_instance;

xcorr_instance * xcorr_init(xcorr_instance * inst, uint16_t size);
xcorr_instance * xcorr_main(xcorr_instance * inst, float x[], float y[], uint16_t size, uint32_t clk);
void xcorr_free(xcorr_instance * inst);


#endif
