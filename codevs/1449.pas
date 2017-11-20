var
    a,i:longint; s:int64;
begin
    readln(a);
    s:=1;
    for i:=2 to a do s:=s*i;
    writeln(s);
end.