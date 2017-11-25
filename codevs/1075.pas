var
    n,i,t:longint;
    a,b:array[1..1000] of longint;
begin
    readln(n);
    for i:=1 to n do
    begin
        read(t);
        inc(a[t]);
    end;
    t:=0;
    for i:=1 to 1000 do
        if a[i]>0 then begin inc(t); b[t]:=i; end;
    writeln(t);
    for i:=1 to t-1 do write(b[i],' ');
    writeln(b[t]);
end.