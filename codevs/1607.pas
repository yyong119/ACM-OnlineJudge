var
    a:array[0..9999] of boolean;
    m,i,n:longint;
begin
    readln(n); fillchar(a,sizeof(a),true);
    for i:=1 to n do
    begin
        readln(m);
        a[m]:=false;
    end;
    for i:=0 to 9999 do
        if a[i] then writeln(i);
end.