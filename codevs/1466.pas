var
    n:longint;
begin
    readln(n);
    if (n mod 4=0)and(n mod 100<>0)or(n mod 400=0) then writeln(366)
    else writeln(365);
end.