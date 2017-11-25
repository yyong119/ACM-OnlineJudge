var
    str:ansistring;
    a:array[1..1000] of string;
    i,k:longint;
begin
    readln(str); k:=1;
    for i:=1 to length(str) do
        if str[i]<>' ' then a[k]:=a[k]+str[i]
            else inc(k);
    for i:=k downto 2 do write(a[i],' '); write(a[1]);
end.