var 
a:array[0..100,0..100] of longint; 
n,i,j,k,l,q,x,y:longint;
begin 
readln(n); 
for i:=1 to n do 
begin 
for j:=1 to n do 
begin 
read(a[i,j]); 
if a[i,j]=0 then a[i,j]:=maxlongint; 
end; 
readln; 
end; 
for k:=1 to n do
for i:=1 to n do 
for j:=1 to n do   
if (k<>i)and(k<>j)and(i<>j)and(a[i,j]>a[i,k]+a[k,j]) then a[i,j]:=a[i,k]+a[k,j]; 
readln(q); 
for i:=1 to q do 
begin 
readln(x,y); 
if a[x,y]=maxlongint then writeln(0) else 
writeln(a[x,y]); 
end;
end.