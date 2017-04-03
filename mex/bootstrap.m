function mexbuild(varargin)

here=pwd;
root=which('bootstrap');
switch(computer)
    case {'MACI64','GLNXA64','x86_64-apple-darwin14.5.0'}    
    root=root(1:findstr(root,'/mex')+3);
    case {'PCWIN64'}    
    root=root(1:findstr(root,'\mex')+3);
end    
cleanup = onCleanup(@() cd(here));
cd(root);

if isempty(varargin)
    cmd = 'all';
else
    cmd = varargin{1};
end

setenv('TEMPLATE_ROOT','../build_generic/lib');

if ~exist('xcorr_mex','file') || strcmp(cmd,'all') || strcmp(cmd,'xcorr_mex')
    mex -outdir . -O CFLAGS="\$CFLAGS -std=c99" -DMEX -I"../include/" ...
        -L$TEMPLATE_ROOT -ltoolbox.a ..., 
        xcorr_mex.cxx
end

