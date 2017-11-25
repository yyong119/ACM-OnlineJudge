var 
    a,b:real;
    c:longint;
begin
    readln(a,b);
    c:=trunc(a*b/10);
    if c mod 10>=5 then writeln(((c div 10)+1)*10)
        else writeln((c div 10)*10);
end.