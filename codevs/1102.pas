var
    c,v:array[0..100] of longint;
    t,m,i,j,k:longint;
    f:array[0..1000] of longint;
function max(a,b:longint):longint;
begin
    if a>b then exit(a) else exit(b);
end;
begin
    readln(t,m);
    for i:=1 to m do read(c[i],v[i]);
    for i:=1 to m do
        for j:=t downto c[i] do
            f[j]:=max(f[j],f[j-c[i]]+v[i]);
    writeln(f[t]);
end.