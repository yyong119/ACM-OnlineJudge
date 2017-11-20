var
    a:array[1..12] of longint;
    n,i:longint;
procedure qsort(l,r:longint);
var mid,tmp,i,j:longint;
begin
    mid:=a[(l+r)div 2]; i:=l; j:=r;
    repeat
        while a[i]<mid do inc(i);
        while a[j]>mid do dec(j);
        if not(i>j) then
        begin
            tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if i<r then qsort(i,r);
    if j>l then qsort(l,j);
end;
begin
    readln(n);
    for i:=1 to n do
        readln(a[i]);
    qsort(1,n);
    for i:=1 to n do writeln(a[i]);
end.