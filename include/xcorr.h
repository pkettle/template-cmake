/**
 % Author: Paul Kettle <paul@pkettle.com>
 % Created: 2016-05-10
 % Copyright (C) 2015 Paul Kettle
 %
 % This program is free software; you can redistribute it and/or modify it
 % under the terms of the GNU General Public License as published by
 % the Free Software Foundation; either version 3 of the License, or
 % (at your option) any later version.
 %
 % This program is distributed in the hope that it will be useful,
 % but WITHOUT ANY WARRANTY; without even the implied warranty of
 % MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 % GNU General Public License for more details.
 %
 % You should have received a copy of the GNU General Public License
 % along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
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
