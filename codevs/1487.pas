var
    a:array[1..10] of int64;
    i,n,aa:longint;
begin
    readln(n);
    for i:=1 to n do
    begin
        readln(aa);
        inc(a[aa]);
    end;
    for i:=1 to 10 do
        for aa:=1 to a[i] do writeln(i);
end.