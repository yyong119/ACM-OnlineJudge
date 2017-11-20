var
 n,k,i,j,m:longint;   s:string;
 ss:array[1..100]of longint;
 a,f:array[0..1000,0..1000]of qword;
begin
 readln(n,m);   readln(s);
 for i:=1 to length(s) do ss[i]:=ord(s[i])-48;
 for i:=1 to n do
  begin
   a[i,i]:=ss[i];
   for j:=i+1 to n do
   a[i,j]:=a[i,j-1]*10+ss[j];
  end;
 for i:=1 to n do
   f[i,0]:=a[1,i];
 for i:=2 to n do
  for j:=1 to m do
   for k:=1 to i-1 do
   if f[i,j]<f[k,j-1]*a[k+1,i]then
    f[i,j]:=f[k,j-1]*a[k+1,i];
 writeln(f[n,m])
end.