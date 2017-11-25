var
 f:array[-1..40,-1..40,-1..40,-1..40]of longint;
 a:array[1..350]of longint;
 b:array[1..4]of longint;
 n,m,i,j,k,l,o,p:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a)else exit(b);
end;
begin
 readln(n,m);
 for i:=1 to n do read(a[i]);
 for i:=1 to m do begin
  read(j);
  inc(b[j]);
 end;
 for i:=0 to b[1] do
  for j:=0 to b[2] do
   for k:=0 to b[3] do
    for l:=0 to b[4] do begin
     f[i,j,k,l]:=max(f[i-1,j,k,l],f[i,j-1,k,l]);
     f[i,j,k,l]:=max(f[i,j,k,l],f[i,j,k-1,l]);
     f[i,j,k,l]:=max(f[i,j,k,l],f[i,j,k,l-1]);
     f[i,j,k,l]:=a[i+j*2+k*3+l*4+1]+f[i,j,k,l];
    end;
 writeln(f[b[1],b[2],b[3],b[4]]);
end.