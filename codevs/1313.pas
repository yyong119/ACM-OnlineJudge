var n:int64; i:longint;
begin
    readln(n);
    for i:=2 to trunc(sqrt(n)) do
        if n mod i=0 then break;
    writeln(n div i);
end.