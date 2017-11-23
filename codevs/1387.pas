var
n,i,o,p1,p2,p3,p4,p6:longint;
a,b,c:array[1..20,1..20] of char;
begin
readln(n);
for i:=1 to n do
begin
for o:=1 to n do
        read(a[i,o]);
readln;
end;
for i:=1 to n do
begin
for o:=1 to n do
read(b[i,o]);
readln;
end;
for i:=1 to n do
for o:=1 to n do
c[i,o]:=a[i,n+1-o];
for i:=1 to n do
for o:=1 to n do
begin
if a[i,o]<>b[n+1-i,n+1-o] then inc(p2);
if a[i,o]<>b[o,n+1-i] then inc(p1);
if b[i,o]<>a[o,n+1-i] then inc(p3);
if a[i,o]<>b[i,n+1-o] then inc(p4);
if a[i,o]<>b[i,o] then inc(p6);
end;
if p1=0 then writeln('1') else
if p2=0 then writeln('2') else
if p3=0 then writeln('3') else
if p4=0 then writeln('4') else
if p6=0 then writeln('6');
if (p1<>0)and(p2<>0)and(p3<>0)and(p4<>0)and(p6<>0) then
begin
p1:=0;
p2:=0;
p3:=0;
p4:=0;
for i:=1 to n do
for o:=1 to n do
begin
if c[i,o]<>b[n+1-i,n+1-o] then inc(p2);
if c[i,o]<>b[o,n+1-i] then inc(p1);
{if c[i,o]<>a[o,n+1-i] then inc(p3);}
if c[i,o]<>b[i,n+1-o] then inc(p4);
end;
if (p1=0)or(p2=0)or(p4=0) then writeln('5') else writeln('7');
end;
end.