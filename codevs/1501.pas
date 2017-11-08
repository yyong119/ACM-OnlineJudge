var n,i,maxw,maxd:longint;
    lc,rc:array[1..10000]of longint;
    wid:array[1..10000]of longint;
procedure go(dep,i:integer);
 begin
  if lc[i]>0 then 
   begin
    inc(wid[dep]);
    go(dep+1,lc[i]);
   end;
  if rc[i]>0 then 
   begin
    inc(wid[dep]);
    go(dep+1,rc[i]);
   end;
  if dep>maxd then maxd:=dep; 
 end;
 
begin
 readln(n);if n=1 then  begin writeln(1,' ',1);exit;end;
 for i:=1to n do readln(lc[i],rc[i]);
 go(1,1);
 maxw:=wid[1];
 wid[1]:=1;
 for i:=2to n do if wid[i]>maxw then maxw:=wid[i];
 writeln(maxw,' ',maxd);
end.