var time:array [1..1000000] of boolean;
    n,a,b,mina,maxb,i,j,a1,a2,t1,t2:longint;
begin
 fillchar(time,sizeof(time),false); mina:=1000001;
 readln(n);
 for i:=1 to n do
  begin
   readln(a,b);
    if a<mina then mina:=a;
    if b>maxb then maxb:=b;
   for j:=a+1 to b do time[j]:=true;
  end;
 for i:=mina+1 to maxb do
  if time[i]
   then begin inc(t1); if t2>a2 then a2:=t2; t2:=0; end
   else begin inc(t2); if t1>a1 then a1:=t1; t1:=0; end;
 if t1>a1 then a1:=t1; t1:=0;
 writeln(a1,' ',a2);
end.