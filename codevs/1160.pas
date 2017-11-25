var a:array[1..100,1..100] of longint;
i,j,k,n,x,y,tot,sum:longint;
begin
readln(n);
for x:=1 to n do
for y:=1 to n do
a[x,y]:=0;
k :=n; j:=1; tot :=0; x :=1; y:=0;
while tot<n*n do
begin
for i :=tot+1 to tot+k do
begin
y:=y+j;
a[x,y]:=i;
end;
tot :=tot+k;
k :=k-1;
for i:=tot+1 to tot+k do
begin
x:=x+j;
a[x,y]:=i;
end;
j :=-j;
tot :=tot+k;
end;
for x:=n downto 1 do
begin
for y :=n downto 2 do
write(n*n-a[x,y]+1,' '); write(n*n-a[x,1]+1);
writeln;
end;
for i:=1 to n do begin inc(sum,n*n-a[i,i]+1);  inc(sum,n*n-a[i,n-i+1]+1); end;
writeln(sum-1);
end.