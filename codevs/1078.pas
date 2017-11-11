var
  i,j,k,m,n,s,t,min,ans:longint;
  a:array[1..100,1..100] of longint;
  d:array[1..100] of longint;
  p:array[1..100] of boolean;
begin
    readln(n);
  for i:=1 to n do
   for j:=1 to n do
    read(a[i,j]);
  fillchar(p,sizeof(p),true);
  p[1]:=false;
  for i:=1 to n do d[i]:=a[1,i];
  for i:=1 to n-1 do
   begin
     min:=maxlongint;
     for j:=1 to n do
      if i<>j then
       if p[j] and (min>d[j]) then
        begin
          min:=d[j];
          s:=j;
        end;
     p[s]:=false;
 
     for j:=1 to n do if (p[j])and(d[j]>a[s,j]) then d[j]:=a[s,j];
   end;
  ans:=0;
  for i:=1 to n do ans:=ans+d[i];
  writeln(ans);
end.