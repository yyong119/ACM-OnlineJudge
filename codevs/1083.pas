var 
    n,i,k,l,s:longint;
    p:array[1..2] of longint;
begin
    readln(n); l:=n;
    while l>0 do
    begin
        inc(k);
        dec(l,k);
    end;
    for i:=1 to k-1 do inc(s,i);
    s:=n-s;
    if k mod 2=0 then begin p[1]:=0; p[2]:=k+1; inc(p[1],s); dec(p[2],s); end
        else begin p[1]:=k+1; p[2]:=0; inc(p[2],s); dec(p[1],s); end;
    writeln(p[1],'/',p[2]);
end.
    