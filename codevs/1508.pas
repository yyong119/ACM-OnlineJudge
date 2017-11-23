var s1,s2:string;
    i,k1,k2:longint;
begin
readln(s1);
readln(s2);
k1:=1;k2:=1;
for i:=1 to length(s1) do
  k1:=(k1*(ord(s1[i])-ord('A')+1)) mod 47;
for i:=1 to length(s2) do
  k2:=(k2*(ord(s2[i])-ord('A')+1)) mod 47;
if k1=k2 then
  writeln('GO')
else
  writeln('STAY');
end.