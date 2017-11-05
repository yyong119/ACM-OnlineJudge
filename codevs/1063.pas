var
 i,j,n,m,k,ha,hb,lb,xx,yy,max:longint; 
 a,b:array[0..100000] of longint; 
procedure kp(l,r:longint); 
 var
  i,j,x,t:longint; 
   begin
    i:=l;j:=r;x:=a[(i+j) div 2]; 
    repeat
     while a[i]<x do inc(i); 
     while a[j]>x do dec(j); 
     if i<=j then begin
      t:=a[i];a[i]:=a[j];a[j]:=t; 
      inc(i);dec(j); 
      end; 
    until i>j; 
  if i<r then kp(i,r); 
  if l<j then kp(l,j); 
 end; 
function find(var h,h1:longint):longint; 
 var
  i,j:longint; 
   begin
    i:=h;j:=h1; 
    if (a[h]<b[h1]) then begin
                           find:=a[h]; 
                           inc(h); 
                           exit(a[h-1]); 
                         end; 
           inc(h1); 
           exit(b[h1-1]); 
   end; 
  begin
   read(n); 
  for i:=1 to n+2 do
   a[i]:=maxlongint; 
   for i:=1 to n do
    read(a[i]); 
  for i:=1 to n+2 do
   b[i]:=maxlongint; 
  kp(1,n); 
  ha:=1;hb:=1;lb:=0; 
  for i:=1 to n-1 do
   begin
      xx:=find(ha,hb); 
      yy:=find(ha,hb); 
      max:=max+xx+yy; 
      inc(lb); 
      b[lb]:=xx+yy; 
   end; 
writeln(max); 
end. 