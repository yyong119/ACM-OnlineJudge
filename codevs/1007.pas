var
    n,i:longint;
    sum:real;
begin
    readln(n);
    repeat
        inc(i);
        sum:=sum+1/i;
    until sum>n;
    writeln(i);
end.