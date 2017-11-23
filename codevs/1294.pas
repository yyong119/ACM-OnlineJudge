var
    a:array[1..10] of longint;
    b:array[1..10] of boolean;
    n:longint;
procedure search(depth:longint);
var i:longint;
begin
    if depth=n+1 then
    begin
        for i:=1 to n-1 do write(a[i],' ');
        writeln(a[n]); exit;
    end;
    for i:=1 to n do
        if b[i]=false then
        begin
            b[i]:=true; a[depth]:=i;
            search(depth+1);
            b[i]:=false;
        end;
end;
begin
    readln(n);
    search(1);
end.