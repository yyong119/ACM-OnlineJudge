var i,j,n,k,l,zg,yg:longint;
    c:array [1..100000,1..3] of longint;
    b:array [1..100000] of longint;
    m:int64;
function find(l:longint):longint;
begin if b[l]<>l then b[l]:=find(b[l]); exit(b[l]); end;
procedure qsort(l,r:longint);
var i,j,mid:longint;
    p:array [1..3] of longint;
begin
    i:=l; j:=r;mid:=c[(i+j) div 2,3];
    repeat
         while c[i,3]<mid do inc(i);
         while c[j,3]>mid do dec(j);
         if i<=j then
         begin
           p:=c[i]; c[i]:=c[j]; c[j]:=p; inc(i); dec(j);
         end;
    until i>j;
    if i<r then qsort(i,r); if j>l then qsort(l,j);
end;
begin
    read(n,m);
    for i:=1 to m do begin inc(k); read(c[k,1],c[k,2],c[k,3]); end;
    qsort(1,k);for i:=1 to n do b[i]:=i;
    m:=0; j:=0; l:=0;
    repeat
      inc(j); zg:=find(c[j,1]); yg:=find(c[j,2]);
      if zg<>yg then
      begin inc(l);  m:=m+c[j,3]; b[zg]:=yg; end;
    until l=n-1;
    writeln(m);
end.