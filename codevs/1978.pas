var
    f:array[1..40] of longint;
    i,j:longint;
begin
    readln(j); 
    f[1]:=1; f[2]:=1;
    for i:=3 to j do f[i]:=f[i-1]+f[i-2];
    writeln(f[j]);
end.