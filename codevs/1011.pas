var
    f:array[1..100] of longint;
    n:longint;
function find(k:longint):longint;
var i:longint;
begin
    find:=0;
    for i:=1 to k div 2 do
        if f[i]<>0 then inc(find,f[i])
        else begin f[i]:=find(i)+1; inc(find,f[i]); end;
end;
begin
    readln(n);
    f[1]:=1; f[2]:=2;
    writeln(find(n)+1);
end.