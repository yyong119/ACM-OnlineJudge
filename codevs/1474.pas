var
    n,i,k,s:longint;
    a:array[1..100] of longint;
begin
    readln(n,s);
    while n>0 do
    begin
        inc(i);
        a[i]:=n mod s;
        n:=n div s;
    end;
    k:=i;
    for i:=k downto 1 do
        if a[i]<10 then write(a[i])
        else
        case a[i] of
            10:write('A');
            11:write('B');
            12:write('C');
            13:write('D');
            14:write('E');
            15:write('F');
        end;
end.