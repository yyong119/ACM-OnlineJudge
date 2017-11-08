var
  a:array[1..200,0..72] of longint;
  time,tag,d,left,right:array[1..200] of longint;
  n,i,lrj,t:longint;
procedure init(i1,j1:longint);
var x,y,n1:longint;
begin
  inc(n); read(time[n],tag[n]);
  d[n]:=i1;
  if j1=1 then left[i1]:=n;
  if j1=2 then right[i1]:=n;
  n1:=n;
  if tag[n]=0 then
    begin
      init(n1,1);
      init(n1,2);
    end;
end;
procedure search(i:longint);
var
  j,k:longint;
begin
  if (left[i]=0) and (right[i]=0) then
    begin
      a[i,0]:=0;
      for j:=1 to tag[i] do
        a[i,j]:=5*j+time[i]*2;
    end
  else
    begin
      if left[i]<>0 then search(left[i]);
      if right[i]<>0 then search(right[i]);
      for j:=0 to 72 do
        for k:=0 to 72-j do
          if a[i,j+k]>a[left[i],j]+a[right[i],k]+time[i]*2 then
              a[i,j+k]:=a[left[i],j]+a[right[i],k]+time[i]*2;
    end;
end;

begin
  readln(t); inc(t);
  n:=1; init(1,1);
  for i:=1 to 200 do for lrj:=1 to 72 do a[i,lrj]:=1000;
  search(2);
  i:=72;
  while a[2,i]>=t do
    dec(i);
  writeln(i);
end.