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


