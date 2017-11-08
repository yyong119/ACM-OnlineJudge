var a0,a1,b0,b1,aa0,aa1,bb0,bb1,high,low,i,n,k,ans:longint;
    q:array[1..10000]of longint;
    l:array[1..50000]of boolean;

procedure sushu;
var i,j:longint;
begin
  k:=0;
   fillchar(l,sizeof(l),true);
   for i:=2 to 50000 do
     if l[i] then begin
     inc(k);
     q[k]:=i;
     for j:=2 to 50000 div i do l[i*j]:=false;
   end;
end;
procedure work;
var i:longint;
begin
 ans:=1;
 readln(a0,a1,b0,b1);
 for i:=1 to k do begin
   if q[i]>trunc(sqrt(b1)) then break;
   if b1 mod q[i]=0 then begin
    aa0:=0; aa1:=0; bb0:=0; bb1:=0;
    while a0 mod q[i]=0 do begin a0:=a0 div q[i];inc(aa0);end;
    while a1 mod q[i]=0 do begin
     a1:=a1 div q[i];
     inc(aa1);
     end;
    while b0 mod q[i]=0 do begin
     b0:=b0 div q[i];
     inc(bb0);
     end;
    while b1 mod q[i]=0 do begin
     b1:=b1 div q[i];
     inc(bb1);
     end;
   low:=aa1; high:=100;
   if aa0>aa1 then high:=aa1;
   if bb0<bb1 then begin
   if (bb1>high)or(low>high) then begin writeln('0');exit;end;
   low:=bb1; high:=bb1;end
   else if high>bb1 then high:=bb1;
   ans:=ans*(high-low+1);
   end;
 end;
 if ((a1>1)and(b1<>a1)) or ((a0>1)and(a0<>a1)and(b1=a0)and(b0<>a0)) then begin
  writeln('0');
  exit;
  end;
  if (b1>1)and(b0>1)and(a1<>b1)and(a0 mod b1<>0) then ans:=ans*2;
  writeln(ans);
end;
begin
    sushu;
    readln(n);
    for i:=1 to n do work;
end.