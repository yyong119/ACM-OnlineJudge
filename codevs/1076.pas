var
    n,i:longint;
    a:array[1..100000] of longint;
procedure qsort(l,r:longint);
var i,j,mid,temp:longint;
begin
    i:=l; j:=r; mid:=a[(l+r) div 2];
    repeat
        while a[i]<mid do inc(i);
        while a[j]>mid do dec(j);
        if not(i>j) then
        begin
            temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
            inc(i); dec(j);
        end;
    until i>j;
    if i<r then qsort(i,r);
    if j>l then qsort(l,j);
end;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
    qsort(1,n);
    for i:=1 to n-1 do write(a[i],' '); writeln(a[n]);
end.