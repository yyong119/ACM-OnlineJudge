const
maxn=10000;
var
a,opt:array[0..maxn] of longint;
n,anslen,anstime:longint;
procedure init;
var
x:longint;
begin
n:=0;
repeat
   inc(n);
   read(a[n]);
until seekeof;
end;
procedure main;
var
i,j:longint;
begin
fillchar(opt,sizeof(opt),0);
a[0]:=maxlongint;
for i:=1 to n do
   for j:=i-1 downto 0 do
    if (a[j]>=a[i]) and (opt[j]+1>opt[i]) then
     opt[i]:=opt[j]+1;
anslen:=0;
for i:=1 to n do
   if opt[i]>anslen then
    anslen:=opt[i];
fillchar(opt,sizeof(opt),0);
a[0]:=-maxlongint;
for i:=1 to n do
   for j:=i-1 downto 0 do
    if (a[j]<a[i]) and (opt[j]+1>opt[i]) then
     opt[i]:=opt[j]+1;
anstime:=0;
for i:=1 to n do
   if opt[i]>anstime then
    anstime:=opt[i];
end;
procedure print;
begin
writeln(anslen);
writeln(anstime);
end;
begin
init;
main;
print;
end.