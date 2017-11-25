var
    n,i,j,k:longint;
begin
    readln(n);
    if n=1 then k:=-1
    else
        for i:=2 to trunc(sqrt(n)) do
            if n mod i=0 then k:=-1;
    if k=-1 then writeln('\n') else writeln('\t');
end.