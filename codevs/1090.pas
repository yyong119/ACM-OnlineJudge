var i,n,j:longint;
    a:array[0..50] of int64;
    root,f:array[0..50,0..50] of longint;
function dfs(l,r:longint):int64;
var i:longint; t,ans:int64;
begin
    if (f[l,r]<>-1) then exit(f[l,r]);
    ans:=0;
    if (l>r) then exit(1);
    if l=r then exit(a[l]);
    for i:=l to r do
    begin
        t:=dfs(l,i-1)*dfs(i+1,r)+a[i];
        if t>ans then
        begin
            ans := t;
            root[l,r]:=i;
        end;
    end;
    f[l,r]:=ans;
   dfs := ans;
end;
procedure deep(l,r:longint);
var t:longint;
begin
    if (l>r) then exit;
    if l=r then
    begin
        write(l,' ');
        exit;
    end;
    t:=root[l,r];
    write(t,' ');
    deep(l,t-1); deep(t+1,r);
end;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
    for  i :=0 to n do
        for j :=0 to n do f[i,j]:=-1;
    writeln(dfs(1,n));
    deep(1,n);
    writeln;
end.