var
    n,p,s:int64; i:longint;
begin
    readln(n,p); s:=n;
    if p=0 then writeln(1) else
    begin
    for i:=1 to p-1 do n:=n*s;
    writeln(n);
    end;
end.