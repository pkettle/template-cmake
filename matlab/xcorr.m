% Author: Paul Kettle <paul@pkettle.com>
% Created: 2016-07-27
% Copyright (C) 2016 Paul Kettle
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


function [z] = xcorr(x,y)    

%% Demo mode   
%
global itter;
    
if nargin==0
    T=1/128;
    t=0:T:10; 
    
    x = sin(t*2*pi);
    y = sin(t*2*pi);
      
    this = str2func(mfilename());
    if nargout == 0
        this(x,y);
    else
        [x] = this(x,y);
    end   
else    

%% Entry point
%
    
    if  exist('xcorr_mex','file')
        fprintf('%s:Using mex implementation. ',mfilename);
        tic
        [z] = xcorr_mex(single(x), single(y), 0);
        toc
    else    
        error('%s:Mex implementation not found. ',mfilename);
    end 
    
if nargout==0
    figure(1)
    ax=[];
    ax(end+1) = subplot(311); plot(x);title('$x$','Interpreter','latex');
    ax(end+1) = subplot(312); plot(y);title('$y$','Interpreter','latex');
    ax(end+1) = subplot(313); plot(z);title('$z$','Interpreter','latex');

    if exist('OCTAVE_VERSION', 'builtin') == 0 
	  linkaxes(ax,'x');
    end    
end

end
