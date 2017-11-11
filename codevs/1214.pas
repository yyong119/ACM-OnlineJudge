var
  i,j,n,m,k,now,mm:longint;
  a,b,f:array[0..100] of longint;
function max(xx,yy:longint):longint;
begin
  if xx>yy then exit(xx) else exit(yy);
end;
procedure swap(var aa,bb:longint);
var t:longint;
begin
  t:=aa;aa:=bb;bb:=t;
end;
procedure kp(l,r:longint);
var i,j,x,t,xx:longint;
begin
    i:=l;j:=r;x:=a[(i+j)div 2 ];xx:=b[(i+j)div 2 ];
    repeat
     while (a[i]<x)or((a[i]=x)and(b[i]<xx)) do inc(i);
     while (a[j]>x)or((a[j]=x)and(b[j]>xx)) do dec(j);
     if i<=j then begin
      swap(a[i],a[j]);
      swap(b[i],b[j]);
      inc(i);dec(j);
      end;
    until i>j ;
  if i<r then kp(i,r);
  if l<j then kp(l,j);
end;
begin
    read(n);
    for i:=1 to n do
     f[i]:=1;
    for i:=1 to n  do
    begin
        read(a[i],b[i]);
        if a[i]>b[i] then swap(a[i],b[i]);
    end;
    kp(1,n);
    for i:=1 to n do
    begin
      for j:=1 to i-1 do
      begin
        if a[i]>=b[j] then  f[i]:=max(f[i],f[j]+1);

        end;
      mm:=max(f[i],mm);
    end;
    writeln(mm);
end.