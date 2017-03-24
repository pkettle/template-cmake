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

#include "xcorr.h"

xcorr_instance * xcorr_init(xcorr_instance * inst, uint16_t size){
    
    if (inst == (xcorr_instance *) NULL){
        inst = (xcorr_instance *) malloc(sizeof(xcorr_instance));
        memset(inst, 0, sizeof(xcorr_instance));
        assert(inst);
        inst->status.selfmalloc = 1;
    }
    
    if (inst->buffer ==  (float  *) NULL){
        inst->buffer = (float  *) malloc(sizeof(float) * size);
        assert(inst->buffer);
        memset(inst->buffer, 0, sizeof(float) * size);
    }
    
    inst->size = size;
    
    return inst;
}

void xcorr_free(xcorr_instance * inst){
    assert(inst);
    assert(inst->buffer);
    
    free(inst->buffer);
    
    if(inst->status.selfmalloc)
        free(inst);

}

/* corr of vector x & y, normalized to 1. */
/* x[] & y[] is a circular buffer with current index pointer of clk */
xcorr_instance * xcorr_main(xcorr_instance * inst, float x[], float y[], uint16_t size, uint32_t clk ){

    float ac0=0;
	uint16_t m, n;
    
    //assert(size > inst->size);
    
	uint16_t i0 = (clk + size)%size; // first index

    memset(inst->buffer, 0, sizeof(float) * inst->size);
    
	for ( n = 0; n < size; n++ ){
		ac0 += x[(n+i0+1)%size]*y[(n+i0+1)%size];
  	}

	for ( m = 1; m < inst->size; m++ ){
		for ( n = 0; n < inst->size - m; n++ )
			inst->buffer[(m-1)%inst->size] += x[(n+m+i0+1)%size]*y[(n+i0+1)%size];
		inst->buffer[(m-1)%inst->size] /= ac0;
	}

    return inst;
}


