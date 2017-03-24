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



#include "mex.h"

extern "C" {
#include "../include/xcorr.h"
}

/* The gateway routine. */
void mexFunction( int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[] )
{
    
    uint16_t n,m;
    uint32_t clk;
    
    /* check for the proper number of arguments */
    if(nrhs != 3)
    mexErrMsgTxt("Usage:[z] = xcorr_mex(x, y, clk);\n");
    if(nlhs > 1)
    mexErrMsgTxt("Too many output arguments.");
    
    /* get the length input vector */
    n = mxGetN(prhs[0]);
    m = mxGetM(prhs[0]);
    
    /* get pointers to the real and imaginary parts of the inputs */
    float * x = (float *) mxGetPr(prhs[0]);
    float * y = (float *) mxGetPr(prhs[1]);
    clk = (uint32_t) mxGetScalar(prhs[2]);
        
    /* create a new arrays and set the output pointer to it */
    
    plhs[0] = mxCreateNumericMatrix(m, n, mxSINGLE_CLASS, mxREAL);
    float * z = (float *) mxGetPr(plhs[0]);
    
    xcorr_instance * inst = xcorr_init(NULL, n);
    xcorr_main(inst, x, y, n, clk);
    for (int i=0; i < n ; i++)
        z[i]=inst->buffer[i];
    xcorr_free(inst);
    
    return;
}


