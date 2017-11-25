var
    v,n,i,j:longint;
    a:array[0..20000] of boolean;
    w:array[1..30] of longint;
begin
    readln(v); a[0]:=true;
    readln(n);
    for i:=1 to n do readln(w[i]);
    for i:=1 to n do
        for j:=v downto 0 do
        if (j-w[i]>=0)and(a[j]=false) then a[j]:=a[j-w[i]];
    for i:=v downto 0 do if a[i]=true then begin writeln(v-i); break; end;
end.