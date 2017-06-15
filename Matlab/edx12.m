function out = edx12(strmat, x)
if x == 'u'
    out = upper(strmat);
elseif x == 'l'
    out = lower(strmat);
else
    out = strmat;
end
