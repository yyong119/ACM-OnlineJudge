var
    n,i,j,k,l:longint;
begin
    readln(n);
    for i:=1 to n do
    begin
        for j:=1 to n-i do write(' ');
        write('/');
        for j:=1 to (i-1)*2 do write('_');
        write('\');
        for j:=1 to n-i do write(' ');
        writeln;
    end;
end.